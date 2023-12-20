/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MACL				***************/
/**************		SWC: 	Stm32f103x6.h		***************/
/**************************************************************/
/**************************************************************/

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_


/*-----------------------------*/
//Includes
/*-----------------------------*/
#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "stdlib.h"

/*-----------------------------*/
// Memories Base addresses
/*-----------------------------*/
#define Flash_Memory_Base 	0x08000000
#define System_Memory_Base 	0x1FFFF000
#define SRAM_Memory_Base 	0x20000000

#define Peripherals_Base 	0x40000000

#define Peripherals_Base 	0x40000000


/*-----------------------------*/
// Core Peripherals Base addresses
/*-----------------------------*/

// NVIC
#define NVIC_BASE		0xE000E100								// Nested vectored interrupt controller
#define NVIC_ISER0		*(volatile uint32*) (NVIC_BASE + 0x00)	// Interrupt set-enable registers
#define NVIC_ISER1		*(volatile uint32*) (NVIC_BASE + 0x04)
#define NVIC_ICER0		*(volatile uint32*) (NVIC_BASE + 0x80)	// Interrupt clear-enable registers
#define NVIC_ICER1		*(volatile uint32*) (NVIC_BASE + 0x84)


/*-----------------------------*/
//BUS Peripherals Base addresses
/*-----------------------------*/

/*** AHP ****/
//RCC
#define RCC_BASE		0x40021000

/*** APB2 ****/
// GPIO
#define GPIOA_BASE		0x40010800
#define GPIOB_BASE		0x40010C00
#define GPIOC_BASE		0x40011000
#define GPIOD_BASE		0x40011400

// AFIO
#define AFIO_BASE		0x40010000

// EXTI
#define EXTI_BASE		0x40010400

/*-----------------------------*/
//Peripheral register: RCC
/*-----------------------------*/
typedef struct{

	V_uint32 CR;
	V_uint32 CFGR;
	V_uint32 CIR;
	V_uint32 APB2RSTR;
	V_uint32 APB1RSTR;
	V_uint32 AHBENR;
	V_uint32 APB2ENR;
	V_uint32 APB1ENR;
	V_uint32 BDCR;
	V_uint32 CSR;
	V_uint32 AHBSTR;
	V_uint32 CFGR2;

}RCC_Typedef_t;

/*-----------------------------*/
//Peripheral register: GPIO
/*-----------------------------*/
typedef struct{

	V_uint32 CRL;
	V_uint32 CRH;
	V_uint32 IDR;
	V_uint32 ODR;
	V_uint32 BSRR;
	V_uint32 BRR;
	V_uint32 LCKR;

}GPIO_Typedef_t;

/*-----------------------------*/
//Peripheral register: AFIO
/*-----------------------------*/
typedef struct{

	V_uint32 EVCR;
	V_uint32 MAPR;
	V_uint32 EXTICR[4];
	V_uint32 RESERVED0;
	V_uint32 MAPR2;

}AFIO_Typedef_t;


/*-----------------------------*/
//Peripheral register: EXTI
/*-----------------------------*/
typedef struct{

	V_uint32 IMR;
	V_uint32 EMR;
	V_uint32 RTSR;
	V_uint32 FTSR;
	V_uint32 SWIER;
	V_uint32 PR;

}EXTI_Typedef_t;


/*-----------------------------*/
//Peripheral Instants
/*-----------------------------*/

// RCC
#define RCC 				( (RCC_Typedef_t*) (RCC_BASE) )

// GPIO
#define GPIOA 				( (GPIO_Typedef_t*) (GPIOA_BASE) )
#define GPIOB 				( (GPIO_Typedef_t*) (GPIOB_BASE) )
#define GPIOC 				( (GPIO_Typedef_t*) (GPIOC_BASE) )
#define GPIOD 				( (GPIO_Typedef_t*) (GPIOD_BASE) )

// AFIO
#define AFIO 				( (AFIO_Typedef_t*) (AFIO_BASE) )

// EXTI
#define EXTI				( (EXTI_Typedef_t*) (EXTI_BASE) )




/*-----------------------------*/
// clock enable Macros:
/*-----------------------------*/
#define GPIOA_CLK_EN()		(RCC->APB2ENR |= 1<<2)
#define GPIOB_CLK_EN()		(RCC->APB2ENR |= 1<<3)
#define GPIOC_CLK_EN()		(RCC->APB2ENR |= 1<<4)
#define GPIOD_CLK_EN()		(RCC->APB2ENR |= 1<<5)

#define AFIO_CLK_EN()		(RCC->APB2ENR |= 1<<0)



/*-----------------------------*/
// NVIC IRQ Enable/Disable Macros
/*-----------------------------*/
/******************  Enable  ******************/
#define NVIC_IRQ6_EXTI0_Enable()			(NVIC_ISER0 |= 1<< EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_Enable()			(NVIC_ISER0 |= 1<< EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_Enable()			(NVIC_ISER0 |= 1<< EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_Enable()			(NVIC_ISER0 |= 1<< EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_Enable()			(NVIC_ISER0 |= 1<< EXTI4_IRQ)
#define NVIC_IRQ5_9_EXTI4_Enable()			(NVIC_ISER0 |= 1<< EXTI5_IRQ)
#define NVIC_IRQ10_15_EXTI4_Enable()		(NVIC_ISER1 |= 1<< 8) // 40-32 = 8

/******************  Disable  ******************/
#define NVIC_IRQ6_EXTI0_Disable()			(NVIC_ICER0 |= 1<< EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_Disable()			(NVIC_ICER0 |= 1<< EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_Disable()			(NVIC_ICER0 |= 1<< EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_Disable()			(NVIC_ICER0 |= 1<< EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_Disable()			(NVIC_ICER0 |= 1<< EXTI4_IRQ)
#define NVIC_IRQ5_9_EXTI4_Disable()			(NVIC_ICER0 |= 1<< EXTI5_IRQ)
#define NVIC_IRQ10_15_EXTI4_Disable()		(NVIC_ICER1 |= 1<< 8) // 40-32 = 8


//-*-*-*-*-*-*-*-*-*-*-*-
// Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//EXTI Vector table for connectivity line devices
#define EXTI0_IRQ		6
#define EXTI1_IRQ       7
#define EXTI2_IRQ       8
#define EXTI3_IRQ       9
#define EXTI4_IRQ       10
#define EXTI5_IRQ       23
#define EXTI6_IRQ       23
#define EXTI7_IRQ       23
#define EXTI8_IRQ       23
#define EXTI9_IRQ       23
#define EXTI10_IRQ      40
#define EXTI11_IRQ      40
#define EXTI12_IRQ      40
#define EXTI13_IRQ      40
#define EXTI14_IRQ      40
#define EXTI15_IRQ      40



#endif /* INC_STM32F103X6_H_ */
