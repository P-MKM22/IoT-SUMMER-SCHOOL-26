/*
Project: Servo Motor Sweep
Question: Q 25
Name: P Meet Kumar
Roll No.: IoT 009
File: Servo_Control.ino

Description:
This project controls an SG90 servo motor using a potentiometer.
The potentiometer position (0–1023) is mapped to a servo angle
between 0° and 180°. The current angle is displayed on the
Serial Monitor. A push button performs one complete servo sweep
from 0° to 180° and back to 0° when pressed.
*/

#include <Servo.h>

// Pin Definitions
#define SERVO_PIN 9
#define POT_PIN A0
#define BUTTON_PIN 2

// Create Servo Object
Servo servoMotor;

// Variables
int previousAngle = -1;
bool buttonState = HIGH;
bool lastButtonState = HIGH;

// Setup Function
void setup() {

  Serial.begin(9600);

  servoMotor.attach(SERVO_PIN);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// Main Program
void loop() {

  // Read button state
  buttonState = digitalRead(BUTTON_PIN);

  // Perform one complete sweep when button is pressed
  if (lastButtonState == HIGH && buttonState == LOW) {

    for (int angle = 0; angle <= 180; angle++) {
      servoMotor.write(angle);
      delay(10);
    }

    for (int angle = 180; angle >= 0; angle--) {
      servoMotor.write(angle);
      delay(10);
    }
  }

  lastButtonState = buttonState;

    // Read potentiometer
  int potValue = analogRead(POT_PIN);

  // Map potentiometer value to servo angle
  int angle = map(potValue, 0, 1023, 0, 180);

  // Move servo
  servoMotor.write(angle);

  // Display values only when they change
  if (angle != previousAngle) {

    Serial.print("Potentiometer : ");
    Serial.print(potValue);

    Serial.print(" | Servo Angle : ");
    Serial.print(angle);
    Serial.println("°");

    previousAngle = angle;
  }

  delay(20);

}
