# Traffic Light Controller

## Problem Statement

Design and implement an Arduino-based **Traffic Light Controller** that simulates a real-world traffic signal using three LEDs (Red, Yellow, and Green). The system should also include a **pedestrian crossing button** that immediately interrupts the normal traffic sequence, switches the signal to **RED**, and keeps it ON for **8 seconds** to allow pedestrians to cross safely.

---

# Task Requirements

The project has been implemented according to the following specifications:

- Simulate a traffic light using **3 LEDs**
- **RED LED ON for 5 seconds**
- **YELLOW LED ON for 2 seconds**
- **GREEN LED ON for 4 seconds**
- Push button connected to **Arduino Pin 7**
- Immediately force the **RED signal** when the button is pressed
- Hold the RED signal for **8 seconds**
- Print the active traffic light state with **timestamp (`millis()`)** in the Serial Monitor
- Arduino source code stored as:

```text
Week 02/
└── Traffic Light Controller/
    └── Code/
        └── traffic_light.ino
```

---

# Project Overview

The Traffic Light Controller is an Arduino-based embedded systems project that demonstrates digital output control, timing operations, and event-driven programming. Three LEDs are used to represent the **Red**, **Yellow**, and **Green** traffic signals.

During normal operation, the traffic lights follow a continuous sequence of **RED → YELLOW → GREEN** according to the specified timings. A pedestrian push button allows users to request road crossing at any time. When pressed, the system immediately interrupts the current traffic sequence, activates the RED signal for **8 seconds**, and then resumes the normal traffic cycle.

The current traffic light state along with its execution timestamp (`millis()`) is continuously displayed on the Serial Monitor for monitoring and debugging purposes.

The project has been successfully developed and tested using the **Wokwi Online Simulator** and organized according to the Week 02 repository structure.

---

# Features

- Automatic Traffic Light Sequencing
- Pedestrian Crossing Request
- Immediate RED Override
- 8-Second Pedestrian Crossing Timer
- Real-Time Serial Monitor Logging
- Timestamp using `millis()`
- Modular Arduino Program
- Beginner-Friendly Implementation
- Fully Compatible with Wokwi Simulator

---

# Folder Structure

```text
Week 02
│
└── Traffic Light Controller
    │
    ├── Assets
    │   ├── Traffic Light Controller Hardware setup.png
    │   ├── Traffic Light Controller Red signal.png
    │   ├── Traffic Light Controller Yellow signal.png
    │   ├── Traffic Light Controller Green signal.png
    │   ├── Traffic Light Controller Push Request.png
    │   └── Traffic Light Controller Demo.mp4
    │
    ├── Code
    │   └── traffic_light.ino
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

# Folder Description

## Code

Contains the complete Arduino program (`traffic_light.ino`) responsible for:

- Traffic light sequencing
- LED control
- Pedestrian button detection
- RED signal override
- Serial Monitor logging

---

## Assets

The Assets folder contains all demonstration files related to the project.

Included files:

- Hardware setup screenshot
- RED signal screenshot
- YELLOW signal screenshot
- GREEN signal screenshot
- Pedestrian request screenshot
- Complete working demonstration video

These files provide visual evidence of the successful implementation and testing of the Traffic Light Controller.

---

## Documentation

Contains comprehensive project documentation including:

- Project Objective
- Problem Statement
- Hardware Components
- Circuit Connections
- Working Principle
- Program Flow
- Testing Procedure
- Troubleshooting Guide
- Do's and Don'ts
- Future Enhancements

---

# Hardware Components Used

| Component | Quantity |
|-----------|---------:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| Push Button | 1 |
| 220Ω Resistors | 3 |
| 10kΩ Pull-down Resistor | 1 |
| Jumper Wires | As Required |

---

# Software Used

- Arduino IDE
- Wokwi Online Simulator
- GitHub

---

# Functional Workflow

1. Arduino initializes all LEDs and the push button.
2. RED LED turns ON for **5 seconds**.
3. YELLOW LED turns ON for **2 seconds**.
4. GREEN LED turns ON for **4 seconds**.
5. The sequence repeats continuously.
6. If the pedestrian button is pressed:
   - The current traffic sequence is interrupted.
   - RED LED immediately turns ON.
   - RED remains ON for **8 seconds**.
   - The normal traffic cycle resumes automatically.
7. Each traffic signal transition is logged in the Serial Monitor with its timestamp.

---

# Hardware Demonstration

The project has been successfully simulated and verified.

The repository contains:

- Hardware setup screenshot
- RED signal demonstration
- YELLOW signal demonstration
- GREEN signal demonstration
- Pedestrian request demonstration
- Complete demonstration video

These assets validate the correct operation of the Traffic Light Controller.

---

# Wokwi Simulation

The project has been designed, simulated, and verified using the **Wokwi Online Simulator**.

**Simulation Link**

https://wokwi.com/projects/469047666148879361

---

# Project Highlights

- Complete Traffic Light Simulation
- Pedestrian Safety Mechanism
- Immediate RED Signal Override
- Timestamp Logging using `millis()`
- Modular Arduino Code
- Wokwi Compatible Design
- Easy to Understand Implementation

---

# Learning Outcomes

This project demonstrates practical implementation of:

- Arduino Programming
- Digital Output Control
- LED Interfacing
- Push Button Interfacing
- Traffic Signal Logic
- Conditional Programming
- Timing Operations
- Event-Driven Programming
- Serial Communication
- Embedded System Fundamentals

---

# Future Enhancements

- Four-Way Traffic Intersection
- Vehicle Density Detection
- Smart Traffic Management
- Emergency Vehicle Priority
- LCD/OLED Status Display
- IoT-Based Traffic Monitoring
- Automatic Night Mode
- Solar-Powered Traffic Controller

---

# Repository Contents

This repository includes:

- Arduino Source Code
- Documentation
- Hardware Setup Screenshot
- RED Signal Screenshot
- YELLOW Signal Screenshot
- GREEN Signal Screenshot
- Pedestrian Request Screenshot
- Demonstration Video
- Wokwi Simulation Link

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
