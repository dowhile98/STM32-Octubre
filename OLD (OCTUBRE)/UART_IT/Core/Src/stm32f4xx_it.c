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
#include <stdbool.h>

extern volatile uint32_t uwTick;

extern uint8_t byte;
extern bool status;
uint8_t _byte = 0;

void SysTick_Handler(void){
    if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
        uwTick += 1;
    }
	return;
}

/**
 * USART2
 */
void USART2_IRQHandler(void){
	//verificación de la IT
	if(USART2->SR & USART_SR_RXNE){
		//LEE
		byte = USART2->DR;
		if(byte != _byte){
			status = false;
		}
		_byte = byte;
	}
	return;
}
