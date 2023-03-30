/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "gpio.h"
#include "LCD.h"
#include "ADC.h"

unsigned short int data;

int main(void)
{
	LCD_Init();
	LCD_ClearScreen();

	GPIO_Init(GPIOA,0,3,0);
	GPIOA->PUPDR &= ~(1<<0);
	GPIOA->PUPDR &= ~(1<<1);

	ADC_CONFIG config = {twelve, single , 0};

	ADC_Init(&config);

	for(int i=0;i<8;i++)
	{
	GPIO_Init(GPIOB,i,1,1);
	}

	u8 state=0;


	ADC_StartConv(0);


	if(USE_POLLING){
		while(1)
		{
			ADC_StartConv(0);
			LCD_ClearScreen();
			ADC_GetConversionState(&state);
			if(state && ~ADC_ReadData(&data)){
				LCD_IntToStr(data);
				for(int i=0;i<1000000;i++);
			}
		}

	}


}
void ISR(){
	LCD_ClearScreen();
	ADC_ReadData(&data);
	LCD_IntToStr(data);
	for(int i=0;i<1000000;i++);
	ADC_StartConv(0);
}

void ADC_IRQHandler(void){
	ISR();
}

