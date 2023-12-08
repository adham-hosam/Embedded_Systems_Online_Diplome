/*
 * STM.c
 *
 *      Author: adham
 */

#include "STM.h"


void RCC_Init(){

	/* Lap 1
- APB1 Bus frequency 4MHZ
- APB2 Bus frequency 2MHZ
- AHB frequency 8 MHZ
- SysClk 8 MHZ
- Use only internal HSI_RC
	 */
	// PPRE1[2:0]: APB Low-speed prescaler (APB1)
	//RCC_CFGR |= 0b100<<8;		// 100: HCLK divided by 2

	// PPRE2[2:0]: APB high-speed prescaler (APB2)
	//RCC_CFGR |= 0b101<<11;		// 101: HCLK divided by 4

	/* Lap 2
- APB1 Bus frequency 16MHZ
- APB2 Bus frequency 8MHZ
- AHB frequency 32 MHZ
- SysClk 32 MHZ
- Use only internal HSI_RC
	 */

	// PLLSRC: PLL entry clock source
	RCC_CFGR &= ~(1<<16);	// 0: HSI oscillator clock / 2 selected as PLL input clock

	// PLLMUL: PLL multiplication factor
	RCC_CFGR |= 0b0110 << 18;				// 0110: PLL input clock x 8

	// PPRE1[2:0]: APB Low-speed prescaler (APB1)
	RCC_CFGR |= 0b100<< 8;		// 100: HCLK divided by 2

	// PPRE2[2:0]: APB high-speed prescaler (APB2)
	RCC_CFGR |= 0b101<< 11;		// 101: HCLK divided by 4

	// SW[1:0]: System clock Switch
	RCC_CFGR |= 0b10 << 0;				// 10: PLL selected as system clock

	// PLLON: PLL enable
	RCC_CR |= 1 << 24;

}


void GPIO_Init(){
	// Enable clock for GPIOA
	RCC_APB2ENR |= 1<<2;

	// Enable clock for AFIO
	RCC_APB2ENR |= 1<<0;

	// Configure pin A13 as output
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;

	// Configure pin A0 as floating input for the interrupt
	GPIO_CRL |= (1<<2);	// Floating input (reset state)
}

void LED_Status(Led_status led){
	if(led == LED_ON){
		GPIO_ODR |= 1<<13;
	}
	else if(led == LED_OFF){
		GPIO_ODR &= ~(1<<13);
	}
	else if (led == LED_TOGGLE){
		GPIO_ODR ^=(1<<13);
	}
}
