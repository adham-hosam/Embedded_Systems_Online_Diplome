/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		GPIO.h		   ***************/
/*****************************************************/
/*****************************************************/
#ifndef GPIO_H_
#define GPIO_H_

#include "Platform_Types.h"
#include "BIT_MATH.h"


// GPIOA
#define GPIOA_BASE 		0x40010800
#define GPIOA_CRL 		*( (volatile uint32*) (GPIOA_BASE + 0x00) )
#define GPIOA_CRH 		*( (volatile uint32*) (GPIOA_BASE + 0x04) )
#define GPIOA_IDR 		*( (volatile uint32*) (GPIOA_BASE + 0x08) )
#define GPIOA_ODR 		*( (volatile uint32*) (GPIOA_BASE + 0x0C) )

// GPIOB
#define GPIOB_BASE 		0x40010C00
#define GPIOB_CRL 		*( (volatile uint32*) (GPIOB_BASE + 0x00) )
#define GPIOB_CRH 		*( (volatile uint32*) (GPIOB_BASE + 0x04) )
#define GPIOB_IDR 		*( (volatile uint32*) (GPIOB_BASE + 0x08) )
#define GPIOB_ODR 		*( (volatile uint32*) (GPIOB_BASE + 0x0C) )

/* Port Configurations */
#define PORTA	0
#define PORTB	1
#define PORTC	2

/* Pin Configurations */
#define PIN0	0
#define PIN1	1
#define PIN13	13

/* LED Configurations */
typedef enum{
	LED_OFF,
	LED_ON,
	LED_TOGGLE
}Led_Status;

void GPIO_Init();

uint8 GPIO_GetPinValue(uint8 port , uint8 pin);

void LED_Status(Led_Status led, uint8 port ,  uint8 pin);


#endif /* GPIO_H_ */
