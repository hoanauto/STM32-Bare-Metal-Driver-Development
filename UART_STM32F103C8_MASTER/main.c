#include "UART.h"
#include "RCC.h"
#include "GPIO.h"

volatile char c;

int main(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_Config(GPIOA, 9, MODE_OUTPUT_50MHZ, CNF_AF_PUSH_PULL, 0);   // TX
    GPIO_Config(GPIOA, 10, MODE_INPUT, CNF_FLOATING, 0);             // RX

    UART_Init(USART1, 115200, 8, 1, 0); // baudrate, 8 data bits, 1 stop bit, no parity

    UART_WriteString(USART1, "UA \r\n");

    while (1)
    {
        c = UART_ReadChar(USART1);      // Ch? nh?n m?t ký t?
        UART_WriteChar(USART1, c);      // G?i l?i ký t? dó (echo)
    }
}
