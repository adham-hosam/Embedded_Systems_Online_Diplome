/*
 * CA.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "CA.h"
#include "state.h"
#include "RandomValue.h"

int CA_Speed = 0;
int CA_Distance = 0;
int const CA_Threshold = 50;

void (*CA_State)();	// Function pointer for the current state.


// The connection between UltraSonic Sensor and CA
void Us_Get_Distance(int distance){

	CA_Distance = distance;

	(CA_Distance <= CA_Threshold)? (CA_State = STATE(CA_Waiting_State)) : (CA_State = STATE(CA_Driving_State));

	printf("US -------- distance=%d --------> CA\n",CA_Distance);
}


STATE_Define(CA_Waiting_State){		//void ST_CA_Waiting_State()


	// Initial State
	CA_State_id = CA_waiting;

	printf("Collision Avoidance state is waiting:\n \t distance = %d speed = %d\n",CA_Distance,CA_Speed);


	// State Action (Motor off)
	CA_Speed = 0;
	DC_Motor_SetSpeed(CA_Speed);


}

STATE_Define(CA_Driving_State){

	// Initial State
	CA_State_id = CA_driving;

	printf("Collision Avoidance state is driving:\n \t distance = %d speed = %d\n",CA_Distance,CA_Speed);

	// State Action (Motor on)
	CA_Speed = 30;

	DC_Motor_SetSpeed(CA_Speed);


}








