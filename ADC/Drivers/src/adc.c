/*
 * ADC.c
 *
 *  Created on: May 20, 2022
 *      Author: Abdelrahman Muhsen
 */
#include "stm32f4xx.h"
#include "gpio.h"
#include "ADC.h"

void ADC_Init(ADC_CONFIG* ConfigParamPtr)
{
	RCC->APB2ENR|=(1<<8);
	ADC1->CR2|= (1<<0);
	ADC1->CR1|=((ConfigParamPtr->RES)<<24);
	ADC1->CR2|=((ConfigParamPtr->CONV)<<1);
	ADC1 ->CR2 &= ~ADC_CR2_ALIGN;


	if (USE_POLLING==0)
	{
		ADC1->CR1|=(1<<5); //E0C
		NVIC->ISER[0] |= (1 << 18);
	}
	else{
			ADC1 ->CR1 &= ~(1 << 5);
		}
}
void ADC_StartConv(unsigned char ChannelNum)
{
	ADC1->SQR1 &= ~(15 << 20);
	ADC1->SQR3|= (ChannelNum << 0);
	ADC1->DR &= 0;
	ADC1->CR2|=(1<<30);

}
void ADC_GetConversionState(unsigned char* ConversionStatePtr)
{
	if (USE_POLLING == 1 ){
	*ConversionStatePtr = (ADC1->SR & (1<<1 ));
	}

}
unsigned char ADC_ReadData(unsigned short int* DataPtr)
{
	if (ADC1->SR & 1<<5)  {
		return 1;
	}
	else
	{
		*DataPtr = (ADC1->DR * 150 * 5) / (1.5 * 4096);
		return 0;
	}
}



