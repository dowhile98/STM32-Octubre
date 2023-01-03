/*
 * stm32f4xx_it.c
 *
 *  Created on: 21 dic. 2022
 *      Author: jeffr
 */


#include <stm32f4xx.h>
#include <stdio.h>
uint16_t data;


void ADC_IRQHandler(void){
	if(ADC1->SR & ADC_SR_EOC){
		data = ADC1->DR;
		printf("IN1->%d", data);
	}
	return;
}
