/*
 * STM.h
 *
 *      Author: adham
 */

#include "Platform_Types.h"

typedef enum{
	LED_OFF,
	LED_ON,
	LED_TOGGLE
}Led_status;

#ifndef STM_H_
#define STM_H_

#define RCC_BASE 		0x40021000
#define RCC_CR			*( (volatile uint32*) (RCC_BASE + 0x00) )
#define RCC_CFGR		*( (volatile uint32*) (RCC_BASE + 0x04) )
#define RCC_APB2ENR  	*( (volatile uint32*) (RCC_BASE + 0x18) )


#define GPIOA_BASE 		0x40010800
#define GPIO_CRL        *( (volatile uint32 *)(GPIOA_BASE+0x00) )
#define GPIO_CRH        *( (volatile uint32 *)(GPIOA_BASE+0x04) )
#define GPIO_ODR        *( (volatile uint32 *)(GPIOA_BASE+0x0C) )



void RCC_Init();
void GPIO_Init();
void LED_Status(Led_status led);



#endif /* STM_H_ */
