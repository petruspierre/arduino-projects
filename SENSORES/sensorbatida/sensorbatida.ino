// acender led com palma

int microfone = 2;
int ledPin = 3;

int contPalmas = 0;
int palmasliga = 2;
int palmasdesliga = 2;

// tempo entre os pulsos
unsigned long tempomax = 1000;
unsigned long tempomin = 300;
unsigned long comprimento = 100;
unsigned long time;
unsigned long startTime = 0;

void setup(){
  Serial.begin(9600);
  pinMode(microfone, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}
void loop(){

  Serial.println(digitalRead(microfone));
  delay(100);

  
  time = millis();
  unsigned long tempopalma = time - startTime;

  if(tempopalma >= comprimento && digitalRead(microfone) == LOW){

     if(tempopalma < tempomin || tempopalma > tempomax){
      contPalmas = 0;
      startTime = millis();
     } else {
      contPalmas ++;
      startTime = millis();
     }

     if((contPalmas >= palmasliga - 1) && (digitalRead(ledPin) == HIGH)){
      digitalWrite(ledPin, LOW);
      contPalmas = 0;
     }

     if((contPalmas >= palmasliga-1)&&(digitalRead(ledPin) == LOW)){
      digitalWrite(ledPin, HIGH);
      contPalmas = 0;
     }
  }
}

