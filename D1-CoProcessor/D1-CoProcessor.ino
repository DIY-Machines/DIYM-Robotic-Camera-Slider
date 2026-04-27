// Wemos D1 (ESP8266) - Motion Coprocessor with Dual Serial (USB + ESP32 link)
// Dual-axis (X,Y), shared NC limit per axis,
// soft limits (5mm from ends) after full HOME calibration,
// hard-limit "oh no" event + auto 5mm backoff into soft range,
// full calibration homing: min -> backoff -> max -> backoff -> centre -> report travel+pos,
// HARD/SOFT stop, echo acks,
// Continuous run command: RUN <axis> <speed_steps_per_sec> (uses runSpeed()).
// FIX: Soft STOP during RUN now ramps speed to 0 in runSpeed() mode (no stop() for RUN).
//
// UPDATED:
// - MOVE <axis> <position> <speed> <accel> now treats <position> as an ABSOLUTE target
// - Positional moves emit DONE X / DONE Y on completion
// - Repeated MOVE commands retarget the axis to the latest absolute destination

#include <Arduino.h>
#include <AccelStepper.h>
#include <SoftwareSerial.h>

struct Axis;

// ESP8266 pins: RX=D1 (GPIO5), TX=D7 (GPIO13)
SoftwareSerial Host(D1, D7); // RX, TX

// ----- helpers to print to both Serial ports -----
void printAll(const char* s)                  { Serial.print(s); Host.print(s); }
void printlnAll(const char* s)                { Serial.println(s); Host.println(s); }
void printAll(const __FlashStringHelper* s)   { Serial.print(s); Host.print(s); }
void printlnAll(const __FlashStringHelper* s) { Serial.println(s); Host.println(s); }
void printAll(long v)                         { Serial.print(v); Host.print(v); }
void printAll(int v)                          { Serial.print(v); Host.print(v); }
void printAll(float v)                        { Serial.print(v); Host.print(v); }
void printlnAll()                             { Serial.println(); Host.println(); }
void printAll(const String& s)                { Serial.print(s); Host.print(s); }
void printlnAll(const String& s)              { Serial.println(s); Host.println(s); }

// ========= Mechanics constants =========
static const long  STEPS_PER_MM        = 40;
static const long  SOFT_MARGIN_MM      = 5;
static const long  SOFT_MARGIN_STEPS   = SOFT_MARGIN_MM * STEPS_PER_MM; // 200

// ========= Y smoothing for RUN soft-stop =========
// This is a deceleration rate in steps/s^2 used only for RUN->STOP SOFT on Y.
static const float Y_RUN_DECEL          = 500.0f;  // steps/s^2 (very gentle)
static const float X_RUN_DECEL_FALLBACK = 800.0f;

// ========= Homing motion =========
static const float HOME_VMAX        = 1000;
static const float HOME_SEEK_ACCEL  = 1200;
static const float HOME_BRAKE_ACCEL = 8000;

// ========= Backoff motion =========
static const float BACKOFF_VMAX  = 300;
static const float BACKOFF_ACCEL = 400;

struct Axis {
  AccelStepper stepper;

  int  pinEn;
  int  limPin;
  bool hasEn;

  // Calibration / soft limits
  bool calibrated;
  long softMin;
  long softMax;

  // Continuous run mode
  bool  runMode;        // true => uses runSpeed()
  float runSpeedCmd;    // commanded steps/s (+/-)

  // RUN soft-stop ramp
  bool runStopping;     // true => ramp runSpeedCmd to 0
  float runDecel;       // steps/s^2 for ramp
  uint32_t lastRunMicros;

  // Positional move tracking
  bool positionalMoveActive;

  // Runtime state machines
  uint8_t state;
  int hitDir;
  bool hardLimLatched;

  static const uint8_t IDLE             = 0;
  static const uint8_t STOPPING_ON_LIM  = 1;
  static const uint8_t BACKING_OFF      = 2;
  static const uint8_t WAIT_CLEAR       = 3;

  static const uint8_t HOMING_TO_MIN        = 10;
  static const uint8_t HOMING_STOP_MIN      = 11;
  static const uint8_t HOMING_BACKOFF_MIN   = 12;
  static const uint8_t HOMING_TO_MAX        = 13;
  static const uint8_t HOMING_STOP_MAX      = 14;
  static const uint8_t HOMING_BACKOFF_MAX   = 15;
  static const uint8_t HOMING_TO_CENTER     = 16;

