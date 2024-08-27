#ifndef _TIMER_H__
#define _TIMER_H__

#include "stm32f4xx.h"
#include "stdint.h"


void TIM6Config(void);
void Delay_us(uint16_t us);
void Delay_ms(uint16_t ms);

#endif
