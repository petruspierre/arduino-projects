#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>

#define pintrig 13
#define pinecho 12

#define ledPin 8

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
Ultrasonic ultrasonic(pintrig, pinecho);

void setup() {
  lcd.begin(16,2);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sensor iniciado.");
}

void loop() {
  lcd.setBacklight(HIGH);
  float dcm;
  long dms = ultrasonic.timing();
  dcm = ultrasonic.convert(dms, Ultrasonic::CM);
  Serial.print("Distancia: ");
  Serial.print(dcm);
  Serial.println("cm");
  lcd.setCursor(0,0);
  lcd.print("DISTANCIA: ");
  lcd.setCursor(11,0);
  
  int toneVal;
  toneVal = (400 + dcm);
  tone(7, toneVal);
  
  if(dcm < 5){
    digitalWrite(ledPin, HIGH);
    lcd.print(dcm,1);
    lcd.setCursor(14,0);
    lcd.print("  ");
    delay(300);
  }
  
  if ((dcm >=5) && (dcm < 10)){
      digitalWrite(ledPin, HIGH);
      delay(150);
      digitalWrite(ledPin, LOW);
      delay(150);
      lcd.print(dcm,1);
      lcd.setCursor(14,0);
      lcd.print("  ");
  }
  
  if (dcm >= 10) {
    digitalWrite(ledPin, LOW);
    lcd.print(dcm,1);
    delay(300);
  }
  if(dcm > 1000){
    lcd.clear();
  }
    }