  Axis() : stepper(AccelStepper::DRIVER, -1, -1) {
    pinEn = -1;
    limPin = -1;
    hasEn = false;

    calibrated = false;
    softMin = 0;
    softMax = 0;

    runMode = false;
    runSpeedCmd = 0.0f;

    runStopping = false;
    runDecel = 0.0f;
    lastRunMicros = 0;

    positionalMoveActive = false;

    state = IDLE;
    hitDir = 0;
    hardLimLatched = false;
  }
};

Axis X;
Axis Y;

// ========= Hardware setup helpers =========
void setDriverPins(Axis &A, int stepPin, int dirPin, int enPin) {
  A.stepper.setPinsInverted(false, false, false);
  A.stepper.setEnablePin(enPin);

  A.pinEn = enPin;
  A.hasEn = (enPin >= 0);

  A.stepper = AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);

  if (A.hasEn) {
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);
  }
}

void setLimitPin(Axis &A, int pin) {
  A.limPin = pin;
  if (pin >= 0) pinMode(pin, INPUT_PULLUP);
  // NC: normal LOW, triggered/broken wire HIGH
}

inline bool limitActive(const Axis &A) {
  return (A.limPin >= 0) ? (digitalRead(A.limPin) == HIGH) : false;
}

Axis* axisFromToken(const char* axTok) {
  if (!axTok) return NULL;
  if (axTok[0] == 'X' || axTok[0] == 'x') return &X;
  if (axTok[0] == 'Y' || axTok[0] == 'y') return &Y;
  return NULL;
}

char axisNameFromPtr(Axis* A) {
  if (A == &X) return 'X';
  if (A == &Y) return 'Y';
  return '?';
}

// ========= Event messages =========
void sendHardLimitEvent(char axisName, int dir, long pos) {
  printAll(F("EV HARDLIM "));
  Serial.print(axisName); Host.print(axisName);
  printAll(F(" DIR ")); printAll(dir);
  printAll(F(" POS ")); printAll(pos);
  printlnAll();
}

void sendHomeDoneEvent(char axisName, long travelSteps, long pos) {
  printAll(F("EV HOME_DONE "));
  Serial.print(axisName); Host.print(axisName);
  printAll(F(" TRAVEL ")); printAll(travelSteps);
  printAll(F(" POS ")); printAll(pos);
  printlnAll();
}

void sendSoftClampEvent(char axisName, long reqValue, long appliedValue) {
  printAll(F("EV SOFTCLAMP "));
  Serial.print(axisName); Host.print(axisName);
  printAll(F(" REQ ")); printAll(reqValue);
  printAll(F(" APPLIED ")); printAll(appliedValue);
  printlnAll();
}

void sendSoftLimitStopEvent(char axisName, long pos) {
  printAll(F("EV SOFTLIM "));
  Serial.print(axisName); Host.print(axisName);
  printAll(F(" POS ")); printAll(pos);
  printlnAll();
}

void sendDoneEvent(char axisName) {
  Serial.print(F("DONE "));
  Serial.println(axisName);
  Host.print(F("DONE "));
  Host.println(axisName);
}

// ========= Helpers =========
inline bool axisStopped(Axis &A) {
  return (A.stepper.distanceToGo() == 0) && (A.stepper.speed() == 0);
}

long applySoftLimitsRelative(Axis &A, long reqSteps) {
  if (!A.calibrated) return reqSteps;
  long cur = A.stepper.currentPosition();
  long target = cur + reqSteps;
  if (target < A.softMin) target = A.softMin;
  if (target > A.softMax) target = A.softMax;
  return target - cur;
}

long applySoftLimitsAbsolute(Axis &A, long reqTarget) {
  if (!A.calibrated) return reqTarget;
  if (reqTarget < A.softMin) return A.softMin;
  if (reqTarget > A.softMax) return A.softMax;
  return reqTarget;
}

// ========= RUN helpers =========
void startRun(Axis &A, float speedStepsPerSec, float decelStepsPerSec2) {
  A.runMode = true;
  A.runStopping = false;
  A.runSpeedCmd = speedStepsPerSec;
  A.runDecel = decelStepsPerSec2;
  A.lastRunMicros = micros();

  // Cancel any pending position move
  A.positionalMoveActive = false;
  A.stepper.moveTo(A.stepper.currentPosition());
}

