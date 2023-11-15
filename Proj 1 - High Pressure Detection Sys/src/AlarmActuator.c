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
 * Function         : void AlarmActuator_SetAlarm(Alarm_Status status)
 * Description      : Sets or clears the Alarm Actuator based on the provided status.
 * Parameters (in)  : status - Alarm_ON to turn on the alarm, Alarm_OFF to turn it off.
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void AlarmActuator_SetAlarm(Alarm_Status status)
{
	if(status == Alarm_ON){
		CLR_BIT(GPIOA_ODR , 13);	// Alarm ON	(Active Low)
	}
	else if(status == Alarm_OFF){
		SET_BIT(GPIOA_ODR , 13);	// Alarm OFF (Active low)
	}
}
