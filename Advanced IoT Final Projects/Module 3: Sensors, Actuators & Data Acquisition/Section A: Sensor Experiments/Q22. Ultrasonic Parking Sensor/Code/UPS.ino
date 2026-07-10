/*
Project: Ultrasonic Parking Sensor
Question: Q22
Author: P Meet Kumar
Roll Number: IoT 009
Program: IoT and Drone Building Summer School 2026
Institution: IIT Jammu

Description:
Parking distance alert system using HC-SR04.
Uses millis() for non-blocking timing.
*/

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 5;
const int yellowLED = 6;
const int redLED = 7;
const int buzzer = 8;

unsigned long previousMillis = 0;
bool blinkState = false;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // ---------------- SAFE ----------------
  if (distance > 50) {

    Serial.println("SAFE");

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;
      blinkState = !blinkState;

      digitalWrite(greenLED, blinkState);
    }

    noTone(buzzer);
  }

  // ------------- WARNING ----------------
  else if (distance > 20) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;
      blinkState = !blinkState;

      if (blinkState)
        tone(buzzer, 1000);
      else
        noTone(buzzer);
    }
  }

  // -------------- DANGER ----------------
  else if (distance > 10) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    if (currentMillis - previousMillis >= 200) {

      previousMillis = currentMillis;
      blinkState = !blinkState;

      if (blinkState)
        tone(buzzer, 1500);
      else
        noTone(buzzer);
    }
  }

  // ------------ VERY CLOSE --------------
  else {

    digitalWrite(greenLED, LOW);

    tone(buzzer, 2000);

    if (currentMillis - previousMillis >= 100) {

      previousMillis = currentMillis;
      blinkState = !blinkState;

      digitalWrite(yellowLED, blinkState);
      digitalWrite(redLED, blinkState);
    }
  }
}

// Measure distance using HC-SR04
float getDistance() {

  long duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
    return 400;

  float distance = (duration * 0.034) / 2.0;

  return distance;
}
