#pragma once

#include <stdint.h>

/*
 * dsp.c
 */
// 5ms @ 48kHz
#define AUDIO_BUFFER_LEN 96

extern int16_t rx_buffer[];

#define STATE_LEN 32
#define SAMPLE_LEN 48

extern int16_t ref_buf[];
extern int16_t samp_buf[];

void dsp_process(int16_t *src, size_t len);
void reset_dsp_accumerator(void);
void calculate_gamma(float *gamma);
void fetch_amplitude(float *gamma);
void fetch_amplitude_ref(float *gamma);
