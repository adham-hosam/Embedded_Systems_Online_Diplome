#include "PLATFORM_TYPES.h"

#define RCC_BASE_ADDRESS		0x40021000
#define RCC_APB2ENR				*((volatile u32*)(RCC_BASE_ADDRESS+0x18))

#define GPIOA_BASE_ADDRESS		0x40010800
#define GPIOA_CRH				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_ODR				*((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))


void main(void)
{
	RCC_APB2ENR |= 1<<2;					/*Enable Clock Of GPIOA*/
	GPIOA_CRH &= 0xFF0FFFFF;				/*Clearing Bit-13 Mode */
	GPIOA_CRH |= 0x00200000;				/*Set Bit-13 As Output */
	while(1)
	{
		GPIOA_ODR |= 1<<13;					/*Set Pin-13*/
		for(int i = 0 ; i<= 50000 ; i++);	/*Polling Delay*/
		GPIOA_ODR &= ~(1<<13);				/*Clear Pin-13*/
		for(int i = 0 ; i<= 50000 ; i++);	/*Polling Delay*/
	}

}
