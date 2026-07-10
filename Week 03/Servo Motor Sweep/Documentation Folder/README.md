# Documentation of Servo Motor Sweep

## Overview

This document provides the technical documentation for the **Servo Motor Sweep** project developed during **Week 03** of the **IoT Summer School 2026** at the **Indian Institute of Technology Jammu (IIT Jammu)**.

The project demonstrates the control of an **SG90 Servo Motor** using a **10kΩ potentiometer**. The potentiometer controls the servo position from **0° to 180°**, while a push button performs one complete sweep (**0° → 180° → 0°**). The Serial Monitor displays both the potentiometer value and the corresponding servo angle in real time.

---

## Documentation Contents

- Project Overview
- Hardware Components
- Pin Configuration
- Circuit Connections
- Working Principle
- Step-by-Step Implementation
- Serial Monitor Output
- Code Explanation
- Software Concepts Used
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- Conclusion

---

## Project Structure

```text
Week 03
│
└── Servo Motor Sweep
    │
    ├── Assets
    │   ├── Different servo angle(1).png
    │   ├── Different servo angle(2).png
    │   ├── Servo Motor Sweep hardware setup.png
    │   ├── Servo Motor Sweep demo.mp4
    │   └── .gitkeep
    │
    ├── Code
    │   └── Servo_motor_sweep.ino
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## Hardware Components

- Arduino Uno
- SG90 Servo Motor
- 10kΩ Potentiometer
- Push Button
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Servo Signal | D9 |
| Potentiometer Output | A0 |
| Push Button | D2 |

---

## Circuit Connections

- Connect the **servo signal** pin to **Digital Pin 9**.
- Connect the **potentiometer output** to **Analog Pin A0**.
- Connect one terminal of the **push button** to **Digital Pin 2** and the other to **GND**.
- Connect all components to **5V** and **GND** using a common ground.

---

## Working Principle

The Arduino continuously reads the analog value from the potentiometer and maps it to a servo angle between **0° and 180°**. As the potentiometer rotates, the servo follows the corresponding position.

When the push button is pressed, the servo performs one complete sweep from **0° → 180° → 0°** before returning to normal potentiometer control.

---

## Step-by-Step Implementation

### Step 1: Assemble the Circuit

Connect the Arduino Uno, servo motor, potentiometer, and push button.

### Step 2: Initialize the Servo

Attach the SG90 servo motor using the Arduino Servo Library.

### Step 3: Read Potentiometer Value

Read the analog input from **A0**.

### Step 4: Map the Servo Angle

Convert the potentiometer value into a servo angle using the `map()` function.

### Step 5: Control the Servo

Move the servo according to the mapped angle.

### Step 6: Detect Button Press

Monitor the push button using the internal **INPUT_PULLUP** resistor.

### Step 7: Perform Servo Sweep

Execute one complete servo sweep whenever the button is pressed.

### Step 8: Display Values

Display the potentiometer reading and servo angle on the Serial Monitor.

---

## Serial Monitor Output

```text
Potentiometer : 512 | Servo Angle : 90°
Potentiometer : 735 | Servo Angle : 129°
Potentiometer : 1023 | Servo Angle : 180°
```

---

## Code Explanation

### Servo Initialization

Initializes the SG90 servo using the Servo library.

### Potentiometer Reading

Reads the analog value from the potentiometer.

### Angle Mapping

Maps the analog input range (0–1023) to the servo angle (0°–180°).

### Servo Control

Updates the servo position based on the mapped angle.

### Button Detection

Detects a button press to trigger the automatic sweep.

### Serial Communication

Displays the potentiometer value and servo angle whenever the position changes.

---

## Software Concepts Used

- Servo Motor Interfacing
- Analog Input Processing
- ADC Mapping
- Push Button Interfacing
- Serial Communication
- Arduino Servo Library

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Servo Motor Sweep hardware setup.png | Circuit connection |
| Different servo angle(1).png | Servo position demonstration |
| Different servo angle(2).png | Additional servo position |
| Servo Motor Sweep demo.mp4 | Complete project demonstration |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469196284053317633

**Description**

The simulation demonstrates servo motor control using a potentiometer and an automatic sweep using a push button. It also shows the mapped servo angle and potentiometer value on the Serial Monitor in real time.

---

## Learning Outcomes

- Servo motor interfacing
- Analog input reading
- Servo angle mapping
- Push button interfacing
- Actuator control
- Serial communication

---

## Best Practices

- Use a stable 5V power supply.
- Ensure all components share a common ground.
- Avoid forcing the servo beyond its rotation limits.
- Verify wiring before uploading the program.
- Test Serial Monitor readings after programming.

---

## Conclusion

The **Servo Motor Sweep** project provides practical experience in controlling an actuator using analog input and user interaction. It introduces essential concepts of servo control, angle mapping, and embedded programming, forming a strong foundation for robotics and IoT-based automation projects.
