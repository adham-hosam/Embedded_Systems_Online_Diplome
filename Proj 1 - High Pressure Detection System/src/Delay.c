/*
 * Delay.c
 *
 *  Created on: Nov 15, 2023
 *      Author: adham
 */

#include "Delay.h"

/* Busy waiting function*/
void Delay(uint32 nCount)
{
	for(; nCount != 0; nCount--);
}
