/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Main program of the Smart Street
Lighting System. This file integrates
all modules and controls the complete
operation of the system.
*/

#include "Config.h"
#include "Credentials.h"

#include "Sensor_Manager.h"
#include "Lighting_Manager.h"
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

    initializeLighting();

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

    // Read Sensors
    if (millis() - previousSensorMillis >= SENSOR_INTERVAL)
    {
        previousSensorMillis = millis();

        updateSensorData();

        updateLighting();

        updateAlerts();

        printSensorData();

        printLightingStatus();
    }

    // Update OLED
    if (millis() - previousDisplayMillis >= DISPLAY_INTERVAL)
    {
        previousDisplayMillis = millis();

        if (lightingStatus.streetLightON)
        {
            showLightingStatus();
        }
        else
        {
            showEnergyStatistics();
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
    logLightingEvent();
}
