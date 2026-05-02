
#include <SoftwareSerial.h>

/*
  Lab 5 - Part 2: RoboLink
  Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot
  Board: Arduino Nano ATmega168
  Written by: Mahmoud Yassin, 2026

  What this sketch does:
    This program lets the RoboLink Android app control the 2-motor robot.

    The app sends one BLE command byte to the Bluetooth/BLE module.
    The Bluetooth/BLE module sends that byte to the Arduino Nano.
    The Arduino reads the byte and controls the L9110 2-channel motor driver.

  RoboLink app command map:
    1 = Stop
    2 = Move forward
    3 = Move backward
    4 = Turn left
    5 = Turn right

  Important app behavior:
    The app uses TouchDown and TouchUp for the direction buttons.
    Example:
      Press Forward  -> app sends 2
      Release Forward -> app sends 1

    This makes the robot stop automatically when the button is released.

  Bluetooth/BLE module wiring:
    BLE module VCC -> Arduino Nano 5V
    BLE module GND -> Arduino Nano GND
    BLE module TXD -> Arduino Nano D10
    BLE module RXD -> Arduino Nano D11 through a voltage divider
    BLE module EN/KEY -> not connected during normal use

    The module used in this lab is a special HC-05-style BLE edition.
    It works with BLE, not classic Bluetooth SPP.

  Phone setup note:
    Make sure Bluetooth and Location/GPS are both turned on.
    Also give the RoboLink app all requested Android permissions for
    connectivity and location, such as Nearby Devices, Bluetooth, and Location.

  L9110 motor driver wiring:
    L9110 A-IA -> Arduino Nano D3
    L9110 A-IB -> Arduino Nano D5
    L9110 B-IA -> Arduino Nano D6
    L9110 B-IB -> Arduino Nano D9
    L9110 GND  -> Arduino GND and motor battery/power supply GND
    L9110 VCC  -> External motor power, usually 2.5V to 12V

    Important:
      Do not power the motors only from the Arduino Nano 5V pin or USB.
      Use an external motor power supply and connect all grounds together.

  Serial settings:
    Computer Serial Monitor: 9600 baud
    BLE module UART:         9600 baud

  Testing:
    Open the Serial Monitor at 9600 baud.
    When the app sends commands, the Arduino prints what it received.

  If the robot moves the wrong way:
    Do not change the app command numbers first.
    Adjust the motor wiring or edit the movement functions at the bottom.

  If the robot does not drive straight:
    DC motors are not perfectly matched. One motor may be naturally slower.
    Use LEFT_MOTOR_SPEED and RIGHT_MOTOR_SPEED below to balance the robot.
*/

// Bluetooth/BLE serial connection.
// Arduino D10 receives data from the module TXD pin.
// Arduino D11 sends data to the module RXD pin through a voltage divider.
const int BT_RX_PIN = 10;
const int BT_TX_PIN = 11;
SoftwareSerial BT(BT_RX_PIN, BT_TX_PIN);

// L9110 motor driver input pins.
const int AIA = 3;  // Motor A input A
const int AIB = 5;  // Motor A input B
const int BIA = 6;  // Motor B input A
const int BIB = 9;  // Motor B input B

// Built-in LED. It is used as a small status indicator.
const int LED_PIN = 13;

// Motor speed uses PWM. 0 = stopped, 255 = full speed.
// Motor A is treated as the left motor. Motor B is treated as the right motor.
//
// If the robot turns left when moving forward, the left motor is too slow:
// increase LEFT_MOTOR_SPEED or decrease RIGHT_MOTOR_SPEED.
//
// If the robot turns right when moving forward, the right motor is too slow:
// increase RIGHT_MOTOR_SPEED or decrease LEFT_MOTOR_SPEED.
const int LEFT_MOTOR_SPEED = 200;
const int RIGHT_MOTOR_SPEED = 200;

// Turning uses a lower speed so the robot is easier to control.
// If the robot does not turn strongly enough, increase this number a little.
const int TURN_SPEED = 140;

// A short pause before moving protects the driver during direction changes.
const int directionChangeDelay = 10;

const long SERIAL_BAUD = 9600;

