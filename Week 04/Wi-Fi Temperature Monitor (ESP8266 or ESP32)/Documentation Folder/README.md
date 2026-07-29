# Documentation of Wi-Fi Temperature Monitor

## Overview

This documentation presents the complete implementation details, supporting resources, and technical documentation for **Q33 – Wi-Fi Temperature Monitor (ESP8266/ESP32)** developed during **Week 04** of the **IoT and Drone Building Summer School 2026** conducted by the **Indian Institute of Technology Jammu (IIT Jammu)**.

The project demonstrates how an ESP32 can be configured as a local HTTP web server to monitor environmental conditions over a Wi-Fi network. Real-time temperature and humidity readings obtained from the DHT11 sensor are displayed through a browser-based dashboard, which also allows remote LED control and continuously shows the device uptime.

---

## Documentation Contents

This documentation includes:

- Project overview
- Folder organization
- Implementation details
- Circuit connections
- Execution procedure
- Working principle
- Expected output
- Code explanation
- Libraries used
- Learning outcomes
- Best practices
- References

---

## Project Structure

```text
IoT-SUMMER-SCHOOL-26
│
└── Week 04
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
        ├── README.md
        │
        └── Documentation Folder
            └── README.md
```

---

## Implementation Details

The project was developed using an ESP32 Development Board configured as a local HTTP web server. A DHT11 sensor continuously measures environmental temperature and humidity, while the onboard LED can be controlled remotely through the browser interface.

The ESP32 connects to a local Wi-Fi network and hosts a responsive webpage that displays live sensor readings, LED status, and device uptime. The webpage refreshes automatically every 10 seconds, ensuring that the displayed information remains up to date.

---

## Circuit Connections

### DHT11 Sensor

| DHT11 Pin | ESP32 Pin |
|------------|-----------|
| VCC | 3.3V |
| DATA | GPIO15 |
| GND | GND |

### LED

| LED | ESP32 |
|------|-------|
| Anode (+) | GPIO2 |
| Cathode (-) | GND through 220 Ω resistor |

---

## Execution Steps

### Step 1 – Install Required Software

- Install the latest Arduino IDE.
- Install the ESP32 Board Package.
- Install the required Arduino libraries.

### Step 2 – Assemble the Hardware

- Connect the DHT11 sensor to the ESP32.
- Connect the LED with the current limiting resistor.
- Verify all power and GPIO connections.

### Step 3 – Configure Wi-Fi

- Open the Arduino sketch.
- Update the Wi-Fi SSID and password.
- Save the source code.

### Step 4 – Upload the Program

- Select **ESP32 Dev Module**.
- Select the appropriate COM port.
- Compile the sketch.
- Upload the program successfully.

### Step 5 – Verify Serial Output

- Open the Serial Monitor.
- Set the baud rate to **115200**.
- Wait until the ESP32 connects to the Wi-Fi network.
- Note the IP address displayed.

### Step 6 – Test the Web Dashboard

- Open a browser connected to the same Wi-Fi network.
- Enter the ESP32 IP address.
- Verify temperature and humidity readings.
- Test the LED ON/OFF control.
- Verify automatic page refresh.

### Step 7 – Record Project Outputs

- Capture hardware setup images.
- Capture webpage screenshots.
- Record the project demonstration videos.

---

## Working Principle

The ESP32 reads environmental data from the DHT11 sensor and connects to the configured Wi-Fi network. Once connected, it starts a local HTTP web server that generates a dynamic webpage displaying the latest temperature, humidity, LED status, and device uptime.

Whenever a user accesses the ESP32 IP address through a browser, the webpage is served with updated sensor values. LED control commands received from the webpage are processed by the ESP32, allowing remote operation while continuous monitoring remains active.

---

## Expected Output

The implemented system should:

- Connect successfully to the configured Wi-Fi network.
- Display the assigned IP address in the Serial Monitor.
- Host the web dashboard successfully.
- Display live temperature and humidity values.
- Show the current LED status.
- Allow remote LED control.
- Display device uptime.
- Refresh the webpage automatically every 10 seconds.

---

## Code Explanation

The program is organized into the following modules:

| Module | Description |
|---------|-------------|
| Library Initialization | Includes all required Arduino libraries. |
| Global Configuration | Defines Wi-Fi credentials, GPIO pins, sensor objects, and global variables. |
| Sensor Reading | Acquires temperature and humidity values from the DHT11 sensor. |
| HTML Generator | Creates the dynamic webpage served by the ESP32. |
| Request Handlers | Processes webpage requests and LED control actions. |
| Setup Function | Initializes hardware, Wi-Fi, sensor, and web server. |
| Loop Function | Continuously handles HTTP client requests. |

---

## Libraries Used

- WiFi.h
- WebServer.h
- DHT.h

---

## Learning Outcomes

After completing this project, the following concepts were learned:

- ESP32 Wi-Fi networking
- Embedded web server development
- Browser-based IoT dashboard design
- DHT11 sensor interfacing
- Remote hardware control
- Local network communication
- Dynamic webpage generation
- Practical IoT application development

---

## Best Practices

- Verified hardware connections before uploading the program.
- Used modular programming for improved readability.
- Maintained meaningful variable and function names.
- Performed incremental testing during implementation.
- Organized project files following the repository structure.
- Documented the project for reproducibility and future reference.

---

## References

- Arduino Documentation
- ESP32 Arduino Documentation
- ESP32 WebServer Library Documentation
- Adafruit DHT Sensor Library Documentation
- Indian Institute of Technology Jammu – IoT and Drone Building Summer School 2026

---

## Conclusion

This project successfully demonstrates the implementation of a Wi-Fi-enabled environmental monitoring system using the ESP32 Development Board. It combines sensor interfacing, embedded web server development, browser-based monitoring, and remote device control to provide a practical introduction to IoT communication over a local network.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
