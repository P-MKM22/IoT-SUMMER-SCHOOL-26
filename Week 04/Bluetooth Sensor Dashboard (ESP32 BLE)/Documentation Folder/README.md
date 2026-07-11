# Documentation of Bluetooth Sensor Dashboard (ESP32 BLE)

## Overview

This document provides the complete technical documentation for the **Bluetooth Sensor Dashboard (ESP32 BLE)** developed during **Week 04** of the **IoT Summer School 2026**.

The project demonstrates the workflow of a Bluetooth Low Energy (BLE) based environmental monitoring system using an ESP32 and a DHT sensor. Since **Wokwi and most online circuit simulators do not currently support BLE client applications**, the BLE communication has been simulated through the Serial Monitor while preserving the original BLE architecture, including GATT Services, Characteristics, Descriptors, and UUIDs.

---

## Documentation Contents

- Project Overview
- Components Required
- Pin Configuration
- Circuit Connections
- Step-by-Step Connections
- Working Principle
- BLE Communication Workflow
- GATT Services & Characteristics
- BLE Descriptors
- BLE Scanning Applications
- Implementation Steps
- Serial Monitor Output
- Code Explanation
- Software Concepts Used
- Assets Included
- Wokwi Simulation
- Learning Outcomes
- Best Practices
- Conclusion

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

## Components Required

### Simulation Components

- ESP32 DevKit V1
- DHT22 Sensor *(used in simulation as an alternative to DHT11)*
- Jumper Wires

### Physical Hardware Components

- ESP32 DevKit V1
- DHT11 Sensor
- Android Smartphone
- nRF Connect or LightBlue
- Jumper Wires

---

## Pin Configuration

| Component | ESP32 Pin |
|-----------|-----------|
| DHT Data | GPIO 15 |
| DHT VCC | 3.3V |
| DHT GND | GND |

---

## Circuit Connections

| ESP32 Pin | Connected To |
|-----------|--------------|
| 3.3V | DHT VCC |
| GND | DHT GND |
| GPIO 15 | DHT DATA |

---

## Step-by-Step Connections

### Step 1

Place the ESP32 DevKit V1 in the Wokwi workspace.

### Step 2

Connect the **VCC** pin of the DHT sensor to the **3.3V** pin of the ESP32.

### Step 3

Connect the **GND** pin of the DHT sensor to the **GND** pin of the ESP32.

### Step 4

Connect the **DATA** pin of the DHT sensor to **GPIO 15**.

### Step 5

Upload the Arduino sketch.

### Step 6

Open the Serial Monitor and set the baud rate to **115200**.

### Step 7

Observe the sensor readings and BLE information updating every **3 seconds**.

---

## Working Principle

The ESP32 periodically reads temperature and humidity from the DHT sensor. Every three seconds, the acquired data is combined with a timestamp and prepared for Bluetooth Low Energy communication.

In the simulation, the BLE workflow is represented through the Serial Monitor by displaying the sensor values together with the configured Service UUID and Characteristic UUIDs. On physical hardware, the same data can be accessed through BLE-enabled applications.

---

## BLE Communication Workflow

1. Initialize the ESP32 BLE stack.
2. Create a BLE Service.
3. Create Characteristics for Temperature, Humidity, and Timestamp.
4. Assign unique UUIDs.
5. Attach BLE descriptors.
6. Start BLE advertising.
7. Connect using a BLE scanner.
8. Read updated sensor values.

---

## GATT Services & Characteristics

**GATT (Generic Attribute Profile)** organizes BLE communication using Services and Characteristics.

### Service UUID

```text
12345678-1234-1234-1234-1234567890AB
```

### Characteristic UUIDs

| Characteristic | UUID |
|---------------|------------------------------------------|
| Temperature | 11111111-1111-1111-1111-111111111111 |
| Humidity | 22222222-2222-2222-2222-222222222222 |
| Timestamp | 33333333-3333-3333-3333-333333333333 |

---

## BLE Descriptors

BLE descriptors provide additional metadata for Characteristics, including notification support and access permissions.

