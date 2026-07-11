# Documentation of Question 32

## Overview

This document provides the complete technical documentation for **Question 32 – Bluetooth Sensor Dashboard (ESP32 BLE)** developed as part of the **Advanced IoT Final Project**.

The objective of this project is to monitor environmental conditions using an ESP32 and a DHT sensor while demonstrating the architecture of **Bluetooth Low Energy (BLE)** communication. Sensor readings are updated every three seconds and prepared for transmission using **GATT Services**, **Characteristics**, and **Descriptors**.

> **Simulation Note**
>
> Currently, **Wokwi and most online circuit simulators do not support BLE client applications** such as **nRF Connect** or **LightBlue**. Therefore, the BLE communication has been simulated using the **Serial Monitor**, where Temperature, Humidity, Timestamp, Service UUID, and Characteristic UUID information are displayed every three seconds. The same project can be uploaded to a physical ESP32 to achieve complete BLE functionality without major code modifications.

---

## Documentation Contents

- Project Overview
- Components Required
- Pin Configuration
- Circuit Connections
- Step-by-Step Connections
- Working Principle
- BLE Communication Workflow
- GATT Services
- GATT Characteristics
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
Advanced IoT Final Projects
│
└── Module 4: Wireless Communication & IoT Protocols
    │
    └── Section A: Bluetooth Projects
        │
        └── Q32. Bluetooth Sensor Dashboard (ESP32 BLE)
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
            │   └── ESP32 BLE.ino
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

Place the ESP32 DevKit V1 on the workspace.

### Step 2

Connect the **VCC** pin of the DHT sensor to the **3.3V** pin of the ESP32.

### Step 3

Connect the **GND** pin of the DHT sensor to the **GND** pin of the ESP32.

### Step 4

Connect the **DATA** pin of the DHT sensor to **GPIO 15**.

### Step 5

Upload the Arduino sketch to the ESP32.

### Step 6

Open the Serial Monitor.

### Step 7

Set the Serial Monitor baud rate to **115200**.

### Step 8

Observe the Temperature, Humidity, Timestamp, Service UUID, and Characteristic UUID information updating every **3 seconds**.

---

## Working Principle

The ESP32 continuously reads temperature and humidity from the DHT sensor. Every three seconds, the acquired data is processed together with the current system timestamp.

Since BLE client applications cannot currently be simulated in Wokwi or most online circuit simulators, the BLE communication is represented by displaying the sensor values, Service UUID, and Characteristic UUIDs through the Serial Monitor. When deployed on a physical ESP32, the same information can be exposed through BLE GATT Characteristics, allowing nearby BLE-enabled devices to access the live sensor data.

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469269102584352769

**Description**

This simulation demonstrates the implementation of the **Bluetooth Sensor Dashboard (ESP32 BLE)** using an ESP32 and a DHT22 sensor. Since **Wokwi and most online circuit simulators do not currently support BLE client applications** such as **nRF Connect** or **LightBlue**, Bluetooth communication has been simulated through the Serial Monitor.

The simulation periodically displays **Temperature**, **Humidity**, **Timestamp**, **Service UUID**, and **Characteristic UUIDs** every three seconds, representing the BLE data that would normally be broadcast by the ESP32. This approach preserves the BLE architecture and provides a smooth transition to physical hardware, where the same application can be tested using BLE scanning applications without major code modifications.

---

## BLE Communication Workflow

### Step 1

Initialize the ESP32 BLE stack.

### Step 2

Create a BLE Service for environmental monitoring.

### Step 3

Create individual Characteristics for:

- Temperature
- Humidity
- Timestamp

### Step 4

Assign unique UUIDs to the Service and each Characteristic.

### Step 5

Attach BLE descriptors to every Characteristic.

### Step 6

Start BLE advertising.

### Step 7

Allow nearby BLE-enabled devices to discover the ESP32.

### Step 8

Transmit updated sensor readings every three seconds.

---

## GATT Services

**GATT (Generic Attribute Profile)** defines how BLE devices organize and exchange data.

A **Service** groups multiple Characteristics that belong to the same application. In this project, a single BLE Service is used to organize all environmental monitoring data.

### Service UUID

```text
12345678-1234-1234-1234-1234567890AB
```

---

## GATT Characteristics

A **Characteristic** represents an individual data item inside a BLE Service.

Three Characteristics are defined in this project.

| Characteristic | Purpose |
|---------------|---------|
| Temperature | Stores temperature readings |
| Humidity | Stores humidity readings |
| Timestamp | Stores the current system timestamp |

### Characteristic UUIDs

| Characteristic | UUID |
|---------------|------------------------------------------|
| Temperature | 11111111-1111-1111-1111-111111111111 |
| Humidity | 22222222-2222-2222-2222-222222222222 |
| Timestamp | 33333333-3333-3333-3333-333333333333 |

---

## BLE Descriptors

Descriptors provide additional information about a BLE Characteristic and define how the characteristic behaves.

They are commonly used to specify:

- Read permissions
- Write permissions
- Notification support
- Value description
- Units of measurement

A descriptor is typically attached using:

```cpp
characteristic->addDescriptor(new BLE2902());
```

The **BLE2902 Descriptor** enables notification support, allowing connected BLE clients to automatically receive updated sensor readings without repeatedly requesting them.

Although BLE descriptors cannot be demonstrated in Wokwi or other online simulators, they are an essential component of a complete BLE implementation and should always be included when deploying the project on physical ESP32 hardware.
