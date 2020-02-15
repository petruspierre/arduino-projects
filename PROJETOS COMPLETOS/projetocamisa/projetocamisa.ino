#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Inicializa o display no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
byte sym1[8] = {0x4,0x1c,0x14,0x10,0x18,0x10,0x10};
byte sym2[8] = {0x0,0xe,0x9,0x9,0xe,0xa,0x9};
byte sym3[8] = {0x0,0x7,0x5,0x4,0x4,0x5,0x7};

 
void setup() {
 lcd.begin (16, 2);
 lcd.setBacklight(HIGH);
 lcd.createChar(0, sym1);
 lcd.createChar(1, sym2);
 lcd.createChar(2, sym3);
}
 
void loop() {
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print((char)2); 
 lcd.print((char)1); 
 lcd.print((char)0); 
 lcd.setCursor(6, 0);
 lcd.print("CAIXA");
 delay (3000);

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print((char)2); 
 lcd.print((char)1); 
 lcd.print((char)0); 
 lcd.setCursor(7, 0);
 lcd.print("MRV");
 delay (3000);

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print((char)2); 
 lcd.print((char)1); 
 lcd.print((char)0); 
 lcd.setCursor(6, 0);
 lcd.print("SEJA");
 lcd.setCursor(5, 1);
 lcd.print("SOCIO!");
 delay (3000);
 
}
