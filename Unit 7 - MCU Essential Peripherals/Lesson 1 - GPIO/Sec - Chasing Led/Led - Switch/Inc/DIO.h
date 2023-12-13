/*
 * DIO.h
 *
 *  Created on: Dec 8, 2023
 *      Author: adham
 */

#ifndef DIO_H_
#define DIO_H_

#include "Platform_Types.h"

#define DDRA 	*( (volatile uint8*) (0x3A) )
#define PORTA 	*( (volatile uint8*) (0x3B) )
#define PINA 	*( (volatile uint8*) (0x39) )

#define DDRB 	*( (volatile uint8*) (0x37) )
#define PORTB 	*( (volatile uint8*) (0x38) )
#define PINB 	*( (volatile uint8*) (0x36) )

#define DDRD 	*( (volatile uint8*) (0x31) )
#define PORTD 	*( (volatile uint8*) (0x32) )
#define DDRD 	*( (volatile uint8*) (0x30) )


/* Port Configurations */
#define PORTA_	0
#define PORTB_	1
#define PORTC_	2

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7






void DIO_Init(void);



#endif /* DIO_H_ */
