#include "vex.h"
#include "functions.h"
bool IntakeState = true;
int IntakeOutakeRevs = (360*4);
void IntakeSolenoidUp(void) {
  IntakeSolenoid.set(true);
}
void IntakeSolenoidDown(void) {
  IntakeSolenoid.set(false);
}
void IntakeCommands::Run() {
  Intake.spinFor(forward, IntakeOutakeRevs, degrees); //intake the preload
}
void IntakeCommands::Reverse() {
  Intake.spinFor(reverse,IntakeOutakeRevs, degrees);
}