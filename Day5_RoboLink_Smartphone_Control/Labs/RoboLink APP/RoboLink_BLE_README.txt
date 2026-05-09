README - RoboLink App BLE Robot Controller

App name
--------
RoboLink app

Purpose
-------
RoboLink is an MIT App Inventor app used to control a small Arduino-based robot using BLE Bluetooth.

The app is designed for children. A child can scan for nearby robots, choose the correct robot from the list, and control it using simple direction buttons.

This version only includes the basic robot movement controls:
- Forward
- Backward
- Left
- Right
- Stop

The following old functions are not included in this version:
- Fan ON
- Fan OFF
- Lift UP
- Lift DOWN
- Maze mode

Important note
--------------
This app uses BLE Bluetooth, not Bluetooth Classic.

The old app used BluetoothClient and Send1ByteNumber, which are for Bluetooth Classic / SPP modules.
The RoboLink app uses the BluetoothLE extension and writes bytes to a BLE characteristic.

BLE UUIDs used by RoboLink
--------------------------
Service UUID:
0000FFE0-0000-1000-8000-00805F9B34FB

Characteristic UUID:
0000FFE1-0000-1000-8000-00805F9B34FB

These UUIDs were found using nRF Connect:
- Service: 0xFFE0
- Characteristic: 0xFFE1
- Characteristic properties: NOTIFY, WRITE

MIT App Inventor global variables
---------------------------------
Create these two global variables in the Blocks screen:

initialize global SERVICE_UUID to:
0000FFE0-0000-1000-8000-00805F9B34FB

initialize global CHAR_UUID to:
0000FFE1-0000-1000-8000-00805F9B34FB

Main MIT App Inventor components
--------------------------------
Visible components:
- Scan_Button
  Text: Scan Robots

- Robot_List
  Used to show nearby BLE robots

- Status_Label
  Used to show connection and command status

- Disconnect_Button
  Text: Disconnect

Robot control buttons:
- Forward
- Backward
- Left
- Right
- Stop

Non-visible component:
- BluetoothLE1

Scanning logic
--------------
When Scan_Button.Click:
1. Set Status_Label.Text to "Scanning..."
2. Set Robot_List.ElementsFromString to ""
3. Call BluetoothLE1.StartScanning

When BluetoothLE1.DeviceFound:
1. Set Robot_List.ElementsFromString to BluetoothLE1.DeviceList

Connection logic
----------------
When Robot_List.AfterPicking:
1. Call BluetoothLE1.StopScanning
2. Set Status_Label.Text to join "Connecting to " Robot_List.Selection
3. Call BluetoothLE1.Connect with index Robot_List.SelectionIndex

When BluetoothLE1.Connected:
1. Set Status_Label.Text to "Connected"

When BluetoothLE1.ConnectionFailed:
1. Set Status_Label.Text to join "Connection failed: " reason

When BluetoothLE1.Disconnected:
1. Set Status_Label.Text to "Disconnected"

When Disconnect_Button.Click:
1. Call BluetoothLE1.Disconnect
2. Set Status_Label.Text to "Disconnected"

SendCommand procedure
---------------------
Create a procedure named SendCommand with one input:

cmd

Inside the procedure:

1. Call BluetoothLE1.WriteBytesWithResponse
   serviceUuid = get global SERVICE_UUID
   characteristicUuid = get global CHAR_UUID
   signed = false
   values = make a list get cmd

2. Set Status_Label.Text to join "Sent command: " get cmd

Important:
The "values" input must use:
make a list get cmd

Do not use:
make new sorted list from get cmd

Using the sorted-list block can cause this error:
Bad arguments to sort

RoboLink command mapping
------------------------
The RoboLink app sends one raw byte for each command.

Command number | Hex byte | Meaning in Arduino code
---------------|----------|-------------------------
1              | 0x01     | Stop
2              | 0x02     | Move Forward
3              | 0x03     | Move Backward
4              | 0x04     | Turn Left
5              | 0x05     | Turn Right

This mapping is very important. The Arduino code must use the same numbers.

Button mapping in the RoboLink app
----------------------------------
Forward.TouchDown:
SendCommand 2

Forward.TouchUp:
SendCommand 1

Backward.TouchDown:
SendCommand 3

Backward.TouchUp:
SendCommand 1

Left.TouchDown:
SendCommand 4

Left.TouchUp:
SendCommand 1

Right.TouchDown:
SendCommand 5

Right.TouchUp:
SendCommand 1

Stop.Click:
SendCommand 1

Why TouchUp sends Stop
----------------------
The direction buttons use TouchDown and TouchUp.

