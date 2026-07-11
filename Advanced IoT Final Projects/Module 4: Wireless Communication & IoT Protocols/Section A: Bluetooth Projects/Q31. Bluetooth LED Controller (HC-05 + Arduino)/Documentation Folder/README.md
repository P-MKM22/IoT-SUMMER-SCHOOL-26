# Documentation of Question 31

## Overview

This document provides the complete technical documentation for **Q31 – Bluetooth LED Controller (HC-05 + Arduino)** developed as part of the **Advanced IoT Final Project**, **Module 4: Wireless Communication & IoT Protocols**, **Section A: Bluetooth Projects**.

> **Note:** The original assignment requires communication using an **HC-05 Bluetooth module**. Since **Wokwi and other simulator does not support HC-05 simulation**, the Bluetooth commands were simulated using the **Arduino Serial Monitor**. The command set and application logic remain identical to the HC-05 implementation and can be directly used with physical hardware by replacing the Serial interface with the HC-05 communication interface.

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
└── Module 4: Wireless Communication & IoT Protocols
    │
    └── Section A: Bluetooth Projects
        │
        └── Q31. Bluetooth LED Controller (HC-05 + Arduino)
            │
            ├── Assets
            │   ├── Bluetooth LED Controller (HC-05 + Arduino) demo.mp4
            │   ├── Bluetooth LED Controller (HC-05 + Arduino) hardware setup.png
            │   ├── Command B.png
            │   ├── Command F.png
            │   ├── Command G.png
            │   ├── Command R.png
            │   ├── Command X.png
            │   ├── Invalid Command.png
            │   └── .gitkeep
            │
            ├── Code
            │   └── BT_LED_Controller.ino
            │
            ├── Documentation
            │   └── README.md
            │
            └── README.md
```

---

## Components Required

- Arduino Uno
- Red LED
- Green LED
- Blue LED
- 220Ω Resistors ×3
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Red LED | D8 |
| Green LED | D9 |
| Blue LED | D10 |

---

## Circuit Connections

### Red LED

| LED Pin | Arduino Connection |
|----------|--------------------|
| Anode (+) | D8 through 220Ω resistor |
| Cathode (-) | GND |

### Green LED

| LED Pin | Arduino Connection |
|----------|--------------------|
| Anode (+) | D9 through 220Ω resistor |
| Cathode (-) | GND |

### Blue LED

| LED Pin | Arduino Connection |
|----------|--------------------|
| Anode (+) | D10 through 220Ω resistor |
| Cathode (-) | GND |

---

## Step-by-Step Connections

### Step 1

Connect the Red LED anode to **Digital Pin 8** through a **220Ω resistor**.

### Step 2

Connect the Green LED anode to **Digital Pin 9** through a **220Ω resistor**.

### Step 3

Connect the Blue LED anode to **Digital Pin 10** through a **220Ω resistor**.

### Step 4

Connect the cathodes of all three LEDs to the common **GND** rail.

### Step 5

Power the Arduino Uno and upload the program.

### Step 6

Open the Serial Monitor and set the baud rate to **9600**.

### Step 7

Enter any of the supported commands (`R`, `G`, `B`, `X`, `F`) to simulate Bluetooth communication.

---

## Working Principle

The Arduino continuously monitors incoming characters from the Serial Monitor. Each received command represents a Bluetooth command that would normally be transmitted by an HC-05 module. Depending on the received character, the corresponding LED operation is executed. Invalid commands are rejected and an appropriate message is displayed on the Serial Monitor.

---

## Implementation Steps

### Step 1

Initialize the Serial Monitor and configure all LED pins as outputs.

### Step 2

Wait for a command from the Serial Monitor.

### Step 3

Read the incoming command and compare it with the predefined command set.

### Step 4

Execute the corresponding LED operation.

### Step 5

Display the executed action on the Serial Monitor.

### Step 6

Continue monitoring for the next command.

---

## Serial Monitor Output

```text
========================================
Bluetooth LED Controller
Command Received : R
Status : Red LED ON
========================================
```

---

## Code Explanation

### Serial Communication

Receives command characters from the Serial Monitor to simulate Bluetooth input.

### Command Processing

Identifies the received command and selects the appropriate LED operation.

### LED Control

Controls the Red, Green, and Blue LEDs according to the received command.

### Flash Operation

Flashes all LEDs five consecutive times when the flash command is received.

### Error Handling

Detects unsupported commands and displays an error message without affecting the LEDs.

---

## Software Concepts Used

- Serial Communication
- Command-Based Control
- Digital Output Programming
- LED Interfacing
- Conditional Statements
- Looping Constructs
- Embedded System Programming

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Bluetooth LED Controller (HC-05 + Arduino) hardware setup.png | Circuit implementation |
| Bluetooth LED Controller (HC-05 + Arduino) demo.mp4 | Complete project demonstration |
| Command R.png | Red LED command execution |
| Command G.png | Green LED command execution |
| Command B.png | Blue LED command execution |
| Command X.png | All LEDs OFF command |
| Command F.png | Flash LEDs command |
| Invalid Command.png | Unsupported command handling |

---

## Wokwi Simulation

**Simulation Link**

(https://wokwi.com/projects/469259890688126977)

**Description**

This simulation demonstrates the command-based control of three LEDs using the Arduino Serial Monitor. The Serial Monitor acts as a substitute for the HC-05 Bluetooth module, allowing the same command protocol (`R`, `G`, `B`, `X`, `F`) to be tested in simulation. On physical hardware, the Serial interface can be replaced with the HC-05 Bluetooth module without modifying the control logic.

---

## Learning Outcomes

- Serial communication
- Command-based programming
- LED interfacing
- Digital output control
- Conditional logic
- Embedded system development
- Simulation of Bluetooth communication

---

## Best Practices

- Verify all LED polarity before powering the circuit.
- Use 220Ω current-limiting resistors for each LED.
- Maintain the Serial Monitor baud rate at **9600**.
- Enter commands one at a time for proper execution.
- Validate command responses through the Serial Monitor.

---

## Conclusion

The **Bluetooth LED Controller (HC-05 + Arduino)** project demonstrates command-based wireless device control using Arduino. Although the HC-05 module is unavailable in Wokwi, the Serial Monitor accurately simulates Bluetooth communication while preserving the original command protocol. This approach enables complete testing of the application logic and allows seamless migration to physical hardware with an HC-05 module.
