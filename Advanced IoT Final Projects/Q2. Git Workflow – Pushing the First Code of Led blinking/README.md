# Q02 – LED Blinking using Arduino Uno

## Project Overview

The LED Blinking project is one of the fundamental experiments in embedded systems and Arduino programming. It demonstrates how a microcontroller can control a digital output pin to periodically switch an LED ON and OFF.

This experiment introduces the basic concepts of GPIO (General Purpose Input/Output), program execution flow, and timing functions, forming the foundation for more advanced IoT and embedded system applications.

---

## Objectives

- Understand the architecture of the Arduino Uno.
- Learn how to configure digital output pins.
- Interface an external LED with the Arduino Uno.
- Understand the Arduino programming structure using `setup()` and `loop()`.
- Generate periodic digital signals using software delays.

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| Arduino Uno | 1 |
| LED | 1 |
| 220Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

## Software Used

- Arduino IDE
- Arduino AVR Boards Package
- Git & GitHub

---

## Circuit Connections

| Arduino Uno Pin | Connected To |
|-----------------|--------------|
| Digital Pin 9 | LED (Anode) |
| GND | LED (Cathode through a 220Ω resistor) |

> **Note:** If you used the built-in LED on the Arduino Uno, no external LED or resistor is required because the built-in LED is already connected to Digital Pin 13.

---

## Working Principle

The Arduino Uno initializes Digital Pin 13 as an output pin in the `setup()` function. Inside the `loop()` function, the LED is turned ON for one second and then turned OFF for one second. This cycle repeats continuously until the board is powered off or reset.

---

## Project Structure

```text
P02_LED_Blink
│
├── README.md
├── code/
│   └── led_blink.ino
├── images/
│   └── (Circuit Diagram / Output Images)
└── documentation/
    └── (Project Notes)
```

---

## Source Code

The Arduino sketch for this experiment is available in:

```text
code/led_blink.ino
```

---

## Expected Output

- The LED turns ON for five second.
- The LED turns OFF for one second.
- The blinking sequence repeats continuously.

---

## Applications

- Learning Arduino Programming
- GPIO Testing
- Embedded Systems Fundamentals
- Status Indication
- Hardware Diagnostics
- Prototype Development

---

## Learning Outcomes

After completing this project, I was able to:

- Configure digital output pins on the Arduino Uno.
- Interface LEDs with a microcontroller.
- Understand the execution flow of Arduino programs.
- Control hardware using simple embedded software.
- Build a strong foundation for future IoT and embedded system projects.

---

## Future Enhancements

- Control multiple LEDs using different timing patterns.
- Add push-button interaction.
- Implement PWM for LED brightness control.
- Extend the project using sensors and communication modules.

---
## Online Simulation

This project can be simulated directly in Wokwi without requiring any hardware setup.

**Simulation Link:**  
[Launch Wokwi Simulation](https://wokwi.com/projects/468887976259740673)

> **Platform:** Wokwi Online Simulator

## Author

**P Meet Kumar**  
**Roll Number:** IoT 009  
**Program:** IoT and Drone Building 2026
