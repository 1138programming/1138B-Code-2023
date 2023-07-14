
#include "api.h"
#include "motors.h"
#include "Base.h"
#include "Constants.h"
#include "NewPID.h"
#include "NewPID.cpp"
#include "Odometry.h"
#include <functional>
#include <iostream>

// Variables for Arcade
int speed;
int turn;
int leftcontrol;
int rightcontrol;









//base init
void Base_Init() {

  left_drivetrain.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
  right_drivetrain.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);


}

    void BaseDrive::drive(int speed) {
      left_drivetrain.move_velocity(speed);
      right_drivetrain.move_velocity(speed);
    }
    NewPID DriveDistancePID(0.0,0.0,0.0,0.0,100.0,0.0,1.0);

    void BaseDrive::driveDistance(float distance, float speed) {
      

      float distAtCall = Odometry::getxrawrot();
      DriveDistancePID.setSetpoint(distance);
      left_drivetrain.move_velocity(DriveDistancePID.calculate(Odometry::getxrawrot() - distAtCall));
      right_drivetrain.move_velocity(DriveDistancePID.calculate(Odometry::getxrawrot() - distAtCall));
      
    }
    void BaseDrive::turnDeggrees(float targetDeg, float speed) {
        float gyroAtCall = Odometry::getGyro();
        DriveDistancePID.setSetpoint(targetDeg);
        left_drivetrain = DriveDistancePID.calculate( Odometry::getGyro() - gyroAtCall);
        right_drivetrain = -DriveDistancePID.calculate( Odometry::getGyro() - gyroAtCall);
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