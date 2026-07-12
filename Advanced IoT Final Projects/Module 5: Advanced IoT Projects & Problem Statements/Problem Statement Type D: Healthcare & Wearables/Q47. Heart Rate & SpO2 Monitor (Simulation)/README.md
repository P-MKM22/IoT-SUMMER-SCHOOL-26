# Q 47 – Heart Rate & SpO₂ Monitor (Simulation)

## Overview

This project presents a simulated Smart Health Monitoring System developed using the ESP32 platform. It demonstrates how embedded systems can be used for continuous health monitoring by combining environmental sensing, wearable healthcare concepts, real-time visualization, and emergency alert mechanisms.

The project is designed as a simulation prototype that can later be extended to real healthcare hardware with minimal software modifications.

## Purpose

The objective of this project is to demonstrate the design and implementation of a wearable healthcare monitoring system capable of:

- Monitoring body temperature.
- Simulating Heart Rate and SpO₂ measurements.
- Detecting fall events.
- Providing visual and audible alerts.
- Displaying live health information.
- Recording health data for future analysis.

## Project Highlights

- ESP32-based healthcare monitoring prototype.
- Real-time OLED dashboard.
- Simulated Heart Rate and SpO₂ monitoring.
- Fall detection using MPU6050.
- Emergency indication using LEDs and buzzer.
- CSV health data logging.
- Fully compatible with the Wokwi simulator.

## Repository Contents

This directory contains all resources required to understand, execute, and evaluate the project.

## Project Structure

```text
IoT-SUMMER-SCHOOL-26
│
├── Advanced IoT Final Projects
│
└── Module 5: Advanced IoT Projects & Problem Statements
    │
    └── Problem Statement Type D: Healthcare & Wearables
        │
        └── Q47. Heart Rate & SpO₂ Monitor (Simulation)
            │
            ├── Assets
            │   ├── Emergency button pressed.png
            │   ├── Fall status detected.png
            │   ├── Heart Rate & SpO₂ Monitor demo part 01.mp4
            │   ├── Heart Rate & SpO₂ Monitor demo part 02.mp4
            │   ├── Heart Rate & SpO₂ Monitor hardware setup.png
            │   ├── Heart Rate & SpO₂ Monitor.png
            │   ├── High BPM detected.png
            │   ├── High temperature detected.png
            │   ├── Normal State of all health condition.png
            │   └── SpO₂ level decreasing.png
            │
            ├── Code
            │   └── Health_monitor.ino
            │
            ├── Data
            │   └── Health_log.csv
            │
            ├── Documentation Folder
            │   └── README.md
            │
            └── README.md
```

### Folder Description

| Folder | Purpose |
|---------|---------|
| Assets | Project screenshots, hardware setup images, and demonstration videos. |
| Code | Arduino source code for the complete implementation. |
| Data | Sample health readings stored in CSV format. |
| Documentation Folder | Detailed implementation guide, hardware connections, execution procedure, and technical explanation. |

## Simulation Notes

The project has been developed entirely in the Wokwi simulator. Since certain healthcare components are currently unavailable in the simulator, equivalent components have been used to demonstrate the complete application logic.

| Original Requirement | Simulation Component |
|----------------------|----------------------|
| DHT11 | DHT22 |
| MAX30102 Pulse Oximeter | Potentiometer (SpO₂ Simulation) |
| Heart Rate Sensor | Potentiometer (Heart Rate Simulation) |
| Fall Detection Module | MPU6050 |

These substitutions preserve the intended functionality while keeping the project fully executable in Wokwi.

## Included Resources

The project repository includes:

- Complete Arduino source code
- Hardware wiring reference
- Wokwi simulation
- Demonstration videos
- Output screenshots
- Sample CSV health log
- Technical documentation
- GitHub-ready project structure

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469341476730397697

The simulation demonstrates live monitoring of temperature, simulated Heart Rate, simulated SpO₂, fall detection, OLED visualization, LED indication, buzzer alerts, and CSV-based health data logging.

## References

- ESP32 Arduino Documentation
- Wokwi Documentation
- Adafruit SSD1306 Library
- Adafruit MPU6050 Library
- DHTesp Library Documentation

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
