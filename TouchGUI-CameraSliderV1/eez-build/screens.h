#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_WELCOME_SCREEN = 1,
    SCREEN_ID_SET_MOVEMENT_STYLE = 2,
    SCREEN_ID_SET_END_POINTS = 3,
    SCREEN_ID_SET_SPEED_DURATION_OF_MOVEMENT = 4,
    SCREEN_ID_SETTINGS_HOMING = 5,
    SCREEN_ID_SETTINGS_SPEEDS = 6,
    SCREEN_ID_SETTINGS_ACCEL_ONLY = 7,
    SCREEN_ID_KEYBOARD_SCREEN = 8,
    _SCREEN_ID_LAST = 8
};

typedef struct _objects_t {
    lv_obj_t *welcome_screen;
    lv_obj_t *set_movement_style;
    lv_obj_t *set_end_points;
    lv_obj_t *set_speed_duration_of_movement;
    lv_obj_t *settings_homing;
    lv_obj_t *settings_speeds;
    lv_obj_t *settings_accel_only;
    lv_obj_t *keyboard_screen;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *settings_button;
    lv_obj_t *intro;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *intro_6;
    lv_obj_t *obj6;
    lv_obj_t *intro_1;
    lv_obj_t *intro_2;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *homing_needed;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *intro_4;
    lv_obj_t *settings_button_1;
    lv_obj_t *intro_3;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *intro_5;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *settings_button_2;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *intro_15;
    lv_obj_t *intro_16;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *intro_17;
    lv_obj_t *intro_18;
    lv_obj_t *x_axis_blocker;
    lv_obj_t *intro_7;
    lv_obj_t *y_axis_blocker;
    lv_obj_t *intro_12;
    lv_obj_t *intro_14;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *obj35;
    lv_obj_t *obj36;
    lv_obj_t *intro_9;
    lv_obj_t *settings_button_4;
    lv_obj_t *settings_button_3;
    lv_obj_t *obj37;
    lv_obj_t *y_mode_toggle;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *x_mode_toggle;
    lv_obj_t *obj40;
    lv_obj_t *intro_10;
    lv_obj_t *intro_11;
    lv_obj_t *prepare;
    lv_obj_t *start;
    lv_obj_t *pause;
    lv_obj_t *resume;
    lv_obj_t *new_program;
    lv_obj_t *hide_speed_in_deg;
    lv_obj_t *hide_speed_in_deg_1;
    lv_obj_t *hide_speed_in_deg_2;
    lv_obj_t *hide_y_speed_in_duration;
    lv_obj_t *y_axis_blocker_1;
    lv_obj_t *intro_13;
    lv_obj_t *x_axis_blocker_1;
    lv_obj_t *intro_8;
    lv_obj_t *doing_something_animation;
    lv_obj_t *homing_spinner_1;
    lv_obj_t *obj41;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *homing_spinner;
    lv_obj_t *stop_homing;
    lv_obj_t *obj45;
    lv_obj_t *homed_text;
    lv_obj_t *homed_text_1;
    lv_obj_t *homed_text_2;
    lv_obj_t *homed_text_3;
    lv_obj_t *homed_text_4;
    lv_obj_t *homed_text_5;
    lv_obj_t *settings_button_7;
    lv_obj_t *obj46;
    lv_obj_t *homed_text_6;
    lv_obj_t *obj47;
    lv_obj_t *x_speed_input;
    lv_obj_t *x_accel_input;
    lv_obj_t *y_speed_input;
    lv_obj_t *y_accel_input;
    lv_obj_t *y_step_increment_input;
    lv_obj_t *settings_button_6;
    lv_obj_t *obj48;
    lv_obj_t *homed_text_7;
    lv_obj_t *obj49;
    lv_obj_t *x_accel_input_2;
    lv_obj_t *y_accel_input_2;
    lv_obj_t *settings_button_5;
    lv_obj_t *obj50;
    lv_obj_t *universal_keyboard;
    lv_obj_t *obj51;
    lv_obj_t *save_4;
    lv_obj_t *universal_keyboard_text_area;
} objects_t;

extern objects_t objects;

void create_screen_welcome_screen();
void tick_screen_welcome_screen();

void create_screen_set_movement_style();
void tick_screen_set_movement_style();

void create_screen_set_end_points();
void tick_screen_set_end_points();

void create_screen_set_speed_duration_of_movement();
void tick_screen_set_speed_duration_of_movement();

void create_screen_settings_homing();
void tick_screen_settings_homing();

void create_screen_settings_speeds();
void tick_screen_settings_speeds();

void create_screen_settings_accel_only();
void tick_screen_settings_accel_only();

void create_screen_keyboard_screen();
void tick_screen_keyboard_screen();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/