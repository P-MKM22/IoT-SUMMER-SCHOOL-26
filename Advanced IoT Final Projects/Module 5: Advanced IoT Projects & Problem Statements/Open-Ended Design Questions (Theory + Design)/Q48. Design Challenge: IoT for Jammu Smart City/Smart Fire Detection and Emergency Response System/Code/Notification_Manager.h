#ifndef NOTIFICATION_MANAGER_H
#define NOTIFICATION_MANAGER_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Handles emergency notifications,
incident reporting, and response
tracking for fire emergencies.
*/

#include "Config.h"
#include "Credentials.h"
#include "GPS_Manager.h"

// Notify Fire Brigade
void notifyFireBrigade()
{
    Serial.println();
    Serial.println("Emergency Notification");
    Serial.println("------------------------------");

    Serial.print("Department : Fire Brigade");
    Serial.println();

    Serial.print("Emergency No : ");
    Serial.println(FIRE_BRIGADE);

    Serial.print("Location : ");
    Serial.println(LOCATION_NAME);

    Serial.print("Zone : ");
    Serial.println(ZONE_NAME);

    Serial.println("Status : Notification Sent");

    Serial.println();
}

// Notify Emergency Control Room
void notifyControlRoom()
{
    Serial.println();

    Serial.println("Control Room Notification");
    Serial.println("------------------------------");

    Serial.print("Emergency No : ");
    Serial.println(CONTROL_ROOM);

    Serial.println("Incident Logged");

    Serial.println("Response Team Activated");

    Serial.println();
}

// Notify Disaster Response Team
void notifyDisasterResponse()
{
    Serial.println();

    Serial.println("Disaster Response Team");
    Serial.println("------------------------------");

    Serial.print("Emergency No : ");
    Serial.println(DISASTER_RESPONSE);

    Serial.println("Standby Team Alerted");

    Serial.println();
}

// Generate incident report
void generateIncidentReport()
{
    Incident incident = createIncident();

    Serial.println();

    Serial.println("Fire Incident Report");
    Serial.println("------------------------------");

    Serial.print("Incident ID : ");
    Serial.println(incident.incidentID);

    Serial.print("Location : ");
    Serial.println(incident.location);

    Serial.print("Temperature : ");
    Serial.print(fireStatus.temperature, 1);
    Serial.println(" C");

    Serial.print("Gas Level : ");
    Serial.println(fireStatus.gasLevel);

    Serial.print("Flame : ");

    if (fireStatus.flameDetected)
        Serial.println("Detected");
    else
        Serial.println("Not Detected");

    Serial.print("Risk Level : ");
    Serial.println(fireStatus.riskLevel);

    Serial.println();
}

// Estimate response time
void estimateResponseTime()
{
    Serial.println("Estimated Response Time");

    Serial.println("------------------------------");

    if (fireStatus.riskLevel == "CRITICAL")
    {
        Serial.println("5 Minutes");
    }
    else if (fireStatus.riskLevel == "HIGH")
    {
        Serial.println("10 Minutes");
    }
    else if (fireStatus.riskLevel == "WARNING")
    {
        Serial.println("15 Minutes");
    }
    else
    {
        Serial.println("No Emergency");
    }

    Serial.println();
}

// Notify all emergency services
void notifyEmergencyServices()
{
    notifyFireBrigade();

    notifyControlRoom();

    notifyDisasterResponse();

    generateIncidentReport();

    estimateResponseTime();
}

// Display notification status
void printNotificationStatus()
{
    Serial.println();

    Serial.println("Notification Status");
    Serial.println("------------------------------");

    if (fireStatus.fireDetected)
    {
        Serial.println("Emergency Services Notified");
    }
    else
    {
        Serial.println("System Monitoring Normally");
    }

    Serial.println();
}

#endif
