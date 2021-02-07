#ifndef SYSTICK_INTERFACE_H_ 

#define SYSTICK_INTERFACE_H_

#include "STD_TYPES.h"


void SYS_voidTickInit(void);

void SYS_voidTick_Wait(uint32 value);

void SYS_voidTick_IntervalSignle(uint32 value , void (*ptr)(void)); 

void SYS_voidTick_IntervalPeriodic(uint32 value , void (*ptr)(void));

void SYS_voidTick_IntervalStop(void);

uint32 SYS_u32Tick_GetElaspedTime(void);

uint32 SYS_u32Tick_GetRemaindingTime(void);


#endif
