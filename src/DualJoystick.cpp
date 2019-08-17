#include "DualJoystick.h"


/**
 * constructor 
 * @Param xPin: the analog pin for the x direction
 * @Param yPin: the analog pin for the y direction
*/
DualJoystick::DualJoystick(int xPin, int yPin)
{
  m_joystickPinX = xPin;
  m_joystickPinY = yPin;

  pinMode(m_joystickPinX, INPUT);
  pinMode(m_joystickPinY, INPUT);
  
}

/**
 * reads the x direction of the joystick
 * maps the raw value to a value from -1 - 1
 * @return the mapped x value
*/
double DualJoystick::getX()
{
  m_x = getRawX();
  if((abs(512-m_x) < m_deadband)){m_x = 512;}
  m_x = mapf(m_x,0,1023,-1,1);
  return m_x;
}

/**
 * reads the y direction of the joystick
 * maps the raw value to a value from -1 - 1
 * @return the mapped y value
*/
double DualJoystick::getY()
{
  m_y = getRawY();
  if((abs(512-m_y) < m_deadband)){m_y = 512;}
  m_y = mapf(m_y,0,1023,-1,1);
  return m_y; 
}


/**
 * gets the analog value from the x joystick
 * @returns the raw x value
*/
int DualJoystick::getRawX()
{
  return analogRead(m_joystickPinX);
}

/**
 * gets the analog value from the y joystick
 * @returns the raw y value
*/
int DualJoystick::getRawY()
{
  return analogRead(m_joystickPinY);
}

/**
 * static interface to scale the inputted value to -1 to 1
 * @Param the unscaled value
 * @return the scaled value
*/
double DualJoystick::scale(int x)
{
  return mapf(x,0,1023,-1,1);
}
