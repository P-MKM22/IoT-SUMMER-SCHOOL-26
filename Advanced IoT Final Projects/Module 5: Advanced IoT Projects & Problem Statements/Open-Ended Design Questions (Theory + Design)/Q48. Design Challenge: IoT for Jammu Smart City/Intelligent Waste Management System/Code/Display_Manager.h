#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls the OLED display and
shows waste level, system status,
and collection information.
*/

#include "Config.h"
#include "Waste_Manager.h"

// Startup Screen
void showStartupScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(15,10);
    display.println("SMART");

    display.setCursor(12,34);
    display.println("BIN");

    display.setTextSize(1);

    display.setCursor(15,56);
    display.println("Initializing...");

    display.display();

    delay(2500);
}

// Live Waste Status
void showWasteStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Waste Monitoring");

    display.setCursor(0,14);
    display.print("Bin : ");
    display.println(BIN_ID);

    display.setCursor(0,26);
    display.print("Fill : ");
    display.print(wasteStatus.fillPercentage,1);
    display.println("%");

    display.setCursor(0,38);
    display.print("Level : ");
    display.println(wasteStatus.level);

    display.setCursor(0,52);
    display.print("Status : ");
    display.println(wasteStatus.status);

    display.display();
}

// Collection Screen
void showCollectionStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Collection Status");

    display.setCursor(0,18);
    display.println(getCollectionRecommendation());

    display.setCursor(0,38);
    display.print("Remain : ");
    display.print(getRemainingCapacity(),1);
    display.println("%");

    display.display();
}

// Statistics Screen
void showStatisticsScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Waste Statistics");

    display.setCursor(0,14);
    display.print("Average : ");
    display.print(
        wasteStatistics.averageFillLevel,
        1
    );
    display.println("%");

    display.setCursor(0,26);
    display.print("Maximum : ");
    display.print(
        wasteStatistics.maximumFillLevel,
        1
    );
    display.println("%");

    display.setCursor(0,38);
    display.print("Alerts : ");
    display.println(
        wasteStatistics.fullAlerts
    );

    display.display();
}

// Cloud Status
void showCloudStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(12,20);
    display.println("Uploading Data");

    display.setCursor(22,40);
    display.println("Cloud Sync");

    display.display();
}

// Ready Screen
void showReadyScreen()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(18,18);
    display.println("READY");

    display.setTextSize(1);

    display.setCursor(10,54);
    display.println("Monitoring");

    display.display();
}

// Error Screen
void showSystemError()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(12,18);
    display.println("ERROR");

    display.setTextSize(1);

    display.setCursor(5,54);
    display.println("Check Sensor");

    display.display();
}

#endif
