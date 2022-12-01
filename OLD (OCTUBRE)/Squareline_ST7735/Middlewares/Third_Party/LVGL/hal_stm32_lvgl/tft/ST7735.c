/**
 * @file ST7735.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Includes --------------------------------------------------------*/
#include "ST7735.h"

/*Defines ---------------------------------------------------------*/
#define ST7735_Select()		GPIOX_ODR(CS) = 0
#define ST7735_DeSelect()	GPIOX_ODR(CS) = 1
#define ST7735_RegCommand()	GPIOX_ODR(A0) = 0
#define ST7735_RegData()	GPIOX_ODR(A0) = 1
#define DMAx_(a, b)         DMA ## a
#define DMAx(a)             DMAx_(a)
#define DMAx_Streamy_(a,b)  DMA ## a ## _Stream ## b
#define DMAx_Streamy(a)     DMAx_Streamy_(a)
#define STREAM_NUMBER_(a, b) b
#define STREAM_NUMBER(a)    STREAM_NUMBER_(a)
#define STREAM_TC_H_MASK_(a, b) DMA_HIFCR_CTCIF ## b
#define STREAM_TC_H_MASK(a)     STREAM_TC_H_MASK_(a)
#define STREAM_TC_L_MASK_(a, b) DMA_LIFCR_CTCIF ## b
#define STREAM_TC_L_MASK(a)   STREAM_TC_L_MASK_(a)
/*Extern definition -----------------------------------------------*/
extern void DMA_ST7735_SPI_TransmitComplete_Callback(void);
/*Global variables ------------------------------------------------*/
volatile uint32_t flag_DMA_Stream_bsy;
uint16_t _colstart = 0, _rowstart = 0, _colstart2 = 0, _rowstart2 = 0;
uint8_t tabcolor;
uint16_t _width;  ///< Display width as modified by current rotation
uint16_t _height; ///< Display height as modified by current rotation
int16_t _xstart = 0; ///< Internal framebuffer X offset
int16_t _ystart = 0; ///< Internal framebuffer Y offset
uint8_t rotation;
/*Const data -----------------------------------------------*/
const uint8_t Bcmd[] = {			  // Init commands for 7735B screens
	18,								  // 18 commands in list:
	ST77XX_SWRESET, ST_CMD_DELAY,	  //  1: Software reset, no args, w/delay
	50,								  //     50 ms delay
	ST77XX_SLPOUT, ST_CMD_DELAY,	  //  2: Out of sleep mode, no args, w/delay
	255,							  //     255 = max (500 ms) delay
	ST77XX_COLMOD, 1 + ST_CMD_DELAY,  //  3: Set color mode, 1 arg + delay:
	0x05,							  //     16-bit color
	10,								  //     10 ms delay
	ST7735_FRMCTR1, 3 + ST_CMD_DELAY, //  4: Frame rate control, 3 args + delay:
	0x00,							  //     fastest refresh
	0x06,							  //     6 lines front porch
	0x03,							  //     3 lines back porch
	10,								  //     10 ms delay
	ST77XX_MADCTL, 1,				  //  5: Mem access ctl (directions), 1 arg:
	0x08,							  //     Row/col addr, bottom-top refresh
	ST7735_DISSET5, 2,				  //  6: Display settings #5, 2 args:
	0x15,							  //     1 clk cycle nonoverlap, 2 cycle gate
									  //     rise, 3 cycle osc equalize
	0x02,							  //     Fix on VTL
	ST7735_INVCTR, 1,				  //  7: Display inversion control, 1 arg:
	0x0,							  //     Line inversion
	ST7735_PWCTR1, 2 + ST_CMD_DELAY,  //  8: Power control, 2 args + delay:
	0x02,							  //     GVDD = 4.7V
	0x70,							  //     1.0uA
	10,								  //     10 ms delay
	ST7735_PWCTR2, 1,				  //  9: Power control, 1 arg, no delay:
	0x05,							  //     VGH = 14.7V, VGL = -7.35V
	ST7735_PWCTR3, 2,				  // 10: Power control, 2 args, no delay:
	0x01,							  //     Opamp current small
	0x02,							  //     Boost frequency
	ST7735_VMCTR1, 2 + ST_CMD_DELAY,  // 11: Power control, 2 args + delay:
	0x3C,							  //     VCOMH = 4V
	0x38,							  //     VCOML = -1.1V
	10,								  //     10 ms delay
	ST7735_PWCTR6, 2,				  // 12: Power control, 2 args, no delay:
	0x11, 0x15,
	ST7735_GMCTRP1, 16,		// 13: Gamma Adjustments (pos. polarity), 16 args + delay:
	0x09, 0x16, 0x09, 0x20, //     (Not entirely necessary, but provides
	0x21, 0x1B, 0x13, 0x19, //      accurate colors)
	0x17, 0x15, 0x1E, 0x2B, 0x04, 0x05, 0x02, 0x0E,
	ST7735_GMCTRN1, 16 + ST_CMD_DELAY,					// 14: Gamma Adjustments (neg. polarity), 16 args + delay:
	0x0B, 0x14, 0x08, 0x1E,								//     (Not entirely necessary, but provides
	0x22, 0x1D, 0x18, 0x1E,								//      accurate colors)
	0x1B, 0x1A, 0x24, 0x2B, 0x06, 0x06, 0x02, 0x0F, 10, //     10 ms delay
	ST77XX_CASET, 4,									// 15: Column addr set, 4 args, no delay:
	0x00, 0x02,											//     XSTART = 2
	0x00, 0x81,											//     XEND = 129
	ST77XX_RASET, 4,									// 16: Row addr set, 4 args, no delay:
	0x00, 0x02,											//     XSTART = 1
	0x00, 0x81,											//     XEND = 160
	ST77XX_NORON, ST_CMD_DELAY,							// 17: Normal display on, no args, w/delay
	10,													//     10 ms delay
	ST77XX_DISPON, ST_CMD_DELAY,						// 18: Main screen turn on, no args, delay
	255},												//     255 = max (500 ms) delay

	Rcmd1[] = {						  // 7735R init, part 1 (red or green tab)
		15,							  // 15 commands in list:
		ST77XX_SWRESET, ST_CMD_DELAY, //  1: Software reset, 0 args, w/delay
		150,						  //     150 ms delay
		ST77XX_SLPOUT, ST_CMD_DELAY,  //  2: Out of sleep mode, 0 args, w/delay
		255,						  //     500 ms delay
		ST7735_FRMCTR1, 3,			  //  3: Framerate ctrl - normal mode, 3 arg:
		0x01, 0x2C, 0x2D,			  //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
		ST7735_FRMCTR2, 3,			  //  4: Framerate ctrl - idle mode, 3 args:
		0x01, 0x2C, 0x2D,			  //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
		ST7735_FRMCTR3, 6,			  //  5: Framerate - partial mode, 6 args:
		0x01, 0x2C, 0x2D,			  //     Dot inversion mode
		0x01, 0x2C, 0x2D,			  //     Line inversion mode
		ST7735_INVCTR, 1,			  //  6: Display inversion ctrl, 1 arg:
		0x07,						  //     No inversion
		ST7735_PWCTR1, 3,			  //  7: Power control, 3 args, no delay:
		0xA2, 0x02,					  //     -4.6V
		0x84,						  //     AUTO mode
		ST7735_PWCTR2, 1,			  //  8: Power control, 1 arg, no delay:
		0xC5,						  //     VGH25=2.4C VGSEL=-10 VGH=3 * AVDD
		ST7735_PWCTR3, 2,			  //  9: Power control, 2 args, no delay:
		0x0A,						  //     Opamp current small
		0x00,						  //     Boost frequency
		ST7735_PWCTR4, 2,			  // 10: Power control, 2 args, no delay:
		0x8A,						  //     BCLK/2,
		0x2A,						  //     opamp current small & medium low
		ST7735_PWCTR5, 2,			  // 11: Power control, 2 args, no delay:
		0x8A, 0xEE, ST7735_VMCTR1, 1, // 12: Power control, 1 arg, no delay:
		0x0E, ST77XX_INVOFF, 0,		  // 13: Don't invert display, no args
		ST77XX_MADCTL, 1,			  // 14: Mem access ctl (directions), 1 arg:
		0xC8,						  //     row/col addr, bottom-top refresh
		ST77XX_COLMOD, 1,			  // 15: set color mode, 1 arg, no delay:
		0x05},						  //     16-bit color

	Rcmd2green[] = {		// 7735R init, part 2 (green tab only)
		2,					//  2 commands in list:
		ST77XX_CASET, 4,	//  1: Column addr set, 4 args, no delay:
		0x00, 0x02,			//     XSTART = 0
		0x00, 0x7F + 0x02,	//     XEND = 127
		ST77XX_RASET, 4,	//  2: Row addr set, 4 args, no delay:
		0x00, 0x01,			//     XSTART = 0
		0x00, 0x9F + 0x01}, //     XEND = 159

	Rcmd2red[] = {		 // 7735R init, part 2 (red tab only)
		2,				 //  2 commands in list:
		ST77XX_CASET, 4, //  1: Column addr set, 4 args, no delay:
		0x00, 0x00,		 //     XSTART = 0
		0x00, 0x7F,		 //     XEND = 127
		ST77XX_RASET, 4, //  2: Row addr set, 4 args, no delay:
		0x00, 0x00,		 //     XSTART = 0
		0x00, 0x9F},	 //     XEND = 159

	Rcmd2green144[] = {	 // 7735R init, part 2 (green 1.44 tab)
		2,				 //  2 commands in list:
		ST77XX_CASET, 4, //  1: Column addr set, 4 args, no delay:
		0x00, 0x00,		 //     XSTART = 0
		0x00, 0x7F,		 //     XEND = 127
		ST77XX_RASET, 4, //  2: Row addr set, 4 args, no delay:
		0x00, 0x00,		 //     XSTART = 0
		0x00, 0x7F},	 //     XEND = 127

	Rcmd2green160x80[] = { // 7735R init, part 2 (mini 160x80)
		2,				   //  2 commands in list:
		ST77XX_CASET, 4,   //  1: Column addr set, 4 args, no delay:
		0x00, 0x00,		   //     XSTART = 0
		0x00, 0x4F,		   //     XEND = 79
		ST77XX_RASET, 4,   //  2: Row addr set, 4 args, no delay:
		0x00, 0x00,		   //     XSTART = 0
		0x00, 0x9F},	   //     XEND = 159

	Rcmd3[] = {																		// 7735R init, part 3 (red or green tab)
		4,																			//  4 commands in list:
		ST7735_GMCTRP1, 16,															//  1: Gamma Adjustments (pos. polarity), 16 args + delay:
		0x02, 0x1c, 0x07, 0x12,														//     (Not entirely necessary, but provides
		0x37, 0x32, 0x29, 0x2d,														//      accurate colors)
		0x29, 0x25, 0x2B, 0x39, 0x00, 0x01, 0x03, 0x10, ST7735_GMCTRN1, 16,			//  2: Gamma Adjustments (neg. polarity), 16 args + delay:
		0x03, 0x1d, 0x07, 0x06,														//     (Not entirely necessary, but provides
		0x2E, 0x2C, 0x29, 0x2D,														//      accurate colors)
		0x2E, 0x2E, 0x37, 0x3F, 0x00, 0x00, 0x02, 0x10, ST77XX_NORON, ST_CMD_DELAY, //  3: Normal display on, no args, w/delay
		10,																			//     10 ms delay
		ST77XX_DISPON, ST_CMD_DELAY,												//  4: Main screen turn on, no args w/delay
		100};

