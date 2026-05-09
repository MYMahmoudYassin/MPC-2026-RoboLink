# Day 3: Sensors

Day 3 introduces sensors and shows how a robot can read information from the real world. Students use an IR obstacle sensor for object detection and an ultrasonic sensor for distance measurement.

## Learning Goals

By the end of Day 3, students should be able to:

- Explain what a sensor does in a robot system.
- Connect sensor modules to the Arduino Nano ATmega168.
- Read digital sensor values using Arduino code.
- Use sensor input to control an LED or buzzer.
- Use the Serial Monitor to observe sensor readings.
- Troubleshoot sensor wiring, power, ground, and pin problems.
- Describe how sensors help robots respond to their surroundings.

## Contents

- [`Lessons/Sensors.pdf`](Lessons/Sensors.pdf)
  Main Day 3 lesson for sensor concepts and robot sensing.

- [`Labs/Lab3_IR_Sensor.pdf`](Labs/Lab3_IR_Sensor.pdf)
  Student lab guide for the IR obstacle sensor activity.

- [`Labs/IR_with_Buzzer/IR_with_Buzzer.ino`](Labs/IR_with_Buzzer/IR_with_Buzzer.ino)
  Arduino sketch for the IR sensor, LED, and buzzer circuit.

- [`Labs/Lab3_Ultrasonic Sensor.pdf`](Labs/Lab3_Ultrasonic%20Sensor.pdf)
  Student lab guide for the ultrasonic distance sensor activity.

- [`Labs/Ultrasonic/Ultrasonic.ino`](Labs/Ultrasonic/Ultrasonic.ino)
  Arduino sketch for reading distance from the ultrasonic sensor.

## Suggested Order

1. Open [`Lessons/Sensors.pdf`](Lessons/Sensors.pdf).
2. Build and test the IR sensor circuit using [`Labs/Lab3_IR_Sensor.pdf`](Labs/Lab3_IR_Sensor.pdf).
3. Upload [`Labs/IR_with_Buzzer/IR_with_Buzzer.ino`](Labs/IR_with_Buzzer/IR_with_Buzzer.ino).
4. Build and test the ultrasonic sensor circuit using [`Labs/Lab3_Ultrasonic Sensor.pdf`](Labs/Lab3_Ultrasonic%20Sensor.pdf).
5. Upload [`Labs/Ultrasonic/Ultrasonic.ino`](Labs/Ultrasonic/Ultrasonic.ino).
6. Continue to [`../Day4_Serial_Monitor_Robot/`](../Day4_Serial_Monitor_Robot/) for motor control.

## Safety Reminders

- Ask your instructor to check wiring before plugging in the Arduino.
- Connect every module GND to Arduino GND.
- Do not connect 5V directly to GND.
- Check each sensor pin label before wiring.