enum Motion {
  STOPPED,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

Motion currentMotion = STOPPED;

void showHelp();
void handleCommand(byte command);
byte normalizeCommand(byte command);
void stopMotors();
void moveTo(Motion nextMotion);
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();

void setup() {
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  stopMotors();

  Serial.begin(SERIAL_BAUD);
  BT.begin(SERIAL_BAUD);

  showHelp();
}

void loop() {
  // Main path: commands from the RoboLink Android app through the BLE module.
  if (BT.available() > 0) {
    byte command = BT.read();
    command = normalizeCommand(command);

    Serial.print(F("Received RoboLink command: "));
    Serial.println(command);

    handleCommand(command);
  }

  // Optional test path: commands typed directly in the Serial Monitor.
  // This is useful for debugging without the phone app.
  if (Serial.available() > 0) {
    byte command = Serial.read();

    if (command == '\n' || command == '\r') {
      return;
    }

    command = normalizeCommand(command);

    Serial.print(F("Received USB test command: "));
    Serial.println(command);

    handleCommand(command);
  }
}

void showHelp() {
  Serial.println();
  Serial.println(F("Lab 5 - Part 2: RoboLink"));
  Serial.println(F("RoboLink BLE robot control is ready."));
  Serial.println();
  Serial.println(F("App command map:"));
  Serial.println(F("1 = Stop"));
  Serial.println(F("2 = Forward"));
  Serial.println(F("3 = Backward"));
  Serial.println(F("4 = Left"));
  Serial.println(F("5 = Right"));
  Serial.println();
  Serial.println(F("USB test commands also work: 1, 2, 3, 4, 5"));
  Serial.println();
}

void handleCommand(byte command) {
  if (command == 1) {
    stopMotors();
    Serial.println(F("STOP"));
  } else if (command == 2) {
    moveForward();
    Serial.println(F("FORWARD"));
  } else if (command == 3) {
    moveBackward();
    Serial.println(F("BACKWARD"));
  } else if (command == 4) {
    turnLeft();
    Serial.println(F("LEFT"));
  } else if (command == 5) {
    turnRight();
    Serial.println(F("RIGHT"));
  } else {
    Serial.println(F("UNKNOWN COMMAND"));
  }
}

byte normalizeCommand(byte command) {
  // The RoboLink app sends raw bytes: 1, 2, 3, 4, 5.
  if (command >= 1 && command <= 5) {
    return command;
  }

  // The Serial Monitor sends text characters: '1', '2', '3', '4', '5'.
  if (command >= '1' && command <= '5') {
    return command - '0';
  }

  // Letter commands are supported for quick USB testing.
  if (command == 's' || command == 'S') {
    return 1;
  }
  if (command == 'f' || command == 'F') {
    return 2;
  }
  if (command == 'b' || command == 'B') {
    return 3;
  }
  if (command == 'l' || command == 'L') {
    return 4;
  }
  if (command == 'r' || command == 'R') {
    return 5;
  }

  return command;
}

void stopMotors() {
  digitalWrite(AIA, LOW);
  digitalWrite(AIB, LOW);
  digitalWrite(BIA, LOW);
  digitalWrite(BIB, LOW);
  digitalWrite(LED_PIN, LOW);
  currentMotion = STOPPED;
}

void moveTo(Motion nextMotion) {
  if (currentMotion != STOPPED && currentMotion != nextMotion) {
    stopMotors();
    delay(directionChangeDelay);
  }

  digitalWrite(LED_PIN, HIGH);
  currentMotion = nextMotion;
}

void moveForward() {
  moveTo(FORWARD);

  analogWrite(AIA, LEFT_MOTOR_SPEED);
  digitalWrite(AIB, LOW);

  analogWrite(BIA, RIGHT_MOTOR_SPEED);
  digitalWrite(BIB, LOW);
}

void moveBackward() {
  moveTo(BACKWARD);

  digitalWrite(AIA, LOW);
  analogWrite(AIB, LEFT_MOTOR_SPEED);

  digitalWrite(BIA, LOW);
  analogWrite(BIB, RIGHT_MOTOR_SPEED);
}

void turnLeft() {
  moveTo(LEFT);

  digitalWrite(AIA, LOW);
  analogWrite(AIB, TURN_SPEED);

  analogWrite(BIA, TURN_SPEED);
  digitalWrite(BIB, LOW);
}

void turnRight() {
  moveTo(RIGHT);

  analogWrite(AIA, TURN_SPEED);
  digitalWrite(AIB, LOW);

  digitalWrite(BIA, LOW);
  analogWrite(BIB, TURN_SPEED);
}
