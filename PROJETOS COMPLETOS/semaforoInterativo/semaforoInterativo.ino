// Projeto 4 - Semáforo Interativo

int carRed = 12;
int carYellow = 11;
int carGreen = 10;
int pedRed = 9;
int pedGreen = 8;
int button = 2;
int crossTime = 5000; // tempo para atravessarem
unsigned long changeTime; // tempo desde que o botao foi pressionado //

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);
  // deixar o verde dos carros aberto e o vermelho dos pedestres
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);
  // verifica se o botão foi pressionado e se transcorreram 5 segundos desde a ultima vez que isso ocorreu//
  if (state == HIGH && (millis() - changeTime) > 5000) { // millis é o tempo desde que o Arduino foi iniciado
    changeLights(); // chama a função para alterar as luzes
  }
}
void changeLights(){
  digitalWrite(carGreen, LOW); 
  digitalWrite(carYellow, HIGH);
  delay(2000);
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(1000);

  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(crossTime);

  for(int x=0; x<10; x++){
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  digitalWrite(pedRed, HIGH);
  delay(500);
  digitalWrite(carYellow, HIGH);
  digitalWrite(carRed, LOW);
  delay(1000);
  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);

  changeTime = millis();
  }


