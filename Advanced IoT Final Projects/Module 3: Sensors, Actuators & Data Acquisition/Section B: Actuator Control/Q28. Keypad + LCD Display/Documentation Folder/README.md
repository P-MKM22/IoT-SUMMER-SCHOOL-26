# Documentation of Question 28

## Overview

This document provides the complete technical documentation for **Q 28 – Keypad + LCD Display** developed as part of the **Advanced IoT Final Project**, **Module 3: Sensors, Actuators & Data Acquisition**, **Section B: Actuator Control**.

---

## Documentation Contents

- Project Overview
- Components Required
- Pin Configuration
- Circuit Connections
- Step-by-Step Connections
- Working Principle
- Implementation Steps
- Serial Monitor Output
- Code Explanation
- Software Concepts Used
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- Conclusion

---

## Project Structure

```text
Advanced IoT Final Projects
│
└── Module 3: Sensors, Actuators & Data Acquisition
    │
    └── Section B: Actuator Control
        │
        └── Q28. Keypad + LCD Display
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

## Components Required

- Arduino Uno
- 4×4 Membrane Keypad
- 16×2 LCD Display (I2C)
- I2C Interface Module
- Green LED
- Red LED
- Piezo Buzzer
- 220Ω Resistors ×2
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| LCD SDA | A4 |
| LCD SCL | A5 |
| Keypad Rows | D9, D8, D7, D6 |
| Keypad Columns | D5, D4, D3, D2 |
| Green LED | D10 |
| Red LED | D11 |
| Buzzer | D12 |

---

## Circuit Connections

### LCD Display

| LCD Pin | Arduino |
|----------|----------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### Keypad

| Keypad Pin | Arduino |
|-------------|----------|
| R1 | D9 |
| R2 | D8 |
| R3 | D7 |
| R4 | D6 |
| C1 | D5 |
| C2 | D4 |
| C3 | D3 |
| C4 | D2 |

### Green LED

- Anode → D10 through 220Ω resistor
- Cathode → GND

### Red LED

- Anode → D11 through 220Ω resistor
- Cathode → GND

### Piezo Buzzer

- Positive → D12
- Negative → GND

---

## Step-by-Step Connections

### Step 1

Connect the LCD **VCC** to **5V** and **GND** to **GND**.

### Step 2

Connect the LCD **SDA** pin to **A4** and **SCL** pin to **A5**.

### Step 3

Connect the keypad row pins (**R1–R4**) to **D9, D8, D7, and D6**.

### Step 4

Connect the keypad column pins (**C1–C4**) to **D5, D4, D3, and D2**.

### Step 5

Connect the Green LED anode to **D10** through a **220Ω resistor** and the cathode to **GND**.

### Step 6

Connect the Red LED anode to **D11** through a **220Ω resistor** and the cathode to **GND**.

### Step 7

Connect the buzzer positive terminal to **D12** and the negative terminal to **GND**.

### Step 8

Verify all wiring connections and power the Arduino before starting the simulation.

---

## Working Principle

When powered on, the LCD displays **"ENTER PIN:"** and waits for user input from the keypad. A predefined four-digit password is entered using the keypad. If the entered PIN matches the stored password, the system grants access by displaying a success message, turning ON the green LED, and generating a confirmation beep. If the password is incorrect, the LCD displays an access denied message, the red LED turns ON, and the buzzer alerts the user. After three consecutive incorrect attempts, the system locks for 10 seconds before allowing another attempt.

---

## Implementation Steps

### Step 1

Initialize the LCD, keypad, LEDs, and buzzer.

### Step 2

Display **ENTER PIN:** on the LCD.

### Step 3

Read keypad input and store the entered PIN.

### Step 4

Compare the entered PIN with the predefined password.

### Step 5

Grant or deny access based on the comparison result.

### Step 6

Count incorrect attempts and activate the lockout timer after three failures.

### Step 7

Reset the system after the lock period and wait for the next user.

---

## Serial Monitor Output

```text
--------------------------------
Entered PIN : 2580
Status      : ACCESS GRANTED
Wrong Attempts : 0
--------------------------------
```

---

## Code Explanation

### Keypad Input

Reads the four-digit PIN entered through the membrane keypad.

### Password Verification

Compares the entered PIN with the predefined password stored in the program.

### Access Control

Displays either **ACCESS GRANTED** or **ACCESS DENIED** while controlling the LEDs and buzzer.

### Security Lock

Counts incorrect attempts and locks the system for ten seconds after three consecutive failures.

### User Feedback

Provides real-time status updates through the LCD and Serial Monitor.

---

## Software Concepts Used

- Matrix Keypad Interfacing
- I2C LCD Communication
- Password Authentication
- Digital Input Handling
- LED Control
- Buzzer Control
- Access Control Logic
- Embedded System Programming

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Keypad + LCD display hardware setup.png | Circuit wiring |
| Keypad + LCD display access granted.png | Successful authentication |
| Keypad + LCD display wrong attempt 01.png | First incorrect attempt |
| Keypad + LCD display wrong attempt 02.png | Second incorrect attempt |
| Keypad + LCD display wrong attempt 03.png | Third incorrect attempt and system lock |
| Keypad + LCD display demo.mp4 | Complete project demonstration |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469255039140374529

**Description**

This simulation demonstrates a password-protected access system using a 4×4 membrane keypad and a 16×2 I2C LCD. Users enter a four-digit PIN to authenticate access. The system provides visual and audible feedback, counts incorrect attempts, and temporarily locks after three consecutive failures to improve security.

---

## Learning Outcomes

- Matrix keypad interfacing
- I2C LCD communication
- Password authentication
- User access control
- LED and buzzer interfacing
- Security lock implementation
- Embedded system programming

---

## Best Practices

- Verify keypad row and column wiring before uploading the program.
- Ensure the LCD I2C address matches the hardware configuration.
- Use pull-up logic for stable keypad operation.
- Test the lockout mechanism after incorrect password attempts.
- Verify Serial Monitor output for debugging and validation.

---

## Conclusion

The **Keypad + LCD Display** project demonstrates a simple embedded access control system by combining keypad input, LCD feedback, LED indicators, and buzzer alerts. The implementation introduces password authentication, incorrect attempt tracking, and timed system lockout, providing practical experience in designing secure user-interactive embedded systems.
