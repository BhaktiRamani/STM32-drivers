#include "led.h"
#include "uart.h"
#include <stdio.h>

int main(void)
{
	clock_config();
	led_init();
	_uart_tx_init();
	char x = 'C';
	//uint8_t data[30] = "hello";
	while(1)
	{
	//printf("abcdef");
		putchar(x);
		//printf("hello\n");
		//printf(data);
//		led_on();
//		for(int i = 0; i<=9000; i++){}
//		led_off();
		for(int i = 0; i<=100000; i++){}
	}

}
