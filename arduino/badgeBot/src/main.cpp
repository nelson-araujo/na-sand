#include <Arduino.h>
#include <Servo.h>

// Prototypes
int zeroServo(Servo);
int presentBadge(Servo);

Servo yellowServo;
int yellowServoOut = 13;
int yellowServoIn = 53;

Servo brownServo;
int brownServoOut = 12;
int brownServoIn = 52;

Servo blueServo;
int blueServoOut = 11;
int blueServoIn = 51;

Servo greenServo;
int greenServoOut = 10;
int greenServoIn = 50;



void setup() {
  // Set serial connection
  Serial.begin(115200);


  // Configure inputs
  pinMode(yellowServoIn, INPUT);
  pinMode(brownServoIn, INPUT);
  pinMode(blueServoIn, INPUT);
  pinMode(greenServoIn, INPUT);


  // Map Servo to pin
  yellowServo.attach(yellowServoOut);
  brownServo.attach(brownServoOut);
  blueServo.attach(blueServoOut);
  greenServo.attach(greenServoOut);

  // Set servos to angle 0
  zeroServo(yellowServo);
  zeroServo(brownServo);
  zeroServo(blueServo);
  zeroServo(greenServo);

}

void loop() {
  // delay(100);
  // Serial.println(int(digitalRead(greenServoIn)));
  
  // Monitor yellow servo input
  // int yellowServoInStatus = digitalRead(yellowServoIn);
  // if(yellowServoInStatus == HIGH){
  //   Serial.println("Yellow input activated");
  //   presentBadge(yellowServo);
  // }

  // Monitor brown servo input
  int brownServoInStatus = digitalRead(brownServoIn);
  if(brownServoInStatus == HIGH){
    Serial.println("Brown input activated");
    presentBadge(brownServo);
  }

  // Monitor blue servo input
  int blueServoInStatus = digitalRead(blueServoIn);
  if(blueServoInStatus == HIGH){
    Serial.println("Blue input activated");
    presentBadge(blueServo);
  }

  // Monitor green servo input
  int greenServoInStatus = digitalRead(greenServoIn);
  if( greenServoInStatus == HIGH){
    Serial.println("Green input activated");
    presentBadge(greenServo);
  }
  
}

// Zero out all servos
int zeroServo(Servo servo){
  servo.write(0);

  return 0;
}

// Present badge to reader
int presentBadge(Servo servo) {
  int raisedAngle = 0;    // Raised angle so ready state (Badge away from reader)
  int presentAngle = 60;  // Final angle to present badge to reader
  int readHold = 2500;    // Hold areadHoldngle to read badge

  servo.write(presentAngle);
  delay(readHold);
  servo.write(raisedAngle);

  return 0;
}