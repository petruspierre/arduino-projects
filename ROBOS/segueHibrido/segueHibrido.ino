
// PONTE H
#define vel1 2
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define vel2 7

// SENSORES REFLEXÃO
#define esquerdaRef 8
#define meioRef 9
#define direitaRef 10

// SENSORES DE COR
#define S0a 53
#define S1a 52
#define S2a 51
#define S3a 50
#define outA 49

#define S0b 48
#define S1b 47
#define S2b 46
#define S3b 45
#define outB 44

byte lre=0, lrd=0, lrm=0;
int corDireita=0, corEsquerda=0;
int frequency;

/*
 *  
 *         LRM
 *  LRE CE     CD LRD
 *  
 */

/*
 *
 * IN1 - TRAS DIREITA
 * IN2 - FRENTE DIREITA
 * IN3 - FRENTE ESQUERDA
 * IN4 - TRAS ESQUERDA
 *
*/

void setup() {

  // PONTE H
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);

  // SENSORES REFLEXÃO
  pinMode(esquerdaRef, INPUT);
  pinMode(meioRef, INPUT);
  pinMode(direitaRef, INPUT);

  // SENSORES DE COR
  pinMode(S0a, OUTPUT);
  pinMode(S1a, OUTPUT);
  pinMode(S2a, OUTPUT);
  pinMode(S3a, OUTPUT);
  pinMode(outA, INPUT);

  pinMode(S0b, OUTPUT);
  pinMode(S1b, OUTPUT);
  pinMode(S2b, OUTPUT);
  pinMode(S3b, OUTPUT);
  pinMode(outB, INPUT);

  digitalWrite(S0a,HIGH);
  digitalWrite(S1a,LOW);

  digitalWrite(S0b,HIGH);
  digitalWrite(S1b,LOW);

  Serial.begin(9600);
}

void loop() {

  corDireita = lerCorDireita();
  corEsquerda = lerCorEsquerda();

  lre = digitalRead(esquerdaRef);
  lrd = digitalRead(direitaRef);
  lrm = digitalRead(meioRef);

  Serial.print("LRE: " + lre);
  Serial.print(" CE: " + corEsquerda);
  Serial.print(" LRM: " + lrm);
  Serial.print(" CD: " + corDireita);
  Serial.println(" LRD: " + lrd);

}

int lerCorDireita(){

  digitalWrite(S2a,HIGH);
  digitalWrite(S3a,HIGH);

  frequency = pulseIn(outA, LOW);
  frequency = map(frequency, 30,90,255,0);

  return frequency;
  
}

int lerCorEsquerda(){

  digitalWrite(S2b,HIGH);
  digitalWrite(S3b,HIGH);

  frequency = pulseIn(outB, LOW);
  frequency = map(frequency, 30,90,255,0);

  return frequency;
  
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

void direita( int velocidade1, int velocidade2 ){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(vel1, velocidade1);
  analogWrite(vel2, velocidade2);
}

void esquerda( int velocidade1, int velocidade2 ){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(vel1, velocidade1);
  analogWrite(vel2, velocidade2);
}

//white
//
//R= 136  G= 162  B= 176  
//R= 147  G= 187  B= 165  
//R= 169  G= 158  B= 170  
//R= 169  G= 158  B= 165  
//R= 136  G= 162  B= 165  
//R= 142  G= 162  B= 170  
//R= 136  G= 162  B= 165  
//R= 136  G= 162  B= 165  
//R= 136  G= 162  B= 165  
//R= 142  G= 166  B= 165  
//R= 136  G= 162  B= 165  
//R= 136  G= 162  B= 165  
//R= 136  G= 162  B= 165  
//R= 136  G= 162  B= 165  
//R= 136  G= 162  B= 165  
//
//black
//
//R= -314  G= -276  B= -413  
//R= -325  G= -306  B= -391  
//R= -303  G= -272  B= -379  
//R= -320  G= -297  B= -385  
//R= -320  G= -314  B= -459  
//R= -385  G= -310  B= -436  
//R= -385  G= -335  B= -430  
//R= -347  G= -331  B= -430  
//R= -385  G= -331  B= -396  
//R= -385  G= -331  B= -430  
//R= -379  G= -318  B= -430  
//R= -374  G= -327  B= -425  
//R= -374  G= -327  B= -430  
//R= -385  G= -331  B= -402  
//R= -385  G= -331  B= -430 
//
//verde
//
//R= -287  G= -182  B= -300  
//R= -292  G= -182  B= -300  
//R= -292  G= -187  B= -300  
//R= -292  G= -182  B= -300  
//R= -255  G= -182  B= -300  
//R= -287  G= -182  B= -300  
//R= -287  G= -157  B= -300  
//R= -287  G= -182  B= -300  
//R= -287  G= -182  B= -300  
//R= -292  G= -187  B= -266  
//R= -260  G= -187  B= -306  
//R= -292  G= -187  B= -266  
//R= -292  G= -182  B= -300  
//R= -292  G= -157  B= -300  