/*Static function prototype ---------------------------------------*/
static void ST7735_Reset(void){
	GPIOX_ODR(RESET) = 1;
	LCD_Delay(20);
	GPIOX_ODR(RESET) = 0;
	LCD_Delay(5);
	GPIOX_ODR(RESET) = 1;
	return;
}

static void Send_Data8(uint8_t data){
    while(!(LCD_SPI->SR & SPI_SR_TXE));
	__IO uint8_t *spidr = ((__IO uint8_t *)&LCD_SPI->DR);
    *spidr = data;
	(void)LCD_SPI->DR;
    while(LCD_SPI->SR & SPI_SR_BSY);
	return;
}

static void ST7735_SendToTFT(uint8_t *Byte,uint32_t Length){
	ST7735_Select();
	for(uint16_t index = 0; index < Length; index++){
		Send_Data8(Byte[index]);
	}
	ST7735_DeSelect();
	return;
}
void Send_DMA_Data16(uint16_t* buff, uint16_t dataSize)// Basic function - write those for your MCU !!!!@@@@<#<@<#>#$@!s
{
    LCD_SPI->CR1 &=~ (SPI_CR1_SPE);
    LCD_SPI->CR1 |= SPI_CR1_DFF;                       //data with 16 bit

	ST7735_RegData();
	ST7735_Select();
    //stream configuration
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_EN;               //Se deshabilita el STREAM
    //direccion
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_DIR;
    //high priority
    DMAx_Streamy(LCD_DMA)->CR |= DMA_SxCR_DIR_0;               //mem to periph
    DMAx_Streamy(LCD_DMA)->CR |= DMA_SxCR_PL;                  //very high priority
    //normal mode
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_CIRC;
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_PFCTRL;
    //increment
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_PINC;
    DMAx_Streamy(LCD_DMA)->CR |= DMA_SxCR_MINC;
    //DATA SIZE
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_MSIZE;
    DMAx_Streamy(LCD_DMA)->CR &=~ DMA_SxCR_PSIZE;
    DMAx_Streamy(LCD_DMA)->CR |= DMA_SxCR_PSIZE_0 | DMA_SxCR_MSIZE_0;  //halfword

	//addres configuration
    DMAx_Streamy(LCD_DMA)->M0AR = (uint32_t)buff;
    DMAx_Streamy(LCD_DMA)->PAR = (uint32_t) &(LCD_SPI->DR);
	//tamaño de datos
    DMAx_Streamy(LCD_DMA)->NDTR = dataSize;
    //interrupcion para transmision complet
    DMAx_Streamy(LCD_DMA)->CR |= DMA_SxCR_TCIE;
    //se habilita la peticion de transmision del SPI
    LCD_SPI->CR2 |= SPI_CR2_TXDMAEN;
    //Se habilita el SPI
    LCD_SPI->CR1 |= SPI_CR1_SPE;
	//Se habilita el streeam
    DMAx_Streamy(LCD_DMA)->CR |= DMA_SxCR_EN;
	flag_DMA_Stream_bsy=1;

    return;
}

