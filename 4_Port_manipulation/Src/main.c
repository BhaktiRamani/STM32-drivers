#include "uart.h"
#include "timebase.h"
#include "port.h"



int main(void)
{
	_uart_tx_init();
	_port_init();
	timebase_init();
	char h = 'h';
	char l = 'l';
	while(1)
	{
		high();
		putchar(h);
		delay(1);
		//for(int i = 0; i<=100000; i++){}
		low();
		putchar(l);
		//for(int i = 0; i<=100000; i++){}
		delay(2);


	}

}
