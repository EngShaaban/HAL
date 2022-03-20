/*****************************************************************************/
/* Title                 :   Switch_config                                   */
/* Filename              :   Switch_config.h                                 */
/* Author                :   Shaban Abdullah Awad                            */
/* Origin Date           :   Oct 2, 2021                                     */
/* Version               :   1.0.0                                           */
/* Compiler              :   mingw GCC                                       */
/* Target                :   ATmega16 , ATmega32                             */
/* Notes                 :   None                                            */
/*****************************************************************************/

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_



#define SW_NUM           2

typedef struct
{
	u8 SW_PortID ;
	u8 SW_PinID  ;
	u8 SW_Status ;

}SW_t;

extern SW_t  Switch_AstrSwitchState[SW_NUM] ;


#endif /* SWITCH_CONFIG_H_ */

/***************************** END OF FILE. *********************************/
/****************************************************************************/

