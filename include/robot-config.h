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
extern motor Catapult;
extern digital_out IntakeSolenoid;
extern digital_out Wings;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );