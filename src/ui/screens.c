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

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 307, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Hello, world!");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe31616), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
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


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_screen00();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_screen00,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
