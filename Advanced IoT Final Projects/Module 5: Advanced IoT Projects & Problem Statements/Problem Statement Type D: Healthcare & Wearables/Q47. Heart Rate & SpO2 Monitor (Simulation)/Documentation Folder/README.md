# Documentation of Question 47

## Overview

This documentation describes the implementation of a Smart Health Monitoring System developed using the ESP32. The system monitors temperature, simulated heart rate, simulated SpO₂ level, and detects falls using an MPU6050 sensor. Health parameters are displayed on an OLED display, logged to the Serial Monitor in CSV format, and visual/audio alerts are generated during abnormal conditions.

## Documentation Contents

- Project Overview
- Repository Structure
- Hardware Components
- Circuit Connections
- Software Requirements
- Implementation Details
- Execution Steps
- Working Principle
- Expected Output
- Code Explanation
- Libraries Used
- Assets Included
- Wokwi Simulation
- Best Practices
- Learning Outcomes
- References
- Conclusion

## Repository Structure

```text
IoT-SUMMER-SCHOOL-26
│
├── Advanced IoT Final Projects
│
└── Module 5: Advanced IoT Projects & Problem Statements
    │
    └── Problem Statement Type D: Healthcare & Wearables
        │
        └── Q47. Heart Rate & SpO2 Monitor (Simulation)
            │
            ├── Assets
            │   ├── Emergency button pressed.png
            │   ├── Fall status detected.png
            │   ├── Heart Rate & SpO2 Monitor demo part 01.mp4
            │   ├── Heart Rate & SpO2 Monitor demo part 02.mp4
            │   ├── Heart Rate & SpO2 Monitor hardware setup.png
            │   ├── Heart Rate & SpO2 Monitor.png
            │   ├── High BPM detected.png
            │   ├── High temperature detected.png
            │   ├── Normal State of all health condition.png
            │   └── SpO2 level decreasing.png
            │
            ├── Code
            │   └── Health_monitor.ino
            │
            ├── Data
            │   └── Health_log.csv
            |  
            ├── Documentation Folder
            │   └── README.md
            │
            └── README.md
```

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 DevKit V1 | 1 |
| DHT22 Sensor *(DHT11 Substitute)* | 1 |
| MPU6050 IMU | 1 |
| OLED SSD1306 (128×64) | 1 |
| Potentiometer *(Heart Rate Simulation)* | 1 |
| Potentiometer *(SpO₂ Simulation)* | 1 |
| Active Buzzer | 1 |
| Red LED | 1 |
| Green LED | 1 |
| Push Button | 1 |
| 220 Ω Resistors | 2 |
| Jumper Wires | As required |

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 DATA | GPIO 15 |
| MPU6050 SDA | GPIO 21 |
| MPU6050 SCL | GPIO 22 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Heart Rate Potentiometer | GPIO 34 |
| SpO₂ Potentiometer | GPIO 35 |
| Green LED | GPIO 26 |
| Red LED | GPIO 27 |
| Active Buzzer | GPIO 18 |
| Push Button | GPIO 4 |

## Software Requirements

- Arduino IDE 2.x
- ESP32 Board Package
- Wokwi Simulator
- Adafruit SSD1306 Library
- Adafruit GFX Library
- Adafruit MPU6050 Library
- Adafruit Unified Sensor Library
- DHTesp Library
- Wire Library

## Implementation Details

- Reads temperature from the DHT22 sensor.
- Simulates heart rate using a potentiometer.
- Simulates SpO₂ level using a second potentiometer.
- Detects falls using MPU6050 acceleration values.
- Displays health information on the OLED display.
- Generates visual and audible alerts during abnormal conditions.
- Logs sensor readings in CSV format through the Serial Monitor.
- Allows the emergency alarm to be acknowledged using the push button.

> **Simulation Note**
>
> Wokwi does not currently provide an official MAX30102 pulse oximeter module. Therefore:
>
> - DHT22 is used as a substitute for the DHT11 sensor.
> - A potentiometer is used to simulate Heart Rate values.
> - A second potentiometer is used to simulate SpO₂ values.
> - MPU6050 is used for fall detection.
>
> These substitutions allow the complete healthcare monitoring logic to be demonstrated while remaining fully compatible with the Wokwi simulator.

## Execution Steps

