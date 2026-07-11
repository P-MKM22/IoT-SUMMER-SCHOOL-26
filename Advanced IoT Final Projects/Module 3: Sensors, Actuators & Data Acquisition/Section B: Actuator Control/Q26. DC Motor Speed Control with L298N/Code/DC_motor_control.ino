/*
  Project    : DC Motor Speed Control with L293D
  Question   : Q 26
  Name       : P Meet Kumar
  Roll No.   : IoT 009
  File       : DC_Motor_Speed_Control.ino

  Description:
  This project controls the speed and direction of a DC motor using
  an L293D motor driver. A potentiometer controls the motor speed,
  one push button changes the motor direction, and another button
  starts or stops the motor. The Serial Monitor displays the motor
  direction, speed percentage, and current state.
*/

#define ENA 9
#define IN1 8
#define IN2 7

#define POT_PIN A0

#define DIR_BUTTON 2
#define START_BUTTON 3

bool motorRunning = true;
bool motorForward = true;

bool lastDirButton = HIGH;
bool lastStartButton = HIGH;

unsigned long lastDirPress = 0;
unsigned long lastStartPress = 0;

const unsigned long debounceDelay = 200;

//------------------------------------------------------------

void updateMotor(int pwmValue)
{
  if (!motorRunning)
  {
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    return;
  }

  analogWrite(ENA, pwmValue);

  if (motorForward)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
}

//------------------------------------------------------------

void printStatus(int pwmValue)
{
  int speedPercent = map(pwmValue, 0, 255, 0, 100);

  Serial.println("--------------------------------");

  Serial.print("Direction : ");
  Serial.println(motorForward ? "Forward" : "Reverse");

  Serial.print("Speed     : ");

  if (motorRunning)
    Serial.print(speedPercent);
  else
    Serial.print(0);

  Serial.println("%");

  Serial.print("State     : ");
  Serial.println(motorRunning ? "Running" : "Stopped");

  Serial.println("--------------------------------");
  Serial.println();
}

//------------------------------------------------------------

void setup()
{
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(DIR_BUTTON, INPUT_PULLUP);
  pinMode(START_BUTTON, INPUT_PULLUP);

  updateMotor(0);

  Serial.println("DC Motor Speed Control Started");
  Serial.println();
}

//------------------------------------------------------------

void loop()
{
  // Read potentiometer
  int potValue = analogRead(POT_PIN);

  // Convert to PWM value
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  // Read buttons
  bool dirButton = digitalRead(DIR_BUTTON);
  bool startButton = digitalRead(START_BUTTON);

  // Direction Button
  if (dirButton == LOW &&
      lastDirButton == HIGH &&
      millis() - lastDirPress > debounceDelay)
  {
    motorForward = !motorForward;
    lastDirPress = millis();
    printStatus(pwmValue);
  }

  // Start/Stop Button
  if (startButton == LOW &&
      lastStartButton == HIGH &&
      millis() - lastStartPress > debounceDelay)
  {
    motorRunning = !motorRunning;
    lastStartPress = millis();
    printStatus(pwmValue);
  }

  lastDirButton = dirButton;
  lastStartButton = startButton;

  // Update motor continuously
  updateMotor(pwmValue);

  // Display live values every 300 ms
  static unsigned long previousMillis = 0;

  if (millis() - previousMillis >= 300)
  {
    previousMillis = millis();
    printStatus(pwmValue);
  }
}
