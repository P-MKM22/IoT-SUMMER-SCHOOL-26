/*
Project: Multi-Sensor Data Logger
Question: Q 24
Name: P Meet Kumar
Roll No.: IoT 009
File: Multi_Sensor_Data_Logger.ino

Description:
This project reads data simultaneously from a DHT11 sensor,
an LDR sensor, and an HC-SR04 ultrasonic sensor. Every
5 seconds, it logs temperature, humidity, light intensity,
and distance measurements in a structured format on the
Serial Monitor.
*/

#include <DHT.h>

// Pin Definitions
#define DHTPIN 7
#define DHTTYPE DHT22

#define LDR_PIN A0

#define TRIG_PIN 9
#define ECHO_PIN 10

// Create DHT Object
DHT dht(DHTPIN, DHTTYPE);

// Variables for millis() timing
unsigned long previousMillis = 0;
const unsigned long interval = 5000;

// Function to measure distance using HC-SR04
float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return (duration * 0.034) / 2.0;
}

// Arduino Setup
void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

// Main Program
void loop() {

  // Execute every 5 seconds
  if (millis() - previousMillis >= interval) {

    previousMillis = millis();

    // Read DHT11 Sensor
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Read LDR Sensor
    int ldrRaw = analogRead(LDR_PIN);

    // Convert LDR value into percentage
    int lightPercent = map(ldrRaw, 1023, 0, 0, 100);
    lightPercent = constrain(lightPercent, 0, 100);

    // Determine light condition
    String lightStatus;

    if (lightPercent >= 70) {
      lightStatus = "Bright";
    }
    else if (lightPercent >= 40) {
      lightStatus = "Normal";
    }
    else {
      lightStatus = "Dark";
    }

    // Read ultrasonic sensor
    float distance = getDistance();

    // Display structured sensor log
    Serial.println("=== SENSOR LOG ===");

    Serial.print("Time : ");
    Serial.print(millis());
    Serial.println(" ms");

    Serial.print("Temp : ");

    if (isnan(temperature))
      Serial.print("N/A");
    else
      Serial.print(temperature, 1);

    Serial.print(" C | Humidity: ");

    if (isnan(humidity))
      Serial.print("N/A");
    else
      Serial.print(humidity, 0);

    Serial.println("%");

    Serial.print("Light : ");
    Serial.print(lightPercent);
    Serial.print("% (");
    Serial.print(lightStatus);
    Serial.println(")");

    Serial.print("Distance : ");

    if (distance < 0) {
      Serial.println("Out of Range");
    }
    else {
      Serial.print(distance, 1);
      Serial.println(" cm");
    }

    Serial.println("==================");
    Serial.println();
  }
}
