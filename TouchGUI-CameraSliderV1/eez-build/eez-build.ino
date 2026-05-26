#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <TFT_Touch.h>
#include <HardwareSerial.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "ui.h"
#include "vars.h"

/* Touch pins */
#define HRES 320
#define VRES 240

#define T_DOUT 39
#define T_DIN  32
#define T_CS   33
#define T_CLK  25

#define TFT_HOR_RES 320
#define TFT_VER_RES 240

#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

/* Axis conversions */
#define X_STEPS_PER_MM 40.0f
#define Y_STEPS_PER_DEGREE 14.444444f

/* Prepare defaults (sent directly to D1 in steps units) */
#define PREPARE_X_SPEED_STEPS 1000
#define PREPARE_X_ACCEL_STEPS 800
#define PREPARE_Y_SPEED_STEPS 1000
#define PREPARE_Y_ACCEL_STEPS 1000

TFT_eSPI tft = TFT_eSPI();
TFT_Touch touch(T_CS, T_CLK, T_DIN, T_DOUT);

HardwareSerial MotionSerial(2);

/* ===== X watcher ===== */
static bool xMoveWatcherInitialized = false;
static int32_t lastSeenPositionToMoveXTo = 0;

/* ===== Y watcher ===== */
static bool yMoveWatcherInitialized = false;
static int32_t lastSeenPositionToMoveYTo = 0;

/* ===== X timing watcher ===== */
static bool xTimingWatcherInitialized = false;
static bool xTimingInternalUpdate = false;
static int32_t lastSeenTLXDurationS = 0;
static int32_t lastSeenTLXSpeedMMs = 0;
static bool lastSeenSOTXSpeedOrDuration = false;
static int32_t lastSeenPositionA = 0;
static int32_t lastSeenPositionB = 0;
static int32_t lastSeenXAxisAcceleration = 0;

/* ===== Y timing watcher ===== */
static bool yTimingWatcherInitialized = false;
static bool yTimingInternalUpdate = false;
static int32_t lastSeenTLYDurationS = 0;
static int32_t lastSeenTLYSpeed = 0;
static bool lastSeenSOTYSpeedOrDuration = false;
static int32_t lastSeenPositionC = 0;
static int32_t lastSeenPositionD = 0;
static int32_t lastSeenYAxisAcceleration = 0;

/* ===== Timelapse state ===== */
enum TimelapseAxisPhase
{
    TL_AXIS_IDLE = 0,
    TL_AXIS_TO_START,
    TL_AXIS_TO_END
};

static TimelapseAxisPhase xTimelapsePhase = TL_AXIS_IDLE;
static TimelapseAxisPhase yTimelapsePhase = TL_AXIS_IDLE;

static bool xTimelapseRepeat = false;
static bool yTimelapseRepeat = false;
static bool yTimelapseInfinite = false;

static bool lastSeenTimelapsePaused = false;

/* ===== Prepare state ===== */
static bool xPreparePending = false;
static bool yPreparePending = false;

/* ===== LVGL display ===== */
void my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)px_map, w * h, true);
    tft.endWrite();

    lv_display_flush_ready(disp);
}

/* ===== Touch ===== */
void my_touchpad_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    static uint16_t last_x = HRES / 2;
    static uint16_t last_y = VRES / 2;

    if (touch.Pressed()) {
        last_x = touch.X();
        last_y = touch.Y();
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }

    data->point.x = last_x;
    data->point.y = last_y;
}

static uint32_t my_tick(void)
{
    return millis();
}

/* ===== Serial init ===== */
void initMotionCoprocessorSerial()
{
    MotionSerial.begin(115200, SERIAL_8N1, 3, 1);
}

void markPrepareIncompleteForMotionCommand(const char *cmd)
{
    if (strncmp(cmd, "MOVE ", 5) == 0 ||
        strncmp(cmd, "RUN ", 4) == 0 ||
        strncmp(cmd, "STOP ", 5) == 0) {
        set_var_timelapse_prepare_complete(false);
    }
}

/* ===== Raw send helper ===== */
void sendRawMotionCommand(const char *cmd)
{
    markPrepareIncompleteForMotionCommand(cmd);

    MotionSerial.println(cmd);
    MotionSerial.flush();

    Serial.print("Sent: ");
    Serial.println(cmd);
}

