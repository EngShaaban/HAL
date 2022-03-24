/*
 * main.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Shaban
 */


#include "STD_TYPES.h"
#include "errorStates.h"

#include "MCAL\DIO_interface.h"

#include "LCD_Cnfg.h"
#include "LCD_interface.h"

#ifndef F_CPU
#define F-CPU  16000000UL
#endif

int main(void)
{
	LCD_enuInit( LCD_AstrLcdCnfg );

	while(1)
	{


	}

}
