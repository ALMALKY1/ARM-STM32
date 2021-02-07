/****************************************************************************
*
* Layer : MCAL 
*  
* Author : Almalky
*
* Data : 1/7/2021 11:50 pm 
*****************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


 
#define  BASE_ADRESS_PORTA                  0x40020400 
#define  BASE_ADRESS_PORTB                  0x40020800 
#define  BASE_ADRESS_PORTC                  0x40020C00 
#define  BASE_ADRESS_PORTD                  0x40021000 
#define  BASE_ADRESS_PORTE                  0x40021400 
#define  BASE_ADRESS_PORTF                  0x40021800 
#define  BASE_ADRESS_PORTG                  0x40021C00 
#define  BASE_ADRESS_PORTH                  0x40022200 



#define GPIOA_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOA_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOA_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOA_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOA_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOA_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOA_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOA_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOA_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOA_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))


#define GPIOB_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOB_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOB_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOB_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOB_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOB_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOB_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOB_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOB_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOB_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))


#define GPIOC_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOC_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOC_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOC_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOC_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOC_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOC_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOC_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOC_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOC_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))


#define GPIOD_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOD_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOD_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOD_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOD_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOD_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOD_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOD_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOD_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOD_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))



#define GPIOE_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOE_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOE_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOE_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOE_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOE_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOE_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOE_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOE_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOE_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))



#define GPIOF_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOF_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOF_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOF_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOF_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOF_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOF_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOF_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOF_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOF_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))

#define GPIOG_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOG_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOG_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOG_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOG_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOG_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOG_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOG_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOG_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOG_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))


#define GPIOH_MODER               (*((uint32*)BASE_ADRESS_PORTA + 0x00))
#define GPIOH_OTYPER 							(*((uint32*)BASE_ADRESS_PORTA + 0x04))
#define GPIOH_OSPEEDR 						(*((uint32*)BASE_ADRESS_PORTA + 0x08))
#define GPIOH_PUPDR               (*((uint32*)BASE_ADRESS_PORTA + 0x0c))
#define GPIOH_IDR 								(*((uint32*)BASE_ADRESS_PORTA + 0x10))
#define GPIOH_ODR 								(*((uint32*)BASE_ADRESS_PORTA + 0x14))
#define GPIOH_BSRR 								(*((uint32*)BASE_ADRESS_PORTA + 0x18))
#define GPIOH_LCKR               	(*((uint32*)BASE_ADRESS_PORTA + 0x1c))
#define GPIOH_AFRL 								(*((uint32*)BASE_ADRESS_PORTA + 0x20))
#define GPIOH_AFRH 								(*((uint32*)BASE_ADRESS_PORTA + 0x24))


#endif

