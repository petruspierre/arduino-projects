#define s6 A1
#define s7 A2
#define s3 A3
#define s4 A4
#define s1 A0
#define s5 A5
#define s2 A7

/*

S5 S6 S7

*/

void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("S1: ");
  Serial.print(analogRead(s1));
  Serial.print(" ");

  Serial.print("S2: ");
  Serial.print(analogRead(s2));
  Serial.print(" ");

  Serial.print("S3: ");
  Serial.print(analogRead(s3));
  Serial.print(" ");

  Serial.print("S4: ");
  Serial.print(analogRead(s4));
  Serial.print(" ");

  Serial.print("S5: ");
  Serial.print(analogRead(s5));
  Serial.print(" ");

  Serial.print("S6: ");
  Serial.print(analogRead(s6));
  Serial.print(" ");

  Serial.print("S7: ");
  Serial.print(analogRead(s7));
  Serial.println(" ");

  delay(200);
}