/* ===== SEND COMMANDS ===== */
void sendMoveXCommand()
{
    char cmd[64];

    snprintf(cmd, sizeof(cmd),
        "MOVE X %ld %ld %ld",
        (long)get_var_position_to_move_x_to(),
        (long)get_var_x_axis_speed(),
        (long)get_var_x_axis_accelration()
    );

    sendRawMotionCommand(cmd);
    set_var_x_axis_movement_in_progress(true);
}

void sendMoveYCommand()
{
    char cmd[64];

    snprintf(cmd, sizeof(cmd),
        "MOVE Y %ld %ld %ld",
        (long)get_var_position_to_move_y_to(),
        (long)get_var_y_axis_speed(),
        (long)get_var_y_axis_accel()
    );

    sendRawMotionCommand(cmd);
    set_var_y_axis_movement_in_progress(true);
}

/* ===== Timelapse motion send helpers ===== */
float getXTimelapseSpeedStepsPerSec()
{
    float v = 0.0f;

    if (get_var_sot_x_speed_or_duration()) {
        float distanceSteps = fabsf((float)get_var_position_b() - (float)get_var_position_a());
        float durationS = (float)get_var_tl_x_duration_s();

        if (distanceSteps > 0.0f && durationS > 0.0f) {
            v = distanceSteps / durationS;
        }
    } else {
        v = (float)get_var_tl_x_speed_mms() * X_STEPS_PER_MM;
    }

    if (v < 0.0f) v = -v;
    return v;
}

int32_t getXTimelapseAccelStepsPerSec2()
{
    float a = (float)get_var_x_axis_accelration() * X_STEPS_PER_MM;
    if (a < 0.0f) a = -a;
    return (int32_t)lroundf(a);
}

float getYTimelapseSpeedStepsPerSec()
{
    float v = 0.0f;

    if (get_var_sot_y_speed_or_duration()) {
        float distanceSteps = fabsf((float)get_var_position_d() - (float)get_var_position_c());
        float durationS = (float)get_var_tl_y_duration_s();

        if (distanceSteps > 0.0f && durationS > 0.0f) {
            v = distanceSteps / durationS;
        }
    } else {
        v = (float)get_var_tl_y_speed_mms() * Y_STEPS_PER_DEGREE;
    }

    return v;
}

int32_t getYTimelapseAccelStepsPerSec2()
{
    float a = (float)get_var_y_axis_accel() * Y_STEPS_PER_DEGREE;
    if (a < 0.0f) a = -a;
    return (int32_t)lroundf(a);
}

void sendTimelapseMoveXToSteps(int32_t targetSteps)
{
    float speedSteps = getXTimelapseSpeedStepsPerSec();
    int32_t accelSteps = getXTimelapseAccelStepsPerSec2();

    if (speedSteps <= 0.0f || accelSteps <= 0) {
        return;
    }

    char cmd[64];
    snprintf(cmd, sizeof(cmd),
        "MOVE X %ld %.4f %ld",
        (long)targetSteps,
        speedSteps,
        (long)accelSteps
    );

    sendRawMotionCommand(cmd);
    set_var_x_axis_movement_in_progress(true);
}

void sendTimelapseMoveYToSteps(int32_t targetSteps)
{
    float speedSteps = getYTimelapseSpeedStepsPerSec();
    if (speedSteps < 0.0f) speedSteps = -speedSteps;
    int32_t accelSteps = getYTimelapseAccelStepsPerSec2();

    if (speedSteps <= 0.0f || accelSteps <= 0) {
        return;
    }

    char cmd[64];
    snprintf(cmd, sizeof(cmd),
        "MOVE Y %ld %.4f %ld",
        (long)targetSteps,
        speedSteps,
        (long)accelSteps
    );

    sendRawMotionCommand(cmd);
    set_var_y_axis_movement_in_progress(true);
}

void sendTimelapseInfiniteYRun()
{
    float speedSteps = (float)get_var_tl_y_speed_mms() * Y_STEPS_PER_DEGREE;

    if (speedSteps == 0.0f) {
        return;
    }

    char cmd[64];
    snprintf(cmd, sizeof(cmd),
        "RUN Y %.4f",
        speedSteps
    );

    sendRawMotionCommand(cmd);
    set_var_y_axis_movement_in_progress(true);
}

void sendPrepareMoveXToA()
{
    char cmd[64];
    snprintf(cmd, sizeof(cmd),
        "MOVE X %ld %d %d",
        (long)get_var_position_a(),
        PREPARE_X_SPEED_STEPS,
        PREPARE_X_ACCEL_STEPS
    );

    sendRawMotionCommand(cmd);
    set_var_x_axis_movement_in_progress(true);
}

