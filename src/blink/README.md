# Blink

## Description

Blink is a simple program that flashes a LED connected to GP 22.

Pin 22 was selected because it does not interfere with SPI, I2C, UART, etc.

## Usage

Usage for this program is pretty straight forward.

The example as written requires an external LED to be attached to GP 22.

A pin out [`can be found here`](https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html)

If you are using a non WiFi Pico you can toggle the on-board LED by uncommenting line 9 in blink.c.

The onboard LED is controlled by the Wi-Fi chip in Wireless models, requires extra configuration, and is beyond the scope of the simple example.

Navigate to `main.c` at the root of the project.

- Import the header file at the top:

  ```c
  #include "src/blink/blink.h"
  ```

- In the `main()` we can call the blink function in the while loop to continuously blink the attached LED

- Requires an amount of time in milliseconds for the on/off delay

  ```c
  // blinks once a second
  blink(1000)
  ```

- Any existing code in main.c can be removed a basic example will look like this:

  ```c
  // import the pi pico std library
  #include "pico/stdlib.h"
  // import our blink file
  #include "src/blink/blink.h"

  void main(){

      // loop forever
      while(true){
          //LED will blink on and off every 1/2 second
          blink(500)
      }
  }
  ```

## Back to Main Docs

[`Back To Main`](../../README.md/#table-of-contents)
