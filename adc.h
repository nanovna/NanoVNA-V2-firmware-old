#pragma once

/*
 * adc.c
 */

void adc_init(void);
uint16_t adc_single_read(ADC_TypeDef *adc, uint32_t chsel);
void adc_start_analog_watchdogd(ADC_TypeDef *adc, uint32_t chsel);
void adc_stop(ADC_TypeDef *adc);
void adc_interrupt(ADC_TypeDef *adc);
int16_t adc_vbat_read(ADC_TypeDef *adc);
