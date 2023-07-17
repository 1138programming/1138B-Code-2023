#include "api.h"
#include "constants.h"
#include "motors.h"

//left drivetrain
pros::Motor right_front (RIGHT_FRONT_PORT);
pros::Motor right_back (RIGHT_BACK_PORT);
pros::MotorGroup right_drivetrain({right_front, right_back});
pros::Motor left_front (LEFT_FRONT_PORT);
pros::Motor left_back (LEFT_BACK_PORT);
pros::MotorGroup left_drivetrain({left_front, left_back});
//intake
pros::Motor intakeMotor (INTAKE_PORT);
//catapult
pros::Motor Catapultmotor (CATA_PORT, true);