void sendPrepareMoveYToC()
{
    char cmd[64];
    snprintf(cmd, sizeof(cmd),
        "MOVE Y %ld %d %d",
        (long)get_var_position_c(),
        PREPARE_Y_SPEED_STEPS,
        PREPARE_Y_ACCEL_STEPS
    );

    sendRawMotionCommand(cmd);
    set_var_y_axis_movement_in_progress(true);
}

/* ===== WATCHERS ===== */
void watchForXMoveRequest()
{
    int32_t current = get_var_position_to_move_x_to();

    if (!xMoveWatcherInitialized) {
        lastSeenPositionToMoveXTo = current;
        xMoveWatcherInitialized = true;
        return;
    }

    if (current != lastSeenPositionToMoveXTo) {
        lastSeenPositionToMoveXTo = current;
        sendMoveXCommand();
    }
}

void watchForYMoveRequest()
{
    int32_t current = get_var_position_to_move_y_to();

    if (!yMoveWatcherInitialized) {
        lastSeenPositionToMoveYTo = current;
        yMoveWatcherInitialized = true;
        return;
    }

    if (current != lastSeenPositionToMoveYTo) {
        lastSeenPositionToMoveYTo = current;
        sendMoveYCommand();
    }
}

/* ===== X TIMING CALCULATION ===== */
float getXTravelDistanceMM()
{
    float steps = fabsf((float)get_var_position_b() - (float)get_var_position_a());
    return steps / X_STEPS_PER_MM;
}

void updateXDurationFromSpeed()
{
    float d = getXTravelDistanceMM();
    float v = (float)get_var_tl_x_speed_mms();
    float a = (float)get_var_x_axis_accelration();

    int32_t result = 0;

    if (d > 0.0f && v > 0.0f && a > 0.0f) {
        float t;

        if (d >= (v * v) / a) {
            t = (2.0f * v / a) + ((d - (v * v) / a) / v);
        } else {
            t = 2.0f * sqrtf(d / a);
        }

        if (isfinite(t) && t >= 0.0f) {
            result = (int32_t)lroundf(t);
        }
    }

    xTimingInternalUpdate = true;
    set_var_tl_x_duration_s(result);
    xTimingInternalUpdate = false;
}

void updateXSpeedFromDuration()
{
    float d = getXTravelDistanceMM();
    float T = (float)get_var_tl_x_duration_s();
    float a = (float)get_var_x_axis_accelration();

    int32_t result = 0;

    if (d > 0.0f && T > 0.0f && a > 0.0f) {
        float disc = (T * T) - (4.0f * d / a);

        if (disc >= 0.0f) {
            float v = 0.5f * a * (T - sqrtf(disc));
            if (isfinite(v) && v >= 0.0f) {
                result = (int32_t)lroundf(v);
            }
        }
    }

    xTimingInternalUpdate = true;
    set_var_tl_x_speed_mms(result);
    xTimingInternalUpdate = false;
}

void watchXSpeedDurationCalculation()
{
    int32_t currentDuration = get_var_tl_x_duration_s();
    int32_t currentSpeed = get_var_tl_x_speed_mms();
    bool currentToggle = get_var_sot_x_speed_or_duration();
    int32_t currentPositionA = get_var_position_a();
    int32_t currentPositionB = get_var_position_b();
    int32_t currentAcceleration = get_var_x_axis_accelration();

    if (!xTimingWatcherInitialized) {
        lastSeenTLXDurationS = currentDuration;
        lastSeenTLXSpeedMMs = currentSpeed;
        lastSeenSOTXSpeedOrDuration = currentToggle;
        lastSeenPositionA = currentPositionA;
        lastSeenPositionB = currentPositionB;
        lastSeenXAxisAcceleration = currentAcceleration;
        xTimingWatcherInitialized = true;
        return;
    }

    if (xTimingInternalUpdate) {
        lastSeenTLXDurationS = currentDuration;
        lastSeenTLXSpeedMMs = currentSpeed;
        lastSeenSOTXSpeedOrDuration = currentToggle;
        lastSeenPositionA = currentPositionA;
        lastSeenPositionB = currentPositionB;
        lastSeenXAxisAcceleration = currentAcceleration;
        return;
    }

    bool durationChanged = (currentDuration != lastSeenTLXDurationS);
    bool speedChanged = (currentSpeed != lastSeenTLXSpeedMMs);
    bool toggleChanged = (currentToggle != lastSeenSOTXSpeedOrDuration);
    bool positionChanged = (currentPositionA != lastSeenPositionA) || (currentPositionB != lastSeenPositionB);
    bool accelChanged = (currentAcceleration != lastSeenXAxisAcceleration);

    if (currentToggle == false) {
        if (speedChanged || toggleChanged || positionChanged || accelChanged) {
            updateXDurationFromSpeed();
            currentDuration = get_var_tl_x_duration_s();
        }
    } else {
        if (durationChanged || toggleChanged || positionChanged || accelChanged) {
            updateXSpeedFromDuration();
            currentSpeed = get_var_tl_x_speed_mms();
        }
    }

    lastSeenTLXDurationS = currentDuration;
    lastSeenTLXSpeedMMs = currentSpeed;
    lastSeenSOTXSpeedOrDuration = currentToggle;
    lastSeenPositionA = currentPositionA;
    lastSeenPositionB = currentPositionB;
    lastSeenXAxisAcceleration = currentAcceleration;
}

