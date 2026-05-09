/*
  Lab 4 Part 1: How to Write and Use Functions

  Course: RoboLink: Build and Drive Your Smartphone-Controlled Robot
  Board: Arduino Nano ATmega168
  Written by: Mahmoud Yassin, 2026

  Program Description:
  --------------------
  This program calculates the area of a circle using a user-defined function.

  The user enters the radius of the circle through the Serial Monitor.
  The Arduino reads the radius, sends it to the CircleArea() function,
  calculates the area, and prints the result on the Serial Monitor.

  Formula:
  --------
  Area = π × r × r

  In this program, π is approximated as 3.14.

  Main Concepts:
  --------------
  1. How to write a function.
  2. How to pass a value to a function.
  3. How to return a value from a function.
  4. How to read input from the Serial Monitor.
  5. How to display output on the Serial Monitor.
*/


// This function calculates the area of a circle.
// Input:  r, which represents the radius of the circle.
// Output: The calculated area of the circle.
float CircleArea(float r)
{
  float Area;              // Variable used to store the calculated area

  Area = 3.14 * r * r;     // Calculate the area using Area = π × r × r

  return Area;             // Return the calculated area to the main program
}


// Global variables
float radius = 0;          // Stores the radius entered by the user
float A = 0;               // Stores the calculated area
String input;              // Stores the text entered in the Serial Monitor


void setup() {
  // Start serial communication between the Arduino and the computer.
  // The baud rate must match the baud rate selected in the Serial Monitor.
  Serial.begin(9600);

  // Print the program title and instructions once when the Arduino starts.
  Serial.println("Circle Area Calculator");
  Serial.println("----------------------");
  Serial.println("Enter the radius, then press Enter:");
}


void loop() {
  // Check if the user has entered data in the Serial Monitor.
  if (Serial.available() > 0) {

    // Read the user input until the Enter key is pressed.
    input = Serial.readStringUntil('\n');

    // Convert the input text into a floating-point number.
    radius = input.toFloat();

    // Call the CircleArea() function and store the returned value in A.
    A = CircleArea(radius);

    // Print the calculated area on the Serial Monitor.
    Serial.print("\n");
    Serial.print("Area = ");
    Serial.print(A);
    Serial.print("\n");

    // Ask the user to enter another radius.
    Serial.print("Enter the radius: ");
  }
}
