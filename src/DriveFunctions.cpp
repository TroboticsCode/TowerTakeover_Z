//crucial to include the header file that includes the functions written out here
#include "Functions.h"

//put the diameter of your wheels, in inches, here. the default is 4 inch wheels
#define WHEEL_DIAMETER 2.75

//need to test if using negative inches values drives the robot backward
void drive(float inches, int speed){

frontLeft.setVelocity(speed,percent);
backLeft.setVelocity(speed,percent);
backRight.setVelocity(speed,percent);
frontRight.setVelocity(speed,percent);

//converts linear inches to wheel rotations
float wheel_rotations = inches / (WHEEL_DIAMETER*PI);

frontLeft.spinFor(wheel_rotations,turns, false);
frontRight.spinFor(wheel_rotations,turns, false);
backLeft.spinFor(wheel_rotations,turns, false);
backLeft.spinFor(wheel_rotations,turns);
}

