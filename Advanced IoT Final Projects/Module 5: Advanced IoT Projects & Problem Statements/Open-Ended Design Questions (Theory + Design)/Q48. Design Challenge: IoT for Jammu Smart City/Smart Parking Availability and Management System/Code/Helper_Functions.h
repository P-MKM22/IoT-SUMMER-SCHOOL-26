#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Provides utility functions for
logging, diagnostics, timestamps,
and system information.
*/

#include "Config.h"

// Project Information
void printProjectInfo()
{
    Serial.println();
    Serial.println("========================================");
    Serial.println(" SMART PARKING SYSTEM");
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

    Serial.println("Parking Monitoring Started");

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

// Log Parking Event
void logParkingEvent()
{
    printDivider();

    Serial.println("Parking Event Log");

    Serial.print("Timestamp : ");
    Serial.println(getTimeStamp());

    Serial.print("Slot ID : ");
    Serial.println(SLOT_ID);

    Serial.print("Status : ");
    Serial.println(parkingStatus.slotStatus);

    Serial.print("Distance : ");
    Serial.print(parkingStatus.distance, 1);
    Serial.println(" cm");

    Serial.print("Vehicles Served : ");
    Serial.println(parkingStatistics.totalVehicles);

    printDivider();

    Serial.println();
}

// Reset Parking Data
void resetParkingSystem()
{
    parkingStatus.distance = 0.0;

    parkingStatus.occupied = false;

    parkingStatus.slotStatus = "AVAILABLE";

    parkingStatus.occupiedTime = 0;

    parkingStatistics.totalVehicles = 0;

    parkingStatistics.availableSlots = TOTAL_SLOTS;

    parkingStatistics.occupiedSlots = 0;

    parkingStatistics.occupancyPercentage = 0.0;

    clearAlerts();

    Serial.println();

    Serial.println("Parking System Reset");

    Serial.println();
}

// Run Diagnostics
void runDiagnostics()
{
    printDivider();

    Serial.println("Running Diagnostics");

    if (sensorsReady())
    {
        printSuccess("Ultrasonic Sensor OK");
    }
    else
    {
        printError("Ultrasonic Sensor Failed");
    }

    if (isWiFiConnected())
    {
        printSuccess("Wi-Fi Connected");
    }
    else
    {
        printWarning("Wi-Fi Not Connected");
    }

    printDivider();

    Serial.println();
}

#endif
