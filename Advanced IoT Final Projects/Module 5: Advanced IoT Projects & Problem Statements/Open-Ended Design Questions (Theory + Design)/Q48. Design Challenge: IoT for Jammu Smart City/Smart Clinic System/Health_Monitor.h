#ifndef HEALTH_MONITOR_H
#define HEALTH_MONITOR_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Analyzes patient health parameters,
determines health status, and detects
medical emergencies.
*/

#include "Config.h"

// Analyze patient health
void analyzeHealth()
{
    if (currentHealth.temperature > MAX_BODY_TEMP)
    {
        currentHealth.status = "High Temperature";
    }
    else if (currentHealth.temperature < MIN_BODY_TEMP)
    {
        currentHealth.status = "Low Temperature";
    }
    else if (currentHealth.heartRate > MAX_HEART_RATE)
    {
        currentHealth.status = "High Heart Rate";
    }
    else if (currentHealth.heartRate < MIN_HEART_RATE)
    {
        currentHealth.status = "Low Heart Rate";
    }
    else if (currentHealth.spo2 < MIN_SPO2)
    {
        currentHealth.status = "Low SpO2";
    }
    else
    {
        currentHealth.status = "Normal";
    }
}

// Check if patient is critical
bool isCritical()
{
    if (currentHealth.temperature > 39.0)
        return true;

    if (currentHealth.temperature < 35.0)
        return true;

    if (currentHealth.heartRate > 130)
        return true;

    if (currentHealth.heartRate < 45)
        return true;

    if (currentHealth.spo2 < 90)
        return true;

    return false;
}

// Display health report
void printHealthReport()
{
    Serial.println();

    Serial.println("Health Report");
    Serial.println("-----------------------------");

    Serial.print("Temperature : ");
    Serial.print(currentHealth.temperature, 1);
    Serial.println(" C");

    Serial.print("Heart Rate  : ");
    Serial.print(currentHealth.heartRate);
    Serial.println(" BPM");

    Serial.print("SpO2        : ");
    Serial.print(currentHealth.spo2);
    Serial.println(" %");

    Serial.print("Status      : ");
    Serial.println(currentHealth.status);

    if (isCritical())
    {
        Serial.println("Priority    : CRITICAL");
    }
    else
    {
        Serial.println("Priority    : NORMAL");
    }

    Serial.println();
}

// Medical recommendation
String getRecommendation()
{
    if (isCritical())
    {
        return "Immediate Medical Attention";
    }

    if (currentHealth.status == "High Temperature")
    {
        return "Consult General Physician";
    }

    if (currentHealth.status == "Low SpO2")
    {
        return "Oxygen Support Required";
    }

    if (currentHealth.status == "High Heart Rate")
    {
        return "Cardiology Consultation";
    }

    if (currentHealth.status == "Low Heart Rate")
    {
        return "ECG Recommended";
    }

    return "Patient is Healthy";
}

// Print recommendation
void printRecommendation()
{
    Serial.print("Recommendation : ");
    Serial.println(getRecommendation());

    Serial.println();
}

#endif
