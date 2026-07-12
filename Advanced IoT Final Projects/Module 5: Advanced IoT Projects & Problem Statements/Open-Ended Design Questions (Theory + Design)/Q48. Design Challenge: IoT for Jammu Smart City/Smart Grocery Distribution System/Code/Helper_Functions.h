#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Provides helper functions used across
the Smart Grocery Distribution System.
*/

#include "Config.h"

// Print a section heading
void printHeading(String heading)
{
    Serial.println();
    Serial.println("====================================");
    Serial.println(heading);
    Serial.println("====================================");
}

// Print a separator line
void printSeparator()
{
    Serial.println("------------------------------------");
}

// Return current system uptime
String getSystemTime()
{
    unsigned long totalSeconds = millis() / 1000;

    unsigned int hours = totalSeconds / 3600;
    unsigned int minutes = (totalSeconds % 3600) / 60;
    unsigned int seconds = totalSeconds % 60;

    String time = "";

    if (hours < 10) time += "0";
    time += String(hours);
    time += ":";

    if (minutes < 10) time += "0";
    time += String(minutes);
    time += ":";

    if (seconds < 10) time += "0";
    time += String(seconds);

    return time;
}

// Print current system time
void printCurrentTime()
{
    Serial.print("System Time : ");
    Serial.println(getSystemTime());
}

// Display project information
void printProjectInfo()
{
    printHeading("SMART GROCERY DISTRIBUTION SYSTEM");

    Serial.println("Project      : IoT for Jammu Smart City");
    Serial.println("Controller   : ESP32 DevKit V1");
    Serial.println("Communication: Wi-Fi");
    Serial.println("Authentication: RFID");
    Serial.println("Inventory    : Load Cell + Ultrasonic");
    Serial.println("Cloud        : HTTP API");

    printSeparator();
}

// Check push button status
bool isButtonPressed()
{
    return digitalRead(BUTTON_PIN) == LOW;
}

// Wait until button is pressed
void waitForButtonPress()
{
    while (!isButtonPressed())
    {
        delay(20);
    }

    while (isButtonPressed())
    {
        delay(20);
    }
}

// Display system ready message
void systemReady()
{
    printHeading("SYSTEM READY");

    Serial.println("Waiting for Beneficiary...");
    Serial.println("Scan RFID Card to Continue");

    printSeparator();
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

#endif
