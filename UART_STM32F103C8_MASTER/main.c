#include "GPIO.h"
#include "UART.h"
#include "RCC.h"

static char received_data[100];
int main(void)
{
    // 1. B?t clock cho AFIO, GPIOA, USART1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    // 2. C?u hình GPIO TX (PA9) và RX (PA10)
    GPIO_Config(GPIOA, 9, MODE_OUTPUT_50MHZ, CNF_AF_PUSH_PULL, 0);   // TX
    GPIO_Config(GPIOA, 10, MODE_INPUT, CNF_FLOATING, 0);             // RX

    // 3. Kh?i t?o UART1: 115200 baud, 8 data bit, 1 stop bit, no parity
    UART_Init(USART1, 115200, 8, 1, 0);

    // 4. Chu?i d? li?u c?n g?i
    char message[] = "Hello from STM32!\r\n";

    // 5. G?i chu?i liên t?c
    while (1)
    {
    //    UART_WriteString(USART1, message);

        // Delay thô (kho?ng ~1s)
     //   for (volatile unsigned long i = 0; i < 1000000; i++);
			UART_ReadString(USART1, received_data, sizeof(received_data));
    }
}
