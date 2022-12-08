/*
 * delay.h
 *
 *  Created on: 7 dic. 2022
 *      Author: jeffr
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include <stm32f4xx.h>

void delay_init(void);

void delay_ms(uint32_t time);

#endif /* INC_DELAY_H_ */
