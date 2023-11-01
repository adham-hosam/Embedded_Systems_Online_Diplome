/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************									***************/
/**************									***************/
/**************************************************************/
/**************************************************************/

#ifndef PLATFORM_TYPES
#define  PLATFORM_TYPES

typedef unsigned char              u8   ;
typedef unsigned short int         u16  ;
typedef unsigned int               u32  ;
typedef unsigned long long int     u64  ;

typedef signed char                s8   ;
typedef signed short int           s16  ;
typedef signed int                 s32  ;
typedef signed long long int       s64  ;

typedef float                      f32  ;
typedef double 			 		   f64  ;
typedef long double                f80  ;

typedef volatile u8                vu8  ;  
typedef volatile u16               vu16 ;
typedef volatile u32               vu32 ;
typedef volatile u64               vu64 ;

typedef volatile s8                vs8  ;
typedef volatile s16               vs16 ;
typedef volatile s32               vs32 ;
typedef volatile s64               vs64 ;

#define NULL			0

#define OK 				0
#define NOK				1
#define NULL_POINTER	2

#endif
