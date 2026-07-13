#ifndef ANALYTICS_MANAGER_H
#define ANALYTICS_MANAGER_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Calculates waste statistics,
collection analytics, and
generates performance reports.
*/

#include "Config.h"
#include "Credentials.h"

// Monitoring Start Time
unsigned long monitoringStartTime = millis();

// Highest Recorded Fill Level
float highestRecordedLevel = 0.0;

// Update Analytics
void updateAnalytics()
{
    updateWasteStatistics();

    if (wasteStatus.fillPercentage > highestRecordedLevel)
    {
        highestRecordedLevel =
            wasteStatus.fillPercentage;
    }
}

// System Runtime
unsigned long getSystemRuntime()
{
    return (millis() - monitoringStartTime) / 1000;
}

// Average Fill Level
float getAverageFillLevel()
{
    return wasteStatistics.averageFillLevel;
}

// Daily Collection Estimate
int estimateDailyCollections()
{
    if (wasteStatistics.averageFillLevel >= 80)
        return 3;

    if (wasteStatistics.averageFillLevel >= 50)
        return 2;

    return 1;
}

// Bin Utilization
float getBinUtilization()
{
    return wasteStatus.fillPercentage;
}

// Maintenance Prediction
String predictMaintenance()
{
    if (wasteStatistics.fullAlerts >= 20)
    {
        return "Maintenance Required";
    }

    if (wasteStatistics.fullAlerts >= 10)
    {
        return "Inspection Recommended";
    }

    return "Normal Operation";
}

// Print Analytics Report
void printAnalyticsReport()
{
    Serial.println();

    Serial.println("Waste Analytics");
    Serial.println("--------------------------------");

    Serial.print("System Runtime : ");
    Serial.print(getSystemRuntime());
    Serial.println(" Seconds");

    Serial.print("Average Fill : ");
    Serial.print(getAverageFillLevel(),1);
    Serial.println("%");

    Serial.print("Current Fill : ");
    Serial.print(getBinUtilization(),1);
    Serial.println("%");

    Serial.print("Highest Fill : ");
    Serial.print(highestRecordedLevel,1);
    Serial.println("%");

    Serial.println();
}

// Print Performance Report
void printPerformanceReport()
{
    Serial.println();

    Serial.println("Performance Report");
    Serial.println("--------------------------------");

    Serial.print("Daily Collections : ");
    Serial.println(estimateDailyCollections());

    Serial.print("Overflow Alerts : ");
    Serial.println(wasteStatistics.fullAlerts);

    Serial.print("Maintenance : ");
    Serial.println(predictMaintenance());

    Serial.println();
}

// Print Monitoring Summary
void printMonitoringSummary()
{
    Serial.println();

    Serial.println("Monitoring Summary");
    Serial.println("--------------------------------");

    Serial.print("Bin ID : ");
    Serial.println(BIN_ID);

    Serial.print("Location : ");
    Serial.println(LOCATION);

    Serial.print("Current Status : ");
    Serial.println(wasteStatus.status);

    Serial.print("Waste Level : ");
    Serial.println(wasteStatus.level);

    Serial.println();
}

#endif
