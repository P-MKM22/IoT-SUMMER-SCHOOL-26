# Week 02 – Sensors, IoT Communication, Networking, and Project Development

## Overview

The second week focused on understanding sensors, analog and digital communication, IoT networking, wireless communication protocols, cloud connectivity, and embedded system development using the ESP32. Practical sessions emphasized sensor interfacing, circuit simulation using Tinkercad, and planning the final IoT project. The week concluded with project presentations and technical assignments to strengthen the theoretical concepts.

---

# Topics Covered

## Sensors and Data Acquisition

* Analog Sensors
* Digital Sensors
* Sensor Calibration
* Sensor Accuracy
* Temperature Sensors
* TMP36 Temperature Sensor
* Analog-to-Digital Conversion (ADC)
* ESP32 ADC
* Voltage Measurement
* Signal Conditioning
* Noise Reduction Techniques

## Communication and Networking

* Analog vs Digital Communication
* Wi-Fi Communication
* Bluetooth Communication
* Bluetooth Low Energy (BLE)
* HTTP Protocol
* MQTT Protocol
* Client-Server Architecture
* Machine-to-Machine (M2M) Communication
* Cloud Computing Basics
* IoT Communication Models
* Data Transmission Techniques

## ESP32 Programming

* Reading Analog Sensor Values
* Digital Sensor Interfacing
* Serial Communication
* ESP32 Wireless Connectivity
* Sensor Data Monitoring

## IoT Simulation

* Circuit Design using Tinkercad
* Hardware Simulation
* Testing Virtual Circuits
* Debugging Simulated Projects

---

# Practical Activities

* Interfaced analog and digital sensors with ESP32.
* Measured temperature using the TMP36 temperature sensor.
* Read analog sensor values using the ESP32 ADC.
* Simulated IoT circuits using Tinkercad.
* Configured wireless communication concepts.
* Discussed communication protocols used in IoT.

---

# Project Work

During this week, the final project was planned and discussed in detail. The hardware components, software requirements, implementation strategy, and system workflow were finalized.

## Final Project

### IoT-Based Mortal Kombat Game using ESP32, OLED Display, LEDs, and MPU6050 IMU

### Components Used

* ESP32 Development Board
* OLED Display
* MPU6050 IMU Sensor
* LEDs
* Breadboard
* Jumper Wires
* USB Cable

### Project Description

The project is a gesture-controlled IoT-based Mortal Kombat game developed using the ESP32 microcontroller. The MPU6050 IMU detects player hand gestures, which are processed by the ESP32 to control character movements and attacks. The OLED display provides real-time game animations, while LEDs are used to indicate gameplay events and system status.

---

# Project Presentation

A technical presentation was delivered covering:

* Project Title
* Problem Statement
* Objectives
* Components Used
* System Architecture
* Working Methodology
* Expected Output
* Future Scope

---

# Additional Practical Project

During Week 02, an additional Arduino-based embedded systems project was successfully designed, simulated, and documented to strengthen the understanding of digital electronics, timing operations, and event-driven programming.

## Traffic Light Controller using Arduino UNO

### Components Used

- Arduino UNO
- Breadboard
- Red LED
- Yellow LED
- Green LED
- Push Button
- 220Ω Resistors
- 10kΩ Pull-down Resistor
- Jumper Wires

### Project Description

The Traffic Light Controller simulates a real-world traffic signal using three LEDs representing the **Red**, **Yellow**, and **Green** lights. The system follows a predefined sequence in which the RED light remains ON for **5 seconds**, the YELLOW light for **2 seconds**, and the GREEN light for **4 seconds**.

A pedestrian push button is integrated into the system to provide a safe road-crossing mechanism. Whenever the button is pressed, the controller immediately interrupts the current traffic cycle, activates the RED signal, and holds it for **8 seconds** before resuming the normal traffic sequence.

The system continuously prints the current traffic light state along with the execution timestamp (`millis()`) to the Serial Monitor for monitoring and debugging.

### Features

- Automatic Traffic Light Sequencing
- Pedestrian Crossing Request
- Immediate RED Signal Override
- 8-Second Pedestrian Safety Timer
- Serial Monitor Timestamp Logging
- Modular Arduino Program
- Wokwi Simulator Compatible

### Technologies Used

- Arduino Programming
- Digital Output Control
- Push Button Interfacing
- Timing Operations
- Serial Communication
- Wokwi Online Simulator

### Wokwi Simulation

https://wokwi.com/projects/469047666148879361

---
# Assignments

## Assignment 1 – TMP36 Temperature Sensor

Study the working principle of the TMP36 temperature sensor.

Tasks included:

* Understanding how the TMP36 measures temperature.
* Studying the voltage-to-temperature conversion formula.
* Learning how temperature values are calculated using Arduino/ESP32.
* Understanding practical applications of the TMP36 sensor.

---

## Assignment 2 – Theory Questions

The following theory questions were assigned to strengthen the understanding of IoT networking and communication concepts:

### 1. Controller Area Network (CAN)

Study the Controller Area Network (CAN) protocol, including its architecture, working principle, advantages, disadvantages, and real-world applications in embedded systems and the automotive industry.

### 2. BLE vs Wi-Fi

Compare **Bluetooth Low Energy (BLE)** and **Wi-Fi** based on:

* Communication range
* Power consumption
* Data transfer speed
* Advantages
* Limitations
* IoT applications

### 3. I2C Address Conflict

**Scenario:**

You are building an environmental monitoring station and accidentally purchased three I2C temperature sensors that all have the same fixed hardware address (for example, **0x77**).

Research how an **I2C Multiplexer (TCA9548A)** solves this address conflict and explain:

* Working principle
* Advantages
* Circuit implementation
* Practical IoT applications

### 4. Machine-to-Machine (M2M) Communication

Study Machine-to-Machine (M2M) communication, including:

* Definition
* Architecture
* Communication technologies
* Advantages
* Challenges
* Applications in IoT

---

## Assignment 3 – Project Planning

Prepare the documentation for the final IoT project.

Tasks included:

* Selecting the project idea.
* Identifying the hardware components.
* Preparing the project workflow.
* Creating a presentation explaining the project.

---

## Assignment 4 – Tinkercad Project Submission

* Design the assigned IoT circuit using Tinkercad.
* Verify the simulation.
* Submit the completed Tinkercad project through the provided Google Form.

---

# Skills Acquired

* Sensor Interfacing
* Analog-to-Digital Conversion (ADC)
* ESP32 Programming
* Temperature Sensor Integration
* Wireless Communication
* IoT Networking
* Tinkercad Circuit Simulation
* Technical Presentation Skills
* Project Planning and Documentation
* Embedded System Development

---

# Learning Outcomes

By the end of Week 02, I was able to:

* Interface analog and digital sensors with the ESP32.
* Understand the working principle of the TMP36 temperature sensor.
* Read and process analog sensor data using the ESP32 ADC.
* Compare BLE and Wi-Fi for IoT applications.
* Explain CAN and M2M communication concepts.
* Understand how an I2C multiplexer resolves address conflicts.
* Simulate IoT circuits using Tinkercad.
* Plan and present an IoT project.
* Develop documentation for embedded and IoT systems.
