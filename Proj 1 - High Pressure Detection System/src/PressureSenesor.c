/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/*************	  	SWC  :	PressureSensor.c 	***************/
/**************************************************************/
/**************************************************************/

#include "PressureSenesor.h"

#include "Delay.h"
#include "GPIO.h"


/**************************************************************************
 * Function         : PressureSensor_Status PressureSensor_Init(void)
 * Description      : Initializes the pressure sensor and returns its status.
 * Parameters (in)  : None
 * Parameters (out) : None
 * Return value     : PressureSensor_Status - The status of the pressure sensor.
 **************************************************************************/
PressureSensor_Status PressureSensor_Init(void)
{
	return PSensor_init;	// PressureSensor init successfully
}


/**************************************************************************
 * Function         : PressureSensor_Status PressureSensor_GetPressureValue(uint32* PressureValue)
 * Description      : Read the pressure value from pins A0 to A7 and returns the status.
 * Parameters (in)  : PressureValue - Pointer to store the pressure value.
 * Parameters (out) : None
 * Return value     : PressureSensor_Status - The status of the pressure sensor.
 **************************************************************************/
PressureSensor_Status PressureSensor_GetPressureValue(uint32* PressureValue)
{
	// Check if the pointer to the pressure value is valid
	if(!PressureValue){

		return PSensor_Error;	// Invalid Parameter
	}
	*PressureValue  = (GPIOA_IDR & 0xFF);	// Read the pressure value from pin A0 to A7

	return PSensor_OK;
}


