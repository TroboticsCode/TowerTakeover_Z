/********************************************************************
 *    DriveFunctions.cpp
 * This is where all the drive code lives for user and auton
 * Make sure you have done all the configs in DriveFunctionsConfig.h
 *******************************************************************/

#include "DriveFunctionsConfig.h"
using namespace vex;

#ifdef CHASSIS_4_MOTOR_INLINE
  motor frontLeft = motor(FrontLeftPort, GEAR_SET, false);
  motor backLeft = motor(BackLeftPort, GEAR_SET, false);
  motor frontRight = motor(FrontRightPort, GEAR_SET, true);
  motor backRight = motor(BackRightPort, GEAR_SET, true);

#elif defined(CHASSIS_2_MOTOR_INLINE)
  motor DriveLeft = motor(DriveLeftPort, GEAR_SET, false);
  motor DriveRight = motor(DriveRightPort, GEAR_SET, true);

#elif defined(CHASSIS_X_DRIVE)
  //coming soon!
#endif

#ifdef GYRO
  inertial myGyro = inertial(GYRO_PORT);
#endif

/**************************************************
 * @brief: moves the robot forward or back
 *    at a given speed
 *
 * @param distance: how far to move in inches, absolute value
 * @param velocity: how fast to move, signed value
 *                  sign determines direction
 **************************************************/
void moveLinear(float distance, int velocity)
{
  float rotations = distance * (1/((float)ROTATION_FACTOR));
  Brain.Screen.print("Rotations to turn: %f", rotations);
  Brain.Screen.newLine();
  Brain.Screen.print("Rotation Factor: %f", ROTATION_FACTOR);
  wait(1, sec);

#if defined(PID)
  float DriveR_Power = 0;
  float DriveL_Power = 0;

  pidStruct_t driveL_PID;
  pidStruct_t driveR_PID;

  pidInit(&driveL_PID, 60, 0, 10, 10, 20);
  pidInit(&driveR_PID, 60, 0, 10, 10, 20);

  #if defined (CHASSIS_2_MOTOR_INLINE)
    DriveRight.resetRotation();
    DriveLeft.resetRotation();
  #elif defined(CHASSIS_4_MOTOR_INLINE)
    frontLeft.resetRotation();
    frontRight.resetRotation();
    backLeft.resetRotation();
    backRight.resetRotation();
  #endif
 
  printPIDValues(&driveR_PID);

  do
  {
    #if defined (CHASSIS_2_MOTOR_INLINE)
      printPIDValues(&driveR_PID);
      DriveR_Power = (velocity/100.0f) * pidCalculate(&driveR_PID, rotations, DriveRight.rotation(rev));
      DriveL_Power = (velocity/100.0f) * pidCalculate(&driveL_PID, rotations, DriveLeft.rotation(rev));

      DriveRight.spin(forward, DriveR_Power, pct);
      DriveLeft.spin(forward, DriveL_Power, pct);

    #elif defined (CHASSIS_4_MOTOR_INLINE)
      DriveR_Power = (velocity/100.0f) * pidCalculate(&driveR_PID, rotations, backRight.rotation(rev));
      DriveL_Power = (velocity/100.0f) * pidCalculate(&driveL_PID, rotations, backLeft.rotation(rev));

      frontRight.spin(forward, DriveR_Power, pct);
      frontLeft.spin(forward, DriveL_Power, pct);
      backLeft.spin(forward, DriveL_Power, pct);
      backRight.spin(forward, DriveR_Power, pct);
    #endif
    
  }while(fabs(driveR_PID.avgError) > 0.07 || fabs(driveL_PID.avgError) > 0.07);

#elif !defined (PID)
  #if defined (CHASSIS_2_MOTOR_INLINE)
    DriveRight.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    DriveLeft.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
  #elif defined (CHASSIS_4_MOTOR_INLINE)
    frontLeft.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    backLeft.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    frontRight.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    backRight.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
  #endif
#endif
}


void moveStop(void)
{
#ifdef CHASSIS_4_MOTOR_INLINE
  frontLeft.stop();
  backLeft.stop();
  frontRight.stop();
  backRight.stop();

#elif defined(CHASSIS_2_MOTOR_INLINE)
  DriveRight.stop(brakeType::hold);
  DriveLeft.stop(brakeType::hold);
#endif
}


