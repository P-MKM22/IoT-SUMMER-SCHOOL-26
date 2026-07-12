#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Measures grocery weight using the load cell,
monitors storage level, and manages inventory.
*/

#include "Config.h"

// Initialize the load cell
void initializeLoadCell()
{
    scale.begin(HX711_DT_PIN, HX711_SCK_PIN);

    scale.set_scale(CALIBRATION_FACTOR);

    scale.tare();

    Serial.println("Load Cell Initialized");
}

// Measure grocery weight
float readWeight()
{
    if (!scale.is_ready())
    {
        Serial.println("Load Cell Not Ready");
        return 0.0;
    }

    float weight = scale.get_units(10);

    if (weight < 0)
    {
        weight = 0;
    }

    return weight;
}

// Measure remaining stock using ultrasonic sensor
float readStockLevel()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);

    float distance = duration * 0.0343 / 2.0;

    return distance;
}

// Check inventory status
bool isLowStock(float stockLevel)
{
    if (stockLevel >= LOW_STOCK_LEVEL_CM)
    {
        return true;
    }

    return false;
}

// Display inventory information on Serial Monitor
void printInventory(float weight, float stockLevel)
{
    Serial.println();

    Serial.println("Inventory Details");
    Serial.println("-----------------------------");

    Serial.print("Measured Weight : ");
    Serial.print(weight, 2);
    Serial.println(" kg");

    Serial.print("Storage Level   : ");
    Serial.print(stockLevel, 1);
    Serial.println(" cm");

    if (isLowStock(stockLevel))
    {
        Serial.println("Status          : LOW STOCK");
    }
    else
    {
        Serial.println("Status          : SUFFICIENT");
    }

    Serial.println();
}

// Simulate grocery dispensing
void dispenseGrocery(float requiredWeight)
{
    Serial.println("Dispensing Grocery...");

    float currentWeight = readWeight();

    while (currentWeight < requiredWeight)
    {
        currentWeight = readWeight();

        Serial.print("Current Weight : ");
        Serial.print(currentWeight, 2);
        Serial.println(" kg");

        delay(300);
    }

    Serial.println("Required Quantity Dispensed");
}

#endif
