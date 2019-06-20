#include "DualJoystick.h"



DualJoystick::DualJoystick(int xPin, int yPin)
{
  m_joystickPinX = xPin;
  m_joystickPinY = yPin;

  pinMode(m_joystickPinX, INPUT);
  pinMode(m_joystickPinY, INPUT);
  
}


double DualJoystick::getX()
{
  m_x = analogRead(m_joystickPinX);
  if((abs(512-m_x) < m_deadband)){m_x = 512;}
  return m_x;
}

double DualJoystick::getY()
{
  if((abs(512-m_y) < m_deadband)){m_y = 512;}
  m_y = analogRead(m_joystickPinY);
  return m_y; 
}
