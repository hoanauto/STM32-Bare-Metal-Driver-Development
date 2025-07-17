/** RCC - Register Layout Typedef */
#include <stdint.h>
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

#define DISABLE 0
#define ENABLE 1
#define RCC_APB2Periph_AFIO              ((uint32_t)0x00000001)
#define RCC_APB2Periph_GPIOA             ((uint32_t)0x00000004)
#define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
#define RCC_APB2Periph_GPIOC             ((uint32_t)0x00000010)
#define RCC_APB2Periph_GPIOD             ((uint32_t)0x00000020)
#define RCC_APB2Periph_GPIOE             ((uint32_t)0x00000040)
#define RCC_APB2Periph_GPIOF             ((uint32_t)0x00000080)
#define RCC_APB2Periph_GPIOG             ((uint32_t)0x00000100)
#define RCC_APB2Periph_ADC1              ((uint32_t)0x00000200)
#define RCC_APB2Periph_ADC2              ((uint32_t)0x00000400)
#define RCC_APB2Periph_TIM1              ((uint32_t)0x00000800)
#define RCC_APB2Periph_SPI1              ((uint32_t)0x00001000)
#define RCC_APB2Periph_TIM8              ((uint32_t)0x00002000)
#define RCC_APB2Periph_USART1            ((uint32_t)0x00004000)
#define RCC_APB2Periph_ADC3              ((uint32_t)0x00008000)
#define RCC_APB2Periph_TIM15             ((uint32_t)0x00010000)
#define RCC_APB2Periph_TIM16             ((uint32_t)0x00020000)
#define RCC_APB2Periph_TIM17             ((uint32_t)0x00040000)
#define RCC_APB2Periph_TIM9              ((uint32_t)0x00080000)
#define RCC_APB2Periph_TIM10             ((uint32_t)0x00100000)
#define RCC_APB2Periph_TIM11             ((uint32_t)0x00200000)

void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, uint8_t NewState);