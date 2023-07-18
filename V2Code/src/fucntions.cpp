#include "vex.h"
#include "functions.h"
bool IntakeState = true;
void IntakeSolenoidUp(void) {
  IntakeSolenoid.set(true);
}
void IntakeSolenoidDown(void) {
  IntakeSolenoid.set(false);
}