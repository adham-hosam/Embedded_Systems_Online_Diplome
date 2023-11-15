/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/*************	  	SWC  :	PressureSensor.h 	***************/
/**************************************************************/
/**************************************************************/

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

/* Includes */
#include "Platform_Types.h"

// Enum to represent Pressure Sensor status
typedef enum{

	PSensor_init,
	PSensor_OK,
	PSensor_Error

}PressureSensor_Status;

/* Prototypes */
PressureSensor_Status PressureSensor_Init(void);
PressureSensor_Status PressureSensor_GetPressureValue(uint32* PressureValue);


#endif /* PRESSURE_SENSOR_H_ */
