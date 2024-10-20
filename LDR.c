 /******************************************************************************
 *
 * Module: Light Intensity Sensor
 *
 * File Name: LDR.c
 *
 * Description: source file for the Light Intensity Sensor
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#include "LDR.h"
#include  "adc.h"


uint16 LDR_getLightIntensity(void)
{

	uint16 intensity_value = 0;

	/* Read ADC channel where the intensity sensor is connected */
	g_adcResult=ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the intensity from the ADC value*/
	intensity_value = (uint16)(((uint32)g_adcResult*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return (intensity_value);


}
