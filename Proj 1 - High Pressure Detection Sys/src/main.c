/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/*************	  			main.c				***************/
/**************************************************************/
/**************************************************************/
/**************************************************************/

#include "Platform_Types.h"

#include "GPIO.h"

#include "PressureSenesor.h"
#include "AlarmActuator.h"

#include "Algorithm.h"

int main(){
	uint32 PressureValue;

	 // Initialize GPIO, Pressure Sensor, and Alarm Actuator
	GPIO_Init();
	PressureSensor_Init();
	AlarmActuator_Init();

	while(1){

		 // Read pressure value from the sensor
		PressureSensor_GetPressureValue(&PressureValue);

		// Check the pressure value and control the alarm
		CheckPressureValue(PressureValue);
	}

	return 0;
}

