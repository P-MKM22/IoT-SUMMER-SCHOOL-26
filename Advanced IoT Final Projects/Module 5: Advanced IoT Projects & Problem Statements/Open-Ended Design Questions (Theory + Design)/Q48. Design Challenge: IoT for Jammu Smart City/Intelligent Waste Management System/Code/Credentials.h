#ifndef CREDENTIALS_H
#define CREDENTIALS_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores Wi-Fi credentials,
cloud configuration,
and dustbin information.
*/

// Wi-Fi Credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Device Information
const char* DEVICE_ID = "DUSTBIN_NODE_001";

// Dustbin Information
const char* BIN_ID = "BIN-001";
const char* LOCATION = "Sector-01";
const char* ZONE = "Zone-A";

// Cloud Server
const char* SERVER_URL =
"https://your-server-api.com/api/waste";

// API Key
const char* API_KEY = "YOUR_API_KEY";

// MQTT Configuration (Optional)
const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "jammu/waste/status";

// Wi-Fi Configuration
const unsigned long WIFI_TIMEOUT = 15000;
const unsigned long SYNC_INTERVAL = 5000;

// Dustbin Parameters
const int MAX_BIN_CAPACITY = 100;

// Alert Configuration
const int ALERT_LEVEL = 90;

#endif
