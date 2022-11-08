/*
 * stm32f4xx_it.c
 *
 *  Created on: Nov 4, 2022
 *      Author: jeffr
 */


#include "defines.h"
#include "stm32f4xx.h"
#include "ST7735.h"

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA2_Stream5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream5_IRQn 0 */
	DMA_TransmitComplete_Callback();
  /* USER CODE END DMA1_Stream5_IRQn 0 */

  /* USER CODE BEGIN DMA1_Stream5_IRQn 1 */

  /* USER CODE END DMA1_Stream5_IRQn 1 */
}
