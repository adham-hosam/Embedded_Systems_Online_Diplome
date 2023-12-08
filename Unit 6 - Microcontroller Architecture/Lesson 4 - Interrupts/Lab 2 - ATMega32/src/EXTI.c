
/*
 * EXTI.c
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#include "EXTI.h"

/*Global Pointer to function to hold INT ISR address*/
void (*EXTI_pvInt0Func)(void) = NULL;
void (*EXTI_pvInt1Func)(void) = NULL;
void (*EXTI_pvInt2Func)(void) = NULL;

void EXTI_Init(void){


	// Configure external interrupt 0 (INT0) to trigger on a logical change.
	MCUCR |= (1 << MCUCR_ISC00);
	MCUCR &= ~(1 << MCUCR_ISC01);

	// Configure external interrupt 1 (INT1) to trigger on a falling edge
	MCUCR |= (1 << MCUCR_ISC10);
	MCUCR |= (1 << MCUCR_ISC11);

	// Configure external interrupt 2 (INT2) on the rising edge
	MCUCSR &= ~(1<<MCUCSR_ISC2);

	// Enable external interrupts INT0, INT1, and INT2
	GICR |= 1<<GICR_INT0;
	GICR |= 1<<GICR_INT1;
	GICR |= 1<<GICR_INT2;

	// Enable global interrupt
	SREG |= 1<<SREG_I;
}

void EXTI_Int0SetCallBack(void (*Copy_pvInt0Func)(void)){

	if( Copy_pvInt0Func != NULL){

		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else{
		/*Fn not found*/
	}
}


void EXTI_Int1SetCallBack(void (*Copy_pvInt1Func)(void)){

	if(Copy_pvInt1Func != NULL){
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else{
		/*Fn not found*/
	}
}
void EXTI_Int2SetCallBack(void (*Copy_pvInt2Func)(void)){

	if(Copy_pvInt2Func != NULL){
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else{
		/* Fn not found */
	}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){

	if(EXTI_pvInt0Func != NULL){
		EXTI_pvInt0Func();
	}
	else {
		/* Do nothing*/
	}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){

	if(EXTI_pvInt1Func != NULL){
		EXTI_pvInt1Func();
	}
	else {
		/* Do nothing*/
	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	if(EXTI_pvInt2Func != NULL){
		EXTI_pvInt2Func();
	}
	else{
		/* Do nothing */
	}
}

