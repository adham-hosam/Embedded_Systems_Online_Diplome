/*
 * Led.h
 *
 *  Created on: Dec 12, 2023
 *      Author: adham
 */

#ifndef LED_H_
#define LED_H_

#include "Platform_Types.h"
#include "BIT_MATH.h"

typedef enum{
	LED_OFF,
	LED_ON,
	LED_TOGGLE
}Led_Status;



void LED_Status(Led_Status led, volatile uint8 *port, uint8 pin);
void Buzzer(Led_Status led, volatile uint8 *port, uint8 pin);


#endif /* LED_H_ */
