# Bluetooth Sensor Dashboard (ESP32 BLE)

## Overview

The **Bluetooth Sensor Dashboard (ESP32 BLE)** is a wireless environmental monitoring project developed during **Week 04** of the **IoT Summer School 2026**. The project demonstrates how an ESP32 can periodically collect temperature and humidity data from a DHT sensor and prepare it for Bluetooth Low Energy (BLE) communication.

As BLE client applications are currently not supported by **Wokwi and most online circuit simulators**, the Bluetooth communication has been simulated using the Serial Monitor while preserving the complete BLE architecture. The project serves as a foundation for developing real-time wireless IoT monitoring systems on physical ESP32 hardware.

---

## Project Structure

```text
Week 04
│
└── Bluetooth Sensor Dashboard (ESP32 BLE)
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
    │   └── ESP32_BLE.ino
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## Project Summary

This project demonstrates the workflow of a Bluetooth Low Energy (BLE) sensor node using an ESP32. The system periodically acquires environmental data, generates a timestamp, and prepares the information for transmission using BLE Services and Characteristics.

Although Bluetooth communication cannot be demonstrated in the simulator, the project maintains the same architecture that would be used on physical hardware, making it easy to migrate without redesigning the application.

---

## Key Features

- Periodic temperature and humidity monitoring
- ESP32-based BLE application architecture
- Timestamp generation for sensor readings
- Simulated BLE data broadcasting
- BLE Service and Characteristic UUID implementation
- Clean and modular program structure
- Compatible with deployment on physical ESP32 hardware

---

## Technologies Used

- ESP32 DevKit V1
- DHT22 *(used as a simulation alternative to DHT11)*
- Arduino IDE
- Wokwi Simulator
- Bluetooth Low Energy (BLE)
- Embedded C++

---

## Simulation

**Wokwi Project**

https://wokwi.com/projects/469269102584352769

**Description**

The simulation demonstrates the working logic of an ESP32 BLE Sensor Dashboard. Temperature, humidity, timestamp, and BLE UUID information are displayed through the Serial Monitor at regular intervals, representing the information that would normally be available through Bluetooth Low Energy communication. The implementation provides an effective simulation of the project workflow while remaining fully compatible with physical ESP32 hardware.

---

## Repository Contents

| Directory | Description |
|-----------|-------------|
| Assets | Hardware images, sensor output screenshots, and demonstration video |
| Code | Arduino source code for the ESP32 BLE Sensor Dashboard |
| Documentation | Detailed project documentation, implementation details, BLE concepts, and hardware connections |

---

## Learning Outcomes

After completing this project, the following concepts were explored:

- Bluetooth Low Energy (BLE) fundamentals
- Environmental monitoring using ESP32
- DHT sensor interfacing
- GATT Services and Characteristics
- UUID configuration for BLE communication
- Periodic sensor acquisition
- Embedded system programming
- IoT sensor dashboard development

---

## Future Enhancements

- Enable live BLE communication using a physical ESP32.
- Connect the project with nRF Connect or LightBlue for real-time monitoring.
- Add support for multiple environmental sensors.
- Integrate cloud storage for remote monitoring.
- Develop a mobile dashboard application.
- Implement BLE notifications for automatic sensor updates.
- Extend the project with battery monitoring and device diagnostics.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
