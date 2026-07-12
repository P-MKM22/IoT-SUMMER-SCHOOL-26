#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Reads all health sensors and updates
patient health parameters.
*/

#include "Config.h"

HealthData currentHealth;

// Initialize all sensors
void initializeSensors()
{
    dht.begin();

    pinMode(HEART_RATE_PIN, INPUT);
    pinMode(SPO2_PIN, INPUT);

    Serial.println("Sensors Initialized");
}

// Read body temperature
float readTemperature()
{
    float temperature = dht.readTemperature();

    if (isnan(temperature))
    {
        Serial.println("Temperature Sensor Error");
        return 0.0;
    }

    return temperature;
}

// Read heart rate
int readHeartRate()
{
    int sensorValue = analogRead(HEART_RATE_PIN);

    int heartRate = map(
        sensorValue,
        0,
        4095,
        60,
        140
    );

    return heartRate;
}

// Read SpO₂
int readSpO2()
{
    int sensorValue = analogRead(SPO2_PIN);

    int spo2 = map(
        sensorValue,
        0,
        4095,
        90,
        100
    );

    return spo2;
}

// Update health parameters
void updateHealthData()
{
    currentHealth.temperature = readTemperature();

    currentHealth.heartRate = readHeartRate();

    currentHealth.spo2 = readSpO2();
}

// Display sensor values
void printSensorData()
{
    Serial.println();

    Serial.println("Current Health Parameters");
    Serial.println("------------------------------");

    Serial.print("Temperature : ");
    Serial.print(currentHealth.temperature, 1);
    Serial.println(" C");

    Serial.print("Heart Rate  : ");
    Serial.print(currentHealth.heartRate);
    Serial.println(" BPM");

    Serial.print("SpO2        : ");
    Serial.print(currentHealth.spo2);
    Serial.println(" %");

    Serial.println();
}

// Check sensor status
bool sensorsReady()
{
    float temperature = dht.readTemperature();

    if (isnan(temperature))
    {
        return false;
    }

    return true;
}

#endif
