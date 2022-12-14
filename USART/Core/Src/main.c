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

#include <stdint.h>
#include <stm32f4xx.h>
#include <stdio.h>
#include <defines.h>

//#define SWO_DEBUG
#define SERIAL_USART1_DEBUG
/**
 * @brief configura el PLL a 168MHz
 */
void PLL_Config(void);


int main(void)
{

	//printf("SYSCLK ANTES DE CONFIGURAR EL PLL: %lu\r\n",SystemCoreClock);
	PLL_Config();

	//->USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	/**
	 * PB6 -> USART1_TX
	 * PB7 -> USART1_RX
	 */
#define USART1_TX 	B, 6
#define USART1_RX 	B, 7
	RCC->AHB1ENR |= GPIOX_CLOCK(USART1_TX);
	GPIOX_MODER(MODE_ALTER, USART1_TX);
	GPIOX_MODER(MODE_ALTER, USART1_RX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, USART1_TX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, USART1_RX);
	GPIOX_AFR(7, USART1_TX);
	GPIOX_AFR(7, USART1_RX);
	/*configuracion de los parametros de la comunicacion*/
	USART1->CR1 &=~ USART_CR1_UE;		//deshabilita el usart1
	USART1->CR1 = 0x0;
	/**
	 * USARTDIV = PCLK / (16 * baud)
	 * USARTDIV = 84MHZ / ( 16 * 115200)
	 * USARTDIV = 45.57
	 * MANTISA = 45 -> 0x2D
	 * FRACTION = 0.57 * 16 = 9.12 ->9
	 * FRACTION = 0x9
	 * BRR = 2D9
	 */
	USART1->BRR = 0x2D9;
	/*habilita la transmision de datos*/
	USART1->CR1 |= USART_CR1_TE;
	/*habilitamos la recepcion*/
	USART1->CR1 |= USART_CR1_RE;
	/*habilitamos el USART1*/
	USART1->CR1 |= USART_CR1_UE;
//	/*Transmitir*/
//	while(!(USART1->SR & USART_SR_TXE));
//	USART1->DR = 'H';
//	/*recibir*/
//	while(!(USART1->SR & USART_SR_RXNE));
//	uint8_t data = USART1->DR;
	printf("INGRESE SU EDAD->");
	for(;;){
		__WFI();
//		uint8_t edad;
//		scanf("%u",&edad);
//		printf("su edad es: %d",edad);
	}
}

void PLL_Config(void){
	//1. apagar el pll y esperar que la bandera se limpie
	RCC->CR &=~ (RCC_CR_PLLON);  //RCC->CR &=~ (1<<24);
	while(RCC->CR & RCC_CR_PLLRDY);
	//2. configurar los parametros del pll
	//->Encender el HSE
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	//->HSE como fuente para el PLL
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;			//->HSE -> PLL
	/**
	 * 8MHZ -> / M <1-2MH> -> * N <50-432MH>
	 * Sysclk = ((8MHz/8) * 336) / 2 = 168MHz
	 */
	//->M
	RCC->PLLCFGR &=~ RCC_PLLCFGR_PLLM;
	RCC->PLLCFGR |= 8U<<RCC_PLLCFGR_PLLM_Pos;
	//->N
	RCC->PLLCFGR &=~ RCC_PLLCFGR_PLLN;
	RCC->PLLCFGR |= 336<<RCC_PLLCFGR_PLLN_Pos;
	//->P
	RCC->PLLCFGR &=~ RCC_PLLCFGR_PLLP;
	//3. configurar la latencia de la flash
	FLASH->ACR |= FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN;
	FLASH->ACR |= FLASH_ACR_LATENCY_5WS;
	//->encender el PLL
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	//4. seleccionar el PLL como fuente de reloj
	//->Configurar los prescalers de los buses APB1 y ABP2
	//->APB1
	RCC->CFGR &=~ RCC_CFGR_PPRE1;
	RCC->CFGR |= 0x5u<<RCC_CFGR_PPRE1_Pos;
	//->APB2
	RCC->CFGR &=~ RCC_CFGR_PPRE2;
	RCC->CFGR |= RCC_CFGR_PPRE2_2;
	//->Seleccionar el PLL como fuente de reloj del sistema
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));

	SystemCoreClockUpdate();
	return;
}

/**************************************************/
//printf
int __io_putchar(int ch){
#if defined(SWO_DEBUG)
	ITM_SendChar(ch);
#endif

#if defined(SERIAL_USART1_DEBUG)
	uint8_t c = ch & 0xFF;
	while(!(USART1->SR & USART_SR_TXE));
	USART1->DR = c;
#endif
	return ch;
}
//scanf
int __io_getchar(void){
	while(!(USART1->SR & USART_SR_RXNE));
	uint8_t data = USART1->DR;
	return data;
}
