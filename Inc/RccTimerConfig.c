/*
 * RccTimerConfig.c
 *
 *  Created on: Mar 25, 2022
 *      Author: ad
 */

#include "RccTimerConfig.h"

void config(void){
	//bật clock ngoại
	RCC->CR |= RCC_CR_HSEON;
	//đợi cho clock ngoại bật xong
	while(!(RCC->CR & RCC_CR_HSERDY) );
	//chọn clock chính là clock ngoại hse
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	//đợi chọn clock chính là clock ngoại hse xong
	while(!(RCC->CFGR & RCC_CFGR_SWS_HSE));
	//cấu hình các bộ chia clock
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
	RCC->CFGR|= RCC_CFGR_PPRE2_DIV1;
	//bật clock cho port C ,Timer1
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	//cấu hình PortC13 output (led built-in)
	GPIOC->CRH &=~ GPIO_CRH_CNF13;
	GPIOC->CRH |= GPIO_CRH_MODE13;

	//cấu hình max thanh ghi đếm của timer
	TIM1->ARR =0xffff-1;
	//bộ chia của timer1 là 8: clock của timer1 là 8Mhz/8=1Mhz
	TIM1->PSC =8-1;
	//Bật timer1
	TIM1->CR1 |=TIM_CR1_CEN;
	//Đợi timer1 bật xong
	while(! (TIM1->SR & TIM_SR_UIF ));



}
void delay_us(uint16_t us ){
	TIM1->CNT=0;
	while(TIM1->CNT <us);

}
void delay_ms(uint16_t ms){

	for (uint16_t i=0; i<ms ;i++){
		delay_us(1000);
	}
}
