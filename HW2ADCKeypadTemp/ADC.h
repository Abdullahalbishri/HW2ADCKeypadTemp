/*
 * ADC.h
 *
 * Created: 09/07/2020 04:49:28 م
 *  Author: Ali
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"
#include "ADC_Cfg.h"

typedef enum {AREFInternalVrefTurnedOff,AVCCWithExternalCapacitorAtAREFPin,Internal2point56vVoltageReferenceWithExternalCapacitorAtAREFPin}ADC_VOLTAGE_REFRENCE;
//#define  ADC_VREF_AVCC         0 =AVCC with external capacitor at AREF pin

typedef enum {Channel_0,Channel_1,Channel_2,Channel_3,Channel_4,Channel_5,Channel_6,Channel_7}CHANNELS;
//#define  ADC_CHANNEL_1         1

typedef enum{ADCRightAdjust,ADCLeftAdjust}ADCAdjustResult;
//#define  ADC_RIGHT_ADJUST      1

typedef enum{ADCAutoTriggerEnable,ADCAutoTriggerDisable}ADCConversionTrigger;
//#define  ADC_AUTO_TRIGGER      0

typedef enum{ADCPreScal2,ADCPreScal4,ADCPreScal8,ADCPreScal16,ADCPreScal32,ADCPreScal64,ADCPreScal128}ADCPrescalerSelectBits;
//#define  ADC_PRESC_128         0

typedef enum{ADCInterruptEnable,ADCInterruptDisable}ADCInterruptStatus;
//#define  ADC_INTERRUPT_ENABLE   0

//#define  ADC_INTERRUPT_DISABLE  1


/**********************************  APIs  **************************************/


void ADC_Init(ADC_VOLTAGE_REFRENCE,CHANNELS,ADCAdjustResult,ADCConversionTrigger,ADCPrescalerSelectBits,ADCInterruptStatus);

void ADC_Read(uint16* value ,ADCInterruptStatus);


#endif /* ADC_H_ */