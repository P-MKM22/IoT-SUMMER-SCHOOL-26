/*
------------------------------------------------------------
Project Name : LED Blink Speed Controller
Version      : 1.3
Author       : P Meet Kumar
Roll Number  : IoT 009
Program      : IoT and Drone Building
Date         : DD/MM/YYYY

Description:
This project demonstrates LED blinking using an Arduino Uno.
The blink speed is controlled using a potentiometer, while
the Serial Monitor displays the blink count, potentiometer
value, and delay time.

Platform     : Arduino Uno
Software     : Arduino IDE / Tinkercad
------------------------------------------------------------
*/

const int Pin = 9;
const int potPin = A0;

int blinkCount = 0;
int sensorValue = 0;
int blinkDelay = 0;

void setup() {

  pinMode(Pin, OUTPUT);

  Serial.begin(9600);
  Serial.println("LED Blink Speed Controller");
}

void loop() {

  sensorValue = analogRead(potPin);

  blinkDelay = map(sensorValue, 0, 1023, 100, 1000);

  digitalWrite(Pin, HIGH);
  delay(blinkDelay);

  digitalWrite(Pin, LOW);
  delay(blinkDelay);

  blinkCount++;

  Serial.print("Blink Count: ");
  Serial.print(blinkCount);

  Serial.print(" | Potentiometer: ");
  Serial.print(sensorValue);

  Serial.print(" | Delay: ");
  Serial.print(blinkDelay);
  Serial.println(" ms");
}
