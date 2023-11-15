/*
 * main.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "CA.h"


// Function to perform the initial setup
void Start_Setup(){

	// Start the system with initial State (Waiting)
	CA_State = STATE(CA_Waiting_State);
}

int main()
{
	// Perform initial system setup
	Start_Setup();

	while(1)
	{
		CA_State();	// Execute the current state function (CA_Waiting_State or CA_Driving_State)
	}


	return 0;
}

