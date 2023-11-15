



## ***Name List (nm) for the Project***

**HighPressureDetectionSystem.elf**
	   
		Symbol							After Linking	Before Linking
	    B _E_BSS                          20000001							
        B _E_DATA                         20000000
        T _E_text                         080002d4
        B _S_BSS                          20000000
        B _S_DATA                         20000000
        B _stack_top                      20001004
        B Alarm_Flag                      20000000			00000000				
        T AlarmActuator_Init              0800001c			00000000
        T AlarmActuator_SetAlarm          08000040			00000024
        W Bus_fault                       08000210			00000000
        T CheckPressureValue              08000094			00000000
        T Default_Handler                 08000210			00000000
        T Delay                           08000100			00000000
        T GPIO_Init                       08000124			00000000
        W H_fault_Handler                 08000210			00000000
        T main                            080001a4			00000000
        W MM_fault_Handler                08000210			00000000
        W NMI_Handler                     08000210			00000000
        T PressureSensor_GetPressureValue 080001dc			00000010
        T PressureSensor_Init             080001cc			00000000			
        T Reset_Handler                   0800021c			0000000c
        W Usage_fault_Handler             08000210			00000000
        T vectors                         08000000			00000000

**We can see that addresses have been changed after linking**

