

## ***Name List (nm) for the Project***

**HighPressureDetectionSystem.elf**
   
	    20000001 B _E_BSS
        20000000 B _E_DATA
        080002d4 T _E_text
        20000000 B _S_BSS
        20000000 B _S_DATA
        20001004 B _stack_top
        20000000 B Alarm_Flag
        0800001c T AlarmActuator_Init
        08000040 T AlarmActuator_SetAlarm
        08000210 W Bus_fault
        08000094 T CheckPressureValue
        08000210 T Default_Handler
        08000100 T Delay
        08000124 T GPIO_Init
        08000210 W H_fault_Handler
        080001a4 T main
        08000210 W MM_fault_Handler
        08000210 W NMI_Handler
        080001dc T PressureSensor_GetPressureValue
        080001cc T PressureSensor_Init
        0800021c T Reset_Handler
        08000210 W Usage_fault_Handler
        08000000 T vectors

**We can see that addresses have been changed after linking**

