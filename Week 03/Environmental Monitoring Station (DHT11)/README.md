# Environmental Monitoring Station (DHT11)

## Overview

The **Environmental Monitoring Station (DHT11)** project is part of **Week 03** of the **IoT and Drone Building Summer School 2026** conducted by the Indian Institute of Technology Jammu (IIT Jammu). The project demonstrates real-time environmental monitoring using an ESP32 and a DHT sensor by measuring temperature and humidity, displaying the readings in CSV format, and indicating environmental conditions using LEDs.

> **Note:** Wokwi provides the DHT22 sensor instead of the DHT11. Therefore, the DHT22 has been used for simulation while maintaining the same implementation logic required by the assignment.

---

## Purpose of the Directory

This directory contains all resources required for **Question 21 – Environmental Monitoring Station (DHT11)**, including the Arduino source code, project documentation, simulation assets, and recorded CSV sensor readings.

---

## Folder Hierarchy

```text
Week 03
│
├── README.md
│
└── Environmental Monitoring Station (DHT11)
    │
    ├── Assets
    │   ├── Hardware Connection.png
    │   ├── Serial Monitor Output.png
    │   ├── Normal Condition.png
    │   ├── High Temperature Alert.png
    │   └── High Humidity Alert.png
    │
    ├── Code
    │   └── Environmental_Monitoring_Station.ino
    │
    ├── Data
    │   └── sample_readings.csv
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## Directory Contents

### Assets

Contains screenshots demonstrating:

- Hardware connections.
- Serial Monitor CSV output.
- Normal environmental conditions.
- High temperature alert.
- High humidity alert.

### Code

Contains the complete Arduino program implementing the Environmental Monitoring Station using the ESP32 and DHT sensor.

### Data

Contains the `sample_readings.csv` file with environmental sensor readings recorded during the Wokwi simulation.

### Documentation

Contains detailed technical documentation, including implementation details, execution steps, working principle, expected output, code explanation, and references.

---

## Concepts Covered

- ESP32 Programming
- DHT Sensor Interfacing
- Temperature Monitoring
- Humidity Monitoring
- Celsius to Fahrenheit Conversion
- CSV Data Logging
- GPIO Programming
- LED-Based Status Indication
- Wokwi Simulation
- Embedded IoT Systems

---

## Skills Learned

- Interfacing environmental sensors with ESP32.
- Reading and processing sensor data.
- Converting temperature units programmatically.
- Implementing threshold-based LED indication.
- Recording structured sensor data in CSV format.
- Organizing embedded system projects using a professional GitHub structure.

---

## Expected Learning Outcomes

After completing this project, learners will be able to:

- Interface DHT sensors with ESP32.
- Monitor temperature and humidity in real time.
- Generate CSV-formatted sensor logs.
- Implement GPIO-based output control.
- Simulate embedded systems using Wokwi.
- Develop well-structured IoT projects with complete documentation.

---

## Relationship with Week 03

This project is one of the practical implementations completed during **Week 03**. It focuses on sensor interfacing, environmental monitoring, real-time data acquisition, and structured data logging using the ESP32 platform.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
