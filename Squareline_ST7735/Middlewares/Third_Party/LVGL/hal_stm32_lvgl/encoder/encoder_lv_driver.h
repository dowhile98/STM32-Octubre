/**
 * @file encoder_lv_driver.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __ENCODER_H
#define __ENCODER_H

/*Includes ----------------------------------------------------------*/
#include "stm32f4xx.h"
#include "delay_it.h"
#include "defines.h"
#include <lvgl.h>
#include <src/hal/lv_hal_indev.h>
/*Macro defines -----------------------------------------------------*/
#define ENCODER_TIM             TIM3
#define ENCODER_IT1             A, 6
#define ENCODER_IT2             A, 7
#define ALTER_FUNCTION          2
#define ENCODER_BUTTON_PIN      A, 0
#define ENCODER_TIM_CLOCK_EN()   RCC->APB1ENR |= RCC_APB1ENR_TIM3EN

#define ENCODER_DEBOUNCE_TIME 	300
/*Funcion prototype -------------------------------------------------*/
void lv_port_indev_init(lv_group_t *g);
void encoder_button_callback(uint16_t GPIO_Pin);
#endif
