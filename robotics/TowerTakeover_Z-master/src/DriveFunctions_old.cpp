//crucial to include the header file that includes the functions written out here
#include "Functions.h"

//put the diameter of your wheels, in inches, here. the default is 4 inch wheels
#define WHEEL_DIAMETER 4

//need to test if using negative inches values drives the robot backward
void driveDist(float inches, int speed){

frontLeft.setVelocity(speed,percent);
backLeft.setVelocity(speed,percent);
backRight.setVelocity(speed,percent);
frontRight.setVelocity(speed,percent);

//converts linear inches to wheel rotations
float wheel_rotations = inches / (WHEEL_DIAMETER*PI);

frontLeft.spinFor(wheel_rotations,turns, false);
frontRight.spinFor(wheel_rotations,turns, false);
backLeft.spinFor(wheel_rotations,turns, false);
backRight.spinFor(wheel_rotations,turns);

}


void driveDistR(float inches, int speed){

frontLeft.setVelocity(-speed,percent);
backLeft.setVelocity(-speed,percent);
backRight.setVelocity(-speed,percent);
frontRight.setVelocity(-speed,percent);

//converts linear inches to wheel rotations
float wheel_rotations = inches / (WHEEL_DIAMETER*PI);

frontLeft.spinFor(-wheel_rotations,turns, false);
frontRight.spinFor(-wheel_rotations,turns, false);
backLeft.spinFor(-wheel_rotations,turns, false);
backRight.spinFor(-wheel_rotations,turns);

}


void turnRight(float targetdegree, int speed){
  float turnSpins=targetdegree/112;

  frontLeft.setVelocity(speed,percent);
  frontRight.setVelocity(speed,percent);
  backLeft.setVelocity(speed,percent);
  backRight.setVelocity(speed,percent);

  frontLeft.spinFor(turnSpins, turns,false);
  frontRight.spinFor(-turnSpins,turns,false);
  backLeft.spinFor(turnSpins, turns,false);
  backRight.spinFor(-turnSpins, turns,true);
}

void turnLeft(float targetdegree, int speed){
  float turnSpins=targetdegree/112;
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print(turnSpins);

  frontLeft.setVelocity(speed,percent);
  frontRight.setVelocity(speed,percent);
  backLeft.setVelocity(speed,percent);
  backRight.setVelocity(speed,percent);

  frontLeft.spinFor(-turnSpins, turns,false);
  frontRight.spinFor(turnSpins,turns,false);
  backLeft.spinFor(-turnSpins, turns,false);
  backRight.spinFor(turnSpins, turns,true);
}