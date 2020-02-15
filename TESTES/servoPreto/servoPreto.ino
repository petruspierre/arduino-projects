#include <Servo.h>
 
#define SERVO 6 // Porta Digital 6 PWM
 
Servo s; // Variável Servo
int pos; // Posição Servo
 
void setup ()
{
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
  delay(2000);
}
 
void loop()
{
  s.write(150);
  delay(2000);
  s.write(0);
  delay(2000);
  /*for(pos = 0; pos < 180; pos++)
  {
    s.write(pos);
    delay(15);
    Serial.println(pos);
  }
  delay(1000);
  for(pos = 180; pos >= 0; pos--)
   {
    s.write(pos);
    delay(15);
   }
  delay(1000);*/
}
