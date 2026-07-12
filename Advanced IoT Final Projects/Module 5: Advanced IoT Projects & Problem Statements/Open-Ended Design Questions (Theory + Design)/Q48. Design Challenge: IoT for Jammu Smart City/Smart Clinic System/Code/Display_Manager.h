#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Manages all OLED display screens used
throughout the Smart Clinic System.
*/

#include "Config.h"

// Display startup screen
void showStartupScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(18, 10);
    display.println("SMART");

    display.setCursor(20, 32);
    display.println("CLINIC");

    display.setTextSize(1);

    display.setCursor(8, 55);
    display.println("Government Healthcare");

    display.display();

    delay(2500);
}

// Display waiting screen
void showWaitingScreen()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(15, 10);
    display.println("READY");

    display.setTextSize(1);

    display.setCursor(0, 36);
    display.println("Select Patient");

    display.setCursor(0, 50);
    display.println("Press NEXT Button");

    display.display();
}

// Display patient details
void showPatientDetails(Patient *patient)
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Patient Details");

    display.setCursor(0, 15);
    display.print("ID : ");
    display.println(patient->patientID);

    display.setCursor(0, 28);
    display.print("Name:");

    display.println(patient->patientName);

    display.setCursor(0, 41);
    display.print("Age : ");
    display.println(patient->age);

    display.setCursor(0, 54);
    display.print("Sex : ");
    display.println(patient->gender);

    display.display();
}

// Display health parameters
void showHealthData()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Health Monitor");

    display.setCursor(0, 14);
    display.print("Temp : ");
    display.print(currentHealth.temperature, 1);
    display.println(" C");

    display.setCursor(0, 26);
    display.print("Heart: ");
    display.print(currentHealth.heartRate);
    display.println(" BPM");

    display.setCursor(0, 38);
    display.print("SpO2 : ");
    display.print(currentHealth.spo2);
    display.println("%");

    display.setCursor(0, 52);
    display.print("Status: ");
    display.println(currentHealth.status);

    display.display();
}

// Display appointment details
void showAppointment(Appointment appointment)
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("Appointment");

    display.setCursor(0, 18);
    display.print("Doctor:");

    display.println(appointment.doctorName);

    display.setCursor(0, 34);
    display.print("Dept:");

    display.println(appointment.department);

    display.setCursor(0, 50);
    display.print("Time:");

    display.println(appointment.appointmentTime);

    display.display();
}

// Display emergency alert
void showEmergencyAlert()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(5, 8);
    display.println("MEDICAL");

    display.setCursor(20, 34);
    display.println("ALERT");

    display.display();
}

// Display cloud synchronization
void showCloudSync()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0, 18);
    display.println("Uploading Data...");

    display.setCursor(0, 38);
    display.println("Cloud Sync Active");

    display.display();
}

// Display system error
void showSystemError()
{
    display.clearDisplay();

    display.setTextSize(2);

    display.setCursor(10, 18);
    display.println("ERROR");

    display.setTextSize(1);

    display.setCursor(0, 50);
    display.println("Restart Required");

    display.display();
}

#endif
