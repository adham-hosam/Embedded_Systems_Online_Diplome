/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		RCC.h		   ***************/
/*****************************************************/
/*****************************************************/
#ifndef RCC_H_
#define RCC_H_

#include "Platform_Types.h"
#include "BIT_MATH.h"

#define RCC_BASE 			0x40021000
#define RCC_APB2ENR 		*( (volatile uint32*) (RCC_BASE + 0x18) )
#define RCC_APB2ENR_IOPAEN	2
#define RCC_APB2ENR_IOPBEN	3
void RCC_Init(void);


#endif /* RCC_H_ */
