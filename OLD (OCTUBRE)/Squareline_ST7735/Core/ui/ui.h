// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: Squareline_ST7735

#ifndef _SQUARELINE_ST7735_UI_H
#define _SQUARELINE_ST7735_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "defines.h"
extern lv_obj_t * ui_main_screen;
extern lv_obj_t * ui_pwm;
void ui_event_on_button(lv_event_t * e);
extern lv_obj_t * ui_on_button;
extern lv_obj_t * ui_main_screen_Label1;
void ui_event_off_button(lv_event_t * e);
extern lv_obj_t * ui_off_button;
extern lv_obj_t * ui_main_screen_Label2;
extern lv_obj_t * ui_main_screen_Dropdown1;
extern lv_obj_t * ui_main_screen_Label3;






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
