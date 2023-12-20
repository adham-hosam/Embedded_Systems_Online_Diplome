/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/**************		SWC: 	Led.c				***************/
/**************************************************************/
/**************************************************************/

#include "Led.h"

/**************************************************************************
 * Function         : void LED_Status(GPIO_Typedef_t* GPIOx, uint16 GPIO_PINx, LedStatus_t LedStatus)
 * Description      : Controls the status of an LED connected to a specific GPIO pin.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port structure
 *                    GPIO_PINx - Pin number associated with the LED
 *                    LedStatus - Desired status of the LED (LedStatus_LED_OFF, LedStatus_LED_ON, LedStatus_LED_TOGGLE)
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void LED_Status(GPIO_Typedef_t* GPIOx , uint16 GPIO_PINx, LedStatus_t LedStatus){

	// Check the PIN_MODE to determine the logic level for LED control
#if PIN_MODE == PIN_OUTPUT_LOW
	switch (LedStatus) {

	case LedStatus_LED_OFF:
		// Turn off the LED by setting the pin to high
		MCAL_GPIO_WritePin(GPIOx, GPIO_PINx, GPIO_PinStatus_HIGH);
		break;


	case LedStatus_LED_ON:
		// Turn on the LED by setting the pin to low
		MCAL_GPIO_WritePin(GPIOx, GPIO_PINx, GPIO_PinStatus_LOW);
		break;

		// Toggle the LED status
	case LedStatus_LED_TOGGLE:
		MCAL_GPIO_TogglePin(GPIOx , GPIO_PINx);
		break;
	default:
		break;
	}
#elif PIN_MODE == PIN_OUTPUT_HIGH
	switch (LedStatus) {

	case LedStatus_LED_OFF:
		 // Turn off the LED by setting the pin to low
		MCAL_GPIO_WritePin(GPIOx, GPIO_PINx, GPIO_PinStatus_LOW);
		break;

		// Turn on the LED by setting the pin to high
	case LedStatus_LED_ON:
		MCAL_GPIO_WritePin(GPIOx, GPIO_PINx, GPIO_PinStatus_HIGH);
		break;

		// Toggle the LED status
	case LedStatus_LED_TOGGLE:
		MCAL_GPIO_TogglePin(GPIOx , GPIO_PINx);
		break;
	default:
		break;
	}

#endif
}
