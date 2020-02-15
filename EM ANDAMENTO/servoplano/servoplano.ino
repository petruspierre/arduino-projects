#include <Ultrasonic.h>

#include <Servo.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


#define SERVO 11
#define SERVO2 13
Servo s;
Servo s2;

#define botaoSobe 49
#define botaoDesce 48
#define botaoLibera 46

const byte linhas = 4; //4 linhas
const byte colunas = 4; //4 colunas
int pos = 0;
int ang = 0;
int distanciaBloco = 0.1;
char angulo[2] = "";

byte grau[8] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
};

byte quadrado[8] = {
  B11100,
  B00100,
  B11000,
  B10000,
  B11100,
  B00000,
  B00000,
  B00000
};

byte delta[8] = {
  B00000,
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B11111
};

byte teta[8] = {
  B01110,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001,
  B01110,
  B00000
};

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
Ultrasonic ultrassom(30, 32);
 
//teclado matricial
char matrizteclado[linhas][colunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinoslinhas[linhas] = {9,8,7,6}; //pinos utilizados nas linhas
byte pinoscolunas[colunas] = {5,4,3,2}; //pinos utilizados nas colunas
 
//inicializando o teclado
Keypad teclado = Keypad( makeKeymap(matrizteclado), pinoslinhas, pinoscolunas, linhas, colunas );
 
void setup() {
  pinMode(botaoSobe, INPUT_PULLUP);
  pinMode(botaoDesce, INPUT_PULLUP);
  pinMode(botaoLibera, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("Pressione uma tecla");
  lcd.begin(16,2);


  s.attach(SERVO);
//  s2.attach(SERVO2);
//  s2.write(0);
  s.write(0);
  lcd.createChar(1, grau);
  lcd.createChar(2, quadrado);
  lcd.createChar(3, delta);
  lcd.createChar(4, teta);

  lcd.setCursor(6,0);
  lcd.write(4);
  lcd.print("=0");
  lcd.write(1);
}
 
void loop() {
  char apertatecla = teclado.getKey(); // verifica se alguma tecla foi pressionada
 
  if (apertatecla) {
    if(apertatecla == 'A'){
      if(angulo[0] == ' '){
        if(ang != 90){
          lcd.clear();
          ang++;
          lcd.setCursor(6,0);
          lcd.write(4);
          lcd.print("=");
          lcd.print(ang);
          lcd.write(1);
          s.write(ang);
        } else {
          lcd.setCursor(13,0);
          lcd.print("MAX");
        }   
      }
    } else if(apertatecla == 'B'){
      if(angulo[0] == ' '){
        if(ang != 0){
          lcd.clear();
          ang--;
          lcd.setCursor(6,0);
          lcd.write(4);
          lcd.print("=");
          lcd.print(ang);
          lcd.write(1);
          lcd.setCursor(13,0);
          lcd.print("   ");
          s.write(ang);
        }
      }
    } else if(apertatecla == 'C'){
      Serial.println("servo2");
      int distancia = ultrassom.distanceRead();
      int tempoInicio = millis();
      while(distancia > 10){
        distancia = ultrassom.distanceRead();
        delay(1);
      }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write(4);
      lcd.print("=");
      lcd.print(ang);
      lcd.write(1);
      lcd.print(" ");
      lcd.write(3);
      lcd.print("t=");
      int tempoFinal = millis() - tempoInicio;
      lcd.print(tempoFinal);
      lcd.print("ms");
  
      lcd.setCursor(0,1);
      lcd.print("a=");
      lcd.print((sin(ang*(3.1416/180)))*10);
      lcd.print("m/s");
      lcd.write(2);
  
      apertatecla = teclado.getKey();
      while(!apertatecla){
        apertatecla = teclado.getKey();
      }
      lcd.clear();
      pos = 0;
      angulo[0] = ' ';
      angulo[1] = ' ';
      lcd.setCursor(6,0);
      lcd.write(4);
      lcd.print("=");
      lcd.print(ang);
      lcd.write(1);
      lcd.setCursor(13,0);
      lcd.print("   ");
//    s2.write(90);
//    delay(1000);
//    s2.write(0);
    }
    else if(apertatecla == '*'){
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.write(4);
      lcd.print("=");
      ang = atoi(angulo);
      lcd.print(ang);
      lcd.write(1);
      s.write(ang);
      pos = 0;
      angulo[0] = ' ';
      angulo[1] = ' ';
    } else if(pos > 1){
      lcd.setCursor(13,0);
      lcd.print("MAX");
    }
    else if(apertatecla != '*'){
      lcd.setCursor(pos,1);
      lcd.print(apertatecla);
      lcd.write(1);
      angulo[pos] = apertatecla;
      pos++; 
    } 
    Serial.println(apertatecla);
  }
}
