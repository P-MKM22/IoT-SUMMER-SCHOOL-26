# Documentation of Question 23

## Overview

This document provides the technical documentation for the **Smart Street Light (LDR + PIR)** project developed using Arduino Uno. The system automatically controls the brightness of a street light based on ambient light intensity and motion detection. It ensures energy-efficient operation by turning the light OFF during the day, switching to motion detection mode at night, illuminating the LED at full brightness when motion is detected, and dimming it after 30 seconds of inactivity.

---

## Documentation Contents

- Project Overview
- Hardware Components
- Circuit Configuration
- Software Implementation
- Pin Configuration
- Step-by-Step Implementation
- Working Principle
- Execution Steps
- Alert Logic
- Code Explanation
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- References

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

## Hardware Components

- Arduino Uno
- LDR (Photoresistor Sensor)
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

- Connect the LDR module VCC to **5V** and GND to **GND**.
- Connect the LDR Analog Output (AO) to **A0**.
- Connect the PIR Sensor VCC to **5V**, GND to **GND**, and OUT to **D2**.
- Connect the LED anode to **D9** through a **220 Ω resistor** and the cathode to **GND**.

---

## Working Principle

The LDR continuously measures ambient light intensity. During daylight, the LED remains OFF. When the light level falls below the predefined threshold, the system enters night mode and activates motion monitoring using the PIR sensor.

If motion is detected, the LED turns ON at full brightness and remains ON for 30 seconds. If no further motion is detected during this period, the LED automatically dims to 20% brightness using PWM. All significant events are logged to the Serial Monitor with timestamps generated using the Arduino runtime.

---
## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect the Arduino Uno, LDR sensor, PIR motion sensor, LED, and resistor according to the specified pin configuration.

---

### Step 2: Configure the LDR

Connect the LDR sensor output to analog pin **A0** to continuously measure the ambient light intensity.

---

### Step 3: Configure the PIR Sensor

Connect the PIR sensor output to digital pin **D2** to detect human motion during night mode.

---

### Step 4: Connect the LED

Connect the LED to PWM pin **D9** through a **220 Ω resistor** so that its brightness can be controlled using PWM.

---

### Step 5: Upload the Program

Open the Arduino IDE, select **Arduino Uno**, upload the `SSL.ino` program, and open the Serial Monitor at **9600 baud**.

---

### Step 6: Test Day Mode

Increase the light intensity on the LDR sensor.

Expected Result:

- Street light remains OFF.
- Motion detection is disabled.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: Daylight detected - Street light OFF
```

---

### Step 7: Test Night Mode

Reduce the light intensity below the threshold.

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
- Timer starts for **30 seconds**.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: Motion detected - LED ON (100%)
```

---

### Step 9: Test Automatic Dimming

After 30 seconds without additional motion:

Expected Result:

- LED brightness reduces to **20%** using PWM.
- Serial Monitor displays:

```text
[HH:MM:SS] EVENT: No motion after 30 seconds - LED Dimmed (20%)
```

---

### Step 10: Verify the System

Repeat the above tests by changing the LDR light level and PIR motion state to verify that the system correctly transitions between all operating modes.
---
## Event Logic

| Condition | LED Status | Serial Event |
|-----------|------------|--------------|
| Daylight | OFF | Daylight detected - Street light OFF |
| Night | Motion Monitoring Enabled | Night detected - Motion detection enabled |
| Motion Detected | 100% Brightness | Motion detected - LED ON (100%) |
| No Motion for 30 Seconds | 20% Brightness | No motion after 30 seconds - LED Dimmed (20%) |

---

## Execution Steps

1. Assemble the circuit according to the pin configuration.
2. Upload the `SSL.ino` sketch to the Arduino Uno.
3. Open the Serial Monitor at **9600 baud**.
4. Adjust the LDR sensor to simulate day and night conditions.
5. During daylight, verify that the LED remains OFF.
6. Reduce the light level to enter night mode.
7. Trigger the PIR sensor by enabling motion.
8. Observe the LED turning ON at full brightness.
9. Wait for 30 seconds without motion and verify that the LED dims to 20% brightness.
10. Check that every state transition is logged on the Serial Monitor.

---

## Code Explanation

### LDR Monitoring

The Arduino continuously reads the analog value from the LDR to determine whether it is day or night.

### Motion Detection

The PIR sensor monitors movement only during night mode. Motion immediately turns the LED ON at full brightness.

### Automatic Dimming

A non-blocking timer implemented using `millis()` keeps the LED ON for 30 seconds. After the timeout expires without new motion, the LED brightness is reduced to 20% using PWM.

### Event Logging

Every major event is recorded in the Serial Monitor using the following format:

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
- Non-Blocking Timing using `millis()`
- Serial Communication

---

## Assets Included

| Asset | Description |
|-------|-------------|
| Smart Street Light (LDR + PIR) Hardware setup.png | Circuit hardware setup |
| Smart Street Light (LDR + PIR) demo part 01.mp4 | Day and night mode demonstration |
| Smart Street Light (LDR + PIR) demo part 02.mp4 | Motion detection and LED control demonstration |
| Street light off.png | Day mode output |
| motion detected.png | Motion detected at night |
| no motion detected.png | LED dimmed after timeout |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469185937620186113

**Description**

The Wokwi simulation demonstrates the complete smart street lighting system using an Arduino Uno, LDR sensor, PIR motion sensor, and PWM-controlled LED. It validates automatic day/night detection, motion-based illumination, automatic dimming after inactivity, and timestamp-based event logging without requiring physical hardware.

---

## Learning Outcomes

- Working with LDR sensors
- PIR motion sensing
- PWM brightness control
- Analog and digital interfacing
- Event-driven programming
- Non-blocking programming using `millis()`
- Serial debugging and monitoring
- Smart energy-efficient lighting systems

---

## Best Practices

- Use PWM pins for brightness control.
- Avoid using `delay()` in real-time applications.
- Calibrate the LDR threshold according to ambient lighting.
- Ensure stable power connections for accurate sensor readings.
- Test all operating modes before deployment.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. Arduino Language Reference – https://www.arduino.cc/reference/en/
3. PIR Motion Sensor Datasheet
4. LDR Sensor Documentation
5. Wokwi Simulator – https://wokwi.com/

---

## Conclusion

The Smart Street Light project demonstrates an energy-efficient lighting system that intelligently responds to environmental light and human presence. By combining LDR-based day/night detection, PIR motion sensing, PWM brightness control, and non-blocking timing using `millis()`, the system provides reliable real-time operation while reducing unnecessary power consumption. This project serves as a practical example of sensor integration and embedded automation for smart city applications.
