int pir = 13;
int ledpin = 12;
int buz = 2;

void setup() {
  pinMode(pir, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int presenca = digitalRead(pir);
  Serial.println(presenca);
  if(presenca == LOW){
    digitalWrite(ledpin, LOW);
  } else {
    tone(2,260);
    digitalWrite(ledpin, HIGH);
    delay(100);
    noTone(2);
    digitalWrite(ledpin, LOW);
    delay(100);
  }
}
