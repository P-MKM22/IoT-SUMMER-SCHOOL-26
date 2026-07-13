#ifndef CLOUD_MANAGER_H
#define CLOUD_MANAGER_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Handles Wi-Fi connectivity,
cloud communication, and
uploads waste monitoring data.
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

// Upload Waste Data
void uploadWasteData()
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

    jsonData += "\"bin_id\":\"";
    jsonData += BIN_ID;
    jsonData += "\",";

    jsonData += "\"location\":\"";
    jsonData += LOCATION;
    jsonData += "\",";

    jsonData += "\"zone\":\"";
    jsonData += ZONE;
    jsonData += "\",";

    jsonData += "\"distance\":";
    jsonData += String(wasteStatus.distance, 1);
    jsonData += ",";

    jsonData += "\"fill_percentage\":";
    jsonData += String(wasteStatus.fillPercentage, 1);
    jsonData += ",";

    jsonData += "\"level\":\"";
    jsonData += wasteStatus.level;
    jsonData += "\",";

    jsonData += "\"status\":\"";
    jsonData += wasteStatus.status;
    jsonData += "\",";

    jsonData += "\"is_full\":";
    jsonData += wasteStatus.isFull ? "true" : "false";

    jsonData += "}";

    int responseCode = http.POST(jsonData);

    Serial.println();
    Serial.println("Cloud Synchronization");
    Serial.println("--------------------------------");

    Serial.print("HTTP Response : ");
    Serial.println(responseCode);

    if (responseCode > 0)
    {
        Serial.println("Waste Data Uploaded Successfully");
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

    Serial.print("Bin ID : ");
    Serial.println(BIN_ID);

    Serial.print("Location : ");
    Serial.println(LOCATION);

    Serial.print("Zone : ");
    Serial.println(ZONE);

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

// Synchronize Cloud
void synchronizeCloud()
{
    printNetworkStatus();

    uploadWasteData();
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
