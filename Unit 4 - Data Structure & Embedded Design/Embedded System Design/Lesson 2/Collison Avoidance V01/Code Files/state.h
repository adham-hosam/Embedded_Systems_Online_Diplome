/*
 * state.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef STATE_H_
#define STATE_H_

/* Includes */
#include "time.h"
#include <stdio.h>
#include <stdlib.h>


// It takes an argument (_State_Fun) to create a unique state transition function name.
// For example, if STATE_Define(Waiting) is used, it creates a function named ST_Waiting().
#define STATE_Define(_State_Fun)	void ST_##_State_Fun()

#define STATE(_Current_State_)		ST_##_Current_State_




#endif /* STATE_H_ */
