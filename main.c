 /******************************************************************************
 *
 * Module: Smart Home
 *
 * File Name: main.c
 *
 * Description: source file for main
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#include "stdio.h"
#include "adc.h"
#include "BUZZER.h"
#include "Flame.h"
#include "lcd.h"
#include "LDR.h"
#include "LED.h"
#include "lm35_sensor.h"
#include "Motor.h"
#include "PWM.h"
#include "avr/io.h"
/*******************************************************************************/


int main(void)
{
/*Initializations*/
	LCD_init();
	ADC_init();
	Buzzer_init();
	FlameSensor_init();
	LEDS_init();
	DcMotor_Init();

/*Global Variables*/
	uint8 clr_screen_flag=1;		/*to clear the screen based on it*/


	while(1)
	{

		/* LCD */
/*Block to display :  FAN is off/FAN is on */
/*					  TEMP=  C		LDR=   %*/
		if(FlameSensor_getValue()==0)
		{
		LCD_displayStringRowColumn(1,0,"TEMP=");
		LCD_moveCursor(1,5);
		if(LM35_getTemperature()<100)
		{
		LCD_intgerToString(LM35_getTemperature());
		LCD_displayCharacter(' ');
		}
		else
		LCD_intgerToString(LM35_getTemperature());

		LCD_displayStringRowColumn(1,8,"LDR=");
		LCD_moveCursor(1,12);
		if(LDR_getLightIntensity()<100)
		{
		LCD_intgerToString(LDR_getLightIntensity());
		LCD_displayCharacter(' ');
		}
		else
		LCD_intgerToString(LDR_getLightIntensity());

		LCD_moveCursor(1,15);
		LCD_displayCharacter('%');

		if(LM35_getTemperature()<25)
			LCD_displayStringRowColumn(0,0,"    FAN IS OFF  ");
		else
			LCD_displayStringRowColumn(0,0,"    FAN IS ON   ");
		}


/*TEMPERATURE*/
/*control the dc motor based on temperature sensor */
if(LM35_getTemperature()<25)
{
	DcMotor_Rotate(Stop,0);
}
else if((LM35_getTemperature()>=25)&& (LM35_getTemperature()<30))
{
	DcMotor_Rotate(CW,25);
}
else if((LM35_getTemperature()>=30)&& (LM35_getTemperature()<35))
{
	DcMotor_Rotate(CW,50);
}
else if((LM35_getTemperature()>=35)&& (LM35_getTemperature()<40))
{
	DcMotor_Rotate(CW,75);
}
else if((LM35_getTemperature()>=40))
{
	DcMotor_Rotate(CW,100);
}



/*ALERT*/
/*Alert with sound when fire is detected*/
if(FlameSensor_getValue()==1)
{
	if(clr_screen_flag==1)
	{
		LCD_clearScreen();
		Buzzer_on();
		clr_screen_flag=0;
	}

	LCD_displayStringRowColumn(0,0,"Critical alert!");

}
	else
	{
			Buzzer_off();
			clr_screen_flag=1;
	}



/*LIGHT*/
/*Control LEDs based on Light Intensity Sensor*/
	if(LDR_getLightIntensity()<15)
	{
		LED_on(LED_RED);
		LED_on(LED_GREEN);
		LED_on(LED_BLUE);
	}
	else if( (LDR_getLightIntensity()>15) && (LDR_getLightIntensity()<=50) )
	{
		LED_on(LED_RED);
		LED_on(LED_GREEN);
		LED_off(LED_BLUE);
	}
	else if((LDR_getLightIntensity()>50) && (LDR_getLightIntensity()<=70))
	{
		LED_on(LED_RED);
		LED_off(LED_GREEN);
		LED_off(LED_BLUE);
	}
	else
	{
		LED_off(LED_RED);
		LED_off(LED_GREEN);
		LED_off(LED_BLUE);
	}

	}

	return 0;
}
