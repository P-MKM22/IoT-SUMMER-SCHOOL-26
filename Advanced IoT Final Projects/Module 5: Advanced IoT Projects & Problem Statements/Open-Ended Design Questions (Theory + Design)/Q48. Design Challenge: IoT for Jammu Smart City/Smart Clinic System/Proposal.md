# Smart Clinic System

---

# Project Overview

The Smart Clinic System is an IoT-enabled healthcare solution designed to establish government-operated smart clinics across different city zones. The system enables real-time patient monitoring, digital health records, appointment management, and emergency alert generation. By integrating IoT devices with cloud connectivity, healthcare services become faster, more accessible, and more efficient while reducing overcrowding in major hospitals.

---

# Problem Statement

Government hospitals often face overcrowding, long waiting times, manual record management, delayed emergency response, and limited accessibility. Patients frequently travel long distances for routine health check-ups, increasing both healthcare costs and waiting periods.

The proposed Smart Clinic System aims to solve these challenges by deploying IoT-enabled clinics in different city zones that provide basic healthcare services, digital patient records, and continuous health monitoring.

---

# Proposed IoT Solution

The Smart Clinic System consists of multiple government-operated smart clinics connected through an IoT network. Each clinic continuously monitors patient health using sensors and uploads the collected data to a cloud server. Medical staff can access patient records remotely while emergency alerts are automatically generated whenever abnormal health conditions are detected.

The system offers:

- Digital patient registration
- Smart appointment management
- Real-time health monitoring
- Cloud-based medical records
- Emergency alert generation
- Zone-wise healthcare accessibility
- Remote monitoring by doctors

---

# Hardware Requirements

| Component | Purpose |
|-----------|---------|
| ESP32 DevKit V1 | Main microcontroller |
| OLED Display | Display patient information |
| DHT22 Sensor | Temperature monitoring |
| Pulse Sensor / Potentiometer | Heart rate measurement |
| Potentiometer | SpO₂ simulation |
| Push Buttons | User interaction |
| LEDs | System status indication |
| Buzzer | Emergency alerts |
| Wi-Fi Module (ESP32) | Cloud connectivity |

---

# Software Requirements

| Software | Purpose |
|----------|---------|
| Arduino IDE | Firmware development |
| Wokwi Simulator | Circuit simulation |
| GitHub | Version control |
| HTTP API | Cloud communication |

---

# System Architecture

```text
Patient
   │
   ▼
Health Sensors
   │
   ▼
ESP32 Controller
   │
   ├──► OLED Display
   ├──► Alert System
   └──► Cloud Server
            │
            ▼
     Medical Database
            │
            ▼
      Doctor Dashboard
```

---

# Data Flow

1. Patient arrives at the nearest Smart Clinic.
2. Health sensors collect patient vital signs.
3. ESP32 processes sensor data.
4. Health status is analyzed.
5. Patient information is displayed on the OLED.
6. Emergency alerts are generated if abnormal readings are detected.
7. Health records are uploaded to the cloud server.
8. Doctors access patient records remotely.
9. Updated medical records are securely stored.

---

# Components Used

| Category | Components |
|----------|------------|
| Microcontroller | ESP32 DevKit V1 |
| Sensors | DHT22, Pulse Sensor (or Potentiometer), SpO₂ Potentiometer |
| Output Devices | OLED Display, LEDs, Buzzer |
| Input Devices | Push Buttons |
| Communication | Wi-Fi |
| Cloud | HTTP REST API |

---

# Code Structure

```text
Smart_Clinic_System
│
├── Code
│   ├── Config.h
│   ├── Credentials.h
│   ├── Patient_Manager.h
│   ├── Sensor_Manager.h
│   ├── Display_Manager.h
│   ├── Appointment_Manager.h
│   ├── Health_Monitor.h
│   ├── Alert_Manager.h
│   ├── Cloud_Manager.h
│   ├── Helper_Functions.h
│   └── Smart_Clinic_System.ino
│
└── Proposal.md
```

---

# Working Principle

1. Initialize all hardware components.
2. Read patient health parameters.
3. Analyze the collected sensor data.
4. Display health information.
5. Trigger alerts during emergencies.
6. Upload health records to the cloud.
7. Allow doctors to monitor patient health remotely.

---

# Expected Outcomes

- Reduced waiting time
- Digital healthcare records
- Improved emergency response
- Better healthcare accessibility
- Continuous patient monitoring
- Smart government healthcare services

---

# Future Scope

- AI-assisted disease prediction
- Face recognition-based patient identification
- Electronic Health Record (EHR) integration
- SMS and mobile notifications
- Ambulance dispatch integration
- Online consultation support

---

# Conclusion

The Smart Clinic System demonstrates how IoT can modernize government healthcare by providing accessible, connected, and intelligent medical services. Through sensor-based health monitoring, cloud integration, and automated emergency alerts, the proposed solution enhances healthcare delivery and supports the vision of a smarter and healthier Jammu Smart City.

---

# Author

**Name:** P Meet Kumar

**Roll Number:** IoT 009

**Program:** IoT Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
