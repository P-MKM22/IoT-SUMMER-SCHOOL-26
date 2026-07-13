#ifndef FIRE_DETECTION_H
#define FIRE_DETECTION_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Analyzes sensor data to determine
fire risk, classify emergency level,
and generate safety recommendations.
*/

#include "Config.h"

// Analyze fire conditions
void analyzeFireRisk()
{
    fireStatus.fireDetected = false;

    if (fireStatus.flameDetected)
    {
        fireStatus.fireDetected = true;
        fireStatus.riskLevel = "CRITICAL";
    }
    else if (fireStatus.temperature >= MAX_SAFE_TEMP &&
             fireStatus.gasLevel >= MAX_SAFE_GAS)
    {
        fireStatus.fireDetected = true;
        fireStatus.riskLevel = "HIGH";
    }
    else if (fireStatus.temperature >= MAX_SAFE_TEMP)
    {
        fireStatus.riskLevel = "WARNING";
    }
    else if (fireStatus.gasLevel >= MAX_SAFE_GAS)
    {
        fireStatus.riskLevel = "WARNING";
    }
    else
    {
        fireStatus.riskLevel = "SAFE";
    }
}

// Check whether fire exists
bool isFireDetected()
{
    return fireStatus.fireDetected;
}

// Check for critical emergency
bool isCriticalFire()
{
    if (fireStatus.flameDetected)
        return true;

    if (fireStatus.temperature >= 65.0)
        return true;

    if (fireStatus.gasLevel >= 3500)
        return true;

    return false;
}

// Display fire report
void printFireReport()
{
    Serial.println();

    Serial.println("Fire Detection Report");
    Serial.println("--------------------------------");

    Serial.print("Temperature : ");
    Serial.print(fireStatus.temperature, 1);
    Serial.println(" C");

    Serial.print("Gas Level   : ");
    Serial.println(fireStatus.gasLevel);

    Serial.print("Flame       : ");

    if (fireStatus.flameDetected)
        Serial.println("YES");
    else
        Serial.println("NO");

    Serial.print("Risk Level  : ");
    Serial.println(fireStatus.riskLevel);

    Serial.print("Fire Status : ");

    if (fireStatus.fireDetected)
        Serial.println("DETECTED");
    else
        Serial.println("NORMAL");

    Serial.println();
}

// Safety recommendation
String getSafetyRecommendation()
{
    if (isCriticalFire())
    {
        return "Evacuate Area Immediately";
    }

    if (fireStatus.riskLevel == "HIGH")
    {
        return "Notify Fire Brigade";
    }

    if (fireStatus.riskLevel == "WARNING")
    {
        return "Inspect Surroundings";
    }

    return "Environment Safe";
}

// Display recommendation
void printRecommendation()
{
    Serial.print("Recommendation : ");
    Serial.println(getSafetyRecommendation());

    Serial.println();
}

// Determine response level
String getResponseLevel()
{
    if (isCriticalFire())
        return "LEVEL 3";

    if (fireStatus.riskLevel == "HIGH")
        return "LEVEL 2";

    if (fireStatus.riskLevel == "WARNING")
        return "LEVEL 1";

    return "NORMAL";
}

// Print response level
void printResponseLevel()
{
    Serial.print("Emergency Level : ");
    Serial.println(getResponseLevel());

    Serial.println();
}

#endif
