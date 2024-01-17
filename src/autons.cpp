#include "autons.h"
ASSET(example_txt);
ASSET(WP0_txt);
ASSET(WP1_txt);

void basicWP() {
    chassis.setPose(48, 58, 315);
    chassis.follow(WP0_txt, 15, 2000, false);
    chassis.waitUntilDone();
    chassis.follow(WP1_txt, 15, 5000);
    chassis.waitUntil(10);
    //wings.set_value(true);
    chassis.waitUntil(30);
    //wings.set_value(false);

}
ASSET(WPD1_txt);
ASSET(WPD2_txt);
ASSET(WPD3_txt);
void disrupt() {
    chassis.setPose(30.484, 52.889, 180);
    chassis.follow(WPD1_txt, 10, 5000);
    chassis.waitUntil(30);
    intake.move(127);
    //wings.set_value(true);
    chassis.waitUntil(55);
    intake.move(-127);
    chassis.waitUntilDone();
    chassis.follow(WPD2_txt, 10, 5000, false);
    chassis.waitUntil(5);
    intake.brake();
    //wings.set_value(false);
    chassis.waitUntilDone();

}

void sixBall() {
    chassis.setPose(-36, 54.25, 180);
    intake.move(127);
    chassis.moveToPoint(-5.75, 2, 2000);
    chassis.waitUntilDone();
    chassis.turnTo(-40, 6, 500);
    chassis.waitUntilDone();
    //wings.set_value(true);
    pros::delay(100);
    intake.move(0);
    chassis.moveToPoint(-46, 6, 1500);
    chassis.waitUntilDone();
    chassis.moveToPoint(-40, chassis.getPose().y, 1000, false);
    //wings.set_value(false);
    chassis.waitUntilDone();
    chassis.turnTo(-9, 27.5, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-9, 27.5, 1500);
    intake.move(127);
    chassis.waitUntilDone();
    chassis.turnTo(-40, 0, 1000);
    chassis.waitUntilDone();
    chassis.moveToPose(-46,0,270, 1500, true, 8);
    pros::delay(750);
    intake.move(-127);
    //wings.set_value(true);
    chassis.waitUntilDone();
    intake.move(0);
    //wings.set_value(false);
    chassis.moveToPoint(-40, 0, 1000, false);
    chassis.waitUntilDone();
    chassis.turnTo(-48, 48, 750);
    chassis.waitUntilDone();
    chassis.moveToPose(-56, 45, 305, 2500);
    intake.move(127);
    chassis.waitUntilDone();
    chassis.turnTo(-66, 30, 750);
    chassis.waitUntilDone();
    intake.move(0);
    chassis.moveToPose(-68, 15, 180, 2500);
    pros::delay(250);
    intake.move(0);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.moveToPoint(chassis.getPose().x, (chassis.getPose().y+12), 1000, false);
    chassis.waitUntilDone();
    intake.move(0);
}

void pidTest() {
    chassis.setPose(0,0,0);
    chassis.turnTo(-10, 0, 2500);
    chassis.waitUntilDone();
    chassis.turnTo(0,10,2500);
    chassis.waitUntilDone();
    master.rumble(". . .");
}

void fiveBall() {
    chassis.setPose(-36, 54.25, 180);
    intake.move(127);
    chassis.moveToPoint(-5, 2, 2000);
    chassis.waitUntilDone();
    chassis.turnTo(-40, 2, 500);
    chassis.waitUntilDone();
    //wings.set_value(true);
    pros::delay(100);
    intake.move(0);
    chassis.moveToPoint(-46, 0, 1500);
    chassis.waitUntilDone();
    chassis.moveToPoint(-40, 2, 750, false);
    //wings.set_value(false);
    chassis.waitUntilDone();
    chassis.turnTo(-5, 30, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-6.5, 30, 2500);
    intake.move(127);
    chassis.waitUntilDone();
    chassis.turnTo(-40, 0, 1000);
    chassis.waitUntilDone();
    chassis.moveToPose(-46,0,270, 2500, true, 8);
    pros::delay(500);
    intake.move(-127);
    //wings.set_value(true);
    chassis.waitUntilDone();
    intake.move(0);
    //wings.set_value(false);
    chassis.moveToPoint(-40, 0, 1000, false);
    chassis.waitUntilDone();
}
ASSET(s1_txt);
void safeTwo() {
    chassis.setPose(-35, 59, 90);
    chassis.waitUntilDone();
    intake.move(127);
    chassis.moveToPoint(-6.75, 59, 1000);
    chassis.waitUntilDone();
    chassis.follow(s1_txt, 10, 2000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, 32, 1000);
    chassis.waitUntilDone();
    chassis.turnTo(-60, 0, 750);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.moveToPoint(-60, 25, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-60, 32, 1000, false);
    chassis.waitUntilDone();
    intake.move(0);
}

ASSET(AWP1_txt);
ASSET(AWP2_txt);
void betterWP() {
    chassis.setPose(-34,-59,0);
    descore.set_value(true);
    pros::delay(700);
    descore.set_value(false);
    pros::delay(250);
    intake.move(127);
    lateralController.slew = 25;
    chassis.moveToPoint(-24, -8.5, 3000, true, 127);
    chassis.waitUntilDone();
    lateralController.slew = 5;
    pros::delay(1000);
    chassis.moveToPoint(chassis.getPose().x, (chassis.getPose().y-18), 750, false);
    chassis.waitUntilDone();
    chassis.turnTo((chassis.getPose().x+25), chassis.getPose().y, 750);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.moveToPoint((chassis.getPose().x+18), chassis.getPose().y, 1500);
    chassis.waitUntilDone();
    pros::delay(750);
    intake.move(0);
    chassis.follow(AWP1_txt, 10, 3000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y+5, 750, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y-10, 1000);
    chassis.waitUntilDone();
    chassis.turnTo(chassis.getPose().x, chassis.getPose().y-7.5, 750, false);
    chassis.waitUntilDone();
    chassis.moveToPose(-56,-55, 315, 1000, false);
    chassis.waitUntilDone();
    descore.set_value(true);
    pros::delay(250);
    chassis.moveToPose(-35, -59, 270, 1500, false);
    chassis.waitUntilDone();
    chassis.moveToPose(chassis.getPose().x+28, chassis.getPose().y, 265, 2500, false);
    chassis.waitUntilDone();
    descore.set_value(false);
}