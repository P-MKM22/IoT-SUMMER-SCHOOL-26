#ifndef CONFIG_H
#define CONFIG_H

/*
Project: Smart Clinic System
Question: Q48
Author: P Meet Kumar
Roll Number: IoT 009

Description:
Stores hardware configuration, pin assignments,
system constants, and shared data structures.
*/

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED Display Configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// DHT22 Sensor Configuration
#define DHT_PIN 4
#define DHT_TYPE DHT22

// Heart Rate Potentiometer
#define HEART_RATE_PIN 34

// SpO₂ Potentiometer
#define SPO2_PIN 35

// Push Buttons
#define NEXT_BUTTON_PIN 18
#define EMERGENCY_BUTTON_PIN 19

// Status LEDs
#define GREEN_LED_PIN 26
#define RED_LED_PIN 27

// Buzzer
#define BUZZER_PIN 25

// Normal Health Thresholds
const float MIN_BODY_TEMP = 36.0;
const float MAX_BODY_TEMP = 37.5;

const int MIN_HEART_RATE = 60;
const int MAX_HEART_RATE = 100;

const int MIN_SPO2 = 95;

// Timing Configuration
const unsigned long SENSOR_INTERVAL = 1000;
const unsigned long DISPLAY_INTERVAL = 500;
const unsigned long CLOUD_INTERVAL = 5000;

// Patient Information
struct Patient
{
    String patientID;
    String patientName;
    uint8_t age;
    String gender;
};

// Health Parameters
struct HealthData
{
    float temperature;
    int heartRate;
    int spo2;
    String status;
};

// Appointment Information
struct Appointment
{
    String doctorName;
    String department;
    String appointmentTime;
    bool completed;
};

// Hardware Objects
extern Adafruit_SSD1306 display;
extern DHT dht;

#endif
