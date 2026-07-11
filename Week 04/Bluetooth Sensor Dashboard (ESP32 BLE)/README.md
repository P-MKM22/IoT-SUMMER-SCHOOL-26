# Bluetooth LED Controller (HC-05 + Arduino)

## Overview

This project demonstrates a simple Bluetooth-based LED control system developed during **Week 04** of the **IoT Summer School 2026**. The objective is to understand wireless communication between a mobile device and an Arduino using command-based control. Due to the unavailability of the HC-05 module in Wokwi, Bluetooth communication is simulated using the Arduino Serial Monitor while preserving the original command protocol specified in the assignment.

---

## Objectives

- Understand Bluetooth-based wireless communication.
- Implement command-driven LED control.
- Simulate HC-05 communication using the Serial Monitor.
- Control multiple LEDs through predefined commands.
- Build a foundation for Bluetooth-enabled IoT applications.

---

## Repository Structure

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
    │   ├── BT_LED_Controller.ino
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## Features

- Individual LED control
- Command-based communication
- Serial Monitor simulation
- Easy migration to HC-05 hardware
- Arduino Uno compatible
- Wokwi compatible
- Simple and modular implementation

---

## Supported Commands

| Command | Function |
|----------|----------|
| **R** | Turn ON the Red LED |
| **G** | Turn ON the Green LED |
| **B** | Turn ON the Blue LED |
| **X** | Turn OFF all LEDs |
| **F** | Flash all LEDs five times |

---

## HC-05 Pairing Instructions

> **Note:** Wokwi does not currently support the HC-05 Bluetooth module. Therefore, this project uses the **Serial Monitor** to simulate Bluetooth communication. The following pairing instructions apply when implementing the project on physical hardware.

1. Connect the HC-05 module to the Arduino Uno.
2. Power the Arduino and wait until the HC-05 status LED begins blinking.
3. Enable Bluetooth on your Android smartphone.
4. Search for available Bluetooth devices.
5. Select **HC-05** from the list.
6. Pair the device using the default PIN:
   - **1234**
   - **0000**
7. Open any Bluetooth Terminal application.
8. Connect to the paired HC-05 module.
9. Send the supported commands (`R`, `G`, `B`, `X`, `F`) to control the LEDs.

---

## Assets

| Asset | Description |
|--------|-------------|
| Hardware Setup | Complete circuit implementation used for the project |
| Demo Video | Demonstration of the Bluetooth LED controller |
| Command R | Red LED control |
| Command G | Green LED control |
| Command B | Blue LED control |
| Command X | Turns OFF all LEDs |
| Command F | Flashes all LEDs five times |
| Invalid Command | Demonstrates unsupported command handling |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469259890688126977

**Description**

This simulation demonstrates a Bluetooth LED Controller using the Arduino Serial Monitor as a substitute for the HC-05 module. Users can send predefined commands to control individual LEDs or execute a flash sequence. The implementation preserves the original Bluetooth command protocol, making it directly portable to physical hardware.

---

## Future Enhancements

- Replace Serial communication with an HC-05 Bluetooth module.
- Develop a dedicated Android application for LED control.
- Add PWM brightness adjustment for each LED.
- Control multiple Bluetooth-enabled devices simultaneously.
- Integrate additional sensors and actuators.
- Expand the project into a Bluetooth-based home automation system.
- Support custom user-defined commands.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
