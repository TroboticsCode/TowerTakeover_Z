/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ClawMotor            motor         3               
// Tester1              motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Autons.h"
#include "Functions.h"

using namespace vex;


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Controller1.ButtonR1.pressed(cycle_autons);
  Brain.Screen.pressed(cycle_autons);
  return;
}

void autonomous(void) 
{
 switch (state)
  {
    case NONE:
    break;

    case AutonR:    
      Auton1();
    break;

    case AutonB:
      
    break;
          
    // Default = NO autonomous
    default:
    break;
  }
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  wait(2,seconds);

  //add local user control variables here:
  int liftPower;
  int leftPower;
  int rightPower;

  //User control code here, inside the loop:

  while (1) {
    liftPower = Controller1.Axis3.position(percent);
    liftMotor.setVelocity(liftPower, pct);
    liftMotor.spin(fwd);

    leftPower = (Controller1.Axis2.position(percent) + Controller1.Axis1.position(percent));
    rightPower = (Controller1.Axis2.position(percent) - Controller1.Axis1.position(percent));
    frontLeft.setVelocity(leftPower,pct);
    backLeft.setVelocity(leftPower,pct);
    frontLeft.setVelocity(rightPower,pct);
    backLeft.setVelocity(rightPower,pct);

    frontLeft.spin(fwd);
    backLeft.spin(fwd);
    frontRight.spin(fwd);
    backRight.spin(fwd);
    
    clawMotor.setVelocity(50, pct);
    if(Controller1.ButtonL2.pressing())
    {
      clawMotor.spin(fwd);
    }
    else if (Controller1.ButtonL1.pressing())
    {
      clawMotor.spin(reverse);
    }
    else 
    {
      clawMotor.stop();
    }



    wait(20, msec); // Sleep the task for a short amount of time to
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
