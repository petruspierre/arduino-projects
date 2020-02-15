int red = 11;
int blue = 13;
int green = 12;
int touch = 10;

int cont = 0;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(touch, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(touch) == HIGH){
    cont++;
  } else {
    cont = 0;
  }
  
  if(cont < 1000){
    analogWrite(red, 255);
    analogWrite(blue, 0);
    analogWrite(green, 0);
  } else if(cont >= 1000 && cont < 2000){
    analogWrite(red, 0);
    analogWrite(blue, 255);
    analogWrite(green, 0);
  } else if(cont >= 2000 && cont < 4000){
    analogWrite(red, 0);
    analogWrite(blue, 0);
    analogWrite(green, 255);
  } else if(cont >= 4000 && cont < 5000){
    int x = map(cont, 4000, 5000, 0, 255);
    analogWrite(red, x);
    analogWrite(blue, 0);
    analogWrite(green, 0);
  } else if(cont >= 5000 && cont < 6000){
    int z = map(cont, 5000, 6000, 0, 255);
    analogWrite(red, 0);
    analogWrite(blue, 0);
    analogWrite(green, z);
  } else if(cont >= 6000 && cont < 7000){
    int y = map(cont, 6000, 7000, 0, 255);
    analogWrite(red, 0);
    analogWrite(blue, y);
    analogWrite(green, 0  );
  }
  delay(1);
}
