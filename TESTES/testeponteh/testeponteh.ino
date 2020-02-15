/*Pinagem do arduino*/
 
//motor_A
int IN1 = 5;
int IN2 = 6;
 
//motor_B
int IN3 = 7;
int IN4 = 8;
 
//Inicializa Pinos
void setup(){
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
}
 
void loop(){
 
 /*Inicio dos Estados do motor A*/
 //Sentido 1
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,HIGH);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,HIGH);
 delay(2000);

 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 delay(2000);

 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 delay(2000);
 
/*Fim dos Estados do motor_B*/
}
