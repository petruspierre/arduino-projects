#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define buzzerPin = 2;

int ledsVermelhos[3] = {};
int ledsAmarelos[3] = {};
int ledsAzuis[3] = {};
int ledsVerdes[3] = {};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(115200);//Inicia a comunicaçao serial
  xTaskCreatePinnedToCore(loop2, "loop2", 8192, NULL, 1, NULL, 0); // Cria a tarefa "loop2()" com prioridade 1, atribuída ao core 0
  
  lcd.begin(19, 23); // SDA e SCL respectivamente
  lcd.backlight();
  
  delay(1); // precisa desse delay
}
 
void loop() // O loop() sempre será atribuído ao core 1 automaticamente pelo sistema, com prioridade 1
{
  delay(1);
}
 
void loop2(void*z) // Atribuímos o loop2 ao core 0, com prioridade 1
{
  tocarMusica();
  delay(1);
}

void tocarMusica(){ // Função com a musica completa
  
  //Primeira sessao
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  //Segunda sessão
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
 
  //variante 1
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);
 
  delay(500);
 
  //segunda sessão dnv
   beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
 
  //variante 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  
  delay(650);
  
}

void beep(int note, int duration) // função auxiliar da tocarMusica
{
  //toca
  tone(buzzerPin, note, duration);
 
  //para de tocar
  noTone(buzzerPin);
  delay(50);
  }
}
