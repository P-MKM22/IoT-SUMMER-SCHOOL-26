# Documentation of Question 04
## Overview

This document provides the complete technical documentation for **Question 4 – Versioned Development of an LED Blinking Project**. It explains the hardware requirements, software requirements, circuit connections, implementation details, and enhancements introduced in each version of the project.

The project follows an incremental development approach where each version extends the functionality of the previous one while maintaining a clear development history.

---

# Project Objective

The objective of this project is to understand the concept of version-wise software development in embedded systems. Instead of implementing all features at once, the project evolves through multiple versions, with each version introducing a new enhancement while preserving the previous functionality.

---

# Software Requirements

- Arduino IDE
- Wokwi Simulator
- GitHub

---

# Hardware Requirements

- Arduino Uno
- Breadboard
- LED
- 220 Ω Resistor
- Potentiometer (Version 1.2 onwards)
- Jumper Wires

---

# Version 1.0 – Basic LED Blinking

## Description

Version 1.0 is the initial implementation of the project. It demonstrates basic LED interfacing with an Arduino Uno, where the LED continuously blinks using a fixed delay.

### Components Used

- Arduino Uno
- LED
- 220 Ω Resistor
- Breadboard
- Jumper Wires

### Circuit Connections

| Arduino Pin | Connected Component |
|--------------|--------------------|
| D9 | 220 Ω Resistor |
| Resistor Output | LED Anode (+) |
| LED Cathode (-) | GND |

### Features

- Basic LED blinking
- Fixed delay timing
- Digital output control

### Commit Message

```text
feat: Add Version 1.0 LED Blinking Program
```

---

# Version 1.1 – Serial Monitor Integration

## Description

Version 1.1 extends the previous implementation by introducing Serial Monitor communication. The LED continues blinking while the Serial Monitor displays the blink count, helping users observe the execution of the program.

### Components Used

No additional hardware was required.

### Circuit Connections

The hardware setup remains the same as Version 1.0.

| Arduino Pin | Connected Component |
|--------------|--------------------|
| D9 | 220 Ω Resistor |
| Resistor Output | LED Anode (+) |
| LED Cathode (-) | GND |

### New Features

- Serial Monitor output
- Blink counter
- Runtime monitoring

### Commit Message

```text
feat: Add Serial Monitor Blink Counter
```

---

# Version 1.2 – Potentiometer Controlled Blink Speed

## Description

Version 1.2 introduces analog input by connecting a potentiometer to the Arduino. The potentiometer controls the LED blinking speed in real time, demonstrating analog-to-digital conversion and variable delay generation.

### Additional Component

- Potentiometer (10 kΩ)

### Circuit Connections

| Arduino Pin | Connected Component |
|--------------|--------------------|
| D9 | 220 Ω Resistor |
| Resistor Output | LED Anode (+) |
| LED Cathode (-) | GND |
| A0 | Potentiometer Middle Pin |
| 5V | Potentiometer Left Pin |
| GND | Potentiometer Right Pin |

### New Features

- Analog input using potentiometer
- Dynamic blink speed control
- Variable delay generation
- Real-time sensor monitoring

### Commit Message

```text
feat: Add Potentiometer Controlled Blink Speed
```

---

# Version 1.3 – Professional Code Documentation

## Description

Version 1.3 focuses on improving the quality and readability of the source code. A professional header block was added to the Arduino program containing project information such as the project title, version, author, roll number, description, platform, and development software.

No functional changes were made in this version.

### Components Used

The hardware configuration remains identical to Version 1.2.

### Circuit Connections

| Arduino Pin | Connected Component |
|--------------|--------------------|
| D9 | 220 Ω Resistor |
| Resistor Output | LED Anode (+) |
| LED Cathode (-) | GND |
| A0 | Potentiometer Middle Pin |
| 5V | Potentiometer Left Pin |
| GND | Potentiometer Right Pin |

### Improvements

- Added project header block
- Added author information
- Added roll number
- Added project description
- Added version information
- Improved code readability

### Commit Message

```text
docs: Add Program Header and Documentation
```

---

# Development Workflow

The project was developed using an incremental versioning approach.

1. Designed the basic LED blinking circuit.
2. Verified the hardware using Wokwi.
3. Added Serial Monitor communication.
4. Introduced analog input using a potentiometer.
5. Improved source code documentation.
6. Recorded assets and updated documentation for every version.
7. Maintained a structured Git commit history using Conventional Commits.

---

# Wokwi Simulations

Every version of the project has been simulated using the Wokwi online simulator.

The corresponding simulation link is available in the **README.md** of each version folder.

---

# Learning Outcomes

After completing this project, the following concepts were understood:

- Arduino programming fundamentals
- Digital output interfacing
- Analog input using potentiometers
- Analog-to-Digital Conversion (ADC)
- Serial communication
- LED timing control
- Embedded system debugging
- Incremental software development
- GitHub repository organization
- Version control using Conventional Commits
- Professional project documentation

---

# Conclusion

This project demonstrates the importance of structured software development through incremental versioning. Beginning with a basic LED blinking circuit, the project gradually evolved by incorporating serial communication, analog speed control, and professional source code documentation. By maintaining separate versions, documentation, and commit history, the repository reflects good software engineering practices and serves as a well-organized reference for embedded system development.
