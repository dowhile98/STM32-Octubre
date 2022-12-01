// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: Squareline_ST7735

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_main_screen;
lv_obj_t * ui_pwm;
void ui_event_on_button(lv_event_t * e);
lv_obj_t * ui_on_button;
lv_obj_t * ui_main_screen_Label1;
void ui_event_off_button(lv_event_t * e);
lv_obj_t * ui_off_button;
lv_obj_t * ui_main_screen_Label2;
lv_obj_t * ui_main_screen_Dropdown1;
lv_obj_t * ui_main_screen_Label3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_on_button(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        GPIOX_ODR(LED) = 1;
    }
}
void ui_event_off_button(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        GPIOX_ODR(LED) = 0;
    }
}

///////////////////// SCREENS ////////////////////
void ui_main_screen_screen_init(void)
{
    ui_main_screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_main_screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_main_screen, lv_color_hex(0xEAFF76), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_main_screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pwm = lv_slider_create(ui_main_screen);
    lv_obj_set_width(ui_pwm, 140);
    lv_obj_set_height(ui_pwm, 2);
    lv_obj_set_x(ui_pwm, 0);
    lv_obj_set_y(ui_pwm, 49);
    lv_obj_set_align(ui_pwm, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_pwm, lv_color_hex(0x0CFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pwm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_pwm, lv_color_hex(0xC9FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_pwm, lv_color_hex(0xF60065), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_pwm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_pwm, lv_color_hex(0x7F0E0E), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pwm, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_pwm, lv_color_hex(0x00EFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_pwm, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_on_button = lv_btn_create(ui_main_screen);
    lv_obj_set_width(ui_on_button, 54);
    lv_obj_set_height(ui_on_button, 19);
    lv_obj_set_x(ui_on_button, -38);
    lv_obj_set_y(ui_on_button, 26);
    lv_obj_set_align(ui_on_button, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_on_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_on_button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_on_button, lv_color_hex(0x76EAFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_on_button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_main_screen_Label1 = lv_label_create(ui_on_button);
    lv_obj_set_width(ui_main_screen_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_main_screen_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_main_screen_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_main_screen_Label1, "ON");
    lv_obj_set_style_text_color(ui_main_screen_Label1, lv_color_hex(0x167500), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_main_screen_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_off_button = lv_btn_create(ui_main_screen);
    lv_obj_set_width(ui_off_button, 55);
    lv_obj_set_height(ui_off_button, 20);
    lv_obj_set_x(ui_off_button, 33);
    lv_obj_set_y(ui_off_button, 25);
    lv_obj_set_align(ui_off_button, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_off_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_off_button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_off_button, lv_color_hex(0x7DFFDC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_off_button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_main_screen_Label2 = lv_label_create(ui_off_button);
    lv_obj_set_width(ui_main_screen_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_main_screen_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_main_screen_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_main_screen_Label2, "OFF");
    lv_obj_set_style_text_color(ui_main_screen_Label2, lv_color_hex(0xFF0303), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_main_screen_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_main_screen_Dropdown1 = lv_dropdown_create(ui_main_screen);
    lv_dropdown_set_options(ui_main_screen_Dropdown1, "LED1\nLED2\nLED3\nLED4");
    lv_obj_set_width(ui_main_screen_Dropdown1, 120);
    lv_obj_set_height(ui_main_screen_Dropdown1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_main_screen_Dropdown1, -5);
    lv_obj_set_y(ui_main_screen_Dropdown1, -15);
    lv_obj_set_align(ui_main_screen_Dropdown1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_main_screen_Dropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_main_screen_Label3 = lv_label_create(ui_main_screen);
    lv_obj_set_width(ui_main_screen_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_main_screen_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_main_screen_Label3, -3);
    lv_obj_set_y(ui_main_screen_Label3, -51);
    lv_obj_set_align(ui_main_screen_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_main_screen_Label3, "CONTROL DE LEDS");
    lv_obj_set_style_text_color(ui_main_screen_Label3, lv_color_hex(0xFF7D7D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_main_screen_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_on_button, ui_event_on_button, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_off_button, ui_event_off_button, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_main_screen_screen_init();
    lv_disp_load_scr(ui_main_screen);
}