In a physical implementation, descriptors can be added using:

```cpp
characteristic->addDescriptor(new BLE2902());
```

The **BLE2902** descriptor enables notifications, allowing connected BLE clients to receive updated sensor values automatically.

---

## BLE Scanning Applications

The completed project can be tested on physical hardware using:

- **nRF Connect**
- **LightBlue**

### Basic Steps

1. Install the BLE scanning application.
2. Enable Bluetooth.
3. Upload the program to the ESP32.
4. Scan for nearby BLE devices.
5. Connect to the ESP32.
6. Open the available Service.
7. Read the Temperature, Humidity, and Timestamp Characteristics.

> **Note:** These applications cannot be used within Wokwi because BLE clients are currently unsupported.

---

## Implementation Steps

1. Initialize the Serial Monitor.
2. Initialize the DHT sensor.
3. Configure BLE UUIDs.
4. Read sensor values.
5. Generate a timestamp.
6. Display the data every three seconds.

---

## Serial Monitor Output

```text
==============================================

Timestamp   : 3000 ms
Temperature : 28.1 °C
Humidity    : 61.4 %

BLE Service UUID
12345678-1234-1234-1234-1234567890AB

Temperature Characteristic
11111111-1111-1111-1111-111111111111

Humidity Characteristic
22222222-2222-2222-2222-222222222222

Timestamp Characteristic
33333333-3333-3333-3333-333333333333

==============================================
```

---

## Code Explanation

### Sensor Initialization

Initializes the DHT sensor for environmental monitoring.

### Data Acquisition

Reads temperature and humidity every three seconds.

### Timestamp Generation

Uses `millis()` to generate the elapsed system time.

### BLE UUID Configuration

Defines the Service UUID and Characteristic UUIDs used by the BLE application.

### Data Display

Displays the latest sensor values and BLE information through the Serial Monitor.

---

## Software Concepts Used

- ESP32 Programming
- Bluetooth Low Energy (BLE)
- GATT Architecture
- BLE Services
- BLE Characteristics
- BLE Descriptors
- UUID Configuration
- DHT Sensor Interfacing
- Environmental Monitoring
- Embedded C++

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Bluetooth Sensor Dashboard (ESP32 BLE) hardware setup.png | Circuit implementation |
| Bluetooth Sensor Dashboard (ESP32 BLE) demo.mp4 | Complete project demonstration |
| Sensor Data 01.png | First captured sensor readings |
| Sensor Data 02.png | Updated sensor readings after periodic refresh |
| Service UUID Set.png | Configured BLE Service and Characteristic UUIDs |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469269102584352769

**Description**

This simulation demonstrates the implementation of a BLE-based environmental monitoring system using an ESP32 and a DHT22 sensor. As BLE client applications are not currently supported in Wokwi or most online simulators, the Bluetooth communication is represented through the Serial Monitor by displaying sensor readings together with the configured BLE UUIDs. The project can be directly migrated to physical ESP32 hardware for complete BLE communication.

---

## Learning Outcomes

- Understand Bluetooth Low Energy fundamentals.
- Learn GATT Services and Characteristics.
- Configure BLE UUIDs.
- Interface a DHT sensor with ESP32.
- Simulate BLE communication.
- Develop an environmental monitoring application.

---

## Best Practices

- Use DHT11 on physical hardware as specified in the assignment.
- Verify GPIO connections before uploading the program.
- Keep the Serial Monitor baud rate at **115200**.
- Use unique UUIDs for each BLE Service and Characteristic.
- Test BLE functionality using physical ESP32 hardware and a BLE scanning application.

---

## Conclusion

The **Bluetooth Sensor Dashboard (ESP32 BLE)** introduces the fundamentals of Bluetooth Low Energy communication for IoT applications. Although BLE client communication cannot currently be demonstrated in Wokwi, the simulation accurately represents the application's architecture and data flow. The project establishes a solid foundation for deploying real-time wireless environmental monitoring systems using physical ESP32 hardware.