/* ===== Y TIMING CALCULATION ===== */
float getYTravelDistanceDegrees()
{
    float steps = fabsf((float)get_var_position_d() - (float)get_var_position_c());
    return steps / Y_STEPS_PER_DEGREE;
}

void updateYDurationFromSpeed()
{
    float d = getYTravelDistanceDegrees();
    float v = (float)get_var_tl_y_speed_mms();
    float a = (float)get_var_y_axis_accel();

    int32_t result = 0;

    if (d > 0.0f && v > 0.0f && a > 0.0f) {
        float t;

        if (d >= (v * v) / a) {
            t = (2.0f * v / a) + ((d - (v * v) / a) / v);
        } else {
            t = 2.0f * sqrtf(d / a);
        }

        if (isfinite(t) && t >= 0.0f) {
            result = (int32_t)lroundf(t);
        }
    }

    yTimingInternalUpdate = true;
    set_var_tl_y_duration_s(result);
    yTimingInternalUpdate = false;
}

void updateYSpeedFromDuration()
{
    float d = getYTravelDistanceDegrees();
    float T = (float)get_var_tl_y_duration_s();
    float a = (float)get_var_y_axis_accel();

    int32_t result = 0;

    if (d > 0.0f && T > 0.0f && a > 0.0f) {
        float disc = (T * T) - (4.0f * d / a);

        if (disc >= 0.0f) {
            float v = 0.5f * a * (T - sqrtf(disc));
            if (isfinite(v) && v >= 0.0f) {
                result = (int32_t)lroundf(v);
            }
        }
    }

    yTimingInternalUpdate = true;
    set_var_tl_y_speed_mms(result);
    yTimingInternalUpdate = false;
}

void watchYSpeedDurationCalculation()
{
    int32_t currentDuration = get_var_tl_y_duration_s();
    int32_t currentSpeed = get_var_tl_y_speed_mms();
    bool currentToggle = get_var_sot_y_speed_or_duration();
    int32_t currentPositionC = get_var_position_c();
    int32_t currentPositionD = get_var_position_d();
    int32_t currentAcceleration = get_var_y_axis_accel();

    if (!yTimingWatcherInitialized) {
        lastSeenTLYDurationS = currentDuration;
        lastSeenTLYSpeed = currentSpeed;
        lastSeenSOTYSpeedOrDuration = currentToggle;
        lastSeenPositionC = currentPositionC;
        lastSeenPositionD = currentPositionD;
        lastSeenYAxisAcceleration = currentAcceleration;
        yTimingWatcherInitialized = true;
        return;
    }

    if (yTimingInternalUpdate) {
        lastSeenTLYDurationS = currentDuration;
        lastSeenTLYSpeed = currentSpeed;
        lastSeenSOTYSpeedOrDuration = currentToggle;
        lastSeenPositionC = currentPositionC;
        lastSeenPositionD = currentPositionD;
        lastSeenYAxisAcceleration = currentAcceleration;
        return;
    }

    bool durationChanged = (currentDuration != lastSeenTLYDurationS);
    bool speedChanged = (currentSpeed != lastSeenTLYSpeed);
    bool toggleChanged = (currentToggle != lastSeenSOTYSpeedOrDuration);
    bool positionChanged = (currentPositionC != lastSeenPositionC) || (currentPositionD != lastSeenPositionD);
    bool accelChanged = (currentAcceleration != lastSeenYAxisAcceleration);

    if (currentToggle == false) {
        if (speedChanged || toggleChanged || positionChanged || accelChanged) {
            updateYDurationFromSpeed();
            currentDuration = get_var_tl_y_duration_s();
        }
    } else {
        if (durationChanged || toggleChanged || positionChanged || accelChanged) {
            updateYSpeedFromDuration();
            currentSpeed = get_var_tl_y_speed_mms();
        }
    }

    lastSeenTLYDurationS = currentDuration;
    lastSeenTLYSpeed = currentSpeed;
    lastSeenSOTYSpeedOrDuration = currentToggle;
    lastSeenPositionC = currentPositionC;
    lastSeenPositionD = currentPositionD;
    lastSeenYAxisAcceleration = currentAcceleration;
}

