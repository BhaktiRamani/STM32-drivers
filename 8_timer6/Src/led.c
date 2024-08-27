#include "led.h"

#define GPIOAEN (1U<<0) 	//0x00000001 , for later use to enable clock signal for Port A
#define LED_PIN (1U<<5)

void led_init(void)
{
	/*Enable clock access for Port A*/
	RCC -> AHB1ENR |= GPIOAEN;				//setting bit 1 of register RCC_AHB1ENR as high (RM_pg_144)

	/*Define pin 5 of PORT A as OUTPUT*/
	GPIOA -> MODER |= (1U << 10);
	GPIOA -> MODER &= ~ (1U << 11);			//GPIOX_MODER register use to define output (RM_pg_187)
}

void led_on(void)
{
	/*Enable PA5*/
	GPIOA -> ODR |= LED_PIN;
}

void led_off(void)
{
	/*Disable PA5*/
	GPIOA -> ODR &= ~LED_PIN;
}
