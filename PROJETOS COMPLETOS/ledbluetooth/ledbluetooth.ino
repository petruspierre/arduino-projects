int ledPin = 13;
  
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledPin, LOW);
}

void loop() {
    char z = Serial.read();
    if(z == 'A'){
      digitalWrite(ledPin, HIGH);
      Serial.println(z);
    }
    if(z == 'B'){
      digitalWrite(ledPin, LOW);
      Serial.println(z);
    }
}


