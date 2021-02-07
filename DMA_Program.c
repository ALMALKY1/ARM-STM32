/****************************************************************************
*
* Layer : MCAL 
*  
* Author :Mohamed Almalky
*
* Data : 2/6/2021 12:04 AM 
*****************************************************************************/

#include "STD_TYPES.h" 
#include "BIT_OP.h" 
#include "DMA_Interface.h"
#include "DMA_Private.h"
#include "DMA_Config.h"

#define NULL  (void*)0 
static void (*ptr_DMA1)(void) = NULL ;
static void (*ptr_DMA2)(void) = NULL ;

void DMA_Init(Stream_Number Stream ,Channel_Selection Channel , Stream_Priority Value )
{

#if  DMA_Number == DMA_Number_1 
	
	//DISABLE THE STREAM 
	if(DMA_1_PTR -> Stream_Number[Stream].DMA_CR==1)
	{
	DMA_1_PTR ->Stream_Number[Stream].DMA_CR &= ~(1U<<0);
	}
	while(DMA_1_PTR -> Stream_Number[Stream].DMA_CR==1){}

		//DMA MODE 
#if  DMA_Mode != M2M_Mode 

		
if(DMA_Mode == M2P_Mode)
	
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (M2P_Mode<<6); 

else if (DMA_Mode==P2M_Mode)
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (P2M_Mode<<6);
		
else 
	
		//CLK CHANNEL  

		switch(Channel)
		{
			
			case  channel1_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
		
				case  channel2_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
				
					case  channel3_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
					
						case  channel4_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
						
							case  channel5_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
							
								case  channel6_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
									case  channel7_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
										case  channel8_selected:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
									
		}
#endif

		// PRIPORITY 
switch(Value)
		{
			
			case DMA_Low:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (DMA_Low<< 16);	
			break;
		
				case DMA_Medium  :
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (DMA_Medium<< 16);	
			break;
				
					case  DMA_High :
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (DMA_High<< 16);	
			break;
					
						case  DMA_Very_high:
						DMA_1_PTR -> Stream_Number[Stream].DMA_CR = (DMA_Very_high<< 16);	
			break;
	
		}
		
		//SIZE_OF_DATA_OR_PERIPERAL 
		
#if Memory_size == M_Byte_size 
		
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<13);
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<14);
		
		
#elif Memory_size == M_Half_Word_size 
		
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<13);
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<14);
		
#elif Memory_size == M_Word_size 
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<13);
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<14);
		
		
#endif		
	
#if Periperal_Size == P_Byte_size 
		
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<11);
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<12);
		
		
#elif Periperal_Size == M_Half_Word_size 
		
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<11);
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<12);
		
#elif Periperal_Size == M_Word_size 
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<11);
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<12);
		
		
#endif		
				//Direct_MODE
	
#if DIRECT_MODE == DIRECT_MODE_ENABLE 
		DMA_1_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<1);
#elif DIRECT_MODE == DIRECT_MODE_DISABLE 
		DMA_1_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<1);
		
#endif

		//INCREAMENT_MODE
		
		
#if P_Increament_MODE == P_Increament_MODE_ENABLE 
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<9);
#elif P_Increament_MODE == P_Increament_MODE_DISABLE 
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<9);
		
#endif

	
#if M_Increament_MODE == M_Increament_MODE_ENABLE 
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<10);
#elif M_Increament_MODE == M_Increament_MODE_DISABLE 
		DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<10);
		
#endif

//  Circular mode 


#if Circular_Mode == Circular_MODE_ENABLE 

DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<8);

#elif

DMA_1_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<8);

#endif
		
		
		
		
#if DMA_FIF0_Level == FIFO_Threshold_1 

DMA_1_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<0);
DMA_1_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<1);		
		
		
#elif DMA_FIF0_Level == FIFO_Threshold_2 

DMA_1_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<0);
DMA_1_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<1);		
	
	
		
#elif DMA_FIF0_Level == FIFO_Threshold_3 

DMA_1_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<0);
DMA_1_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<1);	
	
	
			
#elif DMA_FIF0_Level == FIFO_Threshold_4 

DMA_1_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<0);
DMA_1_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<1);		
	
#endif


#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE 

	DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<4);
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<3);	
#endif 	
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<2);
	
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<1);
	
	


		
#elif DMA_Number == 2

	//DISABLE THE STREAM 
	if(DMA_2_PTR -> Stream_Number[Stream].DMA_CR==1)
	{
	DMA_1_PTR ->Stream_Number[Stream].DMA_CR &= ~(1U<<0);
	}
	while(DMA_2_PTR -> Stream_Number[Stream].DMA_CR==1){}

		//DMA MODE 
