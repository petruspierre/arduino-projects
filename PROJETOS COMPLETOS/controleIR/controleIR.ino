#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 13;
byte led1 = 8;
byte led2 = 7;
byte led3 = 6;
byte led4 = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600); // Iniciar o Monitor Serial
    // Inicia o receptor
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Decodificando a entrada do receptor IR
  if(irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);

    // Switch Case para usar o botão pressionado no controle
    switch(results.value){
      case 16724175: // Botao 1
        if(digitalRead(led1) == LOW){
        digitalWrite(led1, HIGH);
        } else{
        digitalWrite(led1, LOW);
        }
      break;
      case 16718055: // Botao 2
      if(digitalRead(led2) == LOW){
        digitalWrite(led2, HIGH);
      } else {
        digitalWrite(led2, LOW);
      }
      break;
      case 16743045: // Botao 3
      if(digitalRead(led3) == LOW){
        digitalWrite(led3, HIGH);
      } else {
        digitalWrite(led3, LOW);
      }
      break;
      case 16716015: // Botao 4
      if(digitalRead(led4) == LOW){
        digitalWrite(led4, HIGH);
      } else {
        digitalWrite(led4, LOW);
      }
      break;
    }
    irrecv.resume();
  }
  delay(10);
}

