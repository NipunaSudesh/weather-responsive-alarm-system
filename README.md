# Weather-Responsive Alarm System using Arduino

## Project Overview

This project is a weather-responsive alarm system that detects light and rain conditions and displays the status on an LCD display. The system is equipped with:
- An LDR (Light Dependent Resistor) sensor to measure light intensity.
- A raindrop sensor to detect rain.
- A buzzer that sounds an alarm when it’s dark, raining, or both.
- A 16x2 I2C LCD display to show the light and rain conditions.

## Components Used

- Arduino Uno
- LDR Sensor (Light Dependent Resistor)
- Raindrop Sensor
- Buzzer Module
- 16x2 I2C LCD Display
- Breadboard
- Jumper Wires

## Circuit Setup

1. **LDR Sensor Connections:**
   - Connect one end of the LDR to 5V and the other to a 10k ohm resistor connected to GND.
   - Connect the junction of the LDR and the resistor to the analog input pin `A0` on the Arduino.

2. **Raindrop Sensor Connections:**
   - VCC: Connect to the 5V pin.
   - GND: Connect to GND.
   - AO (Analog Output): Connect to analog input pin `A1`.

3. **Buzzer Module Connections:**
   - Positive terminal: Connect to digital pin `7`.
   - Negative terminal: Connect to GND.

4. **16x2 I2C LCD Display Connections:**
   - SDA: Connect to the Arduino’s A4 pin.
   - SCL: Connect to the Arduino’s A5 pin.
   - VCC: Connect to 5V.
   - GND: Connect to GND.

## How It Works

1. The LDR sensor reads light intensity and classifies it as either "Light" or "Dark".
2. The raindrop sensor detects whether it’s raining ("Rain") or dry ("Dry").
3. The LCD display shows the following statuses:
   - **Light Status:** "Intensity: Light" or "Intensity: Dark".
   - **Rain Status:** "Cli: Dry" or "Cli: Rain".
4. If either it is dark or raining (or both), the buzzer will sound an alarm.
