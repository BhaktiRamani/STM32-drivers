#include "clock_setup.h"
#include "stm32f4xx.h"

/*Steps to change clock frequency from 16 Mhz to 108 Mhz*/

/*
 	1. ENABLE HSE and wait for the HSE to become Ready
 		HSE - High Speed  External Oscillator

	2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
		Turning on Power for External clock source

	3. Configure the FLASH PREFETCH and the LATENCY Related Settings
		- FLASH PREFATCH - Flash prefetch is a feature that predicts and retrieves instructions
		  from Flash memory before they are needed, reducing the delay between instruction fetches and execution.
		- FLASH LATANCY - Flash latency is the delay in accessing data stored in Flash memory,
		  particularly relevant at higher clock frequencies. It's mitigated by adjusting wait states between Flash memory accesses.

	4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
		HCLK (AHB clock), PCLK1 (APB1 clock), and PCLK2 (APB2 clock).

	5. Configure the MAIN PLL
		To generate the stable clock source using multipliers and divisors.

	6. Enable the PLL and wait for it to become ready

	7. Select the Clock Source and wait for it to be set
*/

#define PLL_M 	4
#define PLL_N 	180
#define PLL_P 	0  // PLLP = 2


void clock_config(void)
{
	/*1) Defining HSE using RCC_CR register    RM_127*/
	RCC -> CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));

	/*2) Enabling the power using RCC_APB1ENR register 		RM_147*/
	RCC -> APB1ENR |= RCC_APB1ENR_PWREN  ;
	PWR -> CR |= PWR_CR_VOS;								/*RM_111*/

	/*3) Flash Prefatch and Latency settings*/
	FLASH->ACR |= 1<<8;
	FLASH->ACR |= 1<<9;
	FLASH->ACR |= 1<<10;
	FLASH->ACR |= 5<<0;

	/*4) Configure Prescalers HCLK, PCLK1, PCLK2*/

	//AHB PR
	RCC -> CFGR |= RCC_CFGR_HPRE_DIV1;

	//APB1 PR
	RCC -> CFGR |= RCC_CFGR_PPRE1_DIV4;

	//APB2 PR
	RCC -> CFGR |= RCC_CFGR_PPRE2_DIV2;

	/*5) PLL settings*/
	RCC->PLLCFGR = (PLL_M <<0) | (PLL_N << 6) | (PLL_P <<16) | (1<<22);

	/*6)Enable the PLL and wait for it to become ready*/
	RCC -> CR |= RCC_CR_PLLON;
	while(!(RCC -> CR & RCC_CR_PLLRDY));

	/*7) Set clock source and wait for it to become ready*/
	RCC -> CFGR |= RCC_CFGR_SW_PLL;
	while((RCC -> CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}
