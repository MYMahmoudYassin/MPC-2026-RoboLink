# Day 3: Sensors

Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot  
Program: Mini Course Program 2026, Carleton University  
Instructors: Dr. Mahmoud Sayed and Mahmoud Yassin

## Overview

Day 3 introduces sensors. Students learn how an Arduino can read information from the real world and use that information to control outputs or make robot decisions.

This day focuses on two common robot sensors:

- An IR obstacle sensor for detecting nearby objects.
- An ultrasonic distance sensor for measuring distance.

## Learning Goals

By the end of Day 3, students should be able to:

- Explain what a sensor does in a robot system.
- Connect sensor modules to the Arduino Nano ATmega168.
- Read digital sensor values using Arduino code.
- Use sensor input to control an LED or buzzer.
- Use the Serial Monitor to observe sensor readings.
- Troubleshoot sensor wiring, power, ground, and pin problems.
- Describe how sensors help robots respond to their surroundings.

## Files

- `Labs/Lab3_IR_Sensor.pdf`  
  Student lab guide for the IR sensor with buzzer activity.

- `Labs/IR_with_Buzzer/IR_with_Buzzer.ino`  
  Arduino code for the IR sensor, LED, and buzzer circuit.

- `Labs/Lab3_Ultrasonic Sensor.pdf`  
  Student lab guide for the ultrasonic sensor activity.

- `Labs/Ultrasonic/Ultrasonic.ino`  
  Arduino code for the ultrasonic sensor activity.

## Suggested Order

1. Open `Labs/Lab3_IR_Sensor.pdf`.
2. Build the IR sensor with buzzer circuit.
3. Open and upload `Labs/IR_with_Buzzer/IR_with_Buzzer.ino`.
4. Use the Serial Monitor to test the IR sensor.
5. Complete the IR sensor observations and reflection questions.
6. Open `Labs/Lab3_Ultrasonic Sensor.pdf`.
7. Build the ultrasonic sensor circuit.
8. Open and upload `Labs/Ultrasonic/Ultrasonic.ino`.
9. Use the Serial Monitor to observe distance readings.

## Lab 3A: IR Sensor with Buzzer

In this activity, an IR obstacle sensor detects whether an object is nearby. When the sensor detects an object, the Arduino turns on an LED and makes a buzzer sound.

Main Arduino ideas:

- `digitalRead()`
- `if/else`
- `tone()`
- `noTone()`
- Serial Monitor testing

## Lab 3B: Ultrasonic Sensor

In this activity, an ultrasonic sensor sends a sound pulse and measures how long it takes for the echo to return. The Arduino uses that time to estimate distance.

Main Arduino ideas:

- Trigger and echo pins
- `delayMicroseconds()`
- `pulseIn()`
- Distance calculation
- Serial Monitor output

## Key Vocabulary

- Sensor
- Input
- Output
- IR sensor
- Ultrasonic sensor
- Trigger
- Echo
- Distance
- Detection
- Serial Monitor
- `digitalRead()`
- `pulseIn()`
- `if/else`

## Safety Reminders

- Ask your instructor to check wiring before plugging in the Arduino.
- Connect every module GND to Arduino GND.
- Do not connect 5V directly to GND.
- Check each sensor pin label before wiring.
- Disconnect the USB cable before changing a circuit.
- Keep jumper wires neat so mistakes are easier to find.

## Next Step

After Day 3, continue to `Day4_Serial_Monitor_Robot/` to use Arduino input and output ideas for robot control.
