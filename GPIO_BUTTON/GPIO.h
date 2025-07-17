#ifndef GPIO_H_
#define GPIO_H_

/* GPIO memory tydef layout */
typedef struct {
  volatile unsigned int CRL;					//offset 00 GPIO tu 0 den 7
	volatile unsigned int CRH;					//offser 04 GPIO tu 8 den 15
	volatile unsigned int IDR;					//offset 08  thanh ghi d?c d? li?u input
	volatile unsigned int ODR;					//offset 0C  thanh ghi ghi d? li?u output
	volatile unsigned int BSRR;					//offset 10
	volatile unsigned int BRR;					//offset 14
	volatile unsigned int	LCKR;					//offset 18
}GPIO_Type;

/* GPIOA base adddresss */
#define GPIOA_BASE  (0x40010800u)
/* GPIOA base pointer */
#define GPIOA		((GPIO_Type *)GPIOA_BASE) // ép kieu dia chi thanh con tro kieu struct

/* GPIOC base adddresss */
#define GPIOC_BASE  (0x40011000u)
/* GPIOC base pointer */
#define GPIOC		((GPIO_Type *)GPIOC_BASE)

void GPIOA_init(void); // hàm dã duoc dinh nghia san extern
void GPIOB_init(void);
void GPIOC_init(void);
void GPIOD_init(void);
void GPIOE_init(void);
void GPIOF_init(void);
void GPIOG_init(void);

#endif /* GPIO_H_ */

