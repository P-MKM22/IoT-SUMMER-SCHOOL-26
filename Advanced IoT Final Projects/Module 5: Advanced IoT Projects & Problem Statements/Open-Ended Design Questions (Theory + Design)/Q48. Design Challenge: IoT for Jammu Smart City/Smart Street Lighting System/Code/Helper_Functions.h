#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Provides common utility functions
for diagnostics, logging,
timestamps, and system information.
*/

#include "Config.h"

// Project Information
void printProjectInfo()
{
    Serial.println();
    Serial.println("========================================");
    Serial.println(" SMART STREET LIGHTING SYSTEM");
    Serial.println(" IoT Summer School 2026");
    Serial.println("========================================");
    Serial.println();
}

// Divider
void printDivider()
{
    Serial.println("----------------------------------------");
}

// System Ready
void systemReady()
{
    printDivider();

    Serial.println("System Initialization Completed");

    Serial.println("Street Lighting Controller Ready");

    printDivider();

    Serial.println();
}

// Success Message
void printSuccess(String message)
{
    Serial.print("[SUCCESS] ");

    Serial.println(message);
}

// Warning Message
void printWarning(String message)
{
    Serial.print("[WARNING] ");

    Serial.println(message);
}

// Error Message
void printError(String message)
{
    Serial.print("[ERROR] ");

    Serial.println(message);
}

// Generate Timestamp
String getTimeStamp()
{
    unsigned long totalSeconds = millis() / 1000;

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    char buffer[12];

    sprintf(
        buffer,
        "%02d:%02d:%02d",
        hours,
        minutes,
        seconds
    );

    return String(buffer);
}

// Print Timestamp
void printTimeStamp()
{
    Serial.print("Time : ");

    Serial.println(getTimeStamp());
}

// Log Lighting Event
void logLightingEvent()
{
    printDivider();

    Serial.println("Lighting Event Log");

    Serial.print("Timestamp : ");
    Serial.println(getTimeStamp());

    Serial.print("Street : ");
    Serial.println(STREET_NAME);

    Serial.print("Pole ID : ");
    Serial.println(LIGHT_POLE_ID);

    Serial.print("Mode : ");
    Serial.println(lightingStatus.systemStatus);

    Serial.print("Light Level : ");
    Serial.println(lightingStatus.lightLevel);

    Serial.print("Motion : ");

    if (lightingStatus.motionDetected)
    {
        Serial.println("Detected");
    }
    else
    {
        Serial.println("Not Detected");
    }

    Serial.print("Lamp Status : ");

    if (lightingStatus.streetLightON)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    printDivider();

    Serial.println();
}

// Reset Controller
void resetLightingSystem()
{
    lightingStatus.lightLevel = 0;
    lightingStatus.isNight = false;
    lightingStatus.motionDetected = false;
    lightingStatus.streetLightON = false;
    lightingStatus.motionTime = 0;
    lightingStatus.systemStatus = "Reset";

    energyStatistics.totalOperatingTime = 0;
    energyStatistics.energySavedTime = 0;
    energyStatistics.motionEvents = 0;
    energyStatistics.efficiency = 0.0;

    clearAlerts();

    digitalWrite(STREET_LIGHT_PIN, LOW);

    Serial.println();

    Serial.println("Lighting System Reset");

    Serial.println();
}

// Run Diagnostics
void runDiagnostics()
{
    printDivider();

    Serial.println("Running System Diagnostics");

    if (sensorsReady())
    {
        printSuccess("Sensors Operational");
    }
    else
    {
        printError("Sensor Failure");
    }

    if (isWiFiConnected())
    {
        printSuccess("Wi-Fi Connected");
    }
    else
    {
        printWarning("Wi-Fi Disconnected");
    }

    Serial.print("OLED Display : ");
    Serial.println("Operational");

    Serial.print("Street Lamp Controller : ");
    Serial.println("Operational");

    printDivider();

    Serial.println();
}

#endif
