/**
 * @file stm32f4xx_it.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <defines.h>
#include <stm32f4xx.h>

extern void EXIT_IRQHandling(uint32_t pin_number);
void EXTI15_10_IRQHandler (void){
    // if(EXTI->PR & EXTI_PR_PR13){
    //     EXTI->PR |= EXTI_PR_PR13;
    //     //TODO
    // }
    EXIT_IRQHandling(GPIOX_PIN(BUTTON));
    return;
}