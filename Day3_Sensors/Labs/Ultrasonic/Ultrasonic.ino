void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // The trigger pin.
  pinMode(3, INPUT);  // The echo pin.

  // Intitalize the Serial transmitter
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Send out the trigger signal
  digitalWrite(2, HIGH);

  //Wait for 10 microseconds
  delayMicroseconds(50);

  //Lower the trigger pin
  digitalWrite(2, LOW);

  //Measure the distance (The time at which the echo signal is HIGH)
  unsigned long int distance_in_time = pulseIn(3, HIGH);

  //Convert time to distance
  // Divide by 2 becuase of the round-trip
  // Divide by   10,000 to convert from micrometers to centimeters (the time is measured originally in microseonds)
  // We are converting to float to get more resolution.
  float distance_in_cm = 343 * distance_in_time /(2*10000.0);

  Serial.print("Distance: ");
  Serial.println(distance_in_cm);

  delay(500);
}
