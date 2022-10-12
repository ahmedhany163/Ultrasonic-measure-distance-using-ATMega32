 /******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the AVR Ultrasonic driver
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/
#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_
#include "../../MCAL/std_types.h"

#define TRIGGER_PORT 	PORTB_ID
#define TRIGGER_PIN 	PIN5_ID
#define ECHO_PORT		PORTD_ID
#define ECHO_PIN		PIN6_ID

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);



#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
