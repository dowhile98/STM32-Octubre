/**
 * @file ui.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "lvgl.h"
#include "lv_driver.h"
#include "defines.h"
static void event_handler1(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        GPIOX_ODR(LED) ^= 1;
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}
static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");

    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}
void lv_example_btn_1(void)
{
    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, event_handler1, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "LED Toggle");
    lv_obj_center(label);

    /*Properties to transition*/
        static lv_style_prop_t props[] = {
            LV_STYLE_TRANSFORM_WIDTH, LV_STYLE_TRANSFORM_HEIGHT, LV_STYLE_TEXT_LETTER_SPACE, 0
        };

        /*Transition descriptor when going back to the default state.
         *Add some delay to be sure the press transition is visible even if the press was very short*/
        static lv_style_transition_dsc_t transition_dsc_def;
        lv_style_transition_dsc_init(&transition_dsc_def, props, lv_anim_path_overshoot, 250, 100, NULL);

        /*Transition descriptor when going to pressed state.
         *No delay, go to presses state immediately*/
        static lv_style_transition_dsc_t transition_dsc_pr;
        lv_style_transition_dsc_init(&transition_dsc_pr, props, lv_anim_path_ease_in_out, 250, 0, NULL);

        /*Add only the new transition to he default state*/
        static lv_style_t style_def;
        lv_style_init(&style_def);
        lv_style_set_transition(&style_def, &transition_dsc_def);

        /*Add the transition and some transformation to the presses state.*/
        static lv_style_t style_pr;
        lv_style_init(&style_pr);
        lv_style_set_transform_width(&style_pr, 10);
        lv_style_set_transform_height(&style_pr, -10);
        lv_style_set_text_letter_space(&style_pr, 10);
        lv_style_set_transition(&style_pr, &transition_dsc_pr);

        lv_obj_t * btn3 = lv_btn_create(lv_scr_act());
        lv_obj_align(btn3, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_style(btn3, &style_pr, LV_STATE_PRESSED);
        lv_obj_add_style(btn3, &style_def, 0);

        lv_obj_t * label1 = lv_label_create(btn3);
        lv_label_set_text(label1, "Gum");
}