#include<pushbutton.h>

int main(void)
{
	_init_();
	while(1)
	{
		if(GPIOC -> IDR & (1U << 13) != 0)
		{
			led_off();
//			for(int i = 0; i <= 90000; i++){}
//			led_off();
//			for(int i = 0; i<= 90000; i++){}
		}

		if(GPIOC -> IDR & (1U << 13) == 0)
				{
					led_on();
		//			for(int i = 0; i <= 90000; i++){}
		//			led_off();
		//			for(int i = 0; i<= 90000; i++){}
				}
//		else
//		{
//			led_on();
//		}

		for(int i = 0; i <= 90000; i++){}

	}

}
