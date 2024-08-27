#ifndef _PORT_H_
#define _PORT_H_

#include "stm32f4xx.h"

void _port_init(void);
void write_address(uint16_t data);
uint32_t read_eeprom(void);
void disable_SDK();

#endif
