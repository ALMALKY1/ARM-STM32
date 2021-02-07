/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/
#ifndef RCC_PRIVATE_H 

#define RCC_PRIVATE_H


#define BASE_ADRESS_RCC      0x40023800

#define RCC_CR               	*((uint32*)0x40023800)
#define RCC_PLLCFGR					 	*((uint32*)0x40023804)
#define RCC_CFGR  						*((uint32*)0x40023808)
#define RCC_AHB1ENR           *((uint32*)0x40023810)
#define RCC_AHB2ENR           *((uint32*)0x40023814)
#define RCC_AHB3ENR           *((uint32*)0x40023818)
#define RCC_APB1ENR           *((uint32*)0x40023820)
#define RCC_APB2ENR           *((uint32*)0x40023824)

#endif

 

