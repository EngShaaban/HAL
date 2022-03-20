/*****************************************************************************/
/* Title                 :   Seven_Segment_Cnfg                                   */
/* Filename              :   Seven_Segment_Cnfg.h                                 */
/* Author                :   Shaban Abdullah Awad                            */
/* Origin Date           :   Oct 4, 2021                                   */
/* Version               :   1.0.0                                           */
/* Compiler              :   mingw GCC                                       */
/* Target                :   ATmega16 , ATmega32                             */
/* Notes                 :   None                                            */
/*                                                                           */
/*****************************************************************************/


/****************************************************************************/
/**************************   FILE GUARDE  **********************************/
#ifndef SEVEN_SEGMENT_CNFG_H_
#define SEVEN_SEGMENT_CNFG_H_


/****************************************************************************/
/* Macro name :    SEG_TYPE .                                               */
/* Description:    To configure the type of Seven Segment Module.           */
/* Options    :    COMMON_ANODE   or  COMMON_CATHOD                         */
/****************************************************************************/
#define   SEG_TYPE       COMMON_ANODE



/*****************************************************************************/
/** Macro name :    SEG_X_PIN  and  SEG_X_PORT.                              */
/*                  Hint: X can be A,B,C,D,E,F, or G .                       */
/*				                                                             */
/** Description:    To configure the Seven Segment terminals.                */
/*                                                                           */
/** Options    :    SEG_X_PIN                                                */
/*                              DIO_PIN0     ,     DIO_PIN4                  */
/*                              DIO_PIN1     ,     DIO_PIN5                  */
/*                              DIO_PIN2     ,     DIO_PIN6                  */
/*                              DIO_PIN3     ,     DIO_PIN7                  */
/*                 SEG_B_PORT                                                */
/*                              DIO_PORTA    ,     DIO_PORTC                 */
/*                              DIO_PORTB    ,     DIO_PORTD                 */
/*                                                                           */
/*****************************************************************************/
#define   SEG_A_PIN      DIO_PIN0
#define   SEG_A_PORT     DIO_PORTA

#define   SEG_B_PIN      DIO_PIN1
#define   SEG_B_PORT     DIO_PORTA

#define   SEG_C_PIN      DIO_PIN2
#define   SEG_C_PORT     DIO_PORTA

#define   SEG_D_PIN      DIO_PIN3
#define   SEG_D_PORT     DIO_PORTA

#define   SEG_E_PIN      DIO_PIN4
#define   SEG_E_PORT     DIO_PORTA

#define   SEG_F_PIN      DIO_PIN5
#define   SEG_F_PORT     DIO_PORTA

#define   SEG_G_PIN      DIO_PIN6
#define   SEG_G_PORT     DIO_PORTA


/*****************************************************************************/
/*  Hint:           You can disconnect SEG_CMN_PIN and SEG_DOT_PIN           */
/*				    if you configure theme as:  NOT_CONNECTED                */
/*                                                                           */
/*****************************************************************************/
#define   SEG_CMN_PIN    DIO_PIN7
#define   SEG_CMN_PORT   DIO_PORTA

#define   SEG_DOT_PIN    DIO_PIN0
#define   SEG_DOT_PORT   DIO_PORTB




#endif /* SEVEN_SEGMENT_CNFG_H_ */

/***************************** END OF FILE. *********************************/
/****************************************************************************/
