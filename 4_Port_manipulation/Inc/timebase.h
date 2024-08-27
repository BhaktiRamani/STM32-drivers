#ifndef _TIMEBASE_H_
#define _TIMEBASE_H_

#include <stdint.h>
#include <stdio.h>

uint32_t get_tick(void);
void timebase_init(void);
void delay(uint32_t delay);

#endif
