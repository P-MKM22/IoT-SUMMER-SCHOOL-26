# Documentation of Q 24

## Multi-Sensor Data Logger

### Overview

The **Multi-Sensor Data Logger** project is developed as part of the **Advanced IoT Final Projects** under **Module 3: Sensors, Actuators & Data Acquisition**, **Section A: Sensor Experiments**, during the **IoT and Drone Building Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

This project demonstrates simultaneous acquisition of **temperature**, **humidity**, **ambient light intensity**, and **distance** using multiple sensors. The collected data is displayed in a structured format on the Serial Monitor every **5 seconds**, illustrating real-time data acquisition and multi-sensor interfacing.

> **Note:** The assignment specifies the use of a **DHT11** sensor. However, the **DHT22** sensor was used in the Wokwi simulation because DHT11 was unavailable. Since both sensors use the same communication protocol and Arduino library, the project functions identically while providing better measurement accuracy.

---

## Documentation Contents

- Project Overview
- Hardware Components
- Pin Configuration
- Circuit Configuration
- Working Principle
- Step-by-Step Implementation
- Serial Output
- Code Explanation
- Software Concepts Used
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- References
- Conclusion

---

## Project Structure

```text
Module 3: Sensors, Actuators & Data Acquisition
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
- DHT22 Temperature & Humidity Sensor*
- LDR Sensor Module
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires

> *Used as a replacement for DHT11 in the simulation.

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 Data | D7 |
| LDR Output | A0 |
| HC-SR04 Trigger | D9 |
| HC-SR04 Echo | D10 |

---

## Circuit Configuration

- Connect the DHT22 data pin to **D7**.
- Connect the LDR analog output to **A0**.
- Connect the HC-SR04 Trigger and Echo pins to **D9** and **D10**.
- Connect all sensors to **5V** and **GND** using a common ground.

---

## Working Principle

The Arduino reads data from the DHT22, LDR, and HC-SR04 sensors simultaneously. The LDR value is converted into a percentage and categorized as **Bright**, **Normal**, or **Dark**, while the ultrasonic sensor measures distance in centimeters. Every **5 seconds**, all readings are formatted and displayed on the Serial Monitor using non-blocking timing with the `millis()` function.

---

## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect the Arduino Uno and all sensors according to the pin configuration.

### Step 2: Initialize Sensors

Initialize the DHT sensor library and configure the ultrasonic sensor pins.

### Step 3: Read Sensor Values

Acquire temperature, humidity, light intensity, and distance readings.

### Step 4: Process the Data

Convert the LDR reading into a percentage and calculate the ultrasonic distance.

### Step 5: Display Output

Print all sensor readings in the required structured format every five seconds.

### Step 6: Save the Log

Capture at least **20 Serial Monitor outputs** and save them as **sensor_log.txt** inside the **Data** folder.

---

## Serial Output

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

- Initializes all sensors.
- Reads temperature and humidity.
- Reads and converts LDR values.
- Calculates ultrasonic distance.
- Formats sensor readings.
- Displays structured output every five seconds using `millis()`.

---

## Software Concepts Used

- Multi-Sensor Interfacing
- Analog Input Processing
- Digital Sensor Reading
- Environmental Monitoring
- Distance Measurement
- Structured Data Logging
- Serial Communication
- Non-Blocking Programming using `millis()`

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Multi Sensor Data logger hardware setup.png | Circuit setup |
| DHT22 reading.png | Temperature and humidity output |
| LDR reading.png | Light intensity output |
| Ultrasonic reading.png | Distance measurement |
| Multi-Sensor Data Logger demo.mp4 | Working demonstration |
| sensor_log.txt | Captured Serial Monitor output |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469191765522067457

**Description**

The simulation demonstrates simultaneous acquisition of temperature, humidity, ambient light intensity, and distance measurements. Sensor values are processed every **5 seconds** and displayed in the required structured format using non-blocking programming with the `millis()` function.

---

## Learning Outcomes

- Multi-sensor interfacing
- Environmental monitoring
- Analog and digital sensor processing
- Structured data logging
- Serial communication
- Non-blocking programming

---

## Best Practices

- Verify all sensor connections.
- Use a common ground.
- Calibrate the LDR if required.
- Validate sensor readings before recording logs.
- Organize project files into their respective folders.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference
3. DHT Sensor Library Documentation
4. HC-SR04 Ultrasonic Sensor Datasheet
5. Wokwi Simulator – https://wokwi.com/

---

## Conclusion

The **Multi-Sensor Data Logger** project demonstrates efficient integration of multiple sensors into a single embedded system. It provides practical experience in environmental monitoring, structured data logging, sensor interfacing, and non-blocking programming, forming a strong foundation for advanced IoT monitoring applications.
