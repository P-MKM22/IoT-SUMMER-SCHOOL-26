#ifndef CONFIG_H
#define CONFIG_H

/*
Project: Smart Street Lighting System
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

// LDR Sensor
#define LDR_PIN 34

// PIR Motion Sensor
#define PIR_PIN 27

// Street Light LED
#define STREET_LIGHT_PIN 26

// Status LED
#define STATUS_LED_PIN 2

// Buzzer
#define BUZZER_PIN 25

// Light Threshold
const int LDR_THRESHOLD = 1800;

// Motion Timeout
const unsigned long LIGHT_TIMEOUT = 10000;

// Update Intervals
const unsigned long SENSOR_INTERVAL = 1000;
const unsigned long DISPLAY_INTERVAL = 500;
const unsigned long CLOUD_INTERVAL = 5000;

// Street Light Status
struct LightingStatus
{
    int lightLevel;
    bool isNight;
    bool motionDetected;
    bool streetLightON;
    unsigned long motionTime;
    String systemStatus;
};

// Energy Statistics
struct EnergyStatistics
{
    unsigned long totalOperatingTime;
    unsigned long energySavedTime;
    int motionEvents;
    float efficiency;
};

// Hardware Objects
extern Adafruit_SSD1306 display;

// Global Variables
extern LightingStatus lightingStatus;
extern EnergyStatistics energyStatistics;

#endif
