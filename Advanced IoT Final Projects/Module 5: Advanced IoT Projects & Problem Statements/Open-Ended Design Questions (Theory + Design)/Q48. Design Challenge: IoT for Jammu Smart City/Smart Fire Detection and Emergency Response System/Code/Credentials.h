#ifndef CREDENTIALS_H
#define CREDENTIALS_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores Wi-Fi credentials, cloud server
configuration, and notification settings.
*/

// Wi-Fi Credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Device Information
const char* DEVICE_ID = "FIRE_NODE_001";

// Deployment Information
const char* LOCATION_NAME = "Jammu Smart City";
const char* ZONE_NAME = "Zone-A";

// Cloud Server Configuration
const char* SERVER_URL =
"https://your-server-api.com/api/fireAlert";

// API Key
const char* API_KEY = "YOUR_API_KEY";

// MQTT Configuration (Optional)
const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "jammu/fire/alerts";

// Emergency Contact Information
const char* FIRE_BRIGADE = "101";
const char* CONTROL_ROOM = "112";
const char* DISASTER_RESPONSE = "108";

// Wi-Fi Timeout
const unsigned long WIFI_TIMEOUT = 15000;

// Cloud Synchronization Time
const unsigned long SYNC_INTERVAL = 5000;

// GPS Coordinates
const float LATITUDE = 32.7266;
const float LONGITUDE = 74.8570;

#endif
