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
void WingsCB() {
  CurrentState = Wings.value();
  Wings.set(!CurrentState);
}

void HangCB() {
  CurrentState = Hang.value();
  Hang.set(!CurrentState);
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

void Turn180() {
  chassis.turn_max_voltage = 12;
  chassis.turn_to_angle(calculateOppositeHeading(chassis.get_absolute_heading()));
}

