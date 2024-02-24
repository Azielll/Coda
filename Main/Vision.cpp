
#include "Arduino.h"
#include "Vision.h"
#include "Constants.h"
#include <Servo.h>

Servo myServo;


Vision::Vision() {
    
    init();

}

void Vision::init() {

    Serial.begin(9600);
    myServo.attach(servo);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    //pinMode(camera, INPUT);
}

void Vision::readDistance() {
    digitalWrite(trigPin, LOW);
    delay(25);
    digitalWrite(trigPin, HIGH);
    delay(25);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);
}

void Vision::moveHead(int x) {
  myServo.write(x);
}

int Vision::getDistance() {
  digitalWrite(trigPin, LOW);
  delay(25);
  digitalWrite(trigPin, HIGH);
  delay(25);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  return distance;
    
}

int Vision::getTrigPin() {
  return trigPin;
}

int Vision::getEchoPin() {
  return echoPin;
}







