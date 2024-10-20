 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: Flame.h
 *
 * Description: header file for LED
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"
#include  "gpio.h"

#define FLAME_SENSOR_PORT		PORTD_ID
#define FLAME_SENSOR_PIN		PIN2_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);




#endif /* FLAME_H_ */
