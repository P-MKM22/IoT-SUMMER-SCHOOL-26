# Smart Fire Detection and Emergency Response System

---

# Project Overview

The Smart Fire Detection and Emergency Response System is an IoT-based public safety solution designed to detect fire incidents at the earliest possible stage and automatically notify the nearest Fire Brigade, Disaster Management Authority, and Municipal Control Room. The system continuously monitors environmental conditions using multiple sensors and immediately activates emergency protocols whenever a potential fire hazard is detected.

Instead of relying solely on citizens to report fire accidents, this system provides automated detection, real-time alerts, cloud monitoring, and rapid emergency response, helping minimize property damage and save lives.

---

# Problem Statement

Fire accidents in residential areas, markets, industries, forests, and public buildings often lead to severe property damage and loss of human life. Delayed reporting, lack of real-time monitoring, and slow emergency response significantly increase the impact of such incidents.

Current challenges include:

- Delayed fire detection
- Manual reporting of incidents
- Slow dispatch of fire brigade services
- Lack of real-time monitoring
- No centralized incident database
- Limited preventive monitoring in public areas

A smart city requires an automated system capable of detecting fire hazards instantly and notifying emergency authorities without human intervention.

---

# Proposed IoT Solution

The proposed system installs IoT-enabled fire monitoring units throughout the city. Each unit continuously measures environmental conditions using temperature, smoke, gas, and flame sensors.

Whenever abnormal conditions are detected, the ESP32 immediately:

- Activates local alarms
- Sends notifications to the Fire Brigade
- Uploads incident data to the cloud
- Shares GPS location of the incident
- Displays live system status
- Records the event for future analysis

The solution enables faster emergency response and improves overall public safety.

---

# Hardware Requirements

| Component | Purpose |
|-----------|---------|
| ESP32 DevKit V1 | Main microcontroller |
| Flame Sensor | Detects fire flames |
| MQ-2 Gas Sensor | Detects smoke and combustible gases |
| DHT22 Sensor | Measures temperature and humidity |
| Buzzer | Local emergency alarm |
| Red LED | Fire warning indicator |
| Green LED | Normal system status |
| OLED Display | Live monitoring dashboard |
| GPS Module (NEO-6M) | Incident location |
| Wi-Fi (ESP32) | Cloud communication |

---

# Software Requirements

| Software | Purpose |
|----------|---------|
| Arduino IDE | Firmware development |
| Wokwi Simulator | Circuit simulation |
| GitHub | Version control |
| HTTP REST API | Cloud communication |
| Firebase / ThingSpeak | Cloud dashboard (optional) |

---

# System Architecture

```text
Flame Sensor
MQ-2 Gas Sensor
DHT22
      │
      ▼
     ESP32
      │
      ├──► OLED Display
      ├──► Buzzer
      ├──► LEDs
      ├──► GPS Module
      │
      └──► Wi-Fi
              │
              ▼
        Cloud Server
              │
      ┌───────┼────────┐
      ▼       ▼        ▼
 Fire Brigade Municipal Control Disaster Authority
```

---

# Data Flow

1. Sensors continuously monitor the environment.
2. ESP32 collects all sensor readings.
3. Fire risk is evaluated.
4. If danger is detected:
   - Fire alarm activates.
   - Warning LEDs turn ON.
   - GPS coordinates are acquired.
   - Incident information is uploaded to the cloud.
   - Fire Brigade receives an emergency notification.
5. Authorities monitor the incident remotely.
6. All events are stored for future analysis.

---

# Components Used

| Category | Components |
|----------|------------|
| Microcontroller | ESP32 DevKit V1 |
| Sensors | Flame Sensor, MQ-2 Gas Sensor, DHT22 |
| Communication | Wi-Fi, GPS |
| Output Devices | OLED Display, Buzzer, LEDs |
| Cloud | HTTP REST API / Firebase |

---

# Code Structure

```text
Smart_Fire_Detection_System
│
├── Code
│   ├── Config.h
│   ├── Credentials.h
│   ├── Sensor_Manager.h
│   ├── Fire_Detection.h
│   ├── GPS_Manager.h
│   ├── Display_Manager.h
│   ├── Alert_Manager.h
│   ├── Cloud_Manager.h
│   ├── Notification_Manager.h
│   ├── Helper_Functions.h
│   └── Smart_Fire_Detection_System.ino
│
└── Proposal.md
```

---

# Working Principle

1. Initialize all sensors and communication modules.
2. Continuously monitor temperature, smoke, gas, and flame intensity.
3. Analyze sensor readings.
4. Detect possible fire conditions.
5. Activate local emergency alarms.
6. Display incident details on OLED.
7. Obtain GPS location.
8. Upload incident information to the cloud.
9. Notify the Fire Brigade and Municipal Control Room.
10. Store incident logs for future investigation.

---

# Expected Outcomes

- Early fire detection
- Faster emergency response
- Reduced property damage
- Improved citizen safety
- Automated incident reporting
- Real-time cloud monitoring
- Smart city emergency management

---

# Future Scope

- AI-based fire prediction
- Drone-assisted fire surveillance
- Automatic sprinkler activation
- Satellite-based monitoring
- GSM/SMS emergency alerts
- Integration with Smart City Command Center
- Mobile application for firefighters
- Machine learning-based false alarm reduction

---

# Conclusion

The Smart Fire Detection and Emergency Response System provides a proactive approach to urban fire safety by combining IoT sensing, cloud connectivity, GPS tracking, and automated emergency notifications. The proposed solution significantly reduces response time, enhances public safety, and supports the vision of a secure and intelligent Jammu Smart City.

---

# Author

**Name:** P Meet Kumar

**Roll Number:** IoT 009

**Program:** IoT Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
