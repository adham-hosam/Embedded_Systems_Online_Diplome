/*
 * EXTI.c
 *
 *  Created on: Dec 5, 2023
 *      Author: adham
 */

#include "EXTI.h"

void EXRI0_Init(void){

	// EXTI0 configuration for PORTA pin 0
	AFIO_EXTICR1 = 0;

	// Configure (Enable) the mask bits0
	EXTI_IMR |= (1<<0);

	// Rising trigger event configuration bit0
	EXTI_RTSR |= (1<<0);

	/* Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
	External Interrupt Controller (EXTI) so that an interrupt coming from line0 can be correctly acknowledged.*/
	NVIC_ISER0 |= (1<<6);

}




