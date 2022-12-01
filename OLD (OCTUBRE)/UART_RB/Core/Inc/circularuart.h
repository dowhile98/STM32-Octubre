/*
 * circularuart.h
 *
 *  Created on: 19 ago. 2022
 *      Author: jeffr
 */

#ifndef INC_CIRCULARUART_H_
#define INC_CIRCULARUART_H_

/*Includes ----------------------------------------*/

#include <stdio.h>
#include <stdint.h>


/*Defines -----------------------------------------*/


/*function prototype ------------------------------*/
void CircularUART2_Init(/*uint32_t pclk, const uint32_t baud, const uint8_t parity*/);
void CircularUART_StartTx(uint8_t * const buffer, const uint8_t length_2N);
void CircularUART_StartRx(uint8_t * const buffer, const uint8_t length_2N);
void CircularUART_ClearTx(void);
void CircularUART_ClearRx(void);
uint16_t CircularUART_Send(const uint8_t * data, const uint16_t maxlen);
uint16_t CircularUART_Receive(uint8_t * data, const uint16_t maxlen);
uint16_t CircularUART_GetUnsentCount(void);
uint16_t CircularUART_GetUnreadCount(void);

#endif /* INC_CIRCULARUART_H_ */
