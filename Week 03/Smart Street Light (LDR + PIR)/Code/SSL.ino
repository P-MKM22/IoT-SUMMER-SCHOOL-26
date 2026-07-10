/*
Project: Smart Street Light (LDR + PIR)
Question: Q 23
Author: P Meet Kumar
Roll Number: IoT 009
Program: IoT and Drone Building Summer School 2026
Institution: Indian Institute of Technology Jammu (IIT Jammu)
Description:
This project controls a street light using an LDR and a PIR sensor. During daylight, the LED remains OFF. At night, the PIR sensor detects motion and turns the LED ON at full brightness for 30 seconds. If no motion is detected after 30 seconds, the LED automatically dims to 20% brightness using PWM. The program uses millis() for non-blocking timing and logs all major events to the Serial Monitor.
*/

const int LDR_PIN = A0;
const int PIR_PIN = 2;
const int LED_PIN = 9;

// Adjust if required in Wokwi
const int NIGHT_THRESHOLD = 300;
const int DAY_THRESHOLD   = 700;

const int FULL_BRIGHTNESS = 255;
const int DIM_BRIGHTNESS  = 51;      //20%

const unsigned long ON_TIME = 30000UL;

enum State {
  DAY_MODE,
  NIGHT_DIM,
  NIGHT_BRIGHT
};

State currentState = DAY_MODE;

unsigned long lastMotionTime = 0;

//------------------------------------------------------

void printTime() {

  unsigned long t = millis() / 1000;

  int hh = (t / 3600) % 24;
  int mm = (t % 3600) / 60;
  int ss = t % 60;

  Serial.print("[");

  if (hh < 10) Serial.print("0");
  Serial.print(hh);
  Serial.print(":");

  if (mm < 10) Serial.print("0");
  Serial.print(mm);
  Serial.print(":");

  if (ss < 10) Serial.print("0");
  Serial.print(ss);

  Serial.print("] ");
}

void logEvent(const char *msg) {

  printTime();
  Serial.print("EVENT: ");
  Serial.println(msg);
}

//------------------------------------------------------

void setup() {

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  analogWrite(LED_PIN, 0);

  Serial.begin(9600);

  logEvent("System Started");
}

//------------------------------------------------------

void loop() {

  int ldr = analogRead(LDR_PIN);

  bool isNight;

  // Hysteresis

  if (currentState == DAY_MODE)
    isNight = (ldr < NIGHT_THRESHOLD);
  else
    isNight = !(ldr > DAY_THRESHOLD);

  //---------------- DAY ----------------

  if (!isNight) {

    if (currentState != DAY_MODE) {

      currentState = DAY_MODE;

      analogWrite(LED_PIN, 0);

      logEvent("Daylight detected - Street light OFF");
    }

    return;
  }

  //---------------- NIGHT ----------------

  bool motion = digitalRead(PIR_PIN);

  // Motion detected

  if (motion) {

    lastMotionTime = millis();

    if (currentState != NIGHT_BRIGHT) {

      currentState = NIGHT_BRIGHT;

      analogWrite(LED_PIN, FULL_BRIGHTNESS);

      logEvent("Motion detected - LED ON (100%)");
    }
  }

  // No motion

  if (currentState == NIGHT_BRIGHT) {

    if (millis() - lastMotionTime >= ON_TIME) {

      currentState = NIGHT_DIM;

      analogWrite(LED_PIN, DIM_BRIGHTNESS);

      logEvent("No motion after 30 seconds - LED Dimmed (20%)");
    }
  }

  // First time entering night

  if (currentState == DAY_MODE && isNight) {

    currentState = NIGHT_DIM;

    analogWrite(LED_PIN, DIM_BRIGHTNESS);

    logEvent("Night detected - Motion detection enabled");
  }

  // Stay dim while waiting

  if (currentState == NIGHT_DIM) {

    analogWrite(LED_PIN, DIM_BRIGHTNESS);
  }
}
