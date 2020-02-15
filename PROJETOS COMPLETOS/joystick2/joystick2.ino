int joyX = 0;
int joyY = 0;
int joyZ = 0;

int eixoX = 0;
int eixoY = 1;
int eixoZ = 2;

int left = 6;
int forward = 4;
int back = 3;
int right = 5;

void setup() {
  pinMode(eixoZ, INPUT);
  Serial.begin(9600);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(forward, OUTPUT);
  pinMode(back, OUTPUT);
}

void loop() {
  joyX = analogRead(eixoX);
  joyY = analogRead(eixoY);
  joyZ = digitalRead(eixoZ);

  joyX = map(joyX, 0, 1023, 0, 3);
  joyY = map(joyY, 0, 1023, 0, 3);
  imprimir();

  if(joyX = 0){
    digitalWrite(left, HIGH);
    digitalWrite(right, LOW);
    digitalWrite(forward, LOW);
    digitalWrite(back, LOW);
    }
  if(joyX = 3){
    digitalWrite(right, HIGH);
    digitalWrite(left, LOW);
    digitalWrite(forward, LOW);
    digitalWrite(back, LOW);
    }
  if(joyY = 0){
    digitalWrite(forward, HIGH);
    digitalWrite(left, LOW);
    digitalWrite(right, LOW);
    digitalWrite(back, LOW);
    }
  if(joyY = 3){
    digitalWrite(back, HIGH);
    digitalWrite(left, LOW);
    digitalWrite(right, LOW);
    digitalWrite(forward, LOW);
    }
  
}
void imprimir(){
  Serial.print("X= ");
  Serial.println(joyX);

  Serial.print("Y= ");
  Serial.println(joyY);

  Serial.print("Z= ");
  Serial.println(joyZ);

  delay(1000);
}

