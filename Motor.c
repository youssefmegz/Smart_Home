/*
 * Motor.c
 *
 *  Created on: Oct 5, 2024
 *      Author: asus
 */


#include "Motor.h"
#include "lm35_sensor.h"
#include "common_macros.h"
#include "gpio.h"
#include "PWM.h"

void DcMotor_Init(void)
{

	GPIO_setupPinDirection(MOTOR_IN1_PORT,MOTOR_IN1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT,MOTOR_IN2_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_EN_PORT,MOTOR_EN_PIN,PIN_OUTPUT);


	GPIO_writePin(MOTOR_IN1_PORT,MOTOR_IN1_PIN,LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT,MOTOR_IN2_PIN,LOGIC_LOW);
}



void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{



	switch (state)
	{

	case CW: 		GPIO_writePin(MOTOR_IN1_PORT,MOTOR_IN1_PIN,LOGIC_HIGH);
					GPIO_writePin(MOTOR_IN2_PORT,MOTOR_IN2_PIN,LOGIC_LOW);
				break;

	case A_CW: 		GPIO_writePin(MOTOR_IN1_PORT,MOTOR_IN1_PIN,LOGIC_LOW);
					GPIO_writePin(MOTOR_IN2_PORT,MOTOR_IN2_PIN,LOGIC_HIGH);
				break;

	case Stop:	GPIO_writePin(MOTOR_IN1_PORT,MOTOR_IN1_PIN,LOGIC_LOW);
				GPIO_writePin(MOTOR_IN2_PORT,MOTOR_IN2_PIN,LOGIC_LOW);;
				break;

	}

	PWM_Timer0_Start(speed);

}
