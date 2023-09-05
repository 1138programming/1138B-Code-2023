#include "vex.h"
#include "callbacks.h"
void MechsCallback() {
    while (1) {
        if (Controller1.ButtonR1.pressing()) {
            Intake.spin(forward,100,percent);
        }
        else if (Controller1.ButtonR2.pressing()) {
          Intake.spin(reverse,100,percent);
        }
        else {
          Intake.stop(coast);
        }
        if (Controller1.ButtonY.pressing()) {
          IntakeSolenoid.set(true);
        }
        else if (Controller1.ButtonB.pressing()) {
          IntakeSolenoid.set(false);
        }
        if (Controller1.ButtonDown.pressing()) {
          Catapult.spin(forward, 40, percent);
        }
        else {
          Catapult.stop(coast);
        }
        if (Controller1.ButtonL1.pressing()) {
          Wings.set(true);
        }
        else if (Controller1.ButtonL2.pressing()) {
          Wings.set(false);
        }
    }
}