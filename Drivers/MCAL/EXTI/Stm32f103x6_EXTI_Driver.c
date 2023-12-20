/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MACL				***************/
/**************		SWC: 	EXTI.c				***************/
/**************************************************************/
/**************************************************************/

#include "Stm32f103x6_EXTI_Driver.h"

/*=========================================================================================================================================*/
// 														Generic Macros
/*=========================================================================================================================================*/

#define AFIO_GPIO_MAPPING(x)	  ((x == GPIOA)?0:\
		(x == GPIOB)?1:\
				(x == GPIOC)?2:\
						(x == GPIOD)?3:0)


/*=========================================================================================================================================*/
// 														Global Variables
/*=========================================================================================================================================*/

void (*GP_IRQ_CallBack[15])(void);

/*=========================================================================================================================================*/
// 														Private Functions
/*=========================================================================================================================================*/

void NVIC_Enable(uint16 IRQ){

	switch(IRQ){
		case EXTI0:		NVIC_IRQ6_EXTI0_Enable();	break;
		case EXTI1:		NVIC_IRQ7_EXTI1_Enable();	break;
		case EXTI2:		NVIC_IRQ8_EXTI2_Enable();	break;
		case EXTI3:		NVIC_IRQ9_EXTI3_Enable();	break;
		case EXTI4:		NVIC_IRQ10_EXTI4_Enable();	break;
		case EXTI5:
		case EXTI6:
		case EXTI7:
		case EXTI8:
		case EXTI9:		NVIC_IRQ5_9_EXTI4_Enable();		break;
		case EXTI10:
		case EXTI11:
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:	NVIC_IRQ10_15_EXTI4_Enable();		break;
		default:		break;
	}

}

void NVIC_Disable(uint16 IRQ){

	switch(IRQ){
		case EXTI0:		NVIC_IRQ6_EXTI0_Disable();		break;
		case EXTI1:		NVIC_IRQ7_EXTI1_Disable();		break;
		case EXTI2:		NVIC_IRQ8_EXTI2_Disable();		break;
		case EXTI3:		NVIC_IRQ9_EXTI3_Disable();		break;
		case EXTI4:		NVIC_IRQ10_EXTI4_Disable();		break;
		case EXTI5:
		case EXTI6:
		case EXTI7:
		case EXTI8:
		case EXTI9:		NVIC_IRQ5_9_EXTI4_Disable();	break;
		case EXTI10:
		case EXTI11:
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:	NVIC_IRQ10_15_EXTI4_Disable();	break;
		default:		break;
	}

}


void UpdateFunction(EXTI_PinConfig_t* EXTI_Config){

	GPIO_PinConfig_t PinCfg;

	// Configure the GPIO Pin to be Floating input
	PinCfg.GPIO_PIN = EXTI_Config->EXTI_Pin.GPIO_PINx;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIOx, &PinCfg);

	// Calculate the AFIO_EXTICR index and position
	uint8 AFIO_EXTICR_Index = EXTI_Config->EXTI_Pin.EXTI_Line_Num / 4;

	uint8 AFIO_EXTICR_Position = (EXTI_Config->EXTI_Pin.EXTI_Line_Num % 4) * 4;

	// Clear the 4 bits
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	 // Configure EXTI line mapping in AFIO
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_MAPPING(EXTI_Config->EXTI_Pin.GPIOx) & 0xF) << AFIO_EXTICR_Position);

	// Trigger Case
		// Clear trigger settings for the EXTI line
	CLR_BIT(EXTI->RTSR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);
	CLR_BIT(EXTI->FTSR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);

		// Configure trigger settings based on the specified case
	switch(EXTI_Config->Trigger_Case){
	case EXTI_Trigger_RISING:  SET_BIT(EXTI->RTSR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);	break;
	case EXTI_Trigger_FALLING: SET_BIT(EXTI->FTSR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);	break;
	case EXTI_Trigger_ON_CHNAGE:
		SET_BIT(EXTI->RTSR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);
		SET_BIT(EXTI->FTSR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);
		break;
	default:
		// Error
		break;
	}

	// Set the callback function
	GP_IRQ_CallBack[EXTI_Config->EXTI_Pin.EXTI_Line_Num] = EXTI_Config->P_IRQ_CallBack;

	// Enable/Disable the interrupt & NVIC
	if(EXTI_Config->IRQ_Status == EXTI_STATUS_ENABLE){

		SET_BIT(EXTI->IMR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);

		NVIC_Enable(EXTI_Config->EXTI_Pin.EXTI_Line_Num);

	}
	else if(EXTI_Config->IRQ_Status == EXTI_STATUS_DISABLE){

		CLR_BIT(EXTI->IMR , EXTI_Config->EXTI_Pin.EXTI_Line_Num);
		NVIC_Disable(EXTI_Config->EXTI_Pin.EXTI_Line_Num);

	}
}

