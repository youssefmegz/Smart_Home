 /******************************************************************************
 *
 * Module: Timer0_PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file for the ATmega32 PWM driver
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/


#include "PWM.h"
#include "avr/io.h"
#include "gpio.h"


void PWM_Timer0_Start(uint8 duty_cycle)
{
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	TCNT0= 0;
	OCR0=(duty_cycle)*MAX_PWM_COUNT;
	TCCR0|= (1<<WGM00) | (1<<WGM01) | (1<<CS00) | (1<<CS02)| (1<<COM01);
}
