#include <Arduino.h>
#include<Servo.h>

Servo servo1;
int servo1Pin=13;

void setup() {
  servo1.attach(servo1Pin);
  servo1.write(0);
  delay(500);
  servo1.write(90);
  delay(500);
  servo1.write(180);
  delay(500);
  servo1.write(0);
  delay(10000);
}

void loop() {

  // servo1.write(0);
  // delay(10000);
  // servo1.write(90);

  // for(int i=0 ; i<=90 ; i++){
  //   servo1.write(i);
  //   delay(5);
  // }

  // delay(500);

  // for(int i=180 ; i>=0 ; i--){
  //   servo1.write(i);
  //   delay(5);
  // }

  // delay(1000);
}