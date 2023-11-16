/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/*************	  	SWC  :	AlarmActuator.h 	***************/
/**************************************************************/
/**************************************************************/

#ifndef ALARMACTUATOR_H_
#define ALARMACTUATOR_H_

/* Includes */
#include "Platform_Types.h"
#include "BIT_MATH.h"

typedef enum{

	Alarm_OFF,	// Alarm is OFF
	Alarm_ON,	// Alarm is ON
	Alarm_Error	// Invalid alarm status

}Alarm_Status;

/* Prototypes */
void AlarmActuator_Init(void);
Alarm_Status AlarmActuator_SetAlarm(Alarm_Status status);

#endif /* ALARMACTUATOR_H_ */
