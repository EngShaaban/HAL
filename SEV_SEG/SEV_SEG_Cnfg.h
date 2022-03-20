/*
 * SEV_SEG_Cnfg.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Shaban
 */

#ifndef SEV_SEG_CNFG_H_
#define SEV_SEG_CNFG_H_



#define  SEG_NUM           1



typedef struct
{
	u8 SEG_u8Type          ;

	u8 SEG_u8LegA_Port     ;
	u8 SEG_u8LegA_Pin      ;

	u8 SEG_u8LegB_Port     ;
	u8 SEG_u8LegB_Pin      ;

	u8 SEG_u8LegC_Port     ;
	u8 SEG_u8LegC_Pin      ;

	u8 SEG_u8LegD_Port     ;
	u8 SEG_u8LegD_Pin      ;

	u8 SEG_u8LegE_Port     ;
	u8 SEG_u8LegE_Pin      ;

	u8 SEG_u8LegF_Port     ;
	u8 SEG_u8LegF_Pin      ;

	u8 SEG_u8LegG_Port     ;
	u8 SEG_u8LegG_Pin      ;

	u8 SEG_u8LegCMN_Port   ;
	u8 SEG_u8LegCMN_Pin    ;

	u8 SEG_u8LegDot_Port   ;
	u8 SEG_u8LegDot_Pin    ;

}SEG_t;

extern SEG_t SevenSegment_AstrSegCnfg[SEG_NUM];

extern u8 SEG_Au8NumDisplay[] ;


#endif /* SEV_SEG_CNFG_H_ */
