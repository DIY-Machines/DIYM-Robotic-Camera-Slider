#include "HardwareSerial.h"
#include <stdint.h>
#include "vars.h"
#include <string>
#include <Arduino.h>


int32_t sliderspeed;

extern "C" int32_t get_var_sliderspeed() {
    return sliderspeed;
}

extern "C" void set_var_sliderspeed(int32_t value) {
    sliderspeed = value;
}

bool homing_requested;

extern "C" bool get_var_homing_requested() {
    return homing_requested;
}

extern "C" void set_var_homing_requested(bool value) {
    homing_requested = value;
}


std::string message_to_send_to_motion_coprocessor;

extern "C" const char *get_var_message_to_send_to_motion_coprocessor() {
    return message_to_send_to_motion_coprocessor.c_str();
}

extern "C" void set_var_message_to_send_to_motion_coprocessor(const char *value) {
    message_to_send_to_motion_coprocessor = value;
}

bool homedor_not;

extern "C" bool get_var_homedor_not() {
    return homedor_not;
}

extern "C" void set_var_homedor_not(bool value) {
    homedor_not = value;
}


std::string message_received_from_motion_coprocessor;

extern "C" const char *get_var_message_received_from_motion_coprocessor() {
    return message_received_from_motion_coprocessor.c_str();
}

extern "C" void set_var_message_received_from_motion_coprocessor(const char *value) {
    message_received_from_motion_coprocessor = value;
}

int32_t available_travel_x;

extern "C" int32_t get_var_available_travel_x() {
    return available_travel_x;
}

extern "C" void set_var_available_travel_x(int32_t value) {
    available_travel_x = value;
}

int32_t current_position_x;

extern "C" int32_t get_var_current_position_x() {
    return current_position_x;
}

extern "C" void set_var_current_position_x(int32_t value) {
    current_position_x = value;
}

bool x_ato_b_movement;

extern "C" bool get_var_x_ato_b_movement() {
    return x_ato_b_movement;
}

extern "C" void set_var_x_ato_b_movement(bool value) {
    x_ato_b_movement = value;
}

bool x_ato_brepeated_movement;

extern "C" bool get_var_x_ato_brepeated_movement() {
    return x_ato_brepeated_movement;
}

extern "C" void set_var_x_ato_brepeated_movement(bool value) {
    x_ato_brepeated_movement = value;
}

bool y_cto_d_movement;

extern "C" bool get_var_y_cto_d_movement() {
    return y_cto_d_movement;
}

extern "C" void set_var_y_cto_d_movement(bool value) {
    y_cto_d_movement = value;
}

bool y_cto_drepeated_movement;

extern "C" bool get_var_y_cto_drepeated_movement() {
    return y_cto_drepeated_movement;
}

extern "C" void set_var_y_cto_drepeated_movement(bool value) {
    y_cto_drepeated_movement = value;
}

bool y_infinate_movement;

extern "C" bool get_var_y_infinate_movement() {
    return y_infinate_movement;
}

extern "C" void set_var_y_infinate_movement(bool value) {
    y_infinate_movement = value;
}

bool x_none_movement;

extern "C" bool get_var_x_none_movement() {
    return x_none_movement;
}

extern "C" void set_var_x_none_movement(bool value) {
    x_none_movement = value;
}

bool y_none_movement;

extern "C" bool get_var_y_none_movement() {
    return y_none_movement;
}

extern "C" void set_var_y_none_movement(bool value) {
    y_none_movement = value;
}

int32_t position_a;

extern "C" int32_t get_var_position_a() {
    return position_a;
}

extern "C" void set_var_position_a(int32_t value) {
    position_a = value;
}

int32_t position_b;

extern "C" int32_t get_var_position_b() {
    return position_b;
}

extern "C" void set_var_position_b(int32_t value) {
    position_b = value;
}

int32_t position_c;

extern "C" int32_t get_var_position_c() {
    return position_c;
}

extern "C" void set_var_position_c(int32_t value) {
    position_c = value;
}

int32_t position_d;

extern "C" int32_t get_var_position_d() {
    return position_d;
}

extern "C" void set_var_position_d(int32_t value) {
    position_d = value;
}

int32_t xslider_bar_position;

extern "C" int32_t get_var_xslider_bar_position() {
    return xslider_bar_position;
}

extern "C" void set_var_xslider_bar_position(int32_t value) {
    xslider_bar_position = value;
}

int32_t position_to_move_x_to;

extern "C" int32_t get_var_position_to_move_x_to() {
    return position_to_move_x_to;
}

extern "C" void set_var_position_to_move_x_to(int32_t value) {
    position_to_move_x_to = value;
}

int32_t x_axis_speed;

extern "C" int32_t get_var_x_axis_speed() {
    return x_axis_speed;
}

extern "C" void set_var_x_axis_speed(int32_t value) {
    x_axis_speed = value;
}

int32_t x_axis_accelration;

extern "C" int32_t get_var_x_axis_accelration() {
    return x_axis_accelration;
}

extern "C" void set_var_x_axis_accelration(int32_t value) {
    x_axis_accelration = value;
}

bool x_axis_movement_in_progress;

extern "C" bool get_var_x_axis_movement_in_progress() {
    return x_axis_movement_in_progress;
}

extern "C" void set_var_x_axis_movement_in_progress(bool value) {
    x_axis_movement_in_progress = value;
}

