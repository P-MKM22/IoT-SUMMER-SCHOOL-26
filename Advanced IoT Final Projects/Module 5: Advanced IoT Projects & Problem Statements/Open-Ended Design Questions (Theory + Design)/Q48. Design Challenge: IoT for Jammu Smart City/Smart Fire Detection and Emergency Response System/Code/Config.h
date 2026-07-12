#ifndef CONFIG_H
#define CONFIG_H

/*
Project: Smart Fire Detection and Emergency Response System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores hardware configuration,
pin assignments, system constants,
and shared data structures.
*/

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED Configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// DHT22 Configuration
#define DHT_PIN 4
#define DHT_TYPE DHT22

// Flame Sensor
#define FLAME_SENSOR_PIN 34

// MQ-2 Gas Sensor
#define GAS_SENSOR_PIN 35

// Push Buttons
#define RESET_BUTTON_PIN 18
#define TEST_BUTTON_PIN 19

// Status LEDs
#define GREEN_LED_PIN 26
#define RED_LED_PIN 27

// Buzzer
#define BUZZER_PIN 25

// Fire Thresholds
const float MAX_SAFE_TEMP = 50.0;
const int MAX_SAFE_GAS = 2500;
const int FLAME_DETECTED = LOW;

// Sensor Reading Interval
const unsigned long SENSOR_INTERVAL = 1000;

// OLED Refresh Interval
const unsigned long DISPLAY_INTERVAL = 500;

// Cloud Upload Interval
const unsigned long CLOUD_INTERVAL = 5000;

// Fire Status
struct FireStatus
{
    float temperature;
    int gasLevel;
    bool flameDetected;
    String riskLevel;
    bool fireDetected;
};

// Incident Information
struct Incident
{
    String incidentID;
    String location;
    String dateTime;
    String responseStatus;
};

// Hardware Objects
extern Adafruit_SSD1306 display;
extern DHT dht;

#endif
