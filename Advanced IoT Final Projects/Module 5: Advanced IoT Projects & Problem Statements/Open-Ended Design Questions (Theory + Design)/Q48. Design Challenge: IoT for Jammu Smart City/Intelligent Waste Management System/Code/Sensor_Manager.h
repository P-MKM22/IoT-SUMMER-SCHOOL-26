#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Initializes the ultrasonic sensor,
measures garbage level,
and updates waste status.
*/

#include "Config.h"

WasteStatus wasteStatus;

// Initialize Sensor
void initializeSensors()
{
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.println("Ultrasonic Sensor Initialized");
}

// Measure Distance
float measureDistance()
{
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIGGER_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if (duration == 0)
    {
        return BIN_HEIGHT;
    }

    float distance = duration * 0.0343 / 2.0;

    if (distance > BIN_HEIGHT)
    {
        distance = BIN_HEIGHT;
    }

    return distance;
}

// Calculate Fill Percentage
float calculateFillPercentage(float distance)
{
    float fill = ((BIN_HEIGHT - distance) / BIN_HEIGHT) * 100.0;

    if (fill < 0)
        fill = 0;

    if (fill > 100)
        fill = 100;

    return fill;
}

// Update Waste Level
void updateWasteLevel()
{
    if (wasteStatus.fillPercentage >= HIGH_LEVEL)
    {
        wasteStatus.level = "HIGH";
        wasteStatus.status = "FULL";
        wasteStatus.isFull = true;
    }
    else if (wasteStatus.fillPercentage >= MEDIUM_LEVEL)
    {
        wasteStatus.level = "MEDIUM";
        wasteStatus.status = "COLLECTION REQUIRED";
        wasteStatus.isFull = false;
    }
    else
    {
        wasteStatus.level = "LOW";
        wasteStatus.status = "AVAILABLE";
        wasteStatus.isFull = false;
    }
}

// Read Sensor Data
void updateSensorData()
{
    wasteStatus.distance = measureDistance();

    wasteStatus.fillPercentage =
        calculateFillPercentage(
            wasteStatus.distance
        );

    wasteStatus.lastUpdate = millis();

    updateWasteLevel();
}

// Print Sensor Data
void printSensorData()
{
    Serial.println();

    Serial.println("Waste Bin Sensor Data");
    Serial.println("--------------------------------");

    Serial.print("Distance : ");
    Serial.print(wasteStatus.distance);
    Serial.println(" cm");

    Serial.print("Fill Level : ");
    Serial.print(wasteStatus.fillPercentage,1);
    Serial.println("%");

    Serial.print("Level : ");
    Serial.println(wasteStatus.level);

    Serial.print("Status : ");
    Serial.println(wasteStatus.status);

    Serial.println();
}

// Sensor Diagnostics
bool sensorsReady()
{
    float distance = measureDistance();

    if (distance < 0 || distance > BIN_HEIGHT)
    {
        return false;
    }

    return true;
}

// Debug Values
void printRawSensorValues()
{
    Serial.println();

    Serial.println("Raw Sensor Values");
    Serial.println("--------------------------------");

    Serial.print("Measured Distance : ");
    Serial.println(measureDistance());

    Serial.println();
}

#endif
