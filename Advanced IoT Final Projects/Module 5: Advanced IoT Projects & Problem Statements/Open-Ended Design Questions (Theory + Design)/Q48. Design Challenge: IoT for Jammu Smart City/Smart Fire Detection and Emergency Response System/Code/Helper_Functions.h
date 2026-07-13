#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Provides utility functions used across
the Smart Fire Detection System.
*/

#include "Config.h"

// Display project information
void printProjectInfo()
{
    Serial.println();
    Serial.println("========================================");
    Serial.println(" SMART FIRE DETECTION SYSTEM");
    Serial.println(" IoT Summer School 2026");
    Serial.println(" Advanced IoT Final Project");
    Serial.println("========================================");
    Serial.println();
}

// Print divider
void printDivider()
{
    Serial.println("----------------------------------------");
}

// Display system ready message
void systemReady()
{
    printDivider();

    Serial.println("System Initialization Completed");

    Serial.println("Fire Monitoring Started");

    printDivider();

    Serial.println();
}

// Print success message
void printSuccess(String message)
{
    Serial.print("[SUCCESS] ");

    Serial.println(message);
}

// Print warning message
void printWarning(String message)
{
    Serial.print("[WARNING] ");

    Serial.println(message);
}

// Print error message
void printError(String message)
{
    Serial.print("[ERROR] ");

    Serial.println(message);
}

// Generate system timestamp
String getTimeStamp()
{
    unsigned long totalSeconds = millis() / 1000;

    int hours = totalSeconds / 3600;

    int minutes = (totalSeconds % 3600) / 60;

    int seconds = totalSeconds % 60;

    char timeBuffer[12];

    sprintf(
        timeBuffer,
        "%02d:%02d:%02d",
        hours,
        minutes,
        seconds
    );

    return String(timeBuffer);
}

// Print timestamp
void printTimeStamp()
{
    Serial.print("Time : ");

    Serial.println(getTimeStamp());
}

// Log incident information
void logIncident()
{
    printDivider();

    Serial.println("Incident Log");

    Serial.print("Time : ");

    Serial.println(getTimeStamp());

    Serial.print("Risk Level : ");

    Serial.println(fireStatus.riskLevel);

    Serial.print("Temperature : ");

    Serial.print(fireStatus.temperature);

    Serial.println(" C");

    Serial.print("Gas Level : ");

    Serial.println(fireStatus.gasLevel);

    Serial.print("Flame : ");

    if (fireStatus.flameDetected)
    {
        Serial.println("Detected");
    }
    else
    {
        Serial.println("Not Detected");
    }

    printDivider();

    Serial.println();
}

// Reset monitoring status
void resetMonitoring()
{
    fireStatus.temperature = 0.0;

    fireStatus.gasLevel = 0;

    fireStatus.flameDetected = false;

    fireStatus.fireDetected = false;

    fireStatus.riskLevel = "SAFE";

    clearAlerts();

    Serial.println();

    Serial.println("Monitoring Reset Completed");

    Serial.println();
}

// Perform system diagnostics
void runDiagnostics()
{
    printDivider();

    Serial.println("Running Diagnostics");

    if (sensorsReady())
    {
        printSuccess("Sensors Operational");
    }
    else
    {
        printError("Sensor Failure");
    }

    if (gpsReady())
    {
        printSuccess("GPS Available");
    }
    else
    {
        printWarning("GPS Unavailable");
    }

    if (isWiFiConnected())
    {
        printSuccess("Wi-Fi Connected");
    }
    else
    {
        printWarning("Wi-Fi Disconnected");
    }

    printDivider();

    Serial.println();
}

#endif
