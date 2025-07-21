#include "UART.h"
#include "RCC.h"
#include "GPIO.h"


void UART_Init(USART_TypeDef *USARTx, uint32_t baudrate, uint8_t dataBits, uint8_t stopBits, char parity)
{
	if(USARTx == USART1){
    USARTx->CR1 &= ~(1 << 13); // Disable USART

    // Clock frequency (APB2: USART1, APB1: USART2/3)
    uint32_t Fck = 72000000;

    float usartdiv = (float)Fck / (16 * baudrate);
    uint32_t mantissa = (uint32_t)usartdiv;
    uint32_t fraction = (uint32_t)((usartdiv - (float)mantissa) * 16);
    USARTx->BRR = (mantissa << 4) | (fraction & 0x0F);

    // Word length
    if (dataBits == 9)
        USARTx->CR1 |= (1 << 12);
    else
        USARTx->CR1 &= ~(1 << 12);

    // Parity
    if (parity == 0) {
        USARTx->CR1 &= ~(1 << 10); // Disable parity
    } else {
        USARTx->CR1 |= (1 << 10);  // Enable parity
        if (parity == 1)
            USARTx->CR1 &= ~(1 << 9); // Even
        else if (parity == 2)
            USARTx->CR1 |= (1 << 9);  // Odd
    }

    // Stop bits
   USARTx->CR2 &= ~(3 << 12); // clear stop bits
if (stopBits == 0.5)
    USARTx->CR2 |= (1 << 12);
else if (stopBits == 2)
    USARTx->CR2 |= (2 << 12);
else if (stopBits == 1.5)
    USARTx->CR2 |= (3 << 12);
// M?c d?nh 1 stop bit thì gi? nguyên

    // Enable TX & RX
    USARTx->CR1 |= (1 << 3) | (1 << 2);// cho truyen va nhan

    USARTx->CR1 |= (1 << 13); // Enable USART
}
}

void UART_WriteChar(USART_TypeDef *USARTx, char c)
{
    while (!(USARTx->SR & (1 << 7))); // TXE empty
    USARTx->DR = c;
    while (!(USARTx->SR & (1 << 6))); // TC truyen thanh cong
}

void UART_WriteString(USART_TypeDef *USARTx, const char *str)
{
    while (*str) { // kiem tra null
        UART_WriteChar(USARTx, *str++);
			
    }
}

char UART_ReadChar(USART_TypeDef *USARTx)
{
    while (!(USARTx->SR & (1 << 5))); // RXNE da co du lieu
    return (char) USARTx->DR;
}
void UART_ReadString(USART_TypeDef *USARTx, char *buffer, uint16_t maxLength)
{
    uint16_t i = 0;
    char c;

    do {
        c = UART_ReadChar(USARTx); // nh?n t?ng ký t?
        buffer[i++] = c;
    } while (c != '\r' && i < (maxLength - 1)); // k?t thúc khi g?p ký t? Enter (CR)

    buffer[i] = '\0'; // k?t thúc chu?i
}
