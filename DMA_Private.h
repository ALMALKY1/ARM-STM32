#ifndef DMA_PRIVATE_H_

#define DMA_PRIVATE_H_ 
#include "STD_TYPES.h" 




typedef struct {
	
	volatile uint32 DMA_CR ;
	volatile uint32 DMA_NDTR ;
	volatile uint32 DMA_PAR ; 
	volatile uint32 DMA_M0AR ;
	volatile uint32 DMA_M1AR;
	volatile uint32 DMA_FCR;
		
}Stream_Number_Confg; 




typedef struct {
	
	
	volatile uint32 DMA_LISR ;
	volatile uint32 DMA_HISR ;
	volatile uint32  DMA_LIFCR ; 
	volatile uint32 DMA_HIFCR ;
	volatile Stream_Number_Confg Stream_Number[8];
	         
}DMA_Type; 

#define DMA_1_PTR    ((DMA_Type*)0x40026000)
#define DMA_2_PTR    ((DMA_Type*)0x40026400)



#endif 
