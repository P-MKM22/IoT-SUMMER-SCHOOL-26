# Smart Street Light (LDR + PIR)

## Overview

The **Smart Street Light (LDR + PIR)** project was developed as part of **Week 03** of the **IoT and Drone Building Summer School 2026** at **Indian Institute of Technology Jammu (IIT Jammu)**. The system automatically controls street lighting based on ambient light intensity and human motion, providing an energy-efficient lighting solution suitable for smart city applications.

Using an **LDR sensor**, the system distinguishes between day and night conditions, while a **PIR motion sensor** detects movement during nighttime. The LED turns ON at full brightness whenever motion is detected and automatically dims after 30 seconds of inactivity using PWM. The implementation utilizes **non-blocking programming with `millis()`**, ensuring continuous sensor monitoring and responsive operation.

---

## Key Features

- Automatic day and night detection using an LDR sensor.
- Motion detection using a PIR sensor.
- LED turns ON at full brightness when motion is detected.
- LED automatically dims to 20% brightness after 30 seconds of no motion.
- LED remains OFF during daylight to conserve energy.
- Event logging with timestamps on the Serial Monitor.
- Non-blocking implementation using `millis()`.
- Fully compatible with Arduino Uno and Wokwi Simulator.

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| LDR Sensor | 1 |
| PIR Motion Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

## Software Requirements

- Arduino IDE 2.x or later
- Wokwi Online Simulator

---

## Folder Structure

```text
Week 03
│
├── Assets
│   ├── Smart Street Light (LDR + PIR) Hardware setup.png
│   ├── Smart Street Light (LDR + PIR) demo part 01.mp4
│   ├── Smart Street Light (LDR + PIR) demo part 02.mp4
│   ├── Street light off.png
│   ├── motion detected.png
│   └── no motion detected.png
│
├── Code
│   └── SSL.ino
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

## Working Principle

The LDR continuously monitors the surrounding light intensity. During daylight, the street light remains OFF. Once the ambient light falls below the predefined threshold, the system switches to night mode and enables motion detection using the PIR sensor.

Whenever motion is detected, the LED immediately turns ON at full brightness. If no additional motion is detected within 30 seconds, the LED automatically dims to 20% brightness using PWM. Throughout operation, important system events are logged to the Serial Monitor with timestamps generated using the Arduino runtime.

---

## Project Assets

The project includes:

- Hardware setup image
- Circuit demonstration videos
- Day mode output image
- Motion detection output image
- LED dimming output image
- Complete Arduino source code
- Technical documentation

---

## Wokwi Simulation

The project was successfully simulated using **Wokwi**, validating:

- Automatic day/night detection
- PIR-based motion sensing
- PWM brightness control
- Non-blocking timing using `millis()`
- Serial Monitor event logging

---

## Learning Outcomes

Through this project, the following concepts were explored:

- Ambient light sensing using LDR
- PIR-based motion detection
- PWM brightness control
- Analog and digital sensor interfacing
- Event-driven embedded programming
- Non-blocking programming using `millis()`
- Serial communication and debugging
- Smart energy-efficient lighting systems

---

## Future Improvements

- Integrate multiple street lights into a smart lighting network.
- Add Wi-Fi or LoRa connectivity for remote monitoring.
- Display system status on an OLED or LCD.
- Store lighting events on a cloud platform.
- Incorporate solar-powered battery backup.
- Implement adaptive brightness based on traffic density.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. PIR Motion Sensor Datasheet
4. LDR Sensor Documentation
5. Wokwi Simulator – https://wokwi.com/

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
