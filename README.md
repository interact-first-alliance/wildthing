<p align="center">
  <a href="https://interactfirst.org/">
    <img src="https://interactfirst.org/wp-content/uploads/2019/05/Interact-FIRST-Web-Logo-Horizontal-Color.png" alt="Interact FIRST Alliance logo" />
  </a>
</p>
<h3 align="center">PowerWheels Wild Thing</>

## Quick start
- Clone the repo: `git clone https://github.com/interact-first-alliance/wildthing.git`

## Documentation
### Code Structure
  - based off of FRC programming structure
               classes are split into a structure and framework easy for most FRC programmers to understand 
#### Class Breakdown 
  - Wildthing.ino
               contains main loop and setup routines 
               
  - Drivetrain.cpp
               controls the movement of the Powerwheels, Uses similar structure to a FRC Drivtrain and Joystick Combination         i.e Joysticks values are from -1 to 1 inclusive and tank style driving. this is to simplify the math used to make it driveable with 1 joystick. Also uses a potentiometer housed in the cavity of the powerwheels in order to limit the velocity of the device. 
               
  - DualJoystick.cpp
               reads and modifies the values sent by the joystick, which in reality are just 2 potentiometers squashed together.
               
  - Constants.cpp 
              class houses all constants used in the code, right now only houses 1 constant and a math function to map floats. 
              
## Creators and Maintainers

**Andrew Cua**

- <https://github.com/andrew-cua>

## Teams
[![](https://firestormrobotics.org/wp-content/uploads/2019/06/firestorm-logo-75.png)](https://firestormrobotics.org)
[![](https://interactfirst.org/wp-content/uploads/2019/06/EG3VDlvg_400x400.jpg)](https://www.eastcobbrobotics.org/)

## Sponsors

Support this project by becoming a sponsor. Your logo will show up here with a link to your website. [[Become a sponsor](https://interactfirst.org)]
