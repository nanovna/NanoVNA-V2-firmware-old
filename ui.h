#pragma once

#include <stdint.h>

/*
 * ui.c
 */
extern void ui_init(void);
extern void ui_process(void);


/*
 * ui.c
 */

typedef struct {
  int8_t digit; /* 0~5 */
  int8_t digit_mode;
  int8_t current_trace; /* 0..3 */
  uint32_t value; // for editing at numeric input area
  uint32_t previous_value;
} uistat_t;

extern uistat_t uistat;
  
void ui_init(void);
void ui_show(void);
void ui_hide(void);

extern uint8_t operation_requested;

void handle_touch_interrupt(void);

#define TOUCH_THRESHOLD 2000

void touch_cal_exec(void);
void touch_draw_test(void);
void touch_start_watchdog(void);
void touch_position(int *x, int *y);
void enter_dfu(void);
