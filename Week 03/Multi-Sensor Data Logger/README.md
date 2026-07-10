# Multi-Sensor Data Logger

## Overview

The **Multi-Sensor Data Logger** project was developed during **Week 03** of the **IoT Summer School 2026**. This project demonstrates how multiple sensors can be integrated with an Arduino Uno to acquire and log real-time environmental data in a structured format.

The system simultaneously collects **temperature**, **humidity**, **ambient light intensity**, and **distance** measurements using dedicated sensors. Every five seconds, the collected data is displayed on the Serial Monitor in a well-organized format, illustrating the fundamentals of multi-sensor interfacing, data acquisition, and embedded system programming.

> **Note:** The original assignment specifies the use of a **DHT11** sensor. However, the **DHT22** sensor was used in the Wokwi simulation because the DHT11 component was unavailable. Since both sensors use the same communication protocol and Arduino library, the functionality of the project remains unchanged while providing improved measurement accuracy.

---

## Project Highlights

- Simultaneous interfacing of multiple sensors.
- Temperature and humidity monitoring.
- Ambient light intensity measurement.
- Ultrasonic distance measurement.
- Structured sensor logging every five seconds.
- Real-time Serial Monitor output.
- Non-blocking execution using `millis()`.
- Compatible with Arduino Uno and Wokwi Simulator.

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| DHT22 Temperature & Humidity Sensor* | 1 |
| LDR Sensor Module | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

> *DHT22 is used in the simulation as a replacement for the DHT11.

---

## Software Requirements

- Arduino IDE
- DHT Sensor Library
- Wokwi Online Simulator

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

## Working Principle

The Arduino Uno continuously communicates with three sensors to collect environmental data. The DHT22 measures temperature and humidity, the LDR measures ambient light intensity, and the HC-SR04 ultrasonic sensor measures the distance to nearby objects.

The LDR reading is converted into a percentage and categorized as **Bright**, **Normal**, or **Dark**. Every five seconds, all sensor readings are formatted into a structured log and displayed on the Serial Monitor using non-blocking timing with the `millis()` function.

---

## Serial Output Format

```text
=== SENSOR LOG ===
Time : 12345 ms
Temp : 28.5 C | Humidity: 65%
Light : 73% (Bright)
Distance : 42 cm
==================
```

---

## Project Assets

This project includes:

- Hardware setup image
- DHT22 sensor reading
- LDR sensor reading
- Ultrasonic sensor reading
- Project demonstration video
- Sensor log file containing captured Serial Monitor output
- Arduino source code
- Detailed project documentation

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469191765522067457

**Description**

The project was successfully implemented and tested using the **Wokwi Online Simulator**. The simulation demonstrates the simultaneous acquisition of temperature, humidity, ambient light intensity, and distance measurements using a DHT22 sensor, LDR sensor, and HC-SR04 ultrasonic sensor.

The system collects data from all three sensors every **5 seconds**, converts the LDR reading into a percentage with brightness classification, measures the distance in centimeters, and displays all values in the required structured format on the Serial Monitor. The implementation uses the `millis()` function for non-blocking execution, ensuring continuous sensor monitoring while maintaining accurate periodic data logging.

---

## Applications

- Environmental Monitoring Systems
- Smart Agriculture
- IoT Data Acquisition
- Weather Monitoring
- Laboratory Experiments
- Smart Home Automation
- Educational IoT Projects

---

## Learning Outcomes

- Multi-sensor interfacing with Arduino
- Environmental data acquisition
- Temperature and humidity sensing
- Ambient light measurement
- Ultrasonic distance sensing
- Structured Serial communication
- Real-time sensor monitoring
- Non-blocking programming using `millis()`

---

## Future Improvements

- Integrate cloud-based IoT platforms.
- Store sensor logs on an SD card.
- Display readings on an OLED or LCD.
- Add Wi-Fi or Bluetooth connectivity.
- Include a Real-Time Clock (RTC) for actual timestamps.
- Develop a web dashboard for live data visualization.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. DHT Sensor Library Documentation
4. HC-SR04 Ultrasonic Sensor Datasheet
5. Wokwi Simulator – https://wokwi.com/

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
