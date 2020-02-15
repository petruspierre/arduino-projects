#include <Servo.h>

Servo MotorX;

int joyX = 0;
int joyZ = 0;
int joyY = 0;

int eixoX = 0;
int eixoY = 1; 
int eixoZ = 2;

void setup() {
  MotorX.attach(3);
  pinMode(eixoZ, INPUT);
  MotorX.write(90);
  Serial.begin(9600);
}

void loop() {

  joyX = analogRead(eixoX);
  joyY = analogRead(eixoY);
  joyZ = digitalRead(eixoZ);

  imprimeEixos();

  joyX = map(joyX, 0, 1023, 0, 179);
  joyY = map(joyY, 0, 1023, 0, 179);
  joyZ = map(joyZ, 0, 1, 0, 179);

  MotorX.write(joyZ);
  delay(20);
}

void imprimeEixos(){
  Serial.print(" Z=");
  Serial.print(joyZ);
}

