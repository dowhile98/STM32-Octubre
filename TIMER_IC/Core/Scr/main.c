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
#include "stm32f4xx.h"
#include "Config.h"
#include "delay.h"

#define DUTY(x)			(uint16_t)((((float)x/100)*(TIM3->ARR + 1)) - 1)

#define TIM2_CH1		A , 0
#define TIM3_CH3		B , 0

#define CK_PSC			16E+6
#define TIM2_PSC			1
#define CH1_PSC			1
#define POLARITY		1
/**
 * @brief timer 2, canal 1 como captura de entrada
 */
void TIM2_ConfigIC(void);
/**
 * brief timer 3 canal 3 como generacion de pwm
 */
void TIM3_CofigOC(void);
/**
 * @brief calcular la frecuencia
 */
static float computeFreq(void);


float freq;

int main(void)
{
	delay_Init();
	/*************************/
	TIM2_ConfigIC();
	TIM3_CofigOC();
	TIM3->CCR3 = DUTY(10);
    /* Loop forever */
	for(;;){
		freq = computeFreq();
		delay_ms(400);
	}
}


/**
 * @brief timer 2, canal 1 como captura de entrada
 */
void TIM2_ConfigIC(void){
	//PA0 -> TIM2_CH1
	RCC->AHB1ENR |= GPIOX_CLOCK(TIM2_CH1);
	GPIOX_MODER(MODE_ALTER,TIM2_CH1);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH,TIM2_CH1);
	GPIOX_AFR(1, TIM2_CH1);
	/*****************************************/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;		//ENABLE CLOCK
	/*CONFIGURAR LA FREQ y el valor de Autorecarga*/
	/*
	 * periodo maximo
	 * Tmax = (ARR + 1)(PSC + 1)/Ftim
	 * Frecuencia minima
	 * Fmin = 1/Tmax
	 * Tmax = (0xFFFFFFFF + 1)(1)/16MHZ = 268.43 seg
	 * Fmin = 3.73E-3 Hz
	 */
	TIM2->CR1 = 0;
	TIM2->PSC = TIM2_PSC - 1;
	TIM2->ARR = 0xFFFFFFFF;
	/*configuracion del canal el cual va trabajar en modo IC*/
	TIM2->CCMR1 |= TIM_CCMR1_CC1S_0;		//TI1 -> COMO ENTRADA
	/*Configurar el filtro*/
	TIM2->CCMR1 |= 0b0110<<4;				//FILTRO DIGITAL
	/*SELECCIONAR EL FLANCO*/
	TIM2->CCER &=~(TIM_CCER_CC1NP | TIM_CCER_CC1P);//RISING EDGE
	/*SELECCIONAR EL PRESCALER DE ENTRADA*/
	TIM2->CCMR1 &=~(TIM_CCMR1_IC1PSC);		//NO PRESCALER
	/*HABILITAR LA CAPTURA*/
	TIM2->CCER |= TIM_CCER_CC1E;			//HABILITA LA CAPTURA
	/*habilitar el conteo del timer*/
	TIM2->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief calcular la frecuencia
 */
static float computeFreq(void){
	uint32_t IC[2];
	float diff;
	float freq;

	/*se detecta el primer flanco*/
	TIM2->SR &=~ TIM_SR_CC1IF;
	while(!(TIM2->SR & TIM_SR_CC1IF));	//ESPERA EL FLANCO
	IC[0] = TIM2->CCR1;
	/*se detecta el segundo flanco*/
	TIM2->SR &=~ TIM_SR_CC1IF;
	while(!(TIM2->SR & TIM_SR_CC1IF));	//espera el segundo flanco
	TIM2->SR &=~ TIM_SR_CC1IF;
	IC[1] = TIM2->CCR1;
	/*se realiza el calculo*/
	if(IC[1]>= IC[0])
		diff = IC[1] - IC[0];
	else
		diff = TIM2->ARR - IC[0] + IC[1];
	freq = (float)((CK_PSC/((TIM2->PSC +1)  * POLARITY)) / diff) * CH1_PSC;

	return freq;
}

/**
 * brief timer 3 canal 3 como generacion de pwm
 */
void TIM3_CofigOC(void){
	//PB0 -> TIM3_CH3
	RCC->AHB1ENR |= GPIOX_CLOCK(TIM3_CH3);
	GPIOX_MODER(MODE_ALTER,TIM3_CH3);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH,TIM3_CH3);
	GPIOX_AFR(2, TIM3_CH3);
	/****************************************/
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	/**
	 * Fpwm = Ftim/(ARR + 1)(PSC + 1)
	 * ARR = Ftim /(PSC +1)Fpwm - 1
	 * ARR = 16MHZ/(15 + 1)1000 - 1
	 * ARR = 1000 - 1
	 */
	TIM3->CR1 = 0;
	TIM3->PSC = 16 - 1;
	TIM3->ARR = 1000 - 1;
	/*Configurar el canal3*/
	TIM3->CCMR2 &=~( TIM_CCMR2_CC3S);
	//MODO DE COMPARACION
	TIM3->CCMR2 &=~ (TIM_CCMR2_OC3M);
	TIM3->CCMR2 |= 0x6U<<4;				//PWM -> MODO 1
	/*POLARIDAD*/
	TIM3->CCER &=~ (TIM_CCER_CC3P);
	// HABILITA EL CANAL PARA LA COMPARACION DE SALIDA
	TIM3->CCER |= TIM_CCER_CC3E;
	/*HABILITAR EL CONTEO DEL TIMER*/
	TIM3->CR1 |= TIM_CR1_CEN;

}