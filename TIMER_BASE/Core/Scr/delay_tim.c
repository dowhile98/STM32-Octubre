/*
 * delay_tim.c
 *
 *  Created on: 20 mar. 2022
 *      Author: Lenovo
 */


#include "delay_tim.h"

void delay_Init(void){
	uint32_t tmp;
	DELAY_CLOCK_EN();
#if USE_DELAY_US
	tmp = DELAY_TIM_PSC/((DELAY_PSC + 1) * 1000000) - 1;
#else
	tmp = DELAY_TIM_PSC/((DELAY_PSC + 1) * 1000) - 1;
#endif

	DELAY_TIM->CR1 &=~ TIM_CR1_CEN;
	DELAY_TIM->ARR = tmp;
	DELAY_TIM->PSC = DELAY_PSC;

	/*Habilitacion del timer*/
	DELAY_TIM->CR1 |= TIM_CR1_CEN;
}


#if USE_DELAY_US == 1

/**
 * @brief funcion que va generar retardos en microsegundos
 */
void delay_us(uint32_t delay){
	uint32_t i;
	DELAY_TIM->CNT = 0;
	for(i = 0; i<delay;i++){
		while(!(DELAY_TIM->SR & TIM_SR_UIF));	//Retardo de 1us
		DELAY_TIM->SR = 0;
	}

}
#endif



/**
 * @brief funcion que va generar retardos en milisegundos
 */
void delay_ms(uint32_t delay){
	uint32_t i;
#if USE_DELAY_US
	for(i = 0;i<delay;i++){
		delay_us(1000);						//retardo de 1ms
	}
#else
	DELAY_TIM->CNT = 0;
	for(i = 0; i<delay;i++){
		while(!(DELAY_TIM->SR & TIM_SR_UIF));	//Retardo de 1ms
		DELAY_TIM->SR &=~ TIM_SR_UIF;
	}
#endif

}
