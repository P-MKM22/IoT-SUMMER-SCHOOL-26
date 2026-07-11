# Q 27 – Relay-Controlled AC Device Simulation

## Overview

This project demonstrates a temperature-based automation system that simulates controlling an AC appliance using a relay module. The relay automatically switches ON or OFF based on temperature readings from the sensor while implementing hysteresis to avoid frequent switching. A manual override button is also provided to allow the user to control the relay independently when required.

> **Note:** The original assignment specifies the use of a **DHT11** sensor. Since **Wokwi provides a DHT22 sensor**, the simulation has been implemented using the DHT22 without affecting the project logic or functionality.

---

## Objectives

- Monitor ambient temperature using a DHT sensor.
- Simulate AC appliance control using a relay and LED.
- Implement hysteresis for stable relay operation.
- Provide a manual override using a push button.
- Log relay state changes along with temperature readings on the Serial Monitor.

---

## Repository Structure

```text
Q27. Relay-Controlled AC Device Simulation
│
├── Assets
│   ├── Relay-Controlled AC Device Hardware setup.png
│   ├── Relay-Controlled AC Device demo.mp4
│   ├── Relay-Controlled AC Device manual override.png
│   ├── Relay-Controlled AC Device temp greater than 28.png
│   ├── Relay-Controlled AC Device temp less than 28.png
│   └── .gitkeep
│
├── Code
│   ├── Relay-Controlled_AC.ino
│   └── README.md
│
├── Documentation
│   └── README.md
│
└── README.md
```

---

## Assets

| Asset | Description |
|--------|-------------|
| Hardware Setup | Complete circuit implementation in Wokwi |
| Demo Video | Demonstration of the working project |
| Manual Override | Relay operation using the push button |
| Temperature Above Threshold | Automatic relay activation |
| Temperature Below Threshold | Automatic relay deactivation |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469252406701644801

**Description**

This simulation demonstrates an automatic relay-controlled AC system using an Arduino Uno, DHT22 sensor, relay module, LED, and push button. The relay responds automatically to temperature thresholds while supporting manual override and real-time event logging through the Serial Monitor.

---

## Future Enhancements

- Replace the simulated LED with an actual AC appliance using a hardware relay module.
- Display temperature and relay status on an LCD or OLED display.
- Add Wi-Fi connectivity for remote monitoring and control.
- Integrate MQTT or Blynk for IoT-based automation.
- Store temperature and relay logs on cloud platforms for analysis.
- Add humidity-based control for smarter environmental automation.

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
