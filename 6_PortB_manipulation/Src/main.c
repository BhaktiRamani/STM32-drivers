#include "uart.h"
#include "timebase.h"
#include "port.h"
#include "clock_setup.h"



int main(void)
{
	clock_config();
	_uart_tx_init();
	_port_init();
	timebase_init();
	char h = 'h';
	//char l = 'l';
	//write_address(0x11);
	//putchar(h);

	disable_SDK();
	putchar(h);

	delay(1);
	write_address(0x12);
	delay(5);
	uint32_t result = read_eeprom();
	putchar(result & 0xff);
	delay(5);





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
