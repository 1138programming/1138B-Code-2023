using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial Inertial5;
extern controller Controller1;
extern motor RightBack;
extern motor RightFront;
extern motor LeftBack;
extern motor LeftFront;
extern motor Intake;
extern digital_out IntakeSolenoid;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );