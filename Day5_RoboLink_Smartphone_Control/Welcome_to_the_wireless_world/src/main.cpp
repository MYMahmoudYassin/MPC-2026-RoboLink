#include <Arduino.h>
#include <SoftwareSerial.h>

/*
  Lab 5 - Part 1: Welcome to the Wireless World
  Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot
  Board: Arduino Nano ATmega168

  What this sketch does:
    This program tests wireless communication between a phone Bluetooth/BLE
    terminal app and an Arduino Nano.

    The phone sends a simple command. The Bluetooth/BLE module receives it and
    passes it to the Arduino through SoftwareSerial. The Arduino then prints the
    command to the computer Serial Monitor and turns the built-in LED on or off
    as a simple test output.

  Why this lab matters:
    Before students control the full robot wirelessly, they should first prove
    that the Arduino can receive wireless commands correctly.

  Bluetooth/BLE module wiring:
    Module TXD  -> Arduino Nano D10
    Module RXD  -> Arduino Nano D11 through a voltage divider
    Module GND  -> Arduino Nano GND
    Module VCC  -> Correct module power pin, usually 5V or 3.3V depending on module

    Important:
      Many Bluetooth/BLE RXD pins are 3.3V logic. The Arduino Nano TX pin sends
      5V logic. Use a voltage divider before connecting Arduino D11 to module RXD.

  Phone setup note:
    Make sure Bluetooth and Location/GPS are both turned on. Also give the app
    all requested Android permissions for connectivity and location, such as
    Nearby Devices, Bluetooth, and Location permissions.

  Serial settings:
    Computer Serial Monitor: 9600 baud
    Bluetooth/BLE module:    9600 baud

  Phone app command map:
    1 or S = stop
    2 or F = forward test
    3 or B = backward test
    4 or L = left test
    5 or R = right test
    ?      = show help

  Notes for this test sketch:
    - This sketch does not drive the motors yet.
    - The built-in LED on pin 13 is used as a simple test indicator.
    - After wireless communication works, these functions can be connected to
      the L9110 motor driver movement code.
*/

// SoftwareSerial creates a second serial port on regular digital pins.
// Format: SoftwareSerial name(Arduino_RX_pin, Arduino_TX_pin)
//
// Arduino RX receives from the Bluetooth/BLE TXD pin.
// Arduino TX sends to the Bluetooth/BLE RXD pin.
const int BT_RX_PIN = 10;
const int BT_TX_PIN = 11;
SoftwareSerial bluetooth(BT_RX_PIN, BT_TX_PIN);

// The Arduino Nano built-in LED is connected to digital pin 13.
const int LED_PIN = 13;

// Both the Serial Monitor and the Bluetooth/BLE module use 9600 baud.
const long SERIAL_BAUD = 9600;

// Function declarations.
// PlatformIO uses standard C++, so functions must be declared before loop()
// if their definitions appear later in the file.
void showHelp();
void handleCommand(char command);
char normalizeCommand(char command);
void stopRobot();
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(SERIAL_BAUD);
  bluetooth.begin(SERIAL_BAUD);

  showHelp();
}

void loop() {
  // Check if the Bluetooth/BLE module received a character from the phone.
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();

    // Ignore Enter/newline characters. Some phone apps send these after a command.
    if (command == '\n' || command == '\r') {
      return;
    }

    command = normalizeCommand(command);

    Serial.print("Received wireless command: ");
    Serial.println(command);

    handleCommand(command);
  }

  // Optional: also allow commands from the computer Serial Monitor.
  // This helps with testing even when the phone is not connected.
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '\n' || command == '\r') {
      return;
    }

    command = normalizeCommand(command);

    Serial.print("Received USB command: ");
    Serial.println(command);

    handleCommand(command);
  }
}

void showHelp() {
  Serial.println();
  Serial.println("Lab 5 - Part 1: Welcome to the Wireless World");
  Serial.println("Bluetooth/BLE command test is ready.");
  Serial.println();
  Serial.println("Send one command from the phone app:");
  Serial.println("1 or S = stop");
  Serial.println("2 or F = forward test");
  Serial.println("3 or B = backward test");
  Serial.println("4 or L = left test");
  Serial.println("5 or R = right test");
  Serial.println("?      = help");
  Serial.println();
}

void handleCommand(char command) {
  if (command == '1' || command == 'S') {
    stopRobot();
  } else if (command == '2' || command == 'F') {
    moveForward();
  } else if (command == '3' || command == 'B') {
    moveBackward();
  } else if (command == '4' || command == 'L') {
    turnLeft();
  } else if (command == '5' || command == 'R') {
    turnRight();
  } else if (command == '?') {
    showHelp();
  } else {
    Serial.println("Unknown command. Send ? for help.");
  }
}

char normalizeCommand(char command) {
  // Some apps send raw byte values 1, 2, 3, 4, 5 instead of text characters
  // '1', '2', '3', '4', '5'. This converts raw bytes into text digits.
  if (command >= 1 && command <= 5) {
    command = command + '0';
  }

  // Make lowercase letters behave like uppercase letters.
  if (command >= 'a' && command <= 'z') {
    command = command - 32;
  }

  return command;
}

void stopRobot() {
  digitalWrite(LED_PIN, LOW);
  Serial.println("STOP test: LED OFF");
}

void moveForward() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("FORWARD test: LED ON");
}

void moveBackward() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("BACKWARD test: LED ON");
}

void turnLeft() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LEFT test: LED ON");
}

void turnRight() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("RIGHT test: LED ON");
}
