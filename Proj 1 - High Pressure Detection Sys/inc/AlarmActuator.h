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

	Alarm_OFF,
	Alarm_ON

}Alarm_Status;

/* Prototypes */
void AlarmActuator_Init(void);
void AlarmActuator_SetAlarm(Alarm_Status status);

#endif /* ALARMACTUATOR_H_ */
