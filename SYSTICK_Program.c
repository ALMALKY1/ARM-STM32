/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Mohamed Almalky
*
* Data : 28/1/2021 11:50 pm 
*****************************************************************************/





#include "BIT_OP.h"
#include "SYSTICK_Private.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Interface.h"

static void (*CallBack_ptr)(void) ; 

static uint32 SYS_interval_value ;

void SYS_voidTickInit(void) {

#if  SYSTICK_SRC_CLOCK == SYS_CLOCK_MODE_AHB 
		
	SYSPTR -> CTRL |=(1<<2);
	
#else
	SYSPTR -> CTRL &=~(1<<2);

#endif	
	
}

void SYS_voidTick_Wait(uint32 value)
{
	

	SYSPTR -> LOAD = value ; 
	
	Set_Bit(SYSPTR -> CTRL , 0 );
	
	while(((SYSPTR -> CTRL)&(1<<16)) == 0);
  
	/* Stop Timer */
	SYSPTR -> CTRL &=~(1<<0);
	
	
	SYSPTR -> LOAD = 0 ; 
	SYSPTR -> VAL = 0 ; 
	

}


void SYS_voidTick_IntervalSignle(uint32 value , void (*ptr)(void))
{
	
	SYSPTR -> LOAD = value ; 
	/* Start Timer */
	Set_Bit(SYSPTR -> CTRL , 0 );
	
	CallBack_ptr = ptr ;
	
	SYS_interval_value = Interval_Single ;
	/* Enable STK Interrupt */
	Set_Bit(SYSPTR -> CTRL , 1 );
	
}


void SYS_voidTick_IntervalPeriodic(uint32 value , void (*ptr)(void)){
	
	SYSPTR -> LOAD = value ; 
	
	Set_Bit(SYSPTR -> CTRL , 0 );
	
	CallBack_ptr = ptr ;
	
	SYS_interval_value = Interval_periodic ;
	/* Enable STK Interrupt */
	Set_Bit(SYSPTR -> CTRL , 1 );
	
	
}



void SYS_voidTick_IntervalStop(void)
{
	/* Disable STK Interrupt */
		SYSPTR -> CTRL &=~(1<<1);
	/* Stop Timer */
		SYSPTR -> CTRL &=~(1<<0);
		SYSPTR -> LOAD = 0 ; 
		SYSPTR -> VAL = 0 ; 

}




uint32 SYS_u32Tick_GetElaspedTime(void)
{
	uint32 ELASPED_TIME; 
	ELASPED_TIME = SYSPTR -> LOAD - SYSPTR->VAL ;
	return ELASPED_TIME ;
	
}


uint32 SYS_u32Tick_GetRemaindingTime(void)
{
	
	uint32 Remainding_TIME; 
	Remainding_TIME = SYSPTR->VAL ;
	return Remainding_TIME ;
	
	
}


static void SysTick_Handler(void)
{
	
	
	uint32 TEMP_value ; 
	
	if(SYS_interval_value == Interval_Single )
	{
		/* Disable STK Interrupt */
		SYSPTR -> CTRL &=~(1<<1);
		
		SYSPTR -> CTRL &=~(1<<0);
		SYSPTR -> LOAD = 0 ; 
		SYSPTR -> VAL = 0 ; 
	}
	
	
	CallBack_ptr();
	TEMP_value = (((SYSPTR -> CTRL)&(1<16))==0);  

	
}











