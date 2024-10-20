 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.c
 *
 * Description: Source file for LED
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#include "LED.h"
#include "gpio.h"



void LEDS_init(void)
{

	GPIO_setupPinDirection(LED_RED_PORT,LED_RED_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT,LED_GREEN_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT,LED_BLUE_PIN,PIN_OUTPUT);

#if (POSITIVE_LOGIC)
	GPIO_writePin(LED_RED_PORT,LED_RED_PIN,LOGIC_LOW);
	GPIO_writePin(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_LOW);
	GPIO_writePin(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_LOW);

#elif
	GPIO_writePin(LED_RED_PORT,LED_RED_PIN,LOGIC_HIGH);
	GPIO_writePin(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_HIGH);
	GPIO_writePin(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_HIGH);
#endif

}



void LED_on(LED_ID id)
{


#if (POSITIVE_LOGIC)
	switch(id)
	{
	case LED_RED : 	GPIO_writePin(LED_RED_PORT,LED_RED_PIN,LOGIC_HIGH);
					break;

	case LED_GREEN: GPIO_writePin(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_HIGH);
					break;

	case LED_BLUE: GPIO_writePin(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_HIGH);
					break;
	}

#else
	switch(id)
	{
	case LED_RED : 	GPIO_writePin(LED_RED_PORT,LED_RED_PIN,LOGIC_LOW);
					break;

	case LED_GREEN: GPIO_writePin(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_LOW);
					break;

	case LED_BLUE: GPIO_writePin(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_LOW);
					break;
	}
#endif

}


void LED_off(LED_ID id)
{

#if POSITIVE_LOGIC
	switch(id)
	{
	case LED_RED : 	GPIO_writePin(LED_RED_PORT,LED_RED_PIN,LOGIC_LOW);
					break;

	case LED_GREEN: GPIO_writePin(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_LOW);
					break;

	case LED_BLUE: GPIO_writePin(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_LOW);
					break;
	}

#else

	switch(id)
	{
	case LED_RED : 	GPIO_writePin(LED_RED_PORT,LED_RED_PIN,LOGIC_HIGH);
					break;

	case LED_GREEN: GPIO_writePin(LED_GREEN_PORT,LED_GREEN_PIN,LOGIC_HIGH);
					break;

	case LED_BLUE: GPIO_writePin(LED_BLUE_PORT,LED_BLUE_PIN,LOGIC_HIGH);
					break;
	}

#endif

}
