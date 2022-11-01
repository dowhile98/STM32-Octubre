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
#include "delay.h"
#include "defines.h"
#include <string.h>
/*Macro defines --------------------------------------------------*/
/**
 * @brief para seleccionar el medio de transmision para el printf
 * 0: USART
 * 1: SW0
 */
#define USE_SW0			1
#define USART1_TX		A, 9
#define USART1_RX		A, 10
#define SW				A, 0
#define LED				D, 12
/*Global variables -----------------------------------------------*/
uint8_t data_stream[100];
/*Function prototypes --------------------------------------------*/



int main(void)
{
	//enable clock
	RCC->AHB1ENR |= GPIOX_CLOCK(USART1_RX);
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= GPIOX_CLOCK(LED);
	//GPIO
	GPIOX_MODER(MODE_ALTER, USART1_TX);
	GPIOX_MODER(MODE_ALTER, USART1_RX);
	GPIOX_AFR(7, USART1_TX);
	GPIOX_AFR(7, USART1_RX);
	GPIOX_MODER(MODE_DIGITAL_INPUT, SW);
	GPIOX_MODER(MODE_OUT, LED);
	//usart1
	USART1->CR1 = 0;
	/**
	 * baud = 115200
	 * USARTDIV  =16MHz/(16 * 115200)
	 * USARTDIV = 8.6805
	 * DIV_Mantisa = 0x8
	 * DIV_Fraction = 16 * 0.6806 ~  = B
	 * BRR = DIV_Mantisa<<4 | DIV_Fraction
	 * BRR = 0x8B
	 */
	USART1->BRR = 0x8B;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_UE;
//-->DMA STREAM7
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	DMA2_Stream7->CR = 0;
	//2. identificar el stream es cual esta asignado al usart1
		//stream 7
		//channel 4
	//3. programar la direccion fuente de la transferencia
	DMA2_Stream7->M0AR = (uint32_t)data_stream;
	//4. programar la direccion del periferico
	DMA2_Stream7->PAR = (uint32_t) &USART1->DR;
	//5. programar cuantos datos se van a transferir
	uint16_t temp = sizeof(data_stream);
	DMA2_Stream7->NDTR = temp;
	//6. configurar la direccion de transferencia de datos
	DMA2_Stream7->CR |= DMA_SxCR_DIR_0;		//memoria a periferico
	//7. programar el tamaño del dato a transferirse
	DMA2_Stream7->CR &=~ DMA_SxCR_MSIZE;
	DMA2_Stream7->CR &=~ DMA_SxCR_PSIZE;
	//8. direct mode o fifo mode
	DMA2_Stream7->FCR |= DMA_SxFCR_DMDIS;
	//DMA2_Stream7->FCR &=~DMA_SxFCR_FTH;
	DMA2_Stream7->FCR |= DMA_SxFCR_FTH;
	//9. se selecciona el canal con el que se trabajará
	DMA2_Stream7->CR &=~ DMA_SxCR_CHSEL;
	DMA2_Stream7->CR |= 0x4<<25;
	//10. se selecciona que la memoria incremente en cada transferencia de byte
	DMA2_Stream7->CR |= DMA_SxCR_MINC;
	//Configurar las interrupciones
	DMA2_Stream7->CR |= 1<<4;												//Transfer complete interrupt enable
	DMA2_Stream7->CR |= 1<<2;												//Transfer error interrupt enable
	DMA2_Stream7->FCR |=1<<7;
	NVIC_EnableIRQ(DMA2_Stream7_IRQn);
	//habilitar el estream

	sprintf((char*)data_stream, "CONFIGURACION CORRECTA DEL DMA2\r\n");
	temp = strlen((char*)data_stream);
	DMA2_Stream7->NDTR = temp;
	DMA2_Stream7->CR |= DMA_SxCR_EN;
	//delay init
	delay_init();
    /* Loop forever */
	for(;;){
		if(GPIOX_IDR(SW) == 0){
			while(GPIOX_IDR(SW) == 0);
			GPIOX_ODR(LED) ^= 1;
			//Transmitir
			USART1->CR3 |= USART_CR3_DMAT;
		}
	}
}
/*Function definition ------------------------------------------------*/
void DMA2_Stream7_IRQHandler(void){
	if(DMA2->HISR & DMA_HISR_TCIF7){			//TC
		DMA2->HIFCR |= DMA_HIFCR_CTCIF7;
		//todo
		uint16_t temp = strlen((char*)data_stream);
		DMA2_Stream7->NDTR = temp;
		USART1->CR3 &=~ USART_CR3_DMAT;
		DMA2_Stream7->CR |= DMA_SxCR_EN;
	}
	else if(DMA2->HISR & 1<<25){
		DMA2->HIFCR |= 1<<25;
		//todo

	}else if(DMA2->HISR & 1<<22){
		DMA2->HIFCR |= 1<<22;
		//todo

	}
	return;
}
/**********************************************************************/

int __io_putchar(int ch){
#if (USE_SW0 == 1)
	ITM_SendChar(ch);
#else
	//todo

#endif
	return ch;
}
