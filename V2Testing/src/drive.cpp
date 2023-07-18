#include "vex.h"
#include "drive.h"
#include "constants.h"

vex::motor right_front(4, vex::ratio6_1);
vex::motor rightBack(3, vex::ratio6_1);
vex::motor_group right_drive(rightBack, right_front);
vex::motor left_front(LEFT_FRONT_PORT, vex::ratio6_1);
vex::motor left_back(LEFT_BACK_PORT, vex::ratio6_1);
vex::motor_group left_drive(left_front, left_back);
vex::drivetrain Basedrive(left_drive, right_drive);
void Drive::init() {
    Basedrive.setDriveVelocity(100, vex::percent);
    Basedrive.setTurnVelocity(75, vex::percent);
}

void Drive::controller(vex::controller controller) {
    Basedrive.arcade(controller.Axis3.position(), controller.Axis1.position());
}