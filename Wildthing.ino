#include "Drivetrain.h"
#include "DualJoystick.h"
#define LEFTMOTORPIN 6
#define RIGHTMOTORPIN 5
#define JOYSTICKX A3
#define JOYSTICKY A4
Drivetrain* wheels;
DualJoystick* driveStick;
void setup() {
  // put your setup code here, to run once:
  wheels = new Drivetrain(LEFTMOTORPIN, RIGHTMOTORPIN);
  driveStick = new DualJoystick(JOYSTICKX,JOYSTICKY);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = driveStick -> getX();
  int y = driveStick -> getY();
  wheels -> cartesianDrive(x, y);
  //Serial.println(map(right,0,1023,1000,2000));
  //Serial.println(driveStick -> getY());
}
