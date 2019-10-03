#pragma once

#include <stdint.h>

// DO NOT INCLUDE THIS FILE OTHER THAN FROM main.c!!!!!

void cal_collect(int type);
void cal_done(void);


void set_sweep_frequency(int type, float frequency);
uint32_t get_sweep_frequency(int type);

float my_atof(const char *p);

void toggle_sweep(void);



void set_trace_type(int t, int type);
void set_trace_channel(int t, int channel);
void set_trace_scale(int t, float scale);
void set_trace_refpos(int t, float refpos);
void draw_battery_status(void);

void set_electrical_delay(float picoseconds);
float get_electrical_delay(void);



void apply_edelay_at(int i);

void set_frequencies(uint32_t start, uint32_t stop, int16_t points);
void update_frequencies(void);


void
cal_collect(int type);

void
cal_done(void);

