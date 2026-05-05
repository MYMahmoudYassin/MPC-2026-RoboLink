/*
  Lab 2: Exp3: Control the Blinking Speed Using 5 LEDs and a Buzzer

  Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot
  Board: Arduino Nano ATmega168
  Written by: Mahmoud Yassin, 2026

  What this program does:
  - There are 5 LEDs, one LED for each speed.
  - The selected LED blinks on and off.
  - The buzzer beeps at the same time as the selected LED.
  - Each button press changes the blinking speed.
  - After the fastest speed, the program returns to the slowest speed.

  Speed LEDs:
  - Speed 1 slowest -> White LED
  - Speed 2         -> Green LED
  - Speed 3         -> Blue LED
  - Speed 4         -> Yellow LED
  - Speed 5 fastest -> Red LED

  Wiring:
  - White LED positive leg  -> D13 through a resistor
  - Green LED positive leg  -> D12 through a resistor
  - Blue LED positive leg   -> D11 through a resistor
  - Yellow LED positive leg -> D10 through a resistor
  - Red LED positive leg    -> D9 through a resistor
  - All LED negative legs   -> GND

  - Button one side -> D2
  - Button other side -> GND

  - Buzzer S / I/O -> D8
  - Buzzer + / VCC -> 5V
  - Buzzer - / GND -> GND

  Important button idea:
  This program uses INPUT_PULLUP for the button.
  That means the Arduino reads:
  - HIGH when the button is not pressed
  - LOW when the button is pressed

  Important timing idea:
  This program uses millis() instead of delay().
  This lets the Arduino keep checking the button while the LED and buzzer are working.
*/

// Button and buzzer pins
const byte BUTTON_PIN = 2;
const byte BUZZER_PIN = 8;

// LED pins from slowest speed to fastest speed:
// white, green, blue, yellow, red
const byte LED_PINS[] = {
  13,  // speed 1: white LED, slowest
  12,  // speed 2: green LED
  11,  // speed 3: blue LED
  10,  // speed 4: yellow LED
  9    // speed 5: red LED, fastest
};

// Blink times are measured in milliseconds.
// Bigger number = slower blink.
// Smaller number = faster blink.
const unsigned long BLINK_TIMES[] = {
  1000,  // speed 1: slowest
  700,   // speed 2
  400,   // speed 3
  200,   // speed 4
  100    // speed 5: fastest
};

const byte NUMBER_OF_SPEEDS = sizeof(BLINK_TIMES) / sizeof(BLINK_TIMES[0]);

// Buzzer sound frequency in Hz
const unsigned int BUZZER_FREQUENCY = 1000;

// This number tells us which speed is being used right now.
// It starts at 0, which means the first speed.
byte currentSpeedNumber = 0;

// These variables remember the LED/buzzer state and the last time it changed.
bool outputIsOn = false;
unsigned long lastOutputChangeTime = 0;

// Button debounce variables
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastButtonChangeTime = 0;
const unsigned long BUTTON_DEBOUNCE_TIME = 50;

void setup() {
  // Set all LED pins as outputs
  for (byte i = 0; i < NUMBER_OF_SPEEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }

  // Set buzzer pin as output
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);

  // Set button pin as input with internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // millis() gives the number of milliseconds since the Arduino started.
  unsigned long currentTime = millis();

  // ---------------- Button reading with debounce ----------------
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

        // When the speed changes, turn everything off first.
        turnOffAllLeds();
        noTone(BUZZER_PIN);
        outputIsOn = false;
        lastOutputChangeTime = currentTime;
      }
    }
  }

  // Save this button reading so we can compare it next time loop() runs.
  lastButtonReading = buttonReading;

  // ---------------- Blink selected LED and buzzer ----------------
  unsigned long selectedBlinkTime = BLINK_TIMES[currentSpeedNumber];

  if (currentTime - lastOutputChangeTime >= selectedBlinkTime) {
    lastOutputChangeTime = currentTime;

    // Change the selected LED and buzzer to the opposite state.
    outputIsOn = !outputIsOn;

    // Make sure only the LED for the current speed can turn on.
    turnOffAllLeds();

    if (outputIsOn) {
      digitalWrite(LED_PINS[currentSpeedNumber], HIGH);
      tone(BUZZER_PIN, BUZZER_FREQUENCY);
    } else {
      digitalWrite(LED_PINS[currentSpeedNumber], LOW);
      noTone(BUZZER_PIN);
    }
  }
}

// This function turns off all LEDs.
void turnOffAllLeds() {
  for (byte i = 0; i < NUMBER_OF_SPEEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
}
