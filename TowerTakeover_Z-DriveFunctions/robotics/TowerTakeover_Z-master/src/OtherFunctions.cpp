#include "Functions.h"

void Lift(int liftTarget){
  liftlMotor.setVelocity(50, percent);
  liftrMotor.setVelocity(50, percent);

  liftlMotor.setStopping(hold);
  liftlMotor.spinToPosition(liftTarget,degrees,false);
  liftrMotor.spinToPosition(liftTarget, degrees, true);
  
  /*liftlMotor.stop();
  liftrMotor.stop();*/
  Brain.Screen.print(liftlMotor.position(degrees));

}
//the claw
void clawOpen(int clawTarget){
  clawMotor.setVelocity(100, percent);
  clawMotor.setStopping(hold);
  clawMotor.spin(reverse);
  wait(clawTarget, msec);
  clawMotor.stop();
}
void clawClose(int clawTarget){
  clawMotor.setVelocity(100, percent);
  clawMotor.setStopping(hold);
  clawMotor.spin(forward);
  wait(clawTarget, msec);
  //clawMotor.stop();
}

  