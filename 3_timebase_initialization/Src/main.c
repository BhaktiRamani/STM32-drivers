#include "led.h"
#include "uart.h"
#include "timebase.h"



int main(void)
{
	led_init();
	_uart_tx_init();
	timebase_init();
	char x = 'k';
	while(1)
	{
//		led_on();
		//putchar('\n');
		delay(1);
		putchar(x);
//		led_off();
		//for(int i = 0; i<=100000; i++){}

	}

}
