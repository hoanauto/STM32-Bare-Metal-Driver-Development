#include "UART.h"
#include "RCC.h"
#include "GPIO.h"

void UART1_Init(UART_Config_t *config)
{
    USART_TypeDef *USARTx = config->Instance;

    // Enable clock cho USART và GPIO tuong ?ng
        RCC->APB2ENR |= RCC_APB2Periph_GPIOA  | RCC_APB2Periph_USART1;
        GPIO_Config(GPIOA, 9, MODE_OUTPUT_50MHZ, CNF_AF_PUSH_PULL, PULL_NONE); // TX
        GPIO_Config(GPIOA,10, MODE_INPUT, CNF_PULL, PULL_UP); // RX
    
   

    // Tính toán baudrate
    uint32_t pclk;
    if (USARTx == USART1)
        pclk = 72000000; // APB2
    else
        pclk = 36000000; // APB1

    uint32_t USARTDIV = (pclk + (config->baudrate / 2)) / config->baudrate;
    USARTx->BRR = USARTDIV;

    // C?u hình word length
    if (config->word_length == 9)
        USARTx->CR1 |= (1 << 12);
    else
        USARTx->CR1 &= ~(1 << 12);

    // C?u hình parity
    if (config->parity == UART_PARITY_NONE) {
        USARTx->CR1 &= ~(1 << 10); // Parity disable
    } else {
        USARTx->CR1 |= (1 << 10); // Parity enable
        if (config->parity == UART_PARITY_ODD)
            USARTx->CR1 |= (1 << 9);
        else
            USARTx->CR1 &= ~(1 << 9);
    }

    // Enable TX và RX
    if (config->mode & UART_MODE_TX)
        USARTx->CR1 |= (1 << 3); // TE
    if (config->mode & UART_MODE_RX)
        USARTx->CR1 |= (1 << 2); // RE

    USARTx->CR1 |= (1 << 13); // Enable USART
}

void UART_WriteChar(USART_TypeDef *USARTx, char c)
{
    while (!(USARTx->SR & (1 << 7))); // Wait TXE
    USARTx->DR = c;
    while (!(USARTx->SR & (1 << 6))); // Wait TC
}

char UART_ReadChar(USART_TypeDef *USARTx)
{
    while (!(USARTx->SR & (1 << 5))); // Wait RXNE
    return USARTx->DR;
}

void UART_WriteString(USART_TypeDef *USARTx, const char *str)
{
    while (*str) {
        UART_WriteChar(USARTx, *str++);
    }
}
