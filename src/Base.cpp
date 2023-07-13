
#include "api.h"
#include "motors.h"
#include "Base.h"
#include "Constants.h"
#include "PID.h"
#include <functional>
#include <iostream>

// Variables for Arcade
int speed;
int turn;
int leftcontrol;
int rightcontrol;
float Drive_Speed_Coefficient = 2;
float Turn_Speed_Coefficient = 1.75;








//base init
void Base_Init() {

  left_drivetrain.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  right_drivetrain.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  PID(0,0,0,0,100,0,1);

}

    void BaseDrive::drive(int speed) {
      left_drivetrain.move_velocity(speed);
      right_drivetrain.move_velocity(speed);
    }
    void BaseDrive::driveDistance(float distance, float speed) {
      int ticksperrotation = 0; //need to test
      float wheelSize = 0; //need to set
      float rotationRequired = distance/wheelSize;
      float tickstomove = ticksperrotation * rotationRequired;
    
      
    }
    void BaseDrive::driveController(pros::Controller controller, int type) {
      switch (type) {
        case 1:
            speed = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * Drive_Speed_Coefficient);
            turn = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * Turn_Speed_Coefficient);

            leftcontrol = (speed + turn); // divides the controller value to get a percent, then multiplies by 600 (max rpm of drive motors), then multiplies by the drive speed coefficient
            rightcontrol = (speed - turn);
            left_drivetrain.move_velocity(leftcontrol);
            right_drivetrain.move_velocity(rightcontrol);
        break;
        case 2:
          float left = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * Drive_Speed_Coefficient);
          float right = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)*Drive_Speed_Coefficient);
          left_drivetrain.move_velocity(left);
          right_drivetrain.move_velocity(right);
        break;
      }
    }