void moveRotate(int16_t degrees, int velocity)
{
  float arcLength = (degrees/360.0f) * CIRCUMFERENCE;
  float rotFactor = ROTATION_FACTOR;
  float rotations = arcLength / rotFactor;

  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("rotations: %f", rotations);
  Brain.Screen.newLine();
  Brain.Screen.print("arc length: %f", arcLength);
  Brain.Screen.newLine();
  Brain.Screen.print("Hyp: %f", HYPOTENUSE);
  Brain.Screen.newLine();
  Brain.Screen.print("Circ: %f", CIRCUMFERENCE);
  Brain.Screen.newLine();
  Brain.Screen.print("rotations factor: %f", ROTATION_FACTOR);
  
  wait(1, sec);

#if defined(PID) 
  #ifdef GYRO
    myGyro.calibrate();
    while(myGyro.isCalibrating());
    myGyro.resetRotation();
  #endif

  #ifdef CHASSIS_2_MOTOR_INLINE
    DriveLeft.resetRotation();
    DriveRight.resetRotation();
  #elif defined CHASSIS_4_MOTOR_INLINE
    frontLeft.resetRotation();
    frontRight.resetRotation();
    backLeft.resetRotation();
    backRight.resetRotation();
  #endif

  #if !defined GYRO
    pidStruct_t rotateR_PID;
    pidStruct_t rotateL_PID;

    pidInit(&rotateR_PID, 55, 0, 7, 7, 10);
    pidInit(&rotateL_PID, 55, 0, 7, 7, 10);

    float DriveR_Power = 0;
    float DriveL_Power = 0;

  #elif defined GYRO
    pidStruct_t rotatePID;
    pidInit(&rotatePID, 2, 0, 0.8, 30, 10);

    float motorPower = 0;
  #endif

  do
  {
  #if defined (GYRO)
    motorPower = (velocity/100.0f) * pidCalculate(&rotatePID, degrees, myGyro.rotation(rotationUnits::deg));
  #elif !defined (GYRO)
    #ifdef CHASSIS_4_MOTOR_INLINE
      DriveL_Power = (velocity/100.0f) * pidCalculate(&rotateL_PID, rotations, backLeft.rotation(rev));
      DriveR_Power = (velocity/100.0f) * pidCalculate(&rotateR_PID, rotations, -1.0f * backRight.rotation(rev));
    #elif defined CHASSIS_2_MOTOR_INLINE
      DriveL_Power = (velocity/100.0f) * pidCalculate(&rotateL_PID, rotations, DriveLeft.rotation(rev));
      DriveR_Power = (velocity/100.0f) * pidCalculate(&rotateR_PID, rotations, -1.0f * DriveRight.rotation(rev));
    #endif
  #endif

  #if defined (GYRO)
    printPIDValues(&rotatePID);
    #ifdef CHASSIS_4_MOTOR_INLINE
      frontRight.spin(forward, motorPower, pct);
      frontLeft.spin(reverse, motorPower, pct);
      backRight.spin(forward, motorPower, pct);
      backLeft.spin(reverse, motorPower, pct);

    #elif defined CHASSIS_2_MOTOR_INLINE
      DriveRight.spin(reverse, motorPower, pct);
      DriveLeft.spin(forward, motorPower, pct);
    #endif

  #else 
    printPIDValues(&rotateR_PID);
    #ifdef CHASSIS_4_MOTOR_INLINE
      frontRight.spin(reverse, DriveR_Power, pct);
      frontLeft.spin(forward, DriveL_Power, pct);
      backRight.spin(reverse, DriveR_Power, pct);
      backLeft.spin(forward, DriveL_Power, pct);

    #elif defined CHASSIS_2_MOTOR_INLINE
      DriveRight.spin(reverse, DriveR_Power, pct);
      DriveLeft.spin(forward, DriveL_Power, pct);
    #endif
  #endif

  wait(10, msec);

  #if defined GYRO
  }while(fabs(rotatePID.avgError) > 0.8); //error in degrees
  #elif !defined GYRO
  }while(fabs(rotateR_PID.avgError) > 0.05 || fabs(rotateL_PID.avgError) > 0.5); //error in units of revs
  #endif
  //end do-while

#elif !defined(PID) && !defined(GYRO)
  #ifdef CHASSIS_4_MOTOR_INLINE
    frontLeft.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    backLeft.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    frontRight.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    backRight.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);

  #elif defined CHASSIS_2_MOTOR_INLINE
    DriveRight.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
    DriveLeft.rotateFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct, false);
  #endif
#endif
}