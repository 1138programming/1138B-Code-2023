#include "vex.h"
#include "drive.h"
#include "constants.h"

void Drive::init() {
    Drivetrain.setDriveVelocity(100, vex::percent);
    Drivetrain.setTurnVelocity(75, vex::percent);
}

void Drive::controller(vex::controller controller) {
    Drivetrain.arcade(controller.Axis3.position(), controller.Axis1.position());
}