/*
 * Led_config.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Shaban
 */

#ifndef LED_CONFIG_H_n
#define LED_CONFIG_H_

#define LED_NUM   2

typedef struct
{
    u8 LED_PortID             ;
    u8 LED_PinID              ;
    u8 LED_Init_State         ;
    u8 LED_Connection_Style   ;

}LED_t;

extern LED_t LED_AstrLedConfig[LED_NUM];



#endif /* LED_CONFIG_H_ */


/******************************* END OF FILE. ***********************************/
/********************************************************************************/
