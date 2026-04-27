#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: SquareBox
lv_style_t *get_style_square_box_MAIN_DEFAULT();
void add_style_square_box(lv_obj_t *obj);
void remove_style_square_box(lv_obj_t *obj);

// Style: SquareBox2
lv_style_t *get_style_square_box2_MAIN_DEFAULT();
void add_style_square_box2(lv_obj_t *obj);
void remove_style_square_box2(lv_obj_t *obj);

// Style: ButtonsStatus
lv_style_t *get_style_buttons_status_MAIN_CHECKED();
lv_style_t *get_style_buttons_status_MAIN_DEFAULT();
void add_style_buttons_status(lv_obj_t *obj);
void remove_style_buttons_status(lv_obj_t *obj);

// Style: ColouredButton
lv_style_t *get_style_coloured_button_MAIN_DEFAULT();
void add_style_coloured_button(lv_obj_t *obj);
void remove_style_coloured_button(lv_obj_t *obj);

// Style: EndPoint_Buttons
lv_style_t *get_style_end_point_buttons_MAIN_DEFAULT();
lv_style_t *get_style_end_point_buttons_MAIN_CHECKED();
void add_style_end_point_buttons(lv_obj_t *obj);
void remove_style_end_point_buttons(lv_obj_t *obj);

// Style: Settings_Pagination_Active
lv_style_t *get_style_settings_pagination_active_MAIN_DEFAULT();
void add_style_settings_pagination_active(lv_obj_t *obj);
void remove_style_settings_pagination_active(lv_obj_t *obj);

// Style: CheckedSliderToggle
lv_style_t *get_style_checked_slider_toggle_INDICATOR_DEFAULT();
lv_style_t *get_style_checked_slider_toggle_INDICATOR_CHECKED();
void add_style_checked_slider_toggle(lv_obj_t *obj);
void remove_style_checked_slider_toggle(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/