Example:
- When the child presses Forward, the app sends command 2.
- When the child releases Forward, the app sends command 1.

This makes the robot stop automatically when the button is released. This is safer and easier for children.

Arduino wiring
--------------
BLE module VCC  -> Arduino Nano 5V
BLE module GND  -> Arduino Nano GND
BLE module TXD  -> Arduino Nano D10
BLE module RXD  -> Arduino Nano D11 through a voltage divider
BLE module EN/KEY -> disconnected during normal use

Important:
The working UART speed found during testing is 9600 baud.

Use this in the Arduino code:
BT.begin(9600);

Basic Arduino test code
-----------------------
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("RoboLink BLE robot command test ready");
}

void loop() {
  if (BT.available()) {
    byte cmd = BT.read();

    Serial.print("Received command: ");
    Serial.println(cmd);

    if (cmd == 1) {
      stopMotors();
      Serial.println("STOP");
    }
    else if (cmd == 2) {
      moveForward();
      Serial.println("FORWARD");
    }
    else if (cmd == 3) {
      moveBackward();
      Serial.println("BACKWARD");
    }
    else if (cmd == 4) {
      turnLeft();
      Serial.println("LEFT");
    }
    else if (cmd == 5) {
      turnRight();
      Serial.println("RIGHT");
    }
    else {
      Serial.println("UNKNOWN COMMAND");
    }
  }
}

void stopMotors() {
  // Add motor stop code here
}

void moveForward() {
  // Add forward motor code here
}

void moveBackward() {
  // Add backward motor code here
}

void turnLeft() {
  // Add left turn motor code here
}

void turnRight() {
  // Add right turn motor code here
}

How to adjust the Arduino code later
------------------------------------
The RoboLink app command mapping should stay the same.

Only change the Arduino functions:

- stopMotors()
- moveForward()
- moveBackward()
- turnLeft()
- turnRight()

Example:
If the robot moves backward when pressing Forward, do not change the app.
Instead, edit the motor wiring logic inside moveForward() in the Arduino code.

Example structure:
void moveForward() {
  // Set motor driver pins for forward movement
}

void moveBackward() {
  // Set motor driver pins for backward movement
}

void stopMotors() {
  // Turn off both motors
}

Using RoboLink with multiple robots
-----------------------------------
RoboLink scans nearby BLE robots and lets the child choose the correct one from the list.

For a classroom with multiple robots:
1. Put a physical label on each robot.
2. Use the last part of the BLE address as the label.

Example:
If the app shows:
EB:FA:CD:5E:D4:C9 HC-05

Label the robot:
D4:C9

This helps children select the correct robot, especially if all BLE modules have the same name, such as HC-05.

Testing checklist
-----------------
1. Upload the Arduino code.
2. Make sure the Arduino code uses BT.begin(9600).
3. Power the BLE module.
4. Open the RoboLink app.
5. Press Scan Robots.
6. Select the correct robot from Robot_List.
7. Wait until Status_Label shows Connected.
8. Press Forward.
9. Arduino Serial Monitor should print:
   Received command: 2
10. Release Forward.
11. Arduino Serial Monitor should print:
   Received command: 1
12. Test Backward, Left, Right, and Stop.

Troubleshooting
---------------
Problem:
The app scans but does not find the robot.

Possible fixes:
- Make sure the BLE module is powered.
- Make sure the phone Bluetooth is on.
- Make sure the app has Nearby devices permission.
- Close nRF Connect or any other app that may already be connected to the BLE module.

Problem:
The app connects but the Arduino receives nothing.

Possible fixes:
- Make sure the selected device is the correct robot.
- Make sure CHAR_UUID is:
  0000FFE1-0000-1000-8000-00805F9B34FB
- Use WriteBytesWithResponse in SendCommand.
- Make sure Arduino uses BT.begin(9600).
- Make sure BLE module TXD is connected to Arduino D10.
- Make sure BLE module GND and Arduino GND are connected.

Problem:
The app shows "Bad arguments to sort".

Fix:
- In SendCommand, replace "make new sorted list from get cmd" with "make a list get cmd".

Problem:
The robot moves in the wrong direction.

Fix:
- Do not change the RoboLink app mapping first.
- Adjust the Arduino motor functions, especially moveForward(), moveBackward(), turnLeft(), and turnRight().

References
----------
MIT App Inventor BluetoothLE extension:
https://iot.appinventor.mit.edu/iot/reference/bluetoothle

MIT App Inventor BluetoothClient documentation:
https://ai2.appinventor.mit.edu/reference/components/connectivity.html

Android Bluetooth permissions:
https://developer.android.com/develop/connectivity/bluetooth/bt-permissions
