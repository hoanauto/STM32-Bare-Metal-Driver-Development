// ADC.h
#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#define ADC1_BASE 0x40012400
#define ADC1 ((ADC_TypeDef *)ADC1_BASE)

typedef struct {
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t JSQR;
    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;
    volatile uint32_t DR;
} ADC_TypeDef;

// Sample time enum (can be expanded)
typedef enum {
    ADC_Sample_1_5 = 0,
    ADC_Sample_7_5 = 1,
    ADC_Sample_13_5 = 2,
    ADC_Sample_28_5 = 3,
    ADC_Sample_41_5 = 4,
    ADC_Sample_55_5 = 5,
    ADC_Sample_71_5 = 6,
    ADC_Sample_239_5 = 7
} ADC_SampleTime_t;

// ADC config struct
typedef struct {
    uint8_t channel;             // Channel number (0 - 17)
    ADC_SampleTime_t sample_time;
    uint8_t continuous_mode;     // 0 = single, 1 = continuous
    uint8_t data_align;          // 0 = right, 1 = left
} ADC_Config_t;

void ADC1_Init(ADC_Config_t config);
uint16_t ADC1_Read(void);

#endif // ADC_H_
