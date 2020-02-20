//crucial that you include the header file that lists the autons

#include "Autons.h"
#include "vex.h"


//name the function and write it out here

void Auton1(){
  liftlMotor.setPosition(0,degrees);
  liftrMotor.setPosition(0,degrees);
  
  moveLinear(3,100);
  clawClose(600);
  Lift(-470);
  wait(1, sec);
  moveRotate(90, 100);
  moveLinear(12, 100);
  clawOpen(600);
  moveLinear(-12, 100);
  Lift(-50); //4 cubes
  moveRotate(-90, 100);
  moveLinear(10,100);
  clawClose(600);
  moveLinear(22,100);
  wait(3,sec);
  moveRotate(-90, 100);
  Lift(100); //height for put 4 cubes in corner
  moveLinear(15,100);
  Lift(0);
  clawOpen(600);
  moveLinear(-15, 100);
  moveRotate(90, 100);





  /*driveDist(9.5,30);
  wait(1000, msec);
  clawOpen(500);
  driveDistR(8,30);
  Lift(-30);
  turnLeft(45,30);
  driveDistR(2,20);*/

  moveLinear(9.5, 100);
  moveStop();
  
  clawOpen(500);
  moveLinear(-8, 100);
  moveStop();
  
  Lift(-30);
  
  moveRotate(-45, 100);
  moveStop();
  moveLinear(-8, 100);
  moveStop();

}

void Auton2(){
  
  liftlMotor.setPosition(0,degrees);
  liftrMotor.setPosition(0,degrees);
  moveLinear(9,100);
  moveStop();
  clawClose(600);
  moveRotate(95, 85);
  moveStop();
  wait(1, sec);
  Lift(-470);
  moveLinear(10, 100);
  moveStop();
  clawOpen(600);
  //put 1 cube in tower okay ^^


  moveLinear(-7.5, 100);
  moveStop();
  Lift(-47); //4 cubes
  moveRotate(-84, 100);
  moveStop();
  moveLinear(18.2,75);
  moveStop();
  clawClose(700);
  
  Lift(-70);
  moveLinear(-26,65);
  moveStop();
  wait(.5,sec);
  moveRotate(-115, 70);
  moveStop();

  
  moveLinear(20,50);
  moveStop();
  Lift(-105);//height for put 4 cubes in corner
  moveLinear(10,45);
  Lift(-63);
  clawOpen(600);
  moveStop();
  moveLinear(-13,100);
  moveStop();
  // above. all good. 1 cube in tower + 4 cubes in corner


  moveRotate(103, 95);
  moveStop();
  moveLinear(25, 90);
  moveStop();
  clawClose(600);
  moveLinear(-3, 90);
  moveStop();
  Lift(-290);
  clawOpen(600);

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