#ifndef UART_H_
#define UART_H_

#include <stdint.h>


#define USART1_BASE  0x40013800UL
#define USART2_BASE  0x40004400UL
#define USART3_BASE  0x40004800UL

#define NO   0
#define Even 1
#define Odd  2

typedef struct {
    volatile uint32_t SR;     // Status register
    volatile uint32_t DR;     // Data register
    volatile uint32_t BRR;    // Baud rate register
    volatile uint32_t CR1;    // Control register 1
    volatile uint32_t CR2;    // Control register 2
    volatile uint32_t CR3;    // Control register 3
    volatile uint32_t GTPR;   // Guard time and prescaler register
} USART_TypeDef;



#define USART1   ((USART_TypeDef *) USART1_BASE)
#define USART2   ((USART_TypeDef *) USART2_BASE)
#define USART3   ((USART_TypeDef *) USART3_BASE)



// ============================
// API
// ============================

void UART_Init(USART_TypeDef *USARTx, uint32_t baudrate, uint8_t dataBits, uint8_t stopBits, char parity);
void UART_WriteChar(USART_TypeDef *USARTx, char c);
char UART_ReadChar(USART_TypeDef *USARTx);
void UART_WriteString(USART_TypeDef *USARTx, const char *str);
void UART_ReadString(USART_TypeDef *USARTx, char *buffer, uint16_t maxLength);

#endif
