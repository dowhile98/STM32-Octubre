/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/*Includes -------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
/*Macro defines --------------------------------------------------*/
/**
 * @brief para seleccionar el medio de transmision para el printf
 * 0: USART
 * 1: SW0
 */
#define USE_SW0			1
/*Global variables -----------------------------------------------*/

/*Function prototypes --------------------------------------------*/



int main(void)
{
	printf("hola mundo\r\n");
    /* Loop forever */
	for(;;){

	}
}
/*Function definition ------------------------------------------------*/
/**********************************************************************/

int __io_putchar(int ch){
#if (USE_SW0 == 1)
	ITM_SendChar(ch);
#else
	//todo

#endif
	return ch;
}
