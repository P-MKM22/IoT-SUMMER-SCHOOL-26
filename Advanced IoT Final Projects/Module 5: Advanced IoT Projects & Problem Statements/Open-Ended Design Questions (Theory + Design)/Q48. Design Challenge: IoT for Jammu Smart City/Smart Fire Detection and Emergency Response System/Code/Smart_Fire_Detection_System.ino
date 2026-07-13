/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Main program of the Smart Fire Detection
and Emergency Response System. This file
integrates all modules and controls the
complete fire monitoring workflow.
*/

#include "Config.h"
#include "Credentials.h"

#include "Sensor_Manager.h"
#include "Fire_Detection.h"
#include "GPS_Manager.h"
#include "Display_Manager.h"
#include "Alert_Manager.h"
#include "Cloud_Manager.h"
#include "Notification_Manager.h"
#include "Helper_Functions.h"

// Hardware Objects
Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

DHT dht(DHT_PIN, DHT_TYPE);

// Timer Variables
unsigned long previousSensorMillis = 0;
unsigned long previousDisplayMillis = 0;
unsigned long previousCloudMillis = 0;

// System Setup
void setup()
{
    Serial.begin(115200);

    initializeSensors();

    initializeGPS();

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
    // Alarm testing
    runAlarmTest();

    // Manual reset
    resetEmergency();

    // Maintain Wi-Fi connection
    reconnectWiFi();

    // Read sensors periodically
    if (millis() - previousSensorMillis >= SENSOR_INTERVAL)
    {
        previousSensorMillis = millis();

        updateSensorData();

        updateLocation();

        analyzeFireRisk();

        printSensorData();

        printFireReport();

        printRecommendation();

        printResponseLevel();

        updateAlerts();
    }

    // Refresh OLED display
    if (millis() - previousDisplayMillis >= DISPLAY_INTERVAL)
    {
        previousDisplayMillis = millis();

        if (isFireDetected())
        {
            showEmergencyScreen();
        }
        else
        {
            showMonitoringScreen();
        }
    }

    // Cloud synchronization
    if (millis() - previousCloudMillis >= CLOUD_INTERVAL)
    {
        previousCloudMillis = millis();

        synchronizeCloud();
    }

    // Handle emergency workflow
    if (isFireDetected())
    {
        notifyEmergencyServices();

        showNotificationScreen();

        logIncident();

        delay(3000);
    }
}
