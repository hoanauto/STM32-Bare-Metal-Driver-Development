#include "RTE_Device.h" // ho?c b? n?u không c?n thi?t
#include "GPIO.h"
#include "RCC.h"  

void GPIOA_init(void);
void GPIOC_init(void);
static void delay(unsigned int timedelay){
    for (unsigned int i = 0; i < timedelay; i++) {}
}

int main(void) {
	GPIOA_init();
	GPIOC_init();
    // Enable clock for GPIOC & GPIOA
   // RCC->APB2ENR |= (1 << 4) | (1 << 2);

    // PA5: Input pull-up
    GPIOA->CRL &= ~(0xF << 20);     // Clear CNF5[1:0], MODE5[1:0]
    GPIOA->CRL |=  (0x8 << 20);     // CNF5 = 10, MODE5 = 00
    GPIOA->ODR &= ~(1 << 5);        // Pulldown

    // PC13: Output push-pull
    GPIOC->CRH &= ~(0xF << 20);     // Clear CNF13 & MODE13
    GPIOC->CRH |=  (0x3 << 20);     // MODE13 = 11 (50MHz), CNF13 = 00

    while (1) {
        if ((GPIOA->IDR & (1 << 5)) == 0) {
            GPIOC->ODR &= ~(1 << 13); // Turn ON LED
        } else {
            GPIOC->ODR |= (1 << 13);  // Turn OFF LED
        }

        delay(100000);
    }
}