void requestRunSoftStop(Axis &A, float decelStepsPerSec2) {
  if (!A.runMode) return;
  A.runStopping = true;
  A.runDecel = decelStepsPerSec2;
  A.lastRunMicros = micros();
}

void cancelRunImmediate(Axis &A) {
  A.runMode = false;
  A.runStopping = false;
  A.runSpeedCmd = 0.0f;
  A.stepper.setSpeed(0);
}

// ========= Continuous run service (runSpeed + soft bounds + soft-stop ramp) =========
void serviceRunMode(Axis &A, char axisName) {
  if (!A.runMode) return;
  if (A.state >= Axis::HOMING_TO_MIN) return; // no runSpeed while homing
  if (A.state != Axis::IDLE) return;          // no runSpeed while handling hard limit

  // If calibrated, enforce soft boundaries during RUN:
  if (A.calibrated) {
    long pos = A.stepper.currentPosition();
    if (A.runSpeedCmd > 0 && pos >= A.softMax) {
      requestRunSoftStop(A, (&A == &Y) ? Y_RUN_DECEL : X_RUN_DECEL_FALLBACK);
      sendSoftLimitStopEvent(axisName, pos);
    }
    if (A.runSpeedCmd < 0 && pos <= A.softMin) {
      requestRunSoftStop(A, (&A == &Y) ? Y_RUN_DECEL : X_RUN_DECEL_FALLBACK);
      sendSoftLimitStopEvent(axisName, pos);
    }
  }

  // Soft-stop ramp: slew runSpeedCmd toward 0
  if (A.runStopping) {
    uint32_t now = micros();
    float dt = (now - A.lastRunMicros) / 1000000.0f;
    A.lastRunMicros = now;

    float dec = A.runDecel * dt;
    if (dec < 0) dec = 0;

    if (A.runSpeedCmd > 0) {
      A.runSpeedCmd -= dec;
      if (A.runSpeedCmd <= 0) A.runSpeedCmd = 0;
    } else if (A.runSpeedCmd < 0) {
      A.runSpeedCmd += dec;
      if (A.runSpeedCmd >= 0) A.runSpeedCmd = 0;
    }

    if (A.runSpeedCmd == 0.0f) {
      // fully stopped
      A.stepper.setSpeed(0);
      A.runMode = false;
      A.runStopping = false;
      return;
    }
  }

  A.stepper.setSpeed(A.runSpeedCmd);
  A.stepper.runSpeed();
}

// ========= Hard limit handling =========
void serviceHardLimit(Axis &A, char axisName) {
  if (A.state >= Axis::HOMING_TO_MIN) return;

  if (A.state == Axis::IDLE) {
    // Consider “moving” if either runSpeedCmd non-zero OR stepper.speed() non-zero
    bool moving = (A.runMode && A.runSpeedCmd != 0.0f) || (A.stepper.speed() != 0);

    if (moving && limitActive(A)) {
      // Hard limit is an “oh no” event: cancel RUN immediately
      if (A.runMode) cancelRunImmediate(A);

      A.positionalMoveActive = false;

      int dir = (A.stepper.speed() > 0) ? +1 : -1;
      if (dir == 0) dir = (A.runSpeedCmd > 0) ? +1 : -1; // fallback

      A.hitDir = dir;
      A.hardLimLatched = true;

      sendHardLimitEvent(axisName, dir, A.stepper.currentPosition());

      // Decelerated stop for positional moves; for RUN we already cancelled speed
      A.stepper.stop();
      A.state = Axis::STOPPING_ON_LIM;
    }
    return;
  }

  if (A.state == Axis::STOPPING_ON_LIM) {
    if (axisStopped(A)) {
      int backDir = -A.hitDir;
      long backSteps = (long)backDir * SOFT_MARGIN_STEPS;

      if (A.calibrated) {
        long cur = A.stepper.currentPosition();
        long target = cur + backSteps;
        if (target < A.softMin) target = A.softMin;
        if (target > A.softMax) target = A.softMax;
        backSteps = target - cur;
      }

      if (A.hasEn) A.stepper.enableOutputs();
      A.stepper.setMaxSpeed(BACKOFF_VMAX);
      A.stepper.setAcceleration(BACKOFF_ACCEL);
      A.stepper.move(backSteps);

      A.state = Axis::BACKING_OFF;
    }
    return;
  }

  if (A.state == Axis::BACKING_OFF) {
    if (axisStopped(A)) A.state = Axis::WAIT_CLEAR;
    return;
  }

  if (A.state == Axis::WAIT_CLEAR) {
    if (!limitActive(A)) {
      A.hitDir = 0;
      A.hardLimLatched = false;
      A.state = Axis::IDLE;
    }
    return;
  }
}

