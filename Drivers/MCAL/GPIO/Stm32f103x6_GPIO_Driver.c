/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MACL				***************/
/**************		SWC: 	GPIO.c				***************/
/**************************************************************/
/**************************************************************/

#include "Stm32f103x6_GPIO_Driver.h"

/*=========================================================================================================================================*/
// Private Functions
/*=========================================================================================================================================*/

/**************************************************************************
 * Function         : static uint8 Get_PinPosition(uint16 GPIO_PINx)
 * Description      : Calculates the position of a pin within its GPIO port configuration register.
 * Parameters (in)  : GPIO_PINx - GPIO pin number.
 * Parameters (out) : None
 * Return value     : The position of the pin in the GPIO port configuration register.
 **************************************************************************/
static uint8 Get_PinPosition(uint16 GPIO_PINx) {

	// Define a base offset for the first pin of each group
	const uint8 baseOffset = 0;

	// Check if PinNum is a valid GPIO pin
	if (GPIO_PINx < GPIO_PIN0 || GPIO_PINx > GPIO_PIN15) {
		// Handle invalid pin number
		return 0;
	}

	// Calculate the position based on the pin number and the base offset
	uint8 position = baseOffset + ((GPIO_PINx % 8) * 4);

	return position;
}

/**************************************************************************
 * Function         : void MCAL_GPIO_Init(GPIO_Typedef_t* GPIOx, GPIO_PinConfig_t* PinConfig)
 * Description      : Initializes a GPIO pin based on the provided configuration.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO peripheral.
 *                    PinConfig - Pointer to the GPIO pin configuration.
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_GPIO_Init(GPIO_Typedef_t* GPIOx ,GPIO_PinConfig_t* PinConfig){

	V_uint32* ConfigReg = NULL;
	uint8 Pin_Config = 0;

	// Determine the configuration register based on the pin number
	ConfigReg = (PinConfig->GPIO_PIN < GPIO_PIN8) ? &GPIOx->CRL : &GPIOx->CRH;

	// Clear the bits corresponding to the pin in the configuration register
	(*ConfigReg) &= ~(0xF << Get_PinPosition(PinConfig->GPIO_PIN));

	// Pin is output
	if( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_AF_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_AF_OUTPUT_OD) ){

		// Set CNF & MODE
		Pin_Config = ( ( ( ( PinConfig->GPIO_MODE -4) << 2 ) | (PinConfig->GPIO_OUTPUT_SPEED)) & 0x0f );

	}
	// Pin is input
	else{
		if( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG) ){
			// Set CNF & MODE
			Pin_Config =  ( ( ( (PinConfig->GPIO_MODE) << 2 ) | 0x0) & 0x0f );
		}
		else if((PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)){ // Consider as input floating

			Pin_Config =  ( ( ( (GPIO_MODE_INPUT_FLO) << 2 ) | 0x0) & 0x0f );

		}
		else{	// Input Pull-up and Pull-down
			Pin_Config =  ( ( ( GPIO_MODE_INPUT_PU << 2 ) | 0x0) & 0x0f );
			if( PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){
				GPIOx->ODR |= (1 << PinConfig->GPIO_PIN);
			}
			else {
				GPIOx->ODR &= ~(1 << PinConfig->GPIO_PIN);
			}
		}
	}
	// Set the bits in the configuration register based on the calculated value
	(*ConfigReg) |= ( (Pin_Config) << Get_PinPosition(PinConfig->GPIO_PIN) );
}

/**************************************************************************
 * Function         : void MCAL_GPIO_DeInit(GPIO_Typedef_t* GPIOx)
 * Description      : DeInitializes a GPIO peripheral.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO peripheral.
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_GPIO_DeInit(GPIO_Typedef_t* GPIOx ){

	// Check the GPIO pointer to determine the GPIO peripheral
	if(GPIOx == GPIOA){

		// Reset and clear the reset for GPIOA
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){

		// Reset and clear the reset for GPIOB
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC){

		// Reset and clear the reset for GPIOC
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD){

		// Reset and clear the reset for GPIOD
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
}

/**************************************************************************
 * Function         : PinStatus MCAL_GPIO_ReadPin(GPIO_Typedef_t* GPIOx, uint16 GPIO_PINx)
 * Description      : Reads the status of a specific GPIO pin.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port.
 *                    GPIO_PINx - GPIO pin number.
 * Parameters (out) : None
 * Return value     : The status of the specified GPIO pin @ref PinStatus_Define
 **************************************************************************/
