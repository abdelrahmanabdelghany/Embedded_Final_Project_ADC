/*
 * inter.c
 *
 *  Created on: May 29, 2022
 *      Author: Abdelrahman Muhsen
 */
#include "inter.h"
#include "stm32f4xx.h"
#include "gpio.h"

void interruptInit(char interruptLine , char PORT, char edge)
{
	enum port myport =PORT;
	enum edge myedge =edge;
	// Enable clock access to sysconf
		RCC->APB2ENR|=(1<<14);

		// Set Selection lines of EXTI0

	  if (interruptLine < 4){
			SYSCFG->EXTICR[0] |= myport<<(interruptLine*4);
	  }
	  else if(interruptLine<8){
			SYSCFG->EXTICR[1] |= myport<<((interruptLine-4)*4);
	  }
	  else if (interruptLine<12){
			SYSCFG->EXTICR[2] |=myport<<((interruptLine-8)*4);
	  }
	  else {
			SYSCFG->EXTICR[3] |=myport<<((interruptLine-12)*4);
	  }


		// Configure the mask bit of exti0
		EXTI->IMR |=(1<<interruptLine);


		// Configure the Trigger  as falling trigger

		switch (myedge){
		 	 case 1:
				EXTI->RTSR |=(1<<interruptLine);
				break;
		 	 case 0:
		 		 EXTI->FTSR |=(1<<interruptLine);
				break;
		 	default:
				EXTI->RTSR |=(1<<interruptLine);
		 		break;
		}

		// enable EXTIx interruptLine from NVIC

		if(interruptLine>9){
			NVIC->ISER[1] |= (1<<8);
		}
		else if(interruptLine>4){
			NVIC->ISER[0] |= (1<<23);
		}
		else{
			NVIC->ISER[0] |= (1<<(interruptLine+6));
		}



}



