/**
 * @file delay_it.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "delay_it.h"
/*variable global*/
volatile uint32_t uwTick = 0;
/**
 * @brief configura la systick para modo interrupcion
 * 
 */
void delay_init_it(void){
    uint32_t temp;

    //deshabilitar
    SysTick->CTRL = 0;
    //calcular el reload
    SystemCoreClockUpdate();
    temp = SystemCoreClock / 1000;
    SysTick->LOAD = temp - 1;
    //configura el registro de control
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    return;

}
/**
 * @brief Retorna el valor de la variabla ticks
 * @param none
 * @return ticks
 */
uint32_t GetTick(void){
	return uwTick;
}

/**
 * @brief genera retardos
 * 
 * @param delay : cantidad de retardo en ms deseado
 */
void delay_ms(uint32_t delay){
    uint32_t tickstart = GetTick();
	uint32_t wait = delay;
	//generacion del retardo
	while((GetTick() - tickstart)<wait);

	return;
}