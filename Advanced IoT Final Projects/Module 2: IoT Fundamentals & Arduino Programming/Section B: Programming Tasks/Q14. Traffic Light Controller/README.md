# Q 14 – Traffic Light Controller

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
/week2/traffic_light/traffic_light.ino
```

---

# Project Overview

The Traffic Light Controller is a basic embedded systems project that demonstrates digital output control, timing operations, and event-driven programming using Arduino.

Under normal conditions, the traffic signal follows a cyclic sequence of **RED → YELLOW → GREEN** with predefined timing intervals. A pedestrian push button allows users to request a safe road crossing. Whenever the button is pressed, the current traffic cycle is interrupted immediately, the RED signal is activated for **8 seconds**, and the normal sequence resumes afterward.

The project also continuously logs the active traffic light state along with the current execution time (`millis()`) to the Serial Monitor, making debugging and verification easier.

The project has been successfully developed and tested using the **Wokwi Online Simulator**, ensuring correct functionality before deployment on actual hardware. :contentReference[oaicite:0]{index=0}

---

# Features

- Automatic Traffic Light Sequencing
- Pedestrian Crossing Request
- Immediate Emergency RED Override
- 8-Second Pedestrian Safety Timer
- Real-Time Serial Monitor Logging
- Timestamp using `millis()`
- Modular Arduino Code
- Beginner-Friendly Logic
- Fully Compatible with Wokwi Simulator

---

# Project Structure

```text
Q14. Traffic Light Controller
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

The Assets folder contains all project demonstration files.

Included assets:

- Hardware setup screenshot
- RED signal screenshot
- YELLOW signal screenshot
- GREEN signal screenshot
- Pedestrian button request screenshot
- Complete demonstration video

These files provide visual proof of the successful implementation and testing of the Traffic Light Controller.

---

## Documentation

Contains detailed documentation explaining:

- Objective
- Hardware Components
- Circuit Connections
- Working Principle
- Program Flow
- Testing
- Troubleshooting
- Do's & Don'ts
- Future Scope

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
   - Current traffic cycle is interrupted.
   - RED LED immediately turns ON.
   - RED remains ON for **8 seconds**.
   - Normal traffic sequence resumes.
7. Every signal transition is logged to the Serial Monitor with its timestamp.

---

# Hardware Demonstration

The Traffic Light Controller has been successfully simulated and verified.

The repository includes:

- Hardware setup image
- RED signal demonstration
- YELLOW signal demonstration
- GREEN signal demonstration
- Pedestrian request demonstration
- Complete working video

These assets validate the complete operation of the project.

---

# Wokwi Simulation

The project has been designed, simulated, and verified using the **Wokwi Online Simulator**, allowing the complete traffic light system to be tested virtually before hardware implementation. Wokwi supports Arduino-based simulations directly in the browser without requiring physical components. :contentReference[oaicite:1]{index=1}

**Simulation Link:**

https://wokwi.com/projects/469047666148879361

---

# Project Highlights

- Complete Traffic Light Simulation
- Pedestrian Safety Feature
- Immediate RED Override
- Real-Time Timestamp Logging
- Modular Arduino Programming
- Wokwi Compatible
- Simple and Efficient Design

---

# Learning Outcomes

This project demonstrates practical implementation of:

- Arduino Programming
- Digital Output Control
- Push Button Interfacing
- LED Control
- Timing Operations
- Conditional Statements
- Event-Driven Programming
- Serial Communication
- Embedded System Fundamentals

---

# Future Enhancements

- Four-way Traffic Intersection
- Vehicle Density Detection
- Smart Traffic Management using IoT
- Emergency Vehicle Priority System
- LCD/OLED Signal Display
- Wireless Monitoring
- Automatic Night Mode
- Solar Powered Traffic Controller

---

# Repository Contents

This repository contains:

- Complete Arduino Source Code
- Project Documentation
- Hardware Setup Screenshot
- Traffic Signal Screenshots
- Pedestrian Request Screenshot
- Demonstration Video
- Wokwi Simulation Link

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
