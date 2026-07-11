# Q 31 – Bluetooth LED Controller (HC-05 + Arduino)

## Overview

This project demonstrates a simple wireless LED control system based on Bluetooth communication. Commands are received from a paired mobile device (simulated through the Serial Monitor in Wokwi) to control three LEDs individually or perform predefined actions. The project introduces the fundamentals of command-based communication used in many IoT and embedded automation systems.

> **Simulation Note:** Since **Wokwi does not support the HC-05 Bluetooth module**, Bluetooth communication is simulated using the **Arduino Serial Monitor**. The command set and program logic remain identical to the actual HC-05 implementation, allowing the same code to be used on physical hardware with minimal changes.

---

## Objectives

- Understand command-based communication.
- Control multiple LEDs using a single communication interface.
- Simulate Bluetooth command processing.
- Practice serial communication and digital output control.
- Develop a reusable command interpreter for embedded applications.

---

## Repository Structure

```text
Q31. Bluetooth LED Controller (HC-05 + Arduino)
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
│   ├── BT-LED-Controller.ino
│   └── README.md
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

## Supported Commands

| Command | Operation |
|----------|-----------|
| **R** | Turn ON the Red LED |
| **G** | Turn ON the Green LED |
| **B** | Turn ON the Blue LED |
| **X** | Turn OFF all LEDs |
| **F** | Flash all LEDs five times |

---

## Assets

| Asset | Description |
|--------|-------------|
| Hardware Setup | Complete circuit implementation used for the project |
| Demo Video | Demonstrates the complete functionality of the controller |
| Command R | Red LED activation |
| Command G | Green LED activation |
| Command B | Blue LED activation |
| Command X | All LEDs turned OFF |
| Command F | Flash sequence of all LEDs |
| Invalid Command | Response generated for unsupported commands |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469259890688126977

**Description**

This simulation replicates Bluetooth-controlled LED operation by accepting commands through the Arduino Serial Monitor. Each command triggers a predefined LED action, providing an effective substitute for HC-05 communication during simulation while preserving the original application logic.

---

## Future Enhancements

- Integrate an HC-05 module for real Bluetooth communication.
- Develop an Android application with dedicated control buttons.
- Support simultaneous control of multiple devices.
- Add PWM brightness control for each LED.
- Implement RGB color mixing using combined commands.
- Store command history for activity logging.
- Extend the system for wireless home automation applications.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
