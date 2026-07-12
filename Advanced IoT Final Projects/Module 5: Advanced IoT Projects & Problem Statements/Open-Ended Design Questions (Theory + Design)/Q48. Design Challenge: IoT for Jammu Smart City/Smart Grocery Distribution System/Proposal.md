# Smart Grocery Distribution System

## Overview

The Smart Grocery Distribution System is an IoT-enabled solution proposed for modernizing the Government Public Distribution System (PDS). The system aims to provide a transparent, secure, and automated method of distributing subsidized groceries to eligible citizens while reducing manual intervention, fraudulent activities, duplicate claims, and inventory mismanagement.

Using IoT sensors, cloud connectivity, and digital authentication, the complete distribution process can be monitored in real time. Every transaction is recorded automatically, allowing government authorities to track inventory, monitor beneficiary distribution, and ensure that welfare schemes reach the intended recipients efficiently.

---

# Problem Statement

Government ration distribution plays an important role in providing essential food supplies to economically weaker sections of society. However, the existing system faces several operational and administrative challenges that affect transparency and efficiency.

Some common issues include:

- Duplicate or fake beneficiary records.
- Manual verification delays.
- Incorrect quantity distribution.
- Black marketing and unauthorized transactions.
- Poor inventory management.
- Lack of real-time monitoring.
- Limited accountability of ration shops.

These problems often result in delayed services and misuse of government resources.

---

# Proposed Solution

The proposed Smart Grocery Distribution System integrates IoT devices, cloud computing, and digital authentication to automate the complete grocery distribution process.

Each beneficiary is authenticated using an RFID card or QR code before receiving groceries. A Load Cell accurately measures the quantity being distributed, while ultrasonic sensors continuously monitor the stock level inside storage containers. The ESP32 processes all sensor data and uploads transaction records to a centralized cloud platform, enabling real-time monitoring through a government dashboard.

The system minimizes human intervention, improves transparency, and ensures accurate distribution of government welfare benefits.

---

# Objectives

- Digitize the Public Distribution System.
- Ensure transparent ration distribution.
- Prevent duplicate and fraudulent transactions.
- Automate quantity measurement.
- Monitor grocery inventory in real time.
- Maintain cloud-based transaction records.
- Improve beneficiary service quality.
- Enable centralized government monitoring.

---

# System Features

- RFID-based beneficiary authentication.
- QR code verification support.
- Automatic grocery weight measurement.
- Live inventory monitoring.
- Real-time cloud synchronization.
- OLED-based user interface.
- Transaction confirmation through buzzer and display.
- Low stock detection.
- Digital transaction history.
- Expandable cloud architecture.

---

# Sensors and Hardware Requirements

| Component | Category | Purpose |
|-----------|----------|---------|
| ESP32 DevKit V1 | Microcontroller | Controls the complete system, processes sensor data, and communicates with the cloud. |
| RFID RC522 Reader | Identification | Authenticates registered beneficiaries before distribution. |
| QR Code Scanner (Optional) | Identification | Alternative authentication method using digital ration cards. |
| Load Cell (10–20 kg) | Weight Sensor | Measures the quantity of grocery dispensed. |
| HX711 Amplifier Module | Signal Conditioning | Converts load cell readings into digital values for ESP32. |
| Ultrasonic Sensor (HC-SR04) | Distance Sensor | Monitors remaining stock inside storage containers. |
| SSD1306 OLED Display | Display | Displays beneficiary details, stock information, and transaction status. |
| Active Buzzer | Alert Device | Provides audio indication for successful or failed transactions. |
| Green LED | Status Indicator | Indicates successful authentication and distribution. |
| Red LED | Status Indicator | Indicates authentication failure or system errors. |
| Push Button | User Input | Confirms or cancels the distribution process. |
| Wi-Fi (ESP32 Built-in) | Communication | Uploads transaction data to the cloud server. |

---

# Controller and Processing Unit

| Device | Function |
|--------|----------|
| ESP32 DevKit V1 | Reads all sensors, authenticates users, processes transactions, updates inventory, and communicates with cloud services. |
| Cloud Database | Stores beneficiary details, inventory records, and transaction history. |
| Government Dashboard | Displays real-time reports, inventory levels, and distribution statistics. |

---

# Communication Technologies

