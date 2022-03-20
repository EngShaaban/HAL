/*
 * Seven_Segment_interface.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Shaban
 */

#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

/****************************************************************************/
/**************************   PRECOMPILED DRIVER   **************************/
/****************************************************************************/


/****************************************************************************/
/****************************  PUBLIC FUNCTIONS  ****************************/

/****************************************************************************/
/* Function Name   : Seven_Segment_enuInit.                                 */
/* Description     : Utility function to initialize the Seven segments.     */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuInit(void);




/****************************************************************************/
/* Function Name   : Seven_Segment_enuDisplayNum.                           */
/* Description     : This function displays an integer number on the 7_Seg. */
/* Argument        : Integer number From 0 to 9 .                           */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num);


/****************************************************************************/
/* Function Name   : Seven_Segment_enuEnableCommon.                         */
/* Description     : This function enables the common line of the 7_seg.    */
/*                   if the common connected to the mcu.                    */
/* Argument        : None .                                                 */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuEnableCommon(void);




/****************************************************************************/
/* Function Name   : Seven_Segment_enuDisableCommon.                        */
/* Description     : This function Disables the common line of the 7_seg.   */
/*                   if the common connected to the mcu.                    */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...............................********************************************/
ES_t Seven_Segment_enuDisableCommon(void);



/****************************************************************************/
/* Function Name   : Seven_Segment_enuEnableDot.                            */
/* Description     : Utility function to turn the Dot ON.                   */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...................................****************************************/
ES_t Seven_Segment_enuEnableDot(void);



/****************************************************************************/
/* Function Name   : Seven_Segment_enuDisableDot.                           */
/* Description     : Utility function to turn the Dot OFF.                  */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...................................****************************************/
ES_t Seven_Segment_enuDisableDot(void);




/****************************************************************************/
/* Function Name   : Seven_Segment_enuClearDisplay.                         */
/* Description     : Utility function to Clear the 7_segment.               */
/* Argument        : None.                                                  */
/* Return          : Error state of type ES_t.                              */
/*...................................****************************************/
ES_t Seven_Segment_enuClearDisplay(void);



#endif /* SEVEN_SEGMENT_INTERFACE_H_ */

/***************************** END OF FILE. *********************************/
/****************************************************************************/

