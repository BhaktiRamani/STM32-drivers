//writing code to only transmit data using USART2 of stm32446RE
#include "uart.h"
#include "stm32f4xx.h"

#include <stdint.h>

#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)

#define SYS_FREQ 16000000
#define APB1_CLK SYS_FREQ
#define UART_BAUDRATE 115200

#define CR1_TE (1<<3)
#define UARTEN (1<<13)

static uint16_t _compute_uart_bd(uint32_t periph_clk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate);
static void uart_write(int ch);

int putchar(int ch)
{
	uart_write(ch);
	return ch;
}

void _uart_tx_init(void)
{
	/*Enable clock access for PORT A because USART2 pins are in PORT A DS_pg_16*/
	RCC -> AHB1ENR |= GPIOAEN;	//setting bit 1 of register RCC_AHB1ENR as high (RM_pg_144)

	/*Set PA2 (USART2_Tx) as alternate function mode (Direction Register)*/
	GPIOA -> MODER |= (1U<<5);
	GPIOA -> MODER &= ~(1U<<4);

	/*Define af as AF07 DS_pg_48*/
	GPIOA -> AFR[0] |= (1U << 8);
	GPIOA -> AFR[0] |= (1U << 9);
	GPIOA -> AFR[0] |= (1U << 10);
	GPIOA -> AFR[0] &= ~(1U << 11);		//GPIOX_AFRL register RM_pg_191, setting AF7 = 0111


	/*Enable clock access to USART2 (APB1 bus)*/
	RCC -> APB1ENR |= UART2EN;

	/*Configure baud rate*/
	uart_set_baudrate(APB1_CLK, UART_BAUDRATE);

	/*Configure transfer direction*/
	USART2 -> CR1 = CR1_TE;

	/*Enable UART module*/
	USART2 -> CR1 |= USART_CR1_UE;

}

static void uart_write(int ch)
{
	/*Empty the transmit register*/
	while(!(USART2 -> SR) & (1 << 7)) {}
	//while (!(USART2->SR & USART_SR_TXE)) {}

	/*Write to transmit data register*/
	USART2 -> DR = (ch & 0xFF);
}

static uint16_t _compute_uart_bd(uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate/2U))/baudrate);
	  //return (periph_clk / baudrate);
}

static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	USART2 -> BRR = _compute_uart_bd(periph_clk, baudrate);
}







