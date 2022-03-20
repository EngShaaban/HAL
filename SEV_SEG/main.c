/*
 * MAIN.C
 *
 *  Created on: Oct 5, 2021
 *      Author: Shaban
 */

#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\STD_TYPES.h"
#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\errorStates.h"

#include "E:\NTI\AVR\ATmeg16_Drivers\MCAL\DIO\DIO_interface.h"

#include "SEV_SEG_Cnfg.h"
#include "SEV_SEG_Interface.h"

#include<util/delay.h>
int main(void)
{
	Seven_Segment_enuInit(SevenSegment_AstrSegCnfg);
	while(1)
	{


		//Seven_Segment_enuDisplayNum(&SevenSegment_AstrSegCnfg[0],9);

		for(int i = 0 ; i <10  ; i++ )
		{
			_delay_ms(1000);
			Seven_Segment_enuDisplayNum(&SevenSegment_AstrSegCnfg[0] , i);
			if(i == 9 )
			{
				for(int j = 9 ;j>=0 ; j--)
				{
					_delay_ms(1000);
					Seven_Segment_enuDisplayNum(&SevenSegment_AstrSegCnfg[0] , j);
				}
			}
		}




	}

}



