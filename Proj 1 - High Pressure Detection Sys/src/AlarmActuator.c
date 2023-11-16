/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/*************	  	SWC  :	AlarmActuator.c 	***************/
/**************************************************************/
/**************************************************************/

#include "AlarmActuator.h"
#include "GPIO.h"


/**************************************************************************
 * Function         : void AlarmActuator_Init()
 * Description      : Initializes the Alarm Actuator and begin with alarm status off
 * Parameters (in)  : None
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void AlarmActuator_Init(){

	GPIOA_ODR |= 1<<13; // Alarm initially off
}

/**************************************************************************
 * Function         : Alarm_Status AlarmActuator_SetAlarm(Alarm_Status status)
 * Description      : Sets the status of the alarm actuator based on the input.
 * Parameters (in)  : status - Desired status of the alarm (Alarm_ON or Alarm_OFF).
 * Parameters (out) : None
 * Return value     : Returns the current status of the alarm.
 **************************************************************************/
Alarm_Status AlarmActuator_SetAlarm(Alarm_Status status)
{
	uint8 Status;

	// Check if the desired status is to turn the alarm ON
	if(status == Alarm_ON){
		CLR_BIT(GPIOA_ODR , 13);	// Alarm ON	(Active Low)

		Status = Alarm_ON;
	}
	 // Check if the desired status is to turn the alarm OFF
	else if(status == Alarm_OFF){
		SET_BIT(GPIOA_ODR , 13);	// Alarm OFF (Active low)

		Status = Alarm_OFF;
	}
	// If an invalid status is provided, set the return status to indicate an error
	else{
		Status = Alarm_Error;
	}

	// Return the current status of the alarm
	return Status;
}
