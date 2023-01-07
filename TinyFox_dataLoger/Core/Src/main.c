/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct{
	uint32_t sensor;
	uint8_t status;
	uint16_t bat;
}DataTx_t;

typedef struct{
	uint8_t periodo;
	uint8_t dowlink;
	struct{
		uint8_t rsv : 3;
		uint8_t modo: 2;
		uint8_t relay2 : 1;
		uint8_t relay1 : 1;
		uint8_t LED : 1;
	}estados;
}DataRx_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define BUFER_SIZE              40
#define UPLINK                  0
#define DOWNLINK                1
#define L_UPLINK                2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

char rxdata[BUFER_SIZE];
char cadena[BUFER_SIZE];
uint8_t countchar = 0;
uint32_t timout = 0;
DataTx_t dataTx;
DataRx_t *dataRx;
uint32_t lastmsg;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void recepcion(char val_caracter)
{
   cadena[countchar]=val_caracter;
   countchar++;
   if(countchar >= BUFER_SIZE)  //caso de error de recepcion
   {
      countchar=0;
   }
   if (val_caracter == 0x0A){
      memset(rxdata, 0, BUFER_SIZE);
      for(int k=0; k<=countchar; k++){
         rxdata[k]=cadena[k];;
      }
      memset(cadena, 0, BUFER_SIZE);
   }
}
void WISOL_Printf(char *format, ...){
	char str[80];

	va_list args;
	va_start(args, format);
	vsprintf(str, format, args);
	HAL_UART_Transmit(&huart1, (uint8_t*)str, strlen(str), 1000);
	va_end(args);
}

bool wait_for_data(uint32_t t_wait_ms){
   char ch = '\0';
   timout = HAL_GetTick();
   countchar=0;
   do{
      //se verifica si se tien un bit disponible
      if(USART1->ISR & USART_ISR_RXNE){
         ch = USART1->RDR;
         recepcion(ch);					//QUEUE
      }
      //se verifica el timout
      if((HAL_GetTick() - timout)>t_wait_ms){
         printf( "NoDAT\r\n");
         memset(cadena, 0, BUFER_SIZE);
         memset(rxdata, 0, BUFER_SIZE);
         break;
      }

   }while (ch != 0x0A);

   //se retorna el resultado
   if(ch == 0x0A){
      return true;
   }else{
      return false;
   }
}
void CMD_ID(void){
	char str[30] = "AT$SL=";
    char id[9] = {'\0'};
    uint8_t i;
	WISOL_Printf("AT$I=10\r\n");
	if(wait_for_data(4000)){
		printf("ID:%s",rxdata);
        for(i = 0; i<8; i++){id[i]=rxdata[i];}
        //dataTx.ID = hexstr2int32(id);
		strcat(str,(char*)rxdata);
		printf("%s",str);
		WISOL_Printf("%s",str);
		if(wait_for_data(30000)){
			printf("%s",rxdata);
		}
	}else{
		//todo

	}

}

void CMD_PAC(void){
	char str[30] = "AT$SL=";
	WISOL_Printf("AT$I=11\r\n");
	if(wait_for_data( 4000)){
		printf("PAC:%s",rxdata);
		strcat(str,(char*)rxdata);
		printf("%s",str);
		WISOL_Printf("%s",str);
		if(wait_for_data( 30000)){
			printf("%s",rxdata);
		}
	}else{
        printf("Error PAC\r\n");
	}
}

void CMD_AT(void){
	WISOL_Printf("AT\r\n");
	if(wait_for_data(2000)){
		//todo
		printf("WISOL->%s\r\n", rxdata);
	}else{
        printf("Error Wisol\n\n");
	}
	return;
}

void CMD_POWER_MODE(int val_pwr){
   if(val_pwr>=5) return ;

   if(val_pwr == 2){

        HAL_Delay(50);
        WISOL_Printf("AT$P=%u\r\n",val_pwr);
        wait_for_data(10000);
        HAL_Delay(50);
        HAL_GPIO_WritePin(WISOL_RST_GPIO_Port, WISOL_RST_Pin, GPIO_PIN_RESET);
        HAL_Delay(50);
   }
   if(val_pwr == 4){
        HAL_GPIO_WritePin(WISOL_RST_GPIO_Port, WISOL_RST_Pin, GPIO_PIN_SET);
        HAL_Delay(50);
        HAL_GPIO_WritePin(WISOL_RST_GPIO_Port, WISOL_RST_Pin, GPIO_PIN_RESET);
        HAL_Delay(80);
        HAL_GPIO_WritePin(WISOL_RST_GPIO_Port, WISOL_RST_Pin, GPIO_PIN_SET);
        HAL_Delay(80);
    }
}


uint16_t CMD_BAT(void){
	uint16_t bat;

	unsigned char ch = 0;
    countchar = 0;
    timout = HAL_GetTick();
    memset(rxdata, 0, BUFER_SIZE);
    memset(cadena, 0, BUFER_SIZE);
    WISOL_Printf("AT$V?\r\n");
    do{
       if(USART1->ISR & USART_ISR_RXNE){
          ch = USART1->RDR;
          cadena[countchar] = ch;
          countchar++;
       }
       if((HAL_GetTick() - timout)>5000){
          memset(rxdata, 0, BUFER_SIZE);
          memset(cadena, 0, BUFER_SIZE);
          break;
       }
    }while( ch != 0x0A);
    countchar = 0;
    //timout = HAL_GetTick();
    do{
       if(USART1->ISR & USART_ISR_RXNE){
          ch = USART1->RDR;
          rxdata[countchar] = ch;
          countchar++;
       }
       if((HAL_GetTick() - timout)>5000){
          memset(rxdata, 0, BUFER_SIZE);
          memset(cadena, 0, BUFER_SIZE);
          break;
       }
    }while (ch != 0x0A);
    bat = atol(cadena);
    LPUART1->CR1 &=~ USART_CR1_UE;
    HAL_Delay(50);
    LPUART1->CR1 |=USART_CR1_UE;
    return bat;
}
void send_uplink(void){
	//se enciende la wisol
	CMD_POWER_MODE(4);
	HAL_Delay(100);
	CMD_AT();
	WISOL_Printf("AT$RC\r\n");
	wait_for_data(10000);
	//dataTx.bat = CMD_BAT();
	HAL_Delay(100);
	printf("uplink\r\n");
	//WISOL_Printf("AT$SF=%08X%%02X%04X\r\n", dataTx.sensor, dataTx.status, dataTx.bat);
	WISOL_Printf("AT$SL=%08X%X%X\r\n", dataTx.sensor, dataTx.status, dataTx.bat);
	if(wait_for_data(30000)){
		printf("datos envidos->%s", rxdata);
	}else{
		printf("error send data\r\n");
	}
	CMD_POWER_MODE(2);
	return;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  CMD_POWER_MODE(4);			//enciende la wisool
  HAL_Delay(400);
  CMD_ID();
  HAL_Delay(100);
  CMD_PAC();
  /* USER CODE END 2 */
  lastmsg = HAL_GetTick();
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if((HAL_GetTick() - lastmsg)>20000){
		  send_uplink();
		  dataTx.sensor ++;
		  lastmsg = HAL_GetTick();
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */
int __io_putchar(int ch){
	uint8_t c = ch & 0xFF;
	HAL_UART_Transmit(&huart2, &c, 1, 1);
	return ch;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
