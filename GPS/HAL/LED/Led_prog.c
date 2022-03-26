/*****************************************************************************/
/* Title                 :   Led_prog                                     */
/* Filename              :   Led_prog.c                                   */
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
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"Led_priv.h"
#include"Led_config.h"




/****************************************************************************/
/* Function Name   : LED_enuInit.                                           */
/* Description     : Utility function to initialize the array of Leds.      */
/* Argument        : Address array of type LED_t.                            */
/* Return          : Error state of type ES_t.                              */
/****************************************************************************/
ES_t LED_enuInit( LED_t* Copy_pstrLedConfig )
{
	ES_t Local_enuErrorState = ES_NOK ;

	if( Copy_pstrLedConfig !=NULL)
	{
		u8 Local_u8Iterator = 0 ;

		for( Local_u8Iterator = 0 ; Local_u8Iterator  < LED_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection( Copy_pstrLedConfig[Local_u8Iterator].LED_PortID,
					Copy_pstrLedConfig[Local_u8Iterator].LED_PinID,
					DIO_OUTPUT_PIN);


			//LED_OFF Scenario Handling in tow Connection Cases  .
			if( Copy_pstrLedConfig[Local_u8Iterator].LED_Init_State == LED_OFF)
			{
				if(Copy_pstrLedConfig[Local_u8Iterator].LED_Connection_Style == LED_SINK )
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrLedConfig[Local_u8Iterator].LED_PinID,DIO_HIGH);
				}
				else if (Copy_pstrLedConfig[Local_u8Iterator].LED_Connection_Style == LED_SOURCE)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrLedConfig[Local_u8Iterator].LED_PinID,DIO_LOW);
				}
				else
				{

				}

			}
			else
			{

			}

			//LED_ON Scenario Handling in tow Connection Cases  .
			if( Copy_pstrLedConfig[Local_u8Iterator].LED_Init_State == LED_ON)
			{
				if(Copy_pstrLedConfig[Local_u8Iterator].LED_Connection_Style == LED_SINK )
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrLedConfig[Local_u8Iterator].LED_PinID,DIO_LOW);
				}
				else if (Copy_pstrLedConfig[Local_u8Iterator].LED_Connection_Style == LED_SOURCE)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_PortID,
							Copy_pstrLedConfig[Local_u8Iterator].LED_PinID,DIO_HIGH);
				}
				else
				{

				}

			}
			else
			{

			}

		}

		Local_enuErrorState = ES_OK;

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}//End ofLED_enuInit.



ES_t LED_enuLedON( LED_t* Copy_pstrLedConfig )
{
	ES_t Local_enuErrorState = ES_NOK ;

	if(Copy_pstrLedConfig != NULL )
	{
		if(Copy_pstrLedConfig->LED_Connection_Style == LED_SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig->LED_PortID,
					Copy_pstrLedConfig->LED_PinID,DIO_LOW);

		}
		else if ( Copy_pstrLedConfig->LED_Connection_Style == LED_SOURCE )
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig->LED_PortID,
					Copy_pstrLedConfig->LED_PinID,DIO_HIGH);
		}
		else
		{

		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}//End of LED_enuLedON.


ES_t LED_enuLedOFF( LED_t* Copy_pstrLedConfig )
{
	ES_t Local_enuErrorState = ES_NOK ;

	if(Copy_pstrLedConfig != NULL )
	{
		if(Copy_pstrLedConfig->LED_Connection_Style == LED_SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig->LED_PortID,
					Copy_pstrLedConfig->LED_PinID,DIO_HIGH);

		}
		else if ( Copy_pstrLedConfig->LED_Connection_Style == LED_SOURCE )
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_pstrLedConfig->LED_PortID,
					Copy_pstrLedConfig->LED_PinID,DIO_LOW);
		}
		else
		{

		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}



	return Local_enuErrorState;
}//End of LED_enuLedOFF.





/***************************************************************************/
/*Function Name   : LED_enuLedGetState.                                    */
/*Description     : Utility function to get the Led state.                 */
/*Argument        : Arg.1:  Address of the Led that you want to            */
/*                  =====   get its Status.                                */
/*                                                                         */
/*                          Example:                                       */
/*                                                                         */
/*                              &LED_AstrLedConfig[0] --->for led0         */
/*                              &LED_AstrLedConfig[1] --->for led1         */
/*                              &LED_AstrLedConfig[2] --->for led2         */
/*                                      .                      .           */
/*                                      .                      .           */
/*                                      .                      .           */
/*                                                                         */
/*                : Arg.2: Address Variable of type u8.                    */
/*                  =====                                                  */
/*                            Example:                                     */
/*                                      &led0  --->for led0                */
/*                                      &led1  --->for led1                */
/* .                                     .               .                 */
/*                                       .               .                 */
/*                                                                         */
/* Return          : Error state of type ES_t.                             */
/***************************************************************************/
ES_t LED_enuLedGetState(LED_t* Copy_pstrLedConfig ,u8* Copy_pu8LedState )
{
	ES_t Local_enuErrorState = ES_NOK ;


	if(Copy_pstrLedConfig != NULL )
	{
		u8 Local_u8LedState = 0 ;
		if(Copy_pstrLedConfig->LED_Connection_Style == LED_SINK)
		{

			Local_enuErrorState = DIO_enuGetPinVlaue( Copy_pstrLedConfig->LED_PortID,Copy_pstrLedConfig->LED_PinID,&Local_u8LedState);

			if ( !Local_u8LedState )
			{
				//LED ON
				*Copy_pu8LedState = LED_ON;
			}
			else if (Local_u8LedState)
			{
				//LED OFF
				*Copy_pu8LedState = LED_OFF;
			}
			else
			{

			}

		}
		else if ( Copy_pstrLedConfig->LED_Connection_Style == LED_SOURCE )
		{
			Local_enuErrorState = DIO_enuGetPinVlaue( Copy_pstrLedConfig->LED_PortID,Copy_pstrLedConfig->LED_PinID,&Local_u8LedState);

			if ( !Local_u8LedState )
			{
				//LED ON
				*Copy_pu8LedState = LED_OFF;
			}
			else if (Local_u8LedState)
			{
				//LED OFF
				*Copy_pu8LedState = LED_ON;
			}
			else
			{

			}


		}
		else
		{

		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}//End of LED_enuLedGetState.

/***************************************************************************/
/*Function Name   : LED_enuLedToggle.                                      */
/*Description     : Utility function to Toggle a certain led.              */
/*Argument        : Arg.1:  Address of the Led that you want to Toggle.    */
/*                  =====                                                  */
/*                                                                         */
/*                          Example:                                       */
/*                                                                         */
/*                              &LED_AstrLedConfig[0] --->for led0         */
/*                              &LED_AstrLedConfig[1] --->for led1         */
/*                              &LED_AstrLedConfig[2] --->for led2         */
/*                                      .                      .           */
/*                                      .                      .           */
/*                                                                         */
/* Return          : Error state of type ES_t.                             */
/****..................*****************************************************/
ES_t LED_enuLedToggle(LED_t* Copy_pstrLedConfig  )
{
	ES_t Local_enuErrorState = ES_NOK ;

	if(Copy_pstrLedConfig != NULL )
	{

		Local_enuErrorState =DIO_enuToggelPin( Copy_pstrLedConfig->LED_PortID , Copy_pstrLedConfig->LED_PinID );

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}

/******************************* END OF FILE. ***********************************/
/********************************************************************************/

