/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Mohamed Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "BIT_OP.h"

void 	vGPIO_PIN_Mode(uint8 PORT_NAME , uint8 PIN_NUMBER , uint8  Mode )
{
	
	switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_MODER |= (Mode <<(PIN_NUMBER * 2)); break;
		case PORTB : 
			GPIOB_MODER |= (Mode << (PIN_NUMBER * 2)); break;
			
		case PORTC : 
			GPIOC_MODER |= (Mode << (PIN_NUMBER * 2)); break;
			
		case PORTD : 
			GPIOD_MODER |= (Mode << (PIN_NUMBER * 2)); break;
			
		case PORTE : 
			GPIOE_MODER |= (Mode << (PIN_NUMBER * 2)); break;
			
		case PORTF : 
			GPIOF_MODER |= (Mode <<(PIN_NUMBER * 2)); break;
			
		case PORTG : 
			GPIOG_MODER |= (Mode << (PIN_NUMBER * 2)); break;
			
		
		case PORTH : 
			GPIOH_MODER |= (Mode << (PIN_NUMBER * 2)); break;
			
		default : break;
		
	}
	
}
	
	
	
	
void 	vGPIO_OUTPUT_PIN_TYPE(uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 OUTPUT_TYPE ){
	
	
	switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_OTYPER |= (OUTPUT_TYPE <<(PIN_NUMBER )); break;
		case PORTB : 
			GPIOB_OTYPER |= (OUTPUT_TYPE << (PIN_NUMBER )); break;
			
		case PORTC : 
			GPIOC_OTYPER |= (OUTPUT_TYPE << (PIN_NUMBER )); break;
			
		case PORTD : 
			GPIOD_OTYPER |= (OUTPUT_TYPE << (PIN_NUMBER )); break;
			
		case PORTE : 
			GPIOE_OTYPER |= (OUTPUT_TYPE << (PIN_NUMBER )); break;
			
		case PORTF : 
			GPIOF_OTYPER |= (OUTPUT_TYPE <<(PIN_NUMBER )); break;
			
		case PORTG : 
			GPIOG_OTYPER |= (OUTPUT_TYPE << (PIN_NUMBER )); break;
			
		
		case PORTH : 
			GPIOH_OTYPER |= (OUTPUT_TYPE << (PIN_NUMBER )); break;
			
		default : break;
		
	}
	
}
	
	
	
	
void 	vGPIO_OUTPUT_PIN_SPEED( uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 OUTPUT_Speed)
{

switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_OSPEEDR |= (OUTPUT_Speed <<(PIN_NUMBER * 2)); break;
		case PORTB : 
			GPIOB_OSPEEDR |= (OUTPUT_Speed << (PIN_NUMBER * 2)); break;
		case PORTC : 
			GPIOC_OSPEEDR |= (OUTPUT_Speed << (PIN_NUMBER * 2)); break;
			
		case PORTD : 
			GPIOD_OSPEEDR |= (OUTPUT_Speed << (PIN_NUMBER * 2)); break;
			
		case PORTE : 
			GPIOE_OSPEEDR |= (OUTPUT_Speed << (PIN_NUMBER * 2)); break;
			
		case PORTF : 
			GPIOF_OSPEEDR |= (OUTPUT_Speed <<(PIN_NUMBER * 2)); break;
			
		case PORTG : 
			GPIOG_OSPEEDR |= (OUTPUT_Speed << (PIN_NUMBER * 2)); break;
			
		
		case PORTH : 
			GPIOH_OSPEEDR |= (OUTPUT_Speed << (PIN_NUMBER * 2)); break;		
		
		default : break;
		
	}
	

}




