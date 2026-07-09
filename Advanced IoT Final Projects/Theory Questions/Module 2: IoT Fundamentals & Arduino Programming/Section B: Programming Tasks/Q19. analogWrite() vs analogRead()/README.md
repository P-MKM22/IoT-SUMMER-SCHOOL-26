# Q 19 – Difference Between analogWrite() and analogRead()

## Question

**What is the difference between `analogWrite()` and `analogRead()` in Arduino? What is PWM and why is it used? Give a practical IoT example for each. (2 Marks)**

---

# Introduction

Arduino provides functions for reading analog sensor values and generating PWM signals to control output devices. Although `analogRead()` and `analogWrite()` have similar names, they perform entirely different operations.

---

# Difference Between analogRead() and analogWrite()

| Feature | analogRead() | analogWrite() |
|---------|--------------|---------------|
| Purpose | Reads analog voltage from a sensor | Generates a PWM signal to simulate analog output |
| Operation | Input | Output |
| Pin Type | Analog input pins (A0–A5) | PWM-enabled digital pins (e.g., D3, D5, D6, D9, D10, D11 on Arduino UNO) |
| Return Value | Integer value (0–1023) | No return value |
| Typical Devices | LDR, Potentiometer, Temperature Sensor | LED, DC Motor, Servo Speed Control |

---

# What is PWM?

**Pulse Width Modulation (PWM)** is a technique used to simulate an analog output by rapidly switching a digital pin between HIGH and LOW. By varying the duty cycle, the average output voltage changes, allowing control of devices such as LEDs and motors.

---

# Why is PWM Used?

- Controls LED brightness
- Controls DC motor speed
- Reduces power consumption
- Simulates analog output using digital pins

---

# Practical IoT Examples

### analogRead()

A smart irrigation system reads soil moisture sensor values using `analogRead()` to determine when watering is required.

### analogWrite()

A smart street lighting system adjusts LED brightness using `analogWrite()` based on ambient light levels to conserve energy.

---

# Conclusion

`analogRead()` is used to read analog sensor inputs, whereas `analogWrite()` generates PWM signals to control output devices. Together, these functions are fundamental for building interactive Arduino and IoT applications.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
