# Documentation of Question 21

## Overview

This documentation presents the implementation of an Environmental Monitoring Station using an ESP32 and a DHT22 sensor (used in Wokwi as an alternative to DHT11). The system measures temperature and humidity every two seconds, displays the readings in CSV format, and indicates environmental conditions using Red and Green LEDs.

> **Note:** The assignment specifies the DHT11 sensor. Since Wokwi provides the DHT22 sensor, it has been used for simulation. The implementation logic remains the same.

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
Q21. Environmental Monitoring Station (DHT11)
│
├── Assets
│   ├── Hardware Connection.png
│   ├── Serial Monitor Output.png
│   ├── Normal Condition.png
│   ├── High Temperature Alert.png
│   └── High Humidity Alert.png
│
├── Code
│   └── EMS.ino
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

- Arduino IDE 2.x
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
| GND | LED cathodes through 220 Ω resistors |

---

## Wokwi Simulation

### Simulation Link

https://wokwi.com/projects/469171145460939777

### Description

The simulation demonstrates real-time environmental monitoring using the ESP32. Temperature and humidity are read every two seconds, displayed in CSV format, and LEDs indicate normal or abnormal environmental conditions based on predefined thresholds.

---

## Implementation Details

The project performs the following operations:

- Initializes the ESP32 and DHT sensor.
- Reads temperature and humidity every two seconds.
- Converts Celsius to Fahrenheit.
- Displays readings in CSV format.
- Monitors threshold values.
- Controls Red and Green LEDs based on environmental conditions.

---

## Execution Steps

### Step 1: Open the Simulation

Open the Wokwi project using the provided simulation link.

---

### Step 2: Verify Circuit Connections

Ensure all components are connected correctly.

- ESP32
- DHT22
- Red LED
- Green LED
- Resistors

---

### Step 3: Review the Source Code

Open `EMS.ino` and verify the GPIO assignments.

```cpp
DHT_PIN = 15
RED_LED_PIN = 18
GREEN_LED_PIN = 19
```

---

### Step 4: Install Required Library (Arduino IDE)

If using Arduino IDE:

- Open **Library Manager**
- Search **DHTesp**
- Install the latest stable version

---

### Step 5: Compile the Program

Click **Verify** and ensure there are no compilation errors.

---

### Step 6: Start the Simulation

Click **Start Simulation**.

The ESP32 begins reading sensor values every two seconds.

---

### Step 7: Observe Serial Monitor

Open the Serial Monitor and set the baud rate to **115200**.

Example output:

```csv
timestamp (s),temp_C (°C),temp_F (°F),humidity (%)
0,29.50,85.10,58.20
2,29.70,85.46,58.40
4,29.90,85.82,58.60
```

---

### Step 8: Test Normal Condition

Set:

- Temperature = 30°C
- Humidity = 60%

Expected Result:

- Green LED ON
- Red LED OFF

---

### Step 9: Test High Temperature

Increase the temperature above **35°C**.

Example:

```
Temperature = 38°C
Humidity = 60%
```

Expected Result:

- Red LED ON
- Green LED OFF

---

### Step 10: Test High Humidity

Keep the temperature below **35°C**.

Increase humidity above **80%**.

Example:

```
Temperature = 28°C
Humidity = 85%
```

Expected Result:

- Red LED ON
- Green LED OFF

---

### Step 11: Verify CSV Output

Ensure the Serial Monitor continuously prints readings in CSV format every two seconds.

---

### Step 12: Save Sample Readings

1. Copy five consecutive readings from the Serial Monitor.
2. Create a file named **sample_readings.csv**.
3. Paste the copied readings into the file.
4. Save the file inside the **Data** folder.
5. Commit and upload the file to the GitHub repository.

---

## Working Principle

The DHT22 sensor measures ambient temperature and humidity. Every two seconds, the ESP32 reads the sensor values, converts the temperature to Fahrenheit, and displays the readings in CSV format. If the temperature exceeds **35°C** or humidity exceeds **80%**, the Red LED turns ON; otherwise, the Green LED remains ON.

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

### LED Behaviour

| Condition | Red LED | Green LED |
|-----------|:-------:|:---------:|
| Normal | OFF | ON |
| Temperature > 35°C | ON | OFF |
| Humidity > 80% | ON | OFF |

---

## Sample CSV Data

The assignment requires storing at least **five sample sensor readings** in a CSV file.

### File Location

```text
Data/sample_readings.csv
```

### File Description

The file contains environmental readings collected from the Serial Monitor during simulation.

| Column | Description | Unit |
|---------|-------------|------|
| timestamp | Elapsed time | Seconds (s) |
| temp_C | Temperature | °C |
| temp_F | Temperature | °F |
| humidity | Relative Humidity | % |

### Sample Content

```csv
timestamp (s),temp_C (°C),temp_F (°F),humidity (%)
0,29.50,85.10,58.20
2,29.70,85.46,58.40
4,29.90,85.82,58.60
6,30.10,86.18,58.90
8,30.30,86.54,59.20
```

### Purpose

- Maintains sensor records.
- Enables spreadsheet analysis.
- Demonstrates structured data logging.
- Satisfies the assignment requirement.

---

## Code Explanation

- Initializes the ESP32, DHT sensor, LEDs, and Serial Monitor.
- Reads temperature and humidity every two seconds.
- Converts Celsius to Fahrenheit.
- Prints readings in CSV format.
- Compares readings with threshold values.
- Controls LEDs according to environmental conditions.
- Repeats continuously.

---

## Libraries Used

| Library | Version | Purpose |
|----------|---------|---------|
| DHTesp | Latest Stable | DHT11/DHT22 sensor interface |

---

## Learning Outcomes

- ESP32 programming
- DHT sensor interfacing
- Temperature conversion
- CSV data logging
- GPIO control
- Conditional programming
- Wokwi simulation
- Real-time environmental monitoring

---

## Best Practices

- Validate sensor readings.
- Use meaningful variable names.
- Keep code modular.
- Follow consistent CSV formatting.
- Test all operating conditions.
- Maintain organized project documentation.

---

## References

1. Arduino Documentation – https://docs.arduino.cc/
2. ESP32 Arduino Core – https://docs.espressif.com/projects/arduino-esp32/
3. DHTesp Library – https://github.com/beegee-tokyo/DHTesp
4. Wokwi Documentation – https://docs.wokwi.com/

---

## Conclusion

The Environmental Monitoring Station successfully demonstrates temperature and humidity monitoring using the ESP32 platform. The project integrates sensor interfacing, CSV data logging, LED-based status indication, and real-time monitoring, providing a strong foundation for IoT-based environmental sensing applications.
