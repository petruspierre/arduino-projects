#include <SoftwareSerial.h>

int red = 11;
int blue = 13;
int green = 12;

SoftwareSerial monitorSerial(2, 3);

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  monitorSerial.begin(9600);
}

void loop() {
  char z;
  z = monitorSerial.read();
  Serial.println(z);
}

void splitString(char* data){
  char* parameter;
  parameter = strtok (data, " ,");
  
  while(parameter != NULL){
    setLED(parameter);
    parameter = strtok (NULL, " ,"); 
  }
}

void setLED(char* data){
  if((data[0] == 'b')){
    int Ans = strtol(data+1, NULL, 10);
    analogWrite(blue, Ans);
  }
  if((data[0] == 'g')){
    int Ans = strtol(data+1, NULL, 10);
    analogWrite(green, Ans);
  }
    if((data[0] == 'b')){
    int Ans = strtol(data+1, NULL, 10);
    analogWrite(red, Ans);
  }
}

