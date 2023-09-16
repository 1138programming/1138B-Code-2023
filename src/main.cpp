// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial5            inertial      5               
// Controller1          controller                    
// RightBack            motor         3               
// RightFront           motor         4               
// LeftBack             motor         9               
// LeftFront            motor         10              
// Intake               motor         7               
// IntakeSolenoid       digital_out   A               
// Eye                  vision        6               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial5            inertial      5               
// Controller1          controller                    
// RightBack            motor         3               
// RightFront           motor         4               
// LeftBack             motor         9               
// LeftFront            motor         10              
// Intake               motor         7               
// IntakeSolenoid       digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial6            inertial      6               
// Controller1          controller                    
// RightBack            motor         3               
// RightFront           motor         4               
// LeftBack             motor         9               
// LeftFront            motor         10              
// Intake               motor         7               
// IntakeSolenoid       digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "functions.h"
#include "v5lvgl.h"
#include "screen.h"
#include "pagehandler.h"
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial5            inertial      5               
// Controller1          controller                    
// RightBack            motor         3               
// RightFront           motor         4               
// LeftBack             motor         9               
// LeftFront            motor         10              
// Intake               motor         7               
// IntakeSolenoid       digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(LeftFront,LeftBack, LeftTop),

//Right Motors:
motor_group(RightFront,RightBack, RightTop),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT5,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
3.25,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
5,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 1;
bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //v5_lv_init();
  //pageHandler(0);
  LeftFront.setStopping(brake);
  LeftBack.setStopping(brake);
  RightFront.setStopping(brake);
  RightBack.setStopping(brake);
  Catapult.setMaxTorque(100,percent);
  IntakeControls::init();
  default_constants();
}

void autonomous(void) {
  auto_started = true;
  switch(getCurrentAuton()){  
    case 1:
      ThreeBall();
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
  // User control code here, inside the loop
  //pneumatic toggles
    
  bool WingExpand;
  bool CurrentState;
  bool IntakeObject;
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    if (Controller1.ButtonR1.pressing()) {
        Intake.spin(forward,100,percent);
    }
    else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse,100,percent);
    }
    else {
      Intake.stop(coast);
    }
    if (Controller1.ButtonDown.pressing()) {
      Catapult.spin(forward, 75, percent);
    }
    else {
      Catapult.stop(coast);
    }

    //toggles
    Controller1.ButtonL1.pressed(LeftWingCB);
    Controller1.ButtonL2.pressed(RightWingCB);
    Controller1.ButtonRight.pressed(BothWingsCB);
    Controller1.ButtonY.pressed(HangCB);
    Controller1.ButtonDown.pressed(Intake2Wings);

    //debug data
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print(IntakeSensor.isNearObject());
    
    
    
    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    if (WingLeft.value() == false && WingRight.value() == false) {
    chassis.control_arcade();
    }
    else {
      chassis.control_arcade_reverse();
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
