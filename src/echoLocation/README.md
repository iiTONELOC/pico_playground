# Echo Location

## Description

This Example uses a Keys Studio HC-SR04 ultrasonic sensor to detect obstacles.
Working code for an Arduino sketch is provided by their documentation if you want to use Arduino. The issue I found when transferring straight to C was that their provided code uses an Arduino IDE specific pulseIn helper function to measure the pulse.

Knowing nothing, I found a description Arduino's documentation for the function: [`pulseLn()`](https://reference.arduino.cc/reference/cs/language/functions/advanced-io/pulsein/)
and did my best to replicate a basic version of it.

### pulseIn()

```c
unsigned long pulseIn(uint pin, uint state)
{
    unsigned long width = 0; // keep initialization out of time critical area

    // wait for any previous pulse to end
    while (gpio_get(pin) == state)
        ;
    // wait for the pulse to start
    while (gpio_get(pin) != state)
        ;
    // wait for the pulse to stop
    while (gpio_get(pin) == state)
    {
        width++;
    }

    // convert the reading to microseconds based off the speed of the clock
    return width / 12.5;
}
```

Once implemented, the algorithms instructions from Keys Studio were replicated,

**_note_** that these instructions were copied verbatim from the [`Keys Studio Docs`](<https://wiki.keyestudio.com/KS3023(3023F)_Keyestudio_Raspberry_Pi_Pico_37_in_1_Sensor_Kit>) - Project 30: Ultrasonic Sensor

```md
1. First pull down the TRIG, and then trigger it with at least 10us high level
   signal;

2. After triggering, the module will automatically transmit eight 40KHZ
   square waves, and automatically detect whether there is a signal to return.

3. If there is a signal returned back, through the ECHO to output a high
   level, the duration time of high level is actually the time from emission to
   reception of ultrasonic.

Test distance = high level duration _ 340m/s _ 0.5
```

My solution calculates the distance differently but seems accurate:

```c
    float check_distance()
    {
        // wite out to trig pin for 2 microseconds at a low level to clear the sensor
        gpio_put(TRIG_PIN, 0);
        sleep_us(2);

        // write out to trig pin for 10 microseconds at a high level to trigger the sensor
        gpio_put(TRIG_PIN, 1);
        sleep_us(10);

        // set the trig pin back to low
        gpio_put(TRIG_PIN, 0);

        // read the echo pin to get the pulse width
        // we take the pulse width and divide it by 2 because
        // the pulse goes out and back
        float pulse_width = pulseIn(ECHO_PIN, 1) / 2;

         // 58 is the number of microseconds it takes for sound to travel 1cm
        float _distance_cm = pulse_width / 58;

        return _distance_cm;
    }
```

## Usage

The following shows an example program that measures the distance and logs it over serial
if the distance falls in the 2-400cm range, which is the guaranteed accuracy range of the sensor, anything outside of this gives wildly inaccurate readings.

Example output:

```shell
Distance: 12cm
```

Example main.c :

```c
    #include <stdlib.h>
    #include <stdio.h>
    #include "pico/stdlib.h"
    #include "src/echoLocation/echo_location.h"

    void main()
    {
        // Initialize for printf output
        stdio_init_all();

        // Initialize echo location sensor
        init_echo_location();

        // Loop forever
        while (true)
        {
            // check the distance of objects in front of the sensor
            echo_distance = check_distance();

            // If the distance is in range, roughly 2cm to 400cm
            if (echo_distance > 2 && echo_distance < 400)
            {
                // print the distance to the serial monitor
                printf("Distance: %lldcm\r\n", (long long)echo_distance);
            }

            // take a reading every half second
            sleep_ms(500);
        }
    }

```

## Back to Main Docs

[`Back To Main`](../../README.md/#table-of-contents)
