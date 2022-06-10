/*
 * adc_watchdog.c
 *
 *  Created on: Jun 10, 2022
 *      Author: ad
 */
#include"adc_watchdog.h"

void ADC_Wachdog(){
ADC1->CR1 |= ADC_CR1_AWDEN;
ADC1->HTR |= 4000;
ADC1->LTR |= 100;
ADC1->CR1 |= ADC_CR1_AWDIE;

__disable_irq();
NVIC_EnableIRQ(ADC1_2_IRQn);
__enable_irq();
}
