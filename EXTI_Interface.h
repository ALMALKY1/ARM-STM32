/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

#ifndef  	EXTI_INTERFACE_H_

#define 	EXTI_INTERFACE_H_
#include "STD_TYPES.h"


typedef enum { 
		PORTA_ID =0,
		PORTB_ID =1,
		PORTC_ID =2, 
		PORTD_ID =3,
		PORTE_ID =4,
		PORTF_ID =5,
		PORTG_ID =6,
		PORTH_ID =7
}PORT_ID;


void vEXTI_Enable(uint8 Number_OF_line );
void vEXTI_Disable(uint8 Number_OF_line );
void vEXTI_Event_Type(uint8 Number_OF_line);
void vEXTI_SWIER_Trigger(uint8 Number_OF_line);
void vEXTI_CLEAR_PENDING(uint8 Number_OF_line);
void vEXTI_SET_PIN_PORT(uint8 Number_OF_line , PORT_ID PORT);
void vEXTI_Call_Back_Function(void (*call_back_ptr)(void));


#define LINE_0  0 
#define LINE_1  1
#define LINE_2  2
#define LINE_3  3
#define LINE_4  4
#define LINE_5  5
#define LINE_6  6
#define LINE_7  7



#endif