// ========= Homing/calibration =========
void startFullHome(Axis &A) {
  if (A.runMode) cancelRunImmediate(A);

  A.positionalMoveActive = false;
  A.calibrated = false;
  A.softMin = 0;
  A.softMax = 0;
  A.hardLimLatched = false;

  if (A.hasEn) A.stepper.enableOutputs();

  A.stepper.setMaxSpeed(HOME_VMAX);
  A.stepper.setAcceleration(HOME_SEEK_ACCEL);

  A.stepper.move(-1000000L);
  A.state = Axis::HOMING_TO_MIN;
}

void serviceHoming(Axis &A, char axisName) {
  if (A.state < Axis::HOMING_TO_MIN) return;

  if (A.state == Axis::HOMING_TO_MIN) {
    if (A.stepper.speed() != 0 && limitActive(A)) {
      A.stepper.setAcceleration(HOME_BRAKE_ACCEL);
      A.stepper.stop();
      A.state = Axis::HOMING_STOP_MIN;
    }
    return;
  }

  if (A.state == Axis::HOMING_STOP_MIN) {
    if (axisStopped(A)) {
      if (A.hasEn) A.stepper.enableOutputs();
      A.stepper.setMaxSpeed(BACKOFF_VMAX);
      A.stepper.setAcceleration(BACKOFF_ACCEL);
      A.stepper.move(+SOFT_MARGIN_STEPS);
      A.state = Axis::HOMING_BACKOFF_MIN;
    }
    return;
  }

  if (A.state == Axis::HOMING_BACKOFF_MIN) {
    if (axisStopped(A) && !limitActive(A)) {
      A.stepper.setCurrentPosition(0);
      A.softMin = 0;

      A.stepper.setMaxSpeed(HOME_VMAX);
      A.stepper.setAcceleration(HOME_SEEK_ACCEL);
      A.stepper.move(+1000000L);
      A.state = Axis::HOMING_TO_MAX;
    }
    return;
  }

  if (A.state == Axis::HOMING_TO_MAX) {
    if (A.stepper.speed() != 0 && limitActive(A)) {
      A.stepper.setAcceleration(HOME_BRAKE_ACCEL);
      A.stepper.stop();
      A.state = Axis::HOMING_STOP_MAX;
    }
    return;
  }

  if (A.state == Axis::HOMING_STOP_MAX) {
    if (axisStopped(A)) {
      if (A.hasEn) A.stepper.enableOutputs();
      A.stepper.setMaxSpeed(BACKOFF_VMAX);
      A.stepper.setAcceleration(BACKOFF_ACCEL);
      A.stepper.move(-SOFT_MARGIN_STEPS);
      A.state = Axis::HOMING_BACKOFF_MAX;
    }
    return;
  }

  if (A.state == Axis::HOMING_BACKOFF_MAX) {
    if (axisStopped(A) && !limitActive(A)) {
      A.softMax = A.stepper.currentPosition();
      A.calibrated = true;

      long centre = A.softMax / 2;
      A.stepper.setMaxSpeed(HOME_VMAX);
      A.stepper.setAcceleration(HOME_SEEK_ACCEL);
      A.stepper.moveTo(centre);
      A.state = Axis::HOMING_TO_CENTER;
    }
    return;
  }

  if (A.state == Axis::HOMING_TO_CENTER) {
    if (axisStopped(A)) {
      sendHomeDoneEvent(axisName, A.softMax, A.stepper.currentPosition());
      A.state = Axis::IDLE;
    }
    return;
  }
}

// ========= Positional move completion =========
void serviceMoveDone(Axis &A, char axisName) {
  if (A.runMode) return;
  if (!A.positionalMoveActive) return;
  if (A.state != Axis::IDLE) return;

  if (A.stepper.distanceToGo() == 0 && A.stepper.speed() == 0) {
    A.positionalMoveActive = false;
    sendDoneEvent(axisName);
  }
}

