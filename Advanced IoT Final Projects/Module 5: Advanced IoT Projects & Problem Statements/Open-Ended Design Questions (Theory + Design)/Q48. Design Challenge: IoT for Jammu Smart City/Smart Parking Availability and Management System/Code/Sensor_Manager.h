#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Initializes the ultrasonic sensor,
measures parking distance, and
updates parking status.
*/

#include "Config.h"

ParkingStatus parkingStatus;

// Initialize ultrasonic sensor
void initializeSensors()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(VEHICLE_BUTTON_PIN, INPUT_PULLUP);

    Serial.println("Parking Sensor Initialized");
}

// Measure distance
float measureDistance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);

    float distance = duration * 0.0343 / 2.0;

    return distance;
}

// Detect vehicle
bool vehicleDetected()
{
    if (digitalRead(VEHICLE_BUTTON_PIN) == LOW)
    {
        return true;
    }

    return parkingStatus.distance <= SLOT_DISTANCE;
}

// Read all sensors
void updateSensorData()
{
    parkingStatus.distance = measureDistance();

    parkingStatus.occupied = vehicleDetected();

    if (parkingStatus.occupied)
    {
        parkingStatus.slotStatus = "OCCUPIED";
    }
    else
    {
        parkingStatus.slotStatus = "AVAILABLE";
    }
}

// Display sensor values
void printSensorData()
{
    Serial.println();

    Serial.println("Parking Sensor Data");
    Serial.println("------------------------------");

    Serial.print("Distance : ");
    Serial.print(parkingStatus.distance, 1);
    Serial.println(" cm");

    Serial.print("Vehicle  : ");

    if (parkingStatus.occupied)
    {
        Serial.println("Detected");
    }
    else
    {
        Serial.println("Not Detected");
    }

    Serial.print("Status   : ");
    Serial.println(parkingStatus.slotStatus);

    Serial.println();
}

// Sensor validation
bool sensorsReady()
{
    float distance = measureDistance();

    if (distance <= 0)
    {
        return false;
    }

    return true;
}

// Debug values
void printRawSensorValues()
{
    Serial.println();

    Serial.println("Raw Sensor Values");
    Serial.println("------------------------------");

    Serial.print("Distance : ");
    Serial.println(parkingStatus.distance);

    Serial.print("Button   : ");
    Serial.println(digitalRead(VEHICLE_BUTTON_PIN));

    Serial.println();
}

#endif
