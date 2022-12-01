/*
 * HD44780.h
 *
 *  Created on: 12 oct. 2022
 *      Author: jeffr
 */

#ifndef INC_HD44780_H_
#define INC_HD44780_H_

/*Includes -------------------------------------------------*/
#include "stm32f4xx.h"
#include "delay.h"
#include "defines.h"
#include <stdarg.h>
#include <stdio.h>

/*Macro defines --------------------------------------------*/
/* 4 bit mode */
/* Control pins, can be overwritten */
/* RS - Register select pin */
#define LCD_RS					A , 0
/* E - Enable pin */
#define LCD_E					A , 1
/* Data pins */
/* D4 - Data 4 pin */
#define LCD_D4					A , 4
/* D5 - Data 5 pin */
#define LCD_D5					B , 0
/* D6 - Data 6 pin */
#define LCD_D6					C , 1
/* D7 - Data 7 pin */
#define LCD_D7					C , 0

/*Function prototypes --------------------------------------*/
/**
 * @brief  Initializes HD44780 LCD
 * @brief  cols: width of lcd
 * @param  rows: height of lcd
 * @retval None
 */
void LCD_Init(uint8_t cols, uint8_t rows);

/**
 * @brief  Turn display on
 * @param  None
 * @retval None
 */
void LCD_DisplayOn(void);

/**
 * @brief  Turn display off
 * @param  None
 * @retval None
 */
void LCD_DisplayOff(void);

/**
 * @brief  Clears entire LCD
 * @param  None
 * @retval None
 */
void LCD_Clear(void);

/**
 * @brief  Puts string on lcd
 * @param  x location
 * @param  y location
 * @param  *str: pointer to string to display
 * @retval None
 */
void LCD_Puts(uint8_t x, uint8_t y, char* str);

/**
 * @brief  Enables cursor blink
 * @param  None
 * @retval None
 */
void LCD_BlinkOn(void);

/**
 * @brief  Disables cursor blink
 * @param  None
 * @retval None
 */
void LCD_BlinkOff(void);

/**
 * @brief  Shows cursor
 * @param  None
 * @retval None
 */
void LCD_CursorOn(void);

/**
 * @brief  Hides cursor
 * @param  None
 * @retval None
 */
void LCD_CursorOff(void);

/**
 * @brief  Scrolls display to the left
 * @param  None
 * @retval None
 */
void LCD_ScrollLeft(void);

/**
 * @brief  Scrolls display to the right
 * @param  None
 * @retval None
 */
void LCD_ScrollRight(void);

/**
 * @brief  Creates custom character
 * @param  location: Location where to save character on LCD. LCD supports up to 8 custom characters, so locations are 0 - 7
 * @param *data: Pointer to 8-bytes of data for one character
 * @retval None
 */
void LCD_CreateChar(uint8_t location, uint8_t* data);

/**
 * @brief  Puts custom created character on LCD
 * @param  location: Location on LCD where character is stored, 0 - 7
 * @retval None
 */
void LCD_PutCustom(uint8_t x, uint8_t y, uint8_t location);

/**
 * @brief  Puts string on lcd
 * @param  x location
 * @param  y location
 * @param  *str: pointer to string to display
 * @retval None
 */
void LCD_Printf(uint8_t x, uint8_t y,char *format,...);


#endif /* INC_HD44780_H_ */
