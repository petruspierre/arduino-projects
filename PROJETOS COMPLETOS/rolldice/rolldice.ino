// Projeto dado com LEDs

  int ledPin[7] = { 2, 3, 4, 5, 7, 8, 6 };
  int dicePatterns[7][7] = {
    {0, 0, 0, 0, 0, 0, 1}, //1
    {0, 1, 0, 0, 1, 0, 0}, //2
    {0, 1, 0, 0, 1, 0, 1}, //3
    {1, 0, 1, 1, 0, 1, 0}, //4
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 1, 1, 1, 1, 1, 0}, //6
    {0, 0, 0, 0, 0, 0, 0} // APAGADO
  };

int switchPin = 10;
int blank = 6;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i<7; i++){
    pinMode(ledPin[i], OUTPUT);
    pinMode(ledPin[i], LOW);
  }
  pinMode(switchPin, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop() {
  Serial.println(digitalRead(switchPin));
  if(!digitalRead(switchPin)){
    rollTheDice();
  }
  delay(100);
}

void rollTheDice(){
  int result = 0;
  int lenghtOfRoll = random(15, 25);
  
  for (int i = 0; i < lenghtOfRoll; i++){
    result = random(0, 6);
    show(result);
    delay(50 + i * 10);
  }

  for(int j = 0; j < 3; j++){
    show(blank);
    delay(250);
    show(result);
    delay(250);
  }
}

void show(int result){
  for(int i = 0; i < 7; i++){
    digitalWrite(ledPin[i], dicePatterns[result][i]);
  }
}

