# Documentation of Question 26

## Overview

This document provides the complete technical documentation for **Q 26 – DC Motor Speed Control with L298N** developed as part of the **Advanced IoT Final Project**, **Module 3: Sensors, Actuators & Data Acquisition**, **Section B: Actuator Control**.

> **Note:** The assignment specifies the **L298N Motor Driver**. However, the implementation was carried out using the **L293D Motor Driver IC** because **Tinkercad does not provide the L298N module**. Both devices are H-Bridge motor drivers and support the same functionality required for this project.

---

## Documentation Contents

- Project Overview
- Components Required
- Pin Configuration
- Circuit Connections
- Working Principle
- Implementation Steps
- Serial Monitor Output
- Code Explanation
- Software Concepts Used
- Assets Included
- Tinkercad Simulation
- Learning Outcomes
- Best Practices
- Conclusion

---

## Project Structure

```text
Advanced IoT Final Projects
│
└── Module 3: Sensors, Actuators & Data Acquisition
    │
    └── Section B: Actuator Control
        │
        └── Q26. DC Motor Speed Control with L298N
            │
            ├── Assets
            │   ├── DC Motor Speed Control with L293D demo.mp4
            │   ├── DC Motor Speed Control with L298N hardware setup.png
            │   ├── DC Motor forward and running status.png
            │   ├── DC Motor reverse and running status.png
            │   ├── DC Motor stopped and started using push button.png
            │   ├── DC Motor stopped as potentiometer is at 255.png
            │   └── .gitkeep
            │
            ├── Code
            │   └── DC_Motor_Speed_Control.ino
            │
            ├── Documentation
            │   └── README.md
            │
            └── README.md
```

---

## Components Required

- Arduino Uno
- L293D Motor Driver IC *(used in place of L298N)*
- DC Motor
- 10kΩ Potentiometer
- Push Button ×2
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Potentiometer | A0 |
| Enable (PWM) | D9 |
| IN1 | D8 |
| IN2 | D7 |
| Direction Button | D2 |
| Start/Stop Button | D3 |

---

## Circuit Connections

- Connect the potentiometer output to **A0**.
- Connect the L293D enable pin to **D9 (PWM)**.
- Connect IN1 and IN2 to **D8** and **D7**.
- Connect the direction button to **D2** using **INPUT_PULLUP**.
- Connect the start/stop button to **D3** using **INPUT_PULLUP**.
- Connect the DC motor to the output pins of the L293D.
- Supply power and connect all grounds together.

---

## Working Principle

The potentiometer continuously controls the motor speed by generating a PWM signal. One push button changes the motor rotation between **Forward** and **Reverse**, while the second button starts or stops the motor. The Serial Monitor displays the potentiometer reading, PWM value, motor speed percentage, motor direction, and operating state.

---

## Implementation Steps

### Step 1
Assemble the Arduino, L293D motor driver, DC motor, potentiometer, and push buttons.

### Step 2
Read the potentiometer value and convert it into a PWM value.

### Step 3
Generate PWM output to control motor speed.

### Step 4
Toggle motor direction using the direction button.

### Step 5
Start or stop the motor using the control button.

### Step 6
Display all parameters on the Serial Monitor.

---

## Serial Monitor Output

```text
Potentiometer : 742
PWM Value     : 185
Speed         : 73%
Direction     : Forward
State         : Running
```

---

## Code Explanation

### Potentiometer Reading
Reads the analog value from A0.

### PWM Speed Control
Maps the potentiometer value to a PWM output between 0 and 255.

### Direction Control
Changes motor rotation between Forward and Reverse.

### Motor State Control
Starts or stops the motor using a push button.

### Serial Monitoring
Displays potentiometer value, PWM output, speed percentage, direction, and motor state.

---

## Software Concepts Used

- PWM Motor Control
- Analog Input
- Push Button Interfacing
- H-Bridge Motor Driver
- DC Motor Direction Control
- Serial Communication
- Button Debouncing

---

## Assets Included

| Asset | Description |
|--------|-------------|
| DC Motor Speed Control with L298N hardware setup.png | Circuit wiring |
| DC Motor forward and running status.png | Forward operation |
| DC Motor reverse and running status.png | Reverse operation |
| DC Motor stopped and started using push button.png | Start/Stop demonstration |
| DC Motor stopped as potentiometer is at 255.png | Motor stop condition |
| DC Motor Speed Control with L293D demo.mp4 | Project demonstration |

---

## Tinkercad Simulation

**Simulation Link**

https://www.tinkercad.com/things/2Yh2ABClB5q-funky-bojo-lappi/editel

**Description**

The simulation demonstrates DC motor speed control using PWM, forward and reverse rotation, and motor start/stop functionality using the L293D motor driver in Tinkercad.

---

## Learning Outcomes

- DC motor interfacing
- PWM speed control
- H-Bridge motor driver operation
- Direction control
- Analog input processing
- Push button interfacing
- Embedded motor control

---

## Best Practices

- Use a common ground for all components.
- Verify motor driver connections before powering the circuit.
- Avoid changing direction rapidly at maximum speed.
- Test PWM values before increasing motor speed.
- Confirm Serial Monitor readings during calibration.

---

## Conclusion

The **DC Motor Speed Control** project demonstrates practical motor control using PWM, H-Bridge direction switching, and user interaction through push buttons. Although the implementation uses the **L293D** due to Tinkercad's component availability, it fulfills all functional requirements of the original **L298N-based assignment** and provides hands-on experience in actuator control and embedded system programming.
