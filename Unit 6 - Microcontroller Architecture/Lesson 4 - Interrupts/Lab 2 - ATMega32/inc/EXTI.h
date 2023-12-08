/*
 * EXTI.h
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "Platform_Types.h"

#define SREG 			*( (volatile uint8*) (0x5F) )	/* Status Register */
#define SREG_I			7	/* Global Interrupt Enable */

#define MCUCSR 			*( (volatile uint8*) (0x54) )	/* MCU Control and Status Register */
#define MCUCSR_ISC2		6	/* Interrupt Sense Control 2 */

#define MCUCR 	*( (volatile uint8*) (0x55) )	/* MCU Control Register */

#define MCUCR_ISC00	0	// Interrupt Sense Control 0 Bit 1 and Bit 0
#define MCUCR_ISC01	1
#define MCUCR_ISC10	2	// Interrupt Sense Control 1 Bit 1 and Bit 0
#define MCUCR_ISC11	3

#define GICR 		*( (volatile uint8*) (0x5B) )	/* General Interrupt Control Register*/
#define GICR_INT2	5	// External Interrupt Request 2 Enable
#define GICR_INT0	6	// External Interrupt Request 0 Enable
#define GICR_INT1	7	// External Interrupt Request 1 Enable

void EXTI_Init(void);

/*Function which will writen in main will be called by this fuction*/
void EXTI_Int0SetCallBack(void (*Copy_pvInt0Func)(void));
void EXTI_Int1SetCallBack(void (*Copy_pvInt1Func)(void));
void EXTI_Int2SetCallBack(void (*Copy_pvInt2Func)(void));



#endif /* EXTI_H_ */
