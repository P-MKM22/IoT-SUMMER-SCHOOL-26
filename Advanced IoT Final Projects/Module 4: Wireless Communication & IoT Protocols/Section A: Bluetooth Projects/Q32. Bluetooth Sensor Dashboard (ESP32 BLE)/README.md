# Q 32 – Bluetooth Sensor Dashboard (ESP32 BLE)

## Overview

This project demonstrates the concept of a **Bluetooth Low Energy (BLE) based environmental monitoring system** using the ESP32 platform. The system periodically acquires temperature and humidity data from a DHT sensor and prepares the information for wireless transmission through BLE.

Since **Wokwi and most online circuit simulators do not currently support BLE client applications**, the BLE communication is simulated using the Serial Monitor while preserving the original BLE architecture, including Service UUIDs and Characteristic UUIDs. This allows the same project to be migrated to physical ESP32 hardware with minimal modifications.

---

## Objectives

- Understand the fundamentals of Bluetooth Low Energy (BLE).
- Build a basic BLE sensor dashboard using ESP32.
- Read environmental data from a DHT sensor.
- Simulate BLE data broadcasting.
- Learn the role of GATT Services and Characteristics.
- Prepare a project suitable for deployment on physical ESP32 hardware.

---

## Repository Structure

```text
Q32. Bluetooth Sensor Dashboard (ESP32 BLE)
│
├── Assets
│   ├── Bluetooth Sensor Dashboard (ESP32 BLE) demo.mp4
│   ├── Bluetooth Sensor Dashboard (ESP32 BLE) hardware setup.png
│   ├── Sensor Data 01.png
│   ├── Sensor Data 02.png
│   ├── Service UUID Set.png
│   └── .gitkeep
│
├── Code
│   ├── ESP32 BLE.ino
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

## Project Highlights

- ESP32-based BLE application
- Environmental monitoring using a DHT sensor
- Sensor update interval of 3 seconds
- Simulated BLE broadcasting through Serial Monitor
- Predefined Service UUID and Characteristic UUIDs
- Easily portable to physical ESP32 hardware
- Modular and well-documented implementation

---

## BLE Data Structure

The simulated BLE dashboard prepares the following information for transmission.

| BLE Data | Description |
|----------|-------------|
| Temperature | Current ambient temperature |
| Humidity | Current relative humidity |
| Timestamp | System time generated using `millis()` |

---

## BLE UUID Configuration

| Item | Purpose |
|------|---------|
| Service UUID | Identifies the environmental monitoring service |
| Temperature UUID | Represents temperature data |
| Humidity UUID | Represents humidity data |
| Timestamp UUID | Represents system timestamp |

---

## Simulation Notes

The complete BLE communication workflow cannot be demonstrated inside Wokwi because BLE client applications are not supported. Instead, the simulation verifies:

- Sensor acquisition
- Data formatting
- Timestamp generation
- UUID configuration
- Periodic data updates
- Overall application logic

This approach ensures that the project remains compatible with actual ESP32 hardware while allowing functional verification inside the simulator.

---

## Assets

| Asset | Description |
|--------|-------------|
| Hardware Setup | Circuit implementation used in the simulation |
| Demo Video | Complete project demonstration |
| Sensor Data 01 | Initial sensor readings captured during execution |
| Sensor Data 02 | Subsequent sensor readings after periodic updates |
| Service UUID Set | Screenshot showing the configured BLE UUIDs |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469269102584352769

**Description**

This simulation demonstrates the working principle of an ESP32-based BLE Sensor Dashboard. Temperature, humidity, timestamp, and BLE UUID information are periodically displayed through the Serial Monitor, representing the data that would normally be available to BLE clients. The implementation provides a reliable simulation environment while maintaining compatibility with physical BLE hardware.

---

## Future Enhancements

- Enable real-time BLE communication using physical ESP32 hardware.
- Integrate nRF Connect or LightBlue for live sensor monitoring.
- Add battery level and device status characteristics.
- Include multiple environmental sensors within the same BLE service.
- Store historical sensor data for analysis.
- Develop a mobile application for custom BLE visualization.
- Expand the dashboard with cloud connectivity for remote monitoring.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
