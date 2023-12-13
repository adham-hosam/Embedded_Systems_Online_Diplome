/*
 * DIO.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#include "DIO.h"
#include "BIT_MATH.h"

void DIO_Init(void){

	// Configure PortA as output
	DDRA = 0xff;

	// Configure PB0 as input pull-up
	CLR_BIT(DDRB , PIN0);
	SET_BIT(PORTB , PIN0);
}

