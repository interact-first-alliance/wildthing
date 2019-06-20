#include "Drivetrain.h" 
#include <math.h>
Drivetrain::Drivetrain(int motorLeft, int motorRight)
{
  m_pinMotorLeft  = motorLeft;
  m_pinMotorRight = motorRight;
  
  m_potentiometerPin = potenPin;
  m_leftMotor.attach(m_pinMotorLeft);
  m_rightMotor.attach(m_pinMotorRight);

  pinMode(m_potentiometerPin, INPUT);
}

void Drivetrain::setPower(int power,Servo* motor)
{
  motor->writeMicroseconds(power);
}

void Drivetrain::cartesianDrive(int x, int y)
{
  //reads the potentiometer and scales to from 1 to 0
  float potentiometerReading = analogRead(m_potentiometerPin);
  float powerScale = mapf(potentiometerReading, 0, 1023, 1,0);
  //scales the x and y from the joystick to -1 - 1 similar to FRC so you can
  //combine the values given from the x and y values given by the joystick
  float rotPow = mapf(x,0,1023,-1,1);
  float movePow  = mapf(y,0,1023,1,-1);
  //multiplies the scaled joystick values to the power scale
  float leftPow = constrain((movePow - steerPow), -1,1) * powerScale;
  float rightPow= constrain((movePow + steerPow), -1,1) * powerScale;
  //remaps the scales x and y back to servo values so it can drive motors
  int leftServo = (int)mapf(leftPow,-1,1,2000,1000);
  int rightServo= (int)mapf(rightPow,-1,1,1000,2000);
  Serial.println(powerScale);
  setPower(leftServo , &m_leftMotor);
  setPower(rightServo, &m_rightMotor);
 }
