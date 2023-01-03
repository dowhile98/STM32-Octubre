/*
 * delay_it.c
 *
 *  Created on: 19 dic. 2022
 *      Author: jeffr
 */

#include <delay_it.h>

/*Global variables -----------------------------------*/
volatile uint32_t uwTick = 0;

/**
 * @brief Retorna el valor de la variabla ticks
 * @param none
 * @return ticks
 */
uint32_t GetTick(void){
	return uwTick;
}
/**
 * @brief inicializa el timer6 para generar eventos cada 1us
 */
void delay_it(void){

	//timer 6 conectado al bus APB1
	//TIMER CLOCK INPUT: 84MHZ
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	/**
	 * updateevent = (PSC_CK / (PSC+ 1)(ARR + 1)
	 * ARR = PSC_CK / ((PSC+1)(updateevent)) - 1
	 * ARR = 84MZ /(1)(1E+6) - 1
	 * ARR = 83 --->VALOR MAXIMO ES (2^16 - 1 = 65535)
	 */
	TIM6->CR1 = 0;
	TIM6->ARR = 83U;
	TIM6->PSC = 0;
	//habilitar las interrupciones
	TIM6->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	//habilitar el conteo del timer
	TIM6->CR1 |= TIM_CR1_CEN;

	return;
}
/**
 * @brief funcion para generar retardos en us
 */
void delay_us(uint32_t delay){

	uint32_t tickstart = GetTick();
	uint32_t wait = delay;
	//generacion del retardo
	while((GetTick() - tickstart)<wait);
}
/**
 * @brief funcion para generar retardos en ms
 */
void delay_ms(uint32_t delay){

	for(uint32_t i = 0; i<delay; i++){
		delay_us(1000);
	}
}
