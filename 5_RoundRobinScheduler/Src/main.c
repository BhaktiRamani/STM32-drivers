#include "led.h"
#include "uart.h"
#include "osKernel.h"

#define QUANTA 		30

typedef uint32_t TaskProfiler;
TaskProfiler Task0_Profiler, Task1_Profiler, Task2_Profiler;

void task0(void)
{
	while(1)
	{
		Task0_Profiler++;
	}
}

void task1(void)
{
	while(1)
	{
		Task1_Profiler++;
	}
}

void task2(void)
{
	while(1)
	{
		Task2_Profiler++;
	}
}


int main(void)
{
	//_uart_tx_init();

	/*Initialize Kernel*/
	osKernelInit();

	/*Add Thread*/
	osKernelAddThreads(&task0, &task1, &task2);

	/*Set RoundRobin time quanta*/
	osKernelLaunch(QUANTA);



}
