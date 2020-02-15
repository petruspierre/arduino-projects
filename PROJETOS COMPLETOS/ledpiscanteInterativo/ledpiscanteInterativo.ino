// Projeto 6 - Efeito de iluminação sequencial com LEDs INTERATIVO
byte ledPin[] = {6,7,8,9,10,11,12,13}; // cria uma array para os pinos dos LEDs
int ledDelay; // intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2;

void setup() {
  for (int x=0; x<8; x++) {
    pinMode(ledPin[x], OUTPUT);
    }
    changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin);
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}
void changeLED(){
  for (int x=0; x<8; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;
  if(currentLED == 7) {
    direction = -1;
  }
  if(currentLED == 0) {
    direction = 1;
  }
}

