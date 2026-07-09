/*
 * Project : PWM Fading Night Light
 * Question : Q17
 * Author : P Meet Kumar
 * Roll No. : IoT 009
 * Date :
 * Description :
 * Automatic PWM night light with three operating modes:
 * 1. Slow Breathing
 * 2. Fast Pulse
 * 3. SOS Pattern
 * Current mode is displayed on the Serial Monitor.
 */

const int LED_PIN = 9;
const int BUTTON_PIN = 2;

int mode = 0;
bool lastButtonState = HIGH;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);

  printMode();
}

void loop() {

  checkButton();

  switch (mode) {

    case 0:
      slowBreathing();
      break;

    case 1:
      fastPulse();
      break;

    case 2:
      sosPattern();
      break;
  }

}

void checkButton() {

  bool currentState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentState == LOW) {

    mode++;

    if (mode > 2)
      mode = 0;

    printMode();

    delay(250);
  }

  lastButtonState = currentState;
}

void printMode() {

  Serial.println();

  switch (mode) {

    case 0:
      Serial.println("Mode 1 : Slow Breathing");
      break;

    case 1:
      Serial.println("Mode 2 : Fast Pulse");
      break;

    case 2:
      Serial.println("Mode 3 : SOS Pattern");
      break;
  }

}

void slowBreathing() {

  // Fade In (1.5 seconds)

  for (int i = 0; i <= 255; i++) {

    analogWrite(LED_PIN, i);

    delay(6);

    if (digitalRead(BUTTON_PIN) == LOW)
      return;
  }

  // Fade Out (1.5 seconds)

  for (int i = 255; i >= 0; i--) {

    analogWrite(LED_PIN, i);

    delay(6);

    if (digitalRead(BUTTON_PIN) == LOW)
      return;
  }

}

void fastPulse() {

  // Fade In (0.25 seconds)

  for (int i = 0; i <= 255; i += 5) {

    analogWrite(LED_PIN, i);

    delay(5);

    if (digitalRead(BUTTON_PIN) == LOW)
      return;
  }

  // Fade Out (0.25 seconds)

  for (int i = 255; i >= 0; i -= 5) {

    analogWrite(LED_PIN, i);

    delay(5);

    if (digitalRead(BUTTON_PIN) == LOW)
      return;
  }

}

void dot() {

  analogWrite(LED_PIN, 255);

  delay(200);

  analogWrite(LED_PIN, 0);

  delay(200);

}

void dash() {

  analogWrite(LED_PIN, 255);

  delay(600);

  analogWrite(LED_PIN, 0);

  delay(200);

}

void sosPattern() {

  // ...

  dot();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  dot();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  dot();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  delay(300);

  // ---

  dash();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  dash();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  dash();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  delay(300);

  // ...

  dot();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  dot();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  dot();
  if (digitalRead(BUTTON_PIN) == LOW) return;

  delay(1000);

}
