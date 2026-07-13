#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls LEDs, buzzer, emergency alerts,
and system response during fire incidents.
*/

#include "Config.h"

// Initialize alert devices
void initializeAlerts()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);
    pinMode(TEST_BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Safe condition
void normalAlert()
{
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Warning condition
void warningAlert()
{
    digitalWrite(GREEN_LED_PIN, LOW);

    digitalWrite(RED_LED_PIN, HIGH);

    tone(BUZZER_PIN, 1200);

    delay(200);

    noTone(BUZZER_PIN);

    delay(200);
}

// High fire risk
void highAlert()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 1800);

        delay(250);

        digitalWrite(RED_LED_PIN, LOW);

        noTone(BUZZER_PIN);

        delay(250);
    }
}

// Critical fire emergency
void criticalAlert()
{
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 2500);

        delay(150);

        digitalWrite(RED_LED_PIN, LOW);

        noTone(BUZZER_PIN);

        delay(150);
    }
}

// Update alerts according to risk level
void updateAlerts()
{
    if (fireStatus.riskLevel == "SAFE")
    {
        normalAlert();
    }
    else if (fireStatus.riskLevel == "WARNING")
    {
        warningAlert();
    }
    else if (fireStatus.riskLevel == "HIGH")
    {
        highAlert();
    }
    else
    {
        criticalAlert();
    }
}

// Test alarm
void runAlarmTest()
{
    if (digitalRead(TEST_BUTTON_PIN) == HIGH)
    {
        return;
    }

    Serial.println();
    Serial.println("Running Alarm Test");

    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, HIGH);

    tone(BUZZER_PIN, 2000);

    delay(1000);

    noTone(BUZZER_PIN);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    Serial.println("Alarm Test Completed");
}

// Reset emergency
void resetEmergency()
{
    if (digitalRead(RESET_BUTTON_PIN) == HIGH)
    {
        return;
    }

    fireStatus.fireDetected = false;

    fireStatus.riskLevel = "SAFE";

    digitalWrite(GREEN_LED_PIN, HIGH);

    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);

    Serial.println();
    Serial.println("Emergency Reset Successful");
}

// Turn OFF every alert
void clearAlerts()
{
    digitalWrite(GREEN_LED_PIN, LOW);

    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

#endif
