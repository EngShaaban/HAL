/*****************************************************************************/
/* Title                 :   Seven_Segment_prog                                   */
/* Filename              :   Seven_Segment_prog.c                                 */
/* Author                :   Shaban Abdullah Awad                            */
/* Origin Date           :   Oct 4, 2021                                     */
/* Version               :   1.0.0                                           */
/* Compiler              :   mingw GCC                                       */
/* Target                :   ATmega16 , ATmega32                             */
/* Notes                 :   None                                            */
/*                                                                           */
/*****************************************************************************/

/****************************************************************************/
/******************************  INCLUDES  **********************************/
#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\STD_TYPES.h"
#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\errorStates.h"

#include "E:\NTI\AVR\ATmeg16_Drivers\MCAL\DIO\DIO_interface.h"

#include"Seven_Segment_priv.h"
#include"Seven_Segment_Cnfg.h"



/****************************************************************************/
/* Function Name   : Seven_Segment_enuInit.                                 */
/* Description     : Utility function to initialize the Seven segments.     */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK ;


	DIO_enuSetPinDirection(SEG_A_PORT , SEG_A_PIN , DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(SEG_B_PORT , SEG_B_PIN , DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(SEG_C_PORT , SEG_C_PIN , DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(SEG_D_PORT , SEG_D_PIN , DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(SEG_E_PORT , SEG_E_PIN , DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(SEG_F_PORT , SEG_F_PIN , DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(SEG_G_PORT , SEG_G_PIN , DIO_OUTPUT_PIN);

#if   (SEG_CMN_PORT <= DIO_PORTD ) &&  (SEG_CMN_PIN  <= DIO_PIN7)
	DIO_enuSetPinDirection(SEG_CMN_PORT , SEG_CMN_PIN , DIO_OUTPUT_PIN);

		#if SEG_TYPE  ==  COMMON_ANODE
			DIO_enuSetPinValue(SEG_CMN_PORT , SEG_CMN_PIN , DIO_HIGH);
		#elif  SEG_TYPE  ==  COMMON_CATHOD
			DIO_enuSetPinValue(SEG_CMN_PORT , SEG_CMN_PIN , DIO_LOW);
		#endif


#elif  SEG_CMN_PORT == NOT_CONNECTED || SEG_CMN_PIN == NOT_CONNECTED
	//Do nothing.
#else
#error "Unvalid Choice for the common Pin, Please Correct it and try again!!. "
#endif

#if   SEG_DOT_PIN != NOT_CONNECTED
	DIO_enuSetPinDirection(SEG_DOT_PORT , SEG_DOT_PIN , DIO_OUTPUT_PIN);
#endif


#if   SEG_DOT_PORT <= DIO_PORTD  &&  SEG_DOT_PIN  <= DIO_PIN7
	DIO_enuSetPinDirection(SEG_DOT_PORT , SEG_DOT_PIN , DIO_OUTPUT_PIN);

#elif  SEG_DOT_PORT == NOT_CONNECTED || SEG_DOT_PIN == NOT_CONNECTED
	//Do nothing.
#else
#error "Unvalid Choice for the DOT Pin, Please Correct it and try again!!. "
#endif

	return Local_enuErrorState ;
} //End of



/****************************************************************************/
/* Function Name   : Seven_Segment_enuDisplayNum.                           */
/* Description     : This function displays an integer number on the 7_Seg. */
/* Argument        : Integer number From 0 to 9 .                           */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num)
{
	ES_t Local_enuErrorState = ES_NOK ;

	if( Copy_u8Num < 10)
	{
#if   SEG_TYPE   ==  COMMON_CATHOD
		Copy_u8Num = SEG_Au8NumDisplay[Copy_u8Num];
		DIO_enuSetPinValue(SEG_A_PORT , SEG_A_PIN ,LEG_A  );
		DIO_enuSetPinValue(SEG_B_PORT , SEG_B_PIN ,LEG_B  );
		DIO_enuSetPinValue(SEG_C_PORT , SEG_C_PIN , LEG_C  );
		DIO_enuSetPinValue(SEG_D_PORT , SEG_D_PIN , LEG_D  );
		DIO_enuSetPinValue(SEG_E_PORT , SEG_E_PIN , LEG_E  );
		DIO_enuSetPinValue(SEG_F_PORT , SEG_F_PIN , LEG_F  );
		DIO_enuSetPinValue(SEG_G_PORT , SEG_G_PIN , LEG_G  );

#elif   SEG_TYPE   ==  COMMON_ANODE
		Copy_u8Num = SEG_Au8NumDisplay[Copy_u8Num];

		DIO_enuSetPinValue(SEG_A_PORT , SEG_A_PIN ,!LEG_A );
		DIO_enuSetPinValue(SEG_B_PORT , SEG_B_PIN ,!LEG_B );
		DIO_enuSetPinValue(SEG_C_PORT , SEG_C_PIN ,!LEG_C );
		DIO_enuSetPinValue(SEG_D_PORT , SEG_D_PIN ,!LEG_D );
		DIO_enuSetPinValue(SEG_E_PORT , SEG_E_PIN ,!LEG_E );
		DIO_enuSetPinValue(SEG_F_PORT , SEG_F_PIN ,!LEG_F );
		DIO_enuSetPinValue(SEG_G_PORT , SEG_G_PIN ,!LEG_G );

#else
#error"Seven Segment can be either COMMON_ANODE or COMMON_CATHOD  Only!!."
#endif


	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState ;
} //End of




/****************************************************************************/
/* Function Name   : Seven_Segment_enuEnableCommon.                         */
/* Description     : This function enables the common line of the 7_seg.    */
/*                   if the common connected to the mcu.                    */
/* Argument        : None .                                                 */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuEnableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK ;

#if  (SEG_CMN_PIN <= DIO_PIN7) && (SEG_CMN_PORT <= DIO_PORTD)

#if    SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT , SEG_CMN_PIN ,DIO_HIGH);

#elif  SEG_TYPE == COMMON_CATHOD
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT , SEG_CMN_PIN ,DIO_LOW);
#endif

#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#endif

	return Local_enuErrorState ;
} //End of Seven_Segment_enuEnableCommon.



/****************************************************************************/
/* Function Name   : Seven_Segment_enuDisableCommon.                        */
/* Description     : This function Disables the common line of the 7_seg.   */
/*                   if the common connected to the mcu.                    */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuDisableCommon(void)
{
	ES_t Local_enuErrorState = ES_NOK ;

#if  (SEG_CMN_PIN <= DIO_PIN7) && (SEG_CMN_PORT <= DIO_PORTD)

#if    SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT , SEG_CMN_PIN ,DIO_LOW);

#elif  SEG_TYPE == COMMON_CATHOD
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT , SEG_CMN_PIN ,DIO_HIGH);
#endif

#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#endif

	return Local_enuErrorState ;
} //End of Seven_Segment_enuDisableCommon.



/****************************************************************************/
/* Function Name   : Seven_Segment_enuEnableDot.                            */
/* Description     : Utility function to turn the Dot ON.                   */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...................................****************************************/
ES_t Seven_Segment_enuEnableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK ;

#if  (SEG_DOT_PIN <= DIO_PIN7) && (SEG_DOT_PORT <= DIO_PORTD)

#if    SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT , SEG_DOT_PIN ,DIO_LOW);

#elif  SEG_TYPE == COMMON_CATHOD
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT , SEG_DOT_PIN ,DIO_HIGH);
#endif

#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#endif

	return Local_enuErrorState ;
} //End of Seven_Segment_enuEnableDot.



