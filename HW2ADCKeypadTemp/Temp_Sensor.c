/*
 * CFile1.c
 *
 * Created: 11/07/2020 06:46:35 ص
 *  Author: Ali
 */ 


#include "Temp_Sensor.h"



void TempSensor_Init(void)
{
	ADC_Init(AVCCWithExternalCapacitorAtAREFPin,Channel_1,ADCRightAdjust,ADCAutoTriggerEnable,ADCPreScal128,ADCInterruptDisable);
}

void TempSensor_Read(uint16* Temp)
{
	ADC_Read(Temp,ADCInterruptDisable); 
}
