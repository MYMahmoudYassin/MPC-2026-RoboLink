# Day 5: RoboLink Smartphone Control

Day 5 is the final RoboLink project day. Students connect the robot to a BLE module, install the RoboLink Android app, test wireless command bytes, and drive the robot from a smartphone.

## Learning Goals

By the end of Day 5, students should be able to:

- Explain the difference between USB Serial, classic Bluetooth SPP, and BLE communication.
- Wire the BLE module to the Arduino Nano safely.
- Install and prepare the RoboLink Android app.
- Test wireless command bytes before driving the robot.
- Use the same command map for phone control and Serial Monitor testing.
- Drive the robot forward, backward, left, right, and stop from the app.
- Troubleshoot app permissions, BLE connection, UART wiring, and motor response.

## Contents

- [`Lessons/Welcome to the Wireless World .pdf`](Lessons/Welcome%20to%20the%20Wireless%20World%20.pdf)
  Day 5 lesson slides for wireless communication, BLE, and the RoboLink command system.

- [`Labs/Lab5_Part1_Wireless_World.pdf`](Labs/Lab5_Part1_Wireless_World.pdf)
  Lab guide for testing wireless BLE commands between an Android phone and Arduino.

- [`Labs/Lab5_Part1_Wireless_World/Lab5_Part1_Wireless_World.ino`](Labs/Lab5_Part1_Wireless_World/Lab5_Part1_Wireless_World.ino)
  Arduino sketch for checking received BLE commands with the Serial Monitor and built-in LED.

- [`Labs/Lab5_Part2_RoboLink.pdf`](Labs/Lab5_Part2_RoboLink.pdf)
  Lab guide for driving the two-motor robot with the RoboLink Android app.

- [`Labs/Lab5_Part2_RoboLink/Lab5_Part2_RoboLink.ino`](Labs/Lab5_Part2_RoboLink/Lab5_Part2_RoboLink.ino)
  Arduino sketch for full smartphone-controlled robot movement.

- [`Labs/RoboLink APP/Robotak Controller.apk`](Labs/RoboLink%20APP/Robotak%20Controller.apk)
  Android app package used for BLE robot control.

- [`Labs/RoboLink APP/RoboLink_BLE_README.txt`](Labs/RoboLink%20APP/RoboLink_BLE_README.txt)
  Technical notes for the RoboLink BLE app, command map, UUIDs, and troubleshooting.

- [`Labs/AT_test/AT_test.ino`](Labs/AT_test/AT_test.ino)
  Supporting Arduino sketch for checking or configuring the Bluetooth/BLE module.

## Suggested Order

1. Open [`Lessons/Welcome to the Wireless World .pdf`](Lessons/Welcome%20to%20the%20Wireless%20World%20.pdf).
2. Complete [`Labs/Lab5_Part1_Wireless_World.pdf`](Labs/Lab5_Part1_Wireless_World.pdf) using the Part 1 Arduino sketch.
3. Install the RoboLink Android app from the lab link or from [`Labs/RoboLink APP/Robotak Controller.apk`](Labs/RoboLink%20APP/Robotak%20Controller.apk).
4. Confirm that app commands arrive in the Serial Monitor.
5. Complete [`Labs/Lab5_Part2_RoboLink.pdf`](Labs/Lab5_Part2_RoboLink.pdf) using the Part 2 Arduino sketch.
6. Drive the robot through the final class challenge.

## Safety Reminders

- The app is for Android phones only.
- Turn on Bluetooth and Location/GPS before scanning for the robot.
- Allow the required Android permissions, such as Nearby Devices, Bluetooth, and Location.
- Keep the robot wheels lifted during the first wireless motor test.
- Ask your instructor before installing apps or changing Bluetooth module settings.
