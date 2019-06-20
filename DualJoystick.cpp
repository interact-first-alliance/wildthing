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
  m_x = mapf(m_x,0,1023,-1,1);
  return m_x;
}

double DualJoystick::getY()
{
  if((abs(512-m_y) < m_deadband)){m_y = 512;}
  m_y = analogRead(m_joystickPinY);
  m_y = mapf(m_y,0,1023,-1,1);
  return m_y; 
}
