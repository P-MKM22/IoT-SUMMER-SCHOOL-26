# Section A: Sensor Experiments

## Overview

**Section A: Sensor Experiments** is a part of **Module 3: Sensors, Actuators & Data Acquisition** under the **Advanced IoT Final Projects** of the **IoT and Drone Building Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

This section focuses on building practical IoT applications by interfacing different sensors with the Arduino Uno. Each experiment demonstrates the working principles of commonly used sensors, real-time data acquisition, signal processing, and embedded programming techniques. The projects emphasize structured coding, hardware interfacing, sensor calibration, data logging, and non-blocking programming using `millis()` wherever applicable.

---

## Purpose of this Section

The primary objectives of this section are to:

- Understand the working principles of different IoT sensors.
- Learn sensor interfacing with Arduino Uno.
- Acquire and process real-time sensor data.
- Implement event-driven embedded applications.
- Develop structured and reusable Arduino programs.
- Practice serial communication and data logging.
- Build a strong foundation for advanced IoT system development.

---

## Projects Included

### Q21. Environmental Monitoring Station (DHT11)

A basic environmental monitoring system that measures **temperature** and **humidity** using a DHT sensor and displays the readings on the Serial Monitor.

**Concepts Covered**

- Temperature sensing
- Humidity sensing
- Sensor library integration
- Serial communication

---

### Q22. Ultrasonic Parking Sensor

A smart parking assistance system using the **HC-SR04 ultrasonic sensor**, LEDs, and a buzzer to provide distance-based visual and audible alerts.

**Concepts Covered**

- Ultrasonic distance measurement
- LED indication
- Buzzer control
- Non-blocking programming using `millis()`

---

### Q23. Smart Street Light (LDR + PIR)

An intelligent street lighting system that uses an **LDR** and **PIR motion sensor** to automatically control LED brightness based on ambient light conditions and motion detection.

**Concepts Covered**

- Ambient light sensing
- Motion detection
- PWM brightness control
- Event-driven programming

---

### Q24. Multi-Sensor Data Logger

A multi-sensor monitoring system that simultaneously reads **temperature**, **humidity**, **light intensity**, and **distance** data, displaying them in a structured format every five seconds.

**Concepts Covered**

- Multi-sensor interfacing
- Environmental data acquisition
- Structured data logging
- Non-blocking programming using `millis()`

---

## Folder Structure

```text
Section A: Sensor Experiments
│
├── Q21. Environmental Monitoring Station (DHT11)
├── Q22. Ultrasonic Parking Sensor
├── Q23. Smart Street Light (LDR + PIR)
└── Q24. Multi-Sensor Data Logger
```

---

## Skills Developed

- Arduino Programming
- Sensor Interfacing
- Analog and Digital Input Processing
- PWM Control
- Environmental Monitoring
- Distance Measurement
- Motion Detection
- Data Acquisition
- Serial Communication
- Embedded System Design
- Non-Blocking Programming using `millis()`

---

## Learning Outcomes

After completing this section, learners will be able to:

- Interface multiple sensors with Arduino Uno.
- Acquire and process real-time sensor data.
- Develop intelligent sensor-based IoT applications.
- Implement structured Arduino programs for embedded systems.
- Apply event-driven logic and non-blocking programming techniques.
- Build scalable sensor-based solutions for smart IoT applications.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. DHT Sensor Library Documentation
4. HC-SR04 Ultrasonic Sensor Datasheet
5. PIR Motion Sensor Datasheet
6. LDR Sensor Documentation
7. Wokwi Simulator – https://wokwi.com/

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
