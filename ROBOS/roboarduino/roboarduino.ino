int IN1 = 5; // TRAS ESQUERDA
int IN2 = 6; // FRENTE ESQUERDA
int IN3 = 9; // FRENTE DIREITA
int IN4 = 10; // TRAS DIREITA
  
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    char z = Serial.read();
    if(z == 'B'){
      analogWrite(IN1, 255);
      analogWrite(IN2, 0);
      analogWrite(IN3, 255);
      analogWrite(IN4, 0);
      Serial.println(z);
    }
    if(z == 'D'){
      analogWrite(IN1, 0);
      analogWrite(IN2, 255);
      analogWrite(IN3, 255);
      analogWrite(IN4, 0);
      Serial.println(z);
    }
    if(z == 'E'){
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
      Serial.println(z);
    }
    if(z == 'F'){
      analogWrite(IN1, 255);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 255);
      Serial.println(z);
    }
    if(z == 'H'){
      analogWrite(IN1, 0);
      analogWrite(IN2, 255);
      analogWrite(IN3, 0);
      analogWrite(IN4, 255);
      Serial.println(z);
    }
    if((z == 'b') || (z == 'd') || (z == 'e') || (z == 'h') || (z == 'f')){
      analogWrite(IN1, 0);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 0);
      Serial.println(z);
    }
}


