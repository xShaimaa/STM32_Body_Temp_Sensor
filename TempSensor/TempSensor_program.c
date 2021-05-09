/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 				                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC1_interface.h"
#include "ADC1_private.h"
#include "ADC1_config.h"

#include "TempSensor_interface.h"
#include "TempSensor_private.h"
#include "TempSensor_config.h"


void TempSensor_voidInit(void)
{
	/* initializing ADC1 */
	ADC1_voidInit(void);
	
	/* Configuring RCC */
	
	/* configuring sensor's pin */
	MGPIO_VoidSetPinDir(TEMP_SENSOR_PORT, TEMP_SENSOR_PIN, u8 Copy_u8Mode, INPUT_TYPR);

}

u8 TempSensor_u8TempRead(void)
{
	
}

u8 TempSensor_u8CalcAvg(void)
{
	
}
