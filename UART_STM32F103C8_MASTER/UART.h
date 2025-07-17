#ifndef UART_H_
#define UART_H_

#include <stdint.h>

// ============================
// Ð?A CH? THANH GHI C?A USART
// ============================

#define USART1_BASE  0x40013800UL
#define USART2_BASE  0x40004400UL
#define USART3_BASE  0x40004800UL

// ============================
// STRUCT MÔ PH?NG THANH GHI
// ============================

typedef struct {
    volatile uint32_t SR;     // Status register
    volatile uint32_t DR;     // Data register
    volatile uint32_t BRR;    // Baud rate register
    volatile uint32_t CR1;    // Control register 1
    volatile uint32_t CR2;    // Control register 2
    volatile uint32_t CR3;    // Control register 3
    volatile uint32_t GTPR;   // Guard time and prescaler register
} USART_TypeDef;

// ============================
// CON TR? T?I CÁC USART
// ============================

#define USART1   ((USART_TypeDef *) USART1_BASE)
#define USART2   ((USART_TypeDef *) USART2_BASE)
#define USART3   ((USART_TypeDef *) USART3_BASE)

// ============================
// ENUM CHO C?U HÌNH UART
// ============================

typedef enum {
    UART_PARITY_NONE = 0,
    UART_PARITY_EVEN,
    UART_PARITY_ODD
} UART_Parity_t;

typedef enum {
    UART_MODE_TX = 0x1,
    UART_MODE_RX = 0x2,
    UART_MODE_TX_RX = 0x3
} UART_Mode_t;

// ============================
// C?U HÌNH UART B?NG STRUCT
// ============================

typedef struct {
    USART_TypeDef *Instance;
    uint32_t baudrate;
    uint8_t word_length;          // 8 ho?c 9
    UART_Parity_t parity;
    UART_Mode_t mode;
} UART_Config_t;

// ============================
// API
// ============================

void UART1_Init(UART_Config_t *config);
void UART_WriteChar(USART_TypeDef *USARTx, char c);
char UART_ReadChar(USART_TypeDef *USARTx);
void UART_WriteString(USART_TypeDef *USARTx, const char *str);

#endif
