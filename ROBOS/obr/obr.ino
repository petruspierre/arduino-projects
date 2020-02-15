int IN1 = 4; // TRAS ESQUERDA
int IN2 = 5; // FRENTE ESQUERDA
int IN3 = 6; // FRENTE DIREITA
int IN4 = 7; // TRAS DIREITA

int FD = 14;
int FE = 15;

int vel = 255;
int velr = 255;

void setup() {
  pinMode(FD, INPUT);
  pinMode(FE, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int SensorDireita, SensorEsquerda;
  SensorDireita = analogRead(FD);
  SensorEsquerda = analogRead(FE);
  Serial.print("FD: ");
  Serial.print(SensorDireita);
  Serial.print("        ");
  Serial.print("FE: ");
  Serial.println(SensorEsquerda);

  if((SensorDireita < 200) && (SensorEsquerda < 200)){ // branco e branco
    analogWrite(IN1, 0);
    analogWrite(IN2, vel);
    analogWrite(IN3, vel);
    analogWrite(IN4, 0);
  } 
  if((SensorDireita > 200) && (SensorEsquerda < 200)){ // preto e branco
    analogWrite(IN1, velr);
    analogWrite(IN2, 0);
    analogWrite(IN3, vel);
    analogWrite(IN4, 0);
  }
  if((SensorDireita < 200) && (SensorEsquerda > 200)){ // branco e preto
    analogWrite(IN1, 0);
    analogWrite(IN2, velr);
    analogWrite(IN3, 0);
    analogWrite(IN4, vel);
  }
  
  
}
