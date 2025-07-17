#include <stdint.h>
#include "RCC.h"
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, uint8_t NewState)
{
  /* Check the parameters */

  if (NewState != DISABLE)
  {
    RCC->APB2ENR |= RCC_APB2Periph;
  }
  else
  {
    RCC->APB2ENR &= ~RCC_APB2Periph;
  }
}
