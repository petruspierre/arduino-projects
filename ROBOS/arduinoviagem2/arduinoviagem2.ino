
  /* 
   *  
   *   |-------------|
   *   |    PINOS    |
   *   |-------------|
   * 
  */
  
// Sensor de cor
#define S0 2
#define S1 3
#define S2 4
#define S3 11
#define sensorOut 12
//
// Ponte H
#define IN1 9// TRAS ESQUERDA
#define IN2 8 // FRENTE DIREITA
#define IN3 7 // FRENTE ESQUERDA
#define IN4 6 // TRAS DIREITA
int vel1 = 10; // VELOCIDADE DOS MOTORES DA DIREITA
int vel2 = 5; // VELOCIDADE DOS MOTORES DA ESQUERDA
//
// Sensores de faixa
int sensordireita = A2;
int sensoresquerda = A1;
//

  /* 
   *  
   *   |-----------------|
   *   |    VARIAVEIS    |
   *   |-----------------|
   * 
  */
  
int volta = 1;
int tempobranco = 0;
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

void frente(int veldir, int velesq, char boost){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  if(boost == 's'){
    analogWrite(vel2, 255);
    analogWrite(vel1, 255);
    delay(30);
  }
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}
void esquerda(int veldir, int velesq, char boost){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  if(boost == 's'){
    analogWrite(vel2, 255);
    analogWrite(vel1, 255);
    delay(30);
  }
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}
void direita(int veldir, int velesq, char boost){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  if(boost == 's'){
    analogWrite(vel2, 255);
    analogWrite(vel1, 255);
    delay(30);
  }
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}
void tras(int veldir, int velesq, char boost){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if(boost == 's'){
    analogWrite(vel2, 255);
    analogWrite(vel1, 255);
    delay(30);
  }
  
  analogWrite(vel2, veldir);
  analogWrite(vel1, velesq);
}

void parar(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  analogWrite(vel2, 0);
  analogWrite(vel1, 0);
}

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

  //
  // Branco: 0
  // Preto: 1
  //
  // Formato das funções: Velocidade direita, Velocidade esquerda, Boost[s/n]
  // Funções: direita, esquerda, frente, tras, parar
  //

  sm = digitalRead(sensormeio);
  sd = digitalRead(sensordireita);
  se = digitalRead(sensoresquerda);

  if(volta == 1){

    if(sd == 0){
      if(tempobranco < 300){
        frente(80, 150, 'n');
      }
      else if(tempobranco > 300){
        direita(200, 200, 's');
        delay(1000);
        while(sd == 0){
          direita(200, 200, 'n');
        }
        parar();
        delay(50);
        while(sd == 0){
          esquerda(200, 200, 'n');
        }
      }
      tempobranco = tempobranco + 1;
      delay(1);
    }

    if(sd == 1){
      frente(150, 80, 'n');
      tempobranco = 0;
    }

    if(sm == 1){
      delay(15);
      if(sm == 1){
        tras(100, 100, 's');
        delay(300);
        
        parar();
        delay(70);
        
        direita(200, 200, 's');
        delay(1000);

        while(sd == 0){
          direita(200, 200, 'n');
        }

        parar();
        delay(100);

        volta = 2;
      }
    }
  
  } else if (volta == 2){
    while(true){
      parar();
    }
  }

}
