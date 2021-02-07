#ifndef SYSTICK_PRIVATE_H_ 

#define SYSTICK_PRIVATE_H_

#include "STD_TYPES.h"


typedef struct {
	
		volatile  uint32 CTRL ; 
		volatile 	uint32	LOAD;
		volatile 	uint32 VAL ; 

}SYSTICK_Type; 



#define SYSPTR         ((SYSTICK_Type*)0xE000E010)  


#define SYS_CLOCK_MODE_AHB 0 
#define SYS_CLOCK_MODE_AHB_8 1 

#define Interval_Single 0
#define Interval_periodic 1  







#endif
