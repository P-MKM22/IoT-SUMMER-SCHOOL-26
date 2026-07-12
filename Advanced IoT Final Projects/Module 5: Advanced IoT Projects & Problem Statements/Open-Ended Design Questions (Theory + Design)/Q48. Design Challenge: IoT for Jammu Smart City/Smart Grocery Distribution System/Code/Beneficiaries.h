#ifndef BENEFICIARIES_H
#define BENEFICIARIES_H

/*
Project: Smart Grocery Distribution System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores beneficiary information and provides
functions for authentication.
*/

#include "config.h"

// Beneficiary database

Beneficiary beneficiaries[] =
{
    {
        "A1B2C3D4",
        "Rahul Sharma",
        "CGPDS1001",
        true
    },

    {
        "B5C6D7E8",
        "Priya Verma",
        "CGPDS1002",
        true
    },

    {
        "C9D0E1F2",
        "Amit Singh",
        "CGPDS1003",
        true
    },

    {
        "D3E4F5G6",
        "Sneha Patel",
        "CGPDS1004",
        true
    },

    {
        "E7F8G9H0",
        "Rohit Gupta",
        "CGPDS1005",
        false
    }
};

const uint8_t TOTAL_BENEFICIARIES =
sizeof(beneficiaries) / sizeof(beneficiaries[0]);

// Search beneficiary using RFID UID

Beneficiary* findBeneficiary(String uid)
{
    for (uint8_t i = 0; i < TOTAL_BENEFICIARIES; i++)
    {
        if (beneficiaries[i].uid == uid)
        {
            return &beneficiaries[i];
        }
    }

    return nullptr;
}

// Check eligibility

bool isEligible(Beneficiary *person)
{
    if (person == nullptr)
    {
        return false;
    }

    return person->eligible;
}

// Display beneficiary details on Serial Monitor

void printBeneficiary(Beneficiary *person)
{
    if (person == nullptr)
    {
        Serial.println("Beneficiary Not Found");
        return;
    }

    Serial.println();
    Serial.println("Beneficiary Details");
    Serial.println("----------------------------");

    Serial.print("Name          : ");
    Serial.println(person->name);

    Serial.print("Ration Card   : ");
    Serial.println(person->rationCard);

    Serial.print("Eligibility   : ");

    if (person->eligible)
    {
        Serial.println("Approved");
    }
    else
    {
        Serial.println("Rejected");
    }

    Serial.println();
}

#endif
