/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/


#ifndef NVIC_INTERFACE_H_

#define NVIC_INTERFACE_H_

#include "STD_TYPES.h"

void vNVIC_SET_ENABLE(uint8 U8Interrupt_Number);

void vNVIC_Clear_ENABLE(uint8 U8Interrupt_Number);


void vNVIC_SET_PendingFlag(uint8 U8Interrupt_Number);

void vNVIC_Clear_PendingFlag(uint8 U8Interrupt_Number);

uint8 u8NVIC_Read_ActiveFlag(uint8 U8Interrupt_Number);

void vNVIC_Set_Priority(uint8 GROUP_Priority , uint8 SUB_Priority , uint8 U8Interrupt_Number );

#endif
