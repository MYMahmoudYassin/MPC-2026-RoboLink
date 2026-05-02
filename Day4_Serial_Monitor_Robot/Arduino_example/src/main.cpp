#include <Arduino.h>

/*
  Lab Experiment: Serial Monitor Robot Control
  Written by: Mahmoud Yassin

  Description:
    In this lab, students test a simple 2-motor robot from the Arduino
    Serial Monitor. The robot uses an Arduino Nano, an L9110 2-channel
    motor driver, and two DC motors.

    The computer sends one letter to the Arduino through the USB cable.
    The Arduino reads the letter and controls the L9110 motor driver.
    The motor driver then controls the direction and speed of the motors.

  Learning Goals:
    1. Use the Serial Monitor to send commands to an Arduino.
    2. Control two DC motors using an L9110 2-channel motor driver.
    3. Understand simple robot movements: forward, backward, left, right, stop.
    4. Use PWM values from 0 to 255 to control motor speed.

  Materials:
    - Arduino Nano
    - L9110 2-channel motor driver
    - Two DC motors
    - External battery or power supply for the motors
    - USB cable
    - Jumper wires

  Wiring:
    L9110 A-IA -> Arduino Nano D3
    L9110 A-IB -> Arduino Nano D5
    L9110 B-IA -> Arduino Nano D6
    L9110 B-IB -> Arduino Nano D9
    L9110 GND  -> Arduino Nano GND and battery/power supply GND
    L9110 VCC  -> External motor power, usually 2.5V to 12V

    Important:
      The Arduino GND and motor battery GND must be connected together.
      Do not power the motors only from the Arduino Nano 5V pin or USB.

  Arduino IDE Setup:
    Board: Arduino Nano
    Baud rate: 9600
    Serial Monitor line ending: any setting is okay

  Serial Monitor Commands:
    F = forward
    B = backward
    L = turn left
    R = turn right
    S = stop
    + = faster
    - = slower
    ? = show help

  How The Code Is Organized:
    setup()
      Runs once. It sets the motor pins as outputs, stops the motors,
      starts Serial communication, and prints the help menu.

    loop()
      Runs again and again. It checks the Serial Monitor for a command.
      When a command arrives, it calls the correct movement function.

    forward(), backward(), turnLeft(), turnRight()
      These functions tell the L9110 which direction each motor should spin.

    stopMotors()
      Turns off all motor driver inputs.

    faster(), slower()
      Change the PWM speed value. 0 means stopped. 255 means full speed.

  Note:
    The robot stops for 400 ms before every new movement. This short pause
    makes the L9110 driver change direction reliably.
*/

// Connect the L9110 motor driver input pins to these Arduino Nano pins.
const int AIA = 3;  // Motor A input A
const int AIB = 5;  // Motor A input B
const int BIA = 6;  // Motor B input A
const int BIB = 9;  // Motor B input B

// Motor speed uses PWM. 0 = stopped, 255 = full speed.
int motorSpeed = 200;

// The robot stops briefly before each new movement.
// This protects the motor driver and makes direction changes reliable.
const int directionChangeDelay = 400;

void stopMotors() {
  digitalWrite(AIA, LOW);
  digitalWrite(AIB, LOW);
  digitalWrite(BIA, LOW);
  digitalWrite(BIB, LOW);
}

void pauseBeforeMoving() {
  stopMotors();
  delay(directionChangeDelay);
}

void forward() {
  pauseBeforeMoving();

  analogWrite(AIA, motorSpeed);
  digitalWrite(AIB, LOW);

  analogWrite(BIA, motorSpeed);
  digitalWrite(BIB, LOW);
}

void backward() {
  pauseBeforeMoving();

  digitalWrite(AIA, LOW);
  analogWrite(AIB, motorSpeed);

  digitalWrite(BIA, LOW);
  analogWrite(BIB, motorSpeed);
}

void turnLeft() {
  pauseBeforeMoving();

  digitalWrite(AIA, LOW);
  analogWrite(AIB, motorSpeed);

  analogWrite(BIA, motorSpeed);
  digitalWrite(BIB, LOW);
}

void turnRight() {
  pauseBeforeMoving();

  analogWrite(AIA, motorSpeed);
  digitalWrite(AIB, LOW);

  digitalWrite(BIA, LOW);
  analogWrite(BIB, motorSpeed);
}

void faster() {
  motorSpeed = motorSpeed + 25;

  if (motorSpeed > 255) {
    motorSpeed = 255;
  }

  Serial.print("Speed: ");
  Serial.println(motorSpeed);
}

void slower() {
  motorSpeed = motorSpeed - 25;

  if (motorSpeed < 0) {
    motorSpeed = 0;
  }

  Serial.print("Speed: ");
  Serial.println(motorSpeed);
}

void showHelp() {
  Serial.println();
  Serial.println("Hi! Welcome to the RoboLink Serial Monitor Robot Control Lab.");
  Serial.println("RoboLink: Serial Monitor Robot Control");
  Serial.println("F = forward");
  Serial.println("B = backward");
  Serial.println("L = left");
  Serial.println("R = right");
  Serial.println("S = stop");
  Serial.println("+ = faster");
  Serial.println("- = slower");
  Serial.println("? = help");
  Serial.print("Current speed: ");
  Serial.println(motorSpeed);
  Serial.println();
}

void setup() {
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  stopMotors();

  Serial.begin(9600);
  showHelp();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Ignore Enter/newline characters from the Serial Monitor.
    if (command == '\n' || command == '\r') {
      return;
    }

    // Make lowercase letters behave like uppercase letters.
    if (command >= 'a' && command <= 'z') {
      command = command - 32;
    }

    if (command == 'F') {
      forward();
      Serial.println("Forward");
    } else if (command == 'B') {
      backward();
      Serial.println("Backward");
    } else if (command == 'L') {
      turnLeft();
      Serial.println("Left");
    } else if (command == 'R') {
      turnRight();
      Serial.println("Right");
    } else if (command == 'S') {
      stopMotors();
      Serial.println("Stop");
    } else if (command == '+') {
      faster();
    } else if (command == '-') {
      slower();
    } else if (command == '?') {
      showHelp();
    } else {
      Serial.println("Unknown command. Send ? for help.");
    }
  }
}
