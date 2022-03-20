/*
 * main.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Shaban
 */

#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\STD_TYPES.h"
#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\errorStates.h"

#include "E:\NTI\AVR\ATmeg16_Drivers\MCAL\DIO\DIO_interface.h"




#include"Seven_Segment_interface.h"
#include"Seven_Segment_Cnfg.h"



#include<util/delay.h>

int main(void)
{
	Seven_Segment_enuInit();
	while(1)
	{
		for(u8 i = 0 ; i<10 ; i++ )
		{

			Seven_Segment_enuDisplayNum(i);
			_delay_ms(500);
		}
	}

}


