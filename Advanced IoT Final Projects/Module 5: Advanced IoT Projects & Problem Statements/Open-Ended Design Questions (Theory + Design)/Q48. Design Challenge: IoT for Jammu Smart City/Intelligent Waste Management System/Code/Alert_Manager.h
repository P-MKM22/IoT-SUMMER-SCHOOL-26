#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls status LEDs and buzzer
for waste level indication,
overflow warning, and maintenance alerts.
*/

#include "Config.h"

// Initialize Alert Devices
void initializeAlerts()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Low Waste Level
void lowLevelAlert()
{
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Medium Waste Level
void mediumLevelAlert()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// High Waste Level
void highLevelAlert()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    tone(BUZZER_PIN, 1800);

    delay(250);

    noTone(BUZZER_PIN);
}

// Overflow Alert
void overflowAlert()
{
    for(int i = 0; i < 3; i++)
    {
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 2200);

        delay(200);

        digitalWrite(RED_LED_PIN, LOW);

        noTone(BUZZER_PIN);

        delay(200);
    }
}

// Update Alert Status
void updateAlerts()
{
    if(wasteStatus.fillPercentage < LOW_LEVEL)
    {
        lowLevelAlert();
    }
    else if(wasteStatus.fillPercentage < MEDIUM_LEVEL)
    {
        mediumLevelAlert();
    }
    else
    {
        highLevelAlert();
    }

    if(isOverflowDetected())
    {
        overflowAlert();
    }
}

// Maintenance Alert
void maintenanceAlert()
{
    for(int i = 0; i < 2; i++)
    {
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(YELLOW_LED_PIN, HIGH);
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 1500);

        delay(300);

        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(RED_LED_PIN, LOW);

        noTone(BUZZER_PIN);

        delay(300);
    }
}

// Alert System Test
void runAlertTest()
{
    Serial.println();

    Serial.println("Running Alert Test");

    maintenanceAlert();

    Serial.println("Alert Test Completed");

    Serial.println();
}

// Clear Alerts
void clearAlerts()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Print Alert Status
void printAlertStatus()
{
    Serial.println();

    Serial.println("Alert Status");
    Serial.println("--------------------------------");

    Serial.print("Current Level : ");
    Serial.println(wasteStatus.level);

    Serial.print("Overflow : ");

    if(isOverflowDetected())
    {
        Serial.println("YES");
    }
    else
    {
        Serial.println("NO");
    }

    Serial.println();
}

#endif
