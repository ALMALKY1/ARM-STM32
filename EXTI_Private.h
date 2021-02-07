/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/


#ifndef _EXTI_PRIVATE_H_

#define _EXTI_PRIVATE_H_
#include "STD_TYPES.h"

#define EXTI_BASE_ADRESS 				0x40013C00
#define EXTI_SYSCFG_ADRESS    	0x40013800


#define EXTI_EMR   	*((uint32*)(EXTI_BASE_ADRESS + 0x04))
#define EXTI_RTSR   *((uint32*)(EXTI_BASE_ADRESS + 0x08))
#define EXTI_FTSR   *((uint32*)(EXTI_BASE_ADRESS + 0x0C))
#define EXTI_SWIER  *((uint32*)(EXTI_BASE_ADRESS + 0x10))
#define EXTI_PR   	*((uint32*)(EXTI_BASE_ADRESS +0x14))

#define SYSCFG_EXTICR1 			*((uint8*)( EXTI_SYSCFG_ADRESS+0x08))
#define SYSCFG_EXTICR2 			*((uint8*)( EXTI_SYSCFG_ADRESS+0x0C))
#define SYSCFG_EXTICR3 			*((uint8*)( EXTI_SYSCFG_ADRESS+0x10))
#define SYSCFG_EXTICR4 			*((uint8*)( EXTI_SYSCFG_ADRESS+0x14))



#define EVENT_RISING 0 
#define EVENT_FALLING 1


#endif 
