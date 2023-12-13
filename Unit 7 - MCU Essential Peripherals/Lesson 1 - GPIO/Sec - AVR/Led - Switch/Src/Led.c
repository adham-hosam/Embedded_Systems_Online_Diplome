/*
 * Led.c
 *
 *  Created on: Dec 12, 2023
 *      Author: adham
 */


#include "Led.h"
#include "DIO.h"

void LED_Status(Led_Status led, volatile uint8 *port, uint8 pin){
	if (led == LED_OFF) {
		CLR_BIT(*port, pin);
	} else if (led == LED_ON) {
		SET_BIT(*port, pin);
	} else if (led == LED_TOGGLE) {
		TOG_BIT(*port, pin);
	} else {
		// Wrong Choice
	}
}

