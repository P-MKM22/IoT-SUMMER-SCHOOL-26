#ifndef PARKING_MANAGER_H
#define PARKING_MANAGER_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Manages parking occupancy,
vehicle entry/exit detection,
parking statistics, and slot status.
*/

#include "Config.h"
#include "Credentials.h"

ParkingStatistics parkingStatistics;

bool previousVehicleState = false;

// Initialize parking system
void initializeParking()
{
    parkingStatistics.totalVehicles = 0;
    parkingStatistics.availableSlots = TOTAL_SLOTS;
    parkingStatistics.occupiedSlots = 0;
    parkingStatistics.occupancyPercentage = 0.0;

    parkingStatus.occupiedTime = 0;
}

// Update parking statistics
void updateParkingStatistics()
{
    if (parkingStatus.occupied)
    {
        parkingStatistics.occupiedSlots = 1;
        parkingStatistics.availableSlots = TOTAL_SLOTS - 1;
    }
    else
    {
        parkingStatistics.occupiedSlots = 0;
        parkingStatistics.availableSlots = TOTAL_SLOTS;
    }

    parkingStatistics.occupancyPercentage =
        ((float)parkingStatistics.occupiedSlots /
         TOTAL_SLOTS) * 100.0;
}

// Detect vehicle entry
void detectVehicleEntry()
{
    if (!previousVehicleState && parkingStatus.occupied)
    {
        parkingStatistics.totalVehicles++;

        parkingStatus.occupiedTime = millis();

        Serial.println();
        Serial.println("Vehicle Entered");

        Serial.print("Slot : ");
        Serial.println(SLOT_ID);

        Serial.println();
    }

    previousVehicleState = parkingStatus.occupied;
}

// Detect vehicle exit
void detectVehicleExit()
{
    if (previousVehicleState && !parkingStatus.occupied)
    {
        unsigned long parkingDuration =
            (millis() - parkingStatus.occupiedTime) / 1000;

        Serial.println();

        Serial.println("Vehicle Exited");

        Serial.print("Parking Time : ");
        Serial.print(parkingDuration);
        Serial.println(" Seconds");

        Serial.println();
    }

    previousVehicleState = parkingStatus.occupied;
}

// Complete parking management
void updateParkingSystem()
{
    detectVehicleEntry();

    detectVehicleExit();

    updateParkingStatistics();
}

// Print parking statistics
void printParkingStatistics()
{
    Serial.println();

    Serial.println("Parking Statistics");
    Serial.println("------------------------------");

    Serial.print("Total Slots : ");
    Serial.println(TOTAL_SLOTS);

    Serial.print("Available : ");
    Serial.println(parkingStatistics.availableSlots);

    Serial.print("Occupied : ");
    Serial.println(parkingStatistics.occupiedSlots);

    Serial.print("Vehicles Served : ");
    Serial.println(parkingStatistics.totalVehicles);

    Serial.print("Occupancy : ");
    Serial.print(parkingStatistics.occupancyPercentage,1);
    Serial.println("%");

    Serial.println();
}

// Return slot status
String getParkingStatus()
{
    if (parkingStatus.occupied)
    {
        return "Occupied";
    }

    return "Available";
}

// Check slot availability
bool isSlotAvailable()
{
    return !parkingStatus.occupied;
}

// Parking recommendation
String getParkingRecommendation()
{
    if (isSlotAvailable())
    {
        return "Slot Available";
    }

    return "Select Another Slot";
}

#endif
