 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "adc.h"
#include "gpio.h"
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint16 LM35_getTemperature(void)
{
	//GPIO_setupPinDirection(PORTA_ID,PIN1_ID,PIN_INPUT);

	uint16 temp_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	g_adcResult=ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the from the ADC value*/
	temp_value = (uint16)(((uint32)g_adcResult*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return (temp_value);
}

