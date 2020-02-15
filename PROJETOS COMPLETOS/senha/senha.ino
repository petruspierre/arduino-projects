#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 lcd.begin (16,2);
}
 
void loop()
{
  lcd.setBacklight(HIGH);
  lcd.setCursor(6,0);
  lcd.print("CAIXA");
  delay(3000);
  lcd.setCursor(4,0);
  lcd.print("PETROBRAS");
  delay(3000);
    lcd.clear();
}
