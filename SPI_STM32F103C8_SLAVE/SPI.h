#ifndef SPI_H_
#define SPI_H_

#include <stdint.h> 

typedef struct {
  volatile uint32_t CR1;     // 0x00
  volatile uint32_t CR2;     // 0x04
  volatile uint32_t SR;      // 0x08
  volatile uint32_t DR;      // 0x0C
  volatile uint32_t CRCPR;   // 0x10
  volatile uint32_t RXCRCR;  // 0x14
  volatile uint32_t TXCRCR;  // 0x18
  volatile uint32_t I2SCFGR; // 0x1C
  volatile uint32_t I2SPR;   // 0x20
} SPI_TypeDef;

#define SPI1_BASE (0x40013000UL)
#define SPI1 ((SPI_TypeDef *)SPI1_BASE)

#define SPI_SLAVE        0
#define SPI_MASTER       1

#define SPI_HARDWARE_NSS 0
#define SPI_SOFTWARE_NSS 1

#define SPI_NSS_LOW      0
#define SPI_NSS_HIGH     1

#define SPI_MODE_0     0  // CPOL = 0, CPHA = 0
#define SPI_MODE_1     1  // CPOL = 0, CPHA = 1
#define SPI_MODE_2     2  // CPOL = 1, CPHA = 0
#define SPI_MODE_3     3  // CPOL = 1, CPHA = 1

// Bit order
#define SPI_MSB_FIRST  0
#define SPI_LSB_FIRST  1

// Data size
#define SPI_DATASIZE_8BIT   0
#define SPI_DATASIZE_16BIT  1

// Baudrate Prescaler
#define SPI_BAUD_DIV_2     0   // 0b000
#define SPI_BAUD_DIV_4     1   // 0b001
#define SPI_BAUD_DIV_8     2   // 0b010
#define SPI_BAUD_DIV_16    3   // 0b011
#define SPI_BAUD_DIV_32    4   // 0b100
#define SPI_BAUD_DIV_64    5   // 0b101
#define SPI_BAUD_DIV_128   6   // 0b110
#define SPI_BAUD_DIV_256   7   // 0b111

// API
void SPI1_Config(uint8_t masterSlave, uint8_t ssmEnable, uint8_t nssLevel,uint8_t mode, uint8_t bitOrder, uint8_t dataSize, uint8_t baudRatePrescaler);
void SPI_Transmit(uint8_t data);
uint8_t SPI_Receive(void);
uint8_t SPI_TransmitReceive(uint8_t data);
void SPI1_GPIO_Init(void);
#endif