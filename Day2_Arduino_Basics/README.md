# Day 2: Arduino Basics

Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot  
Program: Mini Course Program 2026, Carleton University  
Instructors: Dr. Mahmoud Sayed and Mahmoud Yassin

## Overview

Day 2 introduces Arduino World. Students use the Arduino IDE for the first time, upload the built-in Blink example, and then control LEDs and a buzzer using a push button.

This day is designed for students who are new to Arduino programming.

## Learning Goals

By the end of Day 2, students should be able to:

- Open the Arduino IDE and identify the main buttons.
- Select the Arduino Nano board, ATmega168 processor, and correct port.
- Upload the built-in Blink example.
- Explain the difference between `setup()` and `loop()`.
- Use digital output pins to control LEDs.
- Use a push button as a digital input.
- Understand why `INPUT_PULLUP` makes a pressed button read `LOW`.
- Use button presses to change LED blinking speed.
- Add multiple LED colours and a buzzer to a simple Arduino project.

## Files

- `Day2_Arduino_World.pdf`  
  Main student lab guide for Lab 2: Arduino World.

- `Button_controlled_LED_blinking_speed/Button_controlled_LED_blinking_speed.ino`  
  Experiment 2 code. One push button changes the blinking speed of one LED.

- `Control_the_Blinking_of_an_LED_and_Buzzer/Control_the_Blinking_of_an_LED_and_Buzzer.ino`  
  Experiment 3 code. One push button changes the selected LED colour and buzzer speed.

## Suggested Order

1. Open `Day2_Arduino_World.pdf`.
2. Set up the Arduino IDE.
3. Select `Arduino Nano` as the board.
4. Select `ATmega168` as the processor.
5. Select the correct port.
6. Complete Experiment 1 using `File > Examples > 01.Basics > Blink`.
7. Open and upload the Experiment 2 sketch.
8. Build and test the push button LED blinking circuit.
9. Open and upload the Experiment 3 sketch.
10. Build and test the multiple LED colours and buzzer circuit.

## Experiments

### Experiment 1: Built-In Blink

Students use the Arduino IDE example menu to upload the built-in Blink sketch. This confirms that the Arduino board, USB cable, port, and upload settings are working.

### Experiment 2: Push Button LED Blinking Speed

Students use one push button to move through five blinking speeds. The code uses `millis()` so the Arduino can keep checking the button while the LED is blinking.

### Experiment 3: Multiple LED Colours and Buzzer

Students use one push button to choose between five LED colours. The selected LED blinks, and the buzzer beeps at the same speed.

## Key Vocabulary

- Arduino IDE
- Sketch
- Upload
- Verify
- Board
- Port
- Pin
- `setup()`
- `loop()`
- `digitalWrite()`
- `digitalRead()`
- `INPUT_PULLUP`
- `millis()`
- Buzzer

## Safety Reminders

- Ask your instructor to check wiring before plugging in the Arduino.
- Use resistors with external LEDs.
- Do not connect 5V directly to GND.
- Disconnect the USB cable before changing a circuit.
- Check LED direction before testing.
- Keep jumper wires neat so mistakes are easier to find.

## Next Step

After Day 2, continue to `Day3_Sensors/` to start using sensors with the Arduino.
