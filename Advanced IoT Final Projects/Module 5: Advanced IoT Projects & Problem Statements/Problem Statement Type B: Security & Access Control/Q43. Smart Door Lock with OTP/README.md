# Q 43 – Smart Door Lock with OTP

## Problem Statement

A university hostel wants to replace traditional physical keys with a secure PIN-based entry system that also generates a One-Time Password (OTP). The objective is to design a Smart Door Lock System where a student enters their **4-digit Student ID** using a keypad. The system then generates a **6-digit OTP**, sends it via **Bluetooth**, and grants access only if the correct OTP is entered within **30 seconds**.

---

# Task Requirements

The project has been designed to satisfy the following requirements:

- 4×4 Keypad for Student ID and OTP entry
- 16×2 I2C LCD Display for user prompts and masked input
- HC-05 Bluetooth / ESP32 Bluetooth to transmit the OTP
- Servo Motor to simulate the door locking mechanism
- 30-second countdown timer using `millis()` (Non-blocking implementation)
- Log every access attempt (Success / Failure) to the Serial Monitor

---

# Project Overview

The Smart Door Lock with OTP is an embedded security system developed using the ESP32 platform. Instead of relying on conventional keys, the system authenticates users using a two-step verification process consisting of a Student ID and a randomly generated One-Time Password (OTP).

The user first enters a valid 4-digit Student ID using a 4×4 keypad. After successful ID entry, the ESP32 generates a random 6-digit OTP and sends it through Bluetooth. During simulation in Wokwi, the OTP is displayed on the Serial Monitor due to Bluetooth limitations in the simulator.

The user must enter the OTP within 30 seconds. If the entered OTP matches the generated OTP, the servo motor rotates by **90°**, simulating the unlocking of the door. After a short duration, the door automatically locks again. Every authentication attempt, whether successful or unsuccessful, is recorded in the Serial Monitor.

The entire system is implemented using a **non-blocking timer (`millis()`)**, making it responsive and efficient.

---

# Features

- Secure two-factor authentication
- 4-digit Student ID verification
- Random 6-digit OTP generation
- Bluetooth OTP transmission support
- Masked keypad input using '*'
- 30-second OTP timeout
- Servo-controlled door lock mechanism
- Automatic door re-locking
- LCD-based user interface
- Serial Monitor activity logging
- Event-driven programming using `millis()`
- Modular and maintainable Arduino code

---

# Project Structure

```text
Q43. Smart Door Lock with OTP
│
├── Assets
│   ├── smart door lock hardware setup.png
│   ├── smart door lock success entry.png
│   ├── smart door lock fail entry.png
│   ├── smart door lock success demo part 01.mp4
│   ├── smart door lock success demo part 02.mp4
│   ├── smart door lock fail demo part 01.mp4
│   └── smart door lock fail demo part 02.mp4
│
├── Code
│   └── DoorLockOTP.ino
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

# Folder Description

## Code

Contains the complete Arduino source code (`DoorLockOTP.ino`) for the Smart Door Lock System. The program includes keypad interfacing, OTP generation, LCD interaction, Bluetooth communication support, servo motor control, non-blocking timing using `millis()`, and Serial Monitor logging.

---

## Assets

The Assets folder contains all supporting resources and demonstration files for the project.

Included assets:

- Hardware setup image
- Successful authentication screenshot
- Failed authentication screenshot
- Successful project demonstration videos
- Failed authentication demonstration videos

These files provide visual proof of hardware implementation and successful execution of the project.

---

## Documentation

The Documentation folder contains detailed project documentation covering:

- Project introduction
- Hardware requirements
- Circuit connections
- Working principle
- Software implementation
- Program workflow
- Testing procedure
- Expected output
- Challenges faced
- Future enhancements

---

# Hardware Components Used

| Component | Quantity |
|-----------|---------:|
| ESP32 Development Board | 1 |
| 4×4 Matrix Keypad | 1 |
| 16×2 I2C LCD Display | 1 |
| Servo Motor (SG90) | 1 |
| Bluetooth Module (ESP32 / HC-05) | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

# Software Used

- Arduino IDE
- Wokwi Simulator
- GitHub
- ESP32 Arduino Core
- LiquidCrystal_I2C Library
- Keypad Library
- ESP32Servo Library

---

# Functional Workflow

1. System initializes all hardware peripherals.
2. LCD prompts the user to enter a 4-digit Student ID.
3. Student enters the ID using the keypad.
4. ESP32 generates a random 6-digit OTP.
5. OTP is transmitted through Bluetooth (or displayed in the Serial Monitor during simulation).
6. User enters the received OTP.
7. The system validates the entered OTP.
8. If the OTP is correct:
   - Access is granted.
   - Servo motor rotates to 90°.
   - Door unlocks for a few seconds.
   - Door automatically locks again.
9. If the OTP is incorrect or expires:
   - Access is denied.
10. Every authentication attempt is logged in the Serial Monitor.
11. The system resets automatically and waits for the next user.

---

# Hardware Demonstration

The project has been successfully implemented and verified through hardware simulation.

The repository includes:

- Hardware setup screenshot
- Successful authentication screenshots
- Failed authentication screenshots
- Successful working demonstration videos
- Failed authentication demonstration videos

These assets demonstrate the complete functionality of the Smart Door Lock System under different authentication scenarios.

---

# Wokwi Simulation

The Smart Door Lock with OTP system was designed, tested, and verified using the Wokwi ESP32 Simulator. The simulation demonstrates the complete project workflow, including Student ID entry, OTP generation, OTP verification, servo motor operation, LCD interface, and Serial Monitor logging.

**Simulation Link:**

https://wokwi.com/projects/469006246137329665

> **Note:** Wokwi currently does not support ESP32 Classic Bluetooth (`BluetoothSerial`). Therefore, during simulation, the generated OTP is displayed through the Serial Monitor. The same code can be executed on a physical ESP32 to enable Bluetooth communication.

---

# Project Highlights

- Secure two-level authentication
- Random OTP generation
- Bluetooth communication support
- Servo-controlled smart door locking
- LCD-based user interaction
- Non-blocking timing using `millis()`
- Automatic OTP expiration
- Automatic door re-locking
- Complete Serial Monitor logging
- Modular Arduino programming
- Real-world hostel security application

---

# Learning Outcomes

This project demonstrates practical implementation of:

- ESP32 Programming
- Embedded System Design
- Keypad Interfacing
- LCD Communication (I2C)
- Servo Motor Control
- Bluetooth Communication
- Random Number Generation
- Event-Driven Programming
- Non-blocking Timers using `millis()`
- Embedded Security Systems
- Arduino Library Integration

---

# Future Enhancements

- Fingerprint authentication
- RFID card integration
- Face recognition support
- Mobile application control
- Wi-Fi based notifications
- Cloud database logging
- Multi-user authentication
- OLED graphical display
- Remote access monitoring

---

# Repository Contents

This repository contains:

- Complete Arduino source code
- Project documentation
- Hardware setup screenshots
- Authentication screenshots
- Working demonstration videos
- Wokwi simulation
- Supporting project assets

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
