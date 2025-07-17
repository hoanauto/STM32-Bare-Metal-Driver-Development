#include "SPI.h"
#include "RCC.h"
#include "GPIO.h"
void delay_ms(uint32_t ms){
    for (uint32_t i = 0; i < ms; i++)
    {
        for (volatile uint32_t j = 0; j < 8000; j++); // Ði?u ch?nh giá tr? 8000 tùy t?c d? clock
    }
}
int main(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	 GPIO_Config(GPIOA, 5, MODE_OUTPUT_50MHZ, CNF_AF_PUSH_PULL, PULL_NONE);

    // MISO (PA6) -> Input, Floating
    GPIO_Config(GPIOA, 6, MODE_INPUT, CNF_FLOATING, PULL_NONE);

    // MOSI (PA7) -> Output, Alternate Function Push-Pull
    GPIO_Config(GPIOA, 7, MODE_OUTPUT_50MHZ, CNF_AF_PUSH_PULL , PULL_NONE);
	  // NSS (PA4): Output push-pull n?u dùng ph?n m?m NSS
    GPIO_Config(GPIOA, 4, MODE_OUTPUT_50MHZ, CNF_GP_PUSH_PULL, PULL_NONE); 
	
	 SPI1_Config(SPI_MODE_0, SPI_MSB_FIRST, SPI_DATASIZE_8BIT,
                SPI_BAUD_DIV_8, SPI_MASTER, SPI_SOFTWARE_NSS, SPI_NSS_HIGH);
	static uint8_t dataSend[] = {3,1,10,19,20,36,90};
	

	while (1)
		{  GPIO_Write(GPIOA, 4, LOW);        // G?t NSS xu?ng
				for(uint8_t i=0; i<7; i++)
	{
        SPI_Transmit(dataSend[i]);               // G?i d? li?u
				delay_ms(100);
	}
        GPIO_Write(GPIOA, 4, HIGH);       // G?t NSS lên
					delay_ms(10);
			}
	}
