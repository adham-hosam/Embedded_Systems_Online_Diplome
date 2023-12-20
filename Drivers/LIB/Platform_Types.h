/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  LIBRARY				***************/
/**************									***************/
/**************************************************************/
/**************************************************************/

/*The platform types for ARM Cortex A53 in Little Endian could have the following mapping to the ANSI C types:*/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


		/* Symbols */
#define CPU_TYPE CPU_TYPE_64
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST

		/* Types */
typedef unsigned char 		boolean;
typedef unsigned char 		uint8;
typedef unsigned short		uint16;
typedef unsigned int 		uint32;
typedef unsigned long long 	uint64;
typedef signed char 		sint8;
typedef signed short 		sint16;
typedef signed int 			sint32;
typedef signed long long 	sint64;
typedef unsigned int 		uint8_least;

typedef volatile unsigned int 		V_uint32;


typedef unsigned int 		uint16_least;
typedef unsigned int 		uint32_least;
typedef signed int 			sint8_least;
typedef signed int 			sint16_least;
typedef signed int 			sint32_least;
typedef float 				float32;
typedef double 				float64;

#define DISABLE	0
#define ENABLE	1

#define Low		0
#define High	1

#define NULL ((void *)0)


#endif /*PLATFORM_TYPES_H_*/
