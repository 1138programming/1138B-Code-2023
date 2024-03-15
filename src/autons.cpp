#include <cmath> // For sin(), cos(), and M_PI
#include "autons.h"
#include "devices.h"
#include "lemlib/asset.hpp"
#include "pros/rtos.hpp"

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

void moveVoltage(float leftPower, float rightPower, float duration) {
    left_side.move(leftPower);
    right_side.move(rightPower);
    pros::delay(duration);
    left_side.move(0);
    right_side.move(0);
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
ASSET(sixball1_txt);
ASSET(sixball2_txt);
void sixBallRush() {
    float startTime = pros::millis();
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
    chassis.follow(sixball2_txt, 10, 2000, false);
    chassis.waitUntil(6);
    rightWing.set_value(true);
    chassis.waitUntilDone();
    // chassis.turnToHeading(235, 500, false);
    // moveRelative(-10, 1000);
    // chassis.waitUntilDone();
    // chassis.turnToHeading(160, 750, false);
    // leftWing.set_value(false);
    // chassis.turnToHeading(235, 650, false);
    // chassis.moveToPose(68, -24, 180, 1250, {.forwards=false, .chasePower=20, .maxSpeed=127});
    // chassis.waitUntilDone();
    // moveRelative(6, 500);
    // chassis.waitUntilDone();
    // moveRelative(-8, 750);
    // chassis.waitUntilDone();
    moveRelative(10, 750);
    chassis.waitUntilDone();
    rightWing.set_value(false);
    chassis.turnToHeading(300, 750, false);
    moveRelative(28, 750);
    chassis.waitUntilDone();
    intake.move(-127);
    chassis.turnToHeading(40, 750, false);
    chassis.waitUntilDone();
    pros::delay(250);
    chassis.turnToHeading(270, 500, false);
    intake.move(127);
    moveRelative(18, 750);
    chassis.waitUntilDone();
    moveRelative(-6, 500);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 500, false);
    chassis.follow(sixball1_txt, 10, 1500);
    chassis.waitUntil(30);
    intake.move(-127);
    chassis.waitUntilDone();
    intake.move(0);
    moveRelative(-10, 750);
    chassis.turnToHeading(270, 750, false);
    intake.move(127);
    moveRelative(40, 750);
    chassis.waitUntilDone();
    std::cout << chassis.getPose().x << std::endl;
    std::cout << chassis.getPose().y << std::endl;
    std::cout << chassis.getPose().theta << std::endl;
    float endTime = pros::millis();
    float totalTime = endTime - startTime;
    std::cout << totalTime << std::endl;
    master.print(0,0,"%f", totalTime);

}
ASSET(fiveball1_txt);
void FiveBall() {
    float startTime = pros::millis();
    chassis.setPose(34, -54, 0);
    intake.move(-127);
    chassis.moveToPoint(25, -10, 1500);
    chassis.waitUntil(2);
    intake.move(127);
    chassis.waitUntilDone();
    chassis.moveToPoint(34, -55, 1500, {.forwards=false});
    chassis.waitUntilDone();
    chassis.turnToHeading(75, 350, false);
    intake.move(-127);
    chassis.turnToHeading(90, 350, false);
    moveRelative(8, 750);
    chassis.waitUntilDone();
    chassis.turnToHeading(60, 500, false);
    moveRelative(16, 750);
    chassis.waitUntil(3);
    rightWing.set_value(true);
    chassis.waitUntilDone();
    intake.move(0);
    chassis.turnToHeading(0, 750, false);
    rightWing.set_value(false);
    chassis.waitUntilDone();
    chassis.turnToHeading(225, 750, true);
    chassis.follow(fiveball1_txt, 10, 850, false);
    rightWing.set_value(true);
    chassis.waitUntilDone();
    moveVoltage(-127, -127, 500);
    std::cout << chassis.getPose().x << std::endl;
    std::cout << chassis.getPose().y << std::endl;
    std::cout << chassis.getPose().theta << std::endl;
    moveRelative(8, 750);
    chassis.waitUntilDone();
    rightWing.set_value(false);
    chassis.turnToHeading(270, 750, false);
    chassis.moveToPoint(11, -22, 1250);
    intake.move(127);
    chassis.waitUntilDone();
    moveRelative(-6, 750);
    chassis.turnToHeading(65, 500, false);
    moveRelative(19, 750);
    chassis.waitUntilDone();
    intake.move(-127);
    pros::delay(250);
    chassis.moveToPoint(10, -3, 750);
    chassis.waitUntilDone();
    intake.move(127);
    moveRelative(-6, 500);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 750, false);
    intake.move(-127);
    moveVoltage(127, 127, 500);
    moveRelative(-6, 500);
    chassis.waitUntilDone();
    std::cout << chassis.getPose().x << std::endl;
    std::cout << chassis.getPose().y << std::endl;
    std::cout << chassis.getPose().theta << std::endl;
    float endTime = pros::millis();
    float totalTime = endTime - startTime;
    std::cout << totalTime << std::endl;
    master.print(0,0,"%f", totalTime);

}
ASSET(skillsroute2_txt);
ASSET(skillsroute3_txt);
void skills() {
    float startTime = pros::millis();
    chassis.setPose(-50, -58, 135);
    chassis.moveToPoint(-58, -24, 750, {.forwards=false});
    chassis.waitUntilDone();
    moveVoltage(-127, -127, 500);
    chassis.setPose(-58, -30, 185);
    chassis.moveToPoint(-53, -50, 1000);  
    chassis.waitUntilDone();
    chassis.turnToHeading(72, 750, false);
    moveRelative(-3, 750);
    chassis.waitUntilDone();
    rightWing.set_value(true);
    kicker.tare_position();
    int runCount = 46;
    kicker.move_relative(runCount*360, 127);
    while (!((kicker.get_position() < ((runCount*360) + 5)) && (kicker.get_position() > ((runCount*360) - 5)))) {
    // Continue running this loop as long as the motor is not within +-5 units of its goal
    pros::delay(2);
    }
    rightWing.set_value(false);
    chassis.follow(skillsroute2_txt, 10, 2500);
    chassis.waitUntilDone();
    chassis.turnToHeading(225, 750, false);
    rightWing.set_value(true);
    chassis.moveToPoint(64, -26, 750, {.forwards=false});
    chassis.waitUntilDone();
    moveRelative(8, 750);
    chassis.waitUntilDone();
    moveVoltage(-127, -127, 750);
    chassis.setPose(62.5, -32, 180);
    moveRelative(6, 750);
    chassis.waitUntilDone();
    rightWing.set_value(false);
    chassis.turnToHeading(90, 1000, false);
    chassis.follow(skillsroute3_txt, 10, 5000, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 750, false);
    rightWing.set_value(true);
    leftWing.set_value(true);
    moveVoltage(-127, -127, 1250);
    moveRelative(6, 750);
    chassis.waitUntilDone();
    moveVoltage(-127, -127, 750);
    std::cout << chassis.getPose().x << std::endl;
    std::cout << chassis.getPose().y << std::endl;
    std::cout << chassis.getPose().theta << std::endl;
    float endTime = pros::millis();
    float totalTime = endTime - startTime;
    std::cout << totalTime << std::endl;
    master.print(0,0,"%f", totalTime);
}

void pidTest() {
    new_constants();
    chassis.setPose(0,0,0);
    moveRelative(24, 2500);
    chassis.waitUntilDone();
    moveRelative(-24, 2500);
    chassis.waitUntilDone();
}