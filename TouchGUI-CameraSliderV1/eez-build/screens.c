#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

static const char *screen_names[] = { "Welcome Screen", "Set Movement Style", "Set End Points", "Set Speed-Duration of Movement", "Settings-Homing", "Settings-Speeds", "Settings-Accel-Only", "KeyboardScreen" };
static const char *object_names[] = { "welcome_screen", "set_movement_style", "set_end_points", "set_speed_duration_of_movement", "settings_homing", "settings_speeds", "settings_accel_only", "keyboard_screen", "obj0", "obj1", "settings_button", "intro", "obj2", "obj3", "obj4", "obj5", "intro_6", "obj6", "intro_1", "intro_2", "obj7", "obj8", "obj9", "homing_needed", "obj10", "obj11", "obj12", "obj13", "obj14", "obj15", "obj16", "obj17", "obj18", "obj19", "intro_4", "settings_button_1", "intro_3", "obj20", "obj21", "obj22", "intro_5", "obj23", "obj24", "obj25", "settings_button_2", "obj26", "obj27", "intro_15", "intro_16", "obj28", "obj29", "intro_17", "intro_18", "x_axis_blocker", "intro_7", "y_axis_blocker", "intro_12", "intro_14", "obj30", "obj31", "obj32", "obj33", "obj34", "obj35", "obj36", "obj37", "obj38", "obj39", "intro_9", "settings_button_4", "settings_button_3", "obj40", "y_mode_toggle", "obj41", "obj42", "x_mode_toggle", "obj43", "intro_10", "intro_11", "prepare", "start", "pause", "resume", "new_program", "hide_speed_in_deg", "hide_speed_in_deg_1", "hide_speed_in_deg_2", "hide_y_speed_in_duration", "y_axis_blocker_1", "intro_13", "x_axis_blocker_1", "intro_8", "doing_something_animation", "homing_spinner_1", "obj44", "obj45", "obj46", "obj47", "homing_spinner", "stop_homing", "obj48", "homed_text", "homed_text_1", "homed_text_2", "homed_text_3", "homed_text_4", "homed_text_5", "settings_button_7", "obj49", "homed_text_6", "obj50", "x_speed_input", "x_accel_input", "y_speed_input", "y_accel_input", "y_step_increment_input", "settings_button_6", "obj51", "homed_text_7", "obj52", "x_accel_input_2", "y_accel_input_2", "settings_button_5", "obj53", "universal_keyboard", "obj54", "save_4", "universal_keyboard_text_area" };

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_welcome_screen_welcome_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SCREEN_LOADED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

static void event_handler_cb_set_movement_style_settings_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 7, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 9, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 11, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 13, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 16, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 22, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
}

static void event_handler_cb_set_movement_style_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 24, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 24, 0, e);
    }
}

static void event_handler_cb_set_movement_style_homing_needed(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 26, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj19(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 2, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_set_end_points_settings_button_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj20(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 10, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj21(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 12, 4, value, "Failed to assign Value in Slider widget");
        }
    }
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj22(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 13, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj23(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 16, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj24(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 18, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 0, e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 18, 1, e);
    }
}

static void event_handler_cb_set_end_points_obj25(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 20, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 0, e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 20, 1, e);
    }
}

