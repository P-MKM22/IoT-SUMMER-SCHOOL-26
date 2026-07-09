/*
------------------------------------------------------------
Project     : Digital Piano using Buzzer
File Name   : digital_piano.ino

Author      : P Meet Kumar
Roll Number : IoT 009
Date        : 01 July 2026

Description :
A 4-key digital piano using Arduino UNO and a passive buzzer.
- Do, Re, Mi, Fa notes
- Sol when two or more keys are pressed
- Major/Minor mode toggle
- Uses INPUT_PULLUP
------------------------------------------------------------
*/
#define BUTTON_DO    2
#define BUTTON_RE    3
#define BUTTON_MI    4
#define BUTTON_FA    5
#define BUTTON_MODE  6
#define BUZZER       8

// Major Scale
const int MAJOR_DO = 262;
const int MAJOR_RE = 294;
const int MAJOR_MI = 330;
const int MAJOR_FA = 349;

// Minor Scale
const int MINOR_DO = 200;
const int MINOR_RE = 250;
const int MINOR_MI = 290;
const int MINOR_FA = 330;

// Chord Substitute
const int SOL = 392;

bool minorMode = false;
bool lastModeState = HIGH;

int currentFrequency = 0;

void setup() {

  Serial.begin(9600);

  pinMode(BUTTON_DO, INPUT_PULLUP);
  pinMode(BUTTON_RE, INPUT_PULLUP);
  pinMode(BUTTON_MI, INPUT_PULLUP);
  pinMode(BUTTON_FA, INPUT_PULLUP);
  pinMode(BUTTON_MODE, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);

  Serial.println("--------------------------------");
  Serial.println(" DIGITAL PIANO");
  Serial.println("--------------------------------");
  Serial.println("Mode : MAJOR");
}
void loop() {

  bool doKey = !digitalRead(BUTTON_DO);
  bool reKey = !digitalRead(BUTTON_RE);
  bool miKey = !digitalRead(BUTTON_MI);
  bool faKey = !digitalRead(BUTTON_FA);

  bool modeKey = !digitalRead(BUTTON_MODE);

  // Toggle between Major and Minor scales
  if (modeKey && lastModeState == HIGH) {

    minorMode = !minorMode;

    if (minorMode)
      Serial.println("Mode Changed : MINOR");
    else
      Serial.println("Mode Changed : MAJOR");

    delay(200);   // Debounce
  }

  lastModeState = modeKey;

  // Count how many musical keys are pressed
  int pressedCount = 0;

  if (doKey) pressedCount++;
  if (reKey) pressedCount++;
  if (miKey) pressedCount++;
  if (faKey) pressedCount++;

  int frequency = 0;
  String note = "";

  // Two or more buttons -> Sol
  if (pressedCount >= 2) {

    frequency = SOL;
    note = "Sol (Chord)";

  }
  else {

    if (doKey) {

      frequency = minorMode ? MINOR_DO : MAJOR_DO;
      note = "Do";

    }
    else if (reKey) {

      frequency = minorMode ? MINOR_RE : MAJOR_RE;
      note = "Re";

    }
    else if (miKey) {

      frequency = minorMode ? MINOR_MI : MAJOR_MI;
      note = "Mi";

    }
    else if (faKey) {

      frequency = minorMode ? MINOR_FA : MAJOR_FA;
      note = "Fa";

    }

  }
    // Play or stop the buzzer only when the frequency changes
  if (frequency != currentFrequency) {

    if (frequency == 0) {

      noTone(BUZZER);
      Serial.println("Silence");

    } else {

      tone(BUZZER, frequency);
      Serial.print("Playing : ");
      Serial.println(note);

    }

    currentFrequency = frequency;
  }

  delay(20);
}
