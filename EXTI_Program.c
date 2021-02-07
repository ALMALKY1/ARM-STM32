/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/


#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include 	"EXTI_Config.h"

#define NULL (void*)0
static void(* EXTI_Call_Back) (void) = NULL;

void vEXTI_Enable(uint8 Number_OF_line)
{

	EXTI_EMR |= (1U<<Number_OF_line);
	
}


void vEXTI_Disable(uint8 Number_OF_line)
{

	EXTI_EMR &=~(1U<<Number_OF_line);
	
}

void vEXTI_Event_Type(uint8 Number_OF_line)
{
#if TRIGGER_TYPE == EVENT_RISING
	
	EXTI_RTSR |= (1U<<Number_OF_line);
#elif TRIGGER_TYPE == EVENT_FALLING
	EXTI_FTSR |= (1U<<Number_OF_line);
	
#endif	
}


void vEXTI_SWIER_Trigger(uint8 Number_OF_line)
{
	EXTI_SWIER |= (1U<<Number_OF_line);
}


void vEXTI_CLEAR_PENDING(uint8 Number_OF_line)
{
	EXTI_PR |= (1U<<Number_OF_line);
	
}


void vEXTI_SET_PIN_PORT(uint8 Number_OF_line , PORT_ID PORT)
{
	if(Number_OF_line <= 3)
	{
		SYSCFG_EXTICR1 &=~(0b1111<<(Number_OF_line*4));
		SYSCFG_EXTICR1 |= (PORT<<(Number_OF_line*4));
	}
	
	else if(Number_OF_line <= 7)
	{
		Number_OF_line -= 4;
		SYSCFG_EXTICR2 &=~(0b1111<<(Number_OF_line*4));
		SYSCFG_EXTICR2 |= (PORT<<(Number_OF_line*4));
	}
	
	else if(Number_OF_line <=11)
	{
		Number_OF_line -= 4;
		SYSCFG_EXTICR3 &=~(0b1111<<(Number_OF_line*4));
		SYSCFG_EXTICR3 |= (PORT<<(Number_OF_line*4));
	}
	
	else if(Number_OF_line <= 15)
	{
		Number_OF_line -= 4;
		SYSCFG_EXTICR4 &=~(0b1111<<(Number_OF_line*4));
		SYSCFG_EXTICR4 |= (PORT<<(Number_OF_line*4));
	}
	
	
}

void vEXTI_Call_Back_Function(void (*call_back_ptr)(void))
{
	
	call_back_ptr = EXTI_Call_Back ;
	
}


#if LINE == LINE_0

static void EXTI0_IRQHandler (void)
{
	
	EXTI_Call_Back();
	vEXTI_CLEAR_PENDING(LINE_0);
	
}

#elif LINE == LINE_1


void EXTI1_IRQHandler (void)
{
		EXTI_Call_Back();
	vEXTI_CLEAR_PENDING(LINE_1);
	
	
	
	
	
}

#elif LINE == LINE_2
void EXTI2_IRQHandler (void)
{
	
		EXTI_Call_Back();
	vEXTI_CLEAR_PENDING(LINE_2);
	
	
	
	
}

#elif LINE == LINE_3


void EXTI3_IRQHandler (void)
{
	
	
	
		EXTI_Call_Back();
	vEXTI_CLEAR_PENDING(LINE_3);
	
	
}

#elif LINE == LINE_4
void EXTI4_IRQHandler (void)
{
	
	
		EXTI_Call_Back();
	vEXTI_CLEAR_PENDING(LINE_4);
	
	
	
}

#endif


