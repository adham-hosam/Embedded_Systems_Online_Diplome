/*
 * DIO.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#include "DIO.h"

void DIO_Init(void){

	// Configure PortD for interrupt pins (PD2 & PD3) and output pins for led (PD5 , PD6 & PD7)
	DDRD  = 0b11100000;
	//pull-up activation
	PORTD = 0b00011111;	// Led initially off

	// Configure pin PB2 (INT2) for external interrupt
	DDRB = 0x0;
	//pull-up activation
	PORTB |= (1<<2);
}

void LED_Status(Led_Status led, uint8 pin){
	switch(led){

	case LED_OFF:
		PORTD &= ~(1<<pin);	break;

	case LED_ON:
		PORTD |= (1<<pin); break;

	case LED_TOGGLE:
		PORTD ^= (1<<pin);	break;

	default:
		break;
	}
}
