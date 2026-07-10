# Documentation of Smart Street Light (LDR + PIR)

## Overview

This document provides the complete technical documentation for the **Smart Street Light (LDR + PIR)** project developed during **Week 03** of the **IoT and Drone Building Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

The project demonstrates an intelligent street lighting system that automatically controls LED brightness based on ambient light conditions and human motion. It utilizes an LDR sensor for day/night detection, a PIR motion sensor for movement detection, PWM for LED brightness control, and `millis()` for non-blocking operation.

---

## Documentation Contents

- Project Overview
- Hardware Components
- Circuit Configuration
- Pin Configuration
- Working Principle
- Step-by-Step Implementation
- Event Logic
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
└── Smart Street Light (LDR + PIR)
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

## Hardware Components

- Arduino Uno
- LDR Sensor (Photoresistor)
- PIR Motion Sensor
- LED
- 220 Ω Resistor
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| LDR Analog Output | A0 |
| PIR Output | D2 |
| LED (PWM) | D9 |

---

## Circuit Configuration

- Connect the LDR sensor VCC to **5V** and GND to **GND**.
- Connect the LDR analog output to **A0**.
- Connect the PIR sensor VCC to **5V**, GND to **GND**, and OUT to **D2**.
- Connect the LED anode to **D9** through a **220 Ω resistor** and connect the cathode to **GND**.

---

## Working Principle

The LDR continuously measures the surrounding light intensity to determine whether it is day or night. During daylight, the LED remains OFF to conserve energy.

When the light intensity falls below the threshold, the system enters night mode and enables motion detection. If the PIR sensor detects movement, the LED immediately turns ON at full brightness. After 30 seconds of no motion, the LED automatically dims to 20% brightness using PWM. The entire system operates using `millis()` for non-blocking timing, allowing continuous sensor monitoring while logging important events to the Serial Monitor.

---

## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect the Arduino Uno, LDR sensor, PIR motion sensor, LED, and resistor according to the specified pin configuration.

---

### Step 2: Configure the LDR

Connect the LDR analog output to **A0** to continuously monitor ambient light intensity.

---

### Step 3: Configure the PIR Sensor

Connect the PIR sensor output to **D2** for motion detection during night mode.

---

### Step 4: Connect the LED

Connect the LED to PWM pin **D9** through a **220 Ω resistor** to enable brightness control using PWM.

---

### Step 5: Upload the Program

Open Arduino IDE or Wokwi, upload the `SSL.ino` sketch, and open the Serial Monitor at **9600 baud**.

---

### Step 6: Test Day Mode

Increase the ambient light level.

Expected Result:

- LED remains OFF.
- Motion detection is disabled.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: Daylight detected - Street light OFF
```

---

### Step 7: Test Night Mode

Reduce the light level below the threshold.

Expected Result:

- Motion detection becomes active.
- LED waits for PIR input.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: Night detected - Motion detection enabled
```

---

### Step 8: Test Motion Detection

Trigger the PIR sensor.

Expected Result:

- LED turns ON at **100% brightness**.
- A **30-second timer** starts.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: Motion detected - LED ON (100%)
```

---

### Step 9: Test Automatic Dimming

Wait for **30 seconds** without any additional motion.

Expected Result:

- LED dims to **20% brightness** using PWM.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: No motion after 30 seconds - LED Dimmed (20%)
```

---

### Step 10: Verify Complete Operation

Repeat the tests by changing the LDR light intensity and PIR motion state to verify smooth transitions between all operating modes.

---

## Event Logic

| Condition | LED Status | Serial Event |
|-----------|------------|--------------|
| Daylight | OFF | Daylight detected - Street light OFF |
| Night | Motion Detection Enabled | Night detected - Motion detection enabled |
| Motion Detected | 100% Brightness | Motion detected - LED ON (100%) |
| No Motion for 30 Seconds | 20% Brightness | No motion after 30 seconds - LED Dimmed (20%) |

---

## Code Explanation

### LDR Monitoring

The Arduino continuously reads the analog value from the LDR to determine whether it is day or night.

### Motion Detection

The PIR sensor becomes active only during night mode. Whenever motion is detected, the LED immediately switches to full brightness.

### PWM Brightness Control

After 30 seconds of inactivity, the LED brightness is reduced to 20% using PWM (`analogWrite()`).

### Non-Blocking Timing

The project uses the `millis()` function instead of `delay()`, allowing continuous sensor monitoring while managing LED brightness and timing simultaneously.

### Event Logging

All significant system events are recorded in the Serial Monitor using the following format:

```text
[HH:MM:SS] EVENT: Description
```

---

## Software Concepts Used

- Analog Input Reading
- Digital Input Reading
- PWM Output
- Conditional Statements
- State-Based Programming
- Non-Blocking Programming using `millis()`
- Serial Communication

---

## Assets Included

| Asset | Description |
|-------|-------------|
| Smart Street Light (LDR + PIR) Hardware setup.png | Circuit setup |
| Smart Street Light (LDR + PIR) demo part 01.mp4 | Demonstration of day and night modes |
| Smart Street Light (LDR + PIR) demo part 02.mp4 | Motion detection and automatic dimming |
| Street light off.png | LED OFF during daylight |
| motion detected.png | LED ON after motion detection |
| no motion detected.png | LED dimmed after inactivity |

---

## Wokwi Simulation

The project was successfully simulated using **Wokwi**, demonstrating:

- Day and night detection using the LDR
- PIR-based motion sensing
- PWM brightness control
- Automatic LED dimming after 30 seconds
- Event logging with timestamps
- Non-blocking operation using `millis()`

---

## Learning Outcomes

- LDR sensor interfacing
- PIR motion sensing
- PWM LED brightness control
- Analog and digital input handling
- Event-driven embedded programming
- Non-blocking programming using `millis()`
- Serial communication for debugging
- Smart energy-efficient lighting system design

---

## Best Practices

- Use PWM-supported pins for brightness control.
- Calibrate the LDR threshold according to ambient lighting.
- Avoid using `delay()` in real-time embedded applications.
- Ensure secure wiring to prevent unstable sensor readings.
- Test each operating mode individually before deployment.
- Keep the program modular for easier maintenance.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. PIR Motion Sensor Datasheet
4. LDR Sensor Documentation
5. Wokwi Simulator – https://wokwi.com/

---

## Conclusion

The **Smart Street Light (LDR + PIR)** project demonstrates an intelligent and energy-efficient street lighting solution by integrating ambient light sensing, motion detection, PWM-based brightness control, and non-blocking programming. The system effectively reduces unnecessary power consumption while maintaining reliable illumination during nighttime, making it a practical example of IoT-based smart city automation and embedded system design.
