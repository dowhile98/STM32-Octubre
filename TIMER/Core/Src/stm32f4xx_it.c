/*
 * stm32f4xx_it.c
 *
 *  Created on: 19 dic. 2022
 *      Author: jeffr
 */
#include <stm32f4xx.h>


extern volatile uint32_t uwTick;

void TIM6_DAC_IRQHandler(void){
	if(TIM6->SR & TIM_SR_UIF){
		TIM6->SR &=~ TIM_SR_UIF;
		//TODO
		uwTick += 1;
	}
	return;
}

