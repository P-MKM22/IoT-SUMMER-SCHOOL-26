/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Main program of the Intelligent
Waste Management System.
This file integrates all project
modules and controls the complete
system operation.
*/

#include "Config.h"
#include "Credentials.h"

#include "Sensor_Manager.h"
#include "Waste_Manager.h"
#include "Display_Manager.h"
#include "Alert_Manager.h"
#include "Cloud_Manager.h"
#include "Analytics_Manager.h"
#include "Helper_Functions.h"

// OLED Object
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

    Wire.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED Initialization Failed");

        while (true);
    }

    initializeSensors();

    initializeWasteManager();

    initializeAlerts();

    printProjectInfo();

    showStartupScreen();

    connectWiFi();

    runDiagnostics();

    systemReady();

    showReadyScreen();
}

// Main Program
void loop()
{
    // Maintain Network Connection
    reconnectWiFi();

    // Read Sensor Data
    if (millis() - previousSensorMillis >= SENSOR_INTERVAL)
    {
        previousSensorMillis = millis();

        updateSensorData();

        updateWasteManager();

        updateAlerts();

        printSensorData();

        printWasteStatus();
    }

    // Update OLED Display
    if (millis() - previousDisplayMillis >= DISPLAY_INTERVAL)
    {
        previousDisplayMillis = millis();

        if (wasteStatus.isFull)
        {
            showCollectionStatus();
        }
        else
        {
            showWasteStatus();
        }
    }

    // Cloud Synchronization
    if (millis() - previousCloudMillis >= CLOUD_INTERVAL)
    {
        previousCloudMillis = millis();

        showCloudStatus();

        synchronizeCloud();
    }

    // Analytics
    if (millis() - previousAnalyticsMillis >= 10000)
    {
        previousAnalyticsMillis = millis();

        updateAnalytics();

        printAnalyticsReport();

        printPerformanceReport();

        printMonitoringSummary();
    }

    // Event Logging
    logWasteEvent();
}
