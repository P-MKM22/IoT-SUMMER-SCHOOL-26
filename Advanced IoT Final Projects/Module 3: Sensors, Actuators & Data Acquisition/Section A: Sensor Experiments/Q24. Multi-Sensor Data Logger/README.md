# Q 24 – Multi-Sensor Data Logger

## Overview

The **Multi-Sensor Data Logger** is an IoT-based monitoring system developed as part of the **Advanced IoT Final Projects** under **Module 3: Sensors, Actuators & Data Acquisition**. The project integrates multiple sensors with an Arduino Uno to collect environmental data simultaneously and present it in a structured format through the Serial Monitor.

The system acquires temperature, humidity, ambient light intensity, and distance measurements every five seconds, demonstrating real-time sensor integration, data acquisition, and formatted logging in embedded systems.

> **Note:** The original assignment specifies the use of a **DHT11** sensor. For this project, a **DHT22** sensor was used in the Wokwi simulation because the DHT11 component was unavailable. Since both sensors use the same communication protocol and Arduino library, the project functionality remains unchanged while providing improved measurement accuracy.

---

## Project Highlights

- Simultaneous acquisition of environmental data from multiple sensors.
- Temperature and humidity monitoring using a DHT sensor.
- Ambient light measurement with percentage conversion.
- Distance measurement using ultrasonic sensing.
- Structured sensor log generated every five seconds.
- Non-blocking execution using the `millis()` function.
- Compatible with Arduino Uno and Wokwi Simulator.

---

## Hardware Used

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| DHT22 Temperature & Humidity Sensor* | 1 |
| LDR Sensor Module | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

> *Used as a functional replacement for the DHT11 in the Wokwi simulation.

---

## Software Requirements

- Arduino IDE
- DHT Sensor Library
- Wokwi Online Simulator

---

## Project Structure

```text
Q24. Multi-Sensor Data Logger
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

## System Overview

The Arduino continuously communicates with three sensors to monitor environmental conditions. The DHT sensor measures temperature and humidity, the LDR sensor measures ambient light intensity, and the HC-SR04 ultrasonic sensor determines the distance of nearby objects.

Sensor values are collected at regular intervals and organized into a readable log format, making the system suitable for basic environmental monitoring and data acquisition applications.

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

The repository contains:

- Hardware setup image
- DHT22 sensor output image
- LDR sensor output image
- Ultrasonic sensor output image
- Project demonstration video
- Sensor log file containing captured Serial Monitor readings
- Arduino source code
- Detailed technical documentation

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469191765522067457

The online simulation demonstrates the complete functionality of the project, including simultaneous sensor interfacing, structured data logging, and periodic data acquisition using non-blocking programming techniques.

---

## Applications

- Environmental Monitoring
- Smart Agriculture
- IoT Data Collection
- Weather Monitoring Stations
- Smart Laboratory Experiments
- Educational Embedded Systems Projects

---

## Learning Outcomes

- Interfacing multiple sensors with Arduino
- Reading analog and digital sensor data
- Temperature and humidity monitoring
- Ultrasonic distance measurement
- Ambient light sensing
- Structured Serial communication
- Real-time data acquisition
- Non-blocking programming using `millis()`

---

## Future Enhancements

- Cloud-based data logging
- SD card storage
- OLED/LCD display integration
- Wi-Fi or LoRa communication
- Real-time clock for actual timestamps
- Interactive dashboard visualization

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

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
