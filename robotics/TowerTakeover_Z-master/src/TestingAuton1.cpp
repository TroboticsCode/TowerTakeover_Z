//crucial that you include the header file that lists the autons

#include "Autons.h"


//name the function and write it out here





void Auton1(){
  liftlMotor.setPosition(0,degrees);
  liftrMotor.setPosition(0,degrees);
  clawClose(600);
  
  Lift(-470);

  driveDist(9.5,30);
  wait(1000, msec);
  clawOpen(500);
  driveDistR(8,30);
  Lift(-30);
  turnLeft(45,30);
  driveDistR(2,20);


 /*


  midtowerPosition();
  clawOpen();

  turnRight(90,50);
  clawOpen(1000);
  Lift(30);
  clawClose(500);
  drive(40,50);
  turnRight(90,50);
  drive(70,50);
  Lift(-30);
  clawOpen(500);
  drive(-20,50);
  turnRight(90,50);
  drive(50,50);
  */


}

void Auton2(){
  
  liftlMotor.setPosition(0,degrees);
  liftrMotor.setPosition(0,degrees);
  clawClose(600);
  
  Lift(-470);
  
  //turnLeft(360,60);
}

void Auton3(){
  clawMotor.spinFor(.5, turns);
  driveDist(40,50);
  wait(20, msec);
  driveDistR(40,50);

}