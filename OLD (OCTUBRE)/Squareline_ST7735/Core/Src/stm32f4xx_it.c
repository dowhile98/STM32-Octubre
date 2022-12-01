/*
 * stm32f4xx_it.c
 *
 *  Created on: Nov 4, 2022
 *      Author: jeffr
 */


#include "defines.h"
#include "stm32f4xx.h"
#include "ST7735.h"
#include "lvgl.h"
#include "encoder_lv_driver.h"

extern volatile uint32_t uwTick;

void SysTick_Handler(void){
    if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
        uwTick += 1;
        lv_tick_inc(1);
    }
	return;
}

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA1_Stream5_IRQHandler(void)
{
	DMA_TransmitComplete_Callback();
}

void EXTI0_IRQHandler(void){
  if(EXTI->PR & EXTI_PR_PR0){
    EXTI->PR |= EXTI_PR_PR0;
    //todo
    encoder_button_callback(0);
  }
}