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
