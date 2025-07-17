#include "GPIO.h"
#include "SPI.h"
#include "RCC.h"

#define SPI1_NSS 4 // PA4 dùng làm NSS (chip select)

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms; i++) {
        for (volatile uint32_t j = 0; j < 8000; j++); // ch?nh theo t?c d? clock
    }
}

int main(void)
{
    // 1. B?t clock cho GPIOA và SPI1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

    // 2. C?u hình các chân SPI
    GPIO_Config(GPIOA, 5, MODE_INPUT, CNF_FLOATING, PULL_NONE);              // SCK
    GPIO_Config(GPIOA, 6, MODE_OUTPUT_50MHZ, CNF_AF_PUSH_PULL, PULL_NONE);   // MISO
    GPIO_Config(GPIOA, 7, MODE_INPUT, CNF_FLOATING, PULL_NONE);              // MOSI
    GPIO_Config(GPIOA, 4, MODE_INPUT, CNF_FLOATING, PULL_NONE);              // NSS 

    // 3. C?u hình SPI1 ? ch? d? Slave
    SPI1_Config(SPI_MODE_0, SPI_MSB_FIRST, SPI_DATASIZE_8BIT,
                SPI_BAUD_DIV_8, SPI_SLAVE, SPI_SOFTWARE_NSS, SPI_NSS_LOW); // NSS th?p, gi? SPI ho?t d?ng

    // 4. Nh?n d? li?u
    uint8_t spi_rx_buffer[32];
    uint8_t index = 0;

    while (1)
    {
        // Ki?m tra n?u Master kéo NSS xu?ng thì m?i nh?n
        if (GPIO_Read(GPIOA, SPI1_NSS) == 0)
        {
            uint8_t data = SPI_Receive(); // Nh?n d? li?u SPI
            spi_rx_buffer[index++] = data;

            if (index >= sizeof(spi_rx_buffer)) index = 0;

            delay_ms(10); // tránh nh?n quá nhanh
        }
        else
        {
            index = 0; // Reset n?u NSS không còn kích ho?t
        }
    }
}
