#include "vex.h"
#include "autons.h"
#include "functions.h"
void BasicAuton() {
  repeat(4) {
  Drivetrain.driveFor(forward, 5, inches); //drive forward
  Drivetrain.driveFor(reverse,1, inches); //back up a little
  Drivetrain.turnFor(left, 90, degrees); //turn
  }
  Drivetrain.stop();
}
void ThreeBall() {
  Drivetrain.setDriveVelocity(50,percent);
  Drivetrain.setTurnVelocity(5,percent);
  IntakeSolenoid.set(true); // raise intake for inspection
  wait(5,sec); //place ball
  IntakeSolenoid.set(false); //lower intake
  IntakeCommands::Run(); //intake the preload
  wait(1, sec);
  Drivetrain.driveFor(forward,58, inches);//take preload to the goal
  Drivetrain.turnFor(right, 90, degrees); //turn to the goal
  Drivetrain.driveFor(forward, 3, inches); // move into the goal
  IntakeCommands::Reverse(); //outtake
  Drivetrain.driveFor(reverse, 3, inches); // back up
  Drivetrain.turnFor(left,175, degrees);
  Drivetrain.driveFor(forward, 10, inches);
  IntakeCommands::Run();
  Drivetrain.turnFor(left,180,degrees);
  Drivetrain.driveFor(forward,10,inches);
  Drivetrain.turnFor(left,5, degrees);
  Drivetrain.driveFor(forward,3,inches);
  IntakeCommands::Reverse();
}