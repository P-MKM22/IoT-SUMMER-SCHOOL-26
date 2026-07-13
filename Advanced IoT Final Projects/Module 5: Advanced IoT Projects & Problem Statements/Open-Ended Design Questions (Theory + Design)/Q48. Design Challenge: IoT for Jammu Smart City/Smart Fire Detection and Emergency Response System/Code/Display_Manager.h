#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls all OLED display screens including
system status, sensor monitoring, fire alerts,
GPS information, and cloud synchronization.
*/

#include "Config.h"
#include "GPS_Manager.h"

// Startup screen
void showStartupScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(15, 8);
    display.println("SMART");

    display.setCursor(25, 30);
    display.println("FIRE");

    display.setTextSize(1);

    display.setCursor(10, 54);
    display.println("Detection System");

    display.display();

    delay(2500);
}

// Monitoring screen
void showMonitoringScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Fire Monitoring");

    display.setCursor(0, 16);
    display.print("Temp : ");
    display.print(fireStatus.temperature, 1);
    display.println(" C");

    display.setCursor(0, 28);
    display.print("Gas  : ");
    display.println(fireStatus.gasLevel);

    display.setCursor(0, 40);
    display.print("Flame: ");

    if (fireStatus.flameDetected)
        display.println("YES");
    else
        display.println("NO");

    display.setCursor(0, 54);
    display.print("Risk : ");
    display.println(fireStatus.riskLevel);

    display.display();
}

// GPS screen
void showLocationScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Incident Location");

    display.setCursor(0, 18);
    display.print("Lat:");

    display.println(getLatitude(), 4);

    display.setCursor(0, 34);
    display.print("Lng:");

    display.println(getLongitude(), 4);

    display.setCursor(0, 52);
    display.println(ZONE_NAME);

    display.display();
}

// Emergency screen
void showEmergencyScreen()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(12, 6);
    display.println("FIRE");

    display.setCursor(10, 30);
    display.println("ALERT");

    display.setTextSize(1);

    display.setCursor(8, 55);
    display.println("Evacuate Area");

    display.display();
}

// Fire brigade notification
void showNotificationScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 10);
    display.println("Emergency Alert");

    display.setCursor(0, 28);
    display.println("Fire Brigade");

    display.setCursor(0, 42);
    display.println("Notified");

    display.display();
}

// Cloud synchronization
void showCloudSyncScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(5, 18);
    display.println("Uploading Data");

    display.setCursor(25, 36);
    display.println("Please Wait");

    display.display();
}

// System ready screen
void showReadyScreen()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(18, 18);
    display.println("READY");

    display.setTextSize(1);

    display.setCursor(12, 52);
    display.println("Monitoring...");

    display.display();
}

// System error
void showSystemError()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(15, 18);
    display.println("ERROR");

    display.setTextSize(1);

    display.setCursor(0, 52);
    display.println("Check Sensors");

    display.display();
}

#endif
