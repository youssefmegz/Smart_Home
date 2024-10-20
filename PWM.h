 /******************************************************************************
 *
 * Module: Timer0_PWM
 *
 * File Name: PWM.h
 *
 * Description: Source file for the ATmega32 PWM driver
 *
 * Author: Youssef Maged Tadros
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"


#define MAX_PWM_COUNT		2.55;		//divided by 100 to get the %




void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* PWM_H_ */
