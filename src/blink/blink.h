#ifndef BLINK_H
#define BLINK_H
#include "pico/stdlib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

extern uint LED_PIN;

void blink(int rate);
#endif
