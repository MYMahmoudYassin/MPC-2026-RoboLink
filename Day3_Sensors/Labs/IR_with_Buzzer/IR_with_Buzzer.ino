/*
  Lab 3: IR Sensor with Buzzer

  Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot
  Board: Arduino Nano ATmega168
  Written by: Mahmoud Yassin, 2026

  What this program does:
  - The Arduino reads an IR obstacle sensor.
  - If the IR sensor detects an object, the LED turns on and the buzzer makes sound.
  - If the IR sensor does not detect an object, the LED and buzzer turn off.

  Wiring:
  - IR sensor OUT pin -> D2
  - IR sensor VCC pin -> 5V
  - IR sensor GND pin -> GND
  - Buzzer signal pin -> D8
  - Buzzer VCC pin -> 5V
  - Buzzer GND pin -> GND
  - LED positive leg -> D13 through a resistor, if using an external LED
  - LED negative leg -> GND

  Important IR sensor idea:
  Many IR sensor modules read LOW when an object is detected.
  If your sensor works the opposite way, change LOW to HIGH in the if statement.
*/

const byte IR_SENSOR_PIN = 2;                 // D2 reads the digital signal from the IR sensor.
const byte BUZZER_PIN = 8;                    // D8 sends the sound signal to the buzzer.
const byte LED_PIN = 13;                      // D13 controls the LED.
const unsigned int BUZZER_FREQUENCY = 1000;   // 1000 Hz is the pitch of the buzzer sound.

int sensorStatus = HIGH;                      // This variable stores the sensor reading.

void setup() {                                // setup() runs one time when the Arduino starts.
  Serial.begin(9600);                         // Start the Serial Monitor at 9600 bits per second.
  pinMode(IR_SENSOR_PIN, INPUT);              // Set the IR sensor pin as an input.
  pinMode(BUZZER_PIN, OUTPUT);                // Set the buzzer pin as an output.
  pinMode(LED_PIN, OUTPUT);                   // Set the LED pin as an output.
  digitalWrite(LED_PIN, LOW);                 // Start with the LED turned off.
  noTone(BUZZER_PIN);                         // Start with the buzzer turned off.
}                                             // End of setup().

void loop() {                                 // loop() runs again and again.
  sensorStatus = digitalRead(IR_SENSOR_PIN);  // Read the IR sensor and save the result.
  Serial.println(sensorStatus);               // Print 0 or 1 so we can test the sensor in Serial Monitor.

  if (sensorStatus == LOW) {                  // LOW usually means the IR sensor detects an object.
    digitalWrite(LED_PIN, HIGH);              // Turn on the LED.
    tone(BUZZER_PIN, BUZZER_FREQUENCY);       // Turn on the buzzer at the chosen frequency.
    delay(1000);                              // Keep the LED and buzzer on for 1 second.
  } else {                                    // Otherwise, no object is detected.
    digitalWrite(LED_PIN, LOW);               // Turn off the LED.
    noTone(BUZZER_PIN);                       // Turn off the buzzer.
  }                                           // End of the if/else decision.
}                                             // End of loop().
