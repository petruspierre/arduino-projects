// Projeto acender led com palmas

int microfone = 3; // Pino digital ligado ao sensor de som (DO)
int led = 5; // Pino ligado ao LED
 
int contPalmas = 0; // Contador de Palmas
int palmasRequeridaLigaLed = 2; // Contagem para acender o LED
int palmasRequeridaDesligaLed = 2; // Contagem para apagar o LED
 
// Tempo máximo entre o pulso seguinte
unsigned long tempMaxSom = 1000; 
unsigned long tempMinSom = 300;  
unsigned long compriSonoro = 100; // Comprimento do som esperado
unsigned long time;
unsigned long startTime = 0;
 
void setup() {    
 pinMode(microfone, INPUT); // Inicia o pino do microfone como entrada
 pinMode(led, OUTPUT); // Inicia os pino do LED como saída
// Desliga LED (o LED é invertido HIGH = desliga / LOW = liga)
 digitalWrite(led, HIGH); 
 Serial.begin(9600);
}
 
void loop() { 
 time = millis();
 unsigned long tempoAposPalma = time - startTime;
 Serial.println(compriSonoro);
 Serial.println(tempoAposPalma);
 Serial.println(digitalRead(microfone));
 if (tempoAposPalma >= compriSonoro && digitalRead(microfone) == LOW) {
 
 if (tempoAposPalma < tempMinSom || tempoAposPalma > tempMaxSom) {
 contPalmas = 0;
 startTime = millis();
 }
 else {
   
 // Iniciada a contagem de pulso e o tempo
 contPalmas ++;
 startTime = millis();
 }
 
 // Verifica se a contagem de palma é igual ou superior ao número... 
//esperado e se o LED esta desligado
if((contPalmas>=palmasRequeridaLigaLed-1)&&(digitalRead(led)==HIGH)){
 digitalWrite(led, LOW);
 contPalmas = 0;
 }
 
 // Verifica se a contagem de palma é igual ou superior ao número... 
//esperado e se o LED esta aceso
if((contPalmas>=palmasRequeridaDesligaLed-1)&&(digitalRead(led)==LOW)){
   
 // Desliga LED e zera contagem
 digitalWrite(led, HIGH);
 contPalmas = 0;
 }
 }
 delay(100);
}
