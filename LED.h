 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: header file for LED
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "gpio.h"

#define POSITIVE_LOGIC		1
#define LED_RED_PORT		PORTB_ID
#define LED_GREEN_PORT		PORTB_ID
#define LED_BLUE_PORT		PORTB_ID
#define LED_RED_PIN			PIN5_ID
#define LED_GREEN_PIN		PIN6_ID
#define LED_BLUE_PIN		PIN7_ID



typedef enum
{
	LED_RED,LED_GREEN,LED_BLUE
}LED_ID;



void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);







#endif /* LED_H_ */
