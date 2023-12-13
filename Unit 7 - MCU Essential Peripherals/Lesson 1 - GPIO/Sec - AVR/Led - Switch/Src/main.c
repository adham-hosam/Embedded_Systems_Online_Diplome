/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */
#include "Platform_Types.h"
#include "util/delay.h"


#include "DIO.h"

#include "Led.h"

int main(){

	DIO_Init();
	int Pin = PIN0;

	while(1)
	{
		if(Pin <= PIN7){

			if(GET_BIT( PINB , PIN0) == LOW)
			{
				LED_Status(LED_ON , &PORTA , Pin);
				while(GET_BIT( PINB , PIN0) == LOW);
				Pin++;
			}
		}
		if( Pin > PIN7){
			while(Pin >0){
				if(GET_BIT( PINB , PIN0) == LOW)
				{
					LED_Status(LED_OFF , &PORTA , --Pin);
					while(GET_BIT( PINB , PIN0) == LOW);
				}
			}

		}

	}
}
