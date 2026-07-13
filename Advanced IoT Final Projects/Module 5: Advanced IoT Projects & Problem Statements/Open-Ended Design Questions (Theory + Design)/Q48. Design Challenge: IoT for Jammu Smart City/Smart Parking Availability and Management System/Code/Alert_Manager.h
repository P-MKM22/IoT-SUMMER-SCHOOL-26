#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls LEDs and buzzer to indicate
parking slot availability and vehicle
entry or exit events.
*/

#include "Config.h"

// Initialize alert devices
void initializeAlerts()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Slot Available
void availableAlert()
{
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Slot Occupied
void occupiedAlert()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    noTone(BUZZER_PIN);
}

// Vehicle Entry Alert
void vehicleEntryAlert()
{
    tone(BUZZER_PIN, 1500);

    delay(150);

    noTone(BUZZER_PIN);
}

// Vehicle Exit Alert
void vehicleExitAlert()
{
    tone(BUZZER_PIN, 1000);

    delay(150);

    noTone(BUZZER_PIN);
}

// Update LED Indicators
void updateAlerts()
{
    if (parkingStatus.occupied)
    {
        occupiedAlert();
    }
    else
    {
        availableAlert();
    }
}

// Parking Status
void printAlertStatus()
{
    Serial.println();

    Serial.println("Alert Status");
    Serial.println("------------------------------");

    Serial.print("Green LED : ");

    if (!parkingStatus.occupied)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    Serial.print("Red LED   : ");

    if (parkingStatus.occupied)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    Serial.println();
}

// Alarm Test
void runAlertTest()
{
    Serial.println();

    Serial.println("Running Alert Test");

    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);

    tone(BUZZER_PIN, 1800);

    delay(500);

    noTone(BUZZER_PIN);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    delay(300);

    availableAlert();

    Serial.println("Alert Test Completed");

    Serial.println();
}

// Turn OFF all alerts
void clearAlerts()
{
    digitalWrite(GREEN_LED_PIN, LOW);

    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

#endif
