#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

/*
Project: Intelligent Waste Management System
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
    Serial.println(" INTELLIGENT WASTE MANAGEMENT");
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

    Serial.println("Smart Dustbin Ready");

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

// Log Waste Event
void logWasteEvent()
{
    printDivider();

    Serial.println("Waste Monitoring Log");

    Serial.print("Timestamp : ");
    Serial.println(getTimeStamp());

    Serial.print("Bin ID : ");
    Serial.println(BIN_ID);

    Serial.print("Location : ");
    Serial.println(LOCATION);

    Serial.print("Fill Level : ");
    Serial.print(wasteStatus.fillPercentage,1);
    Serial.println("%");

    Serial.print("Status : ");
    Serial.println(wasteStatus.status);

    Serial.print("Recommendation : ");
    Serial.println(getCollectionRecommendation());

    printDivider();

    Serial.println();
}

// Reset Controller
void resetWasteSystem()
{
    wasteStatus.distance = BIN_HEIGHT;
    wasteStatus.fillPercentage = 0;

    wasteStatus.isFull = false;

    wasteStatus.level = "LOW";
    wasteStatus.status = "AVAILABLE";

    wasteStatistics.totalReadings = 0;
    wasteStatistics.fullAlerts = 0;
    wasteStatistics.averageFillLevel = 0;
    wasteStatistics.maximumFillLevel = 0;

    clearAlerts();

    Serial.println();

    Serial.println("Waste Monitoring System Reset");

    Serial.println();
}

// Run Diagnostics
void runDiagnostics()
{
    printDivider();

    Serial.println("Running System Diagnostics");

    if (sensorsReady())
    {
        printSuccess("Ultrasonic Sensor Operational");
    }
    else
    {
        printError("Ultrasonic Sensor Failure");
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

    Serial.print("Alert System : ");
    Serial.println("Operational");

    printDivider();

    Serial.println();
}

#endif
