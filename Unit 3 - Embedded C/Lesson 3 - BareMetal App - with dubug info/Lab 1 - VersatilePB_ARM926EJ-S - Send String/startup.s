/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/* Startup VersatilePB platform, that contains an ARM926EJ-S  */
/**************************************************************/
/**************************************************************/

.global reset
reset:
	ldr sp, = stack_top	
	bl main				
stop: b stop
