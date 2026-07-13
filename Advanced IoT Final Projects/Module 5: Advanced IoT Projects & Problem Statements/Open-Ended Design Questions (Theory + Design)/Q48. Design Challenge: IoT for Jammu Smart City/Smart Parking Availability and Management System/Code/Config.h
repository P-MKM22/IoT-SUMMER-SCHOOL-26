#ifndef CONFIG_H
#define CONFIG_H

/*
Project: Smart Parking Availability and Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Contains hardware configuration,
pin assignments, constants, and
shared data structures.
*/

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Ultrasonic Sensor Pins
#define TRIG_PIN 5
#define ECHO_PIN 18

// Status LEDs
#define GREEN_LED_PIN 26
#define RED_LED_PIN 27

// Buzzer
#define BUZZER_PIN 25

// Simulation Button
#define VEHICLE_BUTTON_PIN 19

// Parking Parameters
const float SLOT_DISTANCE = 15.0;

// Update Intervals
const unsigned long SENSOR_INTERVAL = 1000;
const unsigned long DISPLAY_INTERVAL = 500;
const unsigned long CLOUD_INTERVAL = 5000;

// Parking Information
struct ParkingStatus
{
    float distance;
    bool occupied;
    String slotStatus;
    unsigned long occupiedTime;
};

// Parking Statistics
struct ParkingStatistics
{
    int totalVehicles;
    int availableSlots;
    int occupiedSlots;
    float occupancyPercentage;
};

// Hardware Objects
extern Adafruit_SSD1306 display;

// Global Variables
extern ParkingStatus parkingStatus;
extern ParkingStatistics parkingStatistics;

#endif