/**************************************************************************
 * Function         : void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
 * Description      : Initializes the EXTI (External Interrupt) for a GPIO pin.
 * Parameters (in)  : EXTI_Config - Pointer to the EXTI pin configuration structure
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config){

	UpdateFunction(EXTI_Config);
}

/**************************************************************************
 * Function         : void MCAL_EXTI_GPIO_DeInit(void)
 * Description      : DeInitializes the EXTI (External Interrupt) configuration for GPIO pins.
 * Parameters (in)  : None
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_EXTI_GPIO_DeInit(void){

	// Disable all EXTI interrupts
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;

	// Clear all EXTI trigger settings
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;

	// Clear EXTI software interrupt event register
	EXTI->SWIER = 0x00000000;

	// Clear EXTI pending register
	EXTI->PR = 0xFFFFFFFF;		// This bit is cleared by writing a ‘1’ into the bit

	// Disable EXTI IRQ from NVIC for each EXTI line
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ5_9_EXTI4_Disable();
	NVIC_IRQ10_15_EXTI4_Disable();

}

/**************************************************************************
 * Function         : void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
 * Description      : Updates the EXTI (External Interrupt) configuration for a GPIO pin.
 * Parameters (in)  : EXTI_Config - Pointer to the EXTI pin configuration structure
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config){

	UpdateFunction(EXTI_Config);
}

/*=========================================================================================================================================*/
// 														ISR Functions
/*=========================================================================================================================================*/

// EXTI Line0 interrupt
void EXTI0_IRQHandler (void){

	// Clear the flag by writing 1
	SET_BIT(EXTI->PR , EXTI0);

	GP_IRQ_CallBack[EXTI0]();
}

// EXTI Line1 interrupt
void EXTI1_IRQHandler (void){

	// Clear the flag by writing 1
	SET_BIT(EXTI->PR , EXTI1);

	GP_IRQ_CallBack[EXTI1]();
}

// EXTI Line2 interrupt
void EXTI2_IRQHandler (void){

	// Clear the flag by writing 1
	SET_BIT(EXTI->PR , EXTI2);

	GP_IRQ_CallBack[EXTI2]();
}

// EXTI Line3 interrupt
void EXTI3_IRQHandler (void){

	// Clear the flag by writing 1
	SET_BIT(EXTI->PR , EXTI3);

	GP_IRQ_CallBack[EXTI3]();
}

// EXTI Line4 interrupt
void EXTI4_IRQHandler (void){

	// Clear the flag by writing 1
	SET_BIT(EXTI->PR , EXTI4);

	GP_IRQ_CallBack[EXTI4]();
}

// EXTI Line[9:5] interrupts
void EXTI9_5_IRQHandler (void){

	// Clear the flag by writing 1 and execute the corresponding function
	if(GET_BIT(EXTI->PR , EXTI5)) { SET_BIT(EXTI->PR , EXTI5);     GP_IRQ_CallBack[EXTI5](); }
	if(GET_BIT(EXTI->PR , EXTI6)) { SET_BIT(EXTI->PR , EXTI6);     GP_IRQ_CallBack[EXTI6](); }
	if(GET_BIT(EXTI->PR , EXTI7)) { SET_BIT(EXTI->PR , EXTI7);     GP_IRQ_CallBack[EXTI7](); }
	if(GET_BIT(EXTI->PR , EXTI8)) { SET_BIT(EXTI->PR , EXTI8);     GP_IRQ_CallBack[EXTI8](); }
	if(GET_BIT(EXTI->PR , EXTI9)) { SET_BIT(EXTI->PR , EXTI9);     GP_IRQ_CallBack[EXTI9](); }

}

// EXTI Line[15:10] interrupts
void EXTI15_10_IRQHandler(void){
	// Clear the flag by writing 1 and execute the corresponding function
	if(GET_BIT(EXTI->PR , EXTI10)) { SET_BIT(EXTI->PR , EXTI10);   GP_IRQ_CallBack[EXTI10](); }
	if(GET_BIT(EXTI->PR , EXTI11)) { SET_BIT(EXTI->PR , EXTI11);   GP_IRQ_CallBack[EXTI11](); }
	if(GET_BIT(EXTI->PR , EXTI12)) { SET_BIT(EXTI->PR , EXTI12);   GP_IRQ_CallBack[EXTI12](); }
	if(GET_BIT(EXTI->PR , EXTI13)) { SET_BIT(EXTI->PR , EXTI13);   GP_IRQ_CallBack[EXTI13](); }
	if(GET_BIT(EXTI->PR , EXTI14)) { SET_BIT(EXTI->PR , EXTI14);   GP_IRQ_CallBack[EXTI14](); }
	if(GET_BIT(EXTI->PR , EXTI15)) { SET_BIT(EXTI->PR , EXTI15);   GP_IRQ_CallBack[EXTI15](); }
}
