#include "Platform_Types.h"

#include "STM.h"
#include "EXTI.h"


int main(void)
{
	RCC_Init();

	// Configure GPIOA -Pin 13 as output
	GPIO_Init();

	// Configure pin A0 as external input
	EXRI0_Init();

	while(1);


}


void EXTI0_IRQHandler(void){

	/* Interrupt has happened  EXTI0 >> PORTA Pin 0 as rising edge */

	// Toggle LED
	LED_Status(LED_TOGGLE);

	// Clear the pending request for line0 by writing 1
	EXTI_PR |= (1<<0);

}
