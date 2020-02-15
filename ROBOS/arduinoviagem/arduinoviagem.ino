
  /* 
   *  
   *   |-------------|
   *   |    PINOS    |
   *   |-------------|
   * 
  */
  
#define IN1 9// TRAS ESQUERDA
#define IN2 8 // FRENTE DIREITA
#define IN3 7 // FRENTE ESQUERDA
#define IN4 6 // TRAS DIREITA
int vel1 = 10; // VELOCIDADE DOS MOTORES DA ESQ
int vel2 = 5; // VELOCIDADE DOS MOTORES DA DIR
int sensormeio = 12;
int sensordireita = 13;
int sensoresquerda = 11;

  /* 
   *  
   *   |-----------------|
   *   |    VARIAVEIS    |
   *   |-----------------|
   * 
  */
  
int cont = 0;
int cont2 = 0;
int cont3 = 0;
int sm;
int se;
int sd;

  /* 
   *  
   *   |-------------|
   *   |   DIREÇÕES  |
   *   |-------------|
   * 
  */

/*void frente(int veldir, int velesq){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(vel2, 255);
  analogWrite(vel1, 255);
  delay(100);
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}
void esquerda(int veldir, int velesq){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  analogWrite(vel2, 255);
  analogWrite(vel1, 255);
  delay(100);
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}
void direita(int veldir, int velesq){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(vel2, 255);
  analogWrite(vel1, 255);
  delay(100);
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}
void tras(int veldir, int velesq){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(vel2, 255);
  analogWrite(vel1, 255);
  delay(100);
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}*/

void setup() {
  
  //PONTE H
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);

  pinMode(sensormeio, INPUT);
  pinMode(sensordireita, INPUT);
  pinMode(sensoresquerda, INPUT);

}

void loop() {

  sm = digitalRead(sensormeio);
  sd = digitalRead(sensordireita);
  se = digitalRead(sensoresquerda);
  // 0 = BRANCO
  // 1 = PRETO

  if(sd == 0){ 

     if(cont3 < 500){
        cont3++;
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);

        if(cont == 0){
           analogWrite(vel2, 255);
           analogWrite(vel1, 255);
           delay(250);
           cont = 1;
        } else {
           analogWrite(vel2, 50);
           analogWrite(vel1, 120);
        }
     } else if(cont >= 500){
      while(sd == 0){
        direita(200, 200);
      }
      cont3 = 0;
     } 

  }
  else if(sd == 1){
     cont3 = 0;
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
  
     if(cont2 == 0){
        analogWrite(vel2, 255);
        analogWrite(vel1, 255);
        delay(250);
        cont2 = 1;
     } else {
        analogWrite(vel2, 120);
        analogWrite(vel1, 50);
     }
  }
  delay(1);
}
    

