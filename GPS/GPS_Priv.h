/*****************************************************************************/
/*****************************************************************************/
/* Title                 :   GPS_Priv                                        */
/* Filename              :   GPS_Priv.h                                      */
/* Author                :   Shaban Abdullah Awad                            */
/* Created on            :   Mar 15, 2022                                    */
/* Version               :   0.0.0                                           */
/* Toolchain             :   avr-gcc (4.3.3)                                 */
/* Target                :   ATmega32                                        */
/* Notes                 :   None                                            */
/*                                                                           */
/*****************************************************************************/


/*****************************************************************************/
/****************************   FILE GUARDE  *********************************/
#ifndef GPS_PRIV_H_
#define GPS_PRIV_H_



typedef union
{
	u8 FLAGS ;

	struct
	{
		u8   GPGGA_LINE_FLAG:           1 ;
		u8   LAT_COMMA_FLAG :           1 ;
		u8   LONG_COMMA_FLAG:           1 ;
		u8   FIRST_DIR_FLAG :           1 ;
		u8   SECOND_DIR_FLAG:           1 ;
		u8   DOT_FLAG       :           1 ;
	}FLAG;

}GPS_FLAGS_t;

void fun(void);

/*****************************************************************************/
/********************* PRIVATE FUNCTIONS LIKE MACROS *************************/

#define GPS_CLEAR_ALL_FLAGSE()          GPS_Flags.FLAGS = 0

#define GPS_SET_LINE_FLAG()             GPS_Flags.FLAG.GPGGA_LINE_FLAG  = 1
#define GPS_SET_LAT_FLAG()              GPS_Flags.FLAG.LAT_COMMA_FLAG   = 1
#define GPS_SET_LONG_FLAG()             GPS_Flags.FLAG.LONG_COMMA_FLAG  = 1
#define GPS_SET_DOT_FLAG()              GPS_Flags.FLAG.DOT_FLAG         = 1
#define GPS_SET_FIRST_DIR_FLAG()        GPS_Flags.FLAG.FIRST_DIR_FLAG   = 1
#define GPS_SET_SEC_DIR_FLAG()          GPS_Flags.FLAG.SECOND_DIR_FLAG  = 1

#define GPS_CLEAR_LINE_FLAG()           GPS_Flags.FLAG.GPGGA_LINE_FLAG  = 0
#define GPS_CLEAR_LAT_FLAG()            GPS_Flags.FLAG.LAT_COMMA_FLAG   = 0
#define GPS_CLEAR_LONG_FLAG()           GPS_Flags.FLAG.LONG_COMMA_FLAG  = 0
#define GPS_CLEAR_DOT_FLAG()            GPS_Flags.FLAG.DOT_FLAG         = 0
#define GPS_CLEAR_FIRST_DIR_FLAG()       GPS_Flags.FLAG.FIRST_DIR_FLAG   = 0
#define GPS_CLEAR_SEC_DIR_FLAG()        GPS_Flags.FLAG.SECOND_DIR_FLAG  = 0






#endif /* GPS_PRIV_H_ */

/***************************** END OF FILE. **********************************/
/*****************************************************************************/


