/****************************************************************************
*
* Layer : MCAL 
*  
* Author :  Mohamed Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/



#include "RCC_Config.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "BIT_OP.h"


void vRCC_Init(SRC_Clk_Name Src_Type , HSE_Src_Type HSE_Type , PLL_Src_Type PLL_Type , AHB_presNum AHB_Pres , APB1_presNum APB1_pres  , APB2_presNum APB2_pres )
{
	
	switch (Src_Type)
	{
		
		case 0 : 
						RCC_CR = 0x00000000;
						Set_Bit(RCC_CR, 16); 				
						while((Get_Bit(RCC_CR,17) && 0x1)!=1);
						Set_Bit(RCC_CFGR,0);
						RCC_CFGR &=~(1U<<1);
						
						switch (HSE_Type)
						{
							case 0: 
							Set_Bit(RCC_CR ,18);	
							break ; 
							case 1: 
							RCC_CFGR &=~(1U<<18);	
							break ; 
							
						}
		break;
		
		case 1 :
			
						Set_Bit(RCC_CR,0);
						while((Get_Bit(RCC_CR,1) && 0x1)!=1);
						RCC_CFGR &=~(1U<<0);
						RCC_CFGR &=~(1U<<1);

		break;
					
		case 2 : 
			
					switch(PLL_Type)
					{
						case 0:              
						Set_Bit(RCC_CR,0);
						while((Get_Bit(RCC_CR,1) && 0x1)!=1);
						Set_Bit(RCC_CR,24);
						while((Get_Bit(RCC_CR,25) && 0x1)!=1);
						RCC_CFGR &=~(1U<<24);
						RCC_CFGR &=~(1U<<0);
						Set_Bit(RCC_CFGR,1);
						
						break;
						
						case 1: 
							
						RCC_CR = 0x00000000;
						Set_Bit(RCC_CR, 16); 				
						while((Get_Bit(RCC_CR,17) && 0x1)!=1);
						
						RCC_CFGR &=~(1U<<0);
						Set_Bit(RCC_CFGR,1);
						
						switch (HSE_Type)
						{
							case 0: 
							Set_Bit(RCC_CR ,18);	
							break ; 
						
							case 1: 
							RCC_CR &=~(1U<<18);	
							break ; 
						}
						
						Set_Bit(RCC_CR,24);
						while((Get_Bit(RCC_CR,25) && 0x1)!=1);
						RCC_CFGR &=~(1U<<0);
						Set_Bit(RCC_CFGR,1);
						break;
						
					}
		
		break; 
		
	}
	
	

	switch(AHB_Pres)
	{
		
		case 0: 
		RCC_CFGR &=~(1U<<7);
		RCC_CFGR &=~(1U<<6);
		RCC_CFGR &=~(1U<<5);
		RCC_CFGR &=~(1U<<4);
			break; 
		
		case 1:
			
		RCC_CFGR |=(1U<<7); 
		RCC_CFGR &=~(1U<<6);
    RCC_CFGR &=~(1U<<5);
		RCC_CFGR &=~(1U<<4);
		break;
		
		case 2 : 
			RCC_CFGR |=(1U<<7);
		RCC_CFGR &=~(1U<<6);
		RCC_CFGR &=~(1U<<5);
		RCC_CFGR |=(1U<<4);
		
		break; 
		
		case 3 :
		RCC_CFGR |=(1U<<7);
		RCC_CFGR &=~(1U<<6);
		RCC_CFGR |=(1U<<5);
		RCC_CFGR &=~(1U<<4);
			break; 
		
		case 4:
		RCC_CFGR |=(1U<<7);
		RCC_CFGR &=~(1U<<6);
		RCC_CFGR |=(1U<<5);
		RCC_CFGR |=(1U<<4);
		break;
		case 5:
		RCC_CFGR |=(1U<<7);
		RCC_CFGR |=(1U<<6);
		RCC_CFGR &=~(1U<<5);
		RCC_CFGR &=~(1U<<4);
		break;
		case 6:
		RCC_CFGR |=(1U<<7);
		RCC_CFGR |=(1U<<6);
		RCC_CFGR &=~(1U<<5);
		RCC_CFGR |=(1U<<4);
		break;
		case 7:
		RCC_CFGR |=(1U<<7);
		RCC_CFGR |=(1U<<6);
		RCC_CFGR |=(1U<<5);
		RCC_CFGR &=~(1U<<4);
		break;
		case 8:
		RCC_CFGR |=(1U<<7);
		RCC_CFGR |=(1U<<6);
		RCC_CFGR |=(1U<<5);
		RCC_CFGR |=(1U<<4);
		break;

	}

	
	switch(APB1_pres)
	{
		case 0:
		
		RCC_CFGR &=~(1U<<12);
		RCC_CFGR &=~(1U<<11);
		RCC_CFGR &=~(1U<<10);
		break;
		case 1:
		RCC_CFGR |=(1U<<12);
		RCC_CFGR &=~(1U<<11);
		RCC_CFGR &=~(1U<<10);
		break;
		case 2:
		RCC_CFGR |=(1U<<12);
		RCC_CFGR &=~(1U<<11);
		RCC_CFGR |=(1U<<10);
		break;
		case 3:
		RCC_CFGR |=(1U<<12);
		RCC_CFGR |=(1U<<11);
		RCC_CFGR &=~(1U<<10);
		break;
		case 4:
		RCC_CFGR |=(1U<<12);
		RCC_CFGR |=(1U<<11);
		RCC_CFGR |=(1U<<10);
		break;
	
		
	}
	
	switch(APB2_pres)
	{
		case 0:
		
		RCC_CFGR &=~(1U<<15);
		RCC_CFGR &=~(1U<<14);
		RCC_CFGR &=~(1U<<13);
		break;
		case 1:
		RCC_CFGR |=(1U<<15);
		RCC_CFGR &=~(1U<<14);
		RCC_CFGR &=~(1U<<13);
		break;
		case 2:
		RCC_CFGR |=(1U<<15);
		RCC_CFGR &=~(1U<<14);
		RCC_CFGR |=(1U<<13);
		break;
		case 3:
		RCC_CFGR |=(1U<<15);
		RCC_CFGR |=(1U<<14);
		RCC_CFGR &=~(1U<<13);
		break;
		case 4:
		RCC_CFGR |=(1U<<15);
		RCC_CFGR |=(1U<<14);
		RCC_CFGR |=(1U<<13);
		break;
		
		
	}
	
	
	
}
	
void vRCC_Enable(PASS_Name PASS_ID , uint8 PreperiaL_ID)
{
	
	
	switch(PASS_ID)
	{
		case 0 : 
			RCC_AHB1ENR |= (1U<<PreperiaL_ID);
			break; 
		case 1 : 
			RCC_AHB2ENR |= (1U<<PreperiaL_ID);
			break;
		case 2 : 
			RCC_AHB3ENR |= (1U<<PreperiaL_ID);
			break;
		case 3: 
			RCC_APB1ENR |= (1U<<PreperiaL_ID);
			break; 
		case 4 : 
			RCC_APB2ENR |= (1U<<PreperiaL_ID);
			break;

	}
	
	
	
	
	
}
	
	
	
	
	
	
	
	
