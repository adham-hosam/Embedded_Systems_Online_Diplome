/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#include "DIO.h"
#include "EXTI.h"

#include "util/delay.h"

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

int main(){

	DIO_Init();
	EXTI_Init();

	EXTI_Int0SetCallBack(&INT0_ISR);
	EXTI_Int1SetCallBack(&INT1_ISR);
	EXTI_Int2SetCallBack(&INT2_ISR);


	while(1){

	}
}

void INT0_ISR(){
	PORTD |= (1<<5);
	_delay_ms(10000);
	PORTD &= ~(1<<5);
}

void INT1_ISR(){

	PORTD |= (1<<6);
	_delay_ms(10000);
	PORTD &= ~(1<<6);
}

void INT2_ISR(void){

	PORTD |= (1<<7);
	_delay_ms(10000);
	PORTD &= ~(1<<7);
}

