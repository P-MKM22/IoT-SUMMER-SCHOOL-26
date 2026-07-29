# Q 33. Wi-Fi Temperature Monitor (ESP8266/ESP32)

## Overview

This project demonstrates a Wi-Fi-enabled environmental monitoring system using the ESP32 Development Board. The ESP32 hosts a local web server that displays real-time temperature and humidity readings obtained from the DHT11 sensor. The web dashboard also provides remote LED control, device uptime monitoring, and automatic data refresh, enabling users to monitor environmental conditions from any browser connected to the same local network.

---

## Objectives

- Establish Wi-Fi connectivity using the ESP32.
- Host a local HTTP web server.
- Monitor temperature and humidity using the DHT11 sensor.
- Display live sensor readings through a web interface.
- Control the onboard LED remotely.
- Display the device uptime.
- Develop a browser-based IoT monitoring dashboard.

---

## Features

- ESP32 Wi-Fi Web Server
- Real-Time Temperature Monitoring
- Real-Time Humidity Monitoring
- Interactive Web Dashboard
- Remote LED ON/OFF Control
- Device Uptime Display
- Automatic Page Refresh (10 Seconds)
- Responsive Browser Interface
- Physical Hardware Implementation

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

- Arduino IDE (Latest Stable Version)
- ESP32 Board Package
- WiFi Library
- WebServer Library
- DHT Sensor Library
- Google Chrome / Microsoft Edge
- Local Wi-Fi Network

---

## Project Structure

```text
Q33. Wi-Fi Temperature Monitor (ESP8266 or ESP32)
│
├── Assets
│   ├── Wi-Fi Temperature Monitor Hardware setup.png
│   ├── LED OFF using webpage.jpeg
│   ├── LED ON using webpage.jpeg
│   ├── Wi-Fi Temperature Monitor part 01.mp4
│   └── Wi-Fi Temperature Monitor part 02.mp4
│
├── Code
│   └── Wi-Fi-Temperature-Monitor.ino
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
| **Wi-Fi Temperature Monitor Hardware setup.png** | Complete hardware setup of the ESP32, DHT11 sensor, LED, and supporting connections used for the project. |
| **LED OFF using webpage.jpeg** | Web dashboard displaying the LED in the OFF state along with live temperature, humidity, LED status, and device uptime. |
| **LED ON using webpage.jpeg** | Web dashboard displaying the LED in the ON state after being toggled through the browser interface. |
| **Wi-Fi Temperature Monitor part 01.mp4** | Demonstrates the ESP32 connecting to the Wi-Fi network, hosting the web server, and displaying live environmental data. |
| **Wi-Fi Temperature Monitor part 02.mp4** | Demonstrates successful LED control through the web dashboard and verifies the complete working of the project. |

---

## Wokwi Simulation

**Simulation Status:** Not Available

This project was implemented and validated using a physical ESP32 Development Board and hardware components to demonstrate real-time Wi-Fi communication and browser-based environmental monitoring.

---

## Learning Outcomes

After completing this project, the following concepts were learned:

- ESP32 Wi-Fi configuration
- Embedded HTTP web server implementation
- Browser-based IoT dashboards
- Real-time environmental monitoring
- Remote device control over Wi-Fi
- Dynamic HTML generation using ESP32
- Local network communication
- Embedded IoT application development

---

## Future Improvements

The project can be further enhanced by:

- Cloud-based IoT monitoring
- MQTT integration
- Blynk dashboard support
- Mobile application interface
- Data logging using Firebase
- Historical sensor graphs
- Email/SMS alert system
- Edge AI-based environmental analysis

---

## References

- Arduino Documentation
- ESP32 Arduino Documentation
- ESP32 WebServer Library Documentation
- Adafruit DHT Sensor Library
- IIT Jammu Summer School 2026 – Module 04 Assignment Manual

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