int32_t position_to_move_y_to;

extern "C" int32_t get_var_position_to_move_y_to() {
    return position_to_move_y_to;
}

extern "C" void set_var_position_to_move_y_to(int32_t value) {
    position_to_move_y_to = value;
}

int32_t y_axis_increment_step;

extern "C" int32_t get_var_y_axis_increment_step() {
    return y_axis_increment_step;
}

extern "C" void set_var_y_axis_increment_step(int32_t value) {
    y_axis_increment_step = value;
}

int32_t y_axis_speed;

extern "C" int32_t get_var_y_axis_speed() {
    return y_axis_speed;
}

extern "C" void set_var_y_axis_speed(int32_t value) {
    y_axis_speed = value;
}

int32_t y_axis_accel;

extern "C" int32_t get_var_y_axis_accel() {
    return y_axis_accel;
}

extern "C" void set_var_y_axis_accel(int32_t value) {
    y_axis_accel = value;
}

bool y_axis_movement_in_progress;

extern "C" bool get_var_y_axis_movement_in_progress() {
    return y_axis_movement_in_progress;
}

extern "C" void set_var_y_axis_movement_in_progress(bool value) {
    y_axis_movement_in_progress = value;
}

bool sot_y_speed_or_duration;

extern "C" bool get_var_sot_y_speed_or_duration() {
    return sot_y_speed_or_duration;
}

extern "C" void set_var_sot_y_speed_or_duration(bool value) {
    sot_y_speed_or_duration = value;
}

bool sot_x_speed_or_duration;

extern "C" bool get_var_sot_x_speed_or_duration() {
    return sot_x_speed_or_duration;
}

extern "C" void set_var_sot_x_speed_or_duration(bool value) {
    sot_x_speed_or_duration = value;
}

int32_t y_axis_duration;

extern "C" int32_t get_var_y_axis_duration() {
    return y_axis_duration;
}

extern "C" void set_var_y_axis_duration(int32_t value) {
    y_axis_duration = value;
}

int32_t x_axis_duration;

extern "C" int32_t get_var_x_axis_duration() {
    return x_axis_duration;
}

extern "C" void set_var_x_axis_duration(int32_t value) {
    x_axis_duration = value;
}

std::string universal_keyboard_keyboard_edit_target;

extern "C" const char *get_var_universal_keyboard_keyboard_edit_target() {
    return universal_keyboard_keyboard_edit_target.c_str();
}

extern "C" void set_var_universal_keyboard_keyboard_edit_target(const char *value) {
    universal_keyboard_keyboard_edit_target = value;
}

std::string universal_keyboard_text_buffer;

extern "C" const char *get_var_universal_keyboard_text_buffer() {
    return universal_keyboard_text_buffer.c_str();
}

extern "C" void set_var_universal_keyboard_text_buffer(const char *value) {
    universal_keyboard_text_buffer = value;
}

int32_t tl_x_speed_mms;

extern "C" int32_t get_var_tl_x_speed_mms() {
    return tl_x_speed_mms;
}

extern "C" void set_var_tl_x_speed_mms(int32_t value) {
    tl_x_speed_mms = value;
}

int32_t tl_x_duration_s;

extern "C" int32_t get_var_tl_x_duration_s() {
    return tl_x_duration_s;
}

extern "C" void set_var_tl_x_duration_s(int32_t value) {
    tl_x_duration_s = value;
}

int32_t tl_y_duration_s;

extern "C" int32_t get_var_tl_y_duration_s() {
    return tl_y_duration_s;
}

extern "C" void set_var_tl_y_duration_s(int32_t value) {
    tl_y_duration_s = value;
}

int32_t tl_y_speed_mms;

extern "C" int32_t get_var_tl_y_speed_mms() {
    return tl_y_speed_mms;
}

extern "C" void set_var_tl_y_speed_mms(int32_t value) {
    tl_y_speed_mms = value;
}

bool timelapse_running;

extern "C" bool get_var_timelapse_running() {
    return timelapse_running;
}

extern "C" void set_var_timelapse_running(bool value) {
    timelapse_running = value;
}

bool timelapse_start_requested;

extern "C" bool get_var_timelapse_start_requested() {
    return timelapse_start_requested;
}

extern "C" void set_var_timelapse_start_requested(bool value) {
    timelapse_start_requested = value;
}

bool timelapse_paused;

extern "C" bool get_var_timelapse_paused() {
    return timelapse_paused;
}

extern "C" void set_var_timelapse_paused(bool value) {
    timelapse_paused = value;
}

bool timelapse_prepare_requested;

extern "C" bool get_var_timelapse_prepare_requested() {
    return timelapse_prepare_requested;
}

extern "C" void set_var_timelapse_prepare_requested(bool value) {
    timelapse_prepare_requested = value;
}

bool timelapse_prepare_complete;

extern "C" bool get_var_timelapse_prepare_complete() {
    return timelapse_prepare_complete;
}

extern "C" void set_var_timelapse_prepare_complete(bool value) {
    timelapse_prepare_complete = value;
}

bool timelpase_doing_something;

extern "C" bool get_var_timelpase_doing_something() {
    return timelpase_doing_something;
}

extern "C" void set_var_timelpase_doing_something(bool value) {
    timelpase_doing_something = value;
}