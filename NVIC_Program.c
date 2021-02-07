/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

#include "NVIC_interface.h"
#include "NVIC_Private.h"





void vNVIC_SET_ENABLE(uint8 U8Interrupt_Number)
{
	
	if(U8Interrupt_Number <= 31)
	{
	NVIC_ISER0 |= (1U<< U8Interrupt_Number );
	}
	
	else if ((U8Interrupt_Number >=31) && (U8Interrupt_Number<=63)){
	
		U8Interrupt_Number -=32;
		NVIC_ISER1 |= (1U<< U8Interrupt_Number );
	}
	
	
}




void vNVIC_Clear_ENABLE(uint8 U8Interrupt_Number)
{
	
	if(U8Interrupt_Number <= 31)
	{
	NVIC_ICER0 |= (1U<< U8Interrupt_Number );
	}
	
	else  if ((U8Interrupt_Number >= 31) &&(U8Interrupt_Number<=63))
	{
		U8Interrupt_Number -=32;
	NVIC_ICER1 |= (1U<< U8Interrupt_Number );
	}
	
	
}

void vNVIC_SET_PendingFlag(uint8 U8Interrupt_Number)
{
	if(U8Interrupt_Number <=31)
	{
		NVIC_ISPR0 |=	(1U<<U8Interrupt_Number);
	}
	else if ((U8Interrupt_Number >=31)&& (U8Interrupt_Number<=63)){
		U8Interrupt_Number -=32;
	  NVIC_ISPR1 |=	(1U<<U8Interrupt_Number);
		
	}
	
	
}


void vNVIC_Clear_PendingFlag(uint8 U8Interrupt_Number)
{
	if(U8Interrupt_Number<=31)
	{
		NVIC_ICPR0 |=(1U<<U8Interrupt_Number);
	}
	
	else if((U8Interrupt_Number >=31) && (U8Interrupt_Number<=63))
	{
		U8Interrupt_Number -=32;
		NVIC_ICPR1 |=(1U<<U8Interrupt_Number);
	}
	
	
}


uint8 u8NVIC_Read_ActiveFlag (uint8 U8Interrupt_Number)
{
	uint8 Value  ; 
	
	if(U8Interrupt_Number <=31)
	{
		Value = ((NVIC_IABR0>>U8Interrupt_Number)& 0x01);	
	}
	
	else if ((U8Interrupt_Number >31) && (U8Interrupt_Number <=63))
	{
		U8Interrupt_Number -=32;
		Value = ((NVIC_IABR0>>U8Interrupt_Number)& 0x01);
	}
	
	return Value ;
	
}


void vNVIC_Set_Priority(uint8 GROUP_Priority , uint8 SUB_Priority , uint8 U8Interrupt_Number)
{

	#if PRIORITY_CFG == 0
	AIRCR = 0xFA050300 ;
	NVIC_IPR0[U8Interrupt_Number] |= ( GROUP_Priority << 4U );
	
	#elif PRIORITY_CFG == 1
	AIRCR = 0xFA050400 ;
	NVIC_IPR0[U8Interrupt_Number] |= (( GROUP_Priority << 5U )&(SUB_Priority <<4U));
	
	#elif PRIORITY_CFG == 2
	AIRCR = 0xFA050500 ;
	NVIC_IPR0[U8Interrupt_Number] |= (( GROUP_Priority << 6U )&(SUB_Priority <<4U));
	
	
	#elif PRIORITY_CFG == 3
	AIRCR = 0xFA050600 ;
	NVIC_IPR0[U8Interrupt_Number] |= (( GROUP_Priority << 7U )&(SUB_Priority <<4U));
	
	
	#elif PRIORITY_CFG == 4
	AIRCR = 0xFA050700 ;
	NVIC_IPR0[U8Interrupt_Number] |= (SUB_Priority <<4U));
	
	
#endif
	
	

	
	
}

