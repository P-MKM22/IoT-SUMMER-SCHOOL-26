# Wi-Fi Temperature Monitor (ESP8266 or ESP32)

## Overview

The Wi-Fi Temperature Monitor is a practical IoT application that demonstrates how an ESP32 can be used as a standalone web server for real-time environmental monitoring. The system acquires temperature and humidity data from a DHT11 sensor and hosts an interactive web dashboard over a local Wi-Fi network. The dashboard also allows users to control the onboard LED remotely while displaying the device uptime and continuously updated sensor readings.

---

## Objectives

- Develop a Wi-Fi-enabled environmental monitoring system using ESP32.
- Interface the DHT11 sensor for temperature and humidity measurement.
- Create a browser-based monitoring dashboard.
- Implement remote LED control through a web interface.
- Demonstrate local network communication using an embedded web server.
- Understand the fundamentals of IoT-based monitoring systems.

---

## Features

- Real-Time Temperature Monitoring
- Real-Time Humidity Monitoring
- ESP32 Embedded Web Server
- Interactive Browser-Based Dashboard
- Remote LED ON/OFF Control
- Device Uptime Monitoring
- Automatic Dashboard Refresh
- Responsive User Interface
- Physical Hardware Demonstration

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Development Board | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| LED | 1 |
| 220 Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- WiFi Library
- WebServer Library
- DHT Sensor Library
- Google Chrome / Microsoft Edge
- Local Wi-Fi Network

---

## Project Structure

```text
Week 04
│
└── Wi-Fi Temperature Monitor (ESP8266 or ESP32)
    │
    ├── Code
    │   └── Wi-Fi Temperature Monitor.ino
    │
    ├── WiFi_Webserver
    │   └── Screenshots
    │       ├── LED OFF using webpage.jpeg
    │       ├── LED ON using webpage.jpeg
    │       ├── Wi-Fi Temperature Monitor Hardware setup.png
    │       ├── Wi-Fi Temperature Monitor part 01.mp4
    │       └── Wi-Fi Temperature Monitor part 02.mp4
    │
    ├── Documentation Folder
    │   └── README.md
    │
    └── README.md
```

---

## Assets Included

| Asset | Description |
|--------|-------------|
| **Wi-Fi Temperature Monitor Hardware setup.png** | Complete hardware setup of the ESP32, DHT11 sensor, and LED used for the project. |
| **LED OFF using webpage.jpeg** | Web dashboard showing the LED in the OFF state with live sensor readings. |
| **LED ON using webpage.jpeg** | Web dashboard showing the LED in the ON state after remote control through the webpage. |
| **Wi-Fi Temperature Monitor part 01.mp4** | Demonstrates Wi-Fi connection, web server initialization, and live environmental monitoring. |
| **Wi-Fi Temperature Monitor part 02.mp4** | Demonstrates LED control through the web interface and complete project functionality. |

---

## Wokwi Simulation

**Simulation Status:** Not Available

This project was implemented and validated using the physical ESP32 Development Board and hardware components instead of a simulation environment.

---

## Learning Outcomes

After completing this task, the following concepts were learned:

- ESP32 Wi-Fi configuration
- Embedded HTTP web server development
- DHT11 sensor interfacing
- Browser-based IoT dashboard development
- Remote hardware control
- Local network communication
- Real-time environmental monitoring
- Practical IoT application development

---

## Future Improvements

- MQTT-based communication
- Cloud platform integration
- Mobile application support
- Data logging and analytics
- Graphical visualization of historical data
- Email and notification alerts
- OTA firmware updates
- Multi-sensor environmental monitoring

---

## References

- Arduino Documentation
- ESP32 Arduino Documentation
- ESP32 WebServer Library Documentation
- Adafruit DHT Sensor Library
- Indian Institute of Technology Jammu – IoT and Drone Building Summer School 2026

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
