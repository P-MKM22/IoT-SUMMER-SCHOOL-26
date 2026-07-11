/*
  Project    : Keypad + LCD Password Protected Access System
  Question   : Q 28
  Name       : P Meet Kumar
  Roll No.   : IoT 009
  File       : Keypad_LCD_Access_System.ino

  Description:
  This project implements a password-protected access system
  using a 4x4 keypad and a 16x2 I2C LCD. Users enter a 4-digit
  PIN through the keypad. If the PIN matches the predefined
  password, access is granted and the green LED turns ON.
  Otherwise, access is denied with a red LED and buzzer alert.
  After three incorrect attempts, the system locks for 10 seconds.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// LCD Configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// LED and Buzzer Pins
#define GREEN_LED 10
#define RED_LED 11
#define BUZZER 12

// Password
String correctPIN = "2580";
String enteredPIN = "";

int wrongAttempts = 0;

// Keypad Configuration
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Display Home Screen
void showHome()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");
  lcd.setCursor(0,1);

  enteredPIN = "";
}

// Access Granted
void accessGranted()
{
  lcd.clear();
  lcd.print("ACCESS");
  lcd.setCursor(0,1);
  lcd.print("GRANTED");

  digitalWrite(GREEN_LED,HIGH);

  tone(BUZZER,1000,200);

  Serial.println("--------------------------------");
  Serial.println("ACCESS GRANTED");
  Serial.print("Entered PIN : ");
  Serial.println(correctPIN);
  Serial.println("--------------------------------");

  delay(3000);

  digitalWrite(GREEN_LED,LOW);

  wrongAttempts = 0;

  showHome();
}

// Access Denied
void accessDenied()
{
  lcd.clear();

  lcd.print("ACCESS");

  lcd.setCursor(0,1);

  lcd.print("DENIED");

  digitalWrite(RED_LED,HIGH);

  tone(BUZZER,600,500);

  Serial.println("--------------------------------");
  Serial.println("ACCESS DENIED");
  Serial.print("Entered PIN : ");
  Serial.println(enteredPIN);
  Serial.print("Wrong Attempts : ");
  Serial.println(wrongAttempts + 1);
  Serial.println("--------------------------------");

  delay(2000);

  digitalWrite(RED_LED,LOW);

  wrongAttempts++;

  if(wrongAttempts>=3)
  {
    lcd.clear();
    lcd.print("SYSTEM LOCKED");
    lcd.setCursor(0,1);
    lcd.print("WAIT 10 SEC");

    Serial.println("SYSTEM LOCKED FOR 10 SECONDS");

    delay(10000);

    wrongAttempts=0;
  }

  showHome();
}

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);

  digitalWrite(GREEN_LED,LOW);
  digitalWrite(RED_LED,LOW);

  showHome();
}

void loop()
{
  char key = keypad.getKey();

  if(key)
  {
    if(key>='0' && key<='9')
    {
      if(enteredPIN.length()<4)
      {
        enteredPIN += key;

        lcd.print("*");

        Serial.print("Key Pressed : ");
        Serial.println(key);
      }

      if(enteredPIN.length()==4)
      {
        delay(300);

        if(enteredPIN==correctPIN)
        {
          accessGranted();
        }
        else
        {
          accessDenied();
        }
      }
    }

    // '*' clears entered PIN
    else if(key=='*')
    {
      showHome();

      Serial.println("PIN Cleared");
    }

    // '#' submits PIN early
    else if(key=='#')
    {
      if(enteredPIN==correctPIN)
      {
        accessGranted();
      }
      else
      {
        accessDenied();
      }
    }
  }
}
