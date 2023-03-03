# Pico Playground &#127827;

## Description

is a development repo for projects using a Raspberry Pi Pico and the C programming language.

## Screenshot

![Comming Soon!](https://images.unsplash.com/photo-1562447208-3d5f81e66179?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1074&q=80)

## Table of Contents

- [`Installation`](#installation)
- [`Usage`](#usage)

## Installation

- Ensure you have the proper tooling installed on your machine:

To install the required tooling visit the official documentation for the required steps.
[`Raspberry Pi Pico - Getting Started Guide`](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) or click on the links below.

- If Linux: [`Go to Chapter 2.2 - The SDK`](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf#%5B%7B%22num%22%3A9%2C%22gen%22%3A0%7D%2C%7B%22name%22%3A%22XYZ%22%7D%2C115%2C841.89%2Cnull%5D)
- If Mac: [`Go to Chapter 9.1 - Building on Apple macOS`](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf#%5B%7B%22num%22%3A41%2C%22gen%22%3A0%7D%2C%7B%22name%22%3A%22XYZ%22%7D%2C115%2C646.89%2Cnull%5D)
- If Windows: [`Go to Chapter - 9.2 Building on MS Windows`](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf#%5B%7B%22num%22%3A43%2C%22gen%22%3A0%7D%2C%7B%22name%22%3A%22XYZ%22%7D%2C115%2C211.6458%2Cnull%5D)

- Clone the project:

```shell
git clone https://github.com/iiTONELOC/pico_playground.git
```

## Usage

This isn't a library, but whatever project you wish to run can be moved to the main.c file's event loop.

Follow the build steps for your required tooling and copy the generated UF2 file from the build folder to the Pi Pico's flash storage.

## Examples

- [`Blink`](./src/blink/README.md#description)
- [`Echo Location`](./src/echoLocation/README.md#description)
