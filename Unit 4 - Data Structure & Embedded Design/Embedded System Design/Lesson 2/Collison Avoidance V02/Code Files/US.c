/*
 * CA.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "US.h"
#include "state.h"
#include "RandomValue.h"


int US_Distance = 0;


void (*US_State)();	// Function pointer for the current state.



void US_Init(){

	printf("UltraSonic Init=====\n");

}


STATE_Define(US_Busy_State){		//void ST_US_Busy_State()


	// Initial State
	US_State_id = US_Busy;

	// State Action
	// Generate random value of the distance (UltraSonic Sensor reading)
	US_Distance = generateRandomDistance(45, 55);

	printf("Collision Avoidance state is waiting:\n \t distance = %d\n",US_Distance);

	// Send the distance from UltraSonic sensor to CA
	Us_Get_Distance(US_Distance);

	// Always Stay in busy state to calculate the distance to send it to CA
	US_State = STATE(US_Busy_State);

}










