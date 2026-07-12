#ifndef CLOUD_MANAGER_H
#define CLOUD_MANAGER_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Handles Wi-Fi connectivity and uploads
transaction data to the cloud server.
*/

#include "Config.h"
#include "Credentials.h"
#include "Transaction_Manager.h"

// Connect to Wi-Fi
bool connectWiFi()
{
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

// Disconnect Wi-Fi
void disconnectWiFi()
{
    WiFi.disconnect(true);

    Serial.println("Wi-Fi Disconnected");
}

// Upload transaction
bool uploadTransaction()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Wi-Fi Not Connected");
        return false;
    }

    HTTPClient http;

    http.begin(SERVER_URL);

    http.addHeader("Content-Type", "application/json");

    String json =
    "{";

    json += "\"device\":\"" + String(DEVICE_ID) + "\",";
    json += "\"beneficiary\":\"" + currentTransaction.beneficiaryName + "\",";
    json += "\"rationCard\":\"" + currentTransaction.rationCard + "\",";
    json += "\"grocery\":\"" + currentTransaction.groceryName + "\",";
    json += "\"quantity\":" + String(currentTransaction.quantity, 2) + ",";
    json += "\"status\":\"SUCCESS\"";

    json += "}";

    int responseCode = http.POST(json);

    Serial.println();
    Serial.println("Cloud Upload");

    Serial.print("HTTP Response : ");
    Serial.println(responseCode);

    http.end();

    return (responseCode > 0);
}

// Synchronize transaction
void synchronizeCloud()
{
    Serial.println();

    Serial.println("Synchronizing Data...");

    if (uploadTransaction())
    {
        Serial.println("Upload Successful");
    }
    else
    {
        Serial.println("Upload Failed");
    }

    Serial.println();
}

#endif
