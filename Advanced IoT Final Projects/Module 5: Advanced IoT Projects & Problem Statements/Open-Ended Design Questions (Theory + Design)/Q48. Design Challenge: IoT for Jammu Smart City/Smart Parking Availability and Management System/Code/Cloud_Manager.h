#ifndef CLOUD_MANAGER_H
#define CLOUD_MANAGER_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Manages Wi-Fi connectivity and uploads
parking information to the cloud server.
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

// Upload parking data
void uploadParkingData()
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

    jsonData += "\"parking\":\"";
    jsonData += PARKING_NAME;
    jsonData += "\",";

    jsonData += "\"zone\":\"";
    jsonData += PARKING_ZONE;
    jsonData += "\",";

    jsonData += "\"slot\":\"";
    jsonData += SLOT_ID;
    jsonData += "\",";

    jsonData += "\"distance\":";
    jsonData += String(parkingStatus.distance, 1);
    jsonData += ",";

    jsonData += "\"occupied\":";
    jsonData += parkingStatus.occupied ? "true" : "false";
    jsonData += ",";

    jsonData += "\"status\":\"";
    jsonData += parkingStatus.slotStatus;
    jsonData += "\"";

    jsonData += "}";

    int responseCode = http.POST(jsonData);

    Serial.println();
    Serial.println("Cloud Synchronization");
    Serial.println("------------------------------");

    Serial.print("HTTP Response : ");
    Serial.println(responseCode);

    if (responseCode > 0)
    {
        Serial.println("Parking Data Uploaded");
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

    Serial.print("Parking : ");
    Serial.println(PARKING_NAME);

    Serial.print("Zone : ");
    Serial.println(PARKING_ZONE);

    Serial.print("Slot : ");
    Serial.println(SLOT_ID);

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

// Synchronize cloud
void synchronizeCloud()
{
    printNetworkStatus();

    uploadParkingData();
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
