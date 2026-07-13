#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Initializes the LDR and PIR sensors,
reads environmental conditions,
and updates the lighting status.
*/

#include "Config.h"

LightingStatus lightingStatus;

// Initialize Sensors
void initializeSensors()
{
    pinMode(LDR_PIN, INPUT);

    pinMode(PIR_PIN, INPUT);

    Serial.println("LDR Sensor Initialized");

    Serial.println("PIR Sensor Initialized");
}

// Read Ambient Light
int readLightLevel()
{
    return analogRead(LDR_PIN);
}

// Detect Motion
bool detectMotion()
{
    return digitalRead(PIR_PIN);
}

// Determine Day or Night
bool isNightTime()
{
    return readLightLevel() < LDR_THRESHOLD;
}

// Read All Sensors
void updateSensorData()
{
    lightingStatus.lightLevel = readLightLevel();

    lightingStatus.isNight = isNightTime();

    lightingStatus.motionDetected = detectMotion();

    if (lightingStatus.isNight)
    {
        lightingStatus.systemStatus = "Night";
    }
    else
    {
        lightingStatus.systemStatus = "Day";
    }
}

// Print Sensor Data
void printSensorData()
{
    Serial.println();

    Serial.println("Street Lighting Sensor Data");
    Serial.println("--------------------------------");

    Serial.print("Light Level : ");
    Serial.println(lightingStatus.lightLevel);

    Serial.print("Environment : ");
    Serial.println(lightingStatus.systemStatus);

    Serial.print("Motion : ");

    if (lightingStatus.motionDetected)
    {
        Serial.println("Detected");
    }
    else
    {
        Serial.println("No Motion");
    }

    Serial.println();
}

// Sensor Health Check
bool sensorsReady()
{
    int value = readLightLevel();

    if (value < 0 || value > 4095)
    {
        return false;
    }

    return true;
}

// Print Raw Values
void printRawSensorValues()
{
    Serial.println();

    Serial.println("Raw Sensor Values");
    Serial.println("--------------------------------");

    Serial.print("LDR ADC : ");
    Serial.println(readLightLevel());

    Serial.print("PIR State : ");
    Serial.println(digitalRead(PIR_PIN));

    Serial.println();
}

#endif
