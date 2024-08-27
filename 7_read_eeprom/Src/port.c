/*Considering PB8, PA10, PB3 as output and trying Port Manipulation*/

#include "port.h"
#include "uart.h"
#include <stdint.h>
#include "timebase.h"


#define GPIOBEN (1<<1);
#define GPIOCEN (1<<2);
#define WE (1<<9);
#define OE (1<<8);

void _port_init(void)
{
	/*Setup Clock for Port B*/
	RCC -> AHB1ENR |= GPIOBEN;
	RCC -> AHB1ENR |= GPIOCEN;

	/*Define Pin B0-B5 as GPIO output pins using GPIOx_MODER*/
	//GPIOB -> MODER &= ~(0xFFFFFFFF);
	GPIOB -> MODER = (0x55555555);


	/*Define Pin C0-C7 as GPIO input pins using GPIOx_MODER*/
	//GPIOC -> MODER &= ~(0xFFFF);
	//GPIOD -> MODER &= ~(1<<4);
	//GPIOD -> MODER &= ~(1<<5);

	/*Define Pin C8-C9 as GPIO output pins*/
	GPIOC -> MODER &= ~(1<<19);
	GPIOC -> MODER &= ~(1<<17);
	GPIOC -> MODER |= (1<<16);
	GPIOC -> MODER |= (1<<18);



}


void write_address(uint16_t data)
{
	GPIOB -> ODR = data;
}

uint32_t read_eeprom(void)
{
//	uint16_t data = 0;
//	data = (uint16_t)GPIOC -> IDR & 0xff;
//	return data;

	/*Define Pin C0-C7 as GPIO input pins using GPIOx_MODER*/
	GPIOC -> MODER &= ~(0xFFFF);
	GPIOC -> ODR &= ~OE;
	GPIOC -> ODR |= WE;

	/*Define Pin C8(OE) = low and C9(WE) = high */
	putchar(GPIOC->IDR);
	return 0;
}

