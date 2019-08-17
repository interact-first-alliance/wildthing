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

void Drivetrain::cartesianDrive(double steerPow, double movePow)
{
  double leftPow = constrain((movePow - steerPow), 1,-1);
  double rightPow= constrain((movePow + steerPow), 1,-1);
  //remaps the scales x and y back to servo values so it can drive motors
  int leftServo = (int)mapf(leftPow,-1,1,2000,1000);
  int rightServo= (int)mapf(rightPow,-1,1,1000,2000);
  setPower(leftServo , &m_leftMotor);
  setPower(rightServo, &m_rightMotor);
 }
