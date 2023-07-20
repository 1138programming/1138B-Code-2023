#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
inertial Inertial5 = inertial(PORT5);
controller Controller1 = controller(primary);
motor RightBack = motor(PORT3, ratio6_1, false);
motor RightFront = motor(PORT4, ratio6_1, false);
motor LeftBack = motor(PORT9, ratio6_1, true);
motor LeftFront = motor(PORT10, ratio6_1, true);
motor Intake = motor(PORT7, ratio6_1, false);
digital_out IntakeSolenoid = digital_out(Brain.ThreeWirePort.A);

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