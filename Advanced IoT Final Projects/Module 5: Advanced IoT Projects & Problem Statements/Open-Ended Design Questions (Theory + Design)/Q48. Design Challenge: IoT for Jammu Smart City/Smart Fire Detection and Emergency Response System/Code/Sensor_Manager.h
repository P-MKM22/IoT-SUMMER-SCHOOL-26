#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Reads all environmental sensors and
updates the fire monitoring data.
*/

#include "Config.h"

FireStatus fireStatus;

// Initialize all sensors
void initializeSensors()
{
    dht.begin();

    pinMode(FLAME_SENSOR_PIN, INPUT);
    pinMode(GAS_SENSOR_PIN, INPUT);

    Serial.println("Fire Monitoring Sensors Initialized");
}

// Read temperature
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

// Read gas level
int readGasLevel()
{
    return analogRead(GAS_SENSOR_PIN);
}

// Read flame sensor
bool readFlameSensor()
{
    return digitalRead(FLAME_SENSOR_PIN) == FLAME_DETECTED;
}

// Update all sensor readings
void updateSensorData()
{
    fireStatus.temperature = readTemperature();

    fireStatus.gasLevel = readGasLevel();

    fireStatus.flameDetected = readFlameSensor();
}

// Print sensor readings
void printSensorData()
{
    Serial.println();

    Serial.println("Environmental Monitoring");
    Serial.println("------------------------------");

    Serial.print("Temperature : ");
    Serial.print(fireStatus.temperature, 1);
    Serial.println(" C");

    Serial.print("Gas Level   : ");
    Serial.println(fireStatus.gasLevel);

    Serial.print("Flame       : ");

    if (fireStatus.flameDetected)
    {
        Serial.println("DETECTED");
    }
    else
    {
        Serial.println("NOT DETECTED");
    }

    Serial.println();
}

// Verify sensor status
bool sensorsReady()
{
    float temperature = dht.readTemperature();

    if (isnan(temperature))
    {
        return false;
    }

    return true;
}

// Display raw values for debugging
void printRawSensorValues()
{
    Serial.println();

    Serial.println("Raw Sensor Values");
    Serial.println("------------------------------");

    Serial.print("Temperature : ");
    Serial.println(fireStatus.temperature);

    Serial.print("Gas ADC     : ");
    Serial.println(fireStatus.gasLevel);

    Serial.print("Flame Input : ");
    Serial.println(digitalRead(FLAME_SENSOR_PIN));

    Serial.println();
}

#endif
