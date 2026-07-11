/*
  Project    : Bluetooth Sensor Dashboard (ESP32 BLE Simulation)
  Question   : Q32
  Name       : P Meet Kumar
  Roll No.   : IoT 009
  File       : BLE-Sensor-Dashboard.ino

  Description:
  This project simulates an ESP32 BLE Sensor Dashboard in Wokwi.
  Temperature, Humidity and Timestamp are updated every 3 seconds.
  BLE UUIDs are included for documentation purposes.
*/

#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// BLE UUIDs (Documentation Reference)

const char* SERVICE_UUID        = "12345678-1234-1234-1234-1234567890AB";
const char* TEMPERATURE_UUID    = "11111111-1111-1111-1111-111111111111";
const char* HUMIDITY_UUID       = "22222222-2222-2222-2222-222222222222";
const char* TIMESTAMP_UUID      = "33333333-3333-3333-3333-333333333333";

unsigned long previousMillis = 0;
const unsigned long interval = 3000;

// Initializes Serial Monitor and DHT sensor

void setup()
{
  Serial.begin(115200);

  dht.begin();

  Serial.println("==============================================");
  Serial.println(" ESP32 BLE Sensor Dashboard (Simulation)");
  Serial.println("==============================================");

  Serial.println("\nBLE Service UUID");
  Serial.println(SERVICE_UUID);

  Serial.println("\nBLE Characteristics");

  Serial.print("Temperature : ");
  Serial.println(TEMPERATURE_UUID);

  Serial.print("Humidity    : ");
  Serial.println(HUMIDITY_UUID);

  Serial.print("Timestamp   : ");
  Serial.println(TIMESTAMP_UUID);

  Serial.println("\nSimulation Started...");
  Serial.println("Sensor data updates every 3 seconds.");
}

// Reads sensor values every 3 seconds

void loop()
{
  if (millis() - previousMillis >= interval)
  {
    previousMillis = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
      Serial.println("\nSensor Read Failed!");
      return;
    }

    Serial.println("\n==============================================");

    Serial.print("Timestamp   : ");
    Serial.print(millis());
    Serial.println(" ms");

    Serial.print("Temperature : ");
    Serial.print(temperature, 1);
    Serial.println(" °C");

    Serial.print("Humidity    : ");
    Serial.print(humidity, 1);
    Serial.println(" %");

    Serial.println("----------------------------------------------");

    Serial.println("BLE Advertisement (Simulation)");

    Serial.print("Service UUID : ");
    Serial.println(SERVICE_UUID);

    Serial.print("Temperature Characteristic : ");
    Serial.println(TEMPERATURE_UUID);

    Serial.print("Humidity Characteristic    : ");
    Serial.println(HUMIDITY_UUID);

    Serial.print("Timestamp Characteristic   : ");
    Serial.println(TIMESTAMP_UUID);

    Serial.println("==============================================");
  }
}
