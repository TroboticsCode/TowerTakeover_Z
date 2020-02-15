#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//always include vex.h because it has all the robot setup declarations
//as well as the API for the code.
#include "vex.h"

void Paint_Screen();

void driveDist(float inches, int speed);
void driveDistR(float inches, int speed);
void turnRight(float targetdegree, int speed);
void turnLeft(float targetdegree, int speed);
void clawOpen(int clawTarget);
void clawClose(int clawTarget);
void Lift(int liftTarget);
#endif