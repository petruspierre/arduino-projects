int vel1= 10;
int IN1= 9;
int IN2= 8;
int IN3= 7;
int IN4= 6;
int vel2= 5;

void esquerda(){
  analogWrite(vel1, 255);
  analogWrite(vel2, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); // ESQUERDA
}
void direita(){
  analogWrite(vel1, 255);
  analogWrite(vel2, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); // DIREITA
}
void tras(){
  analogWrite(vel1, 255);
  analogWrite(vel2, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); // TRAS
}
void frente(){
  analogWrite(vel1, 255);
  analogWrite(vel2, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); // FRENTE
}
void setup() {
  pinMode(vel1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel2, OUTPUT);
    analogWrite(vel1, 255);
  analogWrite(vel2, 255);
  Serial.begin(9600);
}

void loop() {

  char z = Serial.read();
  if(z == 'd'){
    frente();
  }
  else if(z=='b'){
    direita();
  }
  else if(z=='h'){
    esquerda();
  }
  else if(z=='f'){
    tras();
  }
  else if(z=='F' || z=='H' || z=='B' || z=='D'){
    analogWrite(vel1, 0);
  analogWrite(vel2, 0);
    digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); // PARA
  }
}
