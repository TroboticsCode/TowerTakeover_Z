//crucial that you include the header file that lists the autons

#include "Autons.h"
#include "vex.h"


//name the function and write it out here

void Auton1(){
  liftlMotor.setPosition(0,degrees);
  liftrMotor.setPosition(0,degrees);
  clawClose(600);
  
  Lift(-470);

  /*driveDist(9.5,30);
  wait(1000, msec);
  clawOpen(500);
  driveDistR(8,30);
  Lift(-30);
  turnLeft(45,30);
  driveDistR(2,20);*/

  moveLinear(9.5, 100);
  wait(1000, msec);
  clawOpen(500);
  moveLinear(-8, 30);
  Lift(-30);
  moveRotate(-45, 100);
  moveLinear(-2, 100);

}

void Auton2(){
  
  liftlMotor.setPosition(0,degrees);
  liftrMotor.setPosition(0,degrees);
  clawClose(600);
  
  Lift(-470);
  
  //turnLeft(360,60);
}

void AutonRight(){
  clawMotor.spinFor(.5, turns);
  driveDist(40,50);
  wait(20, msec);
  driveDistR(30,50);
  turnRight(90,50);
}

void AutonLeft(){
  clawMotor.spinFor(.5, turns);
  driveDist(40,50);
  wait(20, msec);
  driveDistR(30,50);
  turnLeft(90,50);
}