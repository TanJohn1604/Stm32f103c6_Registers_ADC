/*
 * adc.c
 *
 *  Created on: Jun 10, 2022
 *      Author: ad
 */
#include "adc.h"

void ADC_Init(void){
	//Bật clock adc1
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//bật clock cho port a
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//bật afio cho port a để cấu hình analog (khong can)
//	RCC->APB2ENR |=RCC_APB2ENR_AFIOEN;
	//prescale clock cho adc /2
	RCC->CFGR &= ~RCC_CFGR_ADCPRE_0;
	RCC->CFGR &= ~RCC_CFGR_ADCPRE_1;

	//Interrupt enable for EOC
	ADC1->CR1|=ADC_CR1_EOCIE;
	// enable scan mode
	ADC1->CR1|= ADC_CR1_SCAN;
	//12 bit data align right
	ADC1->CR2 &=~ADC_CR2_ALIGN;
	// continuous conversion
	ADC1->CR2|= ADC_CR2_CONT;
	// sampling time chanel 0 : 1.5CYCLE
	ADC1->SMPR2 &=~ ADC_SMPR2_SMP0;
	//Regular channel sequence length
	ADC1->SQR1&=~ ADC_SQR1_L;
	//bat pa0 thanh analog in


	GPIOA->CRL &=~ GPIO_CRL_CNF0;
	GPIOA->CRL&= ~GPIO_CRL_MODE0;

	GPIOA->CRL &= ~GPIO_CRL_MODE1;
	GPIOA->CRL &= ~GPIO_CRL_CNF1;

	GPIOA->CRL &= ~GPIO_CRL_MODE4;
	GPIOA->CRL &= ~GPIO_CRL_CNF4;
}

void ADC_Enable(void){
	ADC1->CR2 |= ADC_CR2_ADON;
	uint32_t delay = 10000;
	while(delay--);
	ADC1->CR2 |= ADC_CR2_ADON;
}

void ADC_Start(int channel){
	//đưa channel
	ADC1->SQR3 |= (channel<<0);
	//reset status
	ADC1->SR=0;
	//bat
	ADC1->CR2|=ADC_CR2_SWSTART;
}
void ADC_WaitForConv(void){
	while(!(ADC1->SR & (ADC_SR_EOC)));
}
uint16_t ADC_GetVal(void){
	return ADC1->DR;
}

void ADC_Disable(void){
	ADC1->CR2 &=~ ADC_CR2_ADON;
}



