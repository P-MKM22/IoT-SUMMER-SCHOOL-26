#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls LEDs and buzzer for system
notifications and alerts.
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
    digitalWrite(BUZZER_PIN, LOW);
}

// Successful authentication
void authenticationSuccessAlert()
{
    digitalWrite(GREEN_LED_PIN, HIGH);

    tone(BUZZER_PIN, 2000);
    delay(150);
    noTone(BUZZER_PIN);

    delay(500);

    digitalWrite(GREEN_LED_PIN, LOW);
}

// Failed authentication
void authenticationFailedAlert()
{
    digitalWrite(RED_LED_PIN, HIGH);

    for (int i = 0; i < 2; i++)
    {
        tone(BUZZER_PIN, 1000);
        delay(200);

        noTone(BUZZER_PIN);
        delay(200);
    }

    digitalWrite(RED_LED_PIN, LOW);
}

// Grocery distribution completed
void transactionCompleteAlert()
{
    digitalWrite(GREEN_LED_PIN, HIGH);

    tone(BUZZER_PIN, 2500);
    delay(300);

    noTone(BUZZER_PIN);

    digitalWrite(GREEN_LED_PIN, LOW);
}

// Low inventory warning
void lowStockAlert()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 800);
        delay(250);

        noTone(BUZZER_PIN);

        digitalWrite(RED_LED_PIN, LOW);
        delay(250);
    }
}

// System error alert
void systemErrorAlert()
{
    for (int i = 0; i < 5; i++)
    {
        digitalWrite(RED_LED_PIN, HIGH);

        tone(BUZZER_PIN, 500);
        delay(100);

        noTone(BUZZER_PIN);

        digitalWrite(RED_LED_PIN, LOW);
        delay(100);
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
