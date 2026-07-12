#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Contains common utility functions used
throughout the Smart Clinic System.
*/

#include "Config.h"

// Display project information
void printProjectInfo()
{
    Serial.println();
    Serial.println("==========================================");
    Serial.println("      SMART CLINIC SYSTEM");
    Serial.println(" Government Smart Healthcare Solution");
    Serial.println("==========================================");
    Serial.println();
}

// Display system ready message
void systemReady()
{
    Serial.println("------------------------------------------");
    Serial.println("System Initialization Completed");
    Serial.println("Clinic is Ready for Patient Service");
    Serial.println("------------------------------------------");
    Serial.println();
}

// Print success message
void printSuccess(String message)
{
    Serial.print("[SUCCESS] ");
    Serial.println(message);
}

// Print error message
void printError(String message)
{
    Serial.print("[ERROR] ");
    Serial.println(message);
}

// Print warning message
void printWarning(String message)
{
    Serial.print("[WARNING] ");
    Serial.println(message);
}

// Wait for NEXT button
void waitForNextButton()
{
    Serial.println("Press NEXT Button to Continue...");

    while (digitalRead(NEXT_BUTTON_PIN) == HIGH)
    {
        delay(20);
    }

    delay(200);

    while (digitalRead(NEXT_BUTTON_PIN) == LOW)
    {
        delay(20);
    }

    delay(200);
}

// Print divider
void printDivider()
{
    Serial.println("------------------------------------------");
}

// Display current time
String getSystemTime()
{
    unsigned long seconds = millis() / 1000;

    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;

    char timeBuffer[12];

    sprintf(
        timeBuffer,
        "%02d:%02d:%02d",
        hours,
        minutes,
        secs
    );

    return String(timeBuffer);
}

// Display timestamp
void printTimeStamp()
{
    Serial.print("Time : ");
    Serial.println(getSystemTime());
}

// Reset patient data
void resetHealthData()
{
    currentHealth.temperature = 0.0;
    currentHealth.heartRate = 0;
    currentHealth.spo2 = 0;
    currentHealth.status = "Waiting";
}

// Show completion message
void showCompletionMessage()
{
    Serial.println();
    Serial.println("==========================================");
    Serial.println(" Patient Examination Completed");
    Serial.println(" Record Saved Successfully");
    Serial.println("==========================================");
    Serial.println();
}

// Restart clinic session
void resetClinic()
{
    resetHealthData();

    Serial.println("Preparing for Next Patient...");
    Serial.println();

    delay(1000);
}

#endif
