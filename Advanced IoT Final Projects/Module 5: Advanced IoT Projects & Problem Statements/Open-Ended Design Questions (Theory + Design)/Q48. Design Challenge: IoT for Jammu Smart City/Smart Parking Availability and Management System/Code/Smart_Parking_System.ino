/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Main program of the Smart Parking
Availability and Management System.
This file integrates all modules and
controls the complete parking workflow.
*/

#include "Config.h"
#include "Credentials.h"

#include "Sensor_Manager.h"
#include "Parking_Manager.h"
#include "Display_Manager.h"
#include "Alert_Manager.h"
#include "Cloud_Manager.h"
#include "Analytics_Manager.h"
#include "Helper_Functions.h"

// Hardware Objects
Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

// Timer Variables
unsigned long previousSensorMillis = 0;
unsigned long previousDisplayMillis = 0;
unsigned long previousCloudMillis = 0;
unsigned long previousAnalyticsMillis = 0;

// System Setup
void setup()
{
    Serial.begin(115200);

    initializeSensors();

    initializeParking();

    initializeAlerts();

    display.begin(
        SSD1306_SWITCHCAPVCC,
        0x3C
    );

    printProjectInfo();

    showStartupScreen();

    connectWiFi();

    runDiagnostics();

    systemReady();

    showReadyScreen();
}

// Main Loop
void loop()
{
    // Maintain Wi-Fi Connection
    reconnectWiFi();

    // Read Parking Sensor
    if (millis() - previousSensorMillis >= SENSOR_INTERVAL)
    {
        previousSensorMillis = millis();

        updateSensorData();

        updateParkingSystem();

        printSensorData();

        printParkingStatistics();

        printAlertStatus();

        updateAlerts();
    }

    // Update OLED Display
    if (millis() - previousDisplayMillis >= DISPLAY_INTERVAL)
    {
        previousDisplayMillis = millis();

        if (parkingStatus.occupied)
        {
            showParkingStatus();
        }
        else
        {
            showGuidanceScreen();
        }
    }

    // Upload Data to Cloud
    if (millis() - previousCloudMillis >= CLOUD_INTERVAL)
    {
        previousCloudMillis = millis();

        showCloudStatus();

        synchronizeCloud();
    }

    // Generate Analytics
    if (millis() - previousAnalyticsMillis >= 10000)
    {
        previousAnalyticsMillis = millis();

        updateAnalytics();

        printAnalyticsReport();

        printMonitoringSummary();
    }

    // Log Parking Events
    if (parkingStatus.occupied)
    {
        logParkingEvent();

        vehicleEntryAlert();
    }
    else
    {
        vehicleExitAlert();
    }
}
