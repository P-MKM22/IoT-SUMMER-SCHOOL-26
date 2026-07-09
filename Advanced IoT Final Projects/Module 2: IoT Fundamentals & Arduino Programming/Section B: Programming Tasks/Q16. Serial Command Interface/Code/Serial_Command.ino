/*
 * Project : Serial Command Interface
 * Question : Q16
 * Author : P Meet Kumar
 * Roll No. : IoT 009
 * Date :
 * Description :
 * Controls the built-in LED using commands received
 * from the Serial Monitor.
 */

const int LED_PIN = LED_BUILTIN;
int blinkCounter = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  while (!Serial);

  Serial.println("=== Serial Command Interface ===");
  Serial.println("Available Commands:");
  Serial.println("LED_ON");
  Serial.println("LED_OFF");
  Serial.println("BLINK_X (Example: BLINK_5)");
  Serial.println("STATUS");
  Serial.println("RESET");
  Serial.println("--------------------------------");
}

void loop() {

  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "LED_ON") {

      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED Turned ON");

    }
    else if (command == "LED_OFF") {

      digitalWrite(LED_PIN, LOW);
      Serial.println("LED Turned OFF");

    }
    else if (command.startsWith("BLINK_")) {

      if (command.length() == 7) {

        char ch = command.charAt(6);

        if (ch >= '1' && ch <= '9') {

          int times = ch - '0';

          Serial.print("Blinking ");
          Serial.print(times);
          Serial.println(" time(s)");

          for (int i = 0; i < times; i++) {

            digitalWrite(LED_PIN, HIGH);
            delay(500);

            digitalWrite(LED_PIN, LOW);
            delay(500);
          }

          blinkCounter += times;
          Serial.println("Blink Complete");

        } else {

          Serial.println("ERROR: Unknown command");

        }

      } else {

        Serial.println("ERROR: Unknown command");

      }

    }
    else if (command == "STATUS") {

      Serial.println("----- STATUS -----");

      Serial.print("Built-in LED : ");

      if (digitalRead(LED_PIN) == HIGH)
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Counter : ");
      Serial.println(blinkCounter);

    }
    else if (command == "RESET") {

      blinkCounter = 0;
      Serial.println("Blink Counter Reset");

    }
    else {

      Serial.println("ERROR: Unknown command");

    }
  }
}
