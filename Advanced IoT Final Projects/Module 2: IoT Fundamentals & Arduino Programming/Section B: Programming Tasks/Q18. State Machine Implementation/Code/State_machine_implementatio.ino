/*
 * Project : Enhanced Vending Machine State Machine
 * Question : Q18 (Enhanced Version)
 * Author : P Meet Kumar
 * Roll No. : IoT 009
 * Date : 01 July 2026
 * Description :
 * Enhanced vending machine using 5 LEDs.
 *
 * State Transition Diagram
 *
 *                    Insert Coin
 *      +--------------------------------+
 *      |                                |
 *      v                                |
 *   +--------+                     +---------------+
 *   | IDLE   |-------------------->|COIN_INSERTED |
 *   +--------+                     +---------------+
 *        ^                             |        |
 *        |                             |        |
 *        | Cancel                      |Select  |
 *        |                             |Item    |
 *        |                             v        |
 *        |                     +---------------+|
 *        |                     |ITEM_SELECTED || 
 *        |                     +---------------+|
 *        |                        |        |    |
 *        | Cancel                |Confirm |    |
 *        |                       |        |    |
 *        |                       v        |    |
 *        |                  +--------------+   |
 *        |                  | DISPENSING   |   |
 *        |                  +--------------+   |
 *        |                         |           |
 *        +-------------------------+-----------+
 *
 * LED Indication
 * RED    -> IDLE
 * YELLOW -> COIN INSERTED
 * BLUE   -> ITEM SELECTED
 * GREEN  -> DISPENSING
 * WHITE  -> CANCELLED
 */

const int RED_LED = 8;
const int YELLOW_LED = 9;
const int BLUE_LED = 10;
const int GREEN_LED = 11;
const int WHITE_LED = 12;

const int COIN_BUTTON   = 2;
const int SELECT_BUTTON = 3;
const int CANCEL_BUTTON = 4;

enum State
{
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING,
  CANCELLED
};

State currentState = IDLE;

unsigned long previousBlink = 0;
bool blueState = false;

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  pinMode(COIN_BUTTON, INPUT_PULLUP);
  pinMode(SELECT_BUTTON, INPUT_PULLUP);
  pinMode(CANCEL_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);

  updateLEDs();

  Serial.println("===== Enhanced Vending Machine =====");
  Serial.println("Current State : IDLE");
}

void loop()
{
  switch(currentState)
  {

    case IDLE:

      if(digitalRead(COIN_BUTTON) == LOW)
      {
        transitionTo(COIN_INSERTED);
        delay(250);
      }

      break;

    case COIN_INSERTED:

      if(digitalRead(SELECT_BUTTON) == LOW)
      {
        transitionTo(ITEM_SELECTED);
        delay(250);
      }

      else if(digitalRead(CANCEL_BUTTON) == LOW)
      {
        transitionTo(CANCELLED);
        delay(250);
      }

      break;

    case ITEM_SELECTED:

      blinkBlue();

      if(digitalRead(COIN_BUTTON) == LOW)
      {
        transitionTo(DISPENSING);
        delay(250);
      }

      else if(digitalRead(CANCEL_BUTTON) == LOW)
      {
        transitionTo(CANCELLED);
        delay(250);
      }

      break;

    case DISPENSING:

      Serial.println("Dispensing Item...");

      updateLEDs();

      delay(3000);

      Serial.println("Item Dispensed");

      transitionTo(IDLE);

      break;

    case CANCELLED:

      Serial.println("Transaction Cancelled");

      updateLEDs();

      delay(1000);

      transitionTo(IDLE);

      break;
  }
}
// Change current state
void transitionTo(State newState)
{
  Serial.print("Transition : ");
  Serial.print(stateName(currentState));
  Serial.print(" -> ");
  Serial.println(stateName(newState));

  currentState = newState;

  updateLEDs();
}

// Return state name
const char* stateName(State state)
{
  switch(state)
  {
    case IDLE:
      return "IDLE";

    case COIN_INSERTED:
      return "COIN_INSERTED";

    case ITEM_SELECTED:
      return "ITEM_SELECTED";

    case DISPENSING:
      return "DISPENSING";

    case CANCELLED:
      return "CANCELLED";
  }

  return "";
}

// Turn OFF every LED
void allLEDsOff()
{
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
}

// Update LEDs according to current state
void updateLEDs()
{
  allLEDsOff();

  switch(currentState)
  {
    case IDLE:
      digitalWrite(RED_LED, HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(YELLOW_LED, HIGH);
      break;

    case ITEM_SELECTED:
      // Blue LED blinks in this state
      break;

    case DISPENSING:
      digitalWrite(GREEN_LED, HIGH);
      break;

    case CANCELLED:
      digitalWrite(WHITE_LED, HIGH);
      break;
  }
}

// Blink Blue LED without blocking
void blinkBlue()
{
  if (millis() - previousBlink >= 250)
  {
    previousBlink = millis();

    blueState = !blueState;

    digitalWrite(BLUE_LED, blueState);
  }
}
