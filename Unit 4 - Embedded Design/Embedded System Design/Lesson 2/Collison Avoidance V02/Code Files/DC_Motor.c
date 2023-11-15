/*
 * CA.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */


#include "DC_Motor.h"
#include "state.h"


int DC_Speed = 0;


void (*DC_State)();	// Function pointer for the current state.

void DC_Init(){

	printf("DC Motor Init=====\n");
}

// The connection between DC-Motor and CA
void DC_Motor_SetSpeed(int speed){

	DC_Speed = speed;

	DC_State = STATE(DC_Busy_State);

	printf("CA -------- speed=%d --------> DC\n",DC_Speed);
}


STATE_Define(DC_Idle_State){		//void ST_CA_Waiting_State()


	// Initial State
	Motor_state_id =DC_Idle;

	printf("Collision Avoidance state is waiting:\n \t speed = %d\n",DC_Speed);

}

STATE_Define(DC_Busy_State){

	// Initial State
	Motor_state_id = DC_Busy;

	DC_State = STATE(DC_Idle_State);

	printf("Collision Avoidance state is waiting:\n \t speed = %d\n",DC_Speed);

}








