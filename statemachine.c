/**
 * @file statemachine.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef enum{
    LED_OFF = 0,
    LED_ON,
    LED_WAIT
}LED_State_t;


typedef struct 
{
    LED_State_t state;
    uint8_t ledvalue     : 1;
}LED_t;

LED_t led;
int main(void){
    led.state = LED_OFF;
    led.ledvalue = 0;
    for(uint8_t i = 0; i<10; i++){
    switch (led.state)
    {
        case LED_OFF:
            printf("1-->LED OFF\r\n");
            led.ledvalue = 0;
            led.state = LED_WAIT;
            break;

        case LED_WAIT:
            printf("2-->LED WAIT\r\n");
            if(led.ledvalue == 0)
                led.state = LED_ON;
            else
                led.state = LED_OFF;
            break;

        case LED_ON:
            printf("3-->LED ON\r\n");
            led.state = LED_WAIT;
            led.ledvalue = 1;
            break;
    }
    }
    system("PAUSE");
    return 0;
}