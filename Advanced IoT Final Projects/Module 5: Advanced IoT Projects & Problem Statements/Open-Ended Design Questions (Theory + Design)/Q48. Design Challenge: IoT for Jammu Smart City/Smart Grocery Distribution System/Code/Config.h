#ifndef CONFIG_H
#define CONFIG_H

/*
Project: Smart Grocery Distribution System
Question: Q48 - IoT for Jammu Smart City
Author: P Meet Kumar
Roll Number: IoT 009
Board: ESP32 DevKit V1
Programming Language: Arduino (C++)
IDE: Arduino IDE 2.x

Description:
Common hardware configuration, pin assignments,
system constants, and data structures used
throughout the project.
*/

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <MFRC522.h>
#include <HX711.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// RFID module pins
#define RFID_SS_PIN 5
#define RFID_RST_PIN 27

// HX711 Load Cell pins
#define HX711_DT_PIN 16
#define HX711_SCK_PIN 4

// Ultrasonic sensor pins
#define TRIG_PIN 18
#define ECHO_PIN 19

// Status LEDs
#define GREEN_LED_PIN 2
#define RED_LED_PIN 15

// Buzzer
#define BUZZER_PIN 13

// Push button
#define BUTTON_PIN 12

// Weight calibration
const float CALIBRATION_FACTOR = -7050.0;

// Inventory settings
const float STORAGE_HEIGHT_CM = 40.0;
const float LOW_STOCK_LEVEL_CM = 30.0;
const float CRITICAL_STOCK_LEVEL_CM = 35.0;

// Default grocery quantities (kg)
const float DEFAULT_RICE_WEIGHT = 5.0;
const float DEFAULT_WHEAT_WEIGHT = 5.0;
const float DEFAULT_SUGAR_WEIGHT = 1.0;

// Timing intervals (milliseconds)
const unsigned long DISPLAY_INTERVAL = 500;
const unsigned long SENSOR_INTERVAL = 1000;
const unsigned long CLOUD_INTERVAL = 5000;

// Transaction status
enum TransactionStatus
{
    AUTH_PENDING,
    AUTH_SUCCESS,
    AUTH_FAILED,
    DISTRIBUTION_STARTED,
    DISTRIBUTION_COMPLETED,
    LOW_STOCK,
    SYSTEM_ERROR
};

// Beneficiary information
struct Beneficiary
{
    String uid;
    String name;
    String rationCard;
    bool eligible;
};

// Inventory information
struct Inventory
{
    String itemName;
    float availableWeight;
    float minimumWeight;
    bool lowStock;
};

// Transaction details
struct Transaction
{
    String beneficiaryName;
    String rationCard;
    String groceryName;
    float quantity;
    String transactionTime;
    bool success;
};

// Hardware objects
extern Adafruit_SSD1306 display;
extern MFRC522 rfid;
extern HX711 scale;

#endif
