#include "main.h"
#include "autons.h"
void basictestauton() {
  BaseDrive::driveForward(100);
  pros::delay(20);
  BaseDrive::brake();
}