/*
------------------------------------------------------------
Project      : Smart Door Lock with OTP
File Name    : DoorLockOTP.ino

Author       : P Meet Kumar
Roll Number  : IoT 009
Date         : 09 July 2026

Program      : IoT and Drone Building Summer School 2026
Institution  : Indian Institute of Technology Jammu (IIT Jammu)

Description:
A Smart Door Lock System using ESP32, 4x4 Keypad, 16x2 I2C LCD,
Servo Motor, and Bluetooth communication.

Workflow:
1. Enter a 4-digit Student ID.
2. Generate a random 6-digit OTP.
3. Send the OTP via Bluetooth (or Serial Monitor in Wokwi).
4. Enter the OTP within 30 seconds.
5. Unlock the door for 3 seconds if the OTP is correct.
6. Log every access attempt to the Serial Monitor.

Features:
• 4x4 Matrix Keypad
• 16x2 I2C LCD
• ESP32 / HC-05 Bluetooth Support
• Servo Motor Door Lock
• Non-blocking timing using millis()
• Serial Monitor Logging
------------------------------------------------------------
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ESP32Servo.h>

// Uncomment ONLY when using a real ESP32 Bluetooth
// #include <BluetoothSerial.h>
// BluetoothSerial SerialBT;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo doorServo;

#define SERVO_PIN 18

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// System States
enum SystemState {
  WAIT_FOR_ID,
  WAIT_FOR_OTP,
  DOOR_UNLOCKED,
  RESETTING
};

SystemState currentState = WAIT_FOR_ID;

// Global Variables
String studentID = "";
String generatedOTP = "";
String enteredOTP = "";

bool otpGenerated = false;

unsigned long otpStartTime = 0;
unsigned long unlockStartTime = 0;
unsigned long resetStartTime = 0;

const unsigned long OTP_TIMEOUT = 30000;
const unsigned long UNLOCK_DURATION = 3000;
const unsigned long RESET_DURATION = 1500;

// Function Prototypes
void displayHomeScreen();
void processStudentID(char key);
void processOTP(char key);
String generateOTP();
void unlockDoor();
void lockDoor();
void updateTimers();
void resetSystem(bool success);

void setup() {

  Serial.begin(115200);

  // Uncomment for real ESP32 Bluetooth
  // SerialBT.begin("SmartDoorLock");

  randomSeed(micros());

  doorServo.attach(SERVO_PIN);
  doorServo.write(0);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Smart Door Lock");

  lcd.setCursor(0,1);
  lcd.print("Initializing");

  delay(1500);

  displayHomeScreen();

  Serial.println("==================================");
  Serial.println(" SMART DOOR LOCK WITH OTP");
  Serial.println("==================================");
  Serial.println("System Ready");
  Serial.println("Waiting for Student ID...");
  Serial.println("==================================");
}

// Display default screen
void displayHomeScreen() {

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Enter 4-Digit ID");

  lcd.setCursor(0,1);
}

// Generate a random 6-digit OTP
String generateOTP() {

  String otp = "";

  for(int i = 0; i < 6; i++) {
    otp += char(random(0,10) + '0');
  }

  return otp;
}
void loop() {

  updateTimers();

  char key = keypad.getKey();

  switch (currentState) {

    case WAIT_FOR_ID:

      if (key) {
        processStudentID(key);
      }

      break;

    case WAIT_FOR_OTP:

      if (key) {
        processOTP(key);
      }

      break;

    case DOOR_UNLOCKED:
      // Timer handled by updateTimers()
      break;

    case RESETTING:
      // Reset handled by updateTimers()
      break;
  }
}

// Process Student ID
void processStudentID(char key) {

  if (key == '*') {

    studentID = "";

    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);

    return;
  }

  if (key < '0' || key > '9')
    return;

  if (studentID.length() >= 4)
    return;

  studentID += key;

  lcd.print("*");
  Serial.print("*");

  if (studentID.length() == 4) {

    generatedOTP = generateOTP();

    otpGenerated = true;
    otpStartTime = millis();

    Serial.println();
    Serial.println("--------------------------------");
    Serial.println("Student ID : " + studentID);
    Serial.println("Generated OTP : " + generatedOTP);

    // Uncomment for real ESP32 Bluetooth

    /*
    SerialBT.println("===== SMART DOOR LOCK =====");
    SerialBT.println("Student ID : " + studentID);
    SerialBT.println("OTP : " + generatedOTP);
    SerialBT.println("Valid for 30 Seconds");
    SerialBT.println("===========================");
    */

    // Wokwi Simulation
    Serial.println("OTP sent successfully.");

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("OTP Generated");

    lcd.setCursor(0,1);
    lcd.print("Enter OTP");

    enteredOTP = "";

    currentState = WAIT_FOR_OTP;
  }
}

