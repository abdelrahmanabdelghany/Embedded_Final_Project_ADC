/*
 * ADC.h
 *
 *  Created on: May 20, 2022
 *      Author: Abdelrahman Muhsen
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

#define USE_POLLING 1


typedef struct  {
	enum Resolution {twelve , ten , eight , six} RES;
	enum conversionMode {single , cont} CONV;
    char REFVoltage;
}  ADC_CONFIG;



void ADC_Init(ADC_CONFIG* ConfigParamPtr);
void ADC_StartConv(unsigned char ChannelNum);
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
unsigned char ADC_ReadData(unsigned short int* DataPtr);



#endif /* INCLUDE_ADC_H_ */
