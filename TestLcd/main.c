/*
 * main.c
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "LCD_int.h"

#include "util/delay.h"

int main (void)
{

	/**
	u8 name []={ 0x07,0x04,0x1F,0x00,0x04,0x04,0x04,0x00,
			0x00,0x06,0x01,0x01,0x1E,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x1F,0x0A,0x04,0x00,
			0x00,0x00,0x04,0x04,0x1F, 0x00,0x00,0x00};
			*/



	LCD_enuInit();

	LCD_enuDisplayChar('S');
	LCD_enuDisplayChar('h');
	LCD_enuDisplayChar('a');
	LCD_enuDisplayChar('b');
	LCD_enuDisplayChar('a');
	LCD_enuDisplayChar('n');
	LCD_enuDisplayChar(' ');LCD_enuDisplayChar('S');


	while (1)
	{



	}
	return 0;
}
