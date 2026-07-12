#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores patient records and provides
functions for patient management.
*/

#include "Config.h"

// Patient database
Patient patients[] =
{
    {
        "P1001",
        "Rahul Sharma",
        32,
        "Male"
    },

    {
        "P1002",
        "Priya Verma",
        27,
        "Female"
    },

    {
        "P1003",
        "Amit Singh",
        41,
        "Male"
    },

    {
        "P1004",
        "Sneha Patel",
        36,
        "Female"
    },

    {
        "P1005",
        "Rohit Gupta",
        58,
        "Male"
    }
};

const uint8_t TOTAL_PATIENTS =
sizeof(patients) / sizeof(patients[0]);

// Find patient using Patient ID
Patient* findPatient(String patientID)
{
    for (uint8_t i = 0; i < TOTAL_PATIENTS; i++)
    {
        if (patients[i].patientID == patientID)
        {
            return &patients[i];
        }
    }

    return nullptr;
}

// Display patient information
void printPatient(Patient *patient)
{
    if (patient == nullptr)
    {
        Serial.println("Patient Not Found");
        return;
    }

    Serial.println();
    Serial.println("Patient Details");
    Serial.println("---------------------------");

    Serial.print("Patient ID : ");
    Serial.println(patient->patientID);

    Serial.print("Name       : ");
    Serial.println(patient->patientName);

    Serial.print("Age        : ");
    Serial.println(patient->age);

    Serial.print("Gender     : ");
    Serial.println(patient->gender);

    Serial.println();
}

// Register a new patient
void registerPatient(String id,
                     String name,
                     uint8_t age,
                     String gender)
{
    Serial.println();
    Serial.println("Patient Registration");

    Serial.print("Patient ID : ");
    Serial.println(id);

    Serial.print("Name       : ");
    Serial.println(name);

    Serial.print("Age        : ");
    Serial.println(age);

    Serial.print("Gender     : ");
    Serial.println(gender);

    Serial.println("Registration Successful");
    Serial.println();
}

// Check whether patient exists
bool patientExists(String patientID)
{
    return (findPatient(patientID) != nullptr);
}

#endif