#if  DMA_Mode != M2M_Mode 

		
if(DMA_Mode == M2P_Mode)
	
	DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (M2P_Mode<<6); 

else if (DMA_Mode==P2M_Mode)
	DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (P2M_Mode<<6);
		
else 
	
		//CLK CHANNEL  

		switch(Channel)
		{
			
			case  channel1_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
		
				case  channel2_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
				
					case  channel3_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
					
						case  channel4_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
						
							case  channel5_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
							
								case  channel6_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
									case  channel7_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
										case  channel8_selected:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (Channel<< 25);	
			break;
										default : break;
		}

#endif
		// PRIPORITY 
switch(Value)
		{
			
			case DMA_Low:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (DMA_Low<< 16);	
			break;
		
				case DMA_Medium  :
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (DMA_Medium<< 16);	
			break;
				
					case  DMA_High :
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (DMA_High<< 16);	
			break;
					
						case  DMA_Very_high:
						DMA_2_PTR -> Stream_Number[Stream].DMA_CR = (DMA_Very_high<< 16);	
			break;
	
		}
		
		//SIZE_OF_DATA_OR_PERIPERAL 
		
#if Memory_size == M_Byte_size 
		
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<13);
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<14);
		
		
#elif Memory_size == M_Half_Word_size 
		
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<13);
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<14);
		
#elif Memory_size == M_Word_size 
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<13);
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<14);
		
		
#endif		
	
#if Periperal_Size == P_Byte_size 
		
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<11);
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<12);
		
		
#elif Periperal_Size == M_Half_Word_size 
		
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<11);
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<12);
		
#elif Periperal_Size == M_Word_size 
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<11);
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<12);
		
		
#endif		
				//Direct_MODE
	
#if DIRECT_MODE == DIRECT_MODE_ENABLE 
		DMA_2_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<1);
#elif DIRECT_MODE == DIRECT_MODE_DISABLE 
		DMA_2_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<1);
		
#endif

		//INCREAMENT_MODE
		
		
#if P_Increament_MODE == P_Increament_MODE_ENABLE 
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<9);
#elif P_Increament_MODE == P_Increament_MODE_DISABLE 
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<9);
		
#endif

	
#if M_Increament_MODE == M_Increament_MODE_ENABLE 
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<10);
#elif M_Increament_MODE == M_Increament_MODE_DISABLE 
		DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<10);
		
#endif

//  Circular mode 


#if Circular_Mode == Circular_MODE_ENABLE 

DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<8);

#elif

DMA_2_PTR -> Stream_Number[Stream].DMA_CR &=~(1U<<8);

#endif
		
		
		
		
#if DMA_FIF0_Level == FIFO_Threshold_1 

DMA_2_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<0);
DMA_2_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<1);		
		
		
#elif DMA_FIF0_Level == FIFO_Threshold_2 

DMA_2_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<0);
DMA_2_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<1);		
	
	
		
#elif DMA_FIF0_Level == FIFO_Threshold_3 

DMA_2_PTR -> Stream_Number[Stream].DMA_FCR &=~(1U<<0);
DMA_2_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<1);	
	
	
			
#elif DMA_FIF0_Level == FIFO_Threshold_4 

DMA_2_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<0);
DMA_2_PTR -> Stream_Number[Stream].DMA_FCR |= (1U<<1);		
	
#endif

#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE 

	DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<4);
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<3);	
#endif 	
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<3);
	
	DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<1);

	
#endif
		
}

