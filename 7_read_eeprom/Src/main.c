#include "uart.h"
#include "timebase.h"
#include "port.h"



int main(void)
{
	_uart_tx_init();
	_port_init();
	timebase_init();
	//char h = 'h';
	//char l = 'l';
	//write_address(0x11);
	//putchar(h);
	write_address(0x12);
	read_eeprom();
	delay(1);




//	uint16_t result = read_eeprom();
//	putchar(result);
//	read_eeprom();
//	delay(2);

//	char state = 'i';
//	if(state == 'i')
//	{
//		/*Defining Pin C0-C7 as input*/
//		GPIOC -> MODER &= ~(0xFFFF);
//
//		read_eeprom();
//	}
//	else
//	{
//		/*Defining pin C0-C7 as output*/
//		GPIOC -> MODER = (0x5555);
//
//		write_eeprom(data);
//	}

}
