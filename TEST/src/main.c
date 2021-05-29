
/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <math.h>

/* MCAL includes */
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "ADC1_interface.h"

/* HAL includes */
#include "TempSensor_interface.h"

/* global var */
u16 val;
f32 celsius;
f32 temp;


void main(void)
{

	/* enabling RCC clock */
	RCC_voidInitSysClock();
	
	/* enable RCC for used prephirals */
	RCC_voidEnableClock(RCC_APB2, IOPA_PER);
	RCC_voidEnableClock(RCC_APB2, ADC1_PER);

	/* initiate the tempreture sensor */
	TempSensor_voidInit();


	while(1)
	{
		val = TempSensor_f32TempRead();

		/* calculating R using voltage devidor */
		val = (65535 / val) - 1;      						/* (65535/ADC - 1) */
		val = SERIESRESISTOR / val;  						/* 10K / (65535/ADC - 1) */

		/* calculating T */
		celsius = val / THERMISTORNOMINAL;     				/* (R/Ro) */
		//celsius = log(celsius);                  			/* ln(R/Ro) */
		celsius /= BCOEFFICIENT;                   			/* 1/B * ln(R/Ro) */
		celsius += 1.0 / (TEMPERATURENOMINAL + 273.15); 	/* + (1/To) */
		celsius = 1.0 / celsius;                 			/* Inverting the value */
		celsius -= 273.15;                         			/* convert K temp to C */
	}
}

