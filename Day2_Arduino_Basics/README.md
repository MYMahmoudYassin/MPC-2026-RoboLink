# Day 2: Arduino Basics

Day 2 introduces embedded programming with the Arduino IDE. Students upload their first program, learn the structure of an Arduino sketch, and use a push button to control LEDs and a buzzer.

## Learning Goals

By the end of Day 2, students should be able to:

- Open the Arduino IDE and identify the main buttons.
- Select the Arduino Nano board, ATmega168 processor, and correct port.
- Upload the built-in Blink example.
- Explain the difference between `setup()` and `loop()`.
- Use digital output pins to control LEDs and a buzzer.
- Use a push button as a digital input.
- Understand why `INPUT_PULLUP` makes a pressed button read `LOW`.
- Use button presses to change LED and buzzer behavior.

## Contents

- [`Lessons/Programming - Intro.pdf`](Lessons/Programming%20-%20Intro.pdf)
  Introductory programming lesson for C/C++ and embedded code.

- [`Day2_Arduino_World.pdf`](Day2_Arduino_World.pdf)
  Main Day 2 student guide for Arduino setup, Blink, button input, LEDs, and buzzer.

- [`Button_controlled_LED_blinking_speed/Button_controlled_LED_blinking_speed.ino`](Button_controlled_LED_blinking_speed/Button_controlled_LED_blinking_speed.ino)
  Arduino sketch where one push button changes the blinking speed of one LED.

- [`Control_the_Blinking_of_an_LED_and_Buzzer/Control_the_Blinking_of_an_LED_and_Buzzer.ino`](Control_the_Blinking_of_an_LED_and_Buzzer/Control_the_Blinking_of_an_LED_and_Buzzer.ino)
  Arduino sketch where one push button changes the selected LED colour and buzzer speed.

## Suggested Order

1. Open [`Lessons/Programming - Intro.pdf`](Lessons/Programming%20-%20Intro.pdf).
2. Open [`Day2_Arduino_World.pdf`](Day2_Arduino_World.pdf).
3. Set up the Arduino IDE for Arduino Nano and ATmega168.
4. Complete the built-in Blink activity.
5. Upload and test the button-controlled LED blinking sketch.
6. Upload and test the LED and buzzer sketch.
7. Continue to [`../Day3_Sensors/`](../Day3_Sensors/) for sensor input.

## Safety Reminders

- Ask your instructor to check wiring before plugging in the Arduino.
- Use resistors with external LEDs.
- Do not connect 5V directly to GND.
- Disconnect the USB cable before changing a circuit.
