/*
 * RccTimerConfig.h
 *
 *  Created on: Mar 25, 2022
 *      Author: ad
 */

#ifndef RCCTIMERCONFIG_H_
#define RCCTIMERCONFIG_H_
#include <stdint.h>
#include "stm32f1xx.h"
void config(void);
void delay_us(uint16_t us );
void delay_ms(uint16_t ms );
#endif /* RCCTIMERCONFIG_H_ */
