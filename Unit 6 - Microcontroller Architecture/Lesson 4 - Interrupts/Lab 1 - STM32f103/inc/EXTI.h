/*
 * EXTI.h
 *
 *  Created on: Dec 5, 2023
 *      Author: adham
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "Platform_Types.h"

/* External Interrupt*/
#define EXTI_BASE 		0x40010400
#define EXTI_IMR 		*( (volatile uint32*) (EXTI_BASE + 0x00) )	/* Interrupt mask register*/
#define EXTI_EMR 		*( (volatile uint32*) (EXTI_BASE + 0x04) )	/* Event mask register */
#define EXTI_RTSR 		*( (volatile uint32*) (EXTI_BASE + 0x08) )  /* Rising trigger selection register */
#define EXTI_FTSR 		*( (volatile uint32*) (EXTI_BASE + 0x0C) )  /* Falling trigger selection register */
#define EXTI_SWIER 		*( (volatile uint32*) (EXTI_BASE + 0x10) )  /* Software interrupt event register */
#define EXTI_PR 		*( (volatile uint32*) (EXTI_BASE + 0x14) )  /* Pending register */

/*Alternate function I/O */
#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1 	*( (volatile uint32*) (AFIO_BASE + 0x08) )  /* External interrupt configuration register 1 */

/*  Nested vectored interrupt controller*/
#define NVIC_BASE		0xE000E100
#define NVIC_ISER0 		*( (volatile uint32*) (NVIC_BASE + 0x00) )  /* Interrupt set-enable registers */

void EXRI0_Init(void);


#endif /* EXTI_H_ */
