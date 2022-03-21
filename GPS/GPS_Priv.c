/*
 * GPS_Priv.c
 *
 *  Created on: Mar 15, 2022
 *      Author: SHAABAN
 */


#include "LIB/STD_TYPES.h"
#include "LIB/errorStates.h"


#include "GPS_Cnfg.h"
#include "GPS_Priv.h"


//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72

inline void   GPS_inlinevidAsciiToInt( u8 const* GPS_constu8_Buffer , f32* Copy_pf32Lat , f32* Copy_pf32Long   )
{
	u8 Local_u8Counter ;

	u8 Local_u8_Subs_Of_First_Comma   = 0  ;
	u8 Local_u8_Subs_Of_Second_Comma  = 0  ;
	u8 Local_u8_Subs_Of_Third_Comma   = 0  ;
	u8 Local_u8_Subs_Of_Fourth_Comma  = 0  ;


	u16 Local_u16IntPortion= 0 ;

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//  |
	while( *GPS_constu8_Buffer != ',' )
	{
		GPS_constu8_Buffer++;
		Local_u8Counter++	;
	}
	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//              |
	//Count:        10

	Local_u8_Subs_Of_First_Comma = Local_u8Counter ;
	GPS_constu8_Buffer++;
	Local_u8Counter++	;
	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                  |
	//Count:           11
	while( *GPS_constu8_Buffer != ',' )
	{
		GPS_constu8_Buffer++;
		Local_u8Counter++	;

	}
	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                                 |
	//Count:                           20
	Local_u8_Subs_Of_Second_Comma = Local_u8Counter	;
	GPS_constu8_Buffer++;
	Local_u8Counter++	;

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                                     |
	//Count:                               21


	while( *GPS_constu8_Buffer != ',' )
	{
		GPS_constu8_Buffer++;
		Local_u8Counter++	;
	}

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                                        |
	//Count:                                  21


	Local_u8_Subs_Of_Third_Comma = Local_u8Counter	;
	GPS_constu8_Buffer++;
	Local_u8Counter++	;

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                                            |
	//Count:                                      23

	while( *GPS_constu8_Buffer != ',' )
	{
		GPS_constu8_Buffer++;
		Local_u8Counter++	;
	}


	Local_u8Counter++;

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                                                           |
	//Count:                                                     34

	Local_u8_Subs_Of_Fourth_Comma = Local_u8Counter	;

	// We all Set .

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//              |                  |      |               |
	//Comma's#:     1                  2      3               4

	//	Local_u8_Subs_Of_First_Comma
	//	Local_u8_Subs_Of_Second_Comma
	//	Local_u8_Subs_Of_Third_Comma
	//	Local_u8_Subs_Of_Fourth_Comma



	Local_u8_Subs_Of_First_Comma++;

	do
	{
		// 5404.2675
		// |


		Local_u16IntPortion += GPS_constu8_Buffer[Local_u8_Subs_Of_First_Comma];
		//iter_#1      		0+5=5
		//iter_#2           5
		//iter_#3
		//iter_#4
		//iter_#5
		//iter_#6
		//iter_#7
		//iter_#

		Local_u8_Subs_Of_First_Comma++;


	}while(GPS_constu8_Buffer[Local_u8_Subs_Of_First_Comma] != '.');





}//End of GPS_inlinevidAsciiToInt().


