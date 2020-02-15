#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PINOBTN1 30
#define PINOBTN2 31
#define PINOBTN3 32

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

String segundosS, minutosS, milissegundosS;
long segundos=0, minutos=0, milissegundos=0;
byte estadoBotao1 = 1, estadoBotao2 = 1, estadoBotao3 = 1;
byte estadoTempo = 0;

byte play[8] = {
  B00000,
  B00000,
  B01000,
  B01100,
  B01100,
  B01000,
  B00000,
  B00000
};

byte pause[8] = {
  B00000,
  B00000,
  B01010,
  B01010,
  B01010,
  B01010,
  B00000,
  B00000
};

byte stopped[8] = {
  B00000,
  B00000,
  B01110,
  B01110,
  B01110,
  B01110,
  B00000,
  B00000
};

// 0 tempo parado
// 1 tempo pausado
// 2 tempo rodando
 
void setup()
{
 pinMode(PINOBTN1, INPUT_PULLUP);
 pinMode(PINOBTN2, INPUT_PULLUP);
 pinMode(PINOBTN3, INPUT_PULLUP);
 lcd.begin (16,2);
 Serial.begin(9600);

 lcd.createChar(3, play);
 lcd.createChar(1, pause);
 lcd.createChar(2, stopped);
 
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("Tempo: ");
 lcd.write(2);
 lcd.setCursor(4,1);
 lcd.print("00:00:00");
}
 
void loop()
{
  estadoBotao1 = digitalRead(PINOBTN1);
  estadoBotao2 = digitalRead(PINOBTN2);
  estadoBotao3 = digitalRead(PINOBTN3);
  Serial.print(estadoBotao1);
  Serial.print(estadoBotao2);
  Serial.println(estadoBotao3);
  
  if(estadoBotao1 == 0){
    if(estadoTempo == 0 || estadoTempo == 1){
      setarTempo();
      estadoTempo = 2;
      lcd.setCursor(11,0);
      lcd.write(3);
      Serial.println("Tempo iniciado");
    }
  } else if(estadoBotao2 == 0){
    if(estadoTempo == 2){
      estadoTempo = 1;
      lcd.setCursor(11,0);
      lcd.write(1);
      Serial.println("Tempo pausado");
    }
  } else if(estadoBotao3 == 0){
    if(estadoTempo == 2 || estadoTempo == 1){
      estadoTempo = 0;
      minutos = 0;
      segundos = 0;
      milissegundos = 0;
      lcd.setCursor(11,0);
      lcd.write(2);
      lcd.setCursor(4,1);
      lcd.print("00:00:00");
      Serial.println("Tempo reiniciado");
    }
  }

  
  
  if(estadoTempo == 2){
    setarTempo();
    mostrarDisplay();
    milissegundos++;
  }


  delay(1); 
}

void mostrarDisplay(){

  lcd.setCursor(4,1);
  if(minutos < 10 && segundos < 10){
    lcd.print("0" + minutosS + ":" + "0" + segundosS + ":" + milissegundosS); 
  } else if(segundos < 10){
    lcd.print(minutosS + ":" + "0" + segundosS + ":" + milissegundosS); 
  } else if(minutos < 10){
    lcd.print("0" + minutosS + ":" + segundosS + ":" + milissegundosS); 
  } else {
    lcd.print(minutosS + ":" + segundosS + ":" + milissegundosS); 
  }
  
}

void setarTempo(){
  if(segundos == 60){
    segundos = 0;
    minutos++;
  }
  if(milissegundos == 100){
    milissegundos = 0;
    segundos++;
  }
  segundosS = String(segundos);
  minutosS = String(minutos);
  milissegundosS = String(milissegundos);
}

