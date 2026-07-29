# Week 04 – Drone Control Systems, Flight Stabilization, and Control Algorithms

## Overview

Week 04 focused on advanced concepts in drone technology, including flight control systems, stabilization techniques, autonomous navigation, and control algorithms. The learning sessions explored how modern drones maintain stable flight using controllers, sensor fusion, navigation systems, and mission planning software. In addition to theoretical concepts, practical activities were carried out on wireless communication projects using ESP32, providing hands-on experience in implementing IoT-based applications.

---

## Learning Objectives

- Understand the fundamentals of drone flight control systems.
- Learn how flight stabilization is achieved in multirotor drones.
- Study Mission Planner software and its applications.
- Understand different drone flight modes and failsafe mechanisms.
- Learn the North-East-Down (NED) coordinate system.
- Explore PID and Bang-Bang control algorithms.
- Understand the role of the Extended Kalman Filter (EKF).
- Study drone thrust generation and flight stability.
- Develop practical IoT applications using ESP32 and wireless communication.

---

## Topics Covered

### 1. Mission Planner Software

- Introduction to Mission Planner
- Drone configuration
- Flight monitoring
- Mission planning
- Parameter tuning

### 2. Flight Modes

- Stabilize Mode
- Position Hold (Pos Hold)
- Altitude Hold (Alt Hold)
- Land Mode
- Return to Launch (RTL)
- Return to Home (RTH)

### 3. Failsafe Mechanisms

- Battery Failsafe
- GPS Failsafe
- Radio Signal Loss Failsafe
- Automatic Return-to-Home
- Emergency Landing

### 4. NED Coordinate System

Understanding the navigation reference frame used in drones.

- X-axis → North
- Y-axis → East
- Z-axis → Down

Applications:

- Drone navigation
- Position estimation
- Autonomous flight

### 5. Drone Thrust and Stability

- BLDC motor thrust generation
- Relationship between thrust and weight
- Ascending (Thrust > Weight)
- Hovering (Thrust = Weight)
- Descending (Thrust < Weight)

### 6. Under-Actuated Drone System

- Understanding under-actuated systems
- Quadcopter stability
- Continuous feedback control
- Fast control loops

### 7. Flight Control Response

- Human reaction time
- Drone controller response
- Importance of real-time control

### 8. Extended Kalman Filter (EKF)

- Sensor fusion
- State estimation
- Position estimation
- Orientation estimation

### 9. PID Controller

- Proportional Control
- Integral Control
- Derivative Control
- Roll, Pitch and Yaw stabilization

### 10. Bang-Bang Controller

- ON/OFF control algorithm
- Threshold-based switching
- Basic automatic control applications

### 11. Battery and Motor Management

- Battery monitoring
- Power distribution
- Motor synchronization
- Efficient power utilization

---

## Practical Activities

The following practical projects were completed during Week 04:

| Project | Description |
|---------|-------------|
| Bluetooth LED Controller (HC-05 + Arduino) | Controlled an LED wirelessly using Bluetooth communication between an HC-05 module and Arduino. |
| Bluetooth Sensor Dashboard (ESP32 BLE) | Developed a Bluetooth Low Energy (BLE) dashboard for wireless sensor data transmission using ESP32. |
| Wi-Fi Temperature Monitor (ESP8266 or ESP32) | Created a browser-based IoT dashboard to monitor temperature and humidity over a Wi-Fi network with remote LED control. |

---

## Repository Structure

```text
Week 04
│
├── Bluetooth LED Controller (HC-05 + Arduino)
│
├── Bluetooth Sensor Dashboard (ESP32 BLE)
│
├── Wi-Fi Temperature Monitor (ESP8266 or ESP32)
│
└── README.md
```

---

## Tools & Software Used

- Mission Planner
- Arduino IDE
- ESP32 Development Board
- HC-05 Bluetooth Module
- ESP32 BLE
- DHT11 Sensor
- GPS Module
- Flight Controller
- BLDC Motors
- ESC
- LiPo Battery

---

## Skills Acquired

- Drone Flight Control
- Flight Stabilization
- Autonomous Navigation
- Mission Planning
- PID Controller Fundamentals
- Extended Kalman Filter
- NED Coordinate System
- Wireless Communication
- Bluetooth Communication
- Wi-Fi Communication
- IoT Dashboard Development
- Embedded Systems Programming

---

## Learning Outcomes

By the end of Week 04, I was able to:

- Understand drone flight control systems.
- Configure and study Mission Planner software.
- Explain various drone flight modes and failsafe mechanisms.
- Understand the NED coordinate system.
- Explain drone thrust generation and stability.
- Understand PID and Bang-Bang control algorithms.
- Learn the importance of EKF in autonomous navigation.
- Develop Bluetooth-based embedded applications.
- Build Wi-Fi-enabled IoT monitoring systems using ESP32.
- Apply wireless communication concepts to real-world IoT applications.

---

## Summary

Week 04 provided comprehensive exposure to advanced drone control concepts and wireless communication technologies. The theoretical sessions introduced flight stabilization, autonomous navigation, Mission Planner, EKF, PID controllers, and failsafe mechanisms, while the practical sessions focused on implementing Bluetooth and Wi-Fi-based IoT applications using ESP32. Together, these activities strengthened both the theoretical understanding and practical implementation skills required for modern drone and IoT system development.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
