/*
 * Temp_Sensor.h
 *
 * Created: 11/07/2020 06:47:11 ص
 *  Author: Ali
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "ADC.h"


void TempSensor_Init(void);

void TempSensor_Read(uint16* Temp);


#endif /* TEMP_SENSOR_H_ */