PinStatus_t  MCAL_GPIO_ReadPin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx){

	uint8 PinStatus = 0;

	// Check if the specified PinNum is within the valid range
	if(GPIO_PINx <= GPIO_PIN15){

		// Read the status of the specified pin
		PinStatus= GET_BIT(GPIOx->IDR , GPIO_PINx);
	}

	// Return the status of the specified pin
	return PinStatus;

}

/**************************************************************************
 * Function         : PortValue MCAL_GPIO_ReadPort(GPIO_Typedef_t* GPIOx)
 * Description      : Reads the entire port value of a GPIO port.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port structure
 * Parameters (out) : None
 * Return value     : PortValue - Value of the entire GPIO port
 **************************************************************************/
PortValue_t MCAL_GPIO_ReadPort(GPIO_Typedef_t* GPIOx){

	// Return the entire input data register (IDR) value of the GPIO port
	return (uint16)GPIOx->IDR;
}

/**************************************************************************
 * Function         : void MCAL_GPIO_WritePin(GPIO_Typedef_t* GPIOx, uint16 GPIO_PINx, PinStatus Value)
 * Description      : Writes a specified value to a specific pin in a GPIO port.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port structure
 *                    GPIO_PINx - Pin number to write the value to
 *                    Value - Status to be written to the pin @ref PinStatus_Define
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_GPIO_WritePin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx , PinStatus_t Value){

	// Check if the specified PinNum is within the valid range
	if(GPIO_PINx <= GPIO_PIN15){

		// Check the desired value to be written
		if(Value == GPIO_PinStatus_LOW){

			// Clear the specified bit in the Output Data Register
			CLR_BIT(GPIOx->ODR , GPIO_PINx);

			// Alternatively, you can use the Bit Reset Register (BRR) as shown in the commented code
			/* GPIOx->BRR = (1 << GPIO_PINx); */
		}
		else{
			// Set the specified bit in the Output Data Register
			SET_BIT(GPIOx->ODR , GPIO_PINx);

			// Alternatively, you can use the Bit Set Register (BSRR) as shown in the commented code
			/* GPIOx->BSRR = (1 << GPIO_PINx); */
		}
	}
}

/**************************************************************************
 * Function         : void MCAL_GPIO_WritePort(GPIO_Typedef_t* GPIOx, uint16 Value)
 * Description      : Writes a specified value to the entire GPIO port.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port structure
 *                    Value - Value to be written to the entire GPIO port
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_GPIO_WritePort(GPIO_Typedef_t* GPIOx , uint16 Value){

	// Write the specified value to the Output Data Register of the GPIO port
	GPIOx->ODR = (uint32)Value;
}

/**************************************************************************
 * Function         : void MCAL_GPIO_TogglePin(GPIO_Typedef_t* GPIOx, uint16 GPIO_PINx)
 * Description      : Toggles the state of a specific pin in a GPIO port.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port structure
 *                    GPIO_PINx - Pin number to toggle
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_GPIO_TogglePin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx){

	// Check if the specified PinNum is within the valid range
	if(GPIO_PINx <= GPIO_PIN15){

		// Toggle the specified bit in the Output Data Register
		TOG_BIT(GPIOx->ODR , GPIO_PINx);
	}
}

/**************************************************************************
 * Function         : uint8 MCAL_GPIO_LockPin(GPIO_Typedef_t* GPIOx, uint16 GPIO_PINx)
 * Description      : Locks a specific pin in a GPIO port.
 * Parameters (in)  : GPIOx [x:A,B,C,D] - Pointer to the GPIO port structure
 *                    GPIO_PINx - Pin number to lock
 * Parameters (out) : None
 * Return value     : GPIO_LOCK_ENABLED if the pin is successfully locked,
 *                    GPIO_LOCK_ERROR otherwise.
 **************************************************************************/
uint8 MCAL_GPIO_LockPin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx){

	 // Check if the specified PinNum is within the valid range
	if(GPIO_PINx <= GPIO_PIN15){

		// Temporary variable for locking sequence
		V_uint32 Temp = (1 << 16);

		// Set the lock bit for the specified pin
		Temp |= (1 << GPIO_PINx);

		// Perform the lock sequence
		GPIOx->LCKR = Temp;
		GPIOx->LCKR = (1 << GPIO_PINx);
		GPIOx->LCKR = Temp;

		// Read the lock register to check if the pin is locked
		Temp = GPIOx->LCKR;

		// Check the lock status
		if( (uint32) (GPIOx->LCKR & 1<<16) ){

			 // Pin is successfully locked
			return GPIO_LOCK_ENABLED;
		}
		else{
			// Failed to lock the pin
			return GPIO_LOCK_ERROR;
		}
	}

	// Return GPIO_LOCK_ERROR if GPIO_PINx is out of range
	return GPIO_LOCK_ERROR;
}
