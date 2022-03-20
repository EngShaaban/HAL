/*
 * Seven_Segment_priv.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Shaban
 */

#ifndef SEVEN_SEGMENT_PRIV_H_
#define SEVEN_SEGMENT_PRIV_H_

u8 SEG_Au8NumDisplay[10]= { 0x3f, 0x06, 0x5B,
		0x4F, 0x66, 0x6D,
		0x7D, 0x07, 0x7F,
		0x6F};


#define  LEG_A      ((Copy_u8Num>>0)&1)
#define  LEG_B      ((Copy_u8Num>>1)&1)
#define  LEG_C      ((Copy_u8Num>>2)&1)
#define  LEG_D      ((Copy_u8Num>>3)&1)
#define  LEG_E      ((Copy_u8Num>>4)&1)
#define  LEG_F      ((Copy_u8Num>>5)&1)
#define  LEG_G      ((Copy_u8Num>>6)&1)





#define COMMON_ANODE         0
#define COMMON_CATHOD        1

#define NOT_CONNECTED        0


#endif /* SEVEN_SEGMENT_PRIV_H_ */
