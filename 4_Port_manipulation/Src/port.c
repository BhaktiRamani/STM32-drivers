/*Considering PB8, PA10, PB3 as output and trying Port Manipulation*/

#include "port.h"


#define GPIOBEN (1<<1);

void _port_init(void)
{
	/*Setup Clock for Port B*/
	RCC -> AHB1ENR |= GPIOBEN;

	/*Define PB8, PB3, PA10 as GPIO OUTPUT using GPIOx_MODER*/
	GPIOB -> MODER &= ~(1<<17);
	GPIOB -> MODER |= (1<<16);

	GPIOB -> MODER &= ~(1<<7);
	GPIOB -> MODER |= (1<<6);

	GPIOB -> MODER &= ~(1<<21);
	GPIOB -> MODER |= (1<<20);

}

void high(void)
{
	/*Keep the pins high*/
	GPIOB -> ODR |= (1<<8);
	GPIOB -> ODR |= (1<<3);
	GPIOA -> ODR |= (1<<10);
}

void low(void)
{
	/*Keep the pins low*/
	GPIOB -> ODR &= ~(1<<8);
	GPIOB -> ODR &= ~(1<<3);
	GPIOA -> ODR &= ~(1<<10);
}
