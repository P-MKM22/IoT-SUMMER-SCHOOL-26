#ifndef CREDENTIALS_H
#define CREDENTIALS_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores Wi-Fi credentials and cloud
communication settings.
*/

// Wi-Fi Credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Device Information
const char* DEVICE_ID = "SMART_CLINIC_001";

// Hospital Information
const char* CLINIC_NAME = "Government Smart Clinic";
const char* CLINIC_ZONE = "Zone-A";

// Cloud Server
const char* SERVER_URL =
"https://your-server-api.com/api/patientData";

// API Authentication
const char* API_KEY = "YOUR_API_KEY";

// MQTT Configuration (Optional)
const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "smartcity/clinic";

// Wi-Fi Connection Timeout
const unsigned long WIFI_TIMEOUT = 15000;

// Cloud Synchronization Interval
const unsigned long SYNC_INTERVAL = 5000;

#endif
