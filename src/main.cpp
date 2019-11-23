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
      Auton2();
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
  Auton1();

  wait(2,seconds);

  Auton2();
  //add local user control variables here:
  int power;
  //User control code here, inside the loop:

  while (1) {
    power = Controller1.Axis1.position(percent)+Controller1.Axis2.position(percent);
    ClawMotor.setVelocity(power, pct);
    ClawMotor.spin(reverse);
    Controller1.ButtonY.pressed(autonomous);

    if (Controller1.ButtonA.pressing())
    {
      Tester1.spin(forward);
    }

    else if (Controller1.ButtonB.pressing())
    {
      Tester1.spin(reverse);
    }

    else
    {
      Tester1.stop();
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