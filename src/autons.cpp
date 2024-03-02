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
    double deltaX = distance * sin(headingRadians);
    double deltaY = distance * cos(headingRadians);
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
    chassis.follow(dwp1_txt, 10, 3000, false);
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
    chassis.follow(dwp1_txt, 10, 3000, false);
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

void safe3Ball() {
    chassis.setPose(-17,60,90);
    intake.move(127);
    moveRelative(8, 1000);
    chassis.waitUntilDone();   
    chassis.moveToPoint(chassis.getPose().x-31.5, chassis.getPose().y, 2500, {.forwards=false});
    chassis.waitUntilDone();
    chassis.turnToHeading(50, 750, false);
    leftWing.set_value(true);
    pros::delay(250);
    moveRelative(-13.5, 1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(340, 1000, false);
    leftWing.set_value(false);
    chassis.turnToHeading(36, 1000, false);
    chassis.moveToPoint(-60, 22, 1500, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y+10, 750, {.maxSpeed=127});
    chassis.waitUntilDone();
    chassis.turnToHeading(180, 1000, false);
    intake.move(-127);
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y-14, 750, {.maxSpeed=127});
    chassis.waitUntilDone();
    moveRelative(-8, 750);
    chassis.waitUntilDone();
    intake.move(0);
    chassis.turnToHeading(90, 750, false);
    std::cout << chassis.getPose().x << std::endl;
    std::cout << chassis.getPose().y << std::endl;
    std::cout << chassis.getPose().theta << std::endl;

}
ASSET(skill1_txt);
ASSET(skill2_txt);
void skills() {
    chassis.setPose(-40, -54, 90);
    chassis.follow(skill1_txt, 10, 2000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(-56, -46, 1500);
    chassis.turnToHeading(65, 750);
    chassis.waitUntilDone();
    rightWing.set_value(true);
    kicker.move_relative(360*44, 100);
    pros::delay(35000);
    chassis.follow(skill2_txt, 10, 10000, false, false);
    chassis.turnToHeading(270, 750, false);
    rightWing.set_value(true);
    leftWing.set_value(true);
    chassis.moveToPoint(42, chassis.getPose().y, 1500, {.forwards=false});
    chassis.waitUntilDone();
    moveRelative(10, 1000);
    chassis.waitUntilDone();
    moveRelative(-10, 1000);
    chassis.waitUntilDone();
}

void sixBallRush() {
    chassis.setPose(34, -54, 0);
    intake.move(127);
    chassis.moveToPoint(25, -10, 1500);
    chassis.waitUntilDone();
    chassis.moveToPoint(34, -54, 1500, {.forwards=false});
    chassis.waitUntilDone();
    chassis.turnToHeading(45, 750, false);
    intake.move(-127);
    pros::delay(250);
    moveRelative(-6, 750);
    chassis.waitUntilDone();
    intake.move(0);
    chassis.turnToHeading(270, 750, false);
    intake.move(127);
    chassis.moveToPoint(8, -62, 1500);
    chassis.waitUntilDone();
    moveRelative(-37, 2000);
    chassis.waitUntil(10);
    rightWing.set_value(true);
    chassis.waitUntilDone();
    leftWing.set_value(true);
    chassis.turnToHeading(235, 750, false);
    moveRelative(-12, 1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(160, 750, false);
    rightWing.set_value(false);
    chassis.turnToHeading(235, 750, false);
    chassis.moveToPoint(65, -28, 2500, {.forwards=false});
    chassis.waitUntilDone();
    moveRelative(6, 1000);
    chassis.waitUntilDone();
    moveRelative(-8, 1000);
    chassis.waitUntilDone();


}