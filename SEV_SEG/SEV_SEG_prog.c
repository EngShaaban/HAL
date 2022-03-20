/*
 * SEV_SEG_prog.c
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



ES_t Seven_Segment_enuInit( SEG_t*  Cpy_pstrSegCnfg )
{
	ES_t  Local_enuErrorState   = ES_NOK ;

	// Make sure that the passed address is not equal NULL .
	if(Cpy_pstrSegCnfg !=NULL )
	{
		u8 Local_u8Iterator = 0 ;

		for( Local_u8Iterator = 0 ; Local_u8Iterator < SEG_NUM  ; Local_u8Iterator++)
		{

			/********************************************************************************************************************************************/
			/* Configure all pins that connected to the seven segments legs as output pinS.                                                             */
			/********************************************************************************************************************************************/
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegA_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegA_Pin,DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegB_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegB_Pin,DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegC_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegC_Pin,DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegD_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegD_Pin,DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegE_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegE_Pin,DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegF_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegF_Pin,DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegG_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegG_Pin,DIO_OUTPUT_PIN);


			if ( (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8Type) == COMMON_ANODE )
			{

				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegA_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegA_Pin,DIO_HIGH);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegB_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegB_Pin,DIO_HIGH);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegC_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegC_Pin,DIO_HIGH);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegD_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegD_Pin,DIO_HIGH);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegE_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegE_Pin,DIO_HIGH);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegF_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegF_Pin,DIO_HIGH);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegG_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegG_Pin,DIO_HIGH);

				/********************************************************************************************************************************************/
				/**************************************************** Common Pin Scenarios Handling *********************************************************/

				/********************************************************************************************************************************************/
				/* Checking and Handling if there a dedicated pin to Common line scenario .                                                                 */
				/********************************************************************************************************************************************/
				if( ( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port  <= DIO_PORTD ) && (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin  <= DIO_PIN7) )
				{

					/****************************************************************************************************************************************/
					/* Configure the common pin as output pin.                                                                                              */
					/****************************************************************************************************************************************/
					DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin, DIO_OUTPUT_PIN);


					/****************************************************************************************************************************************/
					/* Configure the common pin Logic State as HIGH or LOW according to Seven Segment Type.                                                 */
					/****************************************************************************************************************************************/
					if ( (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8Type) == COMMON_ANODE )
					{
						DIO_enuSetPinValue(Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin,DIO_HIGH);
					}
					else if ( (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8Type) == COMMON_CATHOD )
					{
						DIO_enuSetPinValue(Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin,DIO_LOW);
					}
					else
					{

					}


				}

				/************************************************************************************************************************************************************/
				/* The mcu Does not support pin to to Seven segment common pin .                                                                                            */
				/************************************************************************************************************************************************************/
				else if ( ( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port == NOT_CONNECTED  ) || (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin  == NOT_CONNECTED) )
				{
					// Do Nothing .
				}
				else
				{
					//Report Error.
				}




			}
			else if ((Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8Type) == COMMON_CATHOD)
			{



				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegA_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegA_Pin,DIO_LOW);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegB_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegB_Pin,DIO_LOW);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegC_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegC_Pin,DIO_LOW);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegD_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegD_Pin,DIO_LOW);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegE_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegE_Pin,DIO_LOW);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegF_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegF_Pin,DIO_LOW);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegG_Port ,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegG_Pin,DIO_LOW);

				/********************************************************************************************************************************************/
				/**************************************************** Common Pin Scenarios Handling *********************************************************/

				/********************************************************************************************************************************************/
				/* Checking and Handling if there a dedicated pin to Common line scenario .                                                                 */
				/********************************************************************************************************************************************/
				if( ( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port  <= DIO_PORTD ) && (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin  <= DIO_PIN7) )
				{

					/****************************************************************************************************************************************/
					/* Configure the common pin as output pin.                                                                                              */
					/****************************************************************************************************************************************/
					DIO_enuSetPinDirection( Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin, DIO_OUTPUT_PIN);


					/****************************************************************************************************************************************/
					/* Configure the common pin Logic State as HIGH or LOW according to Seven Segment Type.                                                 */
					/****************************************************************************************************************************************/
					if ( (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8Type) == COMMON_ANODE )
					{
						DIO_enuSetPinValue(Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin,DIO_HIGH);
					}
					else if ( (Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8Type) == COMMON_CATHOD )
					{
						DIO_enuSetPinValue(Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Port,  Cpy_pstrSegCnfg[Local_u8Iterator].SEG_u8LegCMN_Pin,DIO_LOW);
					}
					else
					{

					}



			}

			Local_enuErrorState = ES_OK ;
		}

		else
		{
			Local_enuErrorState = ES_NULL_POINTER ;
		}
		}




	}
	return Local_enuErrorState ;
}//End of




	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	ES_t Seven_Segment_enuDisplayNum(SEG_t*  Cpy_pstrSegCnfg , u8 Cpy_u8Num )
	{
		ES_t  Local_enuErrorState   = ES_NOK ;

		if( Cpy_pstrSegCnfg != NULL )
		{

			Cpy_u8Num=SEG_Au8NumDisplay[Cpy_u8Num];
			(*(u8*)0x31)=Cpy_u8Num;



			if( Cpy_pstrSegCnfg->SEG_u8Type == COMMON_ANODE )
			{

				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegA_Port ,  Cpy_pstrSegCnfg->SEG_u8LegA_Pin ,~Bit0);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegB_Port ,  Cpy_pstrSegCnfg->SEG_u8LegB_Pin ,~Bit1);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegC_Port ,  Cpy_pstrSegCnfg->SEG_u8LegC_Pin ,~Bit2);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegD_Port ,  Cpy_pstrSegCnfg->SEG_u8LegD_Pin ,~Bit3);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegE_Port ,  Cpy_pstrSegCnfg->SEG_u8LegE_Pin ,~Bit4);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegF_Port ,  Cpy_pstrSegCnfg->SEG_u8LegF_Pin ,~Bit5);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegG_Port ,  Cpy_pstrSegCnfg->SEG_u8LegG_Pin ,~Bit6);

			}
			else if (Cpy_pstrSegCnfg->SEG_u8Type == COMMON_CATHOD)
			{

				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegA_Port ,  Cpy_pstrSegCnfg->SEG_u8LegA_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>0)&1 );
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegB_Port ,  Cpy_pstrSegCnfg->SEG_u8LegB_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>1)&1 );
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegC_Port ,  Cpy_pstrSegCnfg->SEG_u8LegC_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>2)&1 );
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegD_Port ,  Cpy_pstrSegCnfg->SEG_u8LegD_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>3)&1 );
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegE_Port ,  Cpy_pstrSegCnfg->SEG_u8LegE_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>4)&1 );
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegF_Port ,  Cpy_pstrSegCnfg->SEG_u8LegF_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>5)&1 );
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegG_Port ,  Cpy_pstrSegCnfg->SEG_u8LegG_Pin ,(SEG_Au8NumDisplay[Cpy_u8Num]>>6)&1 );

			}
			else
			{

			}

			Local_enuErrorState = ES_OK ;
		}
		else
		{
			Local_enuErrorState   = ES_NULL_POINTER ;
		}

		return Local_enuErrorState ;
	}//End of




	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	ES_t Seven_Segment_enuEnableCommon(SEG_t*  Cpy_pstrSegCnfg )
	{
		ES_t  Local_enuErrorState   = ES_NOK ;

		if(Cpy_pstrSegCnfg != NULL )
		{

			if(Cpy_pstrSegCnfg->SEG_u8Type == COMMON_ANODE )


			{
				if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port <= DIO_PORTD) && (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin <= DIO_PIN7) )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegCMN_Port,Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin,DIO_LOW);

				}
				else if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port == NOT_CONNECTED) || (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin == NOT_CONNECTED))
				{

				}
				else
				{

				}

			}


			else if (Cpy_pstrSegCnfg->SEG_u8Type == COMMON_CATHOD )
			{

				if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port <= DIO_PORTD) && (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin <= DIO_PIN7) )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegCMN_Port,Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin,DIO_HIGH);

				}
				else if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port == NOT_CONNECTED) || (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin == NOT_CONNECTED))
				{

				}
				else
				{

				}

			}
			else
			{

			}



			Local_enuErrorState   = ES_OK ;
		}
		else
		{
			Local_enuErrorState   = ES_NULL_POINTER;
		}



		return Local_enuErrorState ;
	}//End of




	/********************************************************************/
	/*************************** *****************************************/
	/********************************************************************/
	ES_t Seven_Segment_enuDisableCommon(SEG_t*  Cpy_pstrSegCnfg )
	{
		ES_t  Local_enuErrorState   = ES_NOK ;

		if(Cpy_pstrSegCnfg != NULL )
		{

			if(Cpy_pstrSegCnfg->SEG_u8Type == COMMON_ANODE )
			{
				if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port <= DIO_PORTD) && (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin <= DIO_PIN7) )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegCMN_Port,Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin,DIO_HIGH);

				}
				else if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port == NOT_CONNECTED) || (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin == NOT_CONNECTED))
				{

				}
				else
				{

				}

			}
			else if (Cpy_pstrSegCnfg->SEG_u8Type == COMMON_CATHOD )
			{

				if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port <= DIO_PORTD) && (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin <= DIO_PIN7) )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegCMN_Port,Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin,DIO_LOW);

				}
				else if((Cpy_pstrSegCnfg->SEG_u8LegCMN_Port == NOT_CONNECTED) || (Cpy_pstrSegCnfg->SEG_u8LegCMN_Pin == NOT_CONNECTED))
				{

				}
				else
				{

				}

			}
			else
			{

			}



			Local_enuErrorState   = ES_OK ;
		}
		else
		{
			Local_enuErrorState   = ES_NULL_POINTER;
		}






		return Local_enuErrorState ;
	}//End of




	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	ES_t Seven_Segment_enuEnableDot(SEG_t*  Cpy_pstrSegCnfg )
	{
		ES_t  Local_enuErrorState   = ES_NOK ;

		if(Cpy_pstrSegCnfg != NULL )
		{

			if((Cpy_pstrSegCnfg->SEG_u8LegDot_Port <= DIO_PORTD) && (Cpy_pstrSegCnfg->SEG_u8LegDot_Pin <= DIO_PIN7) )
			{

				if(Cpy_pstrSegCnfg->SEG_u8Type == COMMON_ANODE )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegDot_Port,Cpy_pstrSegCnfg->SEG_u8LegDot_Pin,DIO_LOW);

				}
				else if (Cpy_pstrSegCnfg->SEG_u8Type == COMMON_CATHOD )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegDot_Port,Cpy_pstrSegCnfg->SEG_u8LegDot_Pin,DIO_HIGH);

				}
				else
				{

				}


			}
			else if( (Cpy_pstrSegCnfg->SEG_u8LegDot_Port == NOT_CONNECTED) || (Cpy_pstrSegCnfg->SEG_u8LegDot_Pin == NOT_CONNECTED ))
			{

			}
			else
			{

			}


		}
		else
		{
			Local_enuErrorState   = ES_NULL_POINTER;
		}


		return Local_enuErrorState ;
	}//End of




	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	ES_t Seven_Segment_enuDisableDot(SEG_t*  Cpy_pstrSegCnfg )
	{
		ES_t  Local_enuErrorState   = ES_NOK ;



		if(Cpy_pstrSegCnfg != NULL )
		{
			if((Cpy_pstrSegCnfg->SEG_u8LegDot_Port <= DIO_PORTD) && (Cpy_pstrSegCnfg->SEG_u8LegDot_Pin <= DIO_PIN7) )
			{

				if(Cpy_pstrSegCnfg->SEG_u8Type == COMMON_ANODE )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegDot_Port,Cpy_pstrSegCnfg->SEG_u8LegDot_Pin,DIO_HIGH);

				}
				else if (Cpy_pstrSegCnfg->SEG_u8Type == COMMON_CATHOD )
				{
					DIO_enuSetPinValue(Cpy_pstrSegCnfg->SEG_u8LegDot_Port,Cpy_pstrSegCnfg->SEG_u8LegDot_Pin,DIO_LOW);

				}
				else
				{

				}


			}
			else if( (Cpy_pstrSegCnfg->SEG_u8LegDot_Port == NOT_CONNECTED) || (Cpy_pstrSegCnfg->SEG_u8LegDot_Pin == NOT_CONNECTED ))
			{

			}
			else
			{

			}


		}
		else
		{
			Local_enuErrorState   = ES_NULL_POINTER;
		}



		return Local_enuErrorState ;
	}//End of




	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	ES_t Seven_Segment_enuClearDisplay(SEG_t*  Cpy_pstrSegCnfg )
	{
		ES_t  Local_enuErrorState   = ES_NOK ;


		if(Cpy_pstrSegCnfg != NULL )
		{
			u8 Cpy_u8Num =  0 ;

			if(Cpy_pstrSegCnfg->SEG_u8Type == COMMON_ANODE )
			{
				// Cpy_u8Num = SEG_Au8NumDisplay[Cpy_u8Num];  // (SEG_Au8NumDisplay[Cpy_u8Num]>>0)&1

				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegA_Port ,  Cpy_pstrSegCnfg->SEG_u8LegA_Pin ,Bit0);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegB_Port ,  Cpy_pstrSegCnfg->SEG_u8LegB_Pin ,Bit1);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegC_Port ,  Cpy_pstrSegCnfg->SEG_u8LegC_Pin ,Bit2);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegD_Port ,  Cpy_pstrSegCnfg->SEG_u8LegD_Pin ,Bit3);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegE_Port ,  Cpy_pstrSegCnfg->SEG_u8LegE_Pin ,Bit4);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegF_Port ,  Cpy_pstrSegCnfg->SEG_u8LegF_Pin ,Bit5);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegG_Port ,  Cpy_pstrSegCnfg->SEG_u8LegG_Pin ,Bit6);



			}
			else if (Cpy_pstrSegCnfg->SEG_u8Type == COMMON_CATHOD )
			{
				//Cpy_u8Num = !SEG_Au8NumDisplay[0];


				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegA_Port ,  Cpy_pstrSegCnfg->SEG_u8LegA_Pin ,Bit0);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegB_Port ,  Cpy_pstrSegCnfg->SEG_u8LegB_Pin ,Bit1);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegC_Port ,  Cpy_pstrSegCnfg->SEG_u8LegC_Pin ,Bit2);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegD_Port ,  Cpy_pstrSegCnfg->SEG_u8LegD_Pin ,Bit3);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegE_Port ,  Cpy_pstrSegCnfg->SEG_u8LegE_Pin ,Bit4);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegF_Port ,  Cpy_pstrSegCnfg->SEG_u8LegF_Pin ,Bit5);
				DIO_enuSetPinValue( Cpy_pstrSegCnfg->SEG_u8LegG_Port ,  Cpy_pstrSegCnfg->SEG_u8LegG_Pin ,Bit6);



			}
			else
			{

			}


		}
		else
		{
			Local_enuErrorState   = ES_NULL_POINTER;
		}


		return Local_enuErrorState ;

	}



	/******************************* END OF FILE. ***********************************/
	/********************************************************************************/
