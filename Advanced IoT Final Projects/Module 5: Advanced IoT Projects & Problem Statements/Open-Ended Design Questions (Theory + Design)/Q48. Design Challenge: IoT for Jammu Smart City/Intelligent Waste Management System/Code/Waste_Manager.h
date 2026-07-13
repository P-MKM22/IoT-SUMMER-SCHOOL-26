#ifndef WASTE_MANAGER_H
#define WASTE_MANAGER_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Manages waste level classification,
collection requirements,
and waste statistics.
*/

#include "Config.h"
#include "Credentials.h"

WasteStatistics wasteStatistics;

// Initialize Waste Manager
void initializeWasteManager()
{
    wasteStatistics.totalReadings = 0;
    wasteStatistics.fullAlerts = 0;
    wasteStatistics.averageFillLevel = 0.0;
    wasteStatistics.maximumFillLevel = 0.0;
}

// Update Statistics
void updateWasteStatistics()
{
    wasteStatistics.totalReadings++;

    wasteStatistics.averageFillLevel =
        ((wasteStatistics.averageFillLevel *
        (wasteStatistics.totalReadings - 1)) +
        wasteStatus.fillPercentage) /
        wasteStatistics.totalReadings;

    if (wasteStatus.fillPercentage >
        wasteStatistics.maximumFillLevel)
    {
        wasteStatistics.maximumFillLevel =
            wasteStatus.fillPercentage;
    }

    if (wasteStatus.isFull)
    {
        wasteStatistics.fullAlerts++;
    }
}

// Collection Recommendation
String getCollectionRecommendation()
{
    if (wasteStatus.fillPercentage >= HIGH_LEVEL)
    {
        return "Immediate Collection";
    }

    if (wasteStatus.fillPercentage >= MEDIUM_LEVEL)
    {
        return "Schedule Collection";
    }

    return "No Collection Required";
}

// Remaining Capacity
float getRemainingCapacity()
{
    return 100.0 - wasteStatus.fillPercentage;
}

// Estimated Available Volume
float getAvailableHeight()
{
    return wasteStatus.distance;
}

// Update Waste Management
void updateWasteManager()
{
    updateWasteStatistics();
}

// Print Waste Status
void printWasteStatus()
{
    Serial.println();

    Serial.println("Waste Bin Status");
    Serial.println("--------------------------------");

    Serial.print("Bin ID : ");
    Serial.println(BIN_ID);

    Serial.print("Fill Level : ");
    Serial.print(wasteStatus.fillPercentage,1);
    Serial.println("%");

    Serial.print("Status : ");
    Serial.println(wasteStatus.status);

    Serial.print("Recommendation : ");
    Serial.println(getCollectionRecommendation());

    Serial.println();
}

// Print Statistics
void printWasteStatistics()
{
    Serial.println();

    Serial.println("Waste Statistics");
    Serial.println("--------------------------------");

    Serial.print("Total Readings : ");
    Serial.println(wasteStatistics.totalReadings);

    Serial.print("Average Fill : ");
    Serial.print(
        wasteStatistics.averageFillLevel,
        1
    );
    Serial.println("%");

    Serial.print("Maximum Fill : ");
    Serial.print(
        wasteStatistics.maximumFillLevel,
        1
    );
    Serial.println("%");

    Serial.print("Overflow Alerts : ");
    Serial.println(wasteStatistics.fullAlerts);

    Serial.println();
}

// Overflow Detection
bool isOverflowDetected()
{
    return wasteStatus.fillPercentage >= 100.0;
}

// Bin Availability
bool isBinAvailable()
{
    return !wasteStatus.isFull;
}

#endif
