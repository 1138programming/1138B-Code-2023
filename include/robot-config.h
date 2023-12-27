#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
inline brain  Brain;

// VEXcode device constructors
inline motor leftFront(18, ratio6_1, true);
inline motor leftMid(19, ratio6_1, true);
inline motor leftBack(20, ratio6_1, true);
inline motor rightFront(11, ratio6_1, false);
inline motor rightMid(12, ratio6_1, false);
inline motor rightBack(13, ratio6_1, false);

inline inertial IMU(15);

// three wire
inline digital_out wings();
inline digital_out balance();
inline digital_out hang();
// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */