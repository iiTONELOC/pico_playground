#ifndef ECHO_LOCATION_H
#define ECHO_LOCATION_H
#include "pico/stdlib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Echo location sensor pins
extern uint ECHO_PIN;
extern uint TRIG_PIN;

// Echo location sensor variables
extern double echo_distance;
double pulseIn(uint pin, uint state);
double check_distance(void);
void init_echo_location(void);

#endif
