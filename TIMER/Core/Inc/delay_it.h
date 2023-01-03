/*
 * delay_it.h
 *
 *  Created on: 19 dic. 2022
 *      Author: jeffr
 */

#ifndef INC_DELAY_IT_H_
#define INC_DELAY_IT_H_

#include <stm32f4xx.h>

/**
 * @brief inicializa el timer6 para generar eventos cada 1us
 */
void delay_it(void);
/**
 * @brief funcion para generar retardos en us
 */
void delay_us(uint32_t delay);
/**
 * @brief funcion para generar retardos en ms
 */
void delay_ms(uint32_t delay);

uint32_t GetTick(void);
#endif /* INC_DELAY_IT_H_ */
