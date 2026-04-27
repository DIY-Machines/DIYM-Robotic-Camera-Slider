#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_END_POINT_MESSAGE_READ = 0,
    FLOW_GLOBAL_VARIABLE_POSITION_A_SET = 1,
    FLOW_GLOBAL_VARIABLE_POSITION_B_SET = 2,
    FLOW_GLOBAL_VARIABLE_POSITION_C_SET = 3,
    FLOW_GLOBAL_VARIABLE_POSITION_D_SET = 4
};

// Native global variables

extern bool get_var_homing_requested();
extern void set_var_homing_requested(bool value);
extern const char *get_var_message_to_send_to_motion_coprocessor();
extern void set_var_message_to_send_to_motion_coprocessor(const char *value);
extern bool get_var_homedor_not();
extern void set_var_homedor_not(bool value);
extern const char *get_var_message_received_from_motion_coprocessor();
extern void set_var_message_received_from_motion_coprocessor(const char *value);
extern int32_t get_var_available_travel_x();
extern void set_var_available_travel_x(int32_t value);
extern int32_t get_var_current_position_x();
extern void set_var_current_position_x(int32_t value);
extern bool get_var_x_ato_b_movement();
extern void set_var_x_ato_b_movement(bool value);
extern bool get_var_x_ato_brepeated_movement();
extern void set_var_x_ato_brepeated_movement(bool value);
extern bool get_var_y_cto_d_movement();
extern void set_var_y_cto_d_movement(bool value);
extern bool get_var_y_cto_drepeated_movement();
extern void set_var_y_cto_drepeated_movement(bool value);
extern bool get_var_y_infinate_movement();
extern void set_var_y_infinate_movement(bool value);
extern bool get_var_x_none_movement();
extern void set_var_x_none_movement(bool value);
extern bool get_var_y_none_movement();
extern void set_var_y_none_movement(bool value);
extern int32_t get_var_position_a();
extern void set_var_position_a(int32_t value);
extern int32_t get_var_position_b();
extern void set_var_position_b(int32_t value);
extern int32_t get_var_position_c();
extern void set_var_position_c(int32_t value);
extern int32_t get_var_position_d();
extern void set_var_position_d(int32_t value);
extern int32_t get_var_xslider_bar_position();
extern void set_var_xslider_bar_position(int32_t value);
extern int32_t get_var_position_to_move_x_to();
extern void set_var_position_to_move_x_to(int32_t value);
extern int32_t get_var_x_axis_speed();
extern void set_var_x_axis_speed(int32_t value);
extern int32_t get_var_x_axis_accelration();
extern void set_var_x_axis_accelration(int32_t value);
extern bool get_var_x_axis_movement_in_progress();
extern void set_var_x_axis_movement_in_progress(bool value);
extern int32_t get_var_position_to_move_y_to();
extern void set_var_position_to_move_y_to(int32_t value);
extern int32_t get_var_y_axis_increment_step();
extern void set_var_y_axis_increment_step(int32_t value);
extern int32_t get_var_y_axis_speed();
extern void set_var_y_axis_speed(int32_t value);
extern int32_t get_var_y_axis_accel();
extern void set_var_y_axis_accel(int32_t value);
extern bool get_var_y_axis_movement_in_progress();
extern void set_var_y_axis_movement_in_progress(bool value);
extern bool get_var_sot_x_speed_or_duration();
extern void set_var_sot_x_speed_or_duration(bool value);
extern bool get_var_sot_y_speed_or_duration();
extern void set_var_sot_y_speed_or_duration(bool value);
extern const char *get_var_universal_keyboard_keyboard_edit_target();
extern void set_var_universal_keyboard_keyboard_edit_target(const char *value);
extern const char *get_var_universal_keyboard_text_buffer();
extern void set_var_universal_keyboard_text_buffer(const char *value);
extern int32_t get_var_tl_x_speed_mms();
extern void set_var_tl_x_speed_mms(int32_t value);
extern int32_t get_var_tl_x_duration_s();
extern void set_var_tl_x_duration_s(int32_t value);
extern int32_t get_var_tl_y_duration_s();
extern void set_var_tl_y_duration_s(int32_t value);
extern int32_t get_var_tl_y_speed_mms();
extern void set_var_tl_y_speed_mms(int32_t value);
extern bool get_var_timelapse_start_requested();
extern void set_var_timelapse_start_requested(bool value);
extern bool get_var_timelapse_running();
extern void set_var_timelapse_running(bool value);
extern bool get_var_timelapse_paused();
extern void set_var_timelapse_paused(bool value);
extern bool get_var_timelapse_prepare_requested();
extern void set_var_timelapse_prepare_requested(bool value);
extern bool get_var_timelapse_prepare_complete();
extern void set_var_timelapse_prepare_complete(bool value);
extern bool get_var_timelpase_doing_something();
extern void set_var_timelpase_doing_something(bool value);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/