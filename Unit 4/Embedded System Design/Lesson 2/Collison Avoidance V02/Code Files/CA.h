/*
 * CA.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum{
	CA_waiting,		// Represents the waiting state.
	CA_driving		// Represents the driving state.
}CA_State_id;

extern void (*CA_State)();	// Function pointer for the current state.

	/* Prototypes*/
STATE_Define(CA_Waiting_State);

STATE_Define(CA_Driving_State);



#endif /* CA_H_ */
