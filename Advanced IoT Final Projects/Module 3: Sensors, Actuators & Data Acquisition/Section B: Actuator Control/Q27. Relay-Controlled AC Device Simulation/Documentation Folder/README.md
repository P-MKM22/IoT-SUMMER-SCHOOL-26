# Documentation of Question 27

## Overview

This document provides the complete technical documentation for **Q 27 – Relay-Controlled AC Device Simulation** developed as part of the **Advanced IoT Final Project**, **Module 3: Sensors, Actuators & Data Acquisition**, **Section B: Actuator Control**.

> **Note:** The assignment specifies a **DHT11** sensor. Since **Wokwi provides the DHT22 sensor**, the project was implemented using the **DHT22**, which offers similar functionality while maintaining the same project logic and objectives.

---

## Documentation Contents

- Project Overview
- Components Required
- Pin Configuration
- Circuit Connections
- Working Principle
- Step-by-Step Connections
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
└── Module 3: Sensors, Actuators & Data Acquisition
    │
    └── Section B: Actuator Control
        │
        └── Q27. Relay-Controlled AC Device Simulation
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
            │   └── Relay-Controlled_AC.ino
            │
            ├── Documentation
            │   └── README.md
            │
            └── README.md
```

---

## Components Required

- Arduino Uno
- DHT22 Sensor *(Used instead of DHT11 in Wokwi)*
- Relay Module
- LED
- 220Ω Resistor
- Push Button
- Breadboard
- Jumper Wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 Data | D7 |
| Relay IN | D8 |
| LED | D9 |
| Push Button | D2 |

---

## Circuit Connections

### DHT22 Sensor

| DHT22 Pin | Arduino Connection |
|------------|-------------------|
| VCC | 5V |
| GND | GND |
| DATA | D7 |

### Relay Module

| Relay Pin | Arduino Connection |
|-----------|-------------------|
| VCC | 5V |
| GND | GND |
| IN | D8 |

### LED

| LED Pin | Arduino Connection |
|---------|--------------------|
| Anode (+) | D9 through 220Ω resistor |
| Cathode (-) | GND |

### Push Button

| Button Terminal | Arduino Connection |
|-----------------|--------------------|
| Terminal 1 | D2 |
| Terminal 2 | GND |

> The button uses the Arduino's internal **INPUT_PULLUP** resistor.

---

## Step-by-Step Connections

### Step 1
Connect the **DHT22 VCC** pin to the Arduino **5V** pin.

### Step 2
Connect the **DHT22 GND** pin to **GND**.

### Step 3
Connect the **DHT22 DATA** pin to **Digital Pin 7**.

### Step 4
Connect the **Relay Module VCC** to **5V**.

### Step 5
Connect the **Relay Module GND** to **GND**.

### Step 6
Connect the **Relay Module IN** pin to **Digital Pin 8**.

### Step 7
Connect the **LED anode** to **Digital Pin 9** through a **220Ω resistor**.

### Step 8
Connect the **LED cathode** to **GND**.

### Step 9
Connect one terminal of the **Push Button** to **Digital Pin 2**.

### Step 10
Connect the other terminal of the **Push Button** to **GND**.

### Step 11
Verify all common ground connections before starting the simulation.

---

## Working Principle

The DHT sensor continuously monitors the surrounding temperature. When the temperature rises above **32°C**, the relay turns ON, simulating an air conditioner being switched ON. Once the temperature falls below **28°C**, the relay turns OFF using hysteresis to prevent rapid switching. A push button enables **Manual Override**, allowing the relay to be controlled manually. Every relay state change is displayed on the Serial Monitor together with the measured temperature.

---

## Implementation Steps

### Step 1
Initialize the DHT sensor, relay module, LED, and push button.

### Step 2
Read the current temperature from the DHT sensor.

### Step 3
Apply hysteresis logic for automatic relay control.

### Step 4
Detect button presses for Manual Override mode.

### Step 5
Update the relay and LED states.

### Step 6
Display relay status and temperature on the Serial Monitor.

---

## Serial Monitor Output

```text
--------------------------------
Temperature : 33.4 °C
Relay State : ON
AC Status   : ON
Mode        : Automatic
--------------------------------
```

---

## Code Explanation

### Sensor Reading

Reads the temperature from the DHT sensor.

### Automatic Relay Control

Turns the relay ON above **32°C** and OFF below **28°C** using hysteresis.

### Manual Override

Allows the relay to be manually controlled using a push button.

### Output Control

Synchronizes the relay module and LED status.

### Serial Communication

Displays temperature, relay state, AC status, and operating mode.

---

## Software Concepts Used

- Temperature Monitoring
- Relay Interfacing
- Hysteresis Control
- Manual Override
- Digital Output Control
- Push Button Interfacing
- Serial Communication
- Embedded System Programming

---

## Assets Included

| Asset | Description |
|--------|-------------|
| Relay-Controlled AC Device Hardware setup.png | Circuit wiring |
| Relay-Controlled AC Device demo.mp4 | Working demonstration |
| Relay-Controlled AC Device manual override.png | Manual mode demonstration |
| Relay-Controlled AC Device temp greater than 28.png | Relay ON condition |
| Relay-Controlled AC Device temp less than 28.png | Relay OFF condition |

---

## Wokwi Simulation

**Simulation Link**

https://wokwi.com/projects/469252406701644801

**Description**

This simulation demonstrates an automatic relay-controlled AC system using a DHT22 sensor, relay module, LED, and push button. The relay automatically switches based on temperature thresholds, while Manual Override allows direct user control. The Serial Monitor logs every relay state change along with the current temperature and operating mode.

---

## Learning Outcomes

- Temperature sensor interfacing
- Relay module control
- Hysteresis implementation
- Manual override logic
- Digital output control
- Serial monitoring
- Embedded automation systems

---

## Best Practices

- Verify all wiring before powering the circuit.
- Ensure all modules share a common ground.
- Use hysteresis to avoid rapid relay switching.
- Test Manual Override independently from Automatic mode.
- Monitor Serial output to verify relay transitions.

---

## Conclusion

The **Relay-Controlled AC Device Simulation** demonstrates an intelligent temperature-based control system using an Arduino Uno. The project combines sensor monitoring, relay actuation, hysteresis, and manual override to simulate a practical HVAC control application. Although the implementation uses a **DHT22** sensor due to Wokwi's component availability, it fully satisfies the functional requirements of the original assignment while providing hands-on experience in embedded automation and actuator control.
