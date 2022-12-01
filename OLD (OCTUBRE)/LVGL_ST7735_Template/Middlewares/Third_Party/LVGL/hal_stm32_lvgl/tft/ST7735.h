/*
 * ST7735.h
 *
 *  Created on: Nov 3, 2022
 *      Author: jeffr
 */

#ifndef THIRD_PARTY_LVGL_HAL_STM32_LVGL_TFT_ST7735_H_
#define THIRD_PARTY_LVGL_HAL_STM32_LVGL_TFT_ST7735_H_
#ifdef __cplusplus
 extern "C" {
#endif

/*Includes -----------------------------------------------------------*/
#include "stm32f4xx.h"
#include "delay_it.h"
#include "defines.h"

/*Macros Defines-------------------------------------------------------*/
//--------->USER DEFINES
#define CS			    B, 6                //Chip select
#define RESET		    B, 7                //Reset pinout
#define A0			    B, 4                //DC pin
#define LCD_Delay       delay_ms            //definir su funcion de retardo
#define LCD_SPI			SPI3
                        //DMA  STREAM
#define LCD_DMA         1, 5

//--------->LCD
#define ST7735_TFTWIDTH_128     128  // for 1.44 and mini
#define ST7735_TFTWIDTH_80      80    // for mini
#define ST7735_TFTHEIGHT_128    128 // for 1.44" display
#define ST7735_TFTHEIGHT_160    160 // for 1.8" and mini display

#define INITR_GREENTAB          0x00
#define INITR_REDTAB            0x01
#define INITR_BLACKTAB          0x02
#define INITR_18GREENTAB        INITR_GREENTAB
#define INITR_18REDTAB          INITR_REDTAB
#define INITR_18BLACKTAB        INITR_BLACKTAB
#define INITR_144GREENTAB       0x01
#define INITR_MINI160x80        0x04
#define INITR_HALLOWING         0x05

// Some register settings
#define ST7735_MADCTL_BGR       0x08
#define ST7735_MADCTL_MH        0x04

#define ST7735_FRMCTR1          0xB1
#define ST7735_FRMCTR2          0xB2
#define ST7735_FRMCTR3          0xB3
#define ST7735_INVCTR           0xB4
#define ST7735_DISSET5          0xB6

#define ST7735_PWCTR1           0xC0
#define ST7735_PWCTR2           0xC1
#define ST7735_PWCTR3           0xC2
#define ST7735_PWCTR4           0xC3
#define ST7735_PWCTR5           0xC4
#define ST7735_VMCTR1           0xC5

#define ST7735_PWCTR6           0xFC

#define ST7735_GMCTRP1          0xE0
#define ST7735_GMCTRN1          0xE1

#define ST_CMD_DELAY            0x80 // special signifier for command lists

#define ST77XX_NOP              0x00
#define ST77XX_SWRESET          0x01
#define ST77XX_RDDID            0x04
#define ST77XX_RDDST            0x09

#define ST77XX_SLPIN            0x10
#define ST77XX_SLPOUT           0x11
#define ST77XX_PTLON            0x12
#define ST77XX_NORON            0x13

#define ST77XX_INVOFF           0x20
#define ST77XX_INVON            0x21
#define ST77XX_DISPOFF          0x28
#define ST77XX_DISPON           0x29
#define ST77XX_CASET            0x2A
#define ST77XX_RASET            0x2B
#define ST77XX_RAMWR            0x2C
#define ST77XX_RAMRD            0x2E

#define ST77XX_PTLAR            0x30
#define ST77XX_TEOFF            0x34
#define ST77XX_TEON             0x35
#define ST77XX_MADCTL           0x36
#define ST77XX_COLMOD           0x3A

#define ST77XX_MADCTL_MY        0x80
#define ST77XX_MADCTL_MX        0x40
#define ST77XX_MADCTL_MV        0x20
#define ST77XX_MADCTL_ML        0x10
#define ST77XX_MADCTL_RGB       0x00

#define ST77XX_RDID1            0xDA
#define ST77XX_RDID2            0xDB
#define ST77XX_RDID3            0xDC
#define ST77XX_RDID4            0xDD

// Some ready-made 16-bit ('565') color settings:
#define ST77XX_BLACK            0x0000
#define ST77XX_WHITE            0xFFFF
#define ST77XX_RED              0xF800
#define ST77XX_GREEN            0x07E0
#define ST77XX_BLUE             0x001F
#define ST77XX_CYAN             0x07FF
#define ST77XX_MAGENTA          0xF81F
#define ST77XX_YELLOW           0xFFE0
#define ST77XX_ORANGE           0xFC00


 // Color definitions
 #define BLACK                  0x0000
 #define BLUE                   0x001F
 #define RED                    0xF800
 #define GREEN                  0x07E0
 #define CYAN                   0x07FF
 #define MAGENTA                0xF81F
 #define YELLOW                 0xFFE0
 #define WHITE                  0xFFFF
 #define color565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

/*Function definition -----------------------------------------------*/
/**
 * @brief 
 * 
 * @param options 
 */
 void LCD_initDisplay(uint8_t options);
/**
 * @brief 
 * 
 * @param m 
 */
 void LCD_setRotation(uint8_t m);
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param w 
 * @param h 
 * @param bitmap 
 */
 void LCD_WriteBitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);
 /**
  * @brief 
  * 
  * @param x 
  * @param y 
  * @param col 
  */
 void LCD_WritePixel(int x, int y, uint16_t col);
/**
 * @brief 
 * 
 * @param commandByte 
 * @param dataBytes 
 * @param numDataBytes 
 */
 void ST7735_SendCommand(uint8_t commandByte, uint8_t *dataBytes, uint8_t numDataBytes);
 /**
  * @brief 
  * 
  * @param cmd 
  */
 void ST7735_WriteCommand(uint8_t cmd);
/**
 * @brief 
 * 
 * @param buff 
 * @param dataSize 
 */
 void Send_DMA_Data16(uint16_t* buff, uint16_t dataSize);

/**
 *
 */
 void DMA_TransmitComplete_Callback();
#ifdef __cplusplus
}
#endif
#endif /* THIRD_PARTY_LVGL_HAL_STM32_LVGL_TFT_ST7735_H_ */