// ========= Command handling =========
void handleLine(String s) {
  s.trim();
  if (s.length() == 0) return;

  String original = s;

  char buf[240];
  s.toCharArray(buf, sizeof(buf));
  char *cmd = strtok(buf, " ");
  if (!cmd) return;

  if (!strcmp(cmd, "CONF")) {
    char *axTok = strtok(NULL, " ");
    char *tStep = strtok(NULL, " ");
    char *tDir  = strtok(NULL, " ");
    char *tEn   = strtok(NULL, " ");
    Axis* A = axisFromToken(axTok);
    if (!A || !tStep || !tDir || !tEn) { printAll(F("ERR CONF args | ")); printlnAll(original); return; }
    setDriverPins(*A, atoi(tStep), atoi(tDir), atoi(tEn));
    printAll(F("OK ")); printlnAll(original);
    return;
  }

  if (!strcmp(cmd, "LIM")) {
    char *axTok = strtok(NULL, " ");
    char *tPin  = strtok(NULL, " ");
    Axis* A = axisFromToken(axTok);
    if (!A || !tPin) { printAll(F("ERR LIM args | ")); printlnAll(original); return; }
    setLimitPin(*A, atoi(tPin));
    printAll(F("OK ")); printlnAll(original);
    return;
  }

  if (!strcmp(cmd, "HOME")) {
    char *axTok = strtok(NULL, " ");
    Axis* A = axisFromToken(axTok);
    if (!A) { printAll(F("ERR HOME args | ")); printlnAll(original); return; }
    if (A->state != Axis::IDLE) { printAll(F("ERR BUSY | ")); printlnAll(original); return; }
    if (A->limPin < 0) { printAll(F("ERR NO_LIM | ")); printlnAll(original); return; }

    printAll(F("OK ")); printlnAll(original);
    startFullHome(*A);
    return;
  }

  if (!strcmp(cmd, "MOVE")) {
    // MOVE <X|Y> <absolute_position_steps> <speed> <accel>
    char *axTok = strtok(NULL, " ");
    char *tPos  = strtok(NULL, " ");
    char *tV    = strtok(NULL, " ");
    char *tA    = strtok(NULL, " ");
    Axis* A = axisFromToken(axTok);
    if (!A || !tPos || !tV || !tA) { printAll(F("ERR MOVE args | ")); printlnAll(original); return; }

    // Do not allow move commands during homing / hard-limit recovery states
    if (A->state != Axis::IDLE) { printAll(F("ERR BUSY | ")); printlnAll(original); return; }

    if (A->runMode) cancelRunImmediate(*A);

    long reqTarget = atol(tPos);
    long appliedTarget = applySoftLimitsAbsolute(*A, reqTarget);
    if (appliedTarget != reqTarget) {
      sendSoftClampEvent(axisNameFromPtr(A), reqTarget, appliedTarget);
    }

    if (A->hasEn) A->stepper.enableOutputs();
    A->stepper.setMaxSpeed(atof(tV));
    A->stepper.setAcceleration(atof(tA));
    A->stepper.moveTo(appliedTarget);
    A->positionalMoveActive = true;

    printAll(F("OK ")); printlnAll(original);
    return;
  }

  if (!strcmp(cmd, "RUN")) {
    // RUN <X|Y> <speed_steps_per_sec>
    char *axTok = strtok(NULL, " ");
    char *tS    = strtok(NULL, " ");
    Axis* A = axisFromToken(axTok);
    if (!A || !tS) { printAll(F("ERR RUN args | ")); printlnAll(original); return; }
    if (A->state != Axis::IDLE) { printAll(F("ERR BUSY | ")); printlnAll(original); return; }

    float spd = atof(tS);

    if (spd == 0.0f) {
      // Equivalent to soft stop request if already running
      if (A->runMode) {
        requestRunSoftStop(*A, (A == &Y) ? Y_RUN_DECEL : X_RUN_DECEL_FALLBACK);
      } else {
        A->stepper.stop();
        A->positionalMoveActive = false;
      }
      printAll(F("OK ")); printlnAll(original);
      return;
    }

    if (A->hasEn) A->stepper.enableOutputs();

    startRun(*A, spd, (A == &Y) ? Y_RUN_DECEL : X_RUN_DECEL_FALLBACK);

    printAll(F("OK ")); printlnAll(original);
    return;
  }

  if (!strcmp(cmd, "STOP")) {
    // STOP <X|Y> [SOFT|HARD|0|1]
    char *axTok = strtok(NULL, " ");
    char *mode  = strtok(NULL, " ");
    Axis* A = axisFromToken(axTok);
    if (!A) { printAll(F("ERR STOP args | ")); printlnAll(original); return; }

    bool hard = false;
    if (mode) {
      if (!strcasecmp(mode, "HARD") || !strcmp(mode, "1")) hard = true;
    }

    // Cancel any special state
    A->state = Axis::IDLE;
    A->hitDir = 0;
    A->hardLimLatched = false;
    A->positionalMoveActive = false;

    if (hard) {
      if (A->runMode) cancelRunImmediate(*A);
      A->stepper.setSpeed(0);
      A->stepper.moveTo(A->stepper.currentPosition());
      A->stepper.disableOutputs();
    } else {
      // SOFT stop:
      // If in RUN mode -> ramp speed to zero in runSpeed() mode
      if (A->runMode) {
        requestRunSoftStop(*A, (A == &Y) ? Y_RUN_DECEL : X_RUN_DECEL_FALLBACK);
      } else {
        // positional move soft stop
        A->stepper.stop();
      }
    }

    printAll(F("OK ")); printlnAll(original);
    return;
  }

  if (!strcmp(cmd, "STAT")) {
    printAll(F("OK ")); printlnAll(original);

    printAll(F("X POS ")); printAll(X.stepper.currentPosition());
    printAll(F(" LIM "));  printAll(X.limPin >= 0 ? (digitalRead(X.limPin)==HIGH) : 0);
    printAll(F(" CAL "));  printAll((int)X.calibrated);
    printAll(F(" MIN "));  printAll(X.softMin);
    printAll(F(" MAX "));  printAll(X.softMax);
    printAll(F(" RUN "));  printAll((int)X.runMode);
    printAll(F(" RSTOP ")); printAll((int)X.runStopping);
    printAll(F(" PMOVE ")); printAll((int)X.positionalMoveActive);
    printAll(F(" SPD "));  printAll(X.runSpeedCmd);
    printAll(F(" ST "));   printAll((int)X.state);
    printlnAll();

    printAll(F("Y POS ")); printAll(Y.stepper.currentPosition());
    printAll(F(" LIM "));  printAll(Y.limPin >= 0 ? (digitalRead(Y.limPin)==HIGH) : 0);
    printAll(F(" CAL "));  printAll((int)Y.calibrated);
    printAll(F(" MIN "));  printAll(Y.softMin);
    printAll(F(" MAX "));  printAll(Y.softMax);
    printAll(F(" RUN "));  printAll((int)Y.runMode);
    printAll(F(" RSTOP ")); printAll((int)Y.runStopping);
    printAll(F(" PMOVE ")); printAll((int)Y.positionalMoveActive);
    printAll(F(" SPD "));  printAll(Y.runSpeedCmd);
    printAll(F(" ST "));   printAll((int)Y.state);
    printlnAll();
    return;
  }

  printAll(F("ERR ? | ")); printlnAll(original);
}

