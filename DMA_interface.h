#ifndef DMA_INTERFACE_H_

#define DMA_INTERFACE_H_ 
#include "STD_TYPES.h" 
#include "DMA_Config.h"

#define M2M_Mode  1 
#define P2M_Mode  2 
#define M2P_Mode  3 

#define DMA_Number_1  1 
#define DMA_Number_2  2 

#define  FIFO_Threshold_1 1
#define  FIFO_Threshold_2 2
#define  FIFO_Threshold_3 3
#define  FIFO_Threshold_4 4

#define DIRECT_MODE_ENABLE  1 
#define DIRECT_MODE_DISABLE 2


#define 	M_Byte_size 0 
#define 	M_Half_Word_size 1
#define 	M_Word_size 2





#define 	P_Byte_size 0
#define 	P_Half_Word_size 1 
#define 	P_Word_size 2

#define  P_Increament_MODE_ENABLE 0
#define  P_Increament_MODE_DISABLE 1

#define  M_Increament_MODE_ENABLE 0
#define  M_Increament_MODE_DISABLE 1

#define 	Circular_MODE_ENABLE 0
#define  	Circular_MODE_DISABLE 1

#define 	TRANSFER_Complete_ENABLE 0
#define  	TRANSFER_Complete_DISABLE 1

#define 	HALF_TRANSFER_Complete_ENABLE 0
#define  	HALF_TRANSFER_Complete_DISABLE 1





void DMA_Init(Stream_Number Stream ,Channel_Selection Channel , Stream_Priority Value );
void DMA_Transfer(uint32* Adresses_of_Src , uint32 * Adresses_of_Dis ,Stream_Number Stream, uint32 Size ); 
void DMA_Enable(Stream_Number Stream);
void DMA_Call_Back(void(*call_back_DMA_ptr)(void));





#endif 