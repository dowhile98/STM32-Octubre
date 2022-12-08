/*
 * delay.c
 *
 *  Created on: 7 dic. 2022
 *      Author: jeffr
 */


#include <delay.h>

void delay_init(void){
	uint32_t temp;
	//->deshabilitar al systick
	SysTick->CTRL = 0;
	//->establecer el valor del reload
	temp = SystemCoreClock / 1000;
	SysTick->LOAD = temp - 1;
	SysTick->VAL = 0;
	//->configuramos el regitro de control
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

	return;
}

void delay_ms(uint32_t time){
	SysTick->VAL = 0;
	for(uint32_t i = 0; i< time; i++){
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)); //se bloquea por 1ms
	}
	return;
}
