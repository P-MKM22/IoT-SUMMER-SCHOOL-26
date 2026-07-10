/*
Project: Environmental Monitoring Station
Question: Q21 - Environmental Monitoring Station (DHT11)
Author: P Meet Kumar
Roll Number: IoT 009
Program: IoT and Drone Building Summer School 2026
Institution: Indian Institute of Technology Jammu (IIT Jammu)
Programming Language: Arduino (C++)
IDE: Arduino IDE / Wokwi
Description:
Reads temperature and humidity every 2 seconds, displays the
readings in CSV format on the Serial Monitor, and controls
status LEDs based on environmental conditions.

Note:
Wokwi uses the DHT22 sensor for simulation. The assignment
requires DHT11. The implementation logic remains identical.
*/

#include <DHTesp.h>

// Pin Definitions
const int DHT_PIN = 15;
const int RED_LED_PIN = 18;
const int GREEN_LED_PIN = 19;

// Create DHT sensor object
DHTesp dht;

// Timestamp in seconds
unsigned long timestamp = 0;

void setup() {
  Serial.begin(115200);

  // Initialize DHT22 sensor
  dht.setup(DHT_PIN, DHTesp::DHT22);

  // Configure LED pins
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  // CSV Header with Units
  Serial.println("timestamp (s),temp_C (°C),temp_F (°F),humidity (%)");
}

void loop() {

  // Read temperature and humidity
  TempAndHumidity data = dht.getTempAndHumidity();

  float tempC = data.temperature;
  float humidity = data.humidity;

  // Validate sensor readings
  if (isnan(tempC) || isnan(humidity)) {
    Serial.println("Sensor reading failed.");
    delay(2000);
    return;
  }

  // Convert Celsius to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Print readings in CSV format
  Serial.print(timestamp);
  Serial.print(",");
  Serial.print(tempC, 2);
  Serial.print(",");
  Serial.print(tempF, 2);
  Serial.print(",");
  Serial.println(humidity, 2);

  // LED indication
  if (tempC > 35.0 || humidity > 80.0) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }

  // Increase timestamp by 2 seconds
  timestamp += 2;

  // Wait for 2 seconds
  delay(2000);
}
