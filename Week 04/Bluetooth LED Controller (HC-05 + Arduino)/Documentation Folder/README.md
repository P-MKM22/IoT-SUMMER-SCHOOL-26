# Documentation of Bluetooth LED Controller (HC-05 + Arduino)

## Overview

This document provides the complete technical documentation for the **Bluetooth LED Controller (HC-05 + Arduino)** developed during **Week 04** of the **IoT Summer School 2026**. This project demonstrates command-based wireless LED control using Bluetooth communication. Since the **HC-05 module is unavailable in Wokwi**, the communication has been simulated using the Arduino Serial Monitor while preserving the original Bluetooth command protocol specified in the assignment.

---

## Documentation Contents

- Project Overview
- Components Required
- Pin Configuration
- Circuit Connections
- Step-by-Step Connections
- Working Principle
- HC-05 Pairing Instructions
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
Week 04
│
└── Bluetooth LED Controller (HC-05 + Arduino)
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
    ├── Documentation Folder
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

> **Physical Hardware Only**
>
> - HC-05 Bluetooth Module
> - Android Smartphone with Bluetooth Terminal Application

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

Connect the **Red LED** to **Digital Pin 8** through a **220Ω resistor**.

### Step 2

Connect the **Green LED** to **Digital Pin 9** through a **220Ω resistor**.

### Step 3

Connect the **Blue LED** to **Digital Pin 10** through a **220Ω resistor**.

### Step 4

Connect the cathodes of all LEDs to the common **GND**.

### Step 5

Upload the program to the Arduino Uno.

### Step 6

Open the **Serial Monitor** and set the baud rate to **9600**.

### Step 7

Send the supported commands to simulate Bluetooth communication.

---

## Working Principle

The Arduino continuously listens for incoming command characters through the Serial Monitor. Each command represents a Bluetooth message that would normally be transmitted from an Android device through an HC-05 module. Depending on the received command, the corresponding LED operation is executed and the action is displayed on the Serial Monitor.

---

## HC-05 Pairing Instructions

> **Note:** These instructions apply when using a physical **HC-05 Bluetooth module**. In Wokwi, the Serial Monitor is used to simulate Bluetooth communication.

### Step 1

Connect the HC-05 module to the Arduino Uno.

### Step 2

Power the Arduino and wait until the HC-05 LED starts blinking.

### Step 3

Enable Bluetooth on your Android smartphone.

### Step 4

Search for available Bluetooth devices.

### Step 5

Select **HC-05** from the available devices.

### Step 6

Enter the default pairing PIN:

- **1234**
- **0000**

### Step 7

Open any Bluetooth Terminal application.

### Step 8

Connect to the paired HC-05 module.

### Step 9

Send the supported commands.

| Command | Operation |
|----------|-----------|
| **R** | Turn ON Red LED |
| **G** | Turn ON Green LED |
| **B** | Turn ON Blue LED |
| **X** | Turn OFF all LEDs |
| **F** | Flash all LEDs five times |

---

## Implementation Steps

### Step 1

Initialize Serial communication and configure all LED pins.

### Step 2

Wait for an incoming command.

### Step 3

Read and validate the received command.

### Step 4

Execute the corresponding LED operation.

### Step 5

Display the executed action on the Serial Monitor.

### Step 6

Continue monitoring for additional commands.

---

## Serial Monitor Output

```text
========================================
Bluetooth LED Controller
========================================

Command Received : R
Status : Red LED ON

----------------------------------------

Command Received : F
Status : Flashing LEDs

Flash Count : 1
Flash Count : 2
Flash Count : 3
Flash Count : 4
Flash Count : 5

Status : Flash Completed
```

---

## Code Explanation

### Serial Communication

Receives command characters from the Serial Monitor.

### Command Interpreter

Processes each received character and determines the requested operation.

### LED Control

Controls the Red, Green, and Blue LEDs individually.

### Flash Sequence

Blinks all three LEDs five consecutive times.

### Invalid Command Handling

Displays an error message whenever an unsupported command is received.

---

## Software Concepts Used

- Serial Communication
- Command-Based Programming
- Digital Output Control
- LED Interfacing
- Conditional Statements
- Looping
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
| Command X.png | All LEDs OFF command execution |
| Command F.png | Flash command execution |
| Invalid Command.png | Unsupported command demonstration |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469259890688126977

**Description**

This simulation demonstrates the complete functionality of a Bluetooth LED Controller using the Arduino Serial Monitor as a replacement for the HC-05 Bluetooth module. All commands defined in the original assignment are supported, making the implementation directly portable to physical hardware by replacing the Serial interface with Bluetooth communication.

---

## Learning Outcomes

- Bluetooth communication concepts
- Serial communication
- Command-driven embedded applications
- LED interfacing
- Digital output control
- Arduino programming
- Wireless device control fundamentals

---

## Best Practices

- Verify LED polarity before powering the circuit.
- Use current-limiting resistors for every LED.
- Maintain the Serial Monitor baud rate at **9600**.
- Send only supported commands for expected operation.
- Validate the Serial Monitor output during testing.

---

## Conclusion

The **Bluetooth LED Controller (HC-05 + Arduino)** introduces the fundamentals of wireless device control through command-based communication. Although the HC-05 module cannot be simulated in Wokwi, using the Serial Monitor preserves the complete application logic while providing a reliable testing environment. The project can be deployed on physical hardware by replacing the Serial interface with the HC-05 Bluetooth module without modifying the command-processing logic.
