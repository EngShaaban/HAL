/*
 * GPS_Priv.c
 *
 *  Created on: Mar 15, 2022
 *      Author: SHAABAN
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include "GPS_Cnfg.h"
#include "GPS_Priv.h"


/*=================================================================*/
/*=================== For Testing purposes ========================*/
#include "../../HAL/LED/Led_config.h"
#include "../../HAL/LED/Led_interface.h"
#include "../../MCAL\USART\UART_Interface.h"
#include"../../MCAL/DIO/DIO_interface.h"
/*====================================================*/

//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
//
//inline void GPS_inlinevidAsciiToInt(const u8* GPS_constu8_Buffer , f32** Copy_pf32Lat , f32** Copy_pf32Long , u8** Copy_pu8LatDir , u8** Copy_pu8LongDir  );



void GPS_inlinevidAsciiToInt(const u8* GPS_p2Constu8_DataBuffer , f32** Copy_pf32Lat , f32** Copy_pf32Long , u8** Copy_pu8LatDir , u8** Copy_pu8LongDir  )
{

	LED_enuLedON(&LED_AstrLedConfig[1]);

	f32 Local_f32TempLat  = 0 ;
	f32 Local_f32TempLong = 0 ;
	u8  Local_u8Temp      = 1 ;



	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                  |
	//P2Data:           11
	do
	{
		// 540 4.2675
		// |

		Local_f32TempLat *= 10;

		Local_f32TempLat += ((*(GPS_p2Constu8_DataBuffer)-0x30));

		//iter_#1      		0+5 = 5
		//iter_#2          50+4 = 54
		//iter_#3         540+0 = 540
		//iter_#4        5400+4 = 5404

		GPS_p2Constu8_DataBuffer++;

	}while( (*GPS_p2Constu8_DataBuffer) != '.');

	/*=================================================*/
	/*=================================================*/

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                        |
	//P2Data:

	GPS_p2Constu8_DataBuffer++;

	//  0.........  10  ....  15 ....  20  .  22  .......... 33  .  35  .............................
	//  043338.100  ,   5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//                           |
	//P2Data:                    21

	do
	{
		// 5404.2675,
		//      |
		Local_u8Temp *= 10 ;

		Local_f32TempLat += ((f32)(*(GPS_p2Constu8_DataBuffer)-0x30)/Local_u8Temp);



		//iter_#1  Local_f32TempLat=   5404 + 0.2=  5404.2
		//iter_#2  Local_f32TempLat=   5404.2 + 0.06=  5404.26
		//iter_#3                      5404.26 + 0.007=  5404.267
		//iter_#4                      5404.267 + 0.0005=  5404.2675


		GPS_p2Constu8_DataBuffer++;


	}while( *(GPS_p2Constu8_DataBuffer) != ',');


	//  5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//  P2Data:        |
	//

	GPS_p2Constu8_DataBuffer++;

	//  5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//  P2Data:            |

	**Copy_pu8LatDir = *GPS_p2Constu8_DataBuffer ;

	GPS_p2Constu8_DataBuffer++;

	//  5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
	//  P2Data:               |


	GPS_p2Constu8_DataBuffer++;

	//  5404  .  2675  ,   N  ,   00159.7569  ,  W  ,   1,10,4.00,100.0,M,50.0,M,,*72
    //  P2Data:                   |


	do
	{
		// 00159.7569
		// |

		Local_f32TempLong *= 10;

		Local_f32TempLong += ((f32)((*GPS_p2Constu8_DataBuffer)-0x30));

		//iter_#1          0 + 0 = 0
		//iter_#2          0 + 0 = 0
		//iter_#3          0 + 1 = 1
		//iter_#4         10 + 5 = 15
		//iter_#4        150 + 9 = 159

		GPS_p2Constu8_DataBuffer++;


	}while( (*GPS_p2Constu8_DataBuffer) != '.');


	// 00159.7569
	//      |
	GPS_p2Constu8_DataBuffer++;

	// 00159.7569
	//       |

	Local_u8Temp = 1 ;

	do
	{

		// 00159.7569,W
		//       |

		Local_u8Temp *= 10 ;

		Local_f32TempLong += (((f32)(*GPS_p2Constu8_DataBuffer)-0x30)/Local_u8Temp);


		//                                                          Local_u8Temp
		//iter_#1  Local_f32TempLat=   159 + 0.7=  159.7            10
		//iter_#2  Local_f32TempLat= 159.7+0.05 =  159.75           100
		//iter_#3                  159.75+0.006 =  159.756          1000
		//iter_#4                 159.756+0.0009 = 159.7569         10000                                   10000


		GPS_p2Constu8_DataBuffer++;


	}while( (*GPS_p2Constu8_DataBuffer) != ',');

	// 00159.7569,W
	//           |


	GPS_p2Constu8_DataBuffer++;
	// 00159.7569,W
	//            |

	**Copy_pu8LongDir = *GPS_p2Constu8_DataBuffer;

	**Copy_pf32Long   = Local_f32TempLong;
	**Copy_pf32Lat    = Local_f32TempLat ;

	LED_enuLedON(&LED_AstrLedConfig[2]);

}//End of GPS_inlinevidAsciiToInt().

/****************************************** END OF FILE. ********************************************/
/****************************************************************************************************/

