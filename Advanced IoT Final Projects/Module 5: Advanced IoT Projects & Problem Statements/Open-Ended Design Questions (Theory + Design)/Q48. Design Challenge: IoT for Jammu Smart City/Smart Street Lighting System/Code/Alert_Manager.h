#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

/*
Project: Smart Street Lighting System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls system alerts using
status LED and buzzer for
fault indication and maintenance.
*/

#include "Config.h"

// Initialize Alert Devices
void initializeAlerts()
{
    pinMode(STATUS_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(STATUS_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Normal Operation
void normalOperationAlert()
{
    digitalWrite(STATUS_LED_PIN, HIGH);

    noTone(BUZZER_PIN);
}

// Fault Indication
void faultAlert()
{
    digitalWrite(STATUS_LED_PIN, LOW);

    for(int i = 0; i < 3; i++)
    {
        tone(BUZZER_PIN, 2000);

        delay(200);

        noTone(BUZZER_PIN);

        delay(150);
    }
}

// Motion Detection Alert
void motionAlert()
{
    tone(BUZZER_PIN, 1200);

    delay(80);

    noTone(BUZZER_PIN);
}

// Maintenance Alert
void maintenanceAlert()
{
    for(int i = 0; i < 2; i++)
    {
        digitalWrite(STATUS_LED_PIN, HIGH);

        tone(BUZZER_PIN, 1800);

        delay(250);

        digitalWrite(STATUS_LED_PIN, LOW);

        noTone(BUZZER_PIN);

        delay(250);
    }
}

// Update Alerts
void updateAlerts()
{
    if(!sensorsReady())
    {
        faultAlert();

        return;
    }

    normalOperationAlert();

    if(lightingStatus.motionDetected)
    {
        motionAlert();
    }
}

// System Self Test
void runAlertTest()
{
    Serial.println();

    Serial.println("Alert System Test");

    digitalWrite(STATUS_LED_PIN, HIGH);

    tone(BUZZER_PIN, 1500);

    delay(500);

    noTone(BUZZER_PIN);

    digitalWrite(STATUS_LED_PIN, LOW);

    delay(300);

    digitalWrite(STATUS_LED_PIN, HIGH);

    Serial.println("Alert Test Completed");

    Serial.println();
}

// Clear Alerts
void clearAlerts()
{
    digitalWrite(STATUS_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Print Alert Status
void printAlertStatus()
{
    Serial.println();

    Serial.println("Alert Status");
    Serial.println("--------------------------------");

    Serial.print("Status LED : ");

    if(digitalRead(STATUS_LED_PIN))
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    Serial.print("Motion : ");

    if(lightingStatus.motionDetected)
    {
        Serial.println("Detected");
    }
    else
    {
        Serial.println("No Motion");
    }

    Serial.println();
}

#endif
