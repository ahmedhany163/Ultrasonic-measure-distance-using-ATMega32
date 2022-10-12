/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the AVR Ultrasonic driver
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/
#include <util/delay.h>
#include "ultrasonic.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/ICU/icu.h"

static uint16 distance;
static uint16 time;

void Ultrasonic_init(void){
	Icu_ConfigType Config = {F_CPU_8, RISING};
	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(ECHO_PORT, ECHO_PIN, PIN_INPUT);
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);
	Icu_init(&Config);
	Icu_setCallBack(&Ultrasonic_edgeProcessing);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_HIGH);
	_delay_us(15);
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	Icu_setEdgeDetectionType(RISING);
	distance = (time*0.01715);
	return (distance +1);
}

void Ultrasonic_edgeProcessing(void){
	time = Icu_getInputCaptureValue();
	Icu_clearTimerValue();
	Icu_setEdgeDetectionType(FALLING);
}
