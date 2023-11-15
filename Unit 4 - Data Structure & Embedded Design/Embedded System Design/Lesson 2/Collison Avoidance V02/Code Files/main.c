/*
 * main.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "CA.h"
#include "US.h"
#include "DC_Motor.h"


// Function to perform the initial setup
void Start_Setup(){


	US_Init();
	DC_Init();

	// Start the system with initial State (Waiting)
	CA_State = STATE(CA_Waiting_State);

	// Start the motor with initial State (Idle)
	DC_State = STATE(DC_Idle_State);

	// Start the UltraSonic Sensor with initial State (Busy)
	US_State = STATE(US_Busy_State);
}

int main()
{
	// Perform initial system setup
	Start_Setup();

	while(1)
	{
		US_State();

		CA_State();	// Execute the current state function (CA_Waiting_State or CA_Driving_State)

		DC_State();
	}


	return 0;
}

