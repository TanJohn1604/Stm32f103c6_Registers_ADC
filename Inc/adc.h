/*
 * adc.h
 *
 *  Created on: Jun 10, 2022
 *      Author: ad
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
#include "stm32f1xx.h"
void ADC_Init(void);
void ADC_Enable(void);
void ADC_Start(int channel);
void ADC_WaitForConv(void);
uint16_t ADC_GetVal(void);
void ADC_Disable(void);

#endif /* ADC_H_ */
