// Future enhancement: CSV serial logging
const int Pin = 9;

void setup() {
  pinMode(Pin, OUTPUT);
}

void loop() {
  digitalWrite(Pin, HIGH);
  delay(500);

  digitalWrite(Pin, LOW);
  delay(500);
}
