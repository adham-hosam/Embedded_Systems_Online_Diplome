/*
 * DIO.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#include "DIO.h"
#include "BIT_MATH.h"

void DIO_Init(void){

	DDRD = 0b11110000;
	PORTD =0xff;

	DDRA = 0xff;
	DDRB = 0xff;
}

