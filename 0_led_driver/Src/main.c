#include "led.h"
#include "clock_setup.h"

int main(void)
{
	clock_config();
	led_init();
	while(1)
	{
		led_on();
		for(int i = 0; i<=9000000; i++){}
		led_off();
		for(int i = 0; i<=10000000; i++){}
	}

}
