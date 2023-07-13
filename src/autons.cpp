#include "main.h"
#include "autons.h"
void basictestauton() {
  BaseDrive::driveDistance(100, 100);
  pros::delay(20);
  BaseDrive::brake();
}