#include "UART.h"

int main(void)
{
    UART_Config_t uart1;
    uart1.Instance = USART1;
    uart1.baudrate = 9600;
    uart1.word_length = 8;
    uart1.parity = UART_PARITY_NONE;
    uart1.mode = UART_MODE_TX_RX;

    UART1_Init(&uart1);

    UART_WriteString(USART1, "Hello from UART!\r\n");

    while (1) {
        char c = UART_ReadChar(USART1); // nh?n ký t?
        UART_WriteChar(USART1, c);      // ph?n h?i l?i ký t? dó
    }
}
