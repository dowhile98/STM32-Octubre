/*
 * oled_lv_drv.h
 *
 *  Created on: Nov 11, 2022
 *      Author: jeffr
 */

#ifndef THIRD_PARTY_LVGL_STM32_OLED_DRV_OLED_LV_DRV_H_
#define THIRD_PARTY_LVGL_STM32_OLED_DRV_OLED_LV_DRV_H_

#include "oled.h"
#include "lvgl.h"

#define DISP_BUF_SIZE 	(128 * 40)

#define LCD_H_RES              128
#define LCD_V_RES              64
// Bit number used to represent command and parameter
#define LCD_CMD_BITS           8
#define	LCD_PARAM_BITS         8

extern lv_disp_t *disp;

void lvgl_driver_init(void);

#endif /* THIRD_PARTY_LVGL_STM32_OLED_DRV_OLED_LV_DRV_H_ */
