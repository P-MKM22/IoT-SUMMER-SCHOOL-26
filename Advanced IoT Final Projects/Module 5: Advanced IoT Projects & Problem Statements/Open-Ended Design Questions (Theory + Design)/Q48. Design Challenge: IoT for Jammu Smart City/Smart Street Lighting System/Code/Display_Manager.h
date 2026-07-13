#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls the OLED display and
shows the live system status,
sensor readings, and energy statistics.
*/

#include "Config.h"
#include "Lighting_Manager.h"

// Startup Screen
void showStartupScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(10, 10);
    display.println("SMART");

    display.setCursor(10, 34);
    display.println("LIGHT");

    display.setTextSize(1);

    display.setCursor(18, 56);
    display.println("Initializing...");

    display.display();

    delay(2500);
}

// Live Status Screen
void showLightingStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Street Lighting");

    display.setCursor(0,14);
    display.print("Mode : ");
    display.println(lightingStatus.systemStatus);

    display.setCursor(0,26);
    display.print("Light : ");
    display.println(lightingStatus.lightLevel);

    display.setCursor(0,38);
    display.print("Motion : ");

    if(lightingStatus.motionDetected)
        display.println("Detected");
    else
        display.println("None");

    display.setCursor(0,52);
    display.print("Lamp : ");

    if(lightingStatus.streetLightON)
        display.println("ON");
    else
        display.println("OFF");

    display.display();
}

// Energy Statistics Screen
void showEnergyStatistics()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Energy Report");

    display.setCursor(0,14);
    display.print("Events : ");
    display.println(energyStatistics.motionEvents);

    display.setCursor(0,26);
    display.print("Run : ");
    display.print(energyStatistics.totalOperatingTime);
    display.println(" s");

    display.setCursor(0,38);
    display.print("Saved : ");
    display.print(energyStatistics.energySavedTime);
    display.println(" s");

    display.setCursor(0,52);
    display.print("Eff : ");
    display.print(energyStatistics.efficiency,1);
    display.println("%");

    display.display();
}

// Cloud Status
void showCloudStatus()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(10,20);
    display.println("Uploading Data");

    display.setCursor(18,40);
    display.println("Cloud Sync");

    display.display();
}

// Maintenance Screen
void showMaintenanceMode()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(0,15);
    display.println("SERVICE");

    display.setTextSize(1);

    display.setCursor(12,52);
    display.println("Maintenance");

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

    display.setCursor(12,54);
    display.println("Monitoring");

    display.display();
}

// Error Screen
void showSystemError()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(10,18);
    display.println("ERROR");

    display.setTextSize(1);

    display.setCursor(8,54);
    display.println("Check Sensors");

    display.display();
}

#endif
