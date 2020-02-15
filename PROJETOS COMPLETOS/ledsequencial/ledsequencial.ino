// Projeto 5 - Efeito de iluminação sequencial com LEDs
byte ledPin[] = {6,7,8,9,10,11,12,13}; // cria uma array para os pinos dos LEDs
int ledDelay(65); // intervalo entre as alterações
int direction = 1;
int currentLED = 0;
int but = 2;
unsigned long changeTime;

void setup() {
  for (int x=0; x<8; x++) {
    pinMode(ledPin[x], OUTPUT);
    }
    changeTime = millis();
    pinMode(but, INPUT_PULLUP);
}

void loop() {
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}
void changeLED(){
  while(!digitalRead(but) == HIGH){
  for (int x=0; x<8; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;
  if(currentLED == 7) {
    direction = -1;
  }
  if(currentLED == 0) {
    direction = 7;
  }
 }
  for (int x=0; x<8; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;
  if(currentLED == 7) {
    direction = -1;
  }
  if(currentLED == 0) {
    direction = 7;
  }
}