void 	vGPIO_PULL_UP_DOWN(uint8 PORT_NAME , uint8 PIN_NUMBER ,uint8 PULL_Type)
{
	
	
	switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
		case PORTB : 
			GPIOB_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
			
		case PORTC : 
			GPIOC_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
			
		case PORTD : 
			GPIOD_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
			
		case PORTE : 
			GPIOE_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
			
		case PORTF : 
			GPIOF_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
			
		case PORTG : 
			GPIOG_PUPDR |= (PULL_Type << (PIN_NUMBER * 2)); break;
			
		case PORTH : 
			GPIOH_PUPDR |= (PULL_Type<< (PIN_NUMBER * 2)); break;
			
		default : break;
		
	}
	
}
	
	
	
	
	
	
uint8 u8GPIO_READ_PIN(uint8 PORT_NAME , uint8 PIN_NUMBER)
{
	uint8 Value =0 ; 
	switch(PORT_NAME)
	{
		case PORTA : 
			Value = (GPIOA_IDR & (1U<<PIN_NUMBER)); break;
		case PORTB : 
			Value = (GPIOB_IDR & (1U<<PIN_NUMBER)); break;
			
		case PORTC : 
			Value = (GPIOC_IDR & (1U<<PIN_NUMBER)); break;
			
		case PORTD : 
			Value = (GPIOD_IDR & (1U<<PIN_NUMBER)); break;
			
		case PORTE : 
			Value = (GPIOE_IDR & (1U<<PIN_NUMBER)); break;
			
		case PORTF : 
			Value = (GPIOF_IDR & (1U<<PIN_NUMBER)); break;
			
		case PORTG : 
			Value = (GPIOG_IDR & (1U<<PIN_NUMBER)); break;
			
		
		case PORTH : 
			Value = (GPIOH_IDR & (1U<<PIN_NUMBER)); break;
		
		default : break;
	}
	
		return Value ;
}
	
	
void 	vGPIO_Write_PIN(uint8 PORT_NAME , uint8 PIN_NUMBER , uint8 Value)
{

		if(Value==1)
		{
			switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_ODR |= (Value<<(PIN_NUMBER )); break;
		case PORTB : 
			GPIOB_ODR |= (Value<<(PIN_NUMBER )); break;
			
		case PORTC : 
			GPIOC_ODR |= (Value<<(PIN_NUMBER )); break;
			
		case PORTD : 
			GPIOD_ODR |= (Value<<(PIN_NUMBER )); break;
			
		case PORTE : 
			GPIOE_ODR |= (Value<<(PIN_NUMBER )); break;
			
		case PORTF : 
			GPIOF_ODR |= (Value<<(PIN_NUMBER )); break;
			
		case PORTG : 
			GPIOG_ODR |= (Value<<(PIN_NUMBER )); break;
			
		
		case PORTH : 
			GPIOH_ODR |= (Value<<(PIN_NUMBER )); break;
		default : break;
	}
}

	 else  
	 {
			switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_ODR &=~ (Value<<(PIN_NUMBER )); break;
		case PORTB : 
			GPIOB_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		case PORTC : 
			GPIOC_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		case PORTD : 
			GPIOD_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		case PORTE : 
			GPIOE_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		case PORTF : 
			GPIOF_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		case PORTG : 
			GPIOG_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		
		case PORTH : 
			GPIOH_ODR &=~ (Value<<(PIN_NUMBER )); break;
			
		default : break;
	}
	
	
	}
	
}
	

void  vGPIO_PIN_LCK(uint8 PORT_NAME , uint8 PIN_NUMBER ) 
{


switch(PORT_NAME)
{
	case PORTA : 

			GPIOA_LCKR |= (1U<<PIN_NUMBER);
			GPIOA_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOA_LCKR &(1U<<LCKK)));  
			break;
	
	
	case PORTB : 

			GPIOB_LCKR |= (1U<<PIN_NUMBER);
			GPIOB_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOB_LCKR &(1U<<LCKK)));  
			break;
	
	case PORTC : 

			GPIOC_LCKR |= (1U<<PIN_NUMBER);
			GPIOC_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOC_LCKR &(1U<<LCKK)));  
			break;
	
	case PORTD : 

			GPIOD_LCKR |= (1U<<PIN_NUMBER);
			GPIOD_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOD_LCKR &(1U<<LCKK)));  
			break;
	
	case PORTE : 

			GPIOE_LCKR |= (1U<<PIN_NUMBER);
			GPIOE_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOE_LCKR &(1U<<LCKK)));  
			break;
	
	case PORTF : 

			GPIOF_LCKR |= (1U<<PIN_NUMBER);
			GPIOF_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOF_LCKR &(1U<<LCKK)));  
			break;
	
	case PORTG : 

			GPIOG_LCKR |= (1U<<PIN_NUMBER);
			GPIOG_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOG_LCKR &(1U<<LCKK)));  
			break;
	
	case PORTH : 

			GPIOH_LCKR |= (1U<<PIN_NUMBER);
			GPIOH_LCKR |=(1U<<PIN_NUMBER);
			while(!(GPIOH_LCKR &(1U<<LCKK)));  
			break;

}
}




void vGPIO_SetAlternate( uint8 PORT_NAME , uint8 PIN_NUMBER , uint8 ALT_value )
{
	
	

		if(PIN_NUMBER<=7)
		{
	switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
		case PORTB : 
			GPIOB_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTC : 
			GPIOC_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTD : 
			GPIOD_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTE : 
			GPIOE_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTF : 
			GPIOF_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTG : 
			GPIOG_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;

		case PORTH : 
			GPIOH_AFRL |= (ALT_value << (PIN_NUMBER *4)); break;
			
		default : break;
		
	}
}


	 else  
		{
			switch(PORT_NAME)
	{
		case PORTA : 
			GPIOA_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
		case PORTB : 
			GPIOB_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTC : 
			GPIOC_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTD : 
			GPIOD_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTE : 
			GPIOE_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTF : 
			GPIOF_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
			
		case PORTG : 
			GPIOG_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;

		case PORTH : 
			GPIOH_AFRH |= (ALT_value << (PIN_NUMBER *4)); break;
			
		default : break;
	
	}
	
}
		
}
	
	
	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
