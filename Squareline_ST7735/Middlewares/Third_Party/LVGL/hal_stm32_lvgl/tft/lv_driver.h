/*
 * lv_driver.h
 *
 *  Created on: Oct 6, 2022
 *      Author: jeffr
 */

#ifndef THIRDPARTY_LVGL_HAL_STM32_LVGL_TFT_LV_DRIVER_H_
#define THIRDPARTY_LVGL_HAL_STM32_LVGL_TFT_LV_DRIVER_H_

/*Includes ---------------------------------------------------------*/
#include "lvgl.h"
#include "lv_conf.h"

/*Macro definition -------------------------------------------------*/
#define SCREEN_PORTION 10

/*Function definition ----------------------------------------------*/

/**
 * @brief inicializa la pantalla tft
 */
void lv_port_disp_init(void);

/**
 * @brief callback del DMA
 */
void DMA_ST7735_SPI_TransmitComplete_Callback();




#endif /* THIRDPARTY_LVGL_HAL_STM32_LVGL_TFT_LV_DRIVER_H_ */
