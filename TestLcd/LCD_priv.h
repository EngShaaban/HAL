/*
 * LCD_priv.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_
/********************* Ana  ******************/
#define LCD_8BIT_FUNC_SET        0x38

#define LCD_4BIT_FUNC_SET        0x28

#define LCD_CLEAR                0X01

#define LCD_RETURN_HOME          0X02


#define LCD_DIPON_CUROFF   0x0C

#define LCD_CURSOR_INCRMNT_RIGHT_AUTO     0x06

#define LCD_DISP_OFF_CUR_OFF              0x08

#define LCD_DISP_ON_CUR_OFF              0x0C


#define LCD_SHIFT_DISP_TO_RIGHT              0x1C

#define LCD_CUR_GOTO_FIRST_LINE              0x80
#define LCD_CUR_GOTO_SECND_LINE              0xC0





#define LCD_DIPOFF_CUROFF   0X08

/**********************************************/


#define EIGHT_BIT	51
#define FOUR_BIT	9




static inline void LCD_invidSendCommend(u8 Copy_u8Command);

static void LCD_vidLatch(u8 Copy_u8Data);

#endif /* LCD_PRIV_H_ */
