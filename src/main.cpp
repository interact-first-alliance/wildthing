#include <Arduino.h>
#include "DualJoystick.h"
#include "Drivetrain.h"
#include "Constants.h"
DualJoystick stick(A0, A1);
Drivetrain driveTrain(10,11);

double x,y;
unsigned long lastTime;
void setup() {
  Serial.begin(9600);
  lastTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-lastTime > 50)
  {
    x = stick.getX;
    y = stick.getY;

    driveTrain.cartesianDrive(x,y);
  }
}