#ifndef DMA_CONFIG_H_

#define DMA_CONFIG_H_ 
#include "STD_TYPES.h"

/*

 M2M_Mode  1 
 P2M_Mode  2 
 M2P_Mode  3 

*/ 


#define DMA_Mode 3


/*
 DMA_Number_1  1 
 DMA_Number_2  2 
*/


#define DMA_Number  1


/*
FIFO_Threshold_1  1/4 full FIFO     0 
FIFO_Threshold_2	1/2 full FIFO     1 
FIFO_Threshold_3  3/4 full FIFO     2 
FIFO_Threshold_4  full FIFO         3
*/
#define DMA_FIF0_Level 0

/*

 DIRECT_MODE_ENABLE  1 
 DIRECT_MODE_DISABLE 2
*/

#define  DIRECT_MODE 1 


typedef enum {

 Stream_Number_0 , 
 Stream_Number_1 ,
 Stream_Number_2 , 
 Stream_Number_3 , 
 Stream_Number_4 , 
 Stream_Number_5 , 
 Stream_Number_6 , 
 Stream_Number_7 ,
 Stream_Number_8 ,
}Stream_Number; 


typedef enum { 
 channel1_selected ,
 channel2_selected ,
 channel3_selected ,
 channel4_selected ,
 channel5_selected ,
 channel6_selected ,
 channel7_selected ,
 channel8_selected ,
	
}Channel_Selection;

typedef enum {
	DMA_Low,
	DMA_Medium,
	DMA_High,
	DMA_Very_high,
}Stream_Priority;



/*

 	M_Byte_size 0 
 	M_Half_Word_size 1
 	M_Word_size 2
*/


#define Memory_size 0

/*
 	P_Byte_size 0
 	P_Half_Word_size 1 
 	P_Word_size 2
*/


#define Periperal_Size 1 



/*

 P_Increament_MODE_ENABLE  0 
 P_Increament_MODE_DISABLE 1
*/

#define P_Increament_MODE 1



/*

 M_Increament_MODE_ENABLE  0 
 M_Increament_MODE_DISABLE 1
*/

#define M_Increament_MODE 1



/*	

Circular_ENABLE 0 
Circular_DISABLE 1 

*/

#define Circular_Mode 0



/*	

TRANSFER_Complete_ENABLE 0 
TRANSFER_Complete_DISABLE 1 

*/

#define TRANSFER_Complete_Mode 0




/*	

HALF_TRANSFER_Complete_ENABLE 0 
HALF_TRANSFER_Complete_DISABLE 1 

*/

#define HALF_TRANSFER_Complete_MODE 0


#endif 