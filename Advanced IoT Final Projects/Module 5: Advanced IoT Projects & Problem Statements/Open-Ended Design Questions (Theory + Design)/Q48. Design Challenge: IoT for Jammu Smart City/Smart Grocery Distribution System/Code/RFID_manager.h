#ifndef RFID_MANAGER_H
#define RFID_MANAGER_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Initializes the RFID reader, reads RFID cards,
and authenticates beneficiaries.
*/

#include "config.h"
#include "beneficiaries.h"

// Initialize RFID module
void initializeRFID()
{
    SPI.begin();
    rfid.PCD_Init();

    Serial.println("RFID Reader Initialized");
}

// Read RFID card UID
String readRFIDCard()
{
    if (!rfid.PICC_IsNewCardPresent())
    {
        return "";
    }

    if (!rfid.PICC_ReadCardSerial())
    {
        return "";
    }

    String uid = "";

    for (byte i = 0; i < rfid.uid.size; i++)
    {
        if (rfid.uid.uidByte[i] < 0x10)
        {
            uid += "0";
        }

        uid += String(rfid.uid.uidByte[i], HEX);
    }

    uid.toUpperCase();

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    return uid;
}

// Authenticate beneficiary
Beneficiary* authenticateBeneficiary()
{
    String uid = readRFIDCard();

    if (uid == "")
    {
        return nullptr;
    }

    Serial.println();
    Serial.println("RFID Card Detected");
    Serial.print("UID : ");
    Serial.println(uid);

    Beneficiary *person = findBeneficiary(uid);

    if (person == nullptr)
    {
        Serial.println("Authentication Failed");
        return nullptr;
    }

    if (!isEligible(person))
    {
        Serial.println("Beneficiary Not Eligible");
        return nullptr;
    }

    Serial.println("Authentication Successful");

    return person;
}

// Wait for a valid card
Beneficiary* waitForCard()
{
    Beneficiary *person = nullptr;

    while (person == nullptr)
    {
        person = authenticateBeneficiary();
        delay(200);
    }

    return person;
}

#endif
