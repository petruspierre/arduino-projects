  /* 
   *  
   *   |-------------|
   *   |    PINOS    |
   *   |-------------|
   * 
  */

#define IN1 3 // TRAS ESQUERDA
#define IN2 4 // FRENTE DIREITA
#define IN3 5 // FRENTE ESQUERDA
#define IN4 6 // TRAS DIREITA
#define S0_D 22
#define S1_D 23
#define S2_D 25
#define S3_D 26
#define sensorOut_D 24

#define S0_E 48
#define S1_E 49
#define S2_E 46
#define S3_E 45
#define sensorOut_E 47

#define ECHO_F 8
#define TRIG_F 9

#define ECHO_D 10
#define TRIG_D 11

#define ECHO_E 12
#define TRIG_E 13

#define ECHO_F 36
#define TRIG_F 37


int sensormeio = 15;
int vel1 = 2;
int vel2 = 7;

int vel = 60;
int velr = 60;

int azul_d = 0;
int azul_e = 0;

  /* 
   *  
   *   |-------------|
   *   |   DIREÇÕES  |
   *   |-------------|
   * 
  */

void frente(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(vel1, vel);
  analogWrite(vel2, vel);
}
void esquerda(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(vel1, vel);
  analogWrite(vel2, velr);
}
void direita(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, velr);
  analogWrite(vel2, velr);
}
void tras(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, velr);
  analogWrite(vel2, velr);
}


void setup() {
  
  //PONTE H
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);

  // SENSOR DE COR DIREITA
  pinMode(S0_D, OUTPUT);
  pinMode(S1_D, OUTPUT);
  pinMode(S2_D, OUTPUT);
  pinMode(S3_D, OUTPUT);
  pinMode(sensorOut_D, INPUT);

  // SENSOR DE COR ESQUERDA
  pinMode(S0_E, OUTPUT);
  pinMode(S1_E, OUTPUT);
  pinMode(S2_E, OUTPUT);
  pinMode(S3_E, OUTPUT);
  pinMode(sensorOut_E, INPUT);

  // SENSOR DE REFLEXÃO DO MEIO
  pinMode(sensormeio, INPUT);

  // FREQUENCIA DOS SENSORES DE COR

  digitalWrite(S0_D,HIGH); // 20%
  digitalWrite(S1_D,LOW);
  digitalWrite(S0_E,HIGH); // 20%
  digitalWrite(S1_E,LOW);


  Serial.begin(9600);
}

void loop() {

  /* 
   *  
   *   |-------------|
   *   |   SENSORES  |
   *   |-------------|
   * 
  */
  
  // Variável para armazenar o valor do sensor do meio
  int sfaixa = analogRead(sensormeio);

  // Varíavel para armazenar o valor do azul na DIREITA
  digitalWrite(S2_D,LOW);
  digitalWrite(S3_D,HIGH);
  azul_d = pulseIn(sensorOut_D, LOW);
  azul_d = map(azul_d, 25,72,255,0);

  // Varíavel para armazenar o valor do azul na ESQUERDA
  digitalWrite(S2_E,LOW);
  digitalWrite(S3_E,HIGH);
  azul_e = pulseIn(sensorOut_E, LOW);
  azul_e = map(azul_e, 25,72,255,0);

  Serial.print("D: ");
  Serial.print(azul_d);
  Serial.print(" E: ");
  Serial.print(azul_e);
  Serial.print(" M: ");
  Serial.println(sfaixa);

  /* 
   *  
   *   |-------------|
   *   | SEGUE FAIXA |
   *   |-------------|
   * 
  */

  // PRETO NO MEIO

    // DIREITA BRANCO - ESQUERDA BRANCO
    if((azul_d > 100) && (azul_e > 100)){
      frente();
    }
    
    // DIREITA PRETO - ESQUERDA BRANCO
    if(azul_d < 100 && azul_e > 100){
      direita();
    }
    
    // ESQUERDA PRETO - DIREITA BRANCO   
    if(azul_e < 100 && azul_d > 100){
      esquerda();
    }

    if(azul_e < 165 && azul_d < 165){
      analogWrite(vel1, 0);
      analogWrite(vel2, 0);
    }  
 }