void DMA_TransmitComplete_Callback()   //Call from stm32f4xx_it.c
					//Basic function - write those for your MCU !!!!@@@@<#<@<#>#$@!s
{

	DMA_ST7735_SPI_TransmitComplete_Callback();  //file lv_driver.c
    LCD_SPI->CR1 &=~ SPI_CR1_DFF;
	ST7735_DeSelect();
#if(STREAM_NUMBER(LCD_DMA)>3)
    DMAx(LCD_DMA)->HIFCR |= STREAM_TC_H_MASK(LCD_DMA);
#else
    DMAx(LCD_DMA)->LIFCR |= STREAM_TC_L_MASK(LCD_DMA);
#endif
	flag_DMA_Stream_bsy=0;
}

static  void ST7735_SendData16(uint16_t Data)
{

	uint8_t tmp[2];
	tmp[0] = (Data>>8);
	tmp[1] = Data & 0xFF;
	ST7735_RegData();
	ST7735_SendToTFT(tmp, 2);

}
void ST7735_WriteCommand(uint8_t cmd){
	ST7735_RegCommand();
	ST7735_SendToTFT(&cmd, 1);
	return;
}

static void ST7735_WriteData(uint8_t *buff, uint32_t buff_size){
	ST7735_RegData();
	ST7735_SendToTFT(buff, buff_size);
	return;
}

