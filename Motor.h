/*
 * Motor.h
 *
 *  Created on: Oct 5, 2024
 *      Author: asus
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "gpio.h"


#define MOTOR_IN1_PORT			PORTB_ID
#define MOTOR_IN2_PORT			PORTB_ID
#define MOTOR_EN_PORT			PORTB_ID
#define MOTOR_IN1_PIN			PIN0_ID
#define MOTOR_IN2_PIN			PIN1_ID
#define MOTOR_EN_PIN			PIN3_ID


typedef enum {
	CW,A_CW,Stop
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
