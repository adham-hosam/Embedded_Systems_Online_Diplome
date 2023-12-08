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

#define DDRB 	*( (volatile uint8*) (0x37) )
#define PORTB 	*( (volatile uint8*) (0x38) )

#define DDRD 	*( (volatile uint8*) (0x31) )
#define PORTD 	*( (volatile uint8*) (0x32) )

typedef enum{
	LED_OFF,
	LED_ON,
	LED_TOGGLE
}Led_Status;

void DIO_Init(void);

void LED_Status(Led_Status led , uint8 pin);


#endif /* DIO_H_ */
