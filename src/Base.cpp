
#include "api.h"

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
pros::Motor left_wheelsfront (LEFT_FRONT_WHEELS_PORT, true);
pros::Motor left_wheelsback (LEFT_BACK_WHEELS_PORT, true);
pros::Motor left_wheelstop (LEFT_TOP_WHEELS_PORT);
//right drivetrain
pros::Motor right_wheelsfront (RIGHT_FRONT_WHEELS_PORT);
pros::Motor right_wheelsback (RIGHT_BACK_WHEELS_PORT);
pros::Motor right_wheelstop (RIGHT_TOP_WHEELS_PORT, true); // True This reverses the motor
pros::Controller master(pros::E_CONTROLLER_MASTER);

//Base Constructor
void Base() {



  left_wheelsback.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_wheelsfront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_wheelstop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_wheelsback.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_wheelsfront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_wheelstop.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  int speed;
  int turn;
  int leftcontrol;
  int rightcontrol;
  float Drive_Speed_Coefficient = 2;

}

void DriveWithJoysticks() {
    
    speed = (master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * Drive_Speed_Coefficient);
    turn = (master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * Drive_Speed_Coefficient);

    leftcontrol = (speed + turn); // divides the controller value to get a percent, then multiplies by 600 (max rpm of drive motors), then multiplies by the drive speed coefficient
    rightcontrol = (speed - turn);

    //tank testing
    //leftcontrol = turn;
    //rightcontrol = speed;

    left_wheelsfront.move_velocity(leftcontrol);
    left_wheelsback.move_velocity(leftcontrol);
    left_wheelstop.move_velocity(leftcontrol);

    right_wheelsfront.move_velocity(rightcontrol);
    right_wheelsback.move_velocity(rightcontrol);
    right_wheelstop.move_velocity(rightcontrol);
}