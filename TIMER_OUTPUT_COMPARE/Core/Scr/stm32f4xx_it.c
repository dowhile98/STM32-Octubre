/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
#include "USART.h"

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/

extern USART_Handle_t handle_usart2;


extern uint16_t pulse1 ;
extern uint16_t pulse2 ;
extern uint16_t pulse3 ;
extern uint16_t pulse4 ;
/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{

  while (1)
  {

  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  while (1)
  {

  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  while (1)
  {

  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  while (1)
  {

  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{

}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{

}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{

}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{

}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/
void USART2_IRQHandler(void)
{
	USART_IRQHandling(&handle_usart2);
}

void TIM3_IRQHandler(void){
	if(TIM3->SR & TIM_SR_CC1IF){
		TIM3->SR &=~ (TIM_SR_CC1IF);
		TIM3->CCR1 += pulse1;
	}
	if(TIM3->SR & TIM_SR_CC2IF){
		TIM3->SR &=~ TIM_SR_CC2IF;
		TIM3->CCR2 += pulse2;
	}
	if(TIM3->SR & TIM_SR_CC3IF){
		TIM3->SR &=~ TIM_SR_CC3IF;
		TIM3->CCR3 += pulse3;
	}
	if(TIM3->SR & TIM_SR_CC4IF){
		TIM3->SR &=~ TIM_SR_CC4IF;
		TIM3->CCR4 += pulse4;
	}
}


