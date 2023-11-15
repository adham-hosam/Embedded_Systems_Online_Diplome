/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/*************	  	SWC  :	GIO.h 				***************/
/**************************************************************/
/**************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

/* Includes */
#include "Platform_Types.h"

/* Port A Registers */
#define GPIO_PORTA 		0x40010800
#define GPIOA_CRL		*(volatile uint32*) (GPIO_PORTA + 0x00)
#define GPIOA_CRH		*(volatile uint32*) (GPIO_PORTA + 0x04)
#define GPIOA_IDR		*(volatile uint32*) (GPIO_PORTA + 0x08)
#define GPIOA_ODR		*(volatile uint32*) (GPIO_PORTA + 0x0C)

/* RCC Registers */
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*(volatile uint32*) (RCC_BASE + 0x18)

/* Prototypes */
void GPIO_Init();



#endif /* GPIO_H_ */
