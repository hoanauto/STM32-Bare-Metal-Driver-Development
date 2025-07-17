#include <stdint.h> 

// MODE definitions (decimal)
#define MODE_INPUT         0   // 0b00
#define MODE_OUTPUT_10MHZ  1   // 0b01
#define MODE_OUTPUT_2MHZ   2   // 0b10
#define MODE_OUTPUT_50MHZ  3   // 0b11

// CNF definitions (decimal)
#define CNF_GP_PUSH_PULL      0   // 0b00
#define CNF_GP_OPEN_DRAIN     1   // 0b01
#define CNF_AF_PUSH_PULL      2   // 0b10
#define CNF_AF_OPEN_DRAIN     3   // 0b11

#define CNF_ANALOG            0   // 0b00 (Input)
#define CNF_FLOATING          1   // 0b01 (Input)
#define CNF_PULL              2   // 0b10 (Input pull-up/down)

// Output status
#define HIGH             1
#define LOW              0
// pull
#define PULL_NONE     0
#define PULL_UP       1
#define PULL_DOWN     2

typedef struct {
  volatile unsigned int CRL;					//offset 0x00
	volatile unsigned int CRH;					//offser 0x04
	volatile unsigned int IDR;					//offset 0x08
	volatile unsigned int ODR;					//offset 0x0C
	volatile unsigned int BSRR;					//offset 0x10
	volatile unsigned int BRR;					//offset 0x14
	volatile unsigned int	LCKR;					//offset 0x18
}GPIO_Type;

typedef struct {
  volatile unsigned int EVCR;        // Event Control Register
  volatile unsigned int MAPR;        // Remap and Debug I/O Configuration
  volatile unsigned int EXTICR1;     // External interrupt configuration register 1 (EXTI0 - EXTI3)
  volatile unsigned int EXTICR2;     // EXTI4 - EXTI7
  volatile unsigned int EXTICR3;     // EXTI8 - EXTI11
  volatile unsigned int EXTICR4;     // EXTI12 - EXTI15
  volatile unsigned int reserved;    // Reserved (not used)
  volatile unsigned int MAPR2;       // Additional remap register
} AFIO_Type;

/* AFIO base adddresss */
#define AFIO_BASE  (0x40010000u)
/* AFIO base pointer */
#define AFIO		((AFIO_Type *)AFIO_BASE)

/* GPIOA base adddresss */
#define GPIOA_BASE  (0x40010800u)
/* GPIOA base pointer */
#define GPIOA		((GPIO_Type *)GPIOA_BASE)

/* GPIOB base adddresss */
#define GPIOB_BASE  (0x40010C00u)
/* GPIOB base pointer */
#define GPIOB		((GPIO_Type *)GPIOB_BASE)

/* GPIOC base adddresss */
#define GPIOC_BASE  (0x40011000u)
/* GPIOC base pointer */
#define GPIOC		((GPIO_Type *)GPIOC_BASE)

/* GPIOD base adddresss */
#define GPIOD_BASE  (0x40011400u)
/* GPIOD base pointer */
#define GPIOD		((GPIO_Type *)GPIOD_BASE)

/* GPIOE base adddresss */
#define GPIOE_BASE  (0x40011800u)
/* GPIOE base pointer */
#define GPIOE		((GPIO_Type *)GPIOE_BASE)

/* GPIOF base adddresss */
#define GPIOF_BASE  (0x40011C00u)
/* GPIOF base pointer */
#define GPIOF		((GPIO_Type *)GPIOF_BASE)

/* GPIOG base adddresss */
#define GPIOG_BASE  (0x40012000u)
/* GPIOG base pointer */
#define GPIOG		((GPIO_Type *)GPIOG_BASE)

void GPIO_Config(GPIO_Type *PORT, uint8_t pin, uint8_t mode, uint8_t cnf, uint8_t pull);

void GPIO_Write(GPIO_Type *PORT, unsigned char index, unsigned char status);

unsigned char GPIO_Read(GPIO_Type *PORT, unsigned char index);

