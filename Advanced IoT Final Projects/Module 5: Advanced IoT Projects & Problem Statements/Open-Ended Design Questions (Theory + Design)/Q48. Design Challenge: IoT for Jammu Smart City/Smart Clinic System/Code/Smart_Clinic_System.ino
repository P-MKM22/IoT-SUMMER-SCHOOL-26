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
