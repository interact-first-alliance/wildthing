#include <Arduino.h>
#include "Constants.h"
#ifndef DUALJOYSTICK_H
  #define DUALJOYSTICK_H

class DualJoystick
{
  private:
    double m_x;
    double m_y;
    int m_deadband = 150;
    int m_joystickPinX;
    int m_joystickPinY;
  public:
    DualJoystick(int xPin, int yPin);
    double getX();
    double getY();
  
};

#endif
