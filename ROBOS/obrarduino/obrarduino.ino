int vel1 = 13;
int IN1 = 12; // TRAS ESQUERDA
int IN2 = 11; // FRENTE ESQUERDA
int IN3 = 10; // TRAS DIREITA
int IN4 = 9; // FRENTE DIREITA
int vel2 = 8;

int sensordireita = 48;
int sensoresquerda = 49;

int velfrente = 45;
int velcurva = 90;

//int sensordireita = 14;
//int sensoresquerda = 15;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);
}

void loop() {

    int sd = digitalRead(sensordireita);
    int se = digitalRead(sensoresquerda);

    if(sd == 0 && se == 0){ // d: branco e: branco
      analogWrite(vel1, velfrente);
      analogWrite(vel2, velfrente);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);
    } else if(sd == 1 && se == 0){ // d: preto e: branco
      analogWrite(vel1, velcurva);
      analogWrite(vel2, velcurva);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH); 
      digitalWrite(IN4, LOW);
      delay(50);
    } else if(sd == 0 && se == 1){ // d: branco e: preto
      analogWrite(vel1, velcurva);
      analogWrite(vel2, velcurva);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);
      delay(50);
    } else if(sd == 1 && se == 1){ // d: preto e: preto
      analogWrite(vel1, velfrente);
      analogWrite(vel2, velfrente);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, HIGH);
  }
}
