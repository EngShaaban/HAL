/*
 * Led_interface.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Shaban
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_OFF            3
#define LED_ON             4



ES_t LED_enuInit( LED_t* Copy_pstrLedConfig );

ES_t LED_enuLedON( LED_t* Copy_pstrLedConfig );

ES_t LED_enuLedOFF( LED_t* Copy_pstrLedConfig );

ES_t LED_enuLedGetState(LED_t* Copy_pstrLedConfig ,u8* Copy_pu8LedState );

ES_t LED_enuLedToggle(LED_t* Copy_pstrLedConfig  );

#endif /* LED_INTERFACE_H_ */


/******************************* END OF FILE. ***********************************/
/********************************************************************************/