| Technology | Purpose |
|------------|---------|
| SPI | Communication between ESP32 and RFID RC522. |
| GPIO | Interface with LEDs, buzzer, ultrasonic sensor, and push button. |
| HX711 Digital Interface | Reads load cell measurements. |
| I²C | Communication with OLED display. |
| Wi-Fi | Uploads transaction data to the cloud platform. |
| HTTP / MQTT | Cloud communication protocol for real-time monitoring. |

---

# System Workflow

1. The beneficiary visits the government grocery distribution center.
2. The RFID card or QR code is scanned for authentication.
3. The ESP32 verifies beneficiary details from the local or cloud database.
4. If authentication is successful, grocery distribution is initiated.
5. The Load Cell measures the exact quantity of groceries dispensed.
6. The Ultrasonic Sensor updates the remaining inventory level.
7. The ESP32 records the transaction details.
8. The complete transaction is uploaded to the cloud.
9. Government authorities can monitor all activities through the dashboard.
10. The OLED displays transaction confirmation while the buzzer provides an audible notification.

---

# Data Flow

| Step | Description |
|------|-------------|
| 1 | Beneficiary scans RFID card or QR code. |
| 2 | ESP32 authenticates the beneficiary. |
| 3 | Load Cell measures grocery quantity. |
| 4 | Inventory level is updated using the Ultrasonic Sensor. |
| 5 | Transaction details are stored locally. |
| 6 | ESP32 uploads transaction data via Wi-Fi. |
| 7 | Cloud database stores the updated information. |
| 8 | Government dashboard displays live inventory and transaction reports. |

---

# Estimated Cost Per Distribution Node

| Component | Approximate Cost (INR) |
|-----------|-----------------------:|
| ESP32 DevKit V1 | ₹550 |
| RFID RC522 | ₹250 |
| Load Cell | ₹400 |
| HX711 Module | ₹120 |
| Ultrasonic Sensor | ₹120 |
| OLED Display | ₹250 |
| Buzzer | ₹50 |
| LEDs and Push Button | ₹80 |
| Miscellaneous Components | ₹500 |
| **Estimated Total** | **₹2,320** |

---

# Expected Benefits

- Transparent distribution of government welfare schemes.
- Elimination of duplicate beneficiaries.
- Reduction in corruption and manual errors.
- Accurate inventory management.
- Faster beneficiary verification.
- Real-time monitoring by government authorities.
- Improved operational efficiency.
- Better utilization of public resources.

---

# Future Enhancements

- Aadhaar-based biometric authentication.
- Face recognition using ESP32-CAM.
- GPS tracking of ration delivery vehicles.
- AI-based inventory demand prediction.
- Blockchain-enabled transaction records.
- Mobile application for beneficiaries.
- SMS notifications after successful distribution.
- Offline synchronization during internet outages.

---

# Repository Structure

```text
IoT-SUMMER-SCHOOL-26
│
├── final_project
│   │
│   ├── smart_city_proposal.md
│   │
│   └── Smart Grocery Distribution System
│       │
│       ├── Assets
│       │   ├── Hardware Setup.png
│       │   ├── System Architecture.png
│       │   ├── Output Screenshot.png
│       │   └── Demonstration.mp4
│       │
│       ├── Code
│       │   └── Smart_Grocery_System.ino
│       │
│       ├── Data
│       │   └── Sample_Transactions.csv
│       │
│       └── README.md
```

---

# Conclusion

The Smart Grocery Distribution System demonstrates how IoT technologies can significantly improve the efficiency, transparency, and reliability of government welfare distribution. By integrating digital authentication, automated quantity measurement, inventory monitoring, and cloud connectivity, the proposed system minimizes human intervention while ensuring that subsidized groceries reach eligible beneficiaries accurately and securely. The solution also provides a scalable framework that can be deployed across multiple government ration distribution centers as part of future Smart City initiatives.

---

# References

- ESP32 Arduino Documentation
- MFRC522 RFID Library Documentation
- HX711 Load Cell Library Documentation
- Arduino Wire Library Documentation
- National Food Security Act (NFSA), Government of India
- Digital India Programme
- Ministry of Consumer Affairs, Food and Public Distribution

---

## Author

**P Meet Kumar**

**Roll Number:** IoT 009

**Program:** IoT and Drone Building Summer School 2026

**Institution:** Indian Institute of Technology Jammu (IIT Jammu)
