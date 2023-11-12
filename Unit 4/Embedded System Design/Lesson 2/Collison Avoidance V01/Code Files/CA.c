/*
 * CA.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "CA.h"
#include "state.h"
#include "RandomValue.h"

static int CA_Speed = 0;
static int CA_Distance = 0;
static int CA_Threshold = 50;

void (*CA_State)();	// Function pointer for the current state.




STATE_Define(CA_Waiting_State){		//void ST_CA_Waiting_State()


	// Initial State
	CA_State_id = CA_waiting;

	// State Action (Motor off)
	CA_Speed = 0;

	// Generate random value of the distance (UltraSonic Sensor reading)
	CA_Distance = generateRandomDistance(45, 55);

	// Event Check (ultraSonic sensor get the distance)
	// If distance is below or equal to the threshold, stay in the waiting state;
    // otherwise, transition to the driving state.
	(CA_Distance <= CA_Threshold)? (CA_State = STATE(CA_Waiting_State)) : (CA_State = STATE(CA_Driving_State));
							      //CA_State = ST_CA_Waiting_State => (address of the function)

	printf("Collision Avoidance state is waiting:\n \t distance = %d speed = %d\n",CA_Distance,CA_Speed);

}

STATE_Define(CA_Driving_State){

	// Initial State
	CA_State_id = CA_driving;

	// State Action (Motor on)
	CA_Speed = 30;


	// Generate random value of the distance (UltraSonic Sensor reading)
	CA_Distance = generateRandomDistance(45, 55);

	// Event Check (ultraSonic sensor get the distance)
	// If distance is below or equal to the threshold, transition back to the waiting state;
    // otherwise, stay in the driving state.
	(CA_Distance <= CA_Threshold)? (CA_State = STATE(CA_Waiting_State)) : (CA_State = STATE(CA_Driving_State));


	printf("Collision Avoidance state is driving:\n \t distance = %d speed = %d\n",CA_Distance,CA_Speed);
}








