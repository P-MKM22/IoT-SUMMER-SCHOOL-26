#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls the OLED display and
shows parking information,
system status, and statistics.
*/

#include "Config.h"
#include "Parking_Manager.h"

// Startup Screen
void showStartupScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(10, 10);
    display.println("SMART");

    display.setCursor(15, 32);
    display.println("PARKING");

    display.setTextSize(1);

    display.setCursor(12, 56);
    display.println("System Starting");

    display.display();

    delay(2500);
}

// Live Parking Status
void showParkingStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Parking Monitor");

    display.setCursor(0, 14);
    display.print("Slot : ");
    display.println(SLOT_ID);

    display.setCursor(0, 26);
    display.print("Status : ");
    display.println(parkingStatus.slotStatus);

    display.setCursor(0, 38);
    display.print("Distance : ");
    display.print(parkingStatus.distance, 1);
    display.println(" cm");

    display.setCursor(0, 52);
    display.print("Vehicle : ");

    if (parkingStatus.occupied)
    {
        display.println("Present");
    }
    else
    {
        display.println("Absent");
    }

    display.display();
}

// Statistics Screen
void showStatisticsScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Parking Statistics");

    display.setCursor(0, 14);
    display.print("Available : ");
    display.println(parkingStatistics.availableSlots);

    display.setCursor(0, 26);
    display.print("Occupied : ");
    display.println(parkingStatistics.occupiedSlots);

    display.setCursor(0, 38);
    display.print("Vehicles : ");
    display.println(parkingStatistics.totalVehicles);

    display.setCursor(0, 52);
    display.print("Usage : ");
    display.print(parkingStatistics.occupancyPercentage,1);
    display.println("%");

    display.display();
}

// Guidance Screen
void showGuidanceScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(10, 12);
    display.println("Parking Guide");

    display.setCursor(0, 32);
    display.println(getParkingRecommendation());

    display.display();
}

// Cloud Status
void showCloudStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(8, 20);
    display.println("Uploading Data");

    display.setCursor(15, 40);
    display.println("Cloud Sync");

    display.display();
}

// System Ready
void showReadyScreen()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(18, 18);
    display.println("READY");

    display.setTextSize(1);

    display.setCursor(12, 54);
    display.println("Monitoring...");

    display.display();
}

// System Error
void showSystemError()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(12, 18);
    display.println("ERROR");

    display.setTextSize(1);

    display.setCursor(5, 54);
    display.println("Check Sensor");

    display.display();
}

#endif
