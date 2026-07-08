// Future enhancement: RGB LED support
const int Pin = 9;
int blinkCount = 0;

void setup() {
  pinMode(Pin, OUTPUT);

  Serial.begin(9600);
  Serial.println("LED Blink Program Started");
}

void loop() {
  digitalWrite(Pin, HIGH);
  delay(500);

  digitalWrite(Pin, LOW);
  delay(500);

  blinkCount++;

  Serial.print("Blink Count: ");
  Serial.println(blinkCount);
}
