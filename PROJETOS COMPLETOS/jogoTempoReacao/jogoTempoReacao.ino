/*
 * Apertou: 0
 * Soltou: 1
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int leds[3] = {12,8,2};
int botoes[3] = {11,7,3};

int numero;
int numeroAnterior=0;
int tempoDelay;
int tempoms;
int partidas;
int media;
byte acertos=0;
byte erros=0;
String dificuldade;

void setup() {
  for(int i=0;i<3;i++){
    pinMode(botoes[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[1], HIGH);
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  randomSeed(analogRead(0));
  digitalWrite(leds[1], HIGH);
  dificuldade = configuracoesJogo();
}

String configuracoesJogo(){
  erros=0;
  acertos=0;
  media=0;
  partidas=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Dificuldade:");
  lcd.setCursor(0,1);
  lcd.print("   1 | 2 | 3");
  boolean libera = true;
  while(libera){
    byte bt1 = digitalRead(botoes[0]);
    byte bt2 = digitalRead(botoes[1]);
    byte bt3 = digitalRead(botoes[2]);
    if(bt1 == LOW){
      dificuldade = "facil";
      libera = false;
    }
    else if(bt2 == LOW){
      dificuldade = "medio";
      libera = false;
    }
    else if(bt3 == LOW){
      dificuldade = "dificil";
      libera = false;
    }
  }
  for(int i=0;i<3;i++){
    digitalWrite(leds[i], LOW);
  }
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("1");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("3");
  delay(1000);
  lcd.clear();
  return dificuldade;
}

void loop() {
  if(partidas != 9){
    lcd.setCursor(15,0);
    lcd.print(partidas+1);
  } else {
    lcd.setCursor(14,0);
    lcd.print(partidas+1);
  }
  
  if(dificuldade == "facil"){
    numero = random(2);
    numeroAnterior = numero;
    tempoDelay = 500;
    iniciarJogo(numero, tempoDelay);
  }
  else if(dificuldade == "medio"){
    numero = random(3);
    numeroAnterior = numero;
    tempoDelay = 500;
    iniciarJogo(numero, tempoDelay);
  }
  else if(dificuldade == "dificil"){
    numero = random(3);
    while(numero == numeroAnterior){
      numero = random(3);
    }
    numeroAnterior = numero;
    tempoDelay = 200;
    iniciarJogo(numero, tempoDelay);
  }

  partidas++;
  if(partidas == 10){
    lcdResultado();
  }
}

void iniciarJogo(int numero, int tempoDelay){
  lcdCor(numero);
  tempoms = 0;
  digitalWrite(leds[numero], HIGH);
  boolean libera = true;
  while(libera){
    byte bt1 = digitalRead(botoes[0]);
    byte bt2 = digitalRead(botoes[1]);
    byte bt3 = digitalRead(botoes[2]);
    if(bt1 == LOW){
      if(numero == 0){
        acertos++;
      } else {
        erros++;
      }
      libera = false;
    }
    else if(bt2 == LOW){
      if(numero == 1){
        acertos++;
      } else {
        erros++;
      }
      libera = false;
    }
    else if(bt3 == LOW){
      if(numero == 2){
        acertos++;
      } else {
        erros++;
      }
      libera = false;
    }
    delay(1);
    tempoms++;
  }
  digitalWrite(leds[numero], LOW);
  lcd.clear();
  lcdTempo(tempoms);
  media+=tempoms;
  delay(tempoDelay);
}

void lcdCor(int numero){
  lcd.setCursor(0,0);
  switch(numero){
    case 0:
      lcd.print("Amarelo");
      break;
    case 1:
      lcd.print("Azul");
      break;
    case 2:
      lcd.print("Vermelho");
      break;
  }
}

void lcdTempo(int tempo){
  lcd.setCursor(0,1);
  lcd.print("Tempo: " + String(tempoms) + "ms");
}

void lcdResultado(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Media:" + String(media/10.0) + "ms");
  lcd.setCursor(0,1);
  lcd.print(" AC: " + String(acertos) + " | " + "ER: " + String(erros));
  while(digitalRead(botoes[0]) && digitalRead(botoes[1]) && digitalRead(botoes[2])){
  }
  lcd.clear();
  delay(500);
  configuracoesJogo();
}


