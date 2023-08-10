#include "vex.h"
#include "functions.h"
int IntakeOutakeRots = 5;


void IntakeControls::init() {
  Intake.setVelocity(100, percent);
}
void IntakeControls::run() {
  Intake.spinFor(forward, (IntakeOutakeRots * 360), degrees);
}
void IntakeControls::back() {
  Intake.spinFor(reverse, (IntakeOutakeRots * 360), degrees);
}