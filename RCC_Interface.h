/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

#ifndef RCC_INTERFACE_H

#define RCC_INTERFACE_H

#include "RCC_Config.h"
#include "STD_TYPES.h"

void vRCC_Init(SRC_Clk_Name Src_Type , HSE_Src_Type HSE_Type , PLL_Src_Type PLL_Type , AHB_presNum AHB_Pres , APB1_presNum APB1_pres  , APB2_presNum APB2_pres );

void vRCC_Enable(PASS_Name PASS_ID , uint8 PreperiaL_ID);






#endif 