// Process OTP
void processOTP(char key) {

  if (key == '*') {

    enteredOTP = "";

    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);

    return;
  }

  if (key < '0' || key > '9')
    return;

  if (enteredOTP.length() >= 6)
    return;

  enteredOTP += key;

  lcd.print("*");
  Serial.print("*");

  if (enteredOTP.length() == 6) {

    Serial.println();
    Serial.println("Entered OTP : " + enteredOTP);

    if (enteredOTP == generatedOTP) {

      unlockDoor();
    }

    else {

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ACCESS DENIED");

      lcd.setCursor(0,1);
      lcd.print("Wrong OTP");

      Serial.println("--------------------------------");
      Serial.println("ACCESS DENIED");
      Serial.println("Reason : Invalid OTP");
      Serial.println("--------------------------------");

      resetSystem(false);
    }
  }
}
// Unlock the door
void unlockDoor() {

  doorServo.write(90);

  unlockStartTime = millis();

  currentState = DOOR_UNLOCKED;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ACCESS GRANTED");

  lcd.setCursor(0, 1);
  lcd.print("Door Unlocked");

  Serial.println("--------------------------------");
  Serial.println("ACCESS GRANTED");
  Serial.println("Door Unlocked");
  Serial.println("--------------------------------");
}

// Lock the door
void lockDoor() {

  doorServo.write(0);

  Serial.println("Door Locked");

  resetSystem(true);
}

// Update all millis() based timers
void updateTimers() {

  // OTP Countdown Timer
  if (currentState == WAIT_FOR_OTP) {

    unsigned long elapsed = millis() - otpStartTime;
    unsigned long remaining = (OTP_TIMEOUT - elapsed) / 1000;

    lcd.setCursor(11, 0);

    if (remaining < 10)
      lcd.print("0");

    lcd.print(remaining);
    lcd.print("s");

    if (elapsed >= OTP_TIMEOUT) {

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("OTP EXPIRED");

      lcd.setCursor(0, 1);
      lcd.print("Access Denied");

      Serial.println("--------------------------------");
      Serial.println("ACCESS DENIED");
      Serial.println("Reason : OTP Expired");
      Serial.println("--------------------------------");

      resetSystem(false);
    }
  }

  // Door remains unlocked for 3 seconds
  if (currentState == DOOR_UNLOCKED) {

    if (millis() - unlockStartTime >= UNLOCK_DURATION) {

      lockDoor();
    }
  }

  // Reset after displaying status
  if (currentState == RESETTING) {

    if (millis() - resetStartTime >= RESET_DURATION) {

      studentID = "";
      generatedOTP = "";
      enteredOTP = "";

      otpGenerated = false;

      displayHomeScreen();

      currentState = WAIT_FOR_ID;

      Serial.println("Waiting for Student ID...");
      Serial.println("--------------------------------");
    }
  }
}
// Reset the system
void resetSystem(bool success) {

  Serial.println("--------------------------------");

  if (success)
    Serial.println("LOG : SUCCESS ENTRY");
  else
    Serial.println("LOG : FAILED ENTRY");

  Serial.println("--------------------------------");
  Serial.println();

  resetStartTime = millis();

  currentState = RESETTING;
}
