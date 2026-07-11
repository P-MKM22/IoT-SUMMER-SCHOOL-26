# Section B – Actuator Control

## Overview

**Section B – Actuator Control** focuses on interfacing and controlling various output devices using Arduino. The projects in this section demonstrate how embedded systems interact with actuators to perform real-world tasks such as motor control, automation, access control, and relay-based switching. These activities strengthen the understanding of PWM, digital output control, user interaction, and practical automation techniques commonly used in IoT and embedded applications.

---

## Section Objectives

- Understand the fundamentals of actuator interfacing.
- Control motors using PWM and H-Bridge drivers.
- Implement relay-based automation systems.
- Design secure embedded access control systems.
- Integrate sensors, buttons, displays, and actuators.
- Develop practical embedded automation projects.

---

## Projects Included

| Question | Project Title | Description |
|:--------:|---------------|-------------|
| **Q25** | Servo Motor Sweep | Controls an SG90 servo motor using a potentiometer for angle adjustment and a push button for automatic sweeping while displaying values on the Serial Monitor. |
| **Q26** | DC Motor Speed Control with L298N | Controls DC motor speed using PWM, changes motor direction using a push button, and starts or stops the motor while displaying real-time operating parameters. *(Implemented using L293D in Tinkercad due to L298N unavailability.)* |
| **Q27** | Relay-Controlled AC Device Simulation | Simulates an automatic AC control system where temperature controls relay operation with hysteresis and a manual override feature. |
| **Q28** | Keypad + LCD Display | Implements a password-protected access system using a 4×4 keypad, 16×2 LCD, LEDs, and buzzer with three-attempt lock protection. |

---

## Concepts Covered

- Servo Motor Control
- DC Motor Control
- PWM (Pulse Width Modulation)
- H-Bridge Motor Drivers
- Relay Interfacing
- Temperature-Based Automation
- Manual Override Logic
- Password Authentication
- Keypad Interfacing
- LCD Communication (I2C)
- Digital Output Control
- User Interface Design
- Embedded Security
- Actuator Integration
- Embedded System Programming

---

## Learning Outcomes

After completing this section, the learner will be able to:

- Interface and control different types of actuators.
- Control servo and DC motors using Arduino.
- Generate PWM signals for speed and position control.
- Implement relay-based automation systems.
- Develop password-protected embedded access systems.
- Integrate sensors, displays, buttons, and actuators into a single application.
- Apply practical embedded programming concepts to solve real-world automation problems.

---

## Directory Structure

```text
Section B: Actuator Control
│
├── Q25. Servo Motor Sweep
├── Q26. DC Motor Speed Control with L298N
├── Q27. Relay-Controlled AC Device Simulation
└── Q28. Keypad + LCD Display
```

---

## Purpose of this Section

This section provides hands-on experience in designing and implementing actuator-based embedded systems. Each project demonstrates a different method of controlling physical devices through Arduino programming, helping build a strong foundation in automation, motor control, user interaction, and secure embedded applications. The knowledge gained in this section serves as an essential building block for advanced IoT systems and real-world embedded engineering projects.
