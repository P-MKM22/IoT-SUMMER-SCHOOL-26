#ifndef CONFIG_H
#define CONFIG_H

/*
Project: Intelligent Waste Management System
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Contains hardware configuration,
pin assignments, constants,
and shared data structures.
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
#define TRIGGER_PIN 5
#define ECHO_PIN 18

// Status LEDs
#define GREEN_LED_PIN 26
#define YELLOW_LED_PIN 27
#define RED_LED_PIN 14

// Buzzer
#define BUZZER_PIN 25

// Dustbin Dimensions (cm)
const float BIN_HEIGHT = 50.0;

// Waste Level Thresholds
const int LOW_LEVEL = 30;
const int MEDIUM_LEVEL = 70;
const int HIGH_LEVEL = 90;

// Update Intervals
const unsigned long SENSOR_INTERVAL = 1000;
const unsigned long DISPLAY_INTERVAL = 500;
const unsigned long CLOUD_INTERVAL = 5000;

// Waste Bin Status
struct WasteStatus
{
    float distance;
    float fillPercentage;

    bool isFull;

    String level;
    String status;

    unsigned long lastUpdate;
};

// System Statistics
struct WasteStatistics
{
    int totalReadings;

    int fullAlerts;

    float averageFillLevel;

    float maximumFillLevel;
};

// Hardware Objects
extern Adafruit_SSD1306 display;

// Global Variables
extern WasteStatus wasteStatus;
extern WasteStatistics wasteStatistics;

#endif
