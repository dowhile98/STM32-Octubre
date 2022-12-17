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
#include <stdbool.h>
#include <delay_it.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 	40


uint8_t rxbuffer[BUFFER_SIZE];
#define SWO_DEBUG
//#define SERIAL_USART1_DEBUG
/**
 * @brief configura el PLL a 168MHz
 */
void PLL_Config(void);
/**
 * @brief recibe la respuesta del modulo
 * @param[in] puntero  a un buffer donde se almacena la informacion
 * @param[in] tiempo de espera para el modulo
 * @return bool
 */
bool wait_for_data(uint8_t *buffer, uint32_t timout);

void CMD_AT(void);

void CMD_ID(void);

void WISOL_Printf(char *format, ...);
void CMD_PAC(void);

uint16_t CMD_BAT(void);


int main(void)
{

	//printf("SYSCLK ANTES DE CONFIGURAR EL PLL: %lu\r\n",SystemCoreClock);
	PLL_Config();
	delay_init_it();
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
	 * USARTDIV = 84MHZ / ( 16 * 9600)
	 * USARTDIV = 546.875
	 * MANTISA = 546 -> 0x222
	 * FRACTION = 0.875 * 16 = 14 ->E
	 * FRACTION = 0xE
	 * BRR = 222E
	 */
	USART1->BRR = 0x222E;
	/*habilita la transmision de datos*/
	USART1->CR1 |= USART_CR1_TE;
	/*habilitamos la recepcion*/
	USART1->CR1 |= USART_CR1_RE;
	/*habilitamos el USART1*/
	USART1->CR1 |= USART_CR1_UE;


	//USART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
#define USART2_TX 	A, 2
#define USART2_RX 	A, 3
	RCC->AHB1ENR |= GPIOX_CLOCK(USART1_TX);
	GPIOX_MODER(MODE_ALTER, USART2_TX);
	GPIOX_MODER(MODE_ALTER, USART2_RX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, USART2_TX);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, USART2_RX);
	GPIOX_AFR(7, USART2_TX);
	GPIOX_AFR(7, USART2_RX);
	/*configuracion de los parametros de la comunicacion*/
	USART2->CR1 &=~ USART_CR1_UE;		//deshabilita el usart1
	USART2->CR1 = 0x0;
	/**
	 * USARTDIV = PCLK / (16 * baud)
	 * USARTDIV = 42MHZ / ( 16 * 115200)
	 * USARTDIV = 22.78
	 * MANTISA = 22 -> 0x16
	 * FRACTION = 0.78 * 16 = 12 ->C
	 * FRACTION = 0xC
	 * BRR = 0x16C
	 */
	USART2->BRR = 0x16C;
	/*habilita la transmision de datos*/
	USART2->CR1 |= USART_CR1_TE;
	/*habilitamos la recepcion*/
	USART2->CR1 |= USART_CR1_RE;
	/*habilitamos el USART1*/
	USART2->CR1 |= USART_CR1_UE;

/********************************************************/
	CMD_AT();
	delay_ms(400);
	CMD_ID();
	delay_ms(400);
	CMD_PAC();

	delay_ms(400);

	printf("bateria->%u",CMD_BAT() );
	for(;;){


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


/**
 * @brief recibe la respuesta del modulo
 * @param[in] puntero  a un buffer donde se almacena la informacion
 * @param[in] tiempo de espera para el modulo
 * @return bool
 */
//OK\r\nRX=00 00 00 00 00 00 00 00\r\n
bool wait_for_data(uint8_t *pBuffer, uint32_t timout){
	bool state = false;
	uint8_t ch;
	uint8_t i = 0;
	uint32_t timout_init = GetTick();
	memset((void*)pBuffer, 0, BUFFER_SIZE);
	do{
		if(USART1->SR & USART_SR_RXNE){
			ch = USART1->DR;
			pBuffer[i] = ch;
			i++;
			if(i >= BUFFER_SIZE){
				i = 0;
			}
			//se verifica el caracter
			if(ch == 0x0A){
				state = true;
			}
		}
		//se verifica el timout
		if((GetTick() - timout_init)> timout ){
			printf("No Dat\r\n");
			state = false;
			memset((void*)pBuffer, 0, BUFFER_SIZE);
			break;
		}
	}while(ch != 0x0A);
	return state;
}

void CMD_AT(void){
	WISOL_Printf("AT\r");
	if(wait_for_data(rxbuffer, 2000)){
		//todo
		printf("WISOL->%s\r\n", rxbuffer);
	}else{

	}
	return;
}
void CMD_ID(void){
	char str[30] = "AT$SL=";
	WISOL_Printf("AT$I=10\r");
	if(wait_for_data(rxbuffer, 4000)){
		printf("ID:%s",rxbuffer);
		strcat(str,(char*)rxbuffer);
		printf("%s",str);
		WISOL_Printf("%s",str);
		if(wait_for_data(rxbuffer, 30000)){
			printf("%s",rxbuffer);
		}
	}else{
		//todo

	}

}

void CMD_PAC(void){
	char str[30] = "AT$SL=";
	WISOL_Printf("AT$I=11\r");
	if(wait_for_data(rxbuffer, 4000)){
		printf("PAC:%s",rxbuffer);
		strcat(str,(char*)rxbuffer);
		printf("%s",str);
		WISOL_Printf("%s",str);
		if(wait_for_data(rxbuffer, 30000)){
			printf("%s",rxbuffer);
		}
	}else{

	}
}

uint16_t CMD_BAT(void){
	uint16_t bat;
	WISOL_Printf("AT$V?\r");
	if(wait_for_data(rxbuffer, 20000)){
		printf("%s",rxbuffer);
		bat = atol((const char*)rxbuffer);
		return bat;
	}
	return 0;
}

void WISOL_Printf(char *format, ...){
	char str[80];
	char *ptr = str;

	va_list args;
	va_start(args, format);
	vsprintf(str, format, args);
	for(uint8_t i = 0; i < strlen(str); i++){
		while(!(USART1->SR & USART_SR_TXE));
		USART1->DR = *ptr;
		ptr++;
	}
	va_end(args);
}
/**************************************************/
//printf
int __io_putchar(int ch){
#if defined(SWO_DEBUG)
	ITM_SendChar(ch);
#endif

#if defined(SERIAL_USART1_DEBUG)
	uint8_t c = ch & 0xFF;
	while(!(USART2->SR & USART_SR_TXE));
	USART2->DR = c;
#endif
	return ch;
}
//scanf
int __io_getchar(void){
	while(!(USART2->SR & USART_SR_RXNE));
	uint8_t data = USART2->DR;
	return data;
}
