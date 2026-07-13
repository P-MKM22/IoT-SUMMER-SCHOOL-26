#ifndef ANALYTICS_MANAGER_H
#define ANALYTICS_MANAGER_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Calculates energy consumption,
lighting efficiency, system usage,
and generates analytical reports.
*/

#include "Config.h"
#include "Credentials.h"

// System Start Time
unsigned long monitoringStartTime = millis();

// Peak Motion Count
int peakMotionEvents = 0;

// Update Analytics
void updateAnalytics()
{
    updateEnergyStatistics();

    if (energyStatistics.motionEvents > peakMotionEvents)
    {
        peakMotionEvents = energyStatistics.motionEvents;
    }
}

// Total System Runtime
unsigned long getSystemRuntime()
{
    return (millis() - monitoringStartTime) / 1000;
}

// Lamp Operating Time
unsigned long getLampOperatingTime()
{
    return energyStatistics.totalOperatingTime;
}

// Energy Saving Percentage
float getEnergySavingPercentage()
{
    return energyStatistics.efficiency;
}

// Average Motion Events
float getAverageMotionEvents()
{
    unsigned long runtime = getSystemRuntime();

    if(runtime == 0)
    {
        return 0;
    }

    return (float)energyStatistics.motionEvents /
           (runtime / 60.0);
}

// Estimate Daily Energy Saving
float estimateDailySaving()
{
    return (energyStatistics.efficiency / 100.0) * 24.0;
}

// Predict Maintenance
String predictMaintenance()
{
    if (energyStatistics.motionEvents > 1000)
    {
        return "Maintenance Recommended";
    }

    if (energyStatistics.motionEvents > 500)
    {
        return "Inspection Required";
    }

    return "Normal Operation";
}

// Print Analytics Report
void printAnalyticsReport()
{
    Serial.println();

    Serial.println("Street Lighting Analytics");
    Serial.println("--------------------------------");

    Serial.print("System Runtime : ");
    Serial.print(getSystemRuntime());
    Serial.println(" Seconds");

    Serial.print("Lamp Runtime : ");
    Serial.print(getLampOperatingTime());
    Serial.println(" Seconds");

    Serial.print("Motion Events : ");
    Serial.println(energyStatistics.motionEvents);

    Serial.print("Peak Events : ");
    Serial.println(peakMotionEvents);

    Serial.print("Energy Saving : ");
    Serial.print(getEnergySavingPercentage(),1);
    Serial.println("%");

    Serial.println();
}

// Print Performance Report
void printPerformanceReport()
{
    Serial.println();

    Serial.println("Performance Report");
    Serial.println("--------------------------------");

    Serial.print("Average Motion/Minute : ");
    Serial.println(getAverageMotionEvents(),2);

    Serial.print("Estimated Daily Saving : ");
    Serial.print(estimateDailySaving(),1);
    Serial.println(" Hours");

    Serial.print("Maintenance Status : ");
    Serial.println(predictMaintenance());

    Serial.println();
}

// Print System Summary
void printMonitoringSummary()
{
    Serial.println();

    Serial.println("Lighting Summary");
    Serial.println("--------------------------------");

    Serial.print("Street : ");
    Serial.println(STREET_NAME);

    Serial.print("Pole ID : ");
    Serial.println(LIGHT_POLE_ID);

    Serial.print("Current Mode : ");
    Serial.println(lightingStatus.systemStatus);

    Serial.print("Lamp Status : ");

    if(lightingStatus.streetLightON)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    Serial.println();
}

#endif