/* ===== Timelapse helpers ===== */
void resetTimelapseStateIfAbandoned()
{
    if (!get_var_timelapse_start_requested() &&
        !get_var_timelapse_running() &&
        !get_var_timelapse_paused()) {
        xTimelapsePhase = TL_AXIS_IDLE;
        yTimelapsePhase = TL_AXIS_IDLE;
        xTimelapseRepeat = false;
        yTimelapseRepeat = false;
        yTimelapseInfinite = false;
    }
}

void updateTimelapseRunningFlag()
{
    bool xBusy = (xTimelapsePhase != TL_AXIS_IDLE);
    bool yBusy = (yTimelapsePhase != TL_AXIS_IDLE) || yTimelapseInfinite;

    if (!xBusy && !yBusy) {
        set_var_timelapse_running(false);
        set_var_timelpase_doing_something(false);
    }
}

void stopTimelapseMotionSoftForPause()
{
    if (xTimelapsePhase != TL_AXIS_IDLE || get_var_x_axis_movement_in_progress()) {
        sendRawMotionCommand("STOP X SOFT");
        set_var_x_axis_movement_in_progress(false);
    }

    if (yTimelapseInfinite) {
        sendRawMotionCommand("RUN Y 0");
        set_var_y_axis_movement_in_progress(false);
    } else if (yTimelapsePhase != TL_AXIS_IDLE || get_var_y_axis_movement_in_progress()) {
        sendRawMotionCommand("STOP Y SOFT");
        set_var_y_axis_movement_in_progress(false);
    }
}

void resumeTimelapseAfterPause()
{
    if (!get_var_timelapse_running() || get_var_timelapse_paused()) {
        return;
    }

    if (xTimelapsePhase == TL_AXIS_TO_START) {
        sendTimelapseMoveXToSteps(get_var_position_a());
    } else if (xTimelapsePhase == TL_AXIS_TO_END) {
        sendTimelapseMoveXToSteps(get_var_position_b());
    }

    if (yTimelapseInfinite) {
        sendTimelapseInfiniteYRun();
    } else if (yTimelapsePhase == TL_AXIS_TO_START) {
        sendTimelapseMoveYToSteps(get_var_position_c());
    } else if (yTimelapsePhase == TL_AXIS_TO_END) {
        sendTimelapseMoveYToSteps(get_var_position_d());
    }
}

void handleTimelapseDoneX()
{
    if (xPreparePending) {
        xPreparePending = false;
        if (!xPreparePending && !yPreparePending) {
            set_var_timelapse_prepare_complete(true);
        }
    }

    if (get_var_timelapse_paused()) {
        return;
    }

    if (xTimelapsePhase == TL_AXIS_IDLE) {
        updateTimelapseRunningFlag();
        return;
    }

    if (xTimelapsePhase == TL_AXIS_TO_START) {
        sendTimelapseMoveXToSteps(get_var_position_b());
        xTimelapsePhase = TL_AXIS_TO_END;
        return;
    }

    if (xTimelapsePhase == TL_AXIS_TO_END) {
        if (xTimelapseRepeat) {
            sendTimelapseMoveXToSteps(get_var_position_a());
            xTimelapsePhase = TL_AXIS_TO_START;
        } else {
            xTimelapsePhase = TL_AXIS_IDLE;
            xTimelapseRepeat = false;
            updateTimelapseRunningFlag();
        }
    }
}

