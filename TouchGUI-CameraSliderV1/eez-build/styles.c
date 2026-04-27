#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: SquareBox
//

void init_style_square_box_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffededed));
    lv_style_set_border_width(style, 0);
    lv_style_set_radius(style, 0);
};

lv_style_t *get_style_square_box_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_square_box_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_square_box(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_square_box_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_square_box(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_square_box_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: SquareBox2
//

void init_style_square_box2_MAIN_DEFAULT(lv_style_t *style) {
    init_style_square_box_MAIN_DEFAULT(style);
    
    lv_style_set_radius(style, 0);
    lv_style_set_border_width(style, 0);
    lv_style_set_border_opa(style, 1255);
    lv_style_set_bg_opa(style, 210);
};

lv_style_t *get_style_square_box2_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_square_box2_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_square_box2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_square_box2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_square_box2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_square_box2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: ButtonsStatus
//

void init_style_buttons_status_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_buttons_status_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_buttons_status_MAIN_CHECKED(style);
    }
    return style;
};

void init_style_buttons_status_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff464646));
    lv_style_set_bg_opa(style, 0);
    lv_style_set_shadow_opa(style, 0);
};

lv_style_t *get_style_buttons_status_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_buttons_status_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_buttons_status(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_buttons_status_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_buttons_status_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_buttons_status(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_buttons_status_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_buttons_status_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: ColouredButton
//

void init_style_coloured_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff1da4ff));
};

lv_style_t *get_style_coloured_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_coloured_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_coloured_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_coloured_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_coloured_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_coloured_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: EndPoint_Buttons
//

void init_style_end_point_buttons_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff07b1ff));
    lv_style_set_border_width(style, 3);
    lv_style_set_border_color(style, lv_color_hex(0xfff89090));
};

lv_style_t *get_style_end_point_buttons_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_end_point_buttons_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_end_point_buttons_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff07b1ff));
    lv_style_set_border_width(style, 3);
    lv_style_set_border_color(style, lv_color_hex(0xff58ff97));
};

lv_style_t *get_style_end_point_buttons_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_end_point_buttons_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_end_point_buttons(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_end_point_buttons_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_end_point_buttons_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_end_point_buttons(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_end_point_buttons_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_end_point_buttons_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: Settings_Pagination_Active
//

void init_style_settings_pagination_active_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_border_width(style, 2);
    lv_style_set_border_side(style, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_pad_top(style, 2);
    lv_style_set_pad_bottom(style, 2);
    lv_style_set_pad_left(style, 2);
    lv_style_set_pad_right(style, 2);
};

lv_style_t *get_style_settings_pagination_active_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_settings_pagination_active_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_settings_pagination_active(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_settings_pagination_active_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_settings_pagination_active(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_settings_pagination_active_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: CheckedSliderToggle
//

void init_style_checked_slider_toggle_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff9a9696));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_checked_slider_toggle_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checked_slider_toggle_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_checked_slider_toggle_INDICATOR_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffa4a0a0));
};

lv_style_t *get_style_checked_slider_toggle_INDICATOR_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_checked_slider_toggle_INDICATOR_CHECKED(style);
    }
    return style;
};

void add_style_checked_slider_toggle(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_checked_slider_toggle_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_checked_slider_toggle_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

void remove_style_checked_slider_toggle(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_checked_slider_toggle_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_checked_slider_toggle_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_square_box,
        add_style_square_box2,
        add_style_buttons_status,
        add_style_coloured_button,
        add_style_end_point_buttons,
        add_style_settings_pagination_active,
        add_style_checked_slider_toggle,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_square_box,
        remove_style_square_box2,
        remove_style_buttons_status,
        remove_style_coloured_button,
        remove_style_end_point_buttons,
        remove_style_settings_pagination_active,
        remove_style_checked_slider_toggle,
    };
    remove_style_funcs[styleIndex](obj);
}