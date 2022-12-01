/*
 * delay_tim.h
 *
 *  Created on: 20 mar. 2022
 *      Author: Lenovo
 */

#ifndef INC_DELAY_TIM_H_
#define INC_DELAY_TIM_H_
#include "stm32f4xx.h"
/**
 * USE_DELAY_US
 * 0 : solo retardos en milisegundos
 * 1 : retardos en microsegundos/milisegundos
 */
#define USE_DELAY_US  0
/**
 * timer usado para generar el retardo
 */
#define DELAY_TIM_PSC		84E+6
#define DELAY_TIM			TIM2
#define DELAY_PSC			0
#define DELAY_CLOCK_EN()	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN

#if USE_DELAY_US == 1

/**
 * @brief funcion que va generar retardos en microsegundos
 */
void delay_us(uint32_t delay);
#endif
/**
 * delay init
 * @param [ticks] : obtenido de la formula ticks = SystemCoreClock * T(s)
 */
void delay_Init(void);
/**
 * @brief funcion que va generar retardos en milisegundos
 */
void delay_ms(uint32_t delay);

#endif /* INC_DELAY_TIM_H_ */
