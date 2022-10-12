/******************************************************************************
 *
 * Main Function
 *
 * File Name: main.c
 *
 * Description: Interfacing with ultrasonic/lcd
 *
 * Author: Ahmed Hany
 *
 *******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "HAL/LCD/lcd.h"
#include "HAL/Ultrasonic/ultrasonic.h"

int main(void){
	uint16 dist;
	SREG |= (1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance =    cm");

	while(1){
		_delay_ms(5);
		LCD_moveCursor(0, 11);
		dist =Ultrasonic_readDistance();
		if(dist<100){
			LCD_intgerToString(dist);
			LCD_displayCharacter(' ');
		}
		else{
			LCD_intgerToString(dist);
		}
	}
	return 0;
}
