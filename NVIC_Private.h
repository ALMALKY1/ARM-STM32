/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/
#ifndef NVIC_PRIVATE_H_

#define NVIC_PRIVATE_H_ 

#include "NVIC_Config.h"

#define NVIC_BASE_ADRESS  0xE000E100  


#define NVIC_ISER0    *((uint32*)(NVIC_BASE_ADRESS +0x100))
#define NVIC_ISER1    *((uint32*)(NVIC_BASE_ADRESS +0x104))
#define NVIC_ICER0		*((uint32*)(NVIC_BASE_ADRESS +0x180))
#define NVIC_ICER1		*((uint32*)(NVIC_BASE_ADRESS +0x184))
#define NVIC_ISPR0		*((uint32*)(NVIC_BASE_ADRESS +0x200))
#define NVIC_ISPR1		*((uint32*)(NVIC_BASE_ADRESS +0x204))
#define NVIC_ICPR0		*((uint32*)(NVIC_BASE_ADRESS +0x280))
#define NVIC_ICPR1		*((uint32*)(NVIC_BASE_ADRESS +0x284))
#define NVIC_IABR0		*((uint32*)(NVIC_BASE_ADRESS +0x300))
#define NVIC_IABR1		*((uint32*)(NVIC_BASE_ADRESS +0x304))


#define NVIC_IPR0			((uint8*)(NVIC_BASE_ADRESS +0x400))
#define NVIC_IPR1			((uint8*)(NVIC_BASE_ADRESS +0x404))

#define SYS_CONTROL_BASE_ADRESS  0xE000ED00
#define AIRCR          *((uint32*)(SYS_CONTROL_BASE_ADRESS+0x0C))






#endif
