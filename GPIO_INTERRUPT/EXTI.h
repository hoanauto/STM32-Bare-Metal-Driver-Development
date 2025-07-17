#ifndef EXTI_H_
#define EXTI_H_
/** EXTI - Register Layout Typedef */
typedef struct {
  volatile unsigned int IMR;					//offset 0x00 	B?t/t?t ng?t cho t?ng EXTI (bit = 1 là cho phép ng?t)
	volatile unsigned int EMR;					//offser 0x04
	volatile unsigned int RTSR;					//offset 0x08 ngat suon len
	volatile unsigned int FTSR;					//offset 0x0C ngat suon xuong
	volatile unsigned int SWIER;				//offset 0x10
	volatile unsigned int PR;						//offset 0x14
} EXTI_Type;
  
/** Peripheral EXTI base address */
#define EXTI_BASE                                 (0x40010400u)
/** Peripheral SCG base pointer */
#define EXTI                                      ((EXTI_Type *)EXTI_BASE)
#endif
