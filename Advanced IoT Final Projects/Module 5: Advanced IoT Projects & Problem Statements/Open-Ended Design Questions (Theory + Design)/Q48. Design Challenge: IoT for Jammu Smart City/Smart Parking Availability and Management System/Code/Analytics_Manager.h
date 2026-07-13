#ifndef ANALYTICS_MANAGER_H
#define ANALYTICS_MANAGER_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Calculates parking utilization,
vehicle statistics, occupancy trends,
and generates analytics reports.
*/

#include "Config.h"
#include "Credentials.h"

// Total monitoring time
unsigned long monitoringStartTime = millis();

// Peak occupancy
float peakOccupancy = 0.0;

// Update occupancy percentage
void updateAnalytics()
{
    parkingStatistics.occupancyPercentage =
        ((float)parkingStatistics.occupiedSlots /
        TOTAL_SLOTS) * 100.0;

    if (parkingStatistics.occupancyPercentage > peakOccupancy)
    {
        peakOccupancy =
            parkingStatistics.occupancyPercentage;
    }
}

// Parking utilization
float getParkingUtilization()
{
    return parkingStatistics.occupancyPercentage;
}

// Average parking duration
unsigned long getParkingDuration()
{
    if (parkingStatus.occupied)
    {
        return (millis() -
                parkingStatus.occupiedTime) / 1000;
    }

    return 0;
}

// Estimated available slots
int estimateAvailableSlots()
{
    return parkingStatistics.availableSlots;
}

// Peak parking usage
float getPeakOccupancy()
{
    return peakOccupancy;
}

// Generate analytics report
void printAnalyticsReport()
{
    Serial.println();

    Serial.println("Parking Analytics");
    Serial.println("------------------------------");

    Serial.print("Total Slots : ");
    Serial.println(TOTAL_SLOTS);

    Serial.print("Occupied Slots : ");
    Serial.println(parkingStatistics.occupiedSlots);

    Serial.print("Available Slots : ");
    Serial.println(parkingStatistics.availableSlots);

    Serial.print("Vehicles Served : ");
    Serial.println(parkingStatistics.totalVehicles);

    Serial.print("Current Usage : ");
    Serial.print(getParkingUtilization(), 1);
    Serial.println("%");

    Serial.print("Peak Usage : ");
    Serial.print(getPeakOccupancy(), 1);
    Serial.println("%");

    Serial.print("Parking Time : ");
    Serial.print(getParkingDuration());
    Serial.println(" Seconds");

    Serial.println();
}

// Monitoring summary
void printMonitoringSummary()
{
    unsigned long runningTime =
        (millis() - monitoringStartTime) / 1000;

    Serial.println();

    Serial.println("Monitoring Summary");
    Serial.println("------------------------------");

    Serial.print("System Uptime : ");
    Serial.print(runningTime);
    Serial.println(" Seconds");

    Serial.print("Current Status : ");
    Serial.println(parkingStatus.slotStatus);

    Serial.print("Recommendation : ");
    Serial.println(getParkingRecommendation());

    Serial.println();
}

// Predict parking availability
String predictAvailability()
{
    if (parkingStatistics.availableSlots > 20)
    {
        return "High Availability";
    }

    if (parkingStatistics.availableSlots > 10)
    {
        return "Moderate Availability";
    }

    if (parkingStatistics.availableSlots > 0)
    {
        return "Limited Availability";
    }

    return "Parking Full";
}

#endif
