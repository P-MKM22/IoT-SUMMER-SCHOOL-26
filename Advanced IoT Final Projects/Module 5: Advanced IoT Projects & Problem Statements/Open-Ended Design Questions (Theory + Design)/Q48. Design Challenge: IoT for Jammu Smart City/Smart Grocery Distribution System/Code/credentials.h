#ifndef CREDENTIALS_H
#define CREDENTIALS_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores Wi-Fi and cloud configuration.
Do not upload this file with real credentials.
*/

// Wi-Fi Credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Device Information
const char* DEVICE_ID = "PDS_NODE_001";

// Cloud Configuration
const char* SERVER_URL = "https://your-server-api.com/api/transactions";

// MQTT Configuration (Optional)
const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "smartcity/pds";

// API Authentication Token
const char* API_TOKEN = "YOUR_API_TOKEN";

#endif
