#ifndef CREDENTIALS_H
#define CREDENTIALS_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores Wi-Fi credentials, cloud
configuration, and parking details.
*/

// Wi-Fi Credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Device Information
const char* DEVICE_ID = "PARKING_NODE_001";

// Parking Information
const char* PARKING_NAME = "Jammu Smart Parking";
const char* PARKING_ZONE = "Zone-A";
const char* SLOT_ID = "A-01";

// Cloud Server
const char* SERVER_URL =
"https://your-server-api.com/api/parking";

// API Key
const char* API_KEY = "YOUR_API_KEY";

// MQTT Configuration (Optional)
const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "jammu/parking/status";

// Wi-Fi Configuration
const unsigned long WIFI_TIMEOUT = 15000;
const unsigned long SYNC_INTERVAL = 5000;

// Parking Capacity
const int TOTAL_SLOTS = 100;

#endif
