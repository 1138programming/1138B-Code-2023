#include <cmath> // For sin(), cos(), and M_PI
#include "autons.h"

/**
* @brief Move the robot a relative distance forwards or backwards
*
* @param distance distance to be moved
* @param timeout the timeout duration for the movement
*/
void moveRelative(float distance, int timeout) {
    double headingRadians = chassis.getPose(true).theta;
    double startingX = chassis.getPose().x;
    double startingY = chassis.getPose().y;
    double deltaX = distance * cos(headingRadians);
    double deltaY = distance * sin(headingRadians);
    double newX = startingX + deltaX;
    double newY = startingY + deltaY;
    if (distance > 0) {
        chassis.moveToPoint(newX, newY, timeout, {.forwards=true});
    }
    else if (distance < 0) {
        chassis.moveToPoint(newX, newY, timeout, {.forwards=false});
    }
};

ASSET(dwp1_txt);

void disruptBowl() {
    chassis.setPose(-36,-54,0);
    intake.move(127);
    chassis.moveToPose(-25, -7, 0, 2000, {.lead=0.2});
    chassis.waitUntilDone();
    chassis.follow(dwp1_txt, 10, 2000, false);
    chassis.waitUntilDone();
    // chassis.turnToHeading(180, 750, false);
    // chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y-3, 750);
    // chassis.waitUntilDone();
    chassis.turnToHeading(180-45, 750, false);
    rightWing.set_value(true);
    // pros::delay(500);
    chassis.moveToPoint(chassis.getPose().x+12, chassis.getPose().y-12, 1500);
    chassis.waitUntilDone();
    chassis.turnToHeading(60, 750, false);
    rightWing.set_value(false);
    // pros::delay(500);
    chassis.turnToHeading(90, 750, false);
    chassis.moveToPose(-12, chassis.getPose().y-5, 90, 2500);
    chassis.waitUntil(24);
    intake.move(-127);
    chassis.waitUntilDone();
    intake.move(0);
    chassis.moveToPoint(-50, chassis.getPose().y+3, 2500, {.forwards=false});
}

void disruptWP() {
    chassis.setPose(-36,-54,0);
    intake.move(127);
    chassis.moveToPose(-25, -7, 0, 2000, {.lead=0.2});
    chassis.waitUntilDone();
    chassis.follow(dwp1_txt, 10, 2000, false);
    chassis.waitUntilDone();
    // chassis.turnToHeading(180, 750, false);
    // chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y-3, 750);
    // chassis.waitUntilDone();
    chassis.turnToHeading(180-45, 750, false);
    rightWing.set_value(true);
    pros::delay(500);
    chassis.moveToPoint(chassis.getPose().x+12, chassis.getPose().y-12, 1500);
    chassis.waitUntilDone();
    chassis.turnToHeading(60, 750, false);
    rightWing.set_value(false);
    pros::delay(500);
    chassis.turnToHeading(90, 750, false);
    chassis.moveToPose(-12, chassis.getPose().y-5, 90, 2500);
    chassis.waitUntil(24);
    intake.move(-127);
    chassis.waitUntilDone();
}