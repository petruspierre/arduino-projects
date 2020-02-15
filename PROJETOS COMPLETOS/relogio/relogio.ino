// Projeto relógio
#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
virtuabotixRTC myRTC(6,7,8);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  /*
  myRTC.setDS1302Time(30,8,23,5,31,5,2018);
  */
}

void loop() {
  // Le as informacoes do CI
  myRTC.updateTime();
    Serial.print("Data: ");
  // Chama a rotina que imprime o dia da semana
  dia_semana(myRTC.dayofweek);
  lcd.setCursor(5,0);
  if(myRTC.dayofmonth < 10){
    lcd.print("0");
    lcd.setCursor(6,0);
  }
  lcd.print(myRTC.dayofmonth);
    Serial.print(myRTC.dayofmonth);
  lcd.setCursor(7,0);
  lcd.print("/");
  lcd.setCursor(8,0);
  if(myRTC.month){
    lcd.print("0");
    lcd.setCursor(9,0);
  }
  lcd.print(myRTC.month);
    Serial.print("/");
    Serial.print(myRTC.month);
  lcd.setCursor(10,0);
  lcd.print("/");
  lcd.setCursor(11,0);
  lcd.print(myRTC.year);
    Serial.print("/");
    Serial.print(myRTC.year);
    Serial.print("   Hora: ");
  lcd.setCursor(1,1);
  lcd.print("Hora: ");
  lcd.setCursor(7,1);
   // Adiciona um 0 caso o valor da hora seja <10
  if(myRTC.hours < 10){
    lcd.print("0");
    lcd.setCursor(8,1);
    Serial.print("0");
  }
  lcd.print(myRTC.hours);
  lcd.setCursor(9,1);
  lcd.print(":");
  lcd.setCursor(10,1);
    Serial.print(myRTC.hours);
    Serial.print(": ");
  // Adiciona um 0 caso o valor dos minutos seja <10
  if(myRTC.minutes < 10){
    lcd.print("0");
    lcd.setCursor(11,1);
    Serial.print("0");
  }
  lcd.print(myRTC.minutes);
  lcd.setCursor(12,1);
  lcd.print(":");
  lcd.setCursor(13,1);
    Serial.print(myRTC.minutes);
    Serial.print(":");
  // Adiciona um 0 caso o valor dos segundos seja <10
  if(myRTC.seconds < 10){
    lcd.print("0");
    lcd.setCursor(14,1);
    Serial.print("");
  }
  lcd.print(myRTC.seconds);
  Serial.println(myRTC.seconds);

  delay(1000);
}

void dia_semana(int dia){
  switch(dia){
    case 1:
    Serial.print("Domingo");
    lcd.setCursor(1,0);
    lcd.print("Dom");
    break;
    case 2:
    Serial.print("Segunda");
    lcd.setCursor(1,0);
    lcd.print("Seg");
    break;
    case 3:
    Serial.print("Terça");
    lcd.setCursor(1,0);
    lcd.print("Ter");
    break;
    case 4:
    Serial.print("Quarta");
    lcd.setCursor(1,0);
    lcd.print("Qua");
    break;
    case 5:
    Serial.print("Quinta");
    lcd.setCursor(1,0);
    lcd.print("Qui");
    break;
    case 6:
    Serial.print("Sexta");
    lcd.setCursor(1,0);
    lcd.print("Sex");
    break;
    case 7:
    Serial.print("Sábado");
    lcd.setCursor(1,0);
    lcd.print("Sab");
    break;
  }
}

