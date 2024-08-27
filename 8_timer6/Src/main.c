#include "led.h"
//#include "clock_setup.h"
#include "timer6.h"

int main(void)
{
	//clock_config();
	led_init();
	TIM6Config();
	while(1)
	{
		led_on();
		Delay_ms(1);
		//Delay_us(1000);
		led_off();
		Delay_ms(2);
		//Delay_us(5000);
	}

}
