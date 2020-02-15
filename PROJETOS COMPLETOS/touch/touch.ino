#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int sensor = 7;
int ledPin = 13;
int ledPin2 = 12;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, HIGH);
  int val;
  val = digitalRead(sensor);
  Serial.print("Valor: ");
  Serial.println(val);

  lcd.setBacklight(HIGH);
  lcd.setCursor(1,0);
  lcd.print("Coloque seu dedo.");

  if(val == 1){
    lcd.setCursor(1,1);
    lcd.print("Ativado.");
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
  }
}
