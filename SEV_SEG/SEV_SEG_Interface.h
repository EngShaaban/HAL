/*
 * SEV_SEG_Interface.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Shaban
 */

#ifndef SEV_SEG_INTERFACE_H_
#define SEV_SEG_INTERFACE_H_






ES_t Seven_Segment_enuInit( SEG_t*  Cpy_pstrSegCnfg );
ES_t Seven_Segment_enuDisplayNum(SEG_t*  Cpy_pstrSegCnfg , u8 Cpy_u8Num );
ES_t Seven_Segment_enuEnableCommon(SEG_t*  Cpy_pstrSegCnfg );
ES_t Seven_Segment_enuDisableCommon(SEG_t*  Cpy_pstrSegCnfg );
ES_t Seven_Segment_enuEnableDot(SEG_t*  Cpy_pstrSegCnfg );
ES_t Seven_Segment_enuDisableDot(SEG_t*  Cpy_pstrSegCnfg );
ES_t Seven_Segment_enuClearDisplay(SEG_t*  Cpy_pstrSegCnfg );


#endif /* SEV_SEG_INTERFACE_H_ */
