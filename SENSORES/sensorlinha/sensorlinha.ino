void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(0));
  Serial.print(" ");
  Serial.println(analogRead(1));
  delay(50);
}
