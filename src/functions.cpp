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
void IntakeControls::stop() {
  Intake.stop();
}
// void WingsCB() {
//   CurrentState = Wings.value();
//   Wings.set(!CurrentState);
// }

void HangCB() {
  CurrentState = Hang.value();
  Hang.set(!CurrentState);
}
void BlockerCB() {
  CurrentState = Blocker.value();
  Blocker.set(!CurrentState);
}

//macros
float calculateOppositeHeading(float currentHeading) {
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
float calculateRelativeHeading(float currentHeading, float turn) {
    // Ensure that currentHeading is within the range [0, 360)
    currentHeading = fmod(currentHeading, 360.0);

    // Calculate the heading to turn to for 180-degree reversal
    float turnHeading = currentHeading + turn;

    // Ensure the result is within the range [0, 360)
    if (turnHeading >= 360.0) {
        turnHeading -= 360.0;
    }

    return turnHeading;
}

void Turn180() {
  chassis.turn_max_voltage = 12;
  chassis.turn_to_angle(calculateOppositeHeading(chassis.get_absolute_heading()));
}
void turnrelativeangle(float angle) {
  chassis.turn_max_voltage = 12;
  chassis.turn_to_angle(calculateRelativeHeading(chassis.get_absolute_heading(),angle));
}

float getBaseTempAvg() {
  float tLtemp = LeftTop.temperature();
  float bLtemp = LeftBack.temperature();
  float fLtemp = LeftFront.temperature();
  float tRtemp = RightTop.temperature();
  float bRtemp = RightBack.temperature();
  float fRtemp = RightBack.temperature();

  float tempAvg = ((tLtemp + bLtemp + fLtemp + tRtemp + bRtemp + fRtemp) / 6);
  return tempAvg;
}
