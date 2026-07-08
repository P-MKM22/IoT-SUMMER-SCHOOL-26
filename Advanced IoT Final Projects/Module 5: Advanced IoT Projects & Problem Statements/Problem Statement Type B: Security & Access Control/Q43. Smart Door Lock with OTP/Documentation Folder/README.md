# Documentation of Question 43

---

# Objective

The objective of this project is to develop a **Smart Door Lock System** using the ESP32 that replaces conventional keys with a secure **Student ID and One-Time Password (OTP)** based authentication mechanism. The system authenticates the user, unlocks the door for a limited time upon successful verification, and automatically resets for the next user.

---

# Problem Statement

A university hostel wants to replace physical keys with a PIN-based entry system that also generates a One-Time Password (OTP). Design a system where a student enters their **4-digit ID** on a keypad, the system generates a **6-digit OTP**, sends it over **Bluetooth**, and only grants access if the OTP is entered within **30 seconds**.

---

# Project Requirements

The project fulfills the following requirements:

- 4×4 Keypad for Student ID and OTP entry
- 16×2 I2C LCD Display
- ESP32 / HC-05 Bluetooth support
- Servo Motor for door locking mechanism
- 30-second countdown timer using `millis()`
- Serial Monitor logging for every authentication attempt

---

# Hardware Components

| Component | Quantity |
|-----------|---------:|
| ESP32 Development Board | 1 |
| 4×4 Matrix Keypad | 1 |
| 16×2 LCD with I2C Module | 1 |
| Servo Motor (SG90) | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

# Software & Libraries

## Software

- Arduino IDE
- Wokwi Simulator
- GitHub

## Libraries

- Wire.h
- LiquidCrystal_I2C.h
- Keypad.h
- ESP32Servo.h
- BluetoothSerial.h *(for physical ESP32 only)*

---

# Circuit Connections

## LCD (I2C)

| LCD Pin | ESP32 Pin |
|----------|-----------|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

## Servo Motor

| Servo Pin | ESP32 Pin |
|-----------|-----------|
| VCC | 5V |
| GND | GND |
| Signal | GPIO 18 |

---

## 4×4 Keypad

| Keypad Pin | ESP32 Pin |
|------------|-----------|
| R1 | GPIO 13 |
| R2 | GPIO 12 |
| R3 | GPIO 14 |
| R4 | GPIO 27 |
| C1 | GPIO 26 |
| C2 | GPIO 25 |
| C3 | GPIO 33 |
| C4 | GPIO 32 |

---

# Working Principle

The system operates through a secure authentication sequence:

1. ESP32 initializes all connected peripherals.
2. LCD prompts the user to enter a 4-digit Student ID.
3. User enters the ID using the keypad.
4. ESP32 generates a random 6-digit OTP.
5. OTP is sent through Bluetooth (or displayed on the Serial Monitor during simulation).
6. A 30-second timer starts immediately.
7. User enters the received OTP.
8. System compares the entered OTP with the generated OTP.
9. If matched:
   - Access Granted is displayed.
   - Servo rotates 90°.
   - Door unlocks.
10. After 3 seconds:
    - Door automatically locks.
11. If OTP is incorrect or expires:
    - Access Denied is displayed.
12. System resets automatically for the next user.

---

# Program Flow

```
System Start
      │
      ▼
Initialize Hardware
      │
      ▼
Enter Student ID
      │
      ▼
Generate OTP
      │
      ▼
Start 30s Timer
      │
      ▼
Enter OTP
      │
      ├───────────────┐
      │               │
      ▼               ▼
Correct OTP      Wrong / Expired
      │               │
      ▼               ▼
Unlock Door     Access Denied
      │               │
      ▼               ▼
Lock Door      Reset System
      │               │
      └──────► Ready for Next User
```

---

# Serial Monitor Output

The Serial Monitor records every authentication attempt, including:

- Student ID
- Generated OTP
- Entered OTP
- Authentication Status
- Door Unlock Event
- Door Lock Event
- Success or Failure Log

This makes debugging and monitoring significantly easier.

---

# Key Features

- Two-factor authentication
- Random OTP generation
- Bluetooth communication support
- Password masking
- LCD user interface
- Servo-based locking mechanism
- Automatic door re-locking
- Non-blocking timing using `millis()`
- Complete activity logging
- Modular and reusable code

---

# Wokwi Simulation

The project has been successfully tested using the Wokwi ESP32 Simulator.

During simulation, Bluetooth communication is represented using the Serial Monitor because Wokwi currently does not support ESP32 Classic Bluetooth.

Simulation Link:

https://wokwi.com/projects/469006246137329665

---

# Testing Performed

The following scenarios were successfully verified:

- Valid Student ID entry
- Random OTP generation
- Correct OTP verification
- Incorrect OTP rejection
- OTP timeout after 30 seconds
- Automatic servo unlocking
- Automatic servo locking
- Serial Monitor logging
- LCD message updates

---

# Do's

- Verify all wiring before powering the ESP32.
- Use the correct I2C address for the LCD.
- Ensure the servo has a stable power supply.
- Enter exactly four digits for the Student ID.
- Enter the OTP within the allotted time.
- Test each module individually before integrating the complete circuit.
- Keep all GPIO connections secure.

---

# Don'ts

- Do not disconnect components while the ESP32 is powered.
- Do not connect the servo signal pin to an incorrect GPIO.
- Do not use `delay()` for implementing the countdown timer.
- Do not leave loose jumper wire connections.
- Do not enter extra digits after the required input length.
- Do not power the ESP32 with an unstable supply.

---

# Troubleshooting

| Issue | Possible Solution |
|--------|------------------|
| LCD not displaying | Check SDA/SCL wiring and I2C address |
| Keypad not responding | Verify row and column pin connections |
| Servo not rotating | Check GPIO 18 and power supply |
| OTP not accepted | Ensure the entered OTP matches the generated OTP |
| LCD displays garbage | Recheck LCD initialization and wiring |
| ESP32 resets unexpectedly | Verify power supply and wiring |

---

# Future Improvements

- Fingerprint authentication
- RFID-based access
- Mobile application support
- Cloud logging
- Wi-Fi notifications
- Face recognition
- Multi-user database
- OLED graphical interface

---

# Conclusion

The Smart Door Lock with OTP successfully demonstrates a secure embedded access control system using ESP32. The project combines keypad input, OTP authentication, LCD interaction, Bluetooth communication, servo control, and non-blocking programming using `millis()` to create a reliable and scalable smart security solution suitable for real-world applications.
