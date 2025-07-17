#include "GPIO.h"


void GPIO_Config(GPIO_Type *PORT, uint8_t pin, uint8_t mode, uint8_t cnf, uint8_t pull)

{
    uint32_t pos = (pin % 8) * 4;           // M?i chân 4 bit, chia lay so du 
    uint32_t config = ((cnf << 2) | mode);  // MODE[1:0] + CNF[1:0]

    if (pin < 8)
    {
        PORT->CRL &= ~(0xF << pos);         // Clear c?u hình cu
        PORT->CRL |= (config << pos);       // Set c?u hình m?i
    }
    else
    {
        PORT->CRH &= ~(0xF << pos);
        PORT->CRH |= (config << pos);
    }

    // N?u là input pull-up/pull-down ? c?n c?u hình ODR
    if (mode == MODE_INPUT && cnf == CNF_PULL)
    {
        if (pull == PULL_UP)
            PORT->ODR |= (1 << pin);        // Pull-up
        else
            PORT->ODR &= ~(1 << pin);       // Pull-down
    }
}
void GPIO_Write(GPIO_Type *PORT, unsigned char index, unsigned char status)
{
    if (status == HIGH) {
        PORT->BSRR = (1 << index);   // Set pin
    } else {
        PORT->BRR = (1 << index);    // Reset pin
    }
}
unsigned char GPIO_Read(GPIO_Type *PORT, unsigned char index)
{
    return (PORT->IDR & (1 << index)) ? 1 : 0; // neu 1 tra ve 1, neu 0 tra ve 0
}
