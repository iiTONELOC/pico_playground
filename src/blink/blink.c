#include "pico/stdlib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

uint LED_PIN = 22; // Doesn't interfere with SPI, I2C, UART, etc.

// Non wifi onboard LED - uncomment code below to use
// LED_PIN = 25;

/// @brief  Alternates between high and low output on GPIO pin 22 at the specified rate
/// @param rate Delay between blinks in milliseconds
void blink(int rate)
{
    rate = rate ? rate : 1000;
    gpio_init(LED_PIN);              // initialize the LED pin
    gpio_set_dir(LED_PIN, GPIO_OUT); // set the LED pin to output

    // blink the LED
    gpio_put(LED_PIN, 1);
    sleep_ms(rate);
    gpio_put(LED_PIN, 0);
    sleep_ms(rate);
}