static void event_handler_cb_set_end_points_settings_button_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 22, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj26(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 24, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 24, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj27(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 26, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 26, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj28(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 30, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 30, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj29(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 32, 3, value, "Failed to assign Checked state");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 32, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj30(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 41, 0, e);
    }
}

static void event_handler_cb_set_end_points_obj32(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 45, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_settings_button_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_settings_button_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_obj40(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 10, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_y_mode_toggle(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_obj41(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 12, 4, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_obj42(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 15, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_x_mode_toggle(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 16, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_obj43(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 17, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 17, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_prepare(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 21, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_start(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 23, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_pause(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 25, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_resume(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 0, e);
    }
}

static void event_handler_cb_set_speed_duration_of_movement_new_program(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 30, 0, e);
    }
}

static void event_handler_cb_settings_homing_obj47(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_settings_homing_stop_homing(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_settings_homing_obj48(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 8, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_settings_homing_settings_button_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_settings_speeds_obj50(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 4, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_settings_speeds_x_speed_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 5, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_settings_speeds_x_accel_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 7, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_settings_speeds_y_speed_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 9, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_settings_speeds_y_accel_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 11, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_settings_speeds_y_step_increment_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 13, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_settings_speeds_settings_button_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_settings_accel_only_obj52(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 5, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_settings_accel_only_x_accel_input_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 6, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_settings_accel_only_y_accel_input_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 8, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_settings_accel_only_settings_button_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_RELEASED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_keyboard_screen_obj54(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_keyboard_screen_universal_keyboard_text_area(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target_obj(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 4, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

//
// Screens
//

void create_screen_welcome_screen() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.welcome_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_event_cb(obj, event_handler_cb_welcome_screen_welcome_screen, LV_EVENT_ALL, flowState);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 63, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "DIY Machines");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 150, 211);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "V1");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 60, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Camera Slider");
        }
    }
    
    tick_screen_welcome_screen();
}

void tick_screen_welcome_screen() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_set_movement_style() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.set_movement_style = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 12, 148);
            lv_obj_set_size(obj, 297, 29);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdcdcd), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 55, 75);
            lv_obj_set_size(obj, 210, 29);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdcdcd), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 37);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            // Settings Button
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button = obj;
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_settings_button, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj10 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Intro
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro = obj;
            lv_obj_set_pos(obj, 68, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Decide shoot movement:");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 92, 76);
            lv_obj_set_size(obj, 82, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj2, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 180, 76);
            lv_obj_set_size(obj, 82, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj3, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj12 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 49, 149);
            lv_obj_set_size(obj, 82, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj4, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj13 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 139, 149);
            lv_obj_set_size(obj, 82, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj5, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj14 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Intro_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_6 = obj;
            lv_obj_set_pos(obj, 60, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "No movements to execute");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 225, 149);
            lv_obj_set_size(obj, 82, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj6, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj15 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Intro_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_1 = obj;
            lv_obj_set_pos(obj, 139, 53);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "X Axis");
        }
        {
            // Intro_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_2 = obj;
            lv_obj_set_pos(obj, 140, 124);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Y Axis");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 52, 198);
            lv_obj_set_size(obj, 208, 31);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj7, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj16 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 57, 76);
            lv_obj_set_size(obj, 30, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj8, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj17 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 14, 149);
            lv_obj_set_size(obj, 30, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_obj9, LV_EVENT_ALL, flowState);
            add_style_buttons_status(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj18 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Homing needed
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.homing_needed = obj;
            lv_obj_set_pos(obj, 53, 182);
            lv_obj_set_size(obj, 208, 31);
            lv_obj_add_event_cb(obj, event_handler_cb_set_movement_style_homing_needed, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Let's home the X axis...");
                }
            }
        }
    }
    
    tick_screen_set_movement_style();
}

void tick_screen_set_movement_style() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj10;
            lv_label_set_text(objects.obj10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 7, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj2, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj2;
            if (new_val) {
                lv_obj_add_state(objects.obj2, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj2, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj11;
            lv_label_set_text(objects.obj11, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj3, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj3;
            if (new_val) {
                lv_obj_add_state(objects.obj3, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj3, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj12;
            lv_label_set_text(objects.obj12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj4, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj4;
            if (new_val) {
                lv_obj_add_state(objects.obj4, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj4, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj13);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj13;
            lv_label_set_text(objects.obj13, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj5, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj5;
            if (new_val) {
                lv_obj_add_state(objects.obj5, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj5, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj14;
            lv_label_set_text(objects.obj14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 16, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj6, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj6;
            if (new_val) {
                lv_obj_add_state(objects.obj6, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj6, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj15);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj15;
            lv_label_set_text(objects.obj15, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 20, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj7;
            if (new_val) {
                lv_obj_add_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj7, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 21, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj16);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj16;
            lv_label_set_text(objects.obj16, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 22, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj8, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj8;
            if (new_val) {
                lv_obj_add_state(objects.obj8, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj8, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 23, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj17);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj17;
            lv_label_set_text(objects.obj17, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj9, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj9;
            if (new_val) {
                lv_obj_add_state(objects.obj9, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj9, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj18);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj18;
            lv_label_set_text(objects.obj18, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 26, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homing_needed, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homing_needed;
            if (new_val) {
                lv_obj_add_flag(objects.homing_needed, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homing_needed, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_set_end_points() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.set_end_points = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 134);
            lv_obj_set_size(obj, 320, 65);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 14, 95);
            lv_obj_set_size(obj, 56, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj19, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Set");
                }
            }
        }
        {
            // Intro_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_4 = obj;
            lv_obj_set_pos(obj, 140, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "X Axis");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 37);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            // Settings Button_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_1 = obj;
            lv_obj_set_pos(obj, 6, 5);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_settings_button_1, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj33 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Intro_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_3 = obj;
            lv_obj_set_pos(obj, 109, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set Endpoints");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj34 = obj;
            lv_obj_set_pos(obj, 10, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 186, 96);
            lv_obj_set_size(obj, 56, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj20, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Set");
                }
            }
        }
        {
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 13, 61);
            lv_obj_set_size(obj, 297, 10);
            lv_slider_set_range(obj, 0, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj21, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_image_src(obj, &img_camera_slider_icon_20, LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 6, 165);
            lv_obj_set_size(obj, 50, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj22, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Set");
                }
            }
        }
        {
            // Intro_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_5 = obj;
            lv_obj_set_pos(obj, 139, 142);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Y Axis");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 212, 165);
            lv_obj_set_size(obj, 50, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj23, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Set");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 119, 165);
            lv_obj_set_size(obj, 40, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj24, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj35 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 166, 165);
            lv_obj_set_size(obj, 40, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj25, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj36 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Settings Button_2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_2 = obj;
            lv_obj_set_pos(obj, 283, 5);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_settings_button_2, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj37 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 81, 96);
            lv_obj_set_size(obj, 56, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj26, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Got To");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 254, 96);
            lv_obj_set_size(obj, 56, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj27, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Go To");
                }
            }
        }
        {
            // Intro_15
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_15 = obj;
            lv_obj_set_pos(obj, 39, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Position A");
        }
        {
            // Intro_16
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_16 = obj;
            lv_obj_set_pos(obj, 215, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Position B");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 62, 165);
            lv_obj_set_size(obj, 50, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj28, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Go to");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj29 = obj;
            lv_obj_set_pos(obj, 266, 165);
            lv_obj_set_size(obj, 50, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj29, LV_EVENT_ALL, flowState);
            add_style_end_point_buttons(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Go to");
                }
            }
        }
        {
            // Intro_17
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_17 = obj;
            lv_obj_set_pos(obj, 26, 142);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Position C");
        }
        {
            // Intro_18
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_18 = obj;
            lv_obj_set_pos(obj, 226, 142);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Position D");
        }
        {
            // X Axis Blocker
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.x_axis_blocker = obj;
            lv_obj_set_pos(obj, -9, 38);
            lv_obj_set_size(obj, 329, 94);
            lv_obj_set_style_bg_opa(obj, 230, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Intro_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.intro_7 = obj;
                    lv_obj_set_pos(obj, 93, 23);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "(X Axis not in use)");
                }
            }
        }
        {
            // Y Axis Blocker
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.y_axis_blocker = obj;
            lv_obj_set_pos(obj, -9, 134);
            lv_obj_set_size(obj, 329, 66);
            lv_obj_set_style_bg_opa(obj, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Intro_12
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.intro_12 = obj;
                    lv_obj_set_pos(obj, 92, 9);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "(Y Axis not in use)");
                }
                {
                    // Intro_14
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.intro_14 = obj;
                    lv_obj_set_pos(obj, 29, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set rotation speed on next screen...");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj30 = obj;
            lv_obj_set_pos(obj, 12, 201);
            lv_obj_set_size(obj, 297, 31);
            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj30, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj38 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj31 = obj;
            lv_obj_set_pos(obj, 10, 45);
            lv_obj_set_size(obj, 300, 187);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffcdcdcd), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj39 = obj;
                    lv_obj_set_pos(obj, -5, 2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Set the endpoints for your shot\n\nDouble Tap on a position moves to that\nsaved position (if one has been saved)\n\n'Long Pressing' on a position saves\nthe sliders current position to memory");
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.obj32 = obj;
                            lv_obj_set_pos(obj, 81, 129);
                            lv_obj_set_size(obj, 100, 26);
                            lv_obj_add_event_cb(obj, event_handler_cb_set_end_points_obj32, LV_EVENT_ALL, flowState);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "OK");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_set_end_points();
}

void tick_screen_set_end_points() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    {
        bool new_val = evalBooleanProperty(flowState, 2, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj19, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj19;
            if (new_val) {
                lv_obj_add_state(objects.obj19, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj19, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj33);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj33;
            lv_label_set_text(objects.obj33, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj34);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj34;
            lv_label_set_text(objects.obj34, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj20, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj20;
            if (new_val) {
                lv_obj_add_state(objects.obj20, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj20, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 12, 3, "Failed to evaluate Max in Slider widget");
        int32_t cur_val = lv_slider_get_max_value(objects.obj21);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            int16_t min = lv_slider_get_min_value(objects.obj21);
            int16_t max = new_val;
            if (min < max) {
                lv_slider_set_range(objects.obj21, min, max);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 12, 4, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.obj21);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj21;
            lv_slider_set_value(objects.obj21, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj22, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj22;
            if (new_val) {
                lv_obj_add_state(objects.obj22, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj22, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 16, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj23, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj23;
            if (new_val) {
                lv_obj_add_state(objects.obj23, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj23, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 18, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj24, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj24;
            if (new_val) {
                lv_obj_add_state(objects.obj24, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj24, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj35);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj35;
            lv_label_set_text(objects.obj35, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 20, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj25, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj25;
            if (new_val) {
                lv_obj_add_state(objects.obj25, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj25, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 21, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj36);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj36;
            lv_label_set_text(objects.obj36, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 23, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj37);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj37;
            lv_label_set_text(objects.obj37, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 24, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj26, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj26;
            if (new_val) {
                lv_obj_add_state(objects.obj26, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj26, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 26, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj27, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj27;
            if (new_val) {
                lv_obj_add_state(objects.obj27, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj27, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 30, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj28, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj28;
            if (new_val) {
                lv_obj_add_state(objects.obj28, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj28, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 32, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj29, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj29;
            if (new_val) {
                lv_obj_add_state(objects.obj29, LV_STATE_CHECKED);
            } else {
                lv_obj_remove_state(objects.obj29, LV_STATE_CHECKED);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 36, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.x_axis_blocker, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.x_axis_blocker;
            if (new_val) {
                lv_obj_add_flag(objects.x_axis_blocker, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.x_axis_blocker, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 38, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.y_axis_blocker, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.y_axis_blocker;
            if (new_val) {
                lv_obj_add_flag(objects.y_axis_blocker, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.y_axis_blocker, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 39, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.intro_12, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.intro_12;
            if (new_val) {
                lv_obj_add_flag(objects.intro_12, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.intro_12, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 40, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.intro_14, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.intro_14;
            if (new_val) {
                lv_obj_add_flag(objects.intro_14, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.intro_14, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 41, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj30, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj30;
            if (new_val) {
                lv_obj_add_flag(objects.obj30, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj30, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 42, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj38);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj38;
            lv_label_set_text(objects.obj38, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 43, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj31, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj31;
            if (new_val) {
                lv_obj_add_flag(objects.obj31, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj31, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 44, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj39, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj39;
            if (new_val) {
                lv_obj_add_flag(objects.obj39, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj39, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 45, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj32, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj32;
            if (new_val) {
                lv_obj_add_flag(objects.obj32, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj32, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_set_speed_duration_of_movement() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.set_speed_duration_of_movement = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 37);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            // Intro_9
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_9 = obj;
            lv_obj_set_pos(obj, 91, 11);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set Speed of Travel");
        }
        {
            // Settings Button_4
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_4 = obj;
            lv_obj_set_pos(obj, 283, 5);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_settings_button_4, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj44 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // Settings Button_3
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_3 = obj;
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, 29, 27);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_settings_button_3, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj45 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 106);
            lv_obj_set_size(obj, 320, 74);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj46 = obj;
            lv_obj_set_pos(obj, 221, 114);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Duration (s)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 31, 114);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Speed (deg/s)");
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj40 = obj;
            lv_obj_set_pos(obj, 34, 135);
            lv_obj_set_size(obj, 96, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_obj40, LV_EVENT_ALL, flowState);
        }
        {
            // Y-Mode-Toggle
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.y_mode_toggle = obj;
            lv_obj_set_pos(obj, 143, 135);
            lv_obj_set_size(obj, 64, 22);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_y_mode_toggle, LV_EVENT_ALL, flowState);
            add_style_checked_slider_toggle(obj);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff9a9696), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj41 = obj;
            lv_obj_set_pos(obj, 216, 135);
            lv_obj_set_size(obj, 96, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_obj41, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 221, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_opa(obj, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Duration (s)");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 31, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Speed (mm/s)");
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj42 = obj;
            lv_obj_set_pos(obj, 34, 63);
            lv_obj_set_size(obj, 96, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_obj42, LV_EVENT_ALL, flowState);
        }
        {
            // X-Mode-Toggle
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.x_mode_toggle = obj;
            lv_obj_set_pos(obj, 143, 64);
            lv_obj_set_size(obj, 64, 22);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_x_mode_toggle, LV_EVENT_ALL, flowState);
            add_style_checked_slider_toggle(obj);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff9a9696), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj43 = obj;
            lv_obj_set_pos(obj, 216, 63);
            lv_obj_set_size(obj, 96, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_obj43, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 167, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "or");
        }
        {
            // Intro_10
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_10 = obj;
            lv_obj_set_pos(obj, 6, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "X");
        }
        {
            // Intro_11
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intro_11 = obj;
            lv_obj_set_pos(obj, 7, 130);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Y");
        }
        {
            // Prepare
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.prepare = obj;
            lv_obj_set_pos(obj, 12, 187);
            lv_obj_set_size(obj, 139, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_prepare, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Start Positions");
                }
            }
        }
        {
            // Start
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.start = obj;
            lv_obj_set_pos(obj, 12, 187);
            lv_obj_set_size(obj, 139, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_start, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff89d543), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Start");
                }
            }
        }
        {
            // Pause
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.pause = obj;
            lv_obj_set_pos(obj, 12, 187);
            lv_obj_set_size(obj, 139, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_pause, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PAUSE");
                }
            }
        }
        {
            // Resume
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.resume = obj;
            lv_obj_set_pos(obj, 12, 187);
            lv_obj_set_size(obj, 139, 45);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_resume, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "RESUME");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 167, 112);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "or");
        }
        {
            // New Program
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.new_program = obj;
            lv_obj_set_pos(obj, 169, 194);
            lv_obj_set_size(obj, 138, 31);
            lv_obj_add_event_cb(obj, event_handler_cb_set_speed_duration_of_movement_new_program, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe86161), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "New Program");
                }
            }
        }
        {
            // Hide speed in deg
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.hide_speed_in_deg = obj;
            lv_obj_set_pos(obj, 26, 112);
            lv_obj_set_size(obj, 117, 68);
            add_style_square_box2(obj);
        }
        {
            // Hide speed in deg_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.hide_speed_in_deg_1 = obj;
            lv_obj_set_pos(obj, 29, 38);
            lv_obj_set_size(obj, 114, 67);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Hide speed in deg_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.hide_speed_in_deg_2 = obj;
            lv_obj_set_pos(obj, 207, 42);
            lv_obj_set_size(obj, 105, 57);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Hide Y speed in duration
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.hide_y_speed_in_duration = obj;
            lv_obj_set_pos(obj, 216, 114);
            lv_obj_set_size(obj, 104, 66);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            // Y Axis Blocker_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.y_axis_blocker_1 = obj;
            lv_obj_set_pos(obj, -9, 114);
            lv_obj_set_size(obj, 329, 70);
            lv_obj_set_style_bg_opa(obj, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Intro_13
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.intro_13 = obj;
                    lv_obj_set_pos(obj, 93, 14);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "(Y Axis not in use)");
                }
            }
        }
        {
            // X Axis Blocker_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.x_axis_blocker_1 = obj;
            lv_obj_set_pos(obj, -9, 40);
            lv_obj_set_size(obj, 329, 73);
            lv_obj_set_style_bg_opa(obj, 230, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Intro_8
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.intro_8 = obj;
                    lv_obj_set_pos(obj, 93, 14);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "(X Axis not in use)");
                }
            }
        }
        {
            // Doing something animation
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.doing_something_animation = obj;
            lv_obj_set_pos(obj, 0, 37);
            lv_obj_set_size(obj, 320, 143);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // HomingSpinner_1
                    lv_obj_t *obj = lv_spinner_create(parent_obj);
                    objects.homing_spinner_1 = obj;
                    lv_obj_set_pos(obj, 89, 7);
                    lv_obj_set_size(obj, 112, 95);
                }
            }
        }
    }
    
    tick_screen_set_speed_duration_of_movement();
}

void tick_screen_set_speed_duration_of_movement() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj44);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj44;
            lv_label_set_text(objects.obj44, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj45);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj45;
            lv_label_set_text(objects.obj45, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 8, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj46, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj46;
            if (new_val) {
                lv_obj_add_flag(objects.obj46, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj46, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj40);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj40);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj40;
            lv_textarea_set_text(objects.obj40, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.y_mode_toggle, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.y_mode_toggle;
            if (new_val) {
                lv_obj_add_flag(objects.y_mode_toggle, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.y_mode_toggle, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 4, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj41);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj41);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj41;
            lv_textarea_set_text(objects.obj41, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj41, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj41;
            if (new_val) {
                lv_obj_add_flag(objects.obj41, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj41, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj42);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj42);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj42;
            lv_textarea_set_text(objects.obj42, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj43);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj43);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj43;
            lv_textarea_set_text(objects.obj43, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 21, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.prepare, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.prepare;
            if (new_val) {
                lv_obj_add_flag(objects.prepare, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.prepare, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 23, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.start, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.start;
            if (new_val) {
                lv_obj_add_flag(objects.start, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.start, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 25, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.pause, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.pause;
            if (new_val) {
                lv_obj_add_flag(objects.pause, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.pause, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 27, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.resume, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.resume;
            if (new_val) {
                lv_obj_add_flag(objects.resume, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.resume, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 30, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.new_program, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.new_program;
            if (new_val) {
                lv_obj_add_flag(objects.new_program, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.new_program, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 32, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.hide_speed_in_deg, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.hide_speed_in_deg;
            if (new_val) {
                lv_obj_add_flag(objects.hide_speed_in_deg, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.hide_speed_in_deg, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 33, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.hide_speed_in_deg_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.hide_speed_in_deg_1;
            if (new_val) {
                lv_obj_add_flag(objects.hide_speed_in_deg_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.hide_speed_in_deg_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 34, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.hide_speed_in_deg_2, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.hide_speed_in_deg_2;
            if (new_val) {
                lv_obj_add_flag(objects.hide_speed_in_deg_2, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.hide_speed_in_deg_2, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 35, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.hide_y_speed_in_duration, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.hide_y_speed_in_duration;
            if (new_val) {
                lv_obj_add_flag(objects.hide_y_speed_in_duration, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.hide_y_speed_in_duration, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 36, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.y_axis_blocker_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.y_axis_blocker_1;
            if (new_val) {
                lv_obj_add_flag(objects.y_axis_blocker_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.y_axis_blocker_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 38, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.x_axis_blocker_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.x_axis_blocker_1;
            if (new_val) {
                lv_obj_add_flag(objects.x_axis_blocker_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.x_axis_blocker_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 40, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.doing_something_animation, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.doing_something_animation;
            if (new_val) {
                lv_obj_add_flag(objects.doing_something_animation, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.doing_something_animation, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_settings_homing() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings_homing = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj47 = obj;
            lv_obj_set_pos(obj, 11, 42);
            lv_obj_set_size(obj, 133, 28);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_homing_obj47, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Home X Axis");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 34);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 72, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "X HOMING CONTROLS");
        }
        {
            // HomingSpinner
            lv_obj_t *obj = lv_spinner_create(parent_obj);
            objects.homing_spinner = obj;
            lv_obj_set_pos(obj, 32, 100);
            lv_obj_set_size(obj, 80, 80);
        }
        {
            // StopHoming
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.stop_homing = obj;
            lv_obj_set_pos(obj, 11, 203);
            lv_obj_set_size(obj, 133, 31);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_homing_stop_homing, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "STOP HOMING");
                }
            }
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj48 = obj;
            lv_obj_set_pos(obj, 161, 110);
            lv_obj_set_size(obj, 150, 122);
            lv_textarea_set_max_length(obj, 200);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_homing_obj48, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // HomedText
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text = obj;
            lv_obj_set_pos(obj, 12, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Available Travel:");
        }
        {
            // HomedText_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_1 = obj;
            lv_obj_set_pos(obj, 12, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
        {
            // HomedText_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_2 = obj;
            lv_obj_set_pos(obj, 12, 154);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Current Position:");
        }
        {
            // HomedText_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_3 = obj;
            lv_obj_set_pos(obj, 11, 172);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
        {
            // HomedText_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_4 = obj;
            lv_obj_set_pos(obj, 12, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
        {
            // HomedText_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_5 = obj;
            lv_obj_set_pos(obj, 199, 70);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Messages from\nmotion control:");
        }
        {
            // Settings Button_7
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_7 = obj;
            lv_obj_set_pos(obj, 5, 4);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_homing_settings_button_7, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj49 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_settings_homing();
}

void tick_screen_settings_homing() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    {
        bool new_val = evalBooleanProperty(flowState, 5, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homing_spinner, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homing_spinner;
            if (new_val) {
                lv_obj_add_flag(objects.homing_spinner, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homing_spinner, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.stop_homing, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.stop_homing;
            if (new_val) {
                lv_obj_add_flag(objects.stop_homing, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.stop_homing, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj48);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj48);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj48;
            lv_textarea_set_text(objects.obj48, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homed_text, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homed_text;
            if (new_val) {
                lv_obj_add_flag(objects.homed_text, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homed_text, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.homed_text_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.homed_text_1;
            lv_label_set_text(objects.homed_text_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homed_text_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homed_text_1;
            if (new_val) {
                lv_obj_add_flag(objects.homed_text_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homed_text_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homed_text_2, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homed_text_2;
            if (new_val) {
                lv_obj_add_flag(objects.homed_text_2, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homed_text_2, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.homed_text_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.homed_text_3;
            lv_label_set_text(objects.homed_text_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homed_text_3, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homed_text_3;
            if (new_val) {
                lv_obj_add_flag(objects.homed_text_3, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homed_text_3, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.homed_text_4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.homed_text_4;
            lv_label_set_text(objects.homed_text_4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.homed_text_4, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.homed_text_4;
            if (new_val) {
                lv_obj_add_flag(objects.homed_text_4, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.homed_text_4, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj49);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj49;
            lv_label_set_text(objects.obj49, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_settings_speeds() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings_speeds = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 98, 3);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPEED SETTINGS");
        }
        {
            // HomedText_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_6 = obj;
            lv_obj_set_pos(obj, 47, 143);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Messages from motion control:");
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj50 = obj;
            lv_obj_set_pos(obj, 5, 168);
            lv_obj_set_size(obj, 310, 64);
            lv_textarea_set_max_length(obj, 200);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_obj50, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // x-speed-input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.x_speed_input = obj;
            lv_obj_set_pos(obj, 79, 32);
            lv_obj_set_size(obj, 69, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789.");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_x_speed_input, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 9, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "X: Speed");
        }
        {
            // x-accel-input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.x_accel_input = obj;
            lv_obj_set_pos(obj, 231, 32);
            lv_obj_set_size(obj, 69, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789.");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_x_accel_input, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 170, 42);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "X Accel");
        }
        {
            // y-speed-input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.y_speed_input = obj;
            lv_obj_set_pos(obj, 65, 79);
            lv_obj_set_size(obj, 58, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789.");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_y_speed_input, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 2, 89);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "Y: Speed");
        }
        {
            // y-accel-input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.y_accel_input = obj;
            lv_obj_set_pos(obj, 170, 79);
            lv_obj_set_size(obj, 56, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789.");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_y_accel_input, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 129, 89);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "Accel");
        }
        {
            // y-step_increment_input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.y_step_increment_input = obj;
            lv_obj_set_pos(obj, 259, 79);
            lv_obj_set_size(obj, 56, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789.");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_y_step_increment_input, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 226, 89);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "Step");
        }
        {
            // Settings Button_6
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_6 = obj;
            lv_obj_set_pos(obj, 4, 1);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_speeds_settings_button_6, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj51 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_settings_speeds();
}

void tick_screen_settings_speeds() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj50);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj50);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj50;
            lv_textarea_set_text(objects.obj50, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.x_speed_input);
        uint32_t max_length = lv_textarea_get_max_length(objects.x_speed_input);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.x_speed_input;
            lv_textarea_set_text(objects.x_speed_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.x_accel_input);
        uint32_t max_length = lv_textarea_get_max_length(objects.x_accel_input);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.x_accel_input;
            lv_textarea_set_text(objects.x_accel_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.y_speed_input);
        uint32_t max_length = lv_textarea_get_max_length(objects.y_speed_input);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.y_speed_input;
            lv_textarea_set_text(objects.y_speed_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.y_accel_input);
        uint32_t max_length = lv_textarea_get_max_length(objects.y_accel_input);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.y_accel_input;
            lv_textarea_set_text(objects.y_accel_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.y_step_increment_input);
        uint32_t max_length = lv_textarea_get_max_length(objects.y_step_increment_input);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.y_step_increment_input;
            lv_textarea_set_text(objects.y_step_increment_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj51);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj51;
            lv_label_set_text(objects.obj51, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_settings_accel_only() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings_accel_only = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 34);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 138);
            lv_obj_set_size(obj, 320, 102);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_square_box2(obj);
            lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 59, 7);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Accel/Decel SETTINGS");
        }
        {
            // HomedText_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.homed_text_7 = obj;
            lv_obj_set_pos(obj, 39, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Messages from Motion Controller");
        }
        {
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.obj52 = obj;
            lv_obj_set_pos(obj, 5, 178);
            lv_obj_set_size(obj, 310, 55);
            lv_textarea_set_max_length(obj, 200);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_accel_only_obj52, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // x-accel-input_2
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.x_accel_input_2 = obj;
            lv_obj_set_pos(obj, 209, 44);
            lv_obj_set_size(obj, 98, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_placeholder_text(obj, "200");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_accel_only_x_accel_input_2, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "X Axis Accel/Deceleration:");
        }
        {
            // y-accel-input_2
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.y_accel_input_2 = obj;
            lv_obj_set_pos(obj, 209, 91);
            lv_obj_set_size(obj, 98, 36);
            lv_textarea_set_accepted_chars(obj, "0123456789");
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_placeholder_text(obj, "200");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_accel_only_y_accel_input_2, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 9, 101);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_label_set_text(obj, "Y Axis Accel/Deceleration:");
        }
        {
            // Settings Button_5
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_button_5 = obj;
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, 29, 25);
            lv_obj_add_event_cb(obj, event_handler_cb_settings_accel_only_settings_button_5, LV_EVENT_ALL, flowState);
            add_style_coloured_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj53 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_settings_accel_only();
}

void tick_screen_settings_accel_only() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.obj52);
        uint32_t max_length = lv_textarea_get_max_length(objects.obj52);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.obj52;
            lv_textarea_set_text(objects.obj52, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.x_accel_input_2);
        uint32_t max_length = lv_textarea_get_max_length(objects.x_accel_input_2);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.x_accel_input_2;
            lv_textarea_set_text(objects.x_accel_input_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.y_accel_input_2);
        uint32_t max_length = lv_textarea_get_max_length(objects.y_accel_input_2);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.y_accel_input_2;
            lv_textarea_set_text(objects.y_accel_input_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj53);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj53;
            lv_label_set_text(objects.obj53, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_keyboard_screen() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.keyboard_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Universal Keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.universal_keyboard = obj;
            lv_obj_set_pos(obj, 0, 61);
            lv_obj_set_size(obj, 320, 179);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.obj54 = obj;
                    lv_obj_set_pos(obj, 193, 0);
                    lv_obj_set_size(obj, 124, 88);
                    lv_obj_add_event_cb(obj, event_handler_cb_keyboard_screen_obj54, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff252525), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Save_4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.save_4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Save");
                        }
                    }
                }
            }
        }
        {
            // Universal_Keyboard_Text_Area
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.universal_keyboard_text_area = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 61);
            lv_textarea_set_accepted_chars(obj, "0123456789.-");
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_keyboard_screen_universal_keyboard_text_area, LV_EVENT_ALL, flowState);
        }
    }
    lv_keyboard_set_textarea(objects.universal_keyboard, objects.universal_keyboard_text_area);
    
    tick_screen_keyboard_screen();
}

void tick_screen_keyboard_screen() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.universal_keyboard_text_area);
        uint32_t max_length = lv_textarea_get_max_length(objects.universal_keyboard_text_area);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.universal_keyboard_text_area;
            lv_textarea_set_text(objects.universal_keyboard_text_area, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_welcome_screen,
    tick_screen_set_movement_style,
    tick_screen_set_end_points,
    tick_screen_set_speed_duration_of_movement,
    tick_screen_settings_homing,
    tick_screen_settings_speeds,
    tick_screen_settings_accel_only,
    tick_screen_keyboard_screen,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

//
// Styles
//

static const char *style_names[] = { "SquareBox", "SquareBox2", "ButtonsStatus", "ColouredButton", "EndPoint_Buttons", "Settings_Pagination_Active", "CheckedSliderToggle" };

extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
//
//

void create_screens() {
    // Initialize styles
    eez_flow_init_styles(add_style, remove_style);
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));

eez_flow_init_fonts(fonts, sizeof(fonts) / sizeof(ext_font_desc_t));

// Set default LVGL theme
    lv_display_t *dispp = lv_display_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_display_set_theme(dispp, theme);
    
    // Initialize screens
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    // Create screens
    create_screen_welcome_screen();
    create_screen_set_movement_style();
    create_screen_set_end_points();
    create_screen_set_speed_duration_of_movement();
    create_screen_settings_homing();
    create_screen_settings_speeds();
    create_screen_settings_accel_only();
    create_screen_keyboard_screen();
}