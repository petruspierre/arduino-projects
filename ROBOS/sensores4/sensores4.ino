#define s6 A1
#define s7 A2
#define s3 A3
#define s4 A4
#define s1 A0
#define s5 A5
#define s2 A7

#define vel1 8
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12
#define vel2 13

int sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7;
int velE = 150;
int velD = 200;

int corte1 = 400;
int corte2 = 650;

/*
                          
                             S5 S6 S7
                          S1 S2    S3 S4

___________|  S1  |  S2  |  S3  |  S4  |  S5  |  S6  |  S7  |
BRANCO (<) | 600  | 350  | 350  | 600  | 350  | 350  | 350  |
PRETO (>=) | 600  | 350  | 350  | 600  | 350  | 350  | 350  |

*/

void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  sensor1 = analogRead(s1);
  sensor2 = analogRead(s2);
  sensor3 = analogRead(s3);
  sensor4 = analogRead(s4);
  sensor5 = analogRead(s5);
  sensor6 = analogRead(s6);
  sensor7 = analogRead(s7);

  //printarSensores();

  // BRANCO - PRETO - BRANCO
  if(sensor2 < corte1 && sensor6 >= corte1 && sensor3 < corte1){
    frente(velE, velD);
  }
  // PRETO - BRANCO - BRANCO 
  else if(sensor2 >= corte1 && sensor6 < corte1 && sensor3 < corte1){
    esquerda(velE, velD);
  }
  // BRANCO - BRANCO - PRETO
  else if(sensor2 < corte1 && sensor6 < corte1 && sensor3 >= corte1){
    direita(velE, velD);
  }
  // PRETO - PRETO - BRANCO
  else if(sensor2 >= corte1 && sensor6 >= corte1 && sensor3 < corte1){
    frente(velE, velD);
    while(sensor2 >= corte1){
      sensor2 = analogRead(s2);
      delay(10);
    }
  }
  // BRANCO - PRETO - PRETO
  else if(sensor2 < corte1 && sensor6 >= corte1 && sensor3 >= corte1){
    frente(velE, velD);
    while(sensor3 >= corte1){
      sensor3 = analogRead(s3);
      delay(10);
    }
  }
  
//  if(sensor1 >= corte2 && sensor2 >= corte1 && sensor3 < corte1 && sensor4 < corte2 && sensor5 < corte1 && sensor6 < corte1 && sensor7 < corte1){
//    frente(150, 200);
//    delay(350);
//    esquerda(200, 200);
//    while(sensor6 < corte1){
//      sensor6 = analogRead(s6);
//    }
//  }
//
//  if(sensor1 < corte2 && sensor2 < corte1 && sensor3 >= corte1 && sensor4 >= corte2 && sensor5 < corte1 && sensor6 < corte1 && sensor7 < corte1){
//    frente(150, 200);
//    delay(350);
//    direita(200, 200);
//    while(sensor6 < corte1){
//      sensor6 = analogRead(s6);
//    }
//  }

  delay(10);
}

void frente( int velocidade1, int velocidade2 ){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(vel1, velocidade1);
  analogWrite(vel2, velocidade2);
}
void tras( int velocidade1, int velocidade2 ){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(vel1, velocidade1);
  analogWrite(vel2, velocidade2);
}
void esquerda( int velocidade1, int velocidade2 ){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(vel1, velocidade1);
  analogWrite(vel2, velocidade2);
}
void direita( int velocidade1, int velocidade2 ){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(vel1, velocidade1);
  analogWrite(vel2, velocidade2);
}

void printarSensores(){
    if(sensor1 < corte2){
    Serial.print("S1: BRANCO");
    Serial.print(" ");
  } else {
    Serial.print("S1: PRETO");
    Serial.print(" ");
  }

  if(sensor2 < corte1){
    Serial.print("S2: BRANCO");
    Serial.print(" ");
  } else {
    Serial.print("S2: PRETO");
    Serial.print(" ");
  }

  if(sensor3 < corte1){
    Serial.print("S3: BRANCO");
    Serial.print(" ");
  } else {
    Serial.print("S3: PRETO");
    Serial.print(" ");
  }

  if(sensor4 < corte2){
    Serial.print("S4: BRANCO");
    Serial.print(" ");
  } else {
    Serial.print("S4: PRETO");
    Serial.print(" ");
  }

  if(sensor5 < corte1){
    Serial.print("S5: BRANCO");
    Serial.print(" ");
  } else {
    Serial.print("S5: PRETO");
    Serial.print(" ");
  }

  if(sensor6 < corte1){
    Serial.print("S6: BRANCO");
    Serial.print(" ");
  } else {
    Serial.print("S6: PRETO");
    Serial.print(" ");
  }

  if(sensor7 < corte1){
    Serial.print("S7: BRANCO");
    Serial.println(" ");
  } else {
    Serial.print("S7: PRETO");
    Serial.println(" ");
  }

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

 delay(500);
}

