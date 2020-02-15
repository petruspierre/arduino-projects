#include <Ultrasonic.h>
#include <Servo.h>

#define trigPin 10
#define echoPin 11

long duration;
int distance;

Ultrasonic ultrasonic(10, 11);

Servo servo;

void setup() {

  Serial.begin(9600);
  servo.attach(12);

}

void loop() {

  for(int i=1;i<=150;i++){
    servo.write(i);
    delay(30);
    Serial.print(i);
    Serial.print(",");
    Serial.print(ultrasonic.distanceRead());
    Serial.print(".");
  }

  for(int i=150;i>1;i--){
    servo.write(i);
    delay(30);
    Serial.print(i);
    Serial.print(",");
    Serial.print(ultrasonic.distanceRead());
    Serial.print(".");
  }
}

