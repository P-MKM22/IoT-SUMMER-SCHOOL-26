# Q 28 – Keypad + LCD Display

## Overview

This project implements a **password-protected access system** using a **4×4 membrane keypad**, **16×2 I2C LCD**, LEDs, and a buzzer. Users must enter the correct four-digit PIN to gain access. The system provides visual and audible feedback for both successful and failed authentication attempts while temporarily locking access after three consecutive incorrect PIN entries.

---

## Features

- 4×4 keypad-based PIN entry
- 16×2 I2C LCD user interface
- Password authentication
- Green LED for successful access
- Red LED and buzzer for incorrect PIN
- Three-attempt security lock
- 10-second lockout protection
- Real-time Serial Monitor logging
- Arduino Uno compatible
- Wokwi simulation support

---

## Project Structure

```text
Q28. Keypad + LCD Display
│
├── Assets
│   ├── Keypad + LCD display access granted.png
│   ├── Keypad + LCD display demo.mp4
│   ├── Keypad + LCD display hardware setup.png
│   ├── Keypad + LCD display wrong attempt 01.png
│   ├── Keypad + LCD display wrong attempt 02.png
│   ├── Keypad + LCD display wrong attempt 03.png
│   └── .gitkeep
│
├── Code
│   └── Keypad + LCD display.ino
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

## Hardware Used

- Arduino Uno
- 4×4 Membrane Keypad
- 16×2 I2C LCD Display
- Green LED
- Red LED
- Piezo Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Project Workflow

1. Display **ENTER PIN:** on the LCD.
2. Read the four-digit PIN entered through the keypad.
3. Compare the entered PIN with the predefined password.
4. Grant or deny access based on the verification result.
5. Count incorrect attempts.
6. Lock the system for **10 seconds** after three consecutive failed attempts.
7. Reset and wait for the next authentication request.

---

## Assets

| Asset | Description |
|--------|-------------|
| Hardware Setup | Complete circuit implementation |
| Access Granted | Successful PIN verification |
| Wrong Attempt 01 | First failed attempt |
| Wrong Attempt 02 | Second failed attempt |
| Wrong Attempt 03 | Third failed attempt and system lock |
| Demo Video | Complete project demonstration |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469255039140374529

**Description**

This Wokwi simulation demonstrates a secure keypad-based access control system using a 4×4 keypad and a 16×2 I2C LCD. It verifies user-entered PINs, provides visual and audible feedback, tracks incorrect attempts, and activates a temporary security lock after repeated authentication failures.

---

## Future Enhancements

- Store multiple user PINs using EEPROM.
- Allow password changes through the keypad.
- Integrate RFID or fingerprint authentication.
- Add a servo motor to simulate an automatic door lock.
- Display the remaining lockout time on the LCD.
- Enable IoT-based remote monitoring and access logging.
- Record authentication history with timestamps.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
```
