#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls LEDs, buzzer, and emergency
notifications based on the patient's
health condition.
*/

#include "Config.h"

// Initialize alert devices
void initializeAlerts()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(EMERGENCY_BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
}

// Normal health indication
void normalAlert()
{
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

// Warning indication
void warningAlert()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);

    tone(BUZZER_PIN, 1200);
    delay(200);

    noTone(BUZZER_PIN);
}

// Critical emergency indication
void criticalAlert()
{
    for (int i = 0; i < 5; i++)
    {
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 2000);
        delay(200);

        digitalWrite(RED_LED_PIN, LOW);

        noTone(BUZZER_PIN);
        delay(200);
    }
}

// Emergency button status
bool emergencyButtonPressed()
{
    return digitalRead(EMERGENCY_BUTTON_PIN) == LOW;
}

// Handle emergency request
void handleEmergency()
{
    if (!emergencyButtonPressed())
    {
        return;
    }

    Serial.println();
    Serial.println("***** EMERGENCY REQUEST *****");
    Serial.println("Calling Medical Staff...");
    Serial.println("Priority Level : HIGH");
    Serial.println();

    criticalAlert();
}

// Update alerts according to health status
void updateAlerts()
{
    if (isCritical())
    {
        criticalAlert();
    }
    else if (currentHealth.status == "Normal")
    {
        normalAlert();
    }
    else
    {
        warningAlert();
    }
}

// Turn off all alerts
void clearAlerts()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);

    noTone(BUZZER_PIN);
}

#endif
