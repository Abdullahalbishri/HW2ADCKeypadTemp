/*
 * CFile1.c
 *
 * Created: 09/07/2020 04:49:04 م
 *  Author: 
 */ 


#include "ADC.h"



void ADC_Init(ADC_VOLTAGE_REFRENCE V,CHANNELS C ,ADCAdjustResult R ,ADCConversionTrigger T ,ADCPrescalerSelectBits S ,ADCInterruptStatus I)//Generic ADC function
{
	

	switch(V)//Voltage Reference Selection ->Regiser ADMUX bit 7,6 REFS1,REFS0
	{
	case AREFInternalVrefTurnedOff:
	CLR_BIT(ADMUX,7);
	CLR_BIT(ADMUX,6);
	break;
	case AVCCWithExternalCapacitorAtAREFPin:
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	break;
	case Internal2point56vVoltageReferenceWithExternalCapacitorAtAREFPin:
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	break;
	default:break;
	}



	switch(C)//Input Channel and Gain Selections ->Regiser ADMUX bit 0,1,2,3,4 MUX0,MUX1,MUX2,MUX3,MUX4
	{
	case Channel_0:
	CLR_BIT(ADMUX,0);
	break;
	case Channel_1:
	SET_BIT(ADMUX,0);
	break;
	case Channel_2:
	SET_BIT(ADMUX,1);
	case Channel_3:
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	break;
	case Channel_4:
	SET_BIT(ADMUX,2);
	break;
	case Channel_5:
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,2);
	break;
	case Channel_6:
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	break;
	case Channel_7:
	SET_BIT(ADMUX,0);
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,2);
	break;
	default:
	break;
	}

	switch(R)//ADLAR: ADC Left Adjust Result ->Regiser ADMUX bit 5 ADLAR
	{
	case ADCRightAdjust:
	CLR_BIT(ADMUX,5);
	break;
	case ADCLeftAdjust:
	SET_BIT(ADMUX,5);
	break;
	default:
	break;
	}
	
	
	switch(T)//ADC Auto Trigger Enable ->Regiser ADCSRA bit 5 ADATE
	{
	case ADCAutoTriggerEnable:
	SET_BIT(ADCSRA,5);
	break;
	case ADCAutoTriggerDisable:
	CLR_BIT(ADCSRA,5);
	break;
	default:
	break;
	}
	

	switch(S)//ADC Prescaler Select Bits ->Regiser ADCSRA bit 0,1,2 ADPS0,ADPS1,ADPS2
	{
	case ADCPreScal2:
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	break;
	case ADCPreScal4:
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	break;
	case ADCPreScal8:
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	break;
	case ADCPreScal16:
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break;
	case ADCPreScal32:
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break;
	case ADCPreScal64:
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break;
	case ADCPreScal128:
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	break;
	default:
	break;
	}

	switch(I)//ADC Interrupt Enable ->Regiser ADCSRA bit 3 ADIE
	{
	case ADCInterruptEnable:
	SET_BIT(ADCSRA , 3);
	break;
	case ADCInterruptDisable:
	CLR_BIT(ADCSRA , 3);
	break;
	default:
	break;
	}
	
		//ADC Enable */
	SET_BIT(ADCSRA,7);
		
}

void ADC_Read(uint16* Analog_Value ,ADCInterruptStatus I)
{
	
	uint16 Digital_Value = 0;
	
	/* Start Conversion*/
	SET_BIT(ADCSRA,6);
	
	if(I !=ADCInterruptEnable)
	{
	while( ! GET_BIT(ADCSRA,4) );
	
	Digital_Value = ADC_Adjust; //(ADCH << 2) | (ADCL >>6);
	
	*Analog_Value = ((Digital_Value * 500) / 1024) ;
	}
}