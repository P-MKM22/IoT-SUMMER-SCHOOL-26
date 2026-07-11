/*
  Project    : Relay-Controlled AC Device Simulation
  Question   : Q 27
  Name       : P Meet Kumar
  Roll No.   : IoT 009
  File       : Relay_Controlled_AC_Device.ino

  Description:
  Relay-controlled AC simulation using a DHT22 sensor (used in
  Wokwi instead of DHT11). The relay turns ON above 32°C and
  OFF below 28°C with hysteresis. A push button enables Manual
  Override mode and allows manual relay control.
*/

#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22

#define RELAY_PIN 8
#define LED_PIN 9
#define BUTTON_PIN 2

DHT dht(DHTPIN, DHTTYPE);

bool relayState = false;
bool manualMode = false;

bool lastButtonState = HIGH;

unsigned long lastDebounce = 0;
const unsigned long debounceDelay = 200;

//------------------------------------------------------------

void updateOutputs()
{
  digitalWrite(RELAY_PIN, relayState);
  digitalWrite(LED_PIN, relayState);
}

//------------------------------------------------------------

void printStatus(float temperature)
{
  Serial.println("--------------------------------");

  Serial.print("Temperature : ");
  Serial.print(temperature, 1);
  Serial.println(" °C");

  Serial.print("Relay State : ");
  Serial.println(relayState ? "ON" : "OFF");

  Serial.print("AC Status   : ");
  Serial.println(relayState ? "ON" : "OFF");

  Serial.print("Mode        : ");
  Serial.println(manualMode ? "Manual Override" : "Automatic");

  Serial.println("--------------------------------");
  Serial.println();
}

//------------------------------------------------------------

void setup()
{
  Serial.begin(9600);

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  updateOutputs();

  Serial.println("Relay-Controlled AC Device Simulation");
  Serial.println();
}

//------------------------------------------------------------

void loop()
{
  float temperature = dht.readTemperature();

  if (isnan(temperature))
  {
    Serial.println("DHT Error");
    delay(1000);
    return;
  }

  bool buttonState = digitalRead(BUTTON_PIN);

  // Button Press
  if (buttonState == LOW &&
      lastButtonState == HIGH &&
      millis() - lastDebounce > debounceDelay)
  {
    lastDebounce = millis();

    // Toggle Manual Mode
    manualMode = !manualMode;

    // When entering Manual Mode,
    // also toggle relay immediately.
    if (manualMode)
    {
      relayState = !relayState;
    }

    printStatus(temperature);
  }

  lastButtonState = buttonState;

  // Automatic Mode
  if (!manualMode)
  {
    static bool previousRelay = relayState;

    if (temperature > 32.0)
      relayState = true;
    else if (temperature < 28.0)
      relayState = false;

    if (relayState != previousRelay)
    {
      printStatus(temperature);
      previousRelay = relayState;
    }
  }

  updateOutputs();

  delay(100);
}
