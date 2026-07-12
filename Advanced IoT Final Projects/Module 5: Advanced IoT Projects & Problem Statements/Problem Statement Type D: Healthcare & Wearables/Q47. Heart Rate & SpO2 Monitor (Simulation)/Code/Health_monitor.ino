/*
Project: Smart Health Monitoring System
Question: Smart Health Monitoring System
Author: P Meet Kumar
Roll Number: IoT 009
Board: ESP32 Dev Module
Programming Language: Arduino (C++)
IDE: Arduino IDE 2.x

Description:
Monitors environmental temperature, simulated heart rate,
and fall detection using ESP32. Displays health information
on an OLED display and triggers visual and audible alerts
during emergency conditions.
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHTesp.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Create the OLED display object
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Create the DHT sensor object
DHTesp dht;

// Create the MPU6050 sensor object
Adafruit_MPU6050 mpu;

// Define the GPIO pin connected to the DHT sensor
const int DHT_PIN = 15;

// Define LED output pins
const int GREEN_LED = 26;
const int RED_LED = 27;

// Define the buzzer output pin
const int BUZZER_PIN = 18;

// Define the push button input pin
const int BUTTON_PIN = 4;

// Define the analog input pin for heart rate simulation
const int HEART_POT_PIN = 34;
const int SPO2_POT_PIN = 35;
// Store environmental readings
float temperature = 0.0;
float humidity = 0.0;

// Store the simulated heart rate
int heartRate = 0;
// Store the simulated SpO2 level
int SpO2 = 98;

// Indicates whether a fall has been detected
bool fallDetected = false;

// Indicates whether the alarm has been acknowledged
bool alarmMuted = false;

// Store the previous execution time for periodic updates
unsigned long previousMillis = 0;

// Update interval in milliseconds
const unsigned long sensorInterval = 2000;

// Health threshold values
const float MAX_TEMPERATURE = 38.0;
const int MAX_HEART_RATE = 100;

// Minimum acceptable SpO2 level
const int MIN_SPO2 = 95;

// Function declarations
void readSensors();
void detectFall();
void updateOLED();
void checkHealthStatus();
void resetAlarm();
void logSensorData();

void setup()
{
    Serial.begin(115200);

    // Initialize the DHT sensor
    dht.setup(DHT_PIN, DHTesp::DHT22);

    // Configure LED pins
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    // Configure buzzer pin
    pinMode(BUZZER_PIN, OUTPUT);

    // Configure push button with internal pull-up resistor
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Configure potentiometer input
    pinMode(HEART_POT_PIN, INPUT);
    pinMode(SPO2_POT_PIN, INPUT);

    // Set default output states
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    // Initialize the OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED initialization failed.");

        while (true);
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2);
    display.setCursor(8, 18);
    display.println("Health");
    display.println("Monitor");
    display.display();

    delay(2000);

    display.clearDisplay();
    display.display();

    // Initialize the MPU6050 sensor
    if (!mpu.begin())
    {
        Serial.println("MPU6050 not detected.");

        while (true);
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    Serial.println("Smart Health Monitoring System Started");
    Serial.println();
    Serial.println("Time(s),Temperature(C),HeartRate(BPM),SpO2(%),Fall,Status");
}
void loop()
{
    // Check if the alarm reset button is pressed
    if (digitalRead(BUTTON_PIN) == LOW)
    {
        resetAlarm();
    }

    // Execute sensor reading every 2 seconds
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= sensorInterval)
    {
        previousMillis = currentMillis;

        readSensors();

        detectFall();

        checkHealthStatus();

        updateOLED();

        logSensorData();
    }
}

// Read temperature, humidity, and simulated heart rate
void readSensors()
{
    TempAndHumidity data = dht.getTempAndHumidity();

    temperature = data.temperature;
    humidity = data.humidity;

   // Read heart rate potentiometer
    int heartPotValue = analogRead(HEART_POT_PIN);

   // Read SpO2 potentiometer
    int spo2PotValue = analogRead(SPO2_POT_PIN);

   // Simulate heart rate (60–120 BPM)
    heartRate = map(heartPotValue, 0, 4095, 60, 120);

   // Simulate SpO2 level (90–100%)
    SpO2 = map(spo2PotValue, 0, 4095, 90, 100);
}

// Detect a possible fall using accelerometer values
void detectFall()
{
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;

    mpu.getEvent(&accel, &gyro, &temp);

    float totalAcceleration =
        sqrt(
            accel.acceleration.x * accel.acceleration.x +
            accel.acceleration.y * accel.acceleration.y +
            accel.acceleration.z * accel.acceleration.z
        );

    // Detect sudden impact or abnormal movement
    if (totalAcceleration > 18.0)
    {
        fallDetected = true;
    }
}

// Reset alarm using the push button
void resetAlarm()
{
    alarmMuted = true;

    fallDetected = false;

    digitalWrite(RED_LED, LOW);

    digitalWrite(GREEN_LED, HIGH);

    digitalWrite(BUZZER_PIN, LOW);

    Serial.println();
    Serial.println("Emergency alarm acknowledged.");
}
// Evaluate health conditions and control LEDs and buzzer
void updateAlerts()
{
    bool emergency = false;
    bool warning = false;

    // Check for abnormal temperature
    if (temperature >= MAX_TEMPERATURE)
    {
        warning = true;
    }

    // Check for abnormal heart rate
    if (heartRate >= MAX_HEART_RATE)
    {
        warning = true;
    }

    // Check if a fall has been detected
    if (fallDetected)
    {
        emergency = true;
    }

    // Reset alarm acknowledgement once all conditions become normal
    if (!warning && !emergency)
    {
        alarmMuted = false;
    }

    // Emergency condition
    if (emergency)
    {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);

        if (!alarmMuted)
        {
            tone(BUZZER_PIN, 1000);
        }

        return;
    }

    // Warning condition
    if (warning)
    {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);

        if (!alarmMuted)
        {
            tone(BUZZER_PIN, 1500, 250);
        }

        return;
    }

    // Normal condition
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    noTone(BUZZER_PIN);
}

// Return the current health status
String getHealthStatus()
{
    if (fallDetected)
    {
        return "EMERGENCY";
    }

    if (temperature >= MAX_TEMPERATURE)
    {
        return "HIGH TEMP";
    }

    if (heartRate >= MAX_HEART_RATE)
    {
        return "HIGH BPM";
    }
    if (SpO2 < MIN_SPO2)
    {
    return "LOW SPO2";
    }

    return "NORMAL";
}
// Display health information on the OLED
void updateOLED()
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Display project title
    display.setCursor(0, 0);
    display.println("Smart Health Monitor");

    // Display temperature
    display.setCursor(0, 14);
    display.print("Temp : ");
    display.print(temperature, 1);
    display.println(" C");

    // Display heart rate
    display.setCursor(0, 26);
    display.print("Heart: ");
    display.print(heartRate);
    display.println(" BPM");

    // Display SpO2
    display.setCursor(0, 38);
    display.print("SpO2 : ");
    display.print(SpO2);
    display.println("%");

    // Display health status
    display.setCursor(0, 50);
    display.print("Status: ");

    String status = getHealthStatus();

    if (status == "NORMAL")
    {
        display.print("NORMAL");
    }
    else if (status == "HIGH TEMP")
    {
        display.print("TEMP HIGH");
    }
    else if (status == "HIGH BPM")
    {
        display.print("BPM HIGH");
    }
    else if (status == "LOW SPO2")
    {
        display.print("LOW SPO2");
    }
    else
    {
        display.print("FALL!");
    }

    display.display();
}

// Print sensor readings in CSV format
void logSensorData()
{
    Serial.print(millis() / 1000);

    Serial.print(",");

    Serial.print(temperature, 1);

    Serial.print(",");

    Serial.print(heartRate);
    Serial.print(",");
    Serial.print(SpO2);

    Serial.print(",");

    if (fallDetected)
    {
        Serial.print("YES");
    }
    else
    {
        Serial.print("NO");
    }

    Serial.print(",");

    Serial.println(getHealthStatus());
}
// Evaluate the health condition and update system outputs
void checkHealthStatus()
{
    bool highTemperature = temperature >= MAX_TEMPERATURE;
    bool highHeartRate = heartRate >= MAX_HEART_RATE;
    bool lowSpO2 = SpO2 < MIN_SPO2;

    // Restore normal operation when every parameter returns to normal
    if (highTemperature || highHeartRate || lowSpO2)
    {
        alarmMuted = false;
    }

    // Emergency condition has the highest priority
    if (fallDetected)
    {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);

        if (!alarmMuted)
        {
            tone(BUZZER_PIN, 2000);
        }

        return;
    }

    // Warning condition
    if (highTemperature || highHeartRate)
    {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);

        if (!alarmMuted)
        {
            tone(BUZZER_PIN, 1500, 300);
        }

        return;
    }

    // Normal condition
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    noTone(BUZZER_PIN);
}
