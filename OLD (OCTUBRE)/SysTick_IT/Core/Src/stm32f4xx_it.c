/**
 * @file stm32f4xx_it.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "stm32f4xx.h"
extern volatile uint32_t uwTick;

void SysTick_Handler(void){
    if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
        uwTick += 1;
    }
	return;
}
