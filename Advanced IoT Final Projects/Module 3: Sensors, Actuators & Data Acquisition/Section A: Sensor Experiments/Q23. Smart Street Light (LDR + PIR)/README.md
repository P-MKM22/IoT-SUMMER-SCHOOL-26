# Q 23 – Smart Street Light (LDR + PIR)

## Overview

The **Smart Street Light** project is an energy-efficient lighting system developed using an Arduino Uno, an LDR sensor, and a PIR motion sensor. The system automatically turns the street light OFF during the day, enables motion detection at night, illuminates the LED at full brightness when motion is detected, and automatically dims the LED after 30 seconds of inactivity using PWM. The implementation uses `millis()` for non-blocking timing and logs all major events to the Serial Monitor.

---

## Features

- Automatic day and night detection using an LDR.
- Motion detection using a PIR sensor.
- LED turns ON at full brightness when motion is detected.
- LED automatically dims to 20% brightness after 30 seconds of no motion.
- LED remains OFF during daylight.
- Event logging with timestamps in the Serial Monitor.
- Non-blocking implementation using `millis()`.
- Compatible with Arduino Uno and Wokwi.

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

## Project Structure

```text
Q23. Smart Street Light (LDR + PIR)
│
├── Assets
│   ├── .gitkeep
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
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

## Working Principle

The LDR continuously monitors ambient light intensity. During daylight, the street light remains OFF. When the light level falls below the predefined threshold, the system enters night mode and enables the PIR sensor. Whenever motion is detected, the LED turns ON at full brightness for 30 seconds. If no further motion is detected during this period, the LED automatically dims to 20% brightness using PWM. All important events are logged to the Serial Monitor.

---

## Project Assets

The **Assets** folder contains:

- Hardware setup image
- Demo Video – Part 01
- Demo Video – Part 02
- Day mode output image
- Motion detected output image
- No motion detected output image

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469185937620186113

The Wokwi simulation demonstrates the complete smart street lighting system, including automatic day/night detection, motion-based lighting, PWM dimming, and Serial Monitor event logging.

---

## How to Run

1. Assemble the circuit according to the hardware setup.
2. Open the project in Arduino IDE or Wokwi.
3. Upload the `SSL.ino` program.
4. Open the Serial Monitor at **9600 baud**.
5. Adjust the LDR to simulate day and night conditions.
6. Trigger the PIR sensor during night mode to observe the LED behavior and event logs.

---

## Learning Outcomes

- LDR-based ambient light sensing
- PIR motion detection
- PWM LED brightness control
- Analog and digital sensor interfacing
- Non-blocking programming using `millis()`
- Event-driven embedded system design
- Serial communication and debugging

---

## Future Improvements

- Add multiple street lights for road networks.
- Display system status on an OLED/LCD.
- Integrate Wi-Fi or LoRa for remote monitoring.
- Store lighting events in cloud databases.
- Add battery backup with solar charging.
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
