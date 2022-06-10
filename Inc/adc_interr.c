/*
 * adc_interr.c
 *
 *  Created on: Jun 10, 2022
 *      Author: ad
 */
#include"adc_interr.h"

void ADC_Interr(){
//Bật interrupt cho cờ EOC
ADC1->CR1 |=ADC_CR1_EOCIE;

__disable_irq();
NVIC_EnableIRQ(ADC1_2_IRQn);
__enable_irq();
}

