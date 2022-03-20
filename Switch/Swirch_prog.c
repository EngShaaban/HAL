/*****************************************************************************/
/* Title                 :   Switch_prog                                     */
/* Filename              :   Switch_prog.c                                   */
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

/****************************************************************************/
/****************************************************************************/
/* Function Name   : Switch_enuInit.                                        */
/* Description     : Utility function to initialize the array of switches.  */
/* Argument        : Address array of type SW_t.                            */
/* Return          : Error state of type ES_t.                              */
/*.................**********************************************************/
ES_t Switch_enuInit(SW_t* Copy_pstrSwitchs)
{
	ES_t Local_enuErrorState = ES_NOK ;

	u8 Local_u8Iterator ;

	if( Copy_pstrSwitchs != NULL   )
	{
		for (Local_u8Iterator = 0 ; Local_u8Iterator < SW_NUM ; Local_u8Iterator++ )
		{

			Local_enuErrorState = DIO_enuSetPinDirection( Copy_pstrSwitchs[Local_u8Iterator].SW_PortID ,
					Copy_pstrSwitchs[Local_u8Iterator].SW_PinID ,
					DIO_INPTU_PIN);

			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrSwitchs[Local_u8Iterator].SW_PortID ,
					Copy_pstrSwitchs[Local_u8Iterator].SW_PinID ,
					Copy_pstrSwitchs[Local_u8Iterator].SW_Status);

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER ;
	}
	return Local_enuErrorState ;
}//End of Switch_enuInit.


/***************************************************************************/
/***************************************************************************/
/*Function Name   : Swithc_enuGetState.                                    */
/*Description     : Utility function to get the Switch state.              */
/*Argument        : Arg_1:  Address of the Switch that you want to         */
/*                  =====   get its Status.                                */
/*                                                                         */
/*                          Example:                                       */
/*                                                                         */
/*                              &Switch_AstrSwitchState[0] --->for switch0 */
/*                              &Switch_AstrSwitchState[1] --->for switch1 */
/*                              &Switch_AstrSwitchState[2] --->for switch2 */
/*                                          .                      .       */
/*                                          .                      .       */
/*                                          .                      .       */
/*                                                                         */
/*                : Arg_2: Address Variable of type u8.                    */
/*                  =====                                                  */
/*                            Example:                                     */
/*                                    &switch0  --->for switch0            */
/*                                    &switch1  --->for switch1            */
/*                                       .               .                 */
/*                                       .               .                 */
/*                                                                         */
/* Return          : Error state of type ES_t.                             */
/*..........................************************************************/
ES_t Switch_enuGetState(SW_t* Copy_pstrSwitchs , u8* Copy_pu8SwState)
{
	ES_t Local_enuErrorState = ES_NOK ;

	if( (Copy_pstrSwitchs != NULL) && (Copy_pu8SwState != NULL))
	{
		u8 Local_u8Connection = Copy_pstrSwitchs->SW_Status ;
		u8 Local_u8SwPinread = 0;

		if( Local_u8Connection == DIO_PULL_UP_PIN )
		{
			DIO_enuGetPinVlaue( Copy_pstrSwitchs->SW_PortID ,Copy_pstrSwitchs->SW_PinID , &Local_u8SwPinread);

			if ( Local_u8SwPinread )
			{
				//released .
				*Copy_pu8SwState  =  SW_RELEASED ;
			}
			else
			{
				//pressed.
				*Copy_pu8SwState  =  SW_PRESSED ;
			}



		}
		else
		{
			DIO_enuGetPinVlaue( Copy_pstrSwitchs->SW_PortID ,Copy_pstrSwitchs->SW_PinID , &Local_u8SwPinread);

			if ( Local_u8SwPinread )
			{
				// pressed  .
				*Copy_pu8SwState  =  SW_PRESSED ;
			}
			else
			{
				//released.
				*Copy_pu8SwState  =  SW_RELEASED ;
			}
			Local_enuErrorState = ES_OK ;

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER ;
	}


	return Local_enuErrorState ;
}//End of Swithc_enuGetState.

/******************************* END OF FILE. ***********************************/
/********************************************************************************/

