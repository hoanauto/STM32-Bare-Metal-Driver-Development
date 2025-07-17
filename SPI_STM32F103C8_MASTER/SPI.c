#include "SPI.h"


void SPI1_Config(uint8_t mode, uint8_t bitOrder, uint8_t dataSize, uint8_t baudRatePrescaler,
                 uint8_t masterSlave, uint8_t ssmEnable, uint8_t nssLevel)
{
    SPI1->CR1 = 0; // Reset CR1

    // Master or Slave
    if (masterSlave == SPI_MASTER)
        SPI1->CR1 |= (1 << 2); // MSTR
    else
        SPI1->CR1 &= ~(1 << 2);

    // Software slave management
    if (ssmEnable == SPI_SOFTWARE_NSS)
    {
        SPI1->CR1 |= (1 << 9); // SSM
        if (nssLevel == SPI_NSS_HIGH)
            SPI1->CR1 |= (1 << 8); // SSI = 1
        else
            SPI1->CR1 &= ~(1 << 8); // SSI = 0
    }

    // CPOL and CPHA
    if (mode & 0x01) SPI1->CR1 |= (1 << 0); // CPHA
    if (mode & 0x02) SPI1->CR1 |= (1 << 1); // CPOL

    // Bit order
    if (bitOrder == SPI_LSB_FIRST)
        SPI1->CR1 |= (1 << 7);
    else
        SPI1->CR1 &= ~(1 << 7);

    // Data frame format
    if (dataSize == SPI_DATASIZE_16BIT)
        SPI1->CR1 |= (1 << 11);
    else
        SPI1->CR1 &= ~(1 << 11);

    // Baud rate
    SPI1->CR1 |= (baudRatePrescaler << 3);  // BR[2:0]

    // Enable SPI
    SPI1->CR1 |= (1 << 6); // SPE
}
void SPI_Transmit(uint8_t data)
{
    // Ð?i d?n khi TXE (Transmit buffer empty) du?c set
    while (!(SPI1->SR & (1 << 1))); // TXE = 1

    // Ghi d? li?u vào thanh ghi truy?n
    SPI1->DR = data;

    // Ð?i d?n khi BSY = 0, d?m b?o SPI dã truy?n xong
    while (SPI1->SR & (1 << 7)); // BSY = 0 khi xong
}
uint8_t SPI_Receive(void)
{
    // G?i dummy byte d? t?o xung clock cho slave ph?n h?i
    SPI_Transmit(0xFF); // G?i b?t k? d? kích ho?t clock

    // Ð?i cho d?n khi có d? li?u nh?n
    while (!(SPI1->SR & (1 << 0))); // RXNE = 1

    // Ð?c d? li?u t? thanh ghi nh?n
    return (uint8_t)(SPI1->DR);
}
uint8_t SPI_TransmitReceive(uint8_t data)
{
    // Ð?i buffer tr?ng
    while (!(SPI1->SR & (1 << 1))); // TXE = 1

    // Ghi d? li?u
    SPI1->DR = data;

    // Ð?i d?n khi có d? li?u nh?n
    while (!(SPI1->SR & (1 << 0))); // RXNE = 1

    // Tr? v? d? li?u nh?n du?c
    return (uint8_t)(SPI1->DR);
}


