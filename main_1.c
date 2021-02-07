#include "STD_TYPES.h" 
#include "BIT_OP.h" 

#include "RCC_Interface.h"
#include "GPIO_Interface.h" 
#include "NVIC_interface.h" 
#include "EXTI_Interface.h"
#include "SYSTICK_Interface.h"
#include "DOTMATRIX_interface.h"



int main (void)
{
	
	vRCC_Init(HSE ,HSE_Crystal ,0,0 ,0,0);
	vRCC_Enable(AHB1,0);
	vRCC_Enable(AHB1,1);
	
	
	
	SYS_voidTickInit();
	DOTMATRIX_Init();
	
	uint8 Display [8] = {0 , 124 , 18 , 18 , 124 , 0 , 0 };
	
	while (1)
	{
	DOTMATRIX_Display(Display);
	}
	
}
	
