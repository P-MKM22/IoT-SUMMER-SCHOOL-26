#ifndef CREDENTIALS_H
#define CREDENTIALS_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores Wi-Fi credentials,
cloud configuration, and
street lighting information.
*/

// Wi-Fi Credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Device Information
const char* DEVICE_ID = "STREET_LIGHT_NODE_001";

// Street Information
const char* STREET_NAME = "Smart City Road";
const char* ZONE_NAME = "Zone-A";
const char* LIGHT_POLE_ID = "SL-001";

// Cloud Server
const char* SERVER_URL =
"https://your-server-api.com/api/streetlight";

// API Key
const char* API_KEY = "YOUR_API_KEY";

// MQTT Configuration (Optional)
const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "jammu/streetlight/status";

// Wi-Fi Configuration
const unsigned long WIFI_TIMEOUT = 15000;
const unsigned long SYNC_INTERVAL = 5000;

// Lighting Parameters
const int MAX_BRIGHTNESS = 255;
const int MIN_BRIGHTNESS = 0;

// Motion Delay
const unsigned long MOTION_DELAY = 10000;

#endif
