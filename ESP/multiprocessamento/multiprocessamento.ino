int sensor;

void setup()
{
  Serial.begin(115200);//Inicia a comunicaçao serial
  pinMode(2, OUTPUT);//Define o led Onboard como saída
  pinMode(18, INPUT);//Define o led Onboard como saída
 
  xTaskCreatePinnedToCore(loop2, "loop2", 8192, NULL, 1, NULL, 0);
  
  delay(1);
}
 
void loop()
{
  sensor = digitalRead(18);
  Serial.println(sensor);
  delay(1);
}
 
void loop2(void*z)
{
  while(1){
    digitalWrite(2, !sensor);
    delay(1);
  }
}
