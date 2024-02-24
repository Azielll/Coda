#include "Arduino.h"
#include "Drive.h"


Drivetrain::Drivetrain() {
  init();
}

void Drivetrain::init() {
  // Left Wheels
  pinMode(leftENA, OUTPUT);
  pinMode(leftENB, OUTPUT);
  pinMode(leftFrontMotorPin1, OUTPUT);
  pinMode(leftFrontMotorPin2, OUTPUT);
  pinMode(leftBackMotorPin1, OUTPUT);
  pinMode(leftBackMotorPin2, OUTPUT);
  // Right Wheels 
  pinMode(rightENA, OUTPUT);
  pinMode(rightENB, OUTPUT);
  pinMode(rightFrontMotorPin1, OUTPUT);
  pinMode(rightFrontMotorPin2, OUTPUT);
  pinMode(rightBackMotorPin1, OUTPUT);
  pinMode(rightBackMotorPin2, OUTPUT);
}

void Drivetrain::forward(int carspeed, int time) {
  //Left Wheels
  digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  digitalWrite(leftBackMotorPin1, LOW);
  digitalWrite(leftBackMotorPin2, HIGH);
  //Right Wheels
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, HIGH);
  digitalWrite(rightBackMotorPin1, LOW);
  digitalWrite(rightBackMotorPin2, HIGH);
  //Speed
  analogWrite(leftENA, carspeed);
  analogWrite(leftENB, carspeed);
  analogWrite(rightENA, carspeed);
  analogWrite(rightENB, carspeed);
  delay(time);
}

void Drivetrain::back(int carspeed, int time) {
  //Left Wheels
  digitalWrite(rightFrontMotorPin1, HIGH);
  digitalWrite(rightFrontMotorPin2, LOW);
  digitalWrite(rightBackMotorPin1, HIGH);
  digitalWrite(rightBackMotorPin2, LOW);
  //Right Wheels
  digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, HIGH);
  digitalWrite(leftBackMotorPin1, HIGH);
  digitalWrite(leftBackMotorPin2, LOW);
  //Speed
  analogWrite(leftENA, carspeed);
  analogWrite(leftENB, carspeed);
  analogWrite(rightENA, carspeed);
  analogWrite(rightENB, carspeed);
  delay(time);
}

void Drivetrain::left(int carspeed, int time) {
  //Left Wheels
  digitalWrite(rightFrontMotorPin1, HIGH);
  digitalWrite(rightFrontMotorPin2, LOW);
  digitalWrite(rightBackMotorPin1, LOW);
  digitalWrite(rightBackMotorPin2, HIGH);
  //Right Wheels
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, HIGH);
  digitalWrite(rightBackMotorPin1, LOW);
  digitalWrite(rightBackMotorPin2, HIGH);  
  //Speed
  analogWrite(leftENA, carspeed);
  analogWrite(leftENB, carspeed);
  analogWrite(rightENA, carspeed);
  analogWrite(rightENB, carspeed);
  delay(time);
}

void Drivetrain::right(int carspeed, int time) {
  //Right Wheels
  digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  digitalWrite(leftBackMotorPin1, HIGH);
  digitalWrite(leftBackMotorPin2, LOW);
  //Left Wheels
  digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  digitalWrite(leftBackMotorPin1, LOW);
  digitalWrite(leftBackMotorPin2, HIGH);
  //Speed
  analogWrite(leftENA, carspeed);
  analogWrite(leftENB, carspeed);
  analogWrite(rightENA, carspeed);
  analogWrite(rightENB, carspeed);
  delay(time);
}

void Drivetrain::stop(int time) {
  //Left Wheels
  digitalWrite(leftFrontMotorPin1, LOW);
  digitalWrite(leftFrontMotorPin2, LOW);
  digitalWrite(leftBackMotorPin1, LOW);
  digitalWrite(leftBackMotorPin2, LOW);
  //Right Wheels
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, LOW);
  digitalWrite(rightBackMotorPin1, LOW);
  digitalWrite(rightBackMotorPin2, LOW);
  delay(time);
}

void Drivetrain::circlePath(int Vl, int Vr) {
  //Left Wheels
  digitalWrite(leftFrontMotorPin1, HIGH);
  digitalWrite(leftFrontMotorPin2, LOW);
  digitalWrite(leftBackMotorPin1, LOW);
  digitalWrite(leftBackMotorPin2, HIGH);
  //Right Wheels
  digitalWrite(rightFrontMotorPin1, LOW);
  digitalWrite(rightFrontMotorPin2, HIGH);
  digitalWrite(rightBackMotorPin1, LOW);
  digitalWrite(rightBackMotorPin2, HIGH);
  //Speed
  analogWrite(leftENA, Vl);
  analogWrite(leftENB, Vl);
  analogWrite(rightENA, Vr);
  analogWrite(rightENB, Vr);
  delay(1);
}

void Drivetrain::differentialEquationPath() {
  circlePath(vl, vr);

  int newXposition = ((vl + vr) * sin(w * (theta / w))) / (2 * w);
  Serial.println(newXposition);
  int newYposition = (((vl + vr) * cos(w * (theta / w)) - 1) / (2 * w)) * -1;
  Serial.println(newYposition);
  int newVcm = newXposition/newYposition;

  int newv1 = v1Calculator(newVcm);


  circlePath(newv1, 255);
  
  }

int Drivetrain::v1Calculator(int vcm) {
  int v1 = (2 * vcm) - 255;
  return v1;
  }
