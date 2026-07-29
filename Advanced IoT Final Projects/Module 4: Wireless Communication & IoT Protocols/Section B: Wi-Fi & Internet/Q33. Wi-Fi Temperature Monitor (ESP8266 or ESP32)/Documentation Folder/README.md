# Documentation of Question 33

## Overview

This documentation presents the complete implementation details, supporting resources, and technical documentation for **Q33 – Wi-Fi Temperature Monitor (ESP8266/ESP32)** developed as part of **Module 04 – Wireless Communication & IoT Protocols** during the **IoT and Drone Building Summer School 2026** conducted by the **Indian Institute of Technology Jammu (IIT Jammu)**.

The project demonstrates how an ESP32 can be configured as a local web server to monitor environmental conditions over a Wi-Fi network. Real-time temperature and humidity readings obtained from the DHT11 sensor are displayed through a browser-based dashboard, which also allows remote LED control and continuously shows the device uptime.

---

## Documentation Contents

This documentation folder includes:

- Complete implementation workflow
- Hardware connection details
- Project execution procedure
- Working principle
- Source code explanation
- Libraries and software requirements
- Expected output
- Project assets
- Learning outcomes
- Best practices followed during implementation

---

## Project Structure

```text
Advanced IoT Final Projects
│
└── Module 4: Wireless Communication & IoT Protocols
    │
    └── Section B: Wi-Fi & Internet
        │
        └── Q33. Wi-Fi Temperature Monitor (ESP8266 or ESP32)
            │
            ├── Assets
            │   ├── LED OFF using webpage.jpeg
            │   ├── LED ON using webpage.jpeg
            │   ├── Wi-Fi Temperature Monitor Hardware setup.png
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

## Implementation Details

The project was implemented using an ESP32 Development Board configured as a local HTTP web server. A DHT11 sensor continuously measures environmental temperature and humidity, while an onboard LED is controlled through a browser-based interface.

The ESP32 connects to a local Wi-Fi network, hosts a responsive webpage, and dynamically updates sensor values, LED status, and device uptime. The webpage refreshes automatically every 10 seconds to provide real-time monitoring without requiring manual page refresh.

---

## Hardware Connections

### ESP32 and DHT11 Sensor

| DHT11 Pin | ESP32 Pin | Purpose |
|------------|-----------|----------|
| VCC | 3.3V | Power Supply |
| DATA | GPIO15 | Sensor Data |
| GND | GND | Common Ground |

### ESP32 and LED

| LED Connection | ESP32 Pin | Purpose |
|----------------|-----------|----------|
| Anode (+) | GPIO2 | LED Output |
| Cathode (-) | GND (220 Ω Resistor) | Current Limiting |

### Power Connections

| Component | Connection |
|-----------|------------|
| ESP32 | USB Power |
| DHT11 | ESP32 3.3V |
| LED | GPIO2 |

---

## Execution Steps

### Step 1 – Development Environment Setup

- Install Arduino IDE.
- Install the ESP32 Board Package.
- Install all required Arduino libraries.
- Select **ESP32 Dev Module** and the appropriate COM port.

### Step 2 – Hardware Assembly

- Connect the DHT11 sensor to the ESP32.
- Connect the LED through a 220 Ω resistor.
- Verify all GPIO, power, and ground connections.

### Step 3 – Configure Wi-Fi Credentials

- Open the Arduino source code.
- Replace the default Wi-Fi SSID and password with the target network credentials.

### Step 4 – Upload the Program

- Compile the Arduino sketch.
- Upload the program to the ESP32.
- Verify successful flashing.

### Step 5 – Connect to Wi-Fi

- Open the Serial Monitor at **115200 baud**.
- Wait until the ESP32 successfully connects to the configured Wi-Fi network.
- Note the IP address assigned by the router.

### Step 6 – Access the Web Dashboard

- Connect a computer or mobile device to the same Wi-Fi network.
- Open any web browser.
- Enter the ESP32 IP address displayed in the Serial Monitor.
- Verify that the dashboard loads successfully.

### Step 7 – Functional Testing

Verify the following:

- Live temperature values are displayed.
- Live humidity values are displayed.
- Device uptime increases continuously.
- LED status updates correctly.
- LED ON/OFF button functions properly.
- The webpage refreshes automatically every 10 seconds.

### Step 8 – Documentation

- Capture hardware setup photographs.
- Capture webpage screenshots.
- Record demonstration videos.
- Organize all project files according to the standardized repository structure.

---

## Working Principle

The ESP32 continuously acquires environmental data from the DHT11 sensor and processes the readings internally. After connecting to the configured Wi-Fi network, it starts an HTTP server that hosts a local monitoring webpage.

Whenever a browser accesses the ESP32 IP address, the server dynamically generates an HTML webpage containing the latest temperature, humidity, LED status, and device uptime. User interactions with the webpage send HTTP requests to the ESP32, enabling remote LED control while sensor monitoring continues uninterrupted.

---

## Expected Output

After successful implementation:

- ESP32 connects to the configured Wi-Fi network.
- The assigned IP address is displayed in the Serial Monitor.
- The browser successfully opens the hosted webpage.
- Live temperature and humidity values are displayed.
- Device uptime updates continuously.
- LED can be controlled remotely from the webpage.
- The dashboard refreshes automatically every 10 seconds.

---

## Code Explanation

The program is organized into the following functional sections:

| Section | Description |
|----------|-------------|
| Library Initialization | Includes the required Arduino libraries. |
| Global Configuration | Defines Wi-Fi credentials, GPIO pins, sensor objects, and global variables. |
| Sensor Processing | Reads temperature and humidity from the DHT11 sensor. |
| HTML Generator | Creates the dynamic webpage displayed by the ESP32. |
| HTTP Request Handlers | Processes webpage requests and LED control commands. |
| Setup Function | Initializes hardware, Wi-Fi, sensor, and web server. |
| Loop Function | Continuously handles incoming client requests. |

---

## Libraries Used

- WiFi.h
- WebServer.h
- DHT.h

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

## Best Practices

The following engineering practices were followed during implementation:

- Modular program design
- Meaningful variable and function naming
- Proper code documentation
- Systematic hardware verification
- Functional testing after every implementation stage
- Organized repository structure
- Comprehensive project documentation

---

## References

- Arduino Documentation — https://docs.arduino.cc/
- ESP32 Arduino Documentation — https://docs.espressif.com/projects/arduino-esp32/
- Adafruit DHT Sensor Library — https://github.com/adafruit/DHT-sensor-library
- ESP32 WebServer Library Documentation — https://github.com/espressif/arduino-esp32
- IIT Jammu Summer School 2026 – Module 04 Assignment Manual

---

## Conclusion

This project successfully demonstrates the implementation of a Wi-Fi-enabled environmental monitoring system using the ESP32 Development Board. By integrating sensor acquisition, embedded web server technology, browser-based device control, and real-time monitoring, the project provides a practical understanding of IoT communication within a local network. The structured implementation, documentation, and testing methodology also establish a strong foundation for developing more advanced cloud-enabled IoT applications.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
