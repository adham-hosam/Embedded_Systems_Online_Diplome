/*
 * RCC.c
 *
 *  Created on: Dec 10, 2023
 *      Author: adham
 */

#include "RCC.h"

void RCC_Init(void){

	// Enable Clock for GPIOA & GPIOB
	SET_BIT(RCC_APB2ENR , RCC_APB2ENR_IOPAEN);
	SET_BIT(RCC_APB2ENR , RCC_APB2ENR_IOPBEN);
}

