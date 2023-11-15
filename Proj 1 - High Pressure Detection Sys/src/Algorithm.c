/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  APP					***************/
/*************	  	SWC  :	Algorithm.c 		***************/
/**************************************************************/
/**************************************************************/

#include "Platform_Types.h"
#include "Delay.h"

#include "Algorithm.h"
#include "AlarmActuator.h"


boolean Alarm_Flag = Low;
/**************************************************************************
 * Function         : void CheckPressureValue(uint32 PressureValue)
 * Description      : Checks the pressure value against a predefined threshold
 *                    and takes actions accordingly.
 * Parameters (in)  : PressureValue - The pressure value to be checked.
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void CheckPressureValue(uint32 PressureValue)
{

	if(PressureValue >= PRESSURE_THRESHOLD && !Alarm_Flag ){


		AlarmActuator_SetAlarm(Alarm_ON);


		Delay(600000);


		AlarmActuator_SetAlarm(Alarm_OFF);

		Alarm_Flag = High;

	}
	else if(PressureValue < PRESSURE_THRESHOLD)
	{

		AlarmActuator_SetAlarm(Alarm_OFF);
		Alarm_Flag = Low;
	}
}

