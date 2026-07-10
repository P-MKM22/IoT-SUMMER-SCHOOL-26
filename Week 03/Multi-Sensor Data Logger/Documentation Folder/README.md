# Documentation of Multi-Sensor Data Logger

## Overview

This document provides the complete technical documentation for the **Multi-Sensor Data Logger** project developed during **Week 03** of the **IoT Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

The project demonstrates real-time acquisition of environmental data by integrating multiple sensors with an Arduino Uno. It simultaneously measures **temperature**, **humidity**, **ambient light intensity**, and **distance**, then logs the collected data in a structured format every five seconds using non-blocking programming with `millis()`.

> **Note:** The original assignment specifies the use of a **DHT11** sensor. However, this implementation uses a **DHT22** sensor in the Wokwi simulation because the DHT11 component was unavailable. Both sensors are supported by the same Arduino library and communication protocol, ensuring identical functionality for this project while providing higher measurement accuracy.

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
Week 03
│
└── Multi-Sensor Data Logger
    │
    ├── Assets
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
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## Hardware Components

- Arduino Uno
- DHT22 Temperature & Humidity Sensor *(used in place of DHT11)*
- LDR Sensor Module
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 Data | D7 |
| LDR Analog Output | A0 |
| HC-SR04 Trigger | D9 |
| HC-SR04 Echo | D10 |

---

## Circuit Configuration

- Connect the DHT22 sensor VCC to **5V**, GND to **GND**, and DATA to **Digital Pin 7**.
- Connect the LDR module VCC to **5V**, GND to **GND**, and Analog Output to **A0**.
- Connect the HC-SR04 sensor VCC to **5V**, GND to **GND**, TRIG to **D9**, and ECHO to **D10**.
- Ensure all sensors share a common ground with the Arduino Uno.

---

## Working Principle

The Arduino Uno continuously collects data from three sensors operating simultaneously.

The DHT22 measures the surrounding temperature and humidity, the LDR measures ambient light intensity, and the HC-SR04 ultrasonic sensor measures the distance to nearby objects.

The raw LDR reading is converted into a percentage and classified as **Bright**, **Normal**, or **Dark**. Every five seconds, the Arduino formats all sensor readings into a structured log and displays them on the Serial Monitor. The timing mechanism is implemented using the `millis()` function, allowing continuous sensor monitoring without blocking program execution.

---

## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect the Arduino Uno, DHT22 sensor, LDR module, and HC-SR04 ultrasonic sensor according to the specified pin configuration.

---

### Step 2: Configure the DHT Sensor

Initialize the DHT library and configure the sensor to read temperature and humidity values.

---

### Step 3: Configure the LDR Sensor

Connect the LDR analog output to **A0** for continuous monitoring of ambient light intensity.

---

### Step 4: Configure the Ultrasonic Sensor

Connect the Trigger and Echo pins of the HC-SR04 to **D9** and **D10**, respectively.

---

### Step 5: Upload the Program

Upload the `MSDL.ino` sketch to the Arduino Uno and open the Serial Monitor at **9600 baud**.

---

### Step 6: Read Sensor Values

Every five seconds, the Arduino reads:

- Temperature
- Humidity
- Ambient Light Intensity
- Distance

---

### Step 7: Process Sensor Data

- Convert the LDR analog reading into a percentage.
- Classify the light level as **Bright**, **Normal**, or **Dark**.
- Calculate the ultrasonic distance in centimeters.

---

### Step 8: Display Structured Sensor Log

The Arduino prints all sensor readings in the required assignment format.

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

### Step 9: Capture Serial Output

Record at least **20 consecutive sensor logs** from the Serial Monitor and save them as:

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

### Sensor Initialization

The DHT library is initialized, and the ultrasonic sensor pins are configured for distance measurement.

### Temperature and Humidity Measurement

The DHT22 sensor provides real-time temperature and humidity readings.

### Ambient Light Measurement

The Arduino reads the analog output of the LDR sensor, converts it into a percentage, and classifies the surrounding light level.

### Distance Measurement

The HC-SR04 calculates the distance using ultrasonic pulse timing and converts it into centimeters.

### Structured Data Logging

Every five seconds, all sensor readings are organized into a structured format for easy monitoring and analysis.

### Non-Blocking Timing

The project uses the `millis()` function instead of `delay()`, allowing continuous execution while maintaining periodic sensor logging.

---

## Software Concepts Used

- Multi-Sensor Interfacing
- Analog Input Processing
- Digital Input Processing
- Temperature & Humidity Monitoring
- Ultrasonic Distance Measurement
- Data Formatting
- Serial Communication
- Non-Blocking Programming using `millis()`

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Multi Sensor Data logger hardware setup.png | Hardware setup of the project |
| DHT22 reading.png | Temperature and humidity output |
| LDR reading.png | Ambient light measurement |
| Ultrasonic reading.png | Distance measurement |
| Multi-Sensor Data Logger demo.mp4 | Complete project demonstration |
| sensor_log.txt | Captured Serial Monitor output |

---

## Wokwi Simulation

The Wokwi simulation demonstrates the complete implementation of the Multi-Sensor Data Logger, including simultaneous sensor interfacing, structured Serial Monitor output, periodic data logging every five seconds, and non-blocking execution using the `millis()` function.

---

## Learning Outcomes

- Multi-sensor interfacing using Arduino Uno
- Temperature and humidity monitoring
- Ambient light sensing
- Ultrasonic distance measurement
- Environmental data acquisition
- Structured Serial communication
- Real-time sensor monitoring
- Non-blocking embedded programming

---

## Best Practices

- Verify all sensor connections before uploading the program.
- Use `millis()` instead of `delay()` for periodic tasks.
- Calibrate the LDR according to ambient lighting conditions.
- Keep sensor wiring secure to ensure stable readings.
- Validate Serial Monitor output before saving the log file.
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

The **Multi-Sensor Data Logger** project demonstrates the integration of multiple sensors into a single embedded system for real-time environmental monitoring. By combining temperature, humidity, light intensity, and distance measurements into a structured logging system, the project highlights essential IoT concepts such as sensor interfacing, data acquisition, serial communication, and non-blocking programming. It serves as a strong foundation for developing more advanced IoT monitoring and automation systems.
