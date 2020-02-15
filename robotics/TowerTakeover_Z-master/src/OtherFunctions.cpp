#include "Functions.h"

void Lift(int liftTarget){
  liftlMotor.setStopping(hold);
  liftlMotor.spinToPosition(liftTarget,degrees,false);
  while(!liftrMotor.spinToPosition(liftTarget, degrees, false))
  {}
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

  