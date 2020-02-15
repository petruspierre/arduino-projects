int vel1 = 13;
int IN1 = 12; // TRAS ESQUERDA
int IN2 = 11; // FRENTE DIREITA
int IN3 = 10; // FRENTE ESQUERDA
int IN4 = 9; // TRAS DIREITA
int vel2 = 8;

//int sensordireita = 14;
//int sensoresquerda = 15;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);
 // pinMode(sensordireita, INPUT);
 // pinMode(sensoresquerda, INPUT);
}

void loop() {
/*  int sd = analogRead(sensordireita);
  int se = analogRead(sensoresquerda);
  if((sd < 200) && (se <200)){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH); //
    digitalWrite(IN3, HIGH); // ATIVA AS PORTAS DOS MOTORES DA FRENTE
    digitalWrite(IN4, LOW);
    analogWrite(vel1, 100); // 
    analogWrite(vel2, 100); // CONTROLE DOS PINOS DE VELOCIDADE DA PONTE H COM PWM
  }else if((sd > 200) && (se < 200)){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH); //
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, HIGH); // ATIVA OS MOTORES FRENTE ESQUERDA E TRÁS DIREITA
    analogWrite(vel1, 100); // 
    analogWrite(vel2, 100); // CONTROLE DOS PINOS DE VELOCIDADE DA PONTE H COM PWM
  }else if((sd < 200) && (se > 200)){
    digitalWrite(IN1, HIGH); //
    digitalWrite(IN2, LOW);   
    digitalWrite(IN3, HIGH); // ATIVA OS MOTORES FRENTE DIREITA E TRÁS ESQUERDA
    digitalWrite(IN4, LOW);
    analogWrite(vel1, 100); // 
    analogWrite(vel2, 100); // CONTROLE DOS PINOS DE VELOCIDADE DA PONTE H COM PWM
  }*/

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH); //
    digitalWrite(IN3, LOW); // ATIVA AS PORTAS DOS MOTORES DA FRENTE
    digitalWrite(IN4, LOW);
    analogWrite(vel1, 255); // 
    analogWrite(vel2, 255); // CONTROLE DOS PINOS DE VELOCIDADE DA PONTE H COM PWM
  
}
