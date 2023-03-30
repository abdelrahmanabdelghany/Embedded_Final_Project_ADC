#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"

const int no_raws = 4;
const int no_cols = 3;
char rows[4]={1,2,3,4}; //fill the array
char cols[3]={5,6,7}; //fill the array
char sevensegment[4]={12,13,14,15};
char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array
char currentvalue;


void KeyPad_INIT(void)
{
	// set input and ouput pins
		// get pins from raw and set it as input
		// get pins from cols and set it as output
	// hint use gpio driver functions

	for(int i = 0; i <no_raws ; i++)
	{
		GPIO_Init(GPIOB,rows[i],0,1);

		GPIOB->PUPDR=GPIOB->PUPDR  &~(1<<(2*rows[i])) ;
		GPIOB->PUPDR=GPIOB->PUPDR |(1<<(2*rows[i]+1)) ;
	}
	for(int i = 0; i <no_cols; i++)
	{
		GPIO_Init(GPIOB,cols[i],1,1);
	}

}


char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void sevensegment_init(void)
{
	for(int i=0; i<4;i++)
	{
		GPIO_Init(GPIOB,sevensegment[i],1,1);
	}
}


void KeyPad_MANAGE(void)
{
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton
	for(int i = 0; i <no_cols; i++)
		{
			GPIO_Write(GPIOB,cols[i],0);
		}
	for (int i = 0; i < no_cols; i++)
	{
		GPIO_Write(GPIOB,cols[i],1);
		for (int j = 0; j < no_raws; j++)
		{
			if(GPIO_Read(GPIOB,rows[j])){
				while(GPIO_Read(GPIOB,rows[j]))
				{
				}
				currentvalue=lookupTable[j][i];
				KeypadCallouts_KeyPressNotificaton();
			}
		}
		GPIO_Write(GPIOB,cols[i],0);
	}


}
void KeypadCallouts_KeyPressNotificaton(void)
{
	switch(currentvalue)
	{
	case 1:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,0);
		GPIO_Write(GPIOB,14,0);
		GPIO_Write(GPIOB,15,1);
		break;
	case 2:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,0);
		GPIO_Write(GPIOB,14,1);
		GPIO_Write(GPIOB,15,0);
		break;
	case 3:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,0);
		GPIO_Write(GPIOB,14,1);
		GPIO_Write(GPIOB,15,1);
		break;
	case 4:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,1);
		GPIO_Write(GPIOB,14,0);
		GPIO_Write(GPIOB,15,0);
		break;
	case 5:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,1);
		GPIO_Write(GPIOB,14,0);
		GPIO_Write(GPIOB,15,1);
		break;
	case 6:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,1);
		GPIO_Write(GPIOB,14,1);
		GPIO_Write(GPIOB,15,0);
		break;
	case 7:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,1);
		GPIO_Write(GPIOB,14,1);
		GPIO_Write(GPIOB,15,1);
		break;
	case 8:
		GPIO_Write(GPIOB,12,1);
		GPIO_Write(GPIOB,13,0);
		GPIO_Write(GPIOB,14,0);
		GPIO_Write(GPIOB,15,0);
		break;
	case 9:
		GPIO_Write(GPIOB,12,1);
		GPIO_Write(GPIOB,13,0);
		GPIO_Write(GPIOB,14,0);
		GPIO_Write(GPIOB,15,1);
		break;
	case 0:
		GPIO_Write(GPIOB,12,0);
		GPIO_Write(GPIOB,13,0);
		GPIO_Write(GPIOB,14,0);
		GPIO_Write(GPIOB,15,0);
		break;
	default:
		break;
	}
}


