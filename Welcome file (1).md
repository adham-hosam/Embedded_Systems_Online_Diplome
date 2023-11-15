


## ***Sections of objects files***

**PressureSensor.o:**

 1. **.text:**
    -   Size: 0x44 bytes
    -   VMA: 0x00000000
    -   LMA: 0x00000000
 2. **.data:**
     -   Size: 0 bytes
    -   VMA: 0x00000000
    -   LMA: 0x00000000

**Algorithm.o:**

	00000000 B Alarm_Flag
	00000000 T CheckPressureValue
             U AlarmActuator_SetAlarm
	00000000 T Delay

**AlarmActuator.o:**

	00000000 T AlarmActuator_Init
	00000024 T AlarmActuator_SetAlarm

In the above list:

-   "B" stands for uninitialized data section (BSS).
-   "T" stands for the text (code) section.
-   "U" means the symbol is undefined (typically a function or a variable that should be defined elsewhere).

