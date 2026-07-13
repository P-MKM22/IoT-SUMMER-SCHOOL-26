# Smart Street Lighting System

---

# Project Overview

The Smart Street Lighting System is an IoT-based smart city solution designed to automatically control street lights based on ambient light conditions and human or vehicle movement. The system uses sensors and an ESP32 microcontroller to reduce electricity consumption while ensuring public safety during nighttime.

Unlike conventional street lights that remain ON throughout the night, this system intelligently adjusts lighting according to environmental conditions and traffic activity. Street light status is continuously monitored and uploaded to a cloud platform, allowing municipal authorities to supervise the city's lighting infrastructure remotely.

---

# Problem Statement

Traditional street lighting systems consume a significant amount of electricity because lights remain ON regardless of pedestrian or vehicle movement. Fault detection is usually manual, resulting in delayed maintenance and increased operational costs.

A smart city requires an automated lighting system capable of minimizing energy consumption while maintaining road safety and providing real-time monitoring of street light conditions.

---

# Proposed IoT Solution

The proposed system uses an LDR sensor to measure ambient light intensity and a PIR sensor to detect pedestrians or vehicles. During daytime, all street lights remain OFF. At night, lights automatically turn ON only when movement is detected within a particular road section.

Each lighting node is controlled by an ESP32, which communicates with a cloud server through Wi-Fi. Municipal authorities can monitor street light status, power consumption, faulty lamps, and lighting schedules using a centralized dashboard.

---

# Hardware Requirements

| Component | Purpose |
|-----------|---------|
| ESP32 DevKit V1 | Main microcontroller |
| LDR Sensor | Ambient light detection |
| PIR Motion Sensor | Detect pedestrian or vehicle movement |
| LED | Street light simulation |
| OLED Display | Display system status |
| Buzzer | Fault or maintenance alert |
| Wi-Fi (ESP32) | Cloud communication |

---

# Software Requirements

| Software | Purpose |
|----------|---------|
| Arduino IDE | Firmware development |
| Wokwi Simulator | Circuit simulation |
| GitHub | Version control |
| HTTP REST API | Cloud communication |
| Firebase / ThingSpeak | Cloud monitoring (Optional) |

---

# System Architecture

```text
Ambient Light
      │
      ▼
   LDR Sensor
      │
      ▼
 PIR Motion Sensor
      │
      ▼
     ESP32
      │
 ┌────┼───────────┐
 ▼    ▼           ▼
LED OLED      Buzzer
      │
      ▼
    Wi-Fi
      │
      ▼
 Cloud Dashboard
      │
      ▼
Municipal Authority
```

---

# Data Flow

1. LDR continuously measures ambient light intensity.
2. ESP32 determines whether it is day or night.
3. PIR sensor detects pedestrian or vehicle movement.
4. Street light automatically turns ON when movement is detected during nighttime.
5. Light automatically turns OFF after a predefined timeout.
6. System uploads lighting status to the cloud.
7. Municipal dashboard displays real-time street light information.
8. Fault conditions are logged for maintenance.

---

# Components Used

| Category | Components |
|----------|------------|
| Microcontroller | ESP32 DevKit V1 |
| Sensors | LDR, PIR Motion Sensor |
| Output Devices | LED, OLED Display, Buzzer |
| Communication | Wi-Fi |
| Cloud | HTTP REST API / Firebase |

---

# Code Structure

```text
Smart_Street_Lighting_System
│
├── Code
│   ├── Config.h
│   ├── Credentials.h
│   ├── Sensor_Manager.h
│   ├── Lighting_Manager.h
│   ├── Display_Manager.h
│   ├── Alert_Manager.h
│   ├── Cloud_Manager.h
│   ├── Analytics_Manager.h
│   ├── Helper_Functions.h
│   └── Smart_Street_Lighting_System.ino
│
└── Proposal.md
```

---

# Working Principle

1. Initialize all sensors and communication modules.
2. Monitor ambient light using the LDR.
3. Detect pedestrian or vehicle movement using the PIR sensor.
4. Control street light automatically.
5. Display current system status on the OLED.
6. Upload operational data to the cloud.
7. Generate analytics regarding energy savings and street light utilization.
8. Notify authorities if any fault is detected.

---

# Expected Outcomes

- Automatic street light control
- Significant energy savings
- Improved public safety
- Reduced maintenance costs
- Real-time lighting monitoring
- Smart city infrastructure support
- Reduced carbon emissions

---

# Future Scope

- Adaptive brightness control using PWM
- AI-based traffic prediction
- Solar-powered street lighting
- Automatic fault localization
- Mobile application integration
- Energy consumption analytics
- Integration with Smart City Command Center
- Support for emergency vehicle priority lighting

---

# Conclusion

The Smart Street Lighting System provides an energy-efficient and intelligent approach to urban lighting management. By integrating IoT sensors, cloud connectivity, and automated control, the system minimizes electricity consumption while improving public safety and reducing maintenance efforts. The proposed solution contributes significantly to building a sustainable and intelligent Jammu Smart City.

---

# Author

**Name:** P Meet Kumar

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
