# Q 26 – DC Motor Speed Control with L298N

## Overview

This project demonstrates **DC motor speed and direction control** using an **Arduino Uno**, an **H-Bridge motor driver**, a **potentiometer**, and two push buttons. The potentiometer controls the motor speed through PWM, one push button changes the motor direction, and the other starts or stops the motor. Real-time motor parameters are displayed on the Serial Monitor for monitoring and testing.

> **Note:** The assignment specifies the **L298N Motor Driver**. Since **Tinkercad does not provide the L298N module**, the project was implemented using the **L293D Motor Driver IC**, which provides equivalent H-Bridge functionality for simulation.

---

## Features

- PWM-based DC motor speed control
- Forward and reverse motor rotation
- Start/Stop motor using a push button
- Potentiometer-controlled speed adjustment
- Real-time Serial Monitor output
- Compatible with Arduino Uno and Tinkercad

---

## Project Structure

```text
Q26. DC Motor Speed Control with L298N
│
├── Assets
│   ├── DC Motor Speed Control with L293D demo.mp4
│   ├── DC Motor Speed Control with L298N hardware setup.png
│   ├── DC Motor forward and running status.png
│   ├── DC Motor reverse and running status.png
│   ├── DC Motor stopped and started using push button.png
│   ├── DC Motor stopped as potentiometer is at 255.png
│   └── .gitkeep
│
├── Code
│   └── DC_Motor_Speed_Control.ino
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

## Hardware Used

- Arduino Uno
- L293D Motor Driver IC *(used instead of L298N)*
- DC Motor
- 10kΩ Potentiometer
- Push Button ×2
- Breadboard
- Jumper Wires

---

## Functional Description

The potentiometer continuously adjusts the motor speed by varying the PWM output. One push button changes the motor rotation between **Forward** and **Reverse**, while the second button starts or stops the motor. The Serial Monitor displays the potentiometer reading, PWM value, speed percentage, motor direction, and current operating state.

---

## Serial Monitor Output

```text
Potentiometer : 780
PWM Value     : 194
Speed         : 76%
Direction     : Forward
State         : Running
```

---

## Repository Contents

- Arduino source code
- Circuit hardware setup
- Demonstration video
- Project screenshots
- Technical documentation
- Project README

---

## Tinkercad Simulation

**Simulation Link**

https://www.tinkercad.com/things/2Yh2ABClB5q-funky-bojo-lappi/editel

**Description**

This Tinkercad simulation demonstrates PWM-based DC motor speed control using an Arduino Uno and the L293D motor driver. The potentiometer adjusts the motor speed, one push button changes the motor direction (Forward/Reverse), and another push button starts or stops the motor. The Serial Monitor displays the potentiometer value, PWM value, speed percentage, motor direction, and motor state in real time.

---

## Future Enhancements

- Replace the L293D with an L298N motor driver for higher current applications.
- Add an LCD or OLED display to show motor status without using the Serial Monitor.
- Integrate Bluetooth or Wi-Fi for wireless motor control.
- Implement closed-loop speed control using an encoder for improved accuracy.
- Add current sensing and overload protection for safer motor operation.
- Support mobile app or IoT-based remote monitoring and control.

## Learning Outcomes

- DC motor interfacing
- PWM speed control
- H-Bridge motor driver operation
- Direction control
- Push button interfacing
- Analog input processing
- Serial communication
- Embedded actuator control

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
