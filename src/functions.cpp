#include "vex.h"
#include "functions.h"
bool CurrentState;
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
void RightWingCB() {
  CurrentState = WingRight.value();
  WingRight.set(!CurrentState);
}
void LeftWingCB() {
  CurrentState = WingLeft.value();
  WingLeft.set(!CurrentState);
}
void BothWingsCB() {
  RightWingCB();
  LeftWingCB();
}
void HangCB() {
  CurrentState = Hang.value();
  Hang.set(!CurrentState);
}

//macros
float calculateTurnHeading(float currentHeading) {
    // Ensure that currentHeading is within the range [0, 360)
    currentHeading = fmod(currentHeading, 360.0);

    // Calculate the heading to turn to for 180-degree reversal
    float turnHeading = currentHeading + 180.0;

    // Ensure the result is within the range [0, 360)
    if (turnHeading >= 360.0) {
        turnHeading -= 360.0;
    }

    return turnHeading;
}

void Intake2Wings() {
  IntakeControls::back();
  chassis.turn_max_voltage = 12;
  chassis.turn_to_angle(calculateTurnHeading(chassis.get_absolute_heading()));
  BothWingsCB();
}