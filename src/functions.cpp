#include "vex.h"
#include "functions.h"
int IntakeOutakeRots = 5;

void IntakeControls::init() {
  Intake.setVelocity(100, percent);
}
void IntakeControls::run() {
  //make thread that moves the intake
}
void IntakeControls::back() {
  Intake.spin(reverse,100,percent);
}
void IntakeControls::stop() {
  Intake.stop();
}