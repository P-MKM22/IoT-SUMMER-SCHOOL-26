#ifndef CLOUD_MANAGER_H
#define CLOUD_MANAGER_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Handles Wi-Fi connectivity,
cloud communication, and
uploads street lighting data.
*/

#include "Config.h"
#include "Credentials.h"

// Connect to Wi-Fi
bool connectWiFi()
{
    Serial.println();
    Serial.print("Connecting to Wi-Fi");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");

        delay(500);

        if (millis() - startTime >= WIFI_TIMEOUT)
        {
            Serial.println();
            Serial.println("Wi-Fi Connection Failed");

            return false;
        }
    }

    Serial.println();
    Serial.println("Wi-Fi Connected");

    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    return true;
}

// Check Wi-Fi Status
bool isWiFiConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

// Upload Lighting Data
void uploadLightingData()
{
    if (!isWiFiConnected())
    {
        Serial.println();
        Serial.println("Cloud Upload Skipped");
        Serial.println("Wi-Fi Not Connected");

        return;
    }

    HTTPClient http;

    http.begin(SERVER_URL);

    http.addHeader("Content-Type", "application/json");
    http.addHeader("API-Key", API_KEY);

    String jsonData = "{";

    jsonData += "\"device\":\"";
    jsonData += DEVICE_ID;
    jsonData += "\",";

    jsonData += "\"street\":\"";
    jsonData += STREET_NAME;
    jsonData += "\",";

    jsonData += "\"zone\":\"";
    jsonData += ZONE_NAME;
    jsonData += "\",";

    jsonData += "\"pole_id\":\"";
    jsonData += LIGHT_POLE_ID;
    jsonData += "\",";

    jsonData += "\"light_level\":";
    jsonData += String(lightingStatus.lightLevel);
    jsonData += ",";

    jsonData += "\"is_night\":";
    jsonData += lightingStatus.isNight ? "true" : "false";
    jsonData += ",";

    jsonData += "\"motion_detected\":";
    jsonData += lightingStatus.motionDetected ? "true" : "false";
    jsonData += ",";

    jsonData += "\"street_light\":";
    jsonData += lightingStatus.streetLightON ? "true" : "false";
    jsonData += ",";

    jsonData += "\"efficiency\":";
    jsonData += String(energyStatistics.efficiency, 1);

    jsonData += "}";

    int responseCode = http.POST(jsonData);

    Serial.println();
    Serial.println("Cloud Synchronization");
    Serial.println("--------------------------------");

    Serial.print("HTTP Response : ");
    Serial.println(responseCode);

    if (responseCode > 0)
    {
        Serial.println("Lighting Data Uploaded");
    }
    else
    {
        Serial.println("Cloud Upload Failed");
    }

    http.end();
}

// Print Network Information
void printNetworkStatus()
{
    Serial.println();

    Serial.println("Network Information");
    Serial.println("--------------------------------");

    Serial.print("Street : ");
    Serial.println(STREET_NAME);

    Serial.print("Zone : ");
    Serial.println(ZONE_NAME);

    Serial.print("Pole ID : ");
    Serial.println(LIGHT_POLE_ID);

    Serial.print("Wi-Fi : ");

    if (isWiFiConnected())
    {
        Serial.println("Connected");
    }
    else
    {
        Serial.println("Disconnected");
    }

    Serial.println();
}

// Cloud Synchronization
void synchronizeCloud()
{
    printNetworkStatus();

    uploadLightingData();
}

// Reconnect Wi-Fi
void reconnectWiFi()
{
    if (isWiFiConnected())
    {
        return;
    }

    Serial.println();

    Serial.println("Reconnecting Wi-Fi...");

    connectWiFi();
}

#endif
