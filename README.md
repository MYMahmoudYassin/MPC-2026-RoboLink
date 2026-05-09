<div align="center">
  <img width="211" height="46" alt="Mini Course Program logo" src="https://github.com/user-attachments/assets/7af10aa5-d64e-46dd-9b3f-78521599634c" />

  <h1>Mini Course Program 2026: RoboLink</h1>

  <p><strong>Build and Drive Your Smartphone-Controlled Robot</strong></p>
  <p>Carleton University Mini Course Program</p>
  <p>Instructors: Dr. Mahmoud Sayed and Mahmoud Yassin</p>

  <p>
    <a href="https://carleton.ca/mcp/">Carleton MCP</a> |
    <a href="https://minic.ca/">Mini-Courses</a>
  </p>

  <img src="assets/Robot_Test.gif" alt="RoboLink robot test drive" width="640" />
</div>

## Course Folder Guide

This repository is the student-facing course pack for RoboLink. The course moves from basic electronics to a working robot that can be driven from an Android phone. Each day folder has its own README with the day introduction, learning goals, exact contents, and suggested order.

| Folder | Students Work On | Main Contents |
| --- | --- | --- |
| [`Day0_Orientation/`](Day0_Orientation/) | Course welcome, schedule, group work, and the project roadmap. | [`Orientation.pdf`](Day0_Orientation/Orientation.pdf) |
| [`Day1_Getting_Started/`](Day1_Getting_Started/) | Circuits, voltage, current, LEDs, switches, and safe wiring habits. | [`Day1_RoboLink_Basic_Electronics.pdf`](Day1_Getting_Started/Day1_RoboLink_Basic_Electronics.pdf), [`Labs/Analog Discovery 2.pdf`](Day1_Getting_Started/Labs/Analog%20Discovery%202.pdf) |
| [`Day2_Arduino_Basics/`](Day2_Arduino_Basics/) | Arduino IDE setup, Blink, button input, LEDs, buzzer, and first sketches. | [`Lessons/Programming - Intro.pdf`](Day2_Arduino_Basics/Lessons/Programming%20-%20Intro.pdf), [`Day2_Arduino_World.pdf`](Day2_Arduino_Basics/Day2_Arduino_World.pdf), Arduino sketches |
| [`Day3_Sensors/`](Day3_Sensors/) | IR object detection, ultrasonic distance sensing, and Serial Monitor readings. | [`Lessons/Sensors.pdf`](Day3_Sensors/Lessons/Sensors.pdf), sensor lab PDFs, Arduino sketches |
| [`Day4_Serial_Monitor_Robot/`](Day4_Serial_Monitor_Robot/) | DC motors, L9110 driver control, and Serial Monitor robot commands. | [`Lessons/DC Motors.ppsx`](Day4_Serial_Monitor_Robot/Lessons/DC%20Motors.ppsx), [`Labs/Lab4_Serial_Monitor_Robot.pdf`](Day4_Serial_Monitor_Robot/Labs/Lab4_Serial_Monitor_Robot.pdf), Arduino sketches |
| [`Day5_RoboLink_Smartphone_Control/`](Day5_RoboLink_Smartphone_Control/) | BLE communication, Android app setup, wireless commands, and final robot driving. | Wireless lesson PDF, Lab 5 PDFs, [`Robotak Controller.apk`](Day5_RoboLink_Smartphone_Control/Labs/RoboLink%20APP/Robotak%20Controller.apk), Arduino sketches |

## Course Snapshot

RoboLink is a five-day robotics mini course for students who are starting with electronics, embedded programming, sensors, motors, and wireless control. The orientation material gives the classroom context, while the folders above are the working materials students use during the course.

By the end of the course, students should be able to:

- Build and test simple breadboard circuits safely.
- Use the Arduino IDE with an Arduino Nano ATmega168.
- Read and modify Arduino sketches.
- Use buttons, IR sensors, ultrasonic sensors, LEDs, buzzers, motors, and the Serial Monitor.
- Control a two-motor robot with an L9110 motor driver.
- Send commands from an Android phone to the robot using a BLE module.
- Troubleshoot wiring, power, code, and communication problems.

## Software

- Arduino IDE
- Arduino AVR board support for Arduino Nano
- Android phone for the RoboLink smartphone control app on Day 5
- PDF reader

## Main Hardware

- Arduino Nano ATmega168
- Breadboard and jumper wires
- LEDs and resistors
- Push button
- Buzzer module
- IR obstacle sensor
- Ultrasonic sensor
- L9110 motor driver
- DC motors and robot chassis
- BLE HC-05-style module used for RoboLink wireless control

## Suggested Use

1. Start with [`Day0_Orientation/`](Day0_Orientation/).
2. Work through each day folder in order.
3. Open the day README before opening the lesson or lab files.
4. Open the matching Arduino `.ino` file in the Arduino IDE when a lab asks for code.
5. Ask your instructor to check wiring before connecting power.

## Survey

The end-of-course survey link is open. Please take a few minutes to complete the feedback form:

[Complete the RoboLink survey](https://forms.gle/tiZQJAAHRRJ7FY2aA)
