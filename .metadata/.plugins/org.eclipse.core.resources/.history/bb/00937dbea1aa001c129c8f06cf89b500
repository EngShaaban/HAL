/*
 * LCD_prog.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Shaban
 */

/****************************************************************************/
/******************************  INCLUDES  **********************************/

#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\STD_TYPES.h"
#include "E:\NTI\AVR\ATmeg16_Drivers\LIB\errorStates.h"

#include "E:\NTI\AVR\ATmeg16_Drivers\MCAL\DIO\DIO_interface.h"

#include"LCD_priv.h"
#include"LCD_Cnfg.h"

#include<util\delay.h>

/*******************************************************************/
/*******************************************************************/
/*******************************************************************/
/*******************************************************************/
/*******************************************************************/






//ES_t LCD_enuDisplayIntegerNum(LCD_t* Cpy_pstrLcdCnfg , s32 Copy_s32Num);


/*******************************************************************/
/*******************************************************************/
/*******************************************************************/

static inline void LCD_invidSendCommend(LCD_t* Cpy_pstrLcdCnfg , u8 Cpy_u8Command)
{


	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8RS_Port , (*Cpy_pstrLcdCnfg).LCD_u8RS_Pin   ,  DIO_LOW  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8RW_Port , (*Cpy_pstrLcdCnfg).LCD_u8RW_Pin   ,  DIO_LOW  );



	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8EN_Port , (*Cpy_pstrLcdCnfg).LCD_u8EN_Pin   ,  DIO_LOW );



	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D7_Port , (*Cpy_pstrLcdCnfg).LCD_u8D7_Pin   ,  C_BIT_7  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D6_Port , (*Cpy_pstrLcdCnfg).LCD_u8D6_Pin   ,  C_BIT_6  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D5_Port , (*Cpy_pstrLcdCnfg).LCD_u8D5_Pin   ,  C_BIT_5  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D4_Port , (*Cpy_pstrLcdCnfg).LCD_u8D4_Pin   ,  C_BIT_4  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D3_Port , (*Cpy_pstrLcdCnfg).LCD_u8D3_Pin   ,  C_BIT_3  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D2_Port , (*Cpy_pstrLcdCnfg).LCD_u8D2_Pin   ,  C_BIT_2  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D1_Port , (*Cpy_pstrLcdCnfg).LCD_u8D1_Pin   ,  C_BIT_1  );
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8D0_Port , (*Cpy_pstrLcdCnfg).LCD_u8D0_Pin   ,  C_BIT_0  );


	///***n***/   _delay_us(100);    // for tsu2=80
	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8EN_Port , (*Cpy_pstrLcdCnfg).LCD_u8EN_Pin   ,  DIO_HIGH );

	_delay_ms(10);

	DIO_enuSetPinValue(  (*Cpy_pstrLcdCnfg).LCD_u8EN_Port , (*Cpy_pstrLcdCnfg).LCD_u8EN_Pin   ,  DIO_LOW  );


}//End of LCD_invidSendCommend().



ES_t LCD_enuInit(LCD_t* Cpy_pstrLcdCnfg)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(  Cpy_pstrLcdCnfg != NULL  )
	{

		u8  Local_u8Iterator = 0 ;

		for ( Local_u8Iterator = 0 ; Local_u8Iterator < LCD_NUM ; Local_u8Iterator++ )
		{
			/******************************************************/
			/* Control Pins Direction Configuration.              */
			/******************************************************/
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RS_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RS_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RW_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RW_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8EN_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8EN_Pin  ,  DIO_OUTPUT_PIN);


			/******************************************************/
			/* Control Pins initial logic status Configuration.   */
			/******************************************************/
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RS_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RS_Pin  ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RW_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8RW_Pin  ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8EN_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8EN_Pin  ,  DIO_LOW );


			/******************************************************/
			/* Data Pins Direction Configuration.                 */
			/******************************************************/
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D7_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D7_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D6_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D6_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D5_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D5_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D4_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D4_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D3_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D3_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D2_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D2_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D1_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D1_Pin  ,  DIO_OUTPUT_PIN);
			DIO_enuSetPinDirection( Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D0_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D0_Pin  ,  DIO_OUTPUT_PIN);

			/******************************************************/
			/* Data Pins initial logic status Configuration.      */
			/******************************************************/
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D7_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D7_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D6_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D6_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D5_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D5_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D4_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D4_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D3_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D3_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D2_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D2_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D1_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D1_Pin   ,  DIO_LOW );
			DIO_enuSetPinValue(  Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D0_Port , Cpy_pstrLcdCnfg[Local_u8Iterator].LCD_u8D0_Pin   ,  DIO_LOW );






			/***********************************************************/
			/* LCD configuration process according to data sheet .     */
			/***********************************************************/

			//Step1:   Wait for more than 30ms .
			_delay_ms(35);

			//Step2:   Function set Command 0x38 for 8bit .
			LCD_invidSendCommend( &Cpy_pstrLcdCnfg[Local_u8Iterator] ,LCD_TOW_LINE_8BIT_MODE);

			//Step3:   Wait for more than 39us .
			_delay_ms(1);


			//Step4:   Display on Cursor off
			LCD_invidSendCommend( &Cpy_pstrLcdCnfg[Local_u8Iterator] , LCD_DISP_ON_CURSOR_OFF);

			//Step5:   Wait for more than 39us .
			_delay_ms(1);


			//Step6:   Clear Display.
			LCD_invidSendCommend( &Cpy_pstrLcdCnfg[Local_u8Iterator], LCD_CLEAR_DISP);

			//Step7:   wait for 1.53 ms.
			_delay_ms(2);

			//Step8:   Shift cursor to the right <Entry Mode Set>.
			LCD_invidSendCommend( &Cpy_pstrLcdCnfg[Local_u8Iterator] , LCD_ENT_SET );

		} //End of for loop.

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER ;
	}



	return Local_enuErrorState ;
}
/********************************************************************/
/**********************************************************************/

ES_t LCD_enuDisplayCharacter(LCD_t* Cpy_pstrLcdCnfg , u8 Cpy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState ;
}




ES_t LCD_enuSendCommand(LCD_t* Cpy_pstrLcdCnfg , u8 Cpy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;



	return Local_enuErrorState ;
}


/**********************************


static inline void  LCD_invidLatch(u8 Copy_u8Data)
{
	// set rw as write operation , EN is low
	DIO_enuSetPinValue(RW_PORT ,RW_PIN ,DIO_LOW);

	//ts = 50 ns .
	_delay_ms(1);

	//EN set.
	DIO_enuSetPinValue(EN_PORT ,EN_PIN ,DIO_HIGH);

	//tpw-Tdws  = 190 ns .
	_delay_ms(1);


	//write Data
	DIO_enuSetPinValue( D7_PORT , D7_PIN , BIT_7 );
	DIO_enuSetPinValue( D6_PORT , D6_PIN , BIT_6 );
	DIO_enuSetPinValue( D5_PORT , D5_PIN , BIT_5 );
	DIO_enuSetPinValue( D4_PORT , D4_PIN , BIT_4 );
	DIO_enuSetPinValue( D3_PORT , D3_PIN , BIT_3 );
	DIO_enuSetPinValue( D2_PORT , D2_PIN , BIT_2 );
	DIO_enuSetPinValue( D1_PORT , D1_PIN , BIT_1 );
	DIO_enuSetPinValue( D0_PORT , D0_PIN , BIT_0 );
	//Tdsw  = 100 ns .
	_delay_ms(1);

	DIO_enuSetPinValue(EN_PORT ,EN_PIN ,DIO_LOW);


}
 ***************************************************/














