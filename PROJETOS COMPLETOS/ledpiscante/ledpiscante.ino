// Projeto 1 - Led Piscante

int ledPin = 10;
void setup() {
  pinMode(ledPin, HIGH);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}
