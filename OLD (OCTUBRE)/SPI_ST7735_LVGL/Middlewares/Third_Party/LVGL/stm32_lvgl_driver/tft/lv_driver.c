/*
 * lv_driver.c
 *
 *  Created on: Oct 6, 2022
 *      Author: jeffr
 */

/*********************
 *      DEFINES
 *********************/
#include "lv_driver.h"
#include "ST7735.h"


/*********************
 *      DEFINES
 *********************/
#define ST_SCR_HORIZONTAL 	128
#define ST_SCR_VERTICAL   	160
#define BUFFOR_SCR_ROWS 	40
/**********************
 *  GLOBAL VARIABLES
 **********************/
extern uint16_t _width;  ///< Display width as modified by current rotation
extern uint16_t _height;
static lv_disp_drv_t *LastDriver;

/**********************
 *  STATIC FUNCTION
 **********************/


static void ST7735_SetAddrWindowForLv(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
			//I Create else 1 function to SetAddrWindow because LvGL calling the function
					//with other parametrs. Similar function is implemented in ../ILI9341/core.c
{
	uint8_t DataToTransfer[4];
	// Calculate end ranges
	// Fulfill X's buffer
	DataToTransfer[0] = x1 >> 8;
	DataToTransfer[1] = x1 & 0xFF;
	DataToTransfer[2] = x2 >> 8;
	DataToTransfer[3] = x2 & 0xFF;
	// Push X's buffer
	ST7735_SendCommand(ST77XX_CASET, DataToTransfer, 4);
	// Fulfill Y's buffer
	DataToTransfer[0] = y1 >> 8;
	DataToTransfer[1] = y1 & 0xFF;
	DataToTransfer[2] = y2 >> 8;
	DataToTransfer[3] = y2 & 0xFF;
	// Push Y's buffer
	ST7735_SendCommand(ST77XX_RASET, DataToTransfer, 4);
}

/*Flush the content of the internal buffer the specific area on the display
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_disp_flush_ready()' has to be called when finished.*/
static void ST7735_flush(lv_disp_drv_t * drv, const lv_area_t * area,  lv_color_t * color_map)
{
	LastDriver=drv;
	ST7735_SetAddrWindowForLv((uint16_t)area->x1, (uint16_t)area->y1, (uint16_t)area->x2, (uint16_t)area->y2);
	ST7735_WriteCommand(ST77XX_RAMWR);
	uint32_t size = (area->x2 - area->x1 +1) * (area->y2 - area->y1 +1);
	Send_DMA_Data16( (uint16_t *)color_map, size);
}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void DMA_ST7735_SPI_TransmitComplete_Callback(void)
{
	lv_disp_flush_ready(LastDriver);
}



void lv_port_disp_init(void)
{
	/*-------------------------
	 * Initialize your display
	 * -----------------------*/
	LCD_initDisplay(INITR_BLACKTAB);
	LCD_setRotation(1);

	/*-----------------------------
	 * Create a buffer for drawing
	 *----------------------------*/
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1[128 * 160 / SCREEN_PORTION]; 						/*Declare a buffer for 1/10 screen size*/
    static lv_color_t buf2[128 * 160 / SCREEN_PORTION];
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, 128 * 160 / SCREEN_PORTION); /*Initialize the display buffer.*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/
    static lv_disp_drv_t disp_drv;                                            			/*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                                              			/*Basic initialization*/
    /*Set up the functions to access to your display*/
    disp_drv.flush_cb = ST7735_flush;                                        			/*Set your driver function*/
    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf;                                            			/*Assign the buffer to the display*/
    /*Set the resolution of the display*/
    disp_drv.hor_res = _width;                                                			/*Set the horizontal resolution of the display*/
    disp_drv.ver_res = _height;                                               			/*Set the vertical resolution of the display*/
    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);                                          			/*Finally register the driver*/

    return;
}
