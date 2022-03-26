/*
 * GPS_Cnfg.c
 *
 *  Created on: Mar 15, 2022
 *      Author: SHAABAN
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"


#include "../../MCAL/DIO/DIO_interface.h"

#include "GPS_Priv.h"
#include "GPS_Cnfg.h"


GPS_t  GPS =
{
		.GPS_STATE_t =      gps_on     ,

		.GPS_VCC_PORT=      DIO_PORTA  ,
		.GPS_VCC_PIN =      DIO_PIN0   ,

		.GPS_GND_PORT=      DIO_PORTA  ,
        .GPS_GND_PIN =      DIO_PIN1   ,
};
