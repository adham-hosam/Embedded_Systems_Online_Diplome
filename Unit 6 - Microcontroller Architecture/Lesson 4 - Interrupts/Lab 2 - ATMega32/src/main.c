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
	LED_Status(LED_ON , 5);
	_delay_ms(10000);
	LED_Status(LED_OFF , 5);
}

void INT1_ISR(){

	LED_Status(LED_ON , 6);
	_delay_ms(10000);
	LED_Status(LED_OFF , 6);
}

void INT2_ISR(void){

	LED_Status(LED_ON , 7);
	_delay_ms(10000);
	LED_Status(LED_OFF , 7);
}

