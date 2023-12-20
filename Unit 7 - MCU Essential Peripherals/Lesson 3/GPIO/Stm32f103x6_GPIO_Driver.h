/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MACL				***************/
/**************		SWC: 	GPIO.h				***************/
/**************************************************************/
/**************************************************************/

#ifndef INC_STM32F103X6_GPIO_DRIVER_H_
#define INC_STM32F103X6_GPIO_DRIVER_H_


/*-----------------------------*/
//Includes
/*-----------------------------*/
#include "Stm32f103x6.h"

/*-----------------------------*/
//Typedef
/*-----------------------------*/
typedef uint8 PinStatus_t;
typedef uint16 PortValue_t;


/*-----------------------------*/
//User type definitions (structures)
/*-----------------------------*/
typedef struct{

	uint16	GPIO_PIN;	// Choose Pin number from the configurations @ref GPIO_PIN_Define

	uint8	GPIO_MODE;	// Choose Pin mode from the configurations @ref GPIO_MODE_Define

	uint8	GPIO_OUTPUT_SPEED;	// Choose Pin speed from the configurations @ref GPIO_OUTPUT_SPEED_Define
}GPIO_PinConfig_t;

/*-----------------------------*/
//Macros Configuration References
/*-----------------------------*/

// GPIO_PIN_Define
#define GPIO_PIN0   0
#define GPIO_PIN1   1
#define GPIO_PIN2   2
#define GPIO_PIN3   3
#define GPIO_PIN4   4
#define GPIO_PIN5   5
#define GPIO_PIN6   6
#define GPIO_PIN7   7
#define GPIO_PIN8   8
#define GPIO_PIN9   9
#define GPIO_PIN10  10
#define GPIO_PIN11  11
#define GPIO_PIN12  12
#define GPIO_PIN13  13
#define GPIO_PIN14  14
#define GPIO_PIN15  15

// GPIO_MODE_Define
#define GPIO_MODE_ANALOG       0 // Analog Mode
#define GPIO_MODE_INPUT_FLO    1 // Input Floating
#define GPIO_MODE_INPUT_PU     2 // Input Pull-up
#define GPIO_MODE_INPUT_PD	   3 // Input Pull-down
#define GPIO_MODE_OUTPUT_PP    4 // Output Push-Pull
#define GPIO_MODE_OUTPUT_OD    5 // Output Open-Drain
#define GPIO_MODE_AF_OUTPUT_PP 6 // Alternate Function Output Push-Pull
#define GPIO_MODE_AF_OUTPUT_OD 7 // Alternate Function Output Open-Drain
#define GPIO_MODE_AF_INPUT     8 // Alternate Function Input

// GPIO_OUTPUT_SPEED_Define
#define GPIO_OUTPUT_SPEED_10MHz		1	// Output mode, max speed 10 MHz
#define GPIO_OUTPUT_SPEED_2MHz		2	// Output mode, max speed 2  MHz
#define GPIO_OUTPUT_SPEED_50MHz		3	// Output mode, max speed 50 MHz

// PinStatus_Define
#define GPIO_PinStatus_LOW	0
#define GPIO_PinStatus_HIGH	1

// GPIO_LockStatus_Define
#define GPIO_LOCK_ERROR		0
#define GPIO_LOCK_ENABLED	1


/*=========================================*/
// APIs Supported by "MCAL GPIO DRIVER"
/*=========================================*/

void MCAL_GPIO_Init(GPIO_Typedef_t* GPIOx ,GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_Typedef_t* GPIOx );

PinStatus_t  MCAL_GPIO_ReadPin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx);
PortValue_t MCAL_GPIO_ReadPort(GPIO_Typedef_t* GPIOx);

void MCAL_GPIO_WritePin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx , PinStatus_t Value);
void MCAL_GPIO_WritePort(GPIO_Typedef_t* GPIOx , uint16 Value);

void MCAL_GPIO_TogglePin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx);

uint8 MCAL_GPIO_LockPin(GPIO_Typedef_t* GPIOx ,uint16 GPIO_PINx);

#endif /* INC_STM32F103X6_GPIO_DRIVER_H_ */
