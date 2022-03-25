/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: SHAABAN
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/errorStates.h"


#include "../HAL/LCD/EF_LCD.h"
#include "../HAL/GPS_Cnfg.h"
#include "../HAL/GPS_Interface.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/USART\UART_Interface.h"



f32 Lat ;
f32 Long ;

u8 latDir;
u8 longDir;

s32   ch  = 'H';


int main(void)
{


	EF_void_LCD_init();

	GPS_enuInit();

	EF_void_LCD_goto(1 , 1);






	UART_enuSendByte('M');
	UART_enuSendByte('a');
	UART_enuSendByte('i');
	UART_enuSendByte('n');


//EF_void_LCD_print_NUM(s32 s16Numberstring,u8 u8RowNumber);
	EF_void_LCD_print_NUM( ch , 1 );

	GPS_enuGetLocation(&Lat , &Long , &latDir , &longDir );


	//f32 Lat ;

	EF_void_LCD_print_NUM( Lat , 1 );



	while(1)
	{
		//ES_t GPS_enuGetLocation(f32* Copy_pf32Lat , f32* Copy_pf32Long , u8 Copy_pu8LatDir , u8 Copy_pu8LongDir );

		//GPS_enuGetLocation(&var1 , &var2 , &lat , &lon );
		UART_enuSendByte(' ');
		UART_enuSendByte(' ');
		UART_enuSendByte('I');
		UART_enuSendByte(' ');
		UART_enuSendByte('a');
		UART_enuSendByte('m');
		UART_enuSendByte(' ');
		UART_enuSendByte('i');
		UART_enuSendByte('n');
		UART_enuSendByte(' ');
		UART_enuSendByte('w');
		UART_enuSendByte('h');
		UART_enuSendByte('i');
		UART_enuSendByte('l');
		UART_enuSendByte('e');
		UART_enuSendByte('(');
		UART_enuSendByte('1');
		UART_enuSendByte(')');



		while(1)
		{
			//Stay here.


		}



	}

	return 0 ;
}


