/*
 * oled.h
 *
 *  Created on: Nov 11, 2022
 *      Author: jeffr
 */

#ifndef THIRD_PARTY_LVGL_STM32_OLED_DRV_OLED_H_
#define THIRD_PARTY_LVGL_STM32_OLED_DRV_OLED_H_

/*Includes ------------------------------------------------*/
#include "stm32f4xx.h"
#include "defines.h"
#include "delay.h"
#include "lvgl.h"
/*Macro defines ------------------------------------------*/
//LCD Rotation
//The rotation values are relative to how you would rotate the physical display in the clockwise direction
#define DISP_ROT_Portrait        0 //0
#define DISP_ROT_Landscape		 1 //90
#define DISP_ROT_Inv_Portrait	 2 //180
#define DISP_ROT_Inv_Landscape   3 //270

#define SSD1306_DISPLAY_ORIENTATION		DISP_ROT_Landscape
#define OLED_I2C						I2C1
extern void I2C_MasterSendData(I2C_TypeDef *I2Cx, uint8_t SlaveAddr,uint8_t *pTxbuffer, uint32_t Len);
/*Function prototypes -------------------------------------*/
void ssd1306_init(void);
void ssd1306_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_map);
void ssd1306_rounder(lv_disp_drv_t * disp_drv, lv_area_t *area);
void ssd1306_set_px_cb(lv_disp_drv_t * disp_drv, uint8_t * buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y,
    lv_color_t color, lv_opa_t opa);

void ssd1306_sleep_in(void);
void ssd1306_sleep_out(void);

#endif /* THIRD_PARTY_LVGL_STM32_OLED_DRV_OLED_H_ */
