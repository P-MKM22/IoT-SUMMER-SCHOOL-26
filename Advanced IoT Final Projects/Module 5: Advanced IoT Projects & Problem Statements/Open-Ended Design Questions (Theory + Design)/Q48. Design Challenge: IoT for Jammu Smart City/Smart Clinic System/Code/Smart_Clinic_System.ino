/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Main program of the Smart Clinic System.
This file integrates all modules including
patient management, health monitoring,
appointment scheduling, cloud communication,
and emergency alert handling.
*/

#include "Config.h"
#include "Credentials.h"

#include "Patient_Manager.h"
#include "Sensor_Manager.h"
#include "Display_Manager.h"
#include "Appointment_Manager.h"
#include "Health_Monitor.h"
#include "Alert_Manager.h"
#include "Cloud_Manager.h"
#include "Helper_Functions.h"

// Hardware object definitions
Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

DHT dht(DHT_PIN, DHT_TYPE);

// Global variables
Patient *currentPatient = nullptr;

unsigned long previousSensorMillis = 0;
unsigned long previousDisplayMillis = 0;
unsigned long previousCloudMillis = 0;

int patientIndex = 0;

// Setup
void setup()
{
    Serial.begin(115200);

    initializeSensors();

    initializeAlerts();

    display.begin(
        SSD1306_SWITCHCAPVCC,
        0x3C
    );

    printProjectInfo();

    showStartupScreen();

    connectWiFi();

    systemReady();

    currentPatient = &patients[0];

    scheduleAppointment("General");
}
// Main program loop
void loop()
{
    // Handle patient selection
    if (digitalRead(NEXT_BUTTON_PIN) == LOW)
    {
        nextPatient();

        delay(300);
    }

    // Check emergency button
    handleEmergency();

    // Read health sensors
    if (millis() - previousSensorMillis >= SENSOR_INTERVAL)
    {
        previousSensorMillis = millis();

        updateHealthData();

        analyzeHealth();

        printSensorData();

        printHealthReport();

        printRecommendation();

        updateAlerts();
    }

    // Refresh OLED display
    if (millis() - previousDisplayMillis >= DISPLAY_INTERVAL)
    {
        previousDisplayMillis = millis();

        showHealthData();
    }

    // Upload data to cloud
    if (millis() - previousCloudMillis >= CLOUD_INTERVAL)
    {
        previousCloudMillis = millis();

        synchronizeCloud(currentPatient);
    }
}

// Switch to next patient
void nextPatient()
{
    patientIndex++;

    if (patientIndex >= TOTAL_PATIENTS)
    {
        patientIndex = 0;
    }

    currentPatient = &patients[patientIndex];

    Serial.println();
    printDivider();

    Serial.println("Loading Next Patient...");

    printPatient(currentPatient);

    showPatientDetails(currentPatient);

    delay(2000);

    scheduleAppointment("General");

    Serial.println("Patient Ready");
}

// Display complete patient record
void displayPatientRecord()
{
    printDivider();

    printPatient(currentPatient);

    printAppointment();

    printHealthReport();

    printRecommendation();

    printTimeStamp();

    printDivider();
}
// Perform system self-test
void runSystemDiagnostics()
{
    Serial.println();
    printDivider();
    Serial.println("Running System Diagnostics");
    printDivider();

    if (sensorsReady())
    {
        printSuccess("Sensors OK");
    }
    else
    {
        printError("Sensor Initialization Failed");
    }

    if (isWiFiConnected())
    {
        printSuccess("Wi-Fi Connected");
    }
    else
    {
        printWarning("Wi-Fi Disconnected");
    }

    printDivider();
}

// Attempt Wi-Fi reconnection
void reconnectWiFi()
{
    if (isWiFiConnected())
    {
        return;
    }

    Serial.println();
    Serial.println("Reconnecting Wi-Fi...");

    connectWiFi();
}

// Process one complete patient visit
void processPatient()
{
    updateHealthData();

    analyzeHealth();

    updateAlerts();

    showHealthData();

    displayPatientRecord();

    synchronizeCloud(currentPatient);

    if (isCritical())
    {
        showEmergencyAlert();

        Serial.println();
        Serial.println("Critical Patient Detected");
        Serial.println("Medical Staff Notified");
    }
}

// Prepare system for the next patient
void prepareNextPatient()
{
    completeAppointment();

    showCompletionMessage();

    clearAlerts();

    resetClinic();

    nextPatient();
}

// Display clinic information
void printClinicInformation()
{
    Serial.println();
    printDivider();

    Serial.println("Government Smart Clinic");

    Serial.print("Clinic Name : ");
    Serial.println(CLINIC_NAME);

    Serial.print("Zone        : ");
    Serial.println(CLINIC_ZONE);

    Serial.print("Device ID   : ");
    Serial.println(DEVICE_ID);

    Serial.print("Patients    : ");
    Serial.println(TOTAL_PATIENTS);

    printDivider();
}

// Reset the complete system
void resetSystem()
{
    Serial.println();
    Serial.println("Resetting Smart Clinic...");

    clearAlerts();

    resetHealthData();

    patientIndex = 0;

    currentPatient = &patients[0];

    scheduleAppointment("General");

    showWaitingScreen();

    Serial.println("System Ready");
}

// End of Smart_Clinic_System.ino
