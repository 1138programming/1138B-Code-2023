#include "vex.h"
#include "functions.h"
int IntakeOutakeRots = 5;

void IntakeControls::init() {
  Intake.setVelocity(100, percent);
}
void IntakeControls::run() {
  Intake.spin(forward,100,percent);
}
void IntakeControls::back() {
  Intake.spin(reverse,100,percent);
}
void IntakeControls::stop() {
  Intake.stop();
}