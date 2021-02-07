/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

#ifndef GPIO_INTERFACE_H_

#define GPIO_INTERFACE_H_
#include "STD_TYPES.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
#define PORTG 6
#define PORTH 7


#define PIN0 				0
#define PIN1 				1
#define PIN2 				2
#define PIN3 				3
#define PIN4 				4
#define PIN5 				5
#define PIN6 				6
#define PIN7 				7
#define PIN8 				8
#define PIN9 				9
#define PIN10				10
#define PIN11				11
#define PIN12				12
#define PIN13				13
#define PIN14				14
#define PIN15				15

#define LCKK				16


#define GPIO_OUTPUT_MODE    				((uint8)0x01)
#define GPIO_INPUT_MODE    					((uint8)0x00)
#define GPIO_ALTFUNCTION_MODE  			((uint8)0x10)
#define GPIO_Analog_MODE					  ((uint8)0x11)



#define GPIO_OUTPUT_PUSHPULL   				((uint8)0x00)
#define GPIO_OUTPUT_OPENDRAIN  				((uint8)0x00)


#define GPIO_OUTPUT_LOW_SPEED 						((uint8)0x00)
#define GPIO_OUTPUT_MEDIUM_SPEED 					((uint8)0x01)
#define GPIO_OUTPUT_HIGH_SPEED 						((uint8)0x10)
#define GPIO_OUTPUT__VERY_HIGH_SPEED 			((uint8)0x11)



#define GPIO_NO_PULL_UP_DOWN    				((uint8)0x01)
#define GPIO_PULL_UP    								((uint8)0x00)
#define GPIO_PULL_DOWN 									((uint8)0x10)





void 	vGPIO_PIN_Mode(uint8 PORT_NAME , uint8 PIN_NUMBER , uint8  Mode ); 

void 	vGPIO_OUTPUT_PIN_TYPE(uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 OUTPUT_TYPE  ); 

void 	vGPIO_OUTPUT_PIN_SPEED( uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 OUTPUT_Speed); 

void 	vGPIO_PULL_UP_DOWN(uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 PULL_Type); 

uint8 u8GPIO_READ_PIN(uint8 PORT_NAME , uint8 PIN_NUMBER);

void 	vGPIO_Write_PIN(uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 Value); 

void  vGPIO_PIN_LCK(uint8 PORT_NAME , uint8 PIN_NUMBER ) ; 

void vGPIO_SetAlternate( uint8 PORT_NAME , uint8 PIN_NUMBER , uint8 ALT_value );




#endif
