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

void old_constants() {
    //lateral constants
    lateralController.kP = 19;
    lateralController.kI = 0; 
    lateralController.kD = 85;
    lateralController.windupRange = 3;
    lateralController.smallError = 1;
    lateralController.smallErrorTimeout = 100;
    lateralController.largeError = 3;
    lateralController.largeErrorTimeout = 500;
    lateralController.slew = 10;
    //angular constants
    angularController.kP = 1.4;
    angularController.kI = 0; 
    angularController.kD = 5;
    angularController.windupRange = 3;
    angularController.smallError = 1;
    angularController.smallErrorTimeout = 100;
    angularController.largeError = 3;
    angularController.largeErrorTimeout = 500;
    angularController.slew = 5;
}

void new_constants() {
    //lateral constants
    lateralController.kP = 100;
    lateralController.kI = 0; 
    lateralController.kD = 0;
    lateralController.windupRange = 3;
    lateralController.smallError = 1;
    lateralController.smallErrorTimeout = 100;
    lateralController.largeError = 3;
    lateralController.largeErrorTimeout = 500;
    lateralController.slew = 0;
    //angular constants
    angularController.kP = 1.4;
    angularController.kI = 0; 
    angularController.kD = 5;
    angularController.windupRange = 3;
    angularController.smallError = 1;
    angularController.smallErrorTimeout = 100;
    angularController.largeError = 3;
    angularController.largeErrorTimeout = 500;
    angularController.slew = 5;
}

ASSET(dwp1_txt);

void disruptBowl() {
    old_constants();
    chassis.setPose(-36,-54,0);
    intake.move(-127);
    chassis.moveToPose(-25, -7, 0, 2000, {.lead=0.2});
    chassis.waitUntil(2);
    intake.move(127);
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
    old_constants;
    chassis.setPose(-36,-54,0);
    intake.move(-127);
    chassis.moveToPose(-25, -7, 0, 2000, {.lead=0.2});
    chassis.waitUntil(2);
    intake.move(127);
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

void sixBallRush() {
    float startTime = pros::millis();
    lateralController.slew = 0;
    angularController.slew = 0;
    chassis.setPose(34, -54, 0);
    intake.move(-127);
    chassis.moveToPoint(25, -10, 1500);
    chassis.waitUntil(2);
    intake.move(127);
    chassis.waitUntilDone();
    chassis.moveToPoint(34, -55, 1500, {.forwards=false});
    chassis.waitUntilDone();
    chassis.turnToHeading(45, 500, false);
    intake.move(-127);
    pros::delay(250);
    // moveRelative(-6, 500);
    // chassis.waitUntilDone();
    chassis.turnToHeading(270, 750, false);
    intake.move(127);
    chassis.moveToPoint(8, -60, 1500);
    chassis.waitUntilDone();
    moveRelative(-37, 750);
    chassis.waitUntil(6);
    rightWing.set_value(true);
    chassis.waitUntilDone();
    leftWing.set_value(true);
    chassis.turnToHeading(235, 500, false);
    moveRelative(-12, 1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(160, 750, false);
    leftWing.set_value(false);
    chassis.turnToHeading(235, 650, false);
    std::cout << chassis.getPose().x << std::endl;
    std::cout << chassis.getPose().y << std::endl;
    std::cout << chassis.getPose().theta << std::endl;
    chassis.moveToPose(68, -24, 180, 1250, {.forwards=false, .chasePower=18, .maxSpeed=127});
    chassis.waitUntilDone();
    // moveRelative(6, 500);
    // chassis.waitUntilDone();
    // moveRelative(-8, 750);
    // chassis.waitUntilDone();
    moveRelative(6, 500);
    chassis.waitUntilDone();
    rightWing.set_value(false);
    chassis.turnToHeading(270, 750, false);
    moveRelative(28, 750);
    chassis.waitUntilDone();
    chassis.turnToHeading(30, 750, false);
    intake.move(-127);
    chassis.waitUntilDone();
    pros::delay(250);
    chassis.turnToHeading(315, 500, false);
    intake.move(127);
    moveRelative(18, 750);
    chassis.waitUntilDone();
    moveRelative(-6, 500);
    chassis.waitUntilDone();
    float endTime = pros::millis();
    float totalTime = endTime - startTime;
    std::cout << totalTime << std::endl;
    master.print(0,0,"%f", totalTime);


}

void pidTest() {
    new_constants();
    chassis.setPose(0,0,0);
    chassis.turnToHeading(180, 2500);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 2500);
    chassis.waitUntilDone();
}