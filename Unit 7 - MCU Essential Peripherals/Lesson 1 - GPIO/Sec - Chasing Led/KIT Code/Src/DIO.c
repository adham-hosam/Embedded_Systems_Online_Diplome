/*
 * DIO.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#include "DIO.h"
#include "BIT_MATH.h"

void DIO_Init(void){

	// Configure Port D Pin 0 as input with pull-down resistor
	DDRD = 0b11110000;
	PORTD = 0x0;

	SET_BIT(DDRD , PIN4);
	SET_BIT(DDRD , PIN5);
	SET_BIT(DDRD , PIN6);
	SET_BIT(DDRD , PIN7);

}

