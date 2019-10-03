#pragma once
#include "board.h"
#define PULSE do { palClearPad(GPIOA, GPIOA_LED); palSetPad(GPIOA, GPIOA_LED);} while(0)
