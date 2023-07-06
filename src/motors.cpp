#include "api.h"
#include "constants.h"
#include "motors.h"

//left drivetrain
pros::Motor left_wheelsfront (LEFT_FRONT_WHEELS_PORT, true);
pros::Motor left_wheelsback (LEFT_BACK_WHEELS_PORT, true);
pros::Motor left_wheelstop (LEFT_TOP_WHEELS_PORT);
pros::MotorGroup left_drivetrain({left_wheelsfront, left_wheelsback, left_wheelstop});
//right drivetrain
pros::Motor right_wheelsfront (RIGHT_FRONT_WHEELS_PORT);
pros::Motor right_wheelsback (RIGHT_BACK_WHEELS_PORT);
pros::Motor right_wheelstop (RIGHT_TOP_WHEELS_PORT, true); // True This reverses the motor
pros::MotorGroup right_drivetrain({right_wheelsfront, right_wheelsback, right_wheelstop});
//intake
pros::Motor Left_intake (INTAKE_LEFT, true);
pros::Motor Right_intake (INTAKE_RIGHT);
pros::MotorGroup intakemotors ({Left_intake, Right_intake});
//catapult
pros::Motor Catapultmotor (CATA_PORT, true);