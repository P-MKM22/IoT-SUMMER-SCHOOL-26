# IoT & Drone Building Summer School 🚁🔌

## What is this?
This repository contains all the code, schematics, and project files from my IoT and Drone Building Summer School assignments. It is divided into two main tracks: ground-level embedded systems (IoT) and aerial mechanics/telemetry (Drone Building). 

The goal of these assignments is to bridge the gap between microcontroller sensor networks and active flight stabilization systems.

## Repository Structure

### 📡 1. IoT Assignments
This directory contains the code for microcontroller-based sensor networks, data logging, and wireless communication.
* **`Assignment_1_Sensor_Data/`**: Code for reading and filtering raw data from physical sensors (e.g., temperature, gyros, or ultrasonic).
* **`Assignment_2_Wireless_Comms/`**: Peer-to-peer and Wi-Fi communication scripts (like ESP-NOW or MQTT) to send telemetry data remotely.
* **`Assignment_3_IoT_Dashboard/`**: Scripts and server-side code to visualize the hardware data in real-time.

### 🚁 2. Drone Building Assignments
This directory focuses on flight controllers, motor calibration, and drone physics.
* **`Assignment_1_Motor_Calibration/`**: Scripts and configuration files for testing BLDC motors and calibrating Electronic Speed Controllers (ESCs).
* **`Assignment_2_Flight_Controller/`**: Custom PID tuning logs and receiver mapping for the flight controller setup.
* **`Assignment_3_Telemetry_Integration/`**: Code to beam real-time flight data (battery voltage, altitude, pitch/roll) back to the ground station.

## Hardware & Software Stack
**Hardware Used:**
* Microcontrollers (e.g., ESP32, Arduino, or NodeMCU)
* Flight Controller (e.g., Pixhawk, F4/F7 Stacks)
* Sensors (IMU/MPU6050, Ultrasonic, Barometer)
* Drone Hardware (BLDC Motors, ESCs, LiPo Batteries, Radio Receiver)

**Software & Tools:**
* Arduino IDE / VS Code (PlatformIO)
* Betaflight / Mission Planner (for drone configuration)

## How to Navigate This Repo
Each assignment folder contains its own specific instructions and code. 
1. Navigate to the specific assignment folder you want to review.
2. Open the `.ino` / `.cpp` / `.py` files in your IDE.
3. Check the wiring diagrams (if included) before flashing the code to your microcontrollers or flight controller to avoid frying the boards!

---
*Documenting the journey from breadboards to the skies.*
