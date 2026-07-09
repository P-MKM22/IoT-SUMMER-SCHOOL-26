# Q13 – Arduino UNO Pin Types

## Question

**List and explain with examples: Digital Input, Digital Output, Analog Input, PWM Output, and I2C/SPI pins available on Arduino UNO. For each, give one real IoT use case.**

---

# Introduction

The Arduino UNO provides different types of pins for interfacing with sensors, actuators, and communication modules. Each pin type serves a specific purpose, enabling the Arduino to interact with external hardware and build a wide range of embedded and IoT applications.

---

# Arduino UNO Pin Types

| Pin Type | Description | Example | Real IoT Use Case |
|----------|-------------|---------|-------------------|
| **Digital Input** | Reads digital signals with two possible states: HIGH or LOW. | Reading a push button or motion sensor. | Smart door lock that detects button presses or door sensors. |
| **Digital Output** | Sends HIGH or LOW signals to control external devices. | Turning an LED or relay ON/OFF. | Smart street lighting system controlling street lights. |
| **Analog Input** | Reads varying voltage levels (0–5V) and converts them into digital values (0–1023). | Reading a potentiometer or soil moisture sensor. | Smart irrigation system monitoring soil moisture. |
| **PWM Output** | Generates Pulse Width Modulation (PWM) signals to simulate analog output. | Controlling LED brightness or DC motor speed. | Smart lighting system with adjustable brightness. |
| **I2C/SPI Pins** | Communication interfaces used to exchange data with external modules and sensors. | OLED Display, MPU6050, SD Card Module. | Environmental monitoring system using multiple sensors and displays. |

---

# Explanation of Each Pin Type

## 1. Digital Input

Digital input pins receive binary signals from external devices. They detect whether the input is **HIGH** or **LOW**.

### Example

- Push Button
- PIR Motion Sensor
- Limit Switch

### Real IoT Use Case

A **smart security system** reads the output of a PIR motion sensor to detect human movement and trigger an alarm.

---

## 2. Digital Output

Digital output pins provide HIGH or LOW signals to control electronic devices.

### Example

- LED
- Relay Module
- Buzzer

### Real IoT Use Case

A **smart home automation system** switches household lights ON or OFF using relay modules controlled by Arduino.

---

## 3. Analog Input

Analog input pins measure continuous voltage levels and convert them into digital values using the Arduino's Analog-to-Digital Converter (ADC).

### Example

- Potentiometer
- LDR
- Soil Moisture Sensor

### Real IoT Use Case

A **smart irrigation system** monitors soil moisture and automatically starts watering when the soil becomes dry.

---

## 4. PWM Output

PWM (Pulse Width Modulation) outputs generate varying duty cycles to simulate analog voltage using digital pins.

### Example

- LED Brightness Control
- DC Motor Speed Control

### Real IoT Use Case

A **smart street lighting system** automatically adjusts LED brightness according to ambient light conditions, reducing power consumption.

---

## 5. I2C/SPI Communication Pins

These communication protocols allow Arduino to exchange data efficiently with multiple external devices.

### I2C Pins

- SDA → A4
- SCL → A5

### SPI Pins

- MOSI → D11
- MISO → D12
- SCK → D13
- SS → D10

### Example

- OLED Display
- MPU6050 Accelerometer and Gyroscope
- EEPROM
- SD Card Module

### Real IoT Use Case

A **smart environmental monitoring system** uses an OLED display and multiple I2C sensors to measure and display temperature, humidity, and air quality.

---

# Summary Table

| Pin Type | Arduino UNO Pins | Function |
|----------|------------------|----------|
| Digital Input | D0–D13 | Read digital signals |
| Digital Output | D0–D13 | Control digital devices |
| Analog Input | A0–A5 | Read analog sensor values |
| PWM Output | D3, D5, D6, D9, D10, D11 | Generate PWM signals |
| I2C | SDA (A4), SCL (A5) | Two-wire communication |
| SPI | D10–D13 | High-speed serial communication |

---

# Conclusion

The Arduino UNO offers multiple pin types to support digital control, analog sensing, PWM-based output, and communication with peripheral devices. Understanding these pin functions enables efficient interfacing with sensors, actuators, and communication modules, forming the foundation for developing reliable embedded and IoT applications.

---

# Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
