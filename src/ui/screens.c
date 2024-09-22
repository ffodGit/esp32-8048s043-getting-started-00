#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_main00_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen00_screen00_btn_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen00_screen00_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen00_screen00_btn_led(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen01_screen01_btn_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen01_screen01_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen01_screen01_arc_pwm(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen02_screen02_btn_back(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen02_screen02_btn_next(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen03_screen03_keyboard(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_READY) {
        action_set_global_eez_event(e);
    }
    if (event == LV_EVENT_CANCEL) {
        action_set_global_eez_event(e);
    }
}

static void event_handler_cb_screen03_screen03_textarea_kb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        action_set_global_eez_event(e);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff16213e), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 251, 214);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Hello, world!");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main00BtnNext
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.main00_btn_next = obj;
            lv_obj_set_pos(obj, 590, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_main_main00_btn_next, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Next");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Main");
            apply_style_dark_theme_claude01_title(obj);
        }
    }
}

void tick_screen_main() {
}

void create_screen_screen00() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen00 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff16213e), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Screen00BtnBack
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen00_btn_back = obj;
            lv_obj_set_pos(obj, 15, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen00_screen00_btn_back, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Screen00BtnNext
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen00_btn_next = obj;
            lv_obj_set_pos(obj, 590, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen00_screen00_btn_next, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Next");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Screen00");
            apply_style_dark_theme_claude01_title(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Screen00BtnLed
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen00_btn_led = obj;
            lv_obj_set_pos(obj, 307, 206);
            lv_obj_set_size(obj, 209, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen00_screen00_btn_led, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "On/Off");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen00() {
}

void create_screen_screen01() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen01 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff16213e), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Screen01");
            apply_style_dark_theme_claude01_title(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Screen01BtnBack
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen01_btn_back = obj;
            lv_obj_set_pos(obj, 15, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen01_screen01_btn_back, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Screen01BtnNext
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen01_btn_next = obj;
            lv_obj_set_pos(obj, 590, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen01_screen01_btn_next, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Next");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Screen01ArcPwm
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.screen01_arc_pwm = obj;
            lv_obj_set_pos(obj, 235, 75);
            lv_obj_set_size(obj, 330, 330);
            lv_arc_set_value(obj, 59);
            lv_arc_set_bg_start_angle(obj, 140);
            lv_arc_set_bg_end_angle(obj, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_screen01_screen01_arc_pwm, LV_EVENT_ALL, 0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe94560), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff103460), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffd1c4c4), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Screen01LabelPwm
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.screen01_label_pwm = obj;
            lv_obj_set_pos(obj, 362, 317);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "100%");
            apply_style_dark_theme_claude01_title(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_screen01() {
}

void create_screen_screen02() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen02 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff16213e), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 15, 15);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Screen02");
            apply_style_dark_theme_claude01_title(obj);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Screen02BtnBack
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen02_btn_back = obj;
            lv_obj_set_pos(obj, 15, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen02_screen02_btn_back, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Screen02BtnNext
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.screen02_btn_next = obj;
            lv_obj_set_pos(obj, 590, 390);
            lv_obj_set_size(obj, 187, 70);
            lv_obj_add_event_cb(obj, event_handler_cb_screen02_screen02_btn_next, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude00_button(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 38, 8);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Next");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Screen02BarHorizontal
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.screen02_bar_horizontal = obj;
            lv_obj_set_pos(obj, 24, 329);
            lv_obj_set_size(obj, 684, 40);
            lv_bar_set_range(obj, 0, 4095);
            lv_bar_set_value(obj, 500, LV_ANIM_OFF);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            apply_style_dark_theme_claude02_bar(obj);
        }
        {
            // Screen02BarVertical
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.screen02_bar_vertical = obj;
            lv_obj_set_pos(obj, 736, 14);
            lv_obj_set_size(obj, 40, 355);
            lv_bar_set_value(obj, 10, LV_ANIM_OFF);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            apply_style_dark_theme_claude02_bar(obj);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 414, 15);
            lv_obj_set_size(obj, 315, 77);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude03_panel(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Screen02LabelVertical
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.screen02_label_vertical = obj;
                    lv_obj_set_pos(obj, 205, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "100%");
                    apply_style_dark_theme_claude01_title(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -7, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Scaled value:");
                    apply_style_dark_theme_claude01_title(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 230, 240);
            lv_obj_set_size(obj, 287, 77);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_dark_theme_claude03_panel(obj);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Screen02LabelHorizontal
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.screen02_label_horizontal = obj;
                    lv_obj_set_pos(obj, 177, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "4095");
                    apply_style_dark_theme_claude01_title(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Raw value:");
                    apply_style_dark_theme_claude01_title(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_screen02() {
}

void create_screen_screen03() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen03 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Screen03Keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.screen03_keyboard = obj;
            lv_obj_set_pos(obj, 0, 130);
            lv_obj_set_size(obj, 800, 350);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_screen03_screen03_keyboard, LV_EVENT_ALL, 0);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff16213e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffe94560), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
        }
        {
            // Screen03TextareaKb
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.screen03_textarea_kb = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 130);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_text(obj, "Test");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, true);
            lv_obj_add_event_cb(obj, event_handler_cb_screen03_screen03_textarea_kb, LV_EVENT_ALL, 0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.screen03_keyboard, objects.screen03_textarea_kb);
}

void tick_screen_screen03() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_screen00();
    create_screen_screen01();
    create_screen_screen02();
    create_screen_screen03();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_screen00,
    tick_screen_screen01,
    tick_screen_screen02,
    tick_screen_screen03,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
