# Documentation

## Overview

This documentation explains the implementation of an Environmental Monitoring Station using an ESP32 and a DHT22 sensor (used in Wokwi as a substitute for the DHT11). The system reads temperature and humidity every two seconds, displays the readings in CSV format, and indicates environmental conditions using Red and Green LEDs.

> **Note:** The assignment specifies the DHT11 sensor. Since Wokwi provides the DHT22 sensor, it is used only for simulation.

---

## Documentation Contents

- Overview
- Project Structure
- Hardware Components
- Software Requirements
- Circuit Connections
- Wokwi Simulation
- Implementation Details
- Execution Steps
- Working Principle
- Expected Output
- Sample CSV Data
- Code Explanation
- Libraries Used
- Learning Outcomes
- Best Practices
- References
- Conclusion

---

## Project Structure

```text
Week 03
│
├── README.md
│
└── Environmental Monitoring Station (DHT11)
    │
    ├── Assets
    │   ├── Hardware Connection.png
    │   ├── Serial Monitor Output.png
    │   ├── Normal Condition.png
    │   ├── High Temperature Alert.png
    │   └── High Humidity Alert.png
    │
    ├── Code
    │   └── Environmental_Monitoring_Station.ino
    │
    ├── Data
    │   └── sample_readings.csv
    │
    ├── Documentation
    │   └── README.md
    │
    └── README.md
```

---

## Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 DevKit V1 | 1 |
| DHT22 Sensor (Wokwi) | 1 |
| Red LED | 1 |
| Green LED | 1 |
| 220 Ω Resistors | 2 |
| Jumper Wires | As required |

---

## Software Requirements

- Arduino IDE 2.x or later
- ESP32 Board Package
- DHTesp Library
- Wokwi Simulator
- Serial Monitor (115200 baud)

---

## Circuit Connections

| ESP32 Pin | Component |
|------------|-----------|
| 3.3V | DHT22 VCC |
| GND | DHT22 GND |
| GPIO15 | DHT22 DATA |
| GPIO18 | Red LED |
| GPIO19 | Green LED |
| GND | LED Cathodes through 220 Ω resistors |

---

## Wokwi Simulation

### Simulation Link

https://wokwi.com/projects/469171145460939777

### Description

The simulation demonstrates real-time temperature and humidity monitoring using the ESP32. Sensor readings are displayed every two seconds, and LEDs indicate whether the environmental conditions are normal or exceed the defined limits.

---

## Implementation Details

The project performs the following tasks:

- Initializes the ESP32 and DHT sensor.
- Reads temperature and humidity every two seconds.
- Converts Celsius to Fahrenheit.
- Prints data in CSV format.
- Compares readings with threshold values.
- Controls the Red and Green LEDs accordingly.

---

## Execution Steps

### Step 1

Open the Wokwi simulation.

### Step 2

Verify that all components are connected correctly.

- ESP32
- DHT22 Sensor
- Red LED
- Green LED

### Step 3

Open `Environmental_Monitoring_Station.ino`.

Verify the GPIO pin assignments.

### Step 4

If using Arduino IDE, install the **DHTesp** library using the Library Manager.

### Step 5

Compile the program and ensure there are no errors.

### Step 6

Click **Start Simulation**.

### Step 7

Open the Serial Monitor and set the baud rate to **115200**.

Observe the CSV output.

### Step 8

Test normal conditions.

Example:

- Temperature = 30°C
- Humidity = 60%

Expected:

- Green LED ON
- Red LED OFF

### Step 9

Increase the temperature above **35°C**.

Expected:

- Red LED ON
- Green LED OFF

### Step 10

Increase the humidity above **80%**.

Expected:

- Red LED ON
- Green LED OFF

### Step 11

Copy at least five sensor readings from the Serial Monitor.

Save them as:

```text
Data/sample_readings.csv
```

Upload the file to the GitHub repository.

---

## Working Principle

The DHT sensor measures temperature and humidity every two seconds. The ESP32 converts the temperature from Celsius to Fahrenheit and prints the values in CSV format. If the temperature exceeds **35°C** or the humidity exceeds **80%**, the Red LED turns ON. Otherwise, the Green LED remains ON.

---

## Expected Output

### Serial Monitor

```csv
timestamp (s),temp_C (°C),temp_F (°F),humidity (%)
0,29.50,85.10,58.20
2,29.70,85.46,58.40
4,29.90,85.82,58.60
6,30.10,86.18,58.90
8,30.30,86.54,59.20
```

### LED Status

| Condition | Red LED | Green LED |
|-----------|:-------:|:---------:|
| Normal | OFF | ON |
| Temperature > 35°C | ON | OFF |
| Humidity > 80% | ON | OFF |

---

## Sample CSV Data

The assignment requires storing at least five sensor readings in a CSV file.

### File Location

```text
Data/sample_readings.csv
```

### CSV Columns

| Column | Description |
|---------|-------------|
| timestamp | Time in seconds |
| temp_C | Temperature in Celsius |
| temp_F | Temperature in Fahrenheit |
| humidity | Relative Humidity (%) |

### Sample Data

```csv
timestamp (s),temp_C (°C),temp_F (°F),humidity (%)
0,29.50,85.10,58.20
2,29.70,85.46,58.40
4,29.90,85.82,58.60
6,30.10,86.18,58.90
8,30.30,86.54,59.20
```

---

## Code Explanation

- Initializes the Serial Monitor and DHT sensor.
- Configures LED pins.
- Reads temperature and humidity every two seconds.
- Converts Celsius to Fahrenheit.
- Prints readings in CSV format.
- Compares readings with threshold values.
- Controls LEDs based on environmental conditions.

---

## Libraries Used

| Library | Version | Purpose |
|----------|---------|---------|
| DHTesp | Latest Stable | Interface with DHT11/DHT22 sensors |

---

## Learning Outcomes

After completing this experiment, the following concepts were learned:

- ESP32 programming
- DHT sensor interfacing
- Environmental monitoring
- CSV data logging
- Temperature conversion
- GPIO programming
- Conditional logic
- Wokwi simulation

---

## Best Practices

- Verify sensor readings before processing.
- Use meaningful variable names.
- Maintain proper code indentation.
- Keep project files organized.
- Follow consistent CSV formatting.
- Test all operating conditions before submission.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. ESP32 Arduino Core Documentation – https://docs.espressif.com/projects/arduino-esp32/
3. DHTesp Library – https://github.com/beegee-tokyo/DHTesp
4. Wokwi Documentation – https://docs.wokwi.com/

---

## Conclusion

This project demonstrates a simple environmental monitoring system using the ESP32 platform. It combines sensor interfacing, CSV data logging, threshold-based LED indication, and real-time monitoring, providing a practical introduction to IoT-based environmental sensing.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
