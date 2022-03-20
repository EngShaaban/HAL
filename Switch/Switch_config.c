/*****************************************************************************/
/* Title                 :   Switch_config                                   */
/* Filename              :   Switch_config.c                                 */
/* Author                :   Shaban Abdullah Awad                            */
/* Origin Date           :   Oct 2, 2021                                     */
/* Version               :   1.0.0                                           */
/* Compiler              :   mingw GCC                                       */
/* Target                :   ATmega16 , ATmega32                             */
/* Notes                 :   None                                            */
/*                                                                           */
/*****************************************************************************/

/****************************************************************************/
/******************************  INCLUDES  **********************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "../../MCAL/DIO/DIO_interface.h"


/******************************************************************************/
/******************************************************************************/
/* Description   : Array of SW_t type Structures to config. switches in Sys.  */
/*                 by writing PortID :                                        */
/*                                     DIO_PORTA    ,   DIO_PORTC             */
/*                                     DIO_PORTB    ,   DIO_PORTD             */
/*                 and PinID:                                                 */
/*                                     DIO_PIN0      ,     DIO_PIN4           */
/*                                     DIO_PIN1      ,     DIO_PIN5           */
/*                                     DIO_PIN2      ,     DIO_PIN6           */
/*                                     DIO_PIN3      ,     DIO_PIN7           */
/*                                                                            */
/*                and Connection Method:                                      */
/*                                     DIO_PULL_UP_PIN  , DIO_FLOAT_PIN       */
/*                                                                            */
/*                                                                            */
/***...................................****************************************/
SW_t  Switch_AstrSwitchState[SW_NUM]=
{
		{DIO_PORTB , DIO_PIN0 , DIO_PULL_UP_PIN},  /* Switch_0 Configuration*/
		//{DIO_PORTB , DIO_PIN1 , DIO_FLOAT_PIN  },  /* Switch_1 Configuration*/
		//{DIO_PORTB , DIO_PIN2 ,DIO_PULL_UP_PIN } /* Switch_2 Configuration*/
};



/******************************* END OF FILE. ***********************************/
/********************************************************************************/


