using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern inertial Inertial5;
extern controller Controller1;
extern motor RightBack;
extern motor RightFront;
extern motor RightTop;
extern motor LeftBack;
extern motor LeftFront;
extern motor LeftTop;
extern motor Intake;
extern motor Catapult;
extern optical IntakeSensor;
extern digital_out Wings;
extern digital_out Hang;
extern digital_out Blocker;
extern signature Eye__SIG_1;
extern signature Eye__SIG_2;
extern signature Eye__SIG_3;
extern signature Eye__SIG_4;
extern signature Eye__SIG_5;
extern signature Eye__SIG_6;
extern signature Eye__SIG_7;
extern vision Eye;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );