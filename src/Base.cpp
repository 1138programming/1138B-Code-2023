
#include "api.h"
#include "motors.h"
#include "Base.h"
#include "Constants.h"
#include <functional>
#include <iostream>

// Variables for Arcade
int speed;
int turn;
int leftcontrol;
int rightcontrol;
float Drive_Speed_Coefficient = 2;
float Turn_Speed_Coefficient = 1.75;

//Base Constructor
void Base_Init() {

  left_drivetrain.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  right_drivetrain.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);

}

    void BaseDrive::driveForward(int speed) {
      left_drivetrain.move_velocity(speed);
      right_drivetrain.move_velocity(speed);
    }
    void BaseDrive::brake() {
      left_drivetrain.brake();
      right_drivetrain.brake();
    }
    void BaseDrive::driveController(pros::Controller controller) {
    speed = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * Drive_Speed_Coefficient);
    turn = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * Turn_Speed_Coefficient);

    leftcontrol = (speed + turn); // divides the controller value to get a percent, then multiplies by 600 (max rpm of drive motors), then multiplies by the drive speed coefficient
    rightcontrol = (speed - turn);

    //tank testing
    //leftcontrol = turn;
    //rightcontrol = speed;

    left_drivetrain.move_velocity(leftcontrol);
    right_drivetrain.move_velocity(rightcontrol);
    }