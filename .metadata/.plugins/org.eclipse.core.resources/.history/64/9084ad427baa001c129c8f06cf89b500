/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: SHAABAN
 */

#include "LIB/STD_TYPES.h"
#include "LIB/errorStates.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL\USART\UART_Interface.h"


#include "GPS_Cnfg.h"
#include "GPS_Interface.h"


f32 var1 ;
f32 var2 ;

u8 lat;
u8 lon;

int main(void)
{

	GPS_enuInit();

	//int i = 3 ;

	UART_enuSendByte('M');
	UART_enuSendByte('a');
	UART_enuSendByte('i');
	UART_enuSendByte('n');

	GPS_enuGetLocation(&var1 , &var2 , &lat , &lon );


	while(1)
	{
		//ES_t GPS_enuGetLocation(f32* Copy_pf32Lat , f32* Copy_pf32Long , u8 Copy_pu8LatDir , u8 Copy_pu8LongDir );

		//GPS_enuGetLocation(&var1 , &var2 , &lat , &lon );
		UART_enuSendByte(' ');
		UART_enuSendByte(' ');
		UART_enuSendByte('w');
		UART_enuSendByte('h');
		UART_enuSendByte('i');
		UART_enuSendByte('l');
		UART_enuSendByte('e');
		UART_enuSendByte('(');
		UART_enuSendByte('1');
		UART_enuSendByte(')');
		(*(u8*)0x33)= lat;
		(*(u8*)0x36)= lon;

		(*(u8*)0x53)= (u8)var1;
		(*(u8*)0x52)= (u8)var2;

		while(1)
		{
			//Stay here.

		}



	}

	return 0 ;
}


