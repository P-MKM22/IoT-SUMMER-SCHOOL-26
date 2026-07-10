/*
Project: Ultrasonic Parking Sensor
Question: Q22 - Ultrasonic Parking Sensor
Author: P Meet Kumar
Roll Number: IoT 009
Program: IoT and Drone Building Summer School 2026
Institution: Indian Institute of Technology Jammu (IIT Jammu)

Hardware:
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Yellow LED
- Red LED
- Active Buzzer

Description:
Measures parking distance using the HC-SR04 sensor and provides
visual and audible alerts based on the detected distance.
Uses millis() for non-blocking timing.
*/

const int trigPin = 9;
const int echoPin = 10;

const int yellowLED = 6;
const int redLED = 7;
const int buzzer = 8;

unsigned long previousMillis = 0;
bool outputState = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {

  // Measure distance
  float distance = getDistance();

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // SAFE ZONE
  if (distance > 50) {

    Serial.println("SAFE");

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

  }

  // WARNING ZONE
  else if (distance > 20 && distance <= 50) {

    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      outputState = !outputState;
      digitalWrite(buzzer, outputState);
    }

  }

  // DANGER ZONE
  else if (distance > 10 && distance <= 20) {

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    if (currentMillis - previousMillis >= 200) {
      previousMillis = currentMillis;
      outputState = !outputState;
      digitalWrite(buzzer, outputState);
    }

  }

  // STOP IMMEDIATELY
  else {

    digitalWrite(buzzer, HIGH);

    if (currentMillis - previousMillis >= 100) {
      previousMillis = currentMillis;
      outputState = !outputState;

      digitalWrite(yellowLED, outputState);
      digitalWrite(redLED, outputState);
    }

  }
}

// Function to measure distance using HC-SR04
float getDistance() {

  long duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // Distance calculation
  float distance = (duration * 0.034) / 2.0;

  return distance;
}
