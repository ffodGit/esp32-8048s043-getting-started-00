#include "styles.h"
#include "images.h"
#include "fonts.h"

void apply_style_dark_theme_claude00_button(lv_obj_t *obj) {
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_dark_theme_claude01_title(lv_obj_t *obj) {
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe94560), LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_dark_theme_claude02_bar(lv_obj_t *obj) {
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff103460), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe94560), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};
void apply_style_dark_theme_claude03_panel(lv_obj_t *obj) {
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
};

