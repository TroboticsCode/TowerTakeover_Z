#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor clawMotor = motor(PORT18, ratio36_1, false);
motor liftlMotor = motor(PORT5, ratio36_1, true);
motor liftrMotor = motor(PORT4, ratio36_1, false);
limit liftSwitch = Brain.ThreeWirePort.B;
/*motor frontLeft = motor(PORT14, ratio18_1, false);
motor frontRight = motor(PORT13, ratio18_1, true);
motor backLeft = motor(PORT11, ratio18_1, false);
motor backRight = motor(PORT12, ratio18_1, true);*/
// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}