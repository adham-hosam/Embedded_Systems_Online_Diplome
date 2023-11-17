
# Mastering Embedded System Online Diploma      		 	High Pressure Detection System

## Project Overview

**Project Title:** High Pressure Detection System

**Author:**  Adham Hossam

**My Profile**: [adhamhosam9@gmail.com (learn-in-depth-store.com)](https://www.learn-in-depth-store.com/certificate/adhamhosam9%40gmail.com)

## Project Description

The High Pressure Detection System is a hardware-based solution designed to monitor and detect high-pressure conditions in a controlled environment. The primary goal of this system is to ensure the safety and integrity of equipment or processes sensitive to elevated pressure levels. The system utilizes a combination of sensors, actuators, and algorithms to effectively identify and respond to instances where pressure exceeds a predefined threshold.

## File Structure
The High Pressure Detection System project adopts a well-organized, layered architecture for enhanced modularity and maintainability. Here is a breakdown of the project structure based on different layers:
1.  **MCAL (Microcontroller Abstraction Layer):**
    
    -   **GPIO (General-Purpose Input/Output):**
        -   **File:** `GPIO.c`, `GPIO.h`
        -   **Description:** Manages the initialization and control of GPIO pins for interfacing with hardware.
2.  **HAL (Hardware Abstraction Layer):**
    -   **PressureSensor:**
        -   **File:** `PressureSenesor.c`, `PressureSenesor.h`
        -   **Description:** Simulates the functionality of a pressure sensor and provides an abstraction layer for higher-level modules.
    -   **AlarmActuator:**
        -   **File:** `AlarmActuator.c`, `AlarmActuator.h`
        -   **Description:** Defines the initialization and control functions for the alarm actuator, abstracting the underlying hardware details.
3.  **APP (Application Layer):**
    -   **Algorithm:**
        -   **File:** `Algorithm.c`, `Algorithm.h`
        -   **Description:** Implements the core algorithm for checking pressure values and triggering the alarm based on specified thresholds.
4.  **LIB (Library):**
    -   **Platform_Types:**
        -   **File:** `Platform_Types.h`
        -   **Description:** Defines platform-specific data types.
    -   **BIT_MATH:**
        -   **File:** `BIT_MATH.h`
        -   **Description:** Includes macros for bitwise operations.
    -   **Delay:**
        -   **File:** `Delay.c`	`Delay.h`
        -   **Description:** Implements delay functions, facilitating time-related operations.

## Build Instructions

I embarked on the journey of creating a High-Pressure Detection System entirely from the ground up, embracing the challenges and opportunities of bare-metal programming.Here's a brief overview of the process:

**1. Startup and Linker Files:**
The startup and linker files, `startup.s` and `linker_script.ld` respectively, were meticulously crafted to define the memory layout, initialization routines, and linking details for the microcontroller.

**2.Makefile Creation:**
A custom Makefile was engineered to automate the build process. This Makefile orchestrated the compilation of source code, linking, and generation of binary and hex files.

**3.Toolchain Configuration:**
The arm-none-eabi toolchain was selected for its compatibility with ARM-based microcontrollers. Configurations were tailored to match the specific needs of the project.

## System Architecting/Design Sequence
**1. System Analysis:**
-   **Purpose:**
    -   Provide a comprehensive understanding of the High Pressure Detection System's architecture and components.

 **2. Block Diagram:**
-   **Purpose:**
    -   Offer a visual representation of the functional blocks within the High Pressure Detection System.

**3. Sequence Diagram:**
-   **Purpose:**
    -   Illustrate the temporal sequence of interactions between various components during different scenarios.

**4.Activity Diagram:**
-   **Purpose:**
    -   Model the workflow and processes within the High Pressure Detection System.
