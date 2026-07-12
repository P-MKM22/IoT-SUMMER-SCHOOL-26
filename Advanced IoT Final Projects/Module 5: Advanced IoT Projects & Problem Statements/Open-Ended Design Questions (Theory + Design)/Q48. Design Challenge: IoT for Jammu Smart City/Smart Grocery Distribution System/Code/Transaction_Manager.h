#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Creates, stores, and displays grocery
distribution transactions.
*/

#include "Config.h"

Transaction currentTransaction;

// Create a new transaction
void createTransaction(Beneficiary *person, String grocery, float quantity)
{
    currentTransaction.beneficiaryName = person->name;
    currentTransaction.rationCard = person->rationCard;
    currentTransaction.groceryName = grocery;
    currentTransaction.quantity = quantity;

    currentTransaction.transactionTime = String(millis() / 1000) + " sec";

    currentTransaction.success = true;
}

// Print transaction details
void printTransaction()
{
    Serial.println();
    Serial.println("========== TRANSACTION ==========");

    Serial.print("Beneficiary : ");
    Serial.println(currentTransaction.beneficiaryName);

    Serial.print("Ration Card : ");
    Serial.println(currentTransaction.rationCard);

    Serial.print("Grocery     : ");
    Serial.println(currentTransaction.groceryName);

    Serial.print("Quantity    : ");
    Serial.print(currentTransaction.quantity, 2);
    Serial.println(" kg");

    Serial.print("Time        : ");
    Serial.println(currentTransaction.transactionTime);

    Serial.print("Status      : ");

    if (currentTransaction.success)
        Serial.println("SUCCESS");
    else
        Serial.println("FAILED");

    Serial.println("=================================");
    Serial.println();
}

// Save transaction
void saveTransaction()
{
    Serial.println("Saving Transaction...");

    delay(500);

    Serial.println("Transaction Saved Successfully.");
}

// Complete transaction
void completeTransaction(Beneficiary *person,
                         String grocery,
                         float quantity)
{
    createTransaction(person, grocery, quantity);

    printTransaction();

    saveTransaction();
}

// Reset transaction
void resetTransaction()
{
    currentTransaction.beneficiaryName = "";
    currentTransaction.rationCard = "";
    currentTransaction.groceryName = "";
    currentTransaction.quantity = 0.0;
    currentTransaction.transactionTime = "";
    currentTransaction.success = false;
}

#endif
