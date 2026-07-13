#ifndef LIGHTING_MANAGER_H
#define LIGHTING_MANAGER_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls street light operation,
manages motion-based lighting,
and records lighting statistics.
*/

#include "Config.h"
#include "Credentials.h"

EnergyStatistics energyStatistics;

bool previousMotionState = false;

// Initialize Lighting System
void initializeLighting()
{
    pinMode(STREET_LIGHT_PIN, OUTPUT);
    pinMode(STATUS_LED_PIN, OUTPUT);

    digitalWrite(STREET_LIGHT_PIN, LOW);
    digitalWrite(STATUS_LED_PIN, LOW);

    energyStatistics.totalOperatingTime = 0;
    energyStatistics.energySavedTime = 0;
    energyStatistics.motionEvents = 0;
    energyStatistics.efficiency = 0.0;

    lightingStatus.streetLightON = false;
}

// Turn ON Street Light
void turnLightON()
{
    digitalWrite(STREET_LIGHT_PIN, HIGH);
    digitalWrite(STATUS_LED_PIN, HIGH);

    lightingStatus.streetLightON = true;
    lightingStatus.motionTime = millis();
}

// Turn OFF Street Light
void turnLightOFF()
{
    digitalWrite(STREET_LIGHT_PIN, LOW);
    digitalWrite(STATUS_LED_PIN, LOW);

    lightingStatus.streetLightON = false;
}

// Motion Event Detection
void detectMotionEvent()
{
    if (!previousMotionState && lightingStatus.motionDetected)
    {
        energyStatistics.motionEvents++;

        Serial.println();
        Serial.println("Motion Detected");
        Serial.println("Street Light Activated");
        Serial.println();
    }

    previousMotionState = lightingStatus.motionDetected;
}

// Automatic Lighting Control
void updateLighting()
{
    detectMotionEvent();

    if (!lightingStatus.isNight)
    {
        turnLightOFF();

        lightingStatus.systemStatus = "Day Mode";

        return;
    }

    if (lightingStatus.motionDetected)
    {
        turnLightON();

        lightingStatus.systemStatus = "Motion Detected";
    }
    else
    {
        if (lightingStatus.streetLightON)
        {
            if (millis() - lightingStatus.motionTime >= LIGHT_TIMEOUT)
            {
                turnLightOFF();

                lightingStatus.systemStatus = "Night Standby";
            }
        }
    }
}

// Update Energy Statistics
void updateEnergyStatistics()
{
    if (lightingStatus.streetLightON)
    {
        energyStatistics.totalOperatingTime++;
    }
    else
    {
        energyStatistics.energySavedTime++;
    }

    unsigned long totalTime =
        energyStatistics.totalOperatingTime +
        energyStatistics.energySavedTime;

    if (totalTime > 0)
    {
        energyStatistics.efficiency =
            ((float)energyStatistics.energySavedTime /
            totalTime) * 100.0;
    }
}

// Print Lighting Status
void printLightingStatus()
{
    Serial.println();

    Serial.println("Street Lighting Status");
    Serial.println("--------------------------------");

    Serial.print("Environment : ");
    Serial.println(lightingStatus.systemStatus);

    Serial.print("Street Light : ");

    if (lightingStatus.streetLightON)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    Serial.print("Motion Events : ");
    Serial.println(energyStatistics.motionEvents);

    Serial.println();
}

// Print Energy Statistics
void printEnergyStatistics()
{
    Serial.println();

    Serial.println("Energy Statistics");
    Serial.println("--------------------------------");

    Serial.print("Operating Time : ");
    Serial.print(energyStatistics.totalOperatingTime);
    Serial.println(" s");

    Serial.print("Energy Saved : ");
    Serial.print(energyStatistics.energySavedTime);
    Serial.println(" s");

    Serial.print("Efficiency : ");
    Serial.print(energyStatistics.efficiency, 1);
    Serial.println("%");

    Serial.println();
}

#endif
