#include <stdio.h>

/** RCC - Register Layout Typedef */
typedef struct {
  volatile unsigned int CR;					//offset 00 
	volatile unsigned int CFGR;				//offser 04 
	volatile unsigned int CIR;				//offset 08
	volatile unsigned int APB2RSTR;		//offset 0C
	volatile unsigned int APB1RSTR;		//offset 10
	volatile unsigned int AHBENR;			//offset 14
	volatile unsigned int	APB2ENR;		//offset 18
	volatile unsigned int APB1ENR; 		//offset 1C
	volatile unsigned int BDCR;				//offset 20
	volatile unsigned int CSR;				//offset 24
} RCC_Type;
  
/** Peripheral SCG base address */
#define RCC_BASE                                 (0x40021000u)
/** Peripheral SCG base pointer */
#define RCC                                      ((RCC_Type *)RCC_BASE)