#ifndef CLOUD_MANAGER_H
#define CLOUD_MANAGER_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Handles Wi-Fi connectivity and uploads
fire incident information to the cloud server.
*/

#include "Config.h"
#include "Credentials.h"
#include "GPS_Manager.h"

// Connect ESP32 to Wi-Fi
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

        if (millis() - startTime > WIFI_TIMEOUT)
        {
            Serial.println();
            Serial.println("Connection Failed");

            return false;
        }
    }

    Serial.println();
    Serial.println("Wi-Fi Connected");

    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    return true;
}

// Check Wi-Fi status
bool isWiFiConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

// Upload fire incident
void uploadIncident()
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

    jsonData += "\"location\":\"";
    jsonData += LOCATION_NAME;
    jsonData += "\",";

    jsonData += "\"zone\":\"";
    jsonData += ZONE_NAME;
    jsonData += "\",";

    jsonData += "\"temperature\":";
    jsonData += String(fireStatus.temperature,1);
    jsonData += ",";

    jsonData += "\"gasLevel\":";
    jsonData += String(fireStatus.gasLevel);
    jsonData += ",";

    jsonData += "\"flameDetected\":";
    jsonData += fireStatus.flameDetected ? "true" : "false";
    jsonData += ",";

    jsonData += "\"riskLevel\":\"";
    jsonData += fireStatus.riskLevel;
    jsonData += "\",";

    jsonData += "\"latitude\":";
    jsonData += String(getLatitude(),6);
    jsonData += ",";

    jsonData += "\"longitude\":";
    jsonData += String(getLongitude(),6);

    jsonData += "}";

    int responseCode = http.POST(jsonData);

    Serial.println();
    Serial.println("Cloud Synchronization");
    Serial.println("------------------------------");

    Serial.print("HTTP Response : ");
    Serial.println(responseCode);

    if (responseCode > 0)
    {
        Serial.println("Incident Uploaded Successfully");
    }
    else
    {
        Serial.println("Upload Failed");
    }

    http.end();
}

// Print network information
void printNetworkStatus()
{
    Serial.println();

    Serial.println("Network Information");
    Serial.println("------------------------------");

    Serial.print("Device : ");
    Serial.println(DEVICE_ID);

    Serial.print("Location : ");
    Serial.println(LOCATION_NAME);

    Serial.print("Zone : ");
    Serial.println(ZONE_NAME);

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

// Synchronize with cloud
void synchronizeCloud()
{
    printNetworkStatus();

    uploadIncident();
}

// Reconnect Wi-Fi
void reconnectWiFi()
{
    if (isWiFiConnected())
    {
        return;
    }

    Serial.println();
    Serial.println("Attempting Reconnection...");

    connectWiFi();
}

#endif
