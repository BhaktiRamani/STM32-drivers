#include<pushbutton.h>

#define GPIOAEN (1U<<0)
#define GPIOCEN (1U<<2)
#define LED_PIN (1U<<5)

void _init_(void)
{
	/*Enable clock signal for Port A & Port C */
	RCC -> AHB1ENR |= GPIOAEN;
	RCC -> AHB1ENR |= GPIOCEN;

	/*Set PA5 as Output*/
	GPIOA -> MODER |= (1U << 10);
	GPIOA -> MODER &= ~ (1U << 11);	//GPIOX_MODER register use to define output (RM_pg_187)

	/*Set PC13 as Input*/
	GPIOC -> MODER &= ~ (1U << 26);
	GPIOC -> MODER &= ~ (1U << 27);

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

