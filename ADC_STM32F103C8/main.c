#include "ADC.h"
#include "GPIO.h"
#include "RCC.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    // RCC, GPIO already enabled in ADC1_Init
    GPIO_Config(GPIOA, 0, MODE_INPUT, CNF_ANALOG, PULL_NONE); // PA0 (ADC1_IN0)

    ADC_Config_t adc_config = {
        .channel = 0,
        .sample_time = ADC_Sample_28_5,
        .continuous_mode = 0,
        .data_align = 0 // Right alignment
    };

    ADC1_Init(adc_config);

    while (1)
    {
        uint16_t value = ADC1_Read();
        // Debug or process value
        for (volatile int i = 0; i < 100000; i++);
    }
}
