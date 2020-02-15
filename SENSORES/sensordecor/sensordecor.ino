
 
#define S0_D 4
#define S1_D 5
#define S2_D 6
#define S3_D 7
#define sensorOut_D 8
#define S0_E 9
#define S1_E 10
#define S2_E 11
#define S3_E 12
#define sensorOut_E 13
#define sensormeio 14

int frequency = 0;
void setup() {
  pinMode(S0_D, OUTPUT);
  pinMode(S1_D, OUTPUT);
  pinMode(S2_D, OUTPUT);
  pinMode(S3_D, OUTPUT);
  pinMode(sensorOut_D, INPUT);
  
  pinMode(S0_E, OUTPUT);
  pinMode(S1_E, OUTPUT);
  pinMode(S2_E, OUTPUT);
  pinMode(S3_E, OUTPUT);
  pinMode(sensorOut_E, INPUT);
  
  pinMode(sensormeio, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0_D,HIGH);
  digitalWrite(S1_D,LOW);
  digitalWrite(S0_E,HIGH);
  digitalWrite(S1_E,LOW);
  
  Serial.begin(9600);
}
void loop() {
  int z = analogRead(sensormeio);
  Serial.print("MEIO: ");
  Serial.print(z);
  Serial.println(" ");
  
  // Setting red filtered photodiodes to be read
  digitalWrite(S2_D,LOW);
  digitalWrite(S3_D,LOW);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut_D, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,72,255,0);
  
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");


  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2_D,HIGH);
  digitalWrite(S3_D,HIGH);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut_D, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,90,255,0);

  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");



  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2_D,LOW);
  digitalWrite(S3_D,HIGH);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut_D, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,70,255,0);
  
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");





  // Setting red filtered photodiodes to be read
  digitalWrite(S2_E,LOW);
  digitalWrite(S3_E,LOW);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut_E, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,72,255,0);
  
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");


  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2_E,HIGH);
  digitalWrite(S3_E,HIGH);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut_E, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30,90,255,0);

  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");


  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2_E,LOW);
  digitalWrite(S3_E,HIGH);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut_E, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,70,255,0);
  
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  
}
