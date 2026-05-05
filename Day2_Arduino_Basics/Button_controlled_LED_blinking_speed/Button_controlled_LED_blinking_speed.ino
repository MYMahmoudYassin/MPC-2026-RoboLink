/*
  Lab 2: Exp2: Control the Blinking of an LED

  Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot
  Board: Arduino Nano ATmega168
  Written by: Mahmoud Yassin, 2026

  What this program does:
  - The LED blinks on and off.
  - Each button press changes the blinking speed.
  - After the fastest speed, the program returns to the slowest speed.

  Wiring:
  - LED positive leg -> D13 through a resistor, if using an external LED
  - LED negative leg -> GND
  - Button one side -> D2
  - Button other side -> GND

  Important button idea:
  This program uses INPUT_PULLUP for the button.
  That means the Arduino reads:
  - HIGH when the button is not pressed
  - LOW when the button is pressed

  Important timing idea:
  This program uses millis() instead of delay().
  This lets the Arduino keep checking the button while the LED is blinking.
*/

// Pin names. Using names makes the code easier to read than using only numbers.
const byte LED_PIN = 13;
const byte BUTTON_PIN = 2;

// Blink times are measured in milliseconds.
// 1000 milliseconds = 1 second.
// Bigger number = slower blink. Smaller number = faster blink.
const unsigned long BLINK_TIMES[] = {
  1000,  // speed 1: slow
  700,   // speed 2
  400,   // speed 3
  200,   // speed 4
  100    // speed 5: fast
};

const byte NUMBER_OF_SPEEDS = sizeof(BLINK_TIMES) / sizeof(BLINK_TIMES[0]);

// This number tells us which speed is being used right now.
// It starts at 0, which means the first speed in BLINK_TIMES.
byte currentSpeedNumber = 0;

// These variables remember the LED state and the last time it changed.
bool ledIsOn = false;
unsigned long lastLedChangeTime = 0;

// These variables help the Arduino read the button cleanly.
// A real button can quickly bounce between HIGH and LOW when pressed.
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastButtonChangeTime = 0;
const unsigned long BUTTON_DEBOUNCE_TIME = 50;

void setup() {
  // Set the LED pin as an output so the Arduino can turn it on and off.
  pinMode(LED_PIN, OUTPUT);

  // Set the button pin as an input with the Arduino's built-in pull-up resistor.
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Start with the LED turned off.
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // millis() gives the number of milliseconds since the Arduino started.
  unsigned long currentTime = millis();

  // Read the button and change the speed if the button was pressed.
  bool buttonReading = digitalRead(BUTTON_PIN);

  // If the reading changed, restart the debounce timer.
  if (buttonReading != lastButtonReading) {
    lastButtonChangeTime = currentTime;
  }

  // If the reading has stayed the same long enough, accept it as stable.
  if (currentTime - lastButtonChangeTime >= BUTTON_DEBOUNCE_TIME) {
    if (buttonReading != stableButtonState) {
      stableButtonState = buttonReading;

      // With INPUT_PULLUP, LOW means the button is pressed.
      if (stableButtonState == LOW) {
        currentSpeedNumber++;

        // If we pass the last speed, go back to the first speed.
        if (currentSpeedNumber >= NUMBER_OF_SPEEDS) {
          currentSpeedNumber = 0;
        }
      }
    }
  }

  // Save this button reading so we can compare it next time loop() runs.
  lastButtonReading = buttonReading;

  // Blink the LED at the selected speed.
  unsigned long selectedBlinkTime = BLINK_TIMES[currentSpeedNumber];

  if (currentTime - lastLedChangeTime >= selectedBlinkTime) {
    lastLedChangeTime = currentTime;

    // Change the LED to the opposite state.
    ledIsOn = !ledIsOn;

    if (ledIsOn) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
