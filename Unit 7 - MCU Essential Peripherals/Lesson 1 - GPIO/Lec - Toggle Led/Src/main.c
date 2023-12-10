/*
 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: adham
 */



#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "RCC.h"
#include "GPIO.h"

void Busy_Wait(uint32 sec);

int main(){

	RCC_Init();
	GPIO_Init();



	while(1){
		if( ( GPIO_GetPinValue(PORTA, PIN1) ) == 0){

			LED_Status(LED_TOGGLE, PORTB, PIN1);
			while(( ( GPIO_GetPinValue(PORTA, PIN1) ) == 0));
		}

		if( (GPIO_GetPinValue(PORTA, PIN13) ) == 1 ){
			LED_Status(LED_TOGGLE, PORTB, PIN13);
		}
		Busy_Wait(1);

	}

}


void Busy_Wait(uint32 sec){
	uint32 i , j;
	for(i = 0 ; i < sec ; i++)
		for(j = 0 ; j<220 ; j++);
}