void ST7735_SendCommand(uint8_t commandByte, uint8_t *dataBytes,
						uint8_t numDataBytes)
{
	ST7735_Select();

	ST7735_WriteCommand(commandByte);
	ST7735_WriteData(dataBytes, numDataBytes);

	ST7735_DeSelect();

	return;
}
void ST7735_displayInit(const uint8_t *addr)
{

	uint8_t numCommands, cmd, numArgs;
	uint16_t ms;

	numCommands = *(addr++); // Number of commands to follow
	while (numCommands--)
	{								 // For each command...
		cmd = *(addr++);			 // Read command
		numArgs = *(addr++);		 // Number of args to follow
		ms = numArgs & ST_CMD_DELAY; // If hibit set, delay follows args
		numArgs &= ~ST_CMD_DELAY;	 // Mask out delay bit
		ST7735_SendCommand(cmd, (uint8_t *)addr, numArgs);
		addr += numArgs;

		if (ms)
		{
			ms = *(addr++); // Read post-command delay time (ms)
			if (ms == 255)
				ms = 500; // If 255, delay for 500 ms
			LCD_Delay(ms);
		}
	}
}

void LCD_setRotation(uint8_t m)
{
	uint8_t madctl = 0;

	rotation = m & 3; // can't be higher than 3

	// For ST7735 with GREEN TAB (including //  HALloWing)...
	if ((tabcolor == INITR_144GREENTAB) || (tabcolor == INITR_HALLOWING))
	{
		// ..._rowstart is 3 for rotations 0&1, 1 for rotations 2&3
		_rowstart = (rotation < 2) ? 3 : 1;
	}

	switch (rotation)
	{
	case 0:
		if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80))
		{
			madctl = ST77XX_MADCTL_MX | ST77XX_MADCTL_MY | ST77XX_MADCTL_RGB;
		}
		else
		{
			madctl = ST77XX_MADCTL_MX | ST77XX_MADCTL_MY | ST7735_MADCTL_BGR;
		}

		if (tabcolor == INITR_144GREENTAB)
		{
			_height = ST7735_TFTHEIGHT_128;
			_width = ST7735_TFTWIDTH_128;
		}
		else if (tabcolor == INITR_MINI160x80)
		{
			_height = ST7735_TFTHEIGHT_160;
			_width = ST7735_TFTWIDTH_80;
		}
		else
		{
			_height = ST7735_TFTHEIGHT_160;
			_width = ST7735_TFTWIDTH_128;
		}
		_xstart = _colstart;
		_ystart = _rowstart;
		break;
	case 1:
		if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80))
		{
			madctl = ST77XX_MADCTL_MY | ST77XX_MADCTL_MV | ST77XX_MADCTL_RGB;
		}
		else
		{
			madctl = ST77XX_MADCTL_MY | ST77XX_MADCTL_MV | ST7735_MADCTL_BGR;
		}

		if (tabcolor == INITR_144GREENTAB)
		{
			_width = ST7735_TFTHEIGHT_128;
			_height = ST7735_TFTWIDTH_128;
		}
		else if (tabcolor == INITR_MINI160x80)
		{
			_width = ST7735_TFTHEIGHT_160;
			_height = ST7735_TFTWIDTH_80;
		}
		else
		{
			_width = ST7735_TFTHEIGHT_160;
			_height = ST7735_TFTWIDTH_128;
		}
		_ystart = _colstart;
		_xstart = _rowstart;
		break;
	case 2:
		if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80))
		{
			madctl = ST77XX_MADCTL_RGB;
		}
		else
		{
			madctl = ST7735_MADCTL_BGR;
		}

		if (tabcolor == INITR_144GREENTAB)
		{
			_height = ST7735_TFTHEIGHT_128;
			_width = ST7735_TFTWIDTH_128;
		}
		else if (tabcolor == INITR_MINI160x80)
		{
			_height = ST7735_TFTHEIGHT_160;
			_width = ST7735_TFTWIDTH_80;
		}
		else
		{
			_height = ST7735_TFTHEIGHT_160;
			_width = ST7735_TFTWIDTH_128;
		}
		_xstart = _colstart;
		_ystart = _rowstart;
		break;
	case 3:
		if ((tabcolor == INITR_BLACKTAB) || (tabcolor == INITR_MINI160x80))
		{
			madctl = ST77XX_MADCTL_MX | ST77XX_MADCTL_MV | ST77XX_MADCTL_RGB;
		}
		else
		{
			madctl = ST77XX_MADCTL_MX | ST77XX_MADCTL_MV | ST7735_MADCTL_BGR;
		}

		if (tabcolor == INITR_144GREENTAB)
		{
			_width = ST7735_TFTHEIGHT_128;
			_height = ST7735_TFTWIDTH_128;
		}
		else if (tabcolor == INITR_MINI160x80)
		{
			_width = ST7735_TFTHEIGHT_160;
			_height = ST7735_TFTWIDTH_80;
		}
		else
		{
			_width = ST7735_TFTHEIGHT_160;
			_height = ST7735_TFTWIDTH_128;
		}
		_ystart = _colstart;
		_xstart = _rowstart;
		break;
	}
	ST7735_SendCommand(ST77XX_MADCTL, &madctl, 1);
}

