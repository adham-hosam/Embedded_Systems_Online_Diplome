/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  APP					***************/
/**************		SWC: 	main.c				***************/
/**************************************************************/
/**************************************************************/


#include "Stm32f103x6.h"
#include "Stm32f103x6_GPIO_Driver.h"
#include "Stm32f103x6_EXTI_Driver.h"

#include "Led.h"
#include "LCD.h"

#include "KeyPad.h"


int Flag = 1;

void GPIO_Init();

void EXTI_Init();

void busyWait(int iterations);

void EXTI9_CallBack(void){

	Flag = 1;

	LCD_SendString("IRQ EXTI9 happened: Falling Edge");

	busyWait(1000);


}


int main(void)
{

	GPIOA_CLK_EN();
	GPIOB_CLK_EN();
	AFIO_CLK_EN();

	//GPIO_Init();



	EXTI_Init();

	LCD_Init();

	while(1){

		if(Flag == 1){
			LCD_ClearScreen();
			Flag = 0;
		}

	}


}

void EXTI_Init(){

	EXTI_PinConfig_t EXTI_Config;
	EXTI_Config.EXTI_Pin = EXTI9PB9;
	EXTI_Config.Trigger_Case = EXTI_Trigger_FALLING;
	EXTI_Config.P_IRQ_CallBack = EXTI9_CallBack;
	EXTI_Config.IRQ_Status = EXTI_STATUS_ENABLE;

	MCAL_EXTI_GPIO_Init(&EXTI_Config);

}

void GPIO_Init(){

	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_PIN = GPIO_PIN0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	// Led Initially off
	LED_Status(GPIOA, GPIO_PIN0, LedStatus_LED_OFF);

}

void busyWait(int iterations) {
	for (int i = 0; i < iterations; ++i) {
		// Perform some dummy operations to simulate busy waiting
		for (int j = 0; j < 255; ++j) {
			// Do nothing, just waste time
		}
	}
}