void handleTimelapseDoneY()
{
    if (yPreparePending) {
        yPreparePending = false;
        if (!xPreparePending && !yPreparePending) {
            set_var_timelapse_prepare_complete(true);
        }
    }

    if (get_var_timelapse_paused()) {
        return;
    }

    if (yTimelapseInfinite) {
        return;
    }

    if (yTimelapsePhase == TL_AXIS_IDLE) {
        updateTimelapseRunningFlag();
        return;
    }

    if (yTimelapsePhase == TL_AXIS_TO_START) {
        sendTimelapseMoveYToSteps(get_var_position_d());
        yTimelapsePhase = TL_AXIS_TO_END;
        return;
    }

    if (yTimelapsePhase == TL_AXIS_TO_END) {
        if (yTimelapseRepeat) {
            sendTimelapseMoveYToSteps(get_var_position_c());
            yTimelapsePhase = TL_AXIS_TO_START;
        } else {
            yTimelapsePhase = TL_AXIS_IDLE;
            yTimelapseRepeat = false;
            updateTimelapseRunningFlag();
        }
    }
}

void startTimelapseIfRequested()
{
    if (!get_var_timelapse_start_requested()) {
        return;
    }

    if (get_var_timelapse_running()) {
        set_var_timelapse_start_requested(false);
        return;
    }

    xTimelapsePhase = TL_AXIS_IDLE;
    yTimelapsePhase = TL_AXIS_IDLE;
    xTimelapseRepeat = false;
    yTimelapseRepeat = false;
    yTimelapseInfinite = false;

    bool anyMovementStarted = false;

    /* X axis */
    if (get_var_x_ato_b_movement() || get_var_x_ato_brepeated_movement()) {
        float xSpeedSteps = getXTimelapseSpeedStepsPerSec();
        int32_t xAccelSteps = getXTimelapseAccelStepsPerSec2();

        if (xSpeedSteps > 0.0f && xAccelSteps > 0 && get_var_position_a() != get_var_position_b()) {
            sendTimelapseMoveXToSteps(get_var_position_a());
            xTimelapsePhase = TL_AXIS_TO_START;
            xTimelapseRepeat = get_var_x_ato_brepeated_movement();
            anyMovementStarted = true;
        }
    }

    /* Y axis */
    if (get_var_y_cto_d_movement() || get_var_y_cto_drepeated_movement()) {
        float ySpeedSteps = getYTimelapseSpeedStepsPerSec();
        int32_t yAccelSteps = getYTimelapseAccelStepsPerSec2();

        if (ySpeedSteps != 0.0f && yAccelSteps > 0 && get_var_position_c() != get_var_position_d()) {
            sendTimelapseMoveYToSteps(get_var_position_c());
            yTimelapsePhase = TL_AXIS_TO_START;
            yTimelapseRepeat = get_var_y_cto_drepeated_movement();
            anyMovementStarted = true;
        }
    } else if (get_var_y_infinate_movement()) {
        float ySpeedSteps = (float)get_var_tl_y_speed_mms() * Y_STEPS_PER_DEGREE;

        if (ySpeedSteps != 0.0f) {
            sendTimelapseInfiniteYRun();
            yTimelapseInfinite = true;
            anyMovementStarted = true;
        }
    }

    if (anyMovementStarted) {
        set_var_timelapse_paused(false);
        set_var_timelapse_running(true);
        set_var_timelpase_doing_something(true);
    } else {
        set_var_timelapse_running(false);
        set_var_timelpase_doing_something(false);
    }
}

void handleTimelapsePauseResume()
{
    bool currentPaused = get_var_timelapse_paused();

    if (currentPaused && !lastSeenTimelapsePaused) {
        if (get_var_timelapse_running()) {
            stopTimelapseMotionSoftForPause();
        }
    } else if (!currentPaused && lastSeenTimelapsePaused) {
        if (get_var_timelapse_running()) {
            resumeTimelapseAfterPause();
        }
    }

    lastSeenTimelapsePaused = currentPaused;
}

