#include <stdio.h>

#define 	Debug_Enable 	1
						
#define DPRINTF(debug_level , ...)	if(Debug_Enable) { \
									if( debug_level > 1 ) \
										printf("@Func: %s\t,File: %s ,Line\t: %d" , __func__ , __FILE__ , __LINE__); \
									printf(">>\t"); \
									printf(__VA_ARGS__); }

void Can_Init(){
		
		DPRINTF(3,"\n");
		
}
	
void Can_Send(){
		
		DPRINTF(3,"\n");
}
									
int main(){
	
	DPRINTF(1,"Enter main\n");
	Can_Init();
	DPRINTF(3,"\n");
	Can_Send();
	DPRINTF(1,"Exit main\n");
	
	return 0;
}
/********************************************************
>>      Enter main
@Func: Can_Init ,File: Debug_Levels.c ,Line     : 13>>
@Func: main     ,File: Debug_Levels.c ,Line     : 26>>
@Func: Can_Send ,File: Debug_Levels.c ,Line     : 19>>
>>      Exit main
********************************************************/