void LCD_initDisplay(uint8_t options)
{
    LCD_SPI->CR1 |= SPI_CR1_SPE;

	// windowWidth = width;
	// windowHeight = height;
	ST7735_Select();
	ST7735_Reset();
	ST7735_displayInit(Rcmd1);
	if (options == INITR_GREENTAB)
	{
		ST7735_displayInit(Rcmd2green);
		_colstart = 2;
		_rowstart = 1;
	}
	else if ((options == INITR_144GREENTAB) || (options == INITR_HALLOWING))
	{
		_height = ST7735_TFTHEIGHT_128;
		_width = ST7735_TFTWIDTH_128;
		ST7735_displayInit(Rcmd2green144);
		_colstart = 2;
		_rowstart = 3; // For default rotation 0
	}
	else if (options == INITR_MINI160x80)
	{
		_height = ST7735_TFTWIDTH_80;
		_width = ST7735_TFTHEIGHT_160;
		ST7735_displayInit(Rcmd2green160x80);
		_colstart = 24;
		_rowstart = 0;
	}
	else
	{
		// colstart, rowstart left at default '0' values
		ST7735_displayInit(Rcmd2red);
	}
	ST7735_displayInit(Rcmd3);

	// Black tab, change MADCTL color filter
	if ((options == INITR_BLACKTAB) || (options == INITR_MINI160x80))
	{
		uint8_t data = 0xC0;
		ST7735_SendCommand(ST77XX_MADCTL, &data, 1);
	}

	if (options == INITR_HALLOWING)
	{
		// //  HALlowing is simply a 1.44" green tab upside-down:
		tabcolor = INITR_144GREENTAB;
		LCD_setRotation(2);
	}
	else
	{
		tabcolor = options;
		LCD_setRotation(0);
	}

	// LCD_setRotation(2);
}
void ST7735_setAddrWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{

	x += _xstart;
	y += _ystart;

	uint32_t xa = ((uint32_t)x << 16) | (x + w - 1);
	uint32_t ya = ((uint32_t)y << 16) | (y + h - 1);

	xa = __builtin_bswap32(xa);
	ya = __builtin_bswap32(ya);

	ST7735_WriteCommand(ST77XX_CASET);
	ST7735_WriteData((uint8_t *)&xa, sizeof(xa));

	// row address set
	ST7735_WriteCommand(ST77XX_RASET);
	ST7735_WriteData((uint8_t *)&ya, sizeof(ya));

	// write to RAM
	ST7735_WriteCommand(ST77XX_RAMWR);
}

void LCD_WritePixel(int x, int y, uint16_t col)
{
	ST7735_Select();
	ST7735_setAddrWindow(x, y, 1, 1); // Clipped area
	ST7735_RegData();
	ST7735_SendData16( col);
	ST7735_DeSelect();
}
/*Function definition --------------------------------------*/

void LCD_WriteBitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
	ST7735_Select();
	ST7735_setAddrWindow(x, y, w, h); // Clipped area
	ST7735_RegData();
	Send_DMA_Data16(bitmap, w * h);

	ST7735_DeSelect();
}

