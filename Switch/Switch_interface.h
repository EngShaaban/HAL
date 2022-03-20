/*****************************************************************************/
/* Title                 :   Switch_interface                                */
/* Filename              :   Switch_interface.h                              */
/* Author                :   Shaban Abdullah Awad                            */
/* Origin Date           :   Oct 2, 2021                                     */
/* Version               :   1.0.0                                           */
/* Compiler              :   mingw GCC                                       */
/* Target                :   ATmega16 , ATmega32                             */
/* Notes                 :   None                                            */
/*****************************************************************************/

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/****************************************************************************/
/************************** PUBLIC MACROS. **********************************/

/****************************************************************************/
/*SWITCH STATUS.                                                            */
/****************************************************************************/
#define SW_RELEASED          0
#define SW_PRESSED           1



/****************************************************************************/
/****************************  PUBLIC FUNCTIONS  ****************************/

/****************************************************************************/
/* Function Name   : Switch_enuInit.                                        */
/* Description     : Utility function to initialize the array of switches.  */
/* Argument        : Address array of type ES_t.                            */
/* Return          : Error state of type ES_t.                              */
/****************************************************************************/
ES_t Switch_enuInit(SW_t* Copy_pstrSwitchs);



/***************************************************************************/
/*Function Name   : Swithc_enuGetState.                                    */
/*Description     : Utility function to get the Switch state.              */
/*Argument        : Arg.1:  Address of the Switch that you want to         */
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
/*                : Arg.2: Address Variable of type u8.                    */
/*                  =====                                                  */
/*                            Example:                                     */
/*                                    &switch0  --->for switch0            */
/*                                    &switch1  --->for switch1            */
/* .                                     .               .                 */
/*                                       .               .                 */
/*                                                                         */
/* Return          : Error state of type ES_t.                             */
/***************************************************************************/
ES_t Switch_enuGetState(SW_t* Copy_pstrSwitchs , u8* Copy_pu8SwState);



#endif /* SWITCH_INTERFACE_H_ */

/***************************** END OF FILE. *********************************/
/****************************************************************************/

