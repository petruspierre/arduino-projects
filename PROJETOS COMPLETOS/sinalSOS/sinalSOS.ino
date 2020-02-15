// Projeto - SOS Morse
int ledPin = 10;

// executa uma vez quando o sketch inicia
void setup() {
  // define o pino como saída
  pinMode(ledPin, OUTPUT);
}

// exxecuta repetidas vezes
void loop() {
  // 3 pontos
  for (int x=0;  x<3; x++) {
    digitalWrite(ledPin, HIGH); // acende o led
    delay(150);
    digitalWrite(ledPin, LOW); // apaga o led
    delay(100);
  }

  // espera 100ms para marcar o intervalo entre as letras 
  delay(100);

  // 3 traços
  for (int x=0; x<3; x++) {
    digitalWrite(ledPin, HIGH); 
    delay(400);
    digitalWrite(ledPin, LOW);
    delay(100);  
    }
    
  // espera 100ms para marcar o intervalo entre as letras 
  delay(100);

  // outros 3 pontos
  for(int x=0;  x<3; x++) {
    digitalWrite(ledPin, HIGH); // acende o led
    delay(150);
    digitalWrite(ledPin, LOW); // apaga o led
    delay(100);
  }
       // espera 5000ms para repetir o sinal de S.O.S
  delay(5000);
  }

