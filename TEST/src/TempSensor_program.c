/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 				                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <math.h>

#include "ADC1_interface.h"

#include "TempSensor_interface.h"
#include "TempSensor_private.h"
#include "TempSensor_config.h"


void TempSensor_voidInit(void)
{
	/* initializing ADC1 */
	ADC1_voidInit(void);
		
	/* configuring sensor's pin */
	MGPIO_VoidSetPinDir(TEMP_SENSOR_PIN, INPUT_TYPR);
}

f328 TempSensor_f32TempRead(void)
{
	u16 Loc_u16val = 0;
	f32 Loc_f32celsius = 0.0;

	/* reading ADC1 value */
	Loc_u16val = ADC1_u16GetRegularVal();

	/* calculating R */
	Loc_u16val = (65535 / Loc_u16val) - 1;      					/* (65535/ADC - 1) */
	Loc_u16val = SERIESRESISTOR / Loc_u16val;  						/* 10K / (65535/ADC - 1) */

	/* calculating T */
	Loc_f32celsius = Loc_u16val / THERMISTORNOMINAL;     			/* (R/Ro) */
	Loc_f32celsius = log(Loc_f32celsius);                  			/* ln(R/Ro) */
	Loc_f32celsius /= BCOEFFICIENT;                   				/* 1/B * ln(R/Ro) */
	Loc_f32celsius += 1.0 / (TEMPERATURENOMINAL + 273.15); 			/* + (1/To) */
	Loc_f32celsius = 1.0 / Loc_f32celsius;                 			/* Invert */
	Loc_f32celsius -= 273.15;                         				/* convert K temp to C */
	
	return(Loc_f32celsius);
}

u8 TempSensor_u8CalcAvg(void)
{
	
}
