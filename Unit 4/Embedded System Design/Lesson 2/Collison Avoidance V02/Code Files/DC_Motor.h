/*
 * CA.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

enum{
	DC_Idle,		// Represents the Idle state.
	DC_Busy			// Represents the Busy state.
}Motor_state_id;

extern void (*DC_State)();	// Function pointer for the current state.

	/* Prototypes*/
void DC_Init(void);

STATE_Define(DC_Idle_State);

STATE_Define(DC_Busy_State);



#endif /* DC_MOTOR_H_ */
