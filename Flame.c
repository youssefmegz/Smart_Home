 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: Flame.c
 *
 * Description: Source file for LED
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#include "Flame.h"
#include "gpio.h"
#include "common_macros.h"


void FlameSensor_init(void)
{

	GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_INPUT);

}



uint8 FlameSensor_getValue(void)
{

uint8 flame_read = GPIO_readPin(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);

return flame_read;

}
