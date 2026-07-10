# Documentation of Question 24

## Overview

This document provides the complete technical documentation for the **Multi-Sensor Data Logger** project developed as part of the **Advanced IoT Final Projects** under **Module 3: Sensors, Actuators & Data Acquisition** during the **IoT and Drone Building Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

The project demonstrates simultaneous acquisition of environmental data using three different sensors: **DHT11/DHT22** for temperature and humidity, **LDR** for ambient light intensity, and **HC-SR04** for distance measurement. Every five seconds, the Arduino collects data from all sensors and displays it in a structured format on the Serial Monitor.

---

## Documentation Contents

- Project Overview
- Hardware Components
- Circuit Configuration
- Pin Configuration
- Working Principle
- Step-by-Step Implementation
- Output Format
- Code Explanation
- Software Concepts Used
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- References

---

## Project Structure

```text
Advanced IoT Final Projects
│
└── Module 3: Sensors, Actuators & Data Acquisition
    │
    └── Section A: Sensor Experiments
        │
        └── Q24. Multi-Sensor Data Logger
            │
            ├── Assets
            │   ├── .gitkeep
            │   ├── DHT22 reading.png
            │   ├── LDR reading.png
            │   ├── Multi Sensor Data logger hardware setup.png
            │   ├── Multi-Sensor Data Logger demo.mp4
            │   └── Ultrasonic reading.png
            │
            ├── Code
            │   └── MSDL.ino
            │
            ├── Data
            │   └── sensor_log.txt
            │
            ├── Documentation Folder
            │   └── README.md
            │
            └── README.md
```

---

## Hardware Components

- Arduino Uno
- DHT11 / DHT22 Temperature & Humidity Sensor
- LDR Sensor Module
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| DHT Sensor Data | D7 |
| LDR Analog Output | A0 |
| HC-SR04 Trigger | D9 |
| HC-SR04 Echo | D10 |

---

## Circuit Configuration

- Connect the DHT sensor VCC to **5V**, GND to **GND**, and DATA to **Digital Pin 7**.
- Connect the LDR module VCC to **5V**, GND to **GND**, and Analog Output to **A0**.
- Connect the HC-SR04 VCC to **5V**, GND to **GND**, TRIG to **D9**, and ECHO to **D10**.
- Power all sensors using the Arduino Uno 5V supply.

---

## Working Principle

The Arduino simultaneously reads data from three sensors. The DHT sensor measures ambient temperature and humidity, the LDR measures light intensity, and the HC-SR04 determines the distance to nearby objects.

The raw LDR value is converted into a percentage and categorized as **Bright**, **Normal**, or **Dark**. Every five seconds, all sensor values are collected and displayed in a structured format on the Serial Monitor. The timing is managed using the `millis()` function to ensure non-blocking execution.

---

## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect all sensors according to the specified pin configuration.

---

### Step 2: Configure the DHT Sensor

Initialize the DHT library and configure the sensor for temperature and humidity measurement.

---

### Step 3: Configure the LDR Sensor

Connect the analog output of the LDR sensor to **A0** for continuous light intensity measurement.

---

### Step 4: Configure the Ultrasonic Sensor

Connect the Trigger and Echo pins of the HC-SR04 to **D9** and **D10** respectively.

---

### Step 5: Upload the Program

Upload the `MSDL.ino` sketch using Arduino IDE and open the Serial Monitor at **9600 baud**.

---

### Step 6: Read Sensor Values

Every five seconds the Arduino reads:

- Temperature
- Humidity
- Light intensity
- Distance

---

### Step 7: Convert Light Intensity

Convert the raw LDR value into a percentage and determine whether the environment is **Bright**, **Normal**, or **Dark**.

---

### Step 8: Display Sensor Log

Display all readings in the required structured format.

Example:

```text
=== SENSOR LOG ===
Time : 12345 ms
Temp : 28.5 C | Humidity: 65%
Light : 73% (Bright)
Distance : 42 cm
==================
```

---

### Step 9: Save Serial Output

Capture at least **20 consecutive sensor logs** and save them as:

```text
sensor_log.txt
```

inside the **Data** folder.

---

## Output Format

```text
=== SENSOR LOG ===
Time : 12345 ms
Temp : 28.5 C | Humidity: 65%
Light : 73% (Bright)
Distance : 42 cm
==================
```

---

## Code Explanation

### DHT Sensor

Reads ambient temperature and humidity values using the DHT library.

### LDR Sensor

Reads the analog value and converts it into a percentage representing ambient light intensity.

### HC-SR04 Sensor

Measures the distance of nearby objects using ultrasonic pulses and calculates the distance in centimeters.

### Structured Logging

Displays all collected sensor data in the assignment-specified format every five seconds.

### Non-Blocking Timing

The `millis()` function is used to maintain a 5-second logging interval without stopping program execution.

---

## Software Concepts Used

- Analog Input
- Digital Input
- Ultrasonic Distance Measurement
- DHT Sensor Library
- Data Formatting
- Serial Communication
- Sensor Integration
- Non-Blocking Programming using `millis()`

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Multi Sensor Data logger hardware setup.png | Complete hardware setup |
| DHT22 reading.png | Temperature and humidity reading |
| LDR reading.png | Ambient light reading |
| Ultrasonic reading.png | Distance measurement |
| Multi-Sensor Data Logger demo.mp4 | Project demonstration |
| sensor_log.txt | Captured Serial Monitor output |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469191765522067457

**Description**

The Wokwi simulation demonstrates simultaneous acquisition of temperature, humidity, ambient light intensity, and distance measurements. The project successfully validates structured data logging every five seconds using non-blocking timing while integrating multiple sensors on a single Arduino Uno.

---

## Learning Outcomes

- Multi-sensor interfacing
- Temperature and humidity measurement
- Ambient light sensing
- Ultrasonic distance measurement
- Structured data logging
- Serial communication
- Sensor data formatting
- Non-blocking programming using `millis()`

---

## Best Practices

- Verify sensor wiring before uploading the program.
- Use `millis()` instead of `delay()` for periodic tasks.
- Calibrate the LDR according to ambient lighting conditions.
- Keep sensor connections secure to avoid unstable readings.
- Validate Serial Monitor output before saving the sensor log.
- Organize project files into Assets, Code, Data, and Documentation folders.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. DHT Sensor Library Documentation
4. HC-SR04 Ultrasonic Sensor Datasheet
5. Wokwi Simulator – https://wokwi.com/

---

## Conclusion

The **Multi-Sensor Data Logger** project demonstrates effective integration of multiple sensors into a single embedded system for real-time environmental monitoring. By combining temperature, humidity, light intensity, and distance measurements into a structured logging system using non-blocking programming, the project highlights fundamental IoT concepts related to sensor interfacing, data acquisition, and serial communication, making it a strong foundation for advanced monitoring and automation applications.
