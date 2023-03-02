#include <stdlib.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "src/echoLocation/echo_location.h"
#include "src/blink/blink.h"

void main()
{
	// Initialize port for printf output
	stdio_init_all();

	// Initialize echo location sensor
	init_echo_location();

	// Loop forever
	while (true)
	{
		// check the distance of objects in front of the sensor
		echo_distance = check_distance();

		// If the distance is out of range, blink the LED
		// roughly 2inches to 12inches
		if (echo_distance < 6 || echo_distance > 30) // 30cm
		{
			blink(750);
		}
		else
		{
			// print the distance to the serial monitor
			printf("Distance: %fcm\r\n", echo_distance);
			blink(150);
		}

		sleep_ms(1000);
	}
}
