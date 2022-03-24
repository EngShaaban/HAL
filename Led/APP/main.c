/*
 * main.c
 *
 *  Created on: Mar 23, 2022
 *      Author: SHAABAN
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/errorStates.h"

#include "../MCAL/DIO_interface.h"

#include "../HAL/Led_config.h"
#include "../HAL/Led_interface.h"

#ifndef F_CPU
#define F_CPU (16000000UL)
#endif

int main(void)
{
	ES_t LED_enuInit(  );
}

