#include <SoftwareSerial.h>

// Nano D10 = RX from module TX
// Nano D11 = TX to module RX
SoftwareSerial BT(10, 11);

void setup() {
  Serial.begin(9600);    // Arduino Serial Monitor
  BT.begin(38400);       // AT mode baud rate

  Serial.println("AT mode bridge ready");
  Serial.println("Serial Monitor: 9600 baud, Both NL & CR");
  Serial.println("Type AT");
}

void loop() {
  if (Serial.available()) {
    BT.write(Serial.read());
  }

  if (BT.available()) {
    Serial.write(BT.read());
  }
}
