#include "autons.h"
ASSET(WP0_txt)
void basicWP() {
    chassis.setPose(40.75, 59, 180);
    chassis.follow(WP0_txt, 10, 2000);
    chassis.waitUntilDone();
    intake.move(-127);
    pros::delay(1000);
    intake.move(0);
    chassis.moveToPoint(58, 40, 1000, false, false);
    chassis.turnTo(58, 50, 1500);
    chassis.waitUntilDone();
    chassis.moveToPoint(58, 32, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(58, 40, 1000, false);
}