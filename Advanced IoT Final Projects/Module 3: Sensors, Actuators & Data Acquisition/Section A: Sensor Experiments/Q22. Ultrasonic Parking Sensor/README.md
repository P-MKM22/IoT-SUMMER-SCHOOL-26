# Q 22 – Ultrasonic Parking Sensor

## Overview

This project implements an intelligent parking assistance system using the HC-SR04 Ultrasonic Sensor and Arduino Uno. The system continuously measures the distance between the sensor and an obstacle, then provides visual and audible alerts to assist safe parking. It uses non-blocking programming with `millis()` for efficient real-time operation.

---

## Objectives

- Measure obstacle distance using the HC-SR04 sensor.
- Calculate distance using the standard ultrasonic formula.
- Display distance on the Serial Monitor.
- Provide visual alerts using Green, Yellow, and Red LEDs.
- Generate different buzzer alerts based on distance.
- Implement non-blocking timing using `millis()`.

---

## Features

- Real-time distance measurement.
- Green LED blinks in the SAFE zone.
- Yellow LED warning indication.
- Red LED danger indication.
- Continuous buzzer in the critical zone.
- Uses `millis()` instead of `delay()`.
- Compatible with Arduino Uno and Wokwi Simulator.

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Buzzer | 1 |
| 220 Ω Resistors | 3 |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

## Software Requirements

- Arduino IDE 2.x or later
- Wokwi Online Simulator

---

## Project Structure

```text
Q22. Ultrasonic Parking Sensor
│
├── Assets
│   ├── .gitkeep
│   ├── Ultrasonic Parking Sensor demo.mp4
│   ├── Ultrasonic parking sensor distance greater than 50cm.png
│   ├── Ultrasonic parking sensor distance less than 10cm.png
│   ├── Ultrasonic parking sensor distance less than 20cm.png
│   └── Ultrasonic parking sensor hardware setup.png
│
├── Code
│   └── UPS.ino
│
├── Documentation Folder
│   └── README.md
│
└── README.md
```

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 Trigger | D9 |
| HC-SR04 Echo | D10 |
| Green LED | D5 |
| Yellow LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |

---

## Working Principle

The HC-SR04 transmits an ultrasonic pulse and waits for the reflected echo. Arduino measures the echo duration and calculates the distance. According to the measured distance, the system activates LEDs and the buzzer to indicate the parking status. The entire system operates continuously using `millis()` without blocking program execution.

---

## Distance Calculation

```cpp
distance = (duration * 0.034) / 2;
```

Where:

- `duration` = Echo pulse time (µs)
- `0.034` = Speed of sound (cm/µs)
- Division by `2` accounts for the round-trip travel of the sound wave.

---

## Alert Conditions

| Distance | Green | Yellow | Red | Buzzer | Serial |
|----------|:-----:|:------:|:---:|:------:|--------|
| > 50 cm | Blink | OFF | OFF | OFF | SAFE |
| 20–50 cm | OFF | ON | OFF | Every 500 ms | Distance |
| 10–20 cm | OFF | OFF | ON | Every 200 ms | Distance |
| < 10 cm | OFF | Flash | Flash | Continuous | Distance |

---

## Execution Steps

1. Assemble the circuit according to the pin connections.
2. Upload the `UPS.ino` sketch to the Arduino Uno.
3. Open the Serial Monitor at **9600 baud**.
4. Place an object in front of the ultrasonic sensor.
5. Observe the measured distance and alert status.
6. Verify each distance range:
   - **>50 cm:** Green LED blinks, Serial displays **SAFE**, buzzer OFF.
   - **20–50 cm:** Yellow LED ON, buzzer beeps every 500 ms.
   - **10–20 cm:** Red LED ON, buzzer beeps every 200 ms.
   - **<10 cm:** Yellow and Red LEDs flash rapidly with a continuous buzzer.

---

## Assets Included

| Asset | Description |
|-------|-------------|
| Ultrasonic Parking Sensor demo.mp4 | Demonstration of the complete project |
| Ultrasonic parking sensor hardware setup.png | Hardware wiring setup |
| Ultrasonic parking sensor distance greater than 50cm.png | SAFE condition |
| Ultrasonic parking sensor distance less than 20cm.png | Danger condition |
| Ultrasonic parking sensor distance less than 10cm.png | Critical parking condition |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469171212359044097

**Description**

The simulation demonstrates real-time distance measurement, LED indications, buzzer alerts, Serial Monitor output, and the non-blocking implementation using `millis()`.

---

## Learning Outcomes

- Ultrasonic distance measurement.
- Arduino digital I/O programming.
- Real-time embedded programming.
- Non-blocking timing using `millis()`.
- LED and buzzer interfacing.
- Sensor-based decision making.
- Serial communication and debugging.

---

## Future Improvements

- Add OLED/LCD display for live distance.
- Integrate Bluetooth or Wi-Fi notifications.
- Implement voice guidance.
- Store parking data on the cloud.
- Add multiple ultrasonic sensors for wider coverage.
- Integrate with a smart parking management system.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. HC-SR04 Ultrasonic Sensor Datasheet
4. Wokwi Simulator – https://wokwi.com/

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
