#include "EXTI.h"
#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"
#include "RTE_Device.h" // B? cung du?c n?u kh�ng c?n

static void delay(unsigned int timedelay) {
    for (unsigned int i = 0; i < timedelay; i++) {}
}

// Prototype d? tr�nh warning "no previous prototype"
void EXTI9_5_IRQHandler(void);

void EXTI9_5_IRQHandler(void)
{
    static uint8_t led_state = 0;  // 0 = OFF, 1 = ON

    if (EXTI->PR & (1 << 5)) // Ki?m tra c? ng?t EXTI5
    {
        if (led_state == 0)
        {
            GPIOC->ODR |= (1 << 13); // B?t LED (PC13 = 1)
            led_state = 1;
        }
        else
        {
            GPIOC->ODR &= ~(1 << 13); // T?t LED (PC13 = 0)
            led_state = 0;
        }

        EXTI->PR |= (1 << 5); // X�a c? ng?t
    }
}


int main(void)
{
    // 1. B?t clock cho GPIOA, GPIOC, AFIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    // 2. C?u h�nh PA5 l�m input pull-down
    GPIO_Config(GPIOA, 5, MODE_INPUT, CNF_PULL, PULL_DOWN);

    // 3. C?u h�nh PC13 l�m output push-pull
    GPIO_Config(GPIOC, 13, MODE_OUTPUT_50MHZ, CNF_GP_PUSH_PULL, PULL_NONE);

    // 4. G�n EXTI5 cho PA5 b?ng c�ch s?a EXTICR2 (EXTI4~7)
    AFIO->EXTICR2 &= ~(0xF << 4);  // Clear 4 bit t?i v? tr� EXTI5 (bit 7:4)
    // M?c d?nh PA => 0000 n�n kh�ng c?n g�n l?i n?u d�ng PA5

    // 5. C?u h�nh EXTI5
    EXTI->IMR  |= (1 << 5);    // Enable interrupt mask cho EXTI5
    EXTI->RTSR |= (1 << 5);    // Rising edge trigger (nh?n n�t s? k�ch ho?t ng?t)
     EXTI->FTSR |= (1 << 5); // N?u mu?n ph�t hi?n c?nh xu?ng th� b?t th�m d�ng n�y

    // 6. B?t ng?t EXTI9_5 tr�n NVIC (n?m trong ISER0, v? tr� 23)
    NVIC->ISER[0] |= (1 << 23); // EXTI9_5_IRQn = 23

    while (1) {
        // Kh�ng c?n l�m g� trong main loop
    }
}
