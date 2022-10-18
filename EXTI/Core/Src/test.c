/*
 * test.c
 *
 *  Created on: 14 oct. 2022
 *      Author: jeffr
 */
#include <stm32f4xx.h>
#define __weak __attribute__((weak))


__weak void EXTI_ApplicationCallback(uint32_t pinnumber){

	if(pinnumber == 13){
		//todo

	}

}
