/****************************************************************************
*
* Layer : MCAL 
*  
* FIEL NAME : RCC_CONFIG 
*
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

typedef enum { 

	HSE = 0 , 
	HSI ,
  PLL
}SRC_Clk_Name; 

typedef enum { 

	HSE_RC = 0 , 
	HSE_Crystal

}HSE_Src_Type; 



typedef enum { 

	PLL_HSI = 0 , 
	PLL_HSE , 
	PLL_HSE_DIVID_TWO
}PLL_Src_Type; 


typedef enum { 

	AHB_Pres1 = 0 , 
	AHB_Pres2  ,
	AHB_Pres4  ,
	AHB_Pres8  ,
	AHB_Pres16  ,
	AHB_Pres64  ,
	AHB_Pres128  ,
	AHB_Pres512 
}AHB_presNum; 


typedef enum { 

	APB1_Pres1 = 0 , 
	APB1_Pres2  ,
	APB1_Pres4  ,
	APB1_Pres8  ,
	APB1_Pres16  ,
	
}APB1_presNum; 


typedef enum { 

	APB2_Pres1 = 0 , 
	APB2_Pres2  ,
	APB2_Pres4  ,
	APB2_Pres8  ,
	APB2_Pres16  ,
	
}APB2_presNum; 


