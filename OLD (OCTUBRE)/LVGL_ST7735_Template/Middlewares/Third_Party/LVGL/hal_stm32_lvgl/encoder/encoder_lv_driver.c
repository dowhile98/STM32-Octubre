/**
 * @file encoder_lv_driver.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "encoder_lv_driver.h"

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void encoder_io_init(void);
/**********************
 *      MACROS
 **********************/
#define SYSCFG_EXTI_SET1_(a, b) SYSCFG_EXTICR1_EXTI ## b ## _P ## a
#define SYSCFG_EXTI_SET1(a)     SYSCFG_EXTI_SET1_(a)
#define SYSCFG_EXTI_SET2_(a, b) SYSCFG_EXTICR2_EXTI ## b ## _P ## a
#define SYSCFG_EXTI_SET2(a)     SYSCFG_EXTI_SET2_(a)
#define SYSCFG_EXTI_SET3_(a, b) SYSCFG_EXTICR3_EXTI ## b ## _P ## a
#define SYSCFG_EXTI_SET3(a)     SYSCFG_EXTI_SET3_(a)
#define SYSCFG_EXTI_SET4_(a, b) SYSCFG_EXTICR4_EXTI ## b ## _P ## a
#define SYSCFG_EXTI_SET4(a)     SYSCFG_EXTI_SET4_(a)
#define EXTI_IRQ_Number_(a, b)  EXTI ## b ## _IRQn
#define EXTI_IRQ_Number(a)      EXTI_IRQ_Number_(a)
/**********************
 *  STATIC VARIABLES
 **********************/
