/*
  Project    : Bluetooth LED Controller (Serial Monitor Simulation)
  Question   : Q 31
  Name       : P Meet Kumar
  Roll No.   : IoT 009
  File       : Bluetooth_LED_Controller.ino

  Description:
  This project simulates an HC-05 Bluetooth LED Controller
  using the Arduino Serial Monitor. Commands entered through
  the Serial Monitor control Red, Green and Blue LEDs.
  The same command logic can later be used with an HC-05
  Bluetooth module without changing the application logic.
*/

#define RED_LED    8
#define GREEN_LED  9
#define BLUE_LED   10

char command;

// Initializes the Serial Monitor and LED pins
void setup()
{
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);

  Serial.println("========================================");
  Serial.println(" Bluetooth LED Controller");
  Serial.println(" (Serial Monitor Simulation)");
  Serial.println("========================================");
  Serial.println("Available Commands");
  Serial.println("R -> Red LED ON");
  Serial.println("G -> Green LED ON");
  Serial.println("B -> Blue LED ON");
  Serial.println("X -> All LEDs OFF");
  Serial.println("F -> Flash LEDs 5 Times");
  Serial.println("========================================");
}

// Continuously checks for incoming commands
void loop()
{
  if (Serial.available())
  {
    command = toupper(Serial.read());

    // Removes unwanted newline characters
    while (Serial.available())
      Serial.read();

    Serial.print("Command Received : ");
    Serial.println(command);

    // Turns ON the Red LED
    if (command == 'R')
    {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, LOW);

      Serial.println("Status : Red LED ON");
    }

    // Turns ON the Green LED
    else if (command == 'G')
    {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);

      Serial.println("Status : Green LED ON");
    }

    // Turns ON the Blue LED
    else if (command == 'B')
    {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);

      Serial.println("Status : Blue LED ON");
    }

    // Turns OFF all LEDs
    else if (command == 'X')
    {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, LOW);

      Serial.println("Status : All LEDs OFF");
    }

    // Flashes all LEDs five times
    else if (command == 'F')
    {
      Serial.println("Status : Flashing LEDs");

      for (int i = 1; i <= 5; i++)
      {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);

        delay(300);

        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);

        delay(300);

        Serial.print("Flash Count : ");
        Serial.println(i);
      }

      Serial.println("Status : Flash Completed");
    }

    // Handles invalid commands
    else
    {
      Serial.println("Invalid Command");
      Serial.println("Use R, G, B, X or F");
    }

    Serial.println("----------------------------------------");
  }
}