void DMA_Transfer(uint32* Adresses_of_Src , uint32 * Adresses_of_Dis ,Stream_Number Stream, uint32 Size  )
{
	#if  DMA_Number == DMA_Number_1 
	if(DMA_Mode == M2M_Mode)
	{
	DMA_1_PTR -> Stream_Number[Stream].DMA_M1AR =(uint32)Adresses_of_Src ;
	DMA_1_PTR -> Stream_Number[Stream].DMA_M0AR =(uint32)Adresses_of_Dis ;	
	}
	else if (DMA_Mode == M2P_Mode)
	{
	DMA_1_PTR -> Stream_Number[Stream].DMA_M0AR =(uint32)Adresses_of_Src ;
	DMA_1_PTR -> Stream_Number[Stream].DMA_PAR =(uint32)Adresses_of_Dis ;
	}
	
	else if (DMA_Mode == P2M_Mode)
	{
	DMA_1_PTR -> Stream_Number[Stream].DMA_PAR =(uint32)Adresses_of_Src ;
	DMA_1_PTR -> Stream_Number[Stream].DMA_M0AR =(uint32)Adresses_of_Dis ;
	}
	else {
	}
	
	
	
	DMA_1_PTR -> Stream_Number[Stream].DMA_NDTR = Size ;
	
	
	
	
			
#elif DMA_Number == 2


	if(DMA_Mode == M2M_Mode)
	{
	DMA_2_PTR -> Stream_Number[Stream].DMA_M1AR =(uint32)Adresses_of_Src ;
	DMA_2_PTR -> Stream_Number[Stream].DMA_M0AR =(uint32)Adresses_of_Dis ;	
	}
	else if (DMA_Mode == M2P_Mode)
	{
	DMA_2_PTR -> Stream_Number[Stream].DMA_M0AR =(uint32)Adresses_of_Src ;
	DMA_2_PTR -> Stream_Number[Stream].DMA_PAR =(uint32)Adresses_of_Dis ;
	}
	
	else if (DMA_Mode == P2M_Mode)
	{
	DMA_2_PTR -> Stream_Number[Stream].DMA_PAR =(uint32)Adresses_of_Src ;
	DMA_2_PTR -> Stream_Number[Stream].DMA_M0AR =(uint32)Adresses_of_Dis ;
	}
	else {
	}
	
	
	
	DMA_2_PTR -> Stream_Number[Stream].DMA_NDTR = Size ;
	
		
	
#endif
	

	
}



void DMA_Enable(Stream_Number Stream)
{
	
#if	DMA_Number == DMA_Number_1

	DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	DMA_1_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<0);
	
		
#elif DMA_Number == 2

	DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	DMA_2_PTR -> Stream_Number[Stream].DMA_CR |= (1U<<0);


	
#endif
	
}

void DMA1_Call_Back(void(*call_back_DMA_ptr)(void))
{
	ptr_DMA1 = call_back_DMA_ptr;
}



#if  DMA_Number == DMA_Number_1

static void DMA1_Stream0_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	 DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 ptr_DMA();
  }
	
	
#endif
}


static void DMA1_Stream1_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	 DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 ptr_DMA1();
  }
	
	
#endif
}


static void DMA1_Stream2_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	 DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 ptr_DMA1();
  }
	
	
#endif
}


static void DMA1_Stream3_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	 DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	 ptr_DMA1();
  }
	
	
#endif
}



static void DMA1_Stream4_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	ptr_DMA1();
  }
	
	
#endif
}



static void DMA1_Stream5_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	ptr_DMA1();
  }
	
	
#endif
}


static void DMA1_Stream6_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	ptr_DMA1();
  }
	
	
#endif
}


static void DMA1_Stream7_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_1_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_1_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA1();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	ptr_DMA1();
  }
	
	
#endif
}



#elif DMA_Number == DMA_Number_2


void DMA2_Call_Back(void(*call_back_DMA_ptr)(void))
{
	ptr_DMA2 = call_back_DMA_ptr;
}




static void DMA2_Stream1_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  ptr_DMA2();
  }
	
	
#endif
}


static void DMA2_Stream2_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  ptr_DMA2();
  }
	
	
#endif
}


static void DMA2_Stream3_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  ptr_DMA2();
  }
	
	
#endif
}



static void DMA2_Stream4_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  ptr_DMA2();
  }
	
	
#endif
}



static void DMA2_Stream5_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  ptr_DMA2();
  }
	
	
#endif
}


static void DMA2_Stream6_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  ptr_DMA2();
  }
	
	
#endif
}


static void DMA2_Stream7_IRQHandler (void)
{
	
#if TRANSFER_Complete_Mode  == TRANSFER_Complete_ENABLE  	
	if(DMA_1_PTR -> DMA_LISR & (1<<5))
	{
		//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
		ptr_DMA2();	
	}
#elif HALF_TRANSFER_Complete_MODE == 	HALF_TRANSFER_Complete_ENABLE
	if(DMA_1_PTR -> DMA_LISR & (1<<4))
	{
	//Clear flag
		DMA_2_PTR -> DMA_HIFCR |=	(1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
	  DMA_2_PTR -> DMA_LIFCR |= (1U<<0)| (1U<<2) |(1U<<3)|(1U<<4)|(1U<<5);
  	ptr_DMA2();
  }
	
	
#endif
}

#endif 