volatile int32_t encoder_value;
bool encoder_btn_flag = false;
bool user_btn_flag = false;
lv_indev_t * indev_encoder;
static int32_t encoder_last_value;

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_port_indev_init(lv_group_t *g){
	static lv_indev_drv_t indev_drv;
	/*------------------
	 * Encoder
	 * -----------------*/

	/*Initialize your encoder if you have*/
	encoder_io_init();
	/*Register a encoder input device*/
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_ENCODER;
	indev_drv.read_cb = encoder_read;
	indev_encoder = lv_indev_drv_register(&indev_drv);

	/*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
	 *add objects to the group with `lv_group_add_obj(group, obj)`
	 *and assign this input device to group to navigate in it:
	 *`lv_indev_set_group(indev_encoder, group);`*/
	lv_indev_t *enc_indev = lv_indev_drv_register(&indev_drv);
	lv_indev_set_group(enc_indev, g);
	return;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static bool is_encoder_button_pressed(void)
{
    bool flag = encoder_btn_flag;
    encoder_btn_flag = false;
    return flag;
}
/*------------------
 * Encoder
 * -----------------*/

/*Initialize your keypad*/
static void encoder_io_init(void)
{
    //ENABLE CLOCK
    RCC->AHB1ENR |= GPIOX_CLOCK(ENCODER_BUTTON_PIN)  | GPIOX_CLOCK(ENCODER_IT1) | GPIOX_CLOCK(ENCODER_IT2);
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    ENCODER_TIM_CLOCK_EN();
    //BUTTON INIT
    GPIOX_MODER(MODE_DIGITAL_INPUT, BUTTON);
    GPIOX_PUPDR(MODE_PU_UP, ENCODER_BUTTON_PIN);
    EXTI->IMR |= 1U<<GPIOX_PIN(ENCODER_BUTTON_PIN);
    EXTI->PR |= 1U<<GPIOX_PIN(ENCODER_BUTTON_PIN);
    EXTI->FTSR |= 1U<<GPIOX_PIN(ENCODER_BUTTON_PIN);
#if(GPIOX_PIN(ENCODER_BUTTON_PIN)<4)
    SYSCFG->EXTICR[0] =~ (0xF)<<(GPIOX_PIN(ENCODER_BUTTON_PIN) * 4);
    SYSCFG->EXTICR[0] |= SYSCFG_EXTI_SET1(ENCODER_BUTTON_PIN);
#elif (GPIOX_PIN(ENCODER_BUTTON_PIN)<8)
    SYSCFG->EXTICR[1] =~ (0xF)<<(GPIOX_PIN(ENCODER_BUTTON_PIN) * 4);
    SYSCFG->EXTICR[1] |= SYSCFG_EXTI_SET2(ENCODER_BUTTON_PIN);
#elif (GPIOX_PIN(ENCODER_BUTTON_PIN)<12)
    SYSCFG->EXTICR[2] =~ (0xF)<<(GPIOX_PIN(ENCODER_BUTTON_PIN) * 4);
    SYSCFG->EXTICR[2] |= SYSCFG_EXTI_SET3(ENCODER_BUTTON_PIN);
#else
    SYSCFG->EXTICR[3] =~ (0xF)<<(GPIOX_PIN(ENCODER_BUTTON_PIN) * 4);
    SYSCFG->EXTICR[3] |= SYSCFG_EXTI_SET4(ENCODER_BUTTON_PIN);
#endif

#if(GPIOX_PIN(ENCODER_BUTTON_PIN) < 5)
    NVIC_EnableIRQ(EXTI_IRQ_Number(ENCODER_BUTTON_PIN));
#elif (GPIOX_PIN(ENCODER_BUTTON_PIN) < 10)
    NVIC_EnableIRQ(EXTI9_5_IRQn);
#else
    NVIC_EnableIRQ(EXTI15_10_IRQn);
#endif
	/*configuracion de pines para el timer2*/
	GPIOX_MODER(MODE_ALTER, ENCODER_IT1);
	GPIOX_MODER(MODE_ALTER, ENCODER_IT2 );
	GPIOX_AFR(ALTER_FUNCTION, ENCODER_IT1);
	GPIOX_AFR(ALTER_FUNCTION, ENCODER_IT2 );
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, ENCODER_IT1);		//Very high speed
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, ENCODER_IT2 );
	//configuracion del timer
	ENCODER_TIM->CR1 = 0;
	ENCODER_TIM->ARR = 0xFFFFFFFFU;
	ENCODER_TIM->PSC = 0;
	//configuracion del canal o los modos captura y comparacion
	//Los canales como entrada
	ENCODER_TIM->CCMR1 = TIM_CCMR1_CC1S_0;					//TI1FP1 mapped on TI1 (PA5)
	ENCODER_TIM->CCMR1 |= TIM_CCMR1_CC2S_0;				//TI1FP2 mapped on TI2 (PA1)
	ENCODER_TIM->CCMR1 |= TIM_CCMR1_IC1PSC | TIM_CCMR1_IC2PSC;
	//configurar la polaridad
	ENCODER_TIM->CCER = 0;
	/*external clock mode 1*/
	//MODO ENCODER
	ENCODER_TIM->SMCR |= TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0;	//Encoder mode 3

	//habilitar el conteo
	ENCODER_TIM->CR1 |= TIM_CR1_CEN;
    /*Your code comes here*/
	//todo

}
/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

	if (is_encoder_button_pressed()) {
        data->state = LV_INDEV_STATE_PR;

	} else {
        data->state = LV_INDEV_STATE_REL;
	}
	encoder_value = ENCODER_TIM->CNT;
	data->enc_diff = encoder_value - encoder_last_value;
	if(data->enc_diff>0){
		data->enc_diff = 1;
		data->key = LV_KEY_RIGHT;
	}else if(data->enc_diff<0){
		data->key = LV_KEY_LEFT;
		data->enc_diff = -1;
	}
	encoder_last_value = encoder_value;
    return;
}



void encoder_button_callback(uint16_t GPIO_Pin)
{
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = GetTick();

    if (GPIO_Pin == GPIOX_PIN(ENCODER_BUTTON_PIN)) {
        if (interrupt_time - last_interrupt_time > ENCODER_DEBOUNCE_TIME) {
            encoder_btn_flag = true;
        }
    }
    last_interrupt_time = interrupt_time;
}
