#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
inertial Inertial5 = inertial(PORT5);
controller Controller1 = controller(primary);
motor RightBack = motor(PORT15, ratio6_1, false);
motor RightFront = motor(PORT14, ratio6_1, false);
motor RightTop = motor(PORT16, ratio6_1, true);
motor LeftBack = motor(PORT12, ratio6_1, true);
motor LeftFront = motor(PORT11, ratio6_1, true);
motor LeftTop = motor(PORT13, ratio6_1, false);
motor Intake = motor(PORT10, ratio6_1, false);
motor  Catapult = motor(PORT8, ratio36_1, true);
optical IntakeSensor = optical(PORT7);
digital_out WingLeft = digital_out(Brain.ThreeWirePort.A);
digital_out WingRight = digital_out(Brain.ThreeWirePort.B);
digital_out Hang = digital_out(Brain.ThreeWirePort.C);
/*vex-vision-config:begin*/
vision Eye = vision (PORT6, 50);
signature Vision5__SIG_1 = signature (1, -6217, -5117, -5667, -5595, -4337, -4966, 2.5, 0);
/*vex-vision-config:end*/

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}