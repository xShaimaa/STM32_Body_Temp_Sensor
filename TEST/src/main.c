
/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

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

	}
}

