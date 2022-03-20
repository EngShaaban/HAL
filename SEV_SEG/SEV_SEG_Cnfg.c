/*
 * SEV_SEG_Cnfg.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Shaban
 */

/****************************************************************************/
/******************************  INCLUDES  **********************************/

#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\STD_TYPES.h"
#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\errorStates.h"

#include "E:\NTI\AVR\ATmeg16_Drivers\MCAL\DIO\DIO_interface.h"

#include "SEV_SEG_Priv.h"
#include "SEV_SEG_Cnfg.h"





/*****************************************************************************/
/** Macro name :    SEG_X_PIN  and  SEG_X_PORT.                              */
/*                  Hint: X can be A,B,C,D,E,F, or G .                       */
/*				                                                             */
/** Description:    Array of type SEG_t structure where each one of          */
/*                  of theme Configure one seven segment.                    */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/** Options   :    SEG_u8Type ----> to config. the type of 7-seg.            */
/*                              |                                            */
/*                              +-> range  COMMON_ANODE or COMMON_CATHODE    */
/*                                                                           */
/*                                                                           */
/*            :     SEG_u8Legx_Port ----> to Pacify the port of leg_x .      */
/*                                  |                                        */
/*                                  +-> range  DIO_PORTA  ,   DIO_PORTC      */
/*                                             DIO_PORTB  ,   DIO_PORTD      */
/*                                                                           */
/*            :     SEG_u8LegB_Pin ----> to Pacify the pin of leg_x .        */
/*                                  |                                        */
/*                                  +-> range  DIO_PIN0     ,     DIO_PIN4   */
/*                                             DIO_PIN1     ,     DIO_PIN5   */
/*                                             DIO_PIN2     ,     DIO_PIN6   */
/*                                             DIO_PIN3     ,     DIO_PIN7   */
/*                                                                           */
/*                                                                           */
/*  Hint:          You can disconnect                                        */
/*                                                                           */
/*                          SEG_u8LegCMN_Port   ,   SEG_u8LegCMN_Pin         */
/*                          SEG_u8LegDot_Port  and  SEG_u8LegDot_Pin         */
/*                                                                           */
/*                    if you configure theme as:  NOT_CONNECTED              */
/* 			                                                                 */
/*****************************************************************************/
SEG_t SevenSegment_AstrSegCnfg[SEG_NUM]=
{
		/********************************************
		 * Seg. Num_1
		 ********************************************/
		{
				.SEG_u8Type       =    COMMON_ANODE   ,

				.SEG_u8LegA_Port  =    DIO_PORTA      ,
				.SEG_u8LegA_Pin   =    DIO_PIN0       ,

				.SEG_u8LegB_Port  =    DIO_PORTA      ,
				.SEG_u8LegB_Pin   =    DIO_PIN1       ,

				.SEG_u8LegC_Port  =    DIO_PORTA      ,
				.SEG_u8LegC_Pin   =    DIO_PIN2       ,

				.SEG_u8LegD_Port   =   DIO_PORTA      ,
				.SEG_u8LegD_Pin    =   DIO_PIN3       ,

				.SEG_u8LegE_Port  =    DIO_PORTA      ,
				.SEG_u8LegE_Pin   =    DIO_PIN4       ,

				.SEG_u8LegF_Port  =    DIO_PORTA      ,
				.SEG_u8LegF_Pin   =    DIO_PIN5       ,

				.SEG_u8LegG_Port  =    DIO_PORTA      ,
				.SEG_u8LegG_Pin   =    DIO_PIN6       ,

				.SEG_u8LegCMN_Port=    DIO_PORTA      ,
				.SEG_u8LegCMN_Pin =    DIO_PIN7       ,

                .SEG_u8LegDot_Port=    DIO_PORTB      ,
                .SEG_u8LegDot_Pin =    DIO_PIN0

		} // End of Segment num.1 configuration.

};


// Common Cathode.
u8 SEG_Au8NumDisplay[10]= {
		0x3f, 0x06, 0x5B,
		0x4F, 0x66, 0x6D,
		0x7D, 0x07, 0x7F,
		0x6F};


/******************************* END OF FILE. ***********************************/
/********************************************************************************/
