/*
 * US.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef US_H_
#define US_H_

#include "state.h"

enum{
	US_Busy		// Represents the Busy state.

}US_State_id;

extern void (*US_State)();	// Function pointer for the current state.

	/* Prototypes*/

void US_Init(void);

STATE_Define(US_Busy_State);




#endif /* US_H_ */
