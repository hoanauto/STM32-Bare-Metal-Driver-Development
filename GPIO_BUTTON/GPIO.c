#include "GPIO.h"
#include "RCC.h"

void GPIOA_init()
{
	RCC->APB2ENR |= 0x00000004; //Dùng ánh x? con tr? c?u trúc (struct pointer)
}// là truy c?p tru?ng bên trong struct
//  RCC -> APB2ENR |= (1<<4)|(1<<2);// bit 1 o vi tri thu 4 va 2, con lai bang 0 (GPIOC va GPIOA)
void GPIOB_init()
{
	RCC->APB2ENR |= 0x00000008;
}

void GPIOC_init()
{
	RCC->APB2ENR |= 0x00000010;
}

void GPIOD_init()
{
	RCC->APB2ENR |= 0x00000020;
}

void GPIOE_init()
{
	RCC->APB2ENR |= 0x00000040;
}

void GPIOF_init()
{
	RCC->APB2ENR |= 0x00000080;
}

void GPIOG_init()
{
	RCC->APB2ENR |= 0x00000100;
}


