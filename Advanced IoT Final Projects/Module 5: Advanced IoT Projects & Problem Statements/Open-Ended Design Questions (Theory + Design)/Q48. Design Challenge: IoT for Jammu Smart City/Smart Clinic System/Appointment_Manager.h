#ifndef APPOINTMENT_MANAGER_H
#define APPOINTMENT_MANAGER_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Manages patient appointments, token generation,
doctor allocation, and queue information.
*/

#include "Config.h"

Appointment currentAppointment;

int tokenNumber = 100;

// Generate next token
int generateToken()
{
    tokenNumber++;

    return tokenNumber;
}

// Assign doctor based on department
void assignDoctor(String department)
{
    currentAppointment.department = department;

    if (department == "General")
    {
        currentAppointment.doctorName = "Dr. Anil Kumar";
    }
    else if (department == "Cardiology")
    {
        currentAppointment.doctorName = "Dr. Priya Sharma";
    }
    else if (department == "Orthopedic")
    {
        currentAppointment.doctorName = "Dr. Vivek Singh";
    }
    else if (department == "Pediatrics")
    {
        currentAppointment.doctorName = "Dr. Neha Gupta";
    }
    else
    {
        currentAppointment.doctorName = "Duty Medical Officer";
    }
}

// Schedule appointment
void scheduleAppointment(String department)
{
    assignDoctor(department);

    currentAppointment.appointmentTime =
    String(millis() / 1000) + " sec";

    currentAppointment.completed = false;

    Serial.println();
    Serial.println("Appointment Scheduled");
    Serial.println("-----------------------------");

    Serial.print("Token Number : ");
    Serial.println(generateToken());

    Serial.print("Department   : ");
    Serial.println(currentAppointment.department);

    Serial.print("Doctor       : ");
    Serial.println(currentAppointment.doctorName);

    Serial.print("Time         : ");
    Serial.println(currentAppointment.appointmentTime);

    Serial.println();
}

// Display appointment details
void printAppointment()
{
    Serial.println();
    Serial.println("Appointment Details");
    Serial.println("-----------------------------");

    Serial.print("Doctor       : ");
    Serial.println(currentAppointment.doctorName);

    Serial.print("Department   : ");
    Serial.println(currentAppointment.department);

    Serial.print("Time         : ");
    Serial.println(currentAppointment.appointmentTime);

    Serial.print("Status       : ");

    if (currentAppointment.completed)
    {
        Serial.println("Completed");
    }
    else
    {
        Serial.println("Pending");
    }

    Serial.println();
}

// Complete appointment
void completeAppointment()
{
    currentAppointment.completed = true;

    Serial.println("Appointment Completed");
}

// Reset appointment
void resetAppointment()
{
    currentAppointment.doctorName = "";
    currentAppointment.department = "";
    currentAppointment.appointmentTime = "";
    currentAppointment.completed = false;
}

#endif
