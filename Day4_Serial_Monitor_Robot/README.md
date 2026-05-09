# Day 4: Serial Monitor Robot

Day 4 moves from individual Arduino outputs to robot motion. Students learn how DC motors are controlled, how the L9110 motor driver works, and how Serial Monitor commands can make the robot move forward, backward, left, right, and stop.

## Learning Goals

By the end of Day 4, students should be able to:

- Explain why motors need a driver instead of being connected directly to Arduino pins.
- Identify the L9110 motor driver inputs and motor outputs.
- Upload and test robot movement code.
- Send simple movement commands from the Serial Monitor.
- Connect code commands to physical robot movement.
- Troubleshoot motor wiring, power, ground, and direction problems.

## Contents

- [`Lessons/DC Motors.ppsx`](Lessons/DC%20Motors.ppsx)
  Motor lesson slides for DC motor principles and driver control.

- [`Labs/Lab4_Serial_Monitor_Robot.pdf`](Labs/Lab4_Serial_Monitor_Robot.pdf)
  Main Day 4 lab guide for Serial Monitor robot control.

- [`Labs/Lab4_Serial_Monitor_Robot/Lab4_Serial_Monitor_Robot.ino`](Labs/Lab4_Serial_Monitor_Robot/Lab4_Serial_Monitor_Robot.ino)
  Arduino sketch for controlling the robot with Serial Monitor commands.

- [`Labs/CircleArea/CircleArea.ino`](Labs/CircleArea/CircleArea.ino)
  Supporting Arduino sketch for a simple Serial Monitor input and calculation activity.

## Suggested Order

1. Open [`Lessons/DC Motors.ppsx`](Lessons/DC%20Motors.ppsx).
2. Open [`Labs/Lab4_Serial_Monitor_Robot.pdf`](Labs/Lab4_Serial_Monitor_Robot.pdf).
3. Build the L9110 motor driver wiring with your instructor's help.
4. Upload [`Labs/Lab4_Serial_Monitor_Robot/Lab4_Serial_Monitor_Robot.ino`](Labs/Lab4_Serial_Monitor_Robot/Lab4_Serial_Monitor_Robot.ino).
5. Test commands from the Serial Monitor while the wheels are lifted.
6. Continue to [`../Day5_RoboLink_Smartphone_Control/`](../Day5_RoboLink_Smartphone_Control/) for wireless robot control.

## Safety Reminders

- Keep the robot wheels lifted during the first motor test.
- Use the correct motor power supply and shared ground.
- Ask your instructor to check wiring before connecting motor power.
- Stop testing immediately if the motor driver or wires get hot.
