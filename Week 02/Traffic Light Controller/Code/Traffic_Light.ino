/*
------------------------------------------------------------
Project     : Traffic Light Controller
File Name   : traffic_light.ino

Author      : P Meet Kumar
Roll Number : IoT 009
Date        : 09 July 2026

Program     : IoT and Drone Building Summer School 2026
Institution : Indian Institute of Technology Jammu (IIT Jammu)

Description :
This program simulates a traffic light system using
three LEDs and a pedestrian crossing button.

Normal Sequence:
RED (5s) → YELLOW (2s) → GREEN (4s)

When the pedestrian button is pressed, the traffic
signal immediately switches to RED for 8 seconds
before returning to the normal sequence.

The current traffic light state along with the
timestamp (millis()) is displayed on the Serial Monitor.
------------------------------------------------------------
*/

const int RED_LED = 2;
const int YELLOW_LED = 3;
const int GREEN_LED = 4;

const int BUTTON = 7;

void setup() {

  // Configure LED pins as outputs
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Configure pedestrian button as input
  pinMode(BUTTON, INPUT);

  Serial.begin(115200);

  Serial.println("Traffic Light Controller Started");
}

void loop() {

  // Check if pedestrian requests road crossing
  if (digitalRead(BUTTON) == HIGH) {

    pedestrianCrossing();
    return;
  }

  // RED signal
  setLights(HIGH, LOW, LOW);

  Serial.print("[");
  Serial.print(millis());
  Serial.println(" ms] RED");

  if (waitWithButtonCheck(5000))
    return;

  // YELLOW signal
  setLights(LOW, HIGH, LOW);

  Serial.print("[");
  Serial.print(millis());
  Serial.println(" ms] YELLOW");

  if (waitWithButtonCheck(2000))
    return;

  // GREEN signal
  setLights(LOW, LOW, HIGH);

  Serial.print("[");
  Serial.print(millis());
  Serial.println(" ms] GREEN");

  if (waitWithButtonCheck(4000))
    return;
}

// Controls the ON/OFF state of all traffic lights
void setLights(bool red, bool yellow, bool green) {

  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);
}

// Handles pedestrian crossing request
void pedestrianCrossing() {

  setLights(HIGH, LOW, LOW);

  Serial.print("[");
  Serial.print(millis());
  Serial.println(" ms] Pedestrian Request -> RED (8 sec)");

  // Hold RED signal for pedestrians
  delay(8000);

  Serial.println("Returning to Normal Traffic Cycle");
}

// Waits for the specified duration while continuously
// monitoring the pedestrian button
bool waitWithButtonCheck(unsigned long duration) {

  unsigned long startTime = millis();

  while (millis() - startTime < duration) {

    // Interrupt normal sequence if button is pressed
    if (digitalRead(BUTTON) == HIGH) {

      pedestrianCrossing();
      return true;
    }
  }

  return false;
}
