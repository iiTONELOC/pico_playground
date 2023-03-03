#include <stdlib.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "src/echoLocation/echo_location.h"
#include "src/blink/blink.h"

void main()
{
	// Initialize  for printf output
	stdio_init_all();

	// Initialize echo location sensor
	init_echo_location();

	// Loop forever
	while (true)
	{
		// check the distance of objects in front of the sensor
		echo_distance = check_distance();

		// If the distance is out of range, blink the LED
		if (echo_distance > 2 && echo_distance < 400)
		{
			// print the distance to the serial monitor
			printf("Distance: %lldcm\r\n", (long long)echo_distance);
			blink(75);
		}
		else
		{
			blink(750);
		}

		sleep_ms(1000);
	}
}
