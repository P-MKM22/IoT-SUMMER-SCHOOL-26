#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Controls all OLED display screens used in
the Smart Grocery Distribution System.
*/

#include "config.h"

// Display startup screen
void showStartupScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(12, 8);
    display.println("SMART");

    display.setCursor(5, 30);
    display.println("GROCERY");

    display.setTextSize(1);
    display.setCursor(18, 55);
    display.println("Distribution System");

    display.display();

    delay(2500);
}

// Waiting for RFID card
void showWaitingScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(8, 8);
    display.println("READY");

    display.setTextSize(1);

    display.setCursor(0, 34);
    display.println("Scan your RFID Card");

    display.setCursor(0, 50);
    display.println("Waiting...");

    display.display();
}

// Authentication successful
void showAuthenticationSuccess(Beneficiary *person)
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Authentication");

    display.setCursor(0, 12);
    display.println("Successful");

    display.setCursor(0, 30);
    display.print("Name:");

    display.setCursor(40, 30);
    display.println(person->name);

    display.setCursor(0, 46);
    display.print("Card:");

    display.setCursor(40, 46);
    display.println(person->rationCard);

    display.display();
}

// Authentication failed
void showAuthenticationFailed()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(0, 10);
    display.println("ACCESS");

    display.setCursor(12, 34);
    display.println("DENIED");

    display.display();
}

// Distribution screen
void showDistribution(float weight)
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Distribution");

    display.setCursor(0, 22);
    display.print("Weight : ");

    display.print(weight, 2);
    display.println(" kg");

    display.setCursor(0, 46);
    display.println("Please Collect");

    display.display();
}

// Transaction completed
void showTransactionComplete()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(10, 12);
    display.println("SUCCESS");

    display.setTextSize(1);

    display.setCursor(0, 48);
    display.println("Transaction Saved");

    display.display();
}

// Low inventory warning
void showLowStock()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(0, 10);
    display.println("LOW");

    display.setCursor(0, 34);
    display.println("STOCK");

    display.display();
}

// System error
void showSystemError()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(0, 12);
    display.println("SYSTEM");

    display.setCursor(20, 36);
    display.println("ERROR");

    display.display();
}

#endif
