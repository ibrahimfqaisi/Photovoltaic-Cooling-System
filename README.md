# Photovoltaic-Cooling-System

## Overview

Provide a brief description of your Arduino project. What does it do? What problem does it solve?

## Table of Contents

- [Graduation Project Details](#graduation-project-details)
- [Features](#features)
- [Requirements](#requirements)
- [Setup](#setup)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)


## Graduation Project Details

This project was prepared by the following team members:

- Ibrahim Adnan Ghaleb Fqaisi
- Barham Jeries Barham Farraj
- Mohannad Mohammad Saeed Ghabboun
- Abd Al Rahman Mohammad Mustafa Issa
- Abd Al Kareem Ibrahim Abd Al Rahman Habahbeh
- Mohammad Mustafa Mohammad Al Horani

It was supervised by Prof. Omar Othman Badran.



### Project PDF

Download the detailed project documentation in [PDF format](/Graduation%20Project%20Details.pdf).

## Features

List the main features of your Arduino project.

## Requirements

Specify the hardware and software requirements to run your project.

### Components:

1. **Arduino Board:** Any Arduino board (e.g., Arduino Uno, Arduino Mega).
2. **DS3231 RTC Module:** Real-Time Clock module for accurate timekeeping.
3. **SD Card Module:** Module for interfacing with an SD card for data storage.
4. **ACS712 Current Sensors:** Current sensors for measuring current in different circuits.
5. **Temperature Sensors (DS18B20):** One-wire digital temperature sensors.

### Libraries:

1. **Wire.h:** Standard Arduino library for I2C communication.
2. **RTClib:** Library for interfacing with DS3231 RTC module. You can find it [here](https://github.com/adafruit/RTClib).
3. **OneWire.h:** Library for OneWire communication protocol. It is often used with DallasTemperature library. You can find it [here](https://github.com/PaulStoffregen/OneWire).
4. **DallasTemperature.h:** Library for interfacing with Dallas Semiconductor temperature sensors. You can find it [here](https://github.com/milesburton/Arduino-Temperature-Control-Library).
5. **SPI.h:** Standard Arduino library for SPI communication.
6. **SD.h:** Library for reading and writing to SD cards. It is included with the Arduino IDE.

## Setup

Explain the steps to set up the project:

1. **Hardware Setup:** Describe how to connect the sensors and other hardware components.
2. **Software Setup:** Explain how to install any necessary libraries, and mention the Arduino IDE or VS Code setup.

## Usage

Provide instructions on how to use your Arduino project.

1. **Uploading Code:** Explain how to upload the code to the Arduino board.
2. **Interpreting Output:** Describe how to interpret the output, especially if there are LEDs, displays, or serial output.

## Dependencies

List any external libraries or tools that your project depends on.

- [RTClib](https://github.com/adafruit/RTClib)
- [OneWire](https://github.com/PaulStoffregen/OneWire)
- [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
- [SD](https://www.arduino.cc/en/Reference/SD)

## Contributing

If you'd like to contribute to this project, please follow these guidelines.

- Fork the repository.
- Create a new branch.
- Make your changes.
- Test your changes.
- Submit a pull request.