| Step | Description |
|------|-------------|
| 1 | Create a new ESP32 project in Wokwi. |
| 2 | Add ESP32, DHT22, MPU6050, OLED, two potentiometers, LEDs, buzzer, and push button. |
| 3 | Connect all components according to the circuit connections table. |
| 4 | Install the required Arduino libraries. |
| 5 | Upload the `Health_monitor.ino` program. |
| 6 | Start the Wokwi simulation. |
| 7 | Observe temperature, heart rate, SpO₂, and health status on the OLED. |
| 8 | Rotate the Heart Rate potentiometer to simulate BPM changes. |
| 9 | Rotate the SpO₂ potentiometer to simulate oxygen saturation changes. |
| 10 | Change the MPU6050 orientation/acceleration values to simulate a fall event. |
| 11 | Press the push button to acknowledge and reset the emergency alarm. |
| 12 | Verify the CSV output in the Serial Monitor. |

## Working Principle

The ESP32 periodically acquires sensor data every two seconds. Temperature is obtained from the DHT22 sensor, while heart rate and SpO₂ values are simulated using two independent potentiometers. The MPU6050 continuously monitors acceleration to identify fall events. Based on predefined threshold values, the ESP32 updates the OLED display, activates LEDs and the buzzer when necessary, and logs all readings in CSV format to the Serial Monitor.

## Expected Output

- Live temperature monitoring
- Simulated heart rate display
- Simulated SpO₂ display
- Fall detection
- OLED status updates
- Red/Green LED indication
- Audible buzzer alerts
- Emergency acknowledgement using the push button
- CSV formatted Serial Monitor output

## Code Explanation

| Module | Purpose |
|---------|---------|
| Sensor Initialization | Initializes DHT22, MPU6050, OLED, LEDs, buzzer, and button |
| Sensor Acquisition | Reads temperature and simulated health parameters |
| Fall Detection | Detects sudden acceleration changes using MPU6050 |
| Health Evaluation | Compares sensor values against threshold limits |
| OLED Display | Displays current health information |
| Alert Management | Controls LEDs and buzzer |
| CSV Logger | Logs all readings to the Serial Monitor |

## Libraries Used

| Library | Purpose |
|----------|---------|
| Wire | I²C Communication |
| DHTesp | DHT22 Sensor Interface |
| Adafruit GFX | OLED Graphics |
| Adafruit SSD1306 | OLED Display Driver |
| Adafruit MPU6050 | MPU6050 Interface |
| Adafruit Unified Sensor | Sensor Abstraction |

## Assets Included

| Asset | Description |
|--------|-------------|
| Hardware Setup | Complete circuit wiring |
| Heart Rate & SpO₂ Monitor | OLED output during monitoring |
| Normal State | System operating normally |
| High BPM Detected | Heart rate exceeds threshold |
| High Temperature Detected | Temperature exceeds threshold |
| SpO₂ Level Decreasing | Simulated low SpO₂ condition |
| Fall Status Detected | Fall detection event |
| Emergency Button Pressed | Alarm acknowledgement demonstration |
| Demo Part 01 | Initial system demonstration |
| Demo Part 02 | Alert condition demonstration |

## Wokwi Simulation

**Simulation Link:**

https://wokwi.com/projects/469341476730397697

**Description**

The simulation demonstrates a complete Smart Health Monitoring System using Wokwi-supported components. Heart Rate and SpO₂ values are simulated using potentiometers, while fall detection is implemented using the MPU6050. The OLED display, LEDs, buzzer, and Serial Monitor illustrate the system's response to different health conditions.

## Best Practices

- Use descriptive variable names.
- Keep sensor reading and display functions modular.
- Validate sensor readings before processing.
- Maintain consistent CSV formatting.
- Protect I²C communication by using supported GPIO pins.
- Document hardware substitutions used during simulation.

## Learning Outcomes

- ESP32 peripheral interfacing
- I²C communication
- OLED graphics programming
- Sensor data acquisition
- Health parameter simulation
- Fall detection using IMU
- Embedded alert system design
- Real-time monitoring and data logging

## References

- https://docs.espressif.com/projects/arduino-esp32/
- https://docs.wokwi.com/
- https://github.com/adafruit/Adafruit_SSD1306
- https://github.com/adafruit/Adafruit_MPU6050
- https://github.com/beegee-tokyo/DHTesp

## Conclusion

This project demonstrates the development of a Smart Health Monitoring System using the ESP32 and Wokwi-supported components. Although the simulator does not provide a MAX30102 pulse oximeter, realistic substitutes were used to implement and validate the complete application logic, making the project suitable for learning, demonstration, and future migration to physical hardware.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
