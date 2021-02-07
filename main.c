#include "STD_TYPES.h" 
#include "BIT_OP.h" 
#include "RCC_Interface.h"
#include "GPIO_Interface.h" 
#include "NVIC_interface.h" 
#include "EXTI_Interface.h"
#include "DMA_Interface.h" 

void Transfer_complete_DMA(void);

uint32 size ; 

int main (void)
{
	
vRCC_Init(HSE ,HSE_Crystal ,0,0 ,0,0);
vRCC_Enable(AHB1,22);
DMA_Init(Stream_Number_0,0,DMA_High);

	
	uint32 u32SRC_Array[size];
	uint32 u32DST_Array[size];
	
	uint32 INDEX ; 
	
for(INDEX = 0 ; INDEX <=size ; INDEX++)
	{		
		u32SRC_Array[INDEX]=INDEX;
	}

vNVIC_SET_ENABLE(11);	
DMA_Transfer(u32SRC_Array , u32DST_Array , Stream_Number_0,size);
DMA_Enable(Stream_Number_0);
DMA_Call_Back (Transfer_complete_DMA);	
	
}	
	
	
void Transfer_complete_DMA(void)
{
	
}
	 
	
	

	
	
	
