#include "Servo.h"
#include <Arduino.h>
#include "Constants.h"
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

class Drivetrain
{
  private:
    int m_pinMotorLeft;
    int m_pinMotorRight;
    int m_potentiometerPin;
    double sensitivity = 0.75;
    double xPrime;
    double yPrime;
    Servo m_leftMotor;
    Servo m_rightMotor;
    void setPower(int power, Servo* motor);
  public:
    Drivetrain(int motorLeft, int motorRight);
    void cartesianDrive(int x, int y);
};
#endif
