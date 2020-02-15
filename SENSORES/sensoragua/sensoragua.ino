int water = 0;

void setup() {
  pinMode(water, INPUT);
  Serial.begin(9600);
}

void loop() {
  int i = analogRead(water);
  Serial.println(i);
  delay(1000);
}
