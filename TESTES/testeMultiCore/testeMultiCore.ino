int sensor;

void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(18, INPUT);
 
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


