/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/**************		SWC: 	Led.h				***************/
/**************************************************************/
/**************************************************************/

#ifndef LED_H_
#define LED_H_

#include "Stm32f103x6.h"
#include "Stm32f103x6_GPIO_Driver.h"

// Define constants for pin output levels
#define PIN_OUTPUT_LOW 			0
#define PIN_OUTPUT_HIGH			1

// Select the default pin mode
#define PIN_MODE        PIN_OUTPUT_LOW

// LED status options
typedef enum LedStatus {
    LedStatus_LED_OFF,
    LedStatus_LED_ON,
    LedStatus_LED_TOGGLE
}LedStatus_t;

void LED_Status(GPIO_Typedef_t* GPIOx , uint16 GPIO_PINx, LedStatus_t LedStatus);


#endif /* LED_H_ */
