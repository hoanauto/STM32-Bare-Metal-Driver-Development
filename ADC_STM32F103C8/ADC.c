#include "ADC.h"
#include "RCC.h"



void ADC1_Init(ADC_Config_t config)
{

    

    // ADC reset
    ADC1->CR2 &= ~(1 << 0); // ADON = 0

    // Set sample time
    if (config.channel <= 9) {
        ADC1->SMPR2 &= ~(0x7 << (config.channel * 3));
        ADC1->SMPR2 |= (config.sample_time << (config.channel * 3));
    } else {
        uint8_t ch = config.channel - 10;
        ADC1->SMPR1 &= ~(0x7 << (ch * 3));
        ADC1->SMPR1 |= (config.sample_time << (ch * 3));
    }

    // Set data alignment
    if (config.data_align == 1)
        ADC1->CR2 |= (1 << 11); // left align
    else
        ADC1->CR2 &= ~(1 << 11); // right align

    // Configure channel in regular sequence
    ADC1->SQR3 = config.channel;

    // Set continuous mode
    if (config.continuous_mode)
        ADC1->CR2 |= (1 << 1);
    else
        ADC1->CR2 &= ~(1 << 1);

    // Power on ADC
    ADC1->CR2 |= (1 << 0);
    for (volatile int i = 0; i < 1000; i++); // short delay

    // Calibration
    ADC1->CR2 |= (1 << 3); // Reset calibration
    while (ADC1->CR2 & (1 << 3));
    ADC1->CR2 |= (1 << 2); // Start calibration
    while (ADC1->CR2 & (1 << 2));

    // Start conversion for single mode
    if (!config.continuous_mode)
        ADC1->CR2 |= (1 << 22);
}

uint16_t ADC1_Read(void)
{
    // Start conversion if not in continuous
    if (!(ADC1->CR2 & (1 << 1)))
        ADC1->CR2 |= (1 << 22);

    while (!(ADC1->SR & (1 << 1))); // Wait for EOC
    return (uint16_t)ADC1->DR;
}