void handlePrepareRequest()
{
    if (!get_var_timelapse_prepare_requested()) {
        return;
    }

    xPreparePending = false;
    yPreparePending = false;

    bool xNeeded = get_var_x_ato_b_movement() || get_var_x_ato_brepeated_movement();
    bool yNeeded = get_var_y_cto_d_movement() || get_var_y_cto_drepeated_movement() || get_var_y_infinate_movement();

    if (xNeeded && get_var_position_a() != get_var_position_b()) {
        sendPrepareMoveXToA();
        xPreparePending = true;
    }

    if (yNeeded && get_var_position_c() != get_var_position_d()) {
        sendPrepareMoveYToC();
        yPreparePending = true;
    }

    set_var_timelapse_prepare_requested(false);

    if (!xPreparePending && !yPreparePending) {
        set_var_timelapse_prepare_complete(true);
    }
}

/* ===== GENERIC SEND ===== */
void processMotionCoprocessorMessage()
{
    const char *msg = get_var_message_to_send_to_motion_coprocessor();

    if (msg == nullptr) return;

    if (strcmp(msg, "Null") != 0 && strlen(msg) > 0) {
        sendRawMotionCommand(msg);
        set_var_message_to_send_to_motion_coprocessor("Null");
    }
}

/* ===== RECEIVE ===== */
void handleMotionCoprocessorMessage(const char *msg)
{
    if (!msg || strlen(msg) == 0) return;

    set_var_message_received_from_motion_coprocessor(msg);

    if (strcmp(msg, "DONE X") == 0) {
        set_var_x_axis_movement_in_progress(false);
        handleTimelapseDoneX();
        return;
    }

    if (strcmp(msg, "DONE Y") == 0) {
        set_var_y_axis_movement_in_progress(false);
        handleTimelapseDoneY();
        return;
    }

    char axis = 0;
    long travel = 0;
    long pos = 0;

    int matched = sscanf(msg, "EV HOME_DONE %c TRAVEL %ld POS %ld", &axis, &travel, &pos);

    if (matched == 3 && axis == 'X') {
        set_var_homedor_not(true);
        set_var_available_travel_x((int32_t)travel);
        set_var_current_position_x((int32_t)pos);
        set_var_homing_requested(false);
    }

    if (matched == 3 && axis == 'Y') {
        // No Y homing handling required
    }
}

void processMotionCoprocessorIncoming()
{
    static char buffer[128];
    static uint8_t idx = 0;

    while (MotionSerial.available()) {
        char c = MotionSerial.read();

        if (c == '\n' || c == '\r') {
            if (idx > 0) {
                buffer[idx] = '\0';
                handleMotionCoprocessorMessage(buffer);
                idx = 0;
            }
        } else {
            if (idx < sizeof(buffer) - 1) {
                buffer[idx++] = c;
            }
        }
    }
}

/* ===== SETUP ===== */
void setup()
{
    Serial.begin(115200);
    delay(200);

    initMotionCoprocessorSerial();

    set_var_message_to_send_to_motion_coprocessor("Null");
    set_var_message_received_from_motion_coprocessor("Null");

    set_var_homedor_not(false);
    set_var_homing_requested(false);

    set_var_position_to_move_x_to(0);
    set_var_x_axis_speed(1000);
    set_var_x_axis_accelration(700);
    set_var_x_axis_movement_in_progress(false);

    set_var_position_to_move_y_to(0);
    set_var_y_axis_speed(1000);
    set_var_y_axis_accel(700);
    set_var_y_axis_movement_in_progress(false);
    set_var_y_axis_increment_step(600);

    set_var_tl_x_speed_mms(0);
    set_var_tl_x_duration_s(0);
    set_var_tl_y_speed_mms(0);
    set_var_tl_y_duration_s(0);

    set_var_timelapse_running(false);
    set_var_timelapse_start_requested(false);
    set_var_timelapse_paused(false);
    set_var_timelpase_doing_something(false);
    set_var_timelapse_prepare_requested(false);
    set_var_timelapse_prepare_complete(false);

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    touch.setCal(494, 3506, 817, 3371, 320, 240, 1);

    lv_init();
    lv_tick_set_cb(my_tick);

    lv_display_t * disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, my_touchpad_read);

    ui_init();

    Serial.println("Setup done");
}

/* ===== LOOP ===== */
void loop()
{
    ui_tick();
    lv_timer_handler();

    watchForXMoveRequest();
    watchForYMoveRequest();
    watchXSpeedDurationCalculation();
    watchYSpeedDurationCalculation();

    resetTimelapseStateIfAbandoned();
    handlePrepareRequest();
    startTimelapseIfRequested();
    handleTimelapsePauseResume();

    processMotionCoprocessorMessage();
    processMotionCoprocessorIncoming();

    delay(5);
}