/****************************************************************************/
/* Function Name   : Seven_Segment_enuDisableDot.                           */
/* Description     : Utility function to turn the Dot OFF.                  */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...................................****************************************/
ES_t Seven_Segment_enuDisableDot(void)
{
	ES_t Local_enuErrorState = ES_NOK ;

#if  (SEG_DOT_PIN <= DIO_PIN7) && (SEG_DOT_PORT <= DIO_PORTD)

#if    SEG_TYPE == COMMON_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT , SEG_DOT_PIN ,DIO_HIGH);

#elif  SEG_TYPE == COMMON_CATHOD
	Local_enuErrorState = DIO_enuSetPinValue(SEG_G_PORT , SEG_DOT_PIN ,DIO_LOW);
#endif

#elif SEG_DOT_PIN == NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#endif

	return Local_enuErrorState ;

} //End of Seven_Segment_enuDisableDot.



/****************************************************************************/
/* Function Name   : Seven_Segment_enuClearDisplay.                         */
/* Description     : Utility function to Clear the 7_segment.               */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...................................****************************************/
ES_t Seven_Segment_enuClearDisplay(void)
{
	ES_t Local_enuErrorState = ES_NOK ;

#if    SEG_TYPE == COMMON_ANODE
	u8    Copy_u8Num = SEG_Au8NumDisplay[0];

	DIO_enuSetPinValue(SEG_A_PORT , SEG_A_PIN ,!LEG_A );
	DIO_enuSetPinValue(SEG_B_PORT , SEG_B_PIN ,!LEG_B );
	DIO_enuSetPinValue(SEG_C_PORT , SEG_C_PIN ,!LEG_C );
	DIO_enuSetPinValue(SEG_D_PORT , SEG_D_PIN ,!LEG_D );
	DIO_enuSetPinValue(SEG_E_PORT , SEG_E_PIN ,!LEG_E );
	DIO_enuSetPinValue(SEG_F_PORT , SEG_F_PIN ,!LEG_F );
	DIO_enuSetPinValue(SEG_G_PORT , SEG_G_PIN ,!LEG_G );


#elif  SEG_TYPE == COMMON_ANODE

	u8    Copy_u8Num = SEG_Au8NumDisplay[0];

	DIO_enuSetPinValue(SEG_A_PORT , SEG_A_PIN ,LEG_A );
	DIO_enuSetPinValue(SEG_B_PORT , SEG_B_PIN ,LEG_B );
	DIO_enuSetPinValue(SEG_C_PORT , SEG_C_PIN ,LEG_C );
	DIO_enuSetPinValue(SEG_D_PORT , SEG_D_PIN ,LEG_D );
	DIO_enuSetPinValue(SEG_E_PORT , SEG_E_PIN ,LEG_E );
	DIO_enuSetPinValue(SEG_F_PORT , SEG_F_PIN ,LEG_F );
	DIO_enuSetPinValue(SEG_G_PORT , SEG_G_PIN ,LEG_G );


#elif
#error"Seven Segment can be either COMMON_ANODE or COMMON_CATHOD  Only!!."
#endif


	return Local_enuErrorState ;
} //End of
