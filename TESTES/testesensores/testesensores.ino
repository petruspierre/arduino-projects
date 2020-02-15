int sensordireita = 48;
int sensoresquerda = 49;

void setup() {
  pinMode(sensordireita, INPUT);
  pinMode(sensoresquerda, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sd = digitalRead(sensordireita);
  int se = digitalRead(sensoresquerda);

  Serial.print("D: ");
  Serial.print(sd);
  Serial.print(" E: ");
  Serial.println(se);
  delay(100);
}
