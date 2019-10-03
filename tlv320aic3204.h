#pragma once

/*
 * tlv320aic3204.c
 */
typedef struct {
  int target_level;
  int gain_hysteresis;
  int attack;
  int attack_scale;
  int decay;
  int decay_scale;
} tlv320aic3204_agc_config_t;

extern void tlv320aic3204_init(void);
extern void tlv320aic3204_set_gain(int lgain, int rgain);
extern void tlv320aic3204_set_digital_gain(int gain);
extern void tlv320aic3204_set_volume(int gain);
extern void tlv320aic3204_agc_config(tlv320aic3204_agc_config_t *conf);
extern void tlv320aic3204_select_in1(void);
extern void tlv320aic3204_select_in3(void);
extern void tlv320aic3204_adc_filter_enable(int enable);
