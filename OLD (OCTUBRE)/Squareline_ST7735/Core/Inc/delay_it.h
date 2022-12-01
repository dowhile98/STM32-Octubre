/**
 * @file delay_it.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DELAY_IT
#define __DELAY_IT

/*Includes -----------------------------------*/
#include "stm32f4xx.h"

/*Function prototypes ------------------------*/
/**
 * @brief configura la systick para modo interrupcion
 * 
 */
void delay_init_it(void);
/**
 * @brief genera retardos
 * 
 * @param delay : cantidad de retardo en ms deseado
 */
void delay_ms(uint32_t delay);
/**
 * @brief Get the Tick object
 * 
 * @return uint32_t 
 */
uint32_t GetTick(void);


#endif