void pump(Stream& s, String& buf) {
  while (s.available()) {
    char c = (char)s.read();
    if (c == '\n') { handleLine(buf); buf = ""; }
    else if (c != '\r') { buf += c; }
  }
}

void setup() {
  Serial.begin(115200);
  Host.begin(115200);

  // X defaults
  setDriverPins(X, D6, D5, D8);
  setLimitPin(X, D2);

  // Y defaults
  setDriverPins(Y, D4, D3, D0);
  setLimitPin(Y, -1);

  // Default motion (positional)
  X.stepper.setMaxSpeed(2000);
  X.stepper.setAcceleration(1000);

  Y.stepper.setMaxSpeed(2000);
  Y.stepper.setAcceleration(1000);

  printlnAll(F("READY"));
}

String inUsb, inHost;

void loop() {
  // Positional moves
  if (!X.runMode) X.stepper.run();
  if (!Y.runMode) Y.stepper.run();

  // Continuous speed mode
  serviceRunMode(X, 'X');
  serviceRunMode(Y, 'Y');

  // Homing/calibration
  serviceHoming(X, 'X');
  serviceHoming(Y, 'Y');

  // Hard limit handling
  serviceHardLimit(X, 'X');
  serviceHardLimit(Y, 'Y');

  // Positional move completion
  serviceMoveDone(X, 'X');
  serviceMoveDone(Y, 'Y');

  // Serial input
  pump(Serial, inUsb);
  pump(Host,   inHost);
}