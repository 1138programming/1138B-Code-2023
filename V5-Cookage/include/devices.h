#pragma once
#include "api.h"
#include "sylib/sylib.hpp"
#include "lemlib/api.hpp"



//controller
static pros::Controller master(pros::E_CONTROLLER_MASTER);

//motors
static pros::Motor left_front_motor(20, pros::E_MOTOR_GEARSET_06, true); // port 1, blue gearbox, not reversed
static pros::Motor left_mid_motor(19, pros::E_MOTOR_GEARSET_06, true); // port 1, blue gearbox, not reversed
static pros::Motor left_back_motor(18, pros::E_MOTOR_GEARSET_06, true); // port 2, green gearbox, not reversed
static pros::Motor right_front_motor(11, pros::E_MOTOR_GEARSET_06, false); // port 3, red gearbox, reversed
static pros::Motor right_mid_motor(12, pros::E_MOTOR_GEARSET_06, false); // port 3, red gearbox, reversed
static pros::Motor right_back_motor(13, pros::E_MOTOR_GEARSET_06, false); // port 4,
static pros::MotorGroup left_side({left_mid_motor, left_front_motor, left_back_motor});
static pros::MotorGroup right_side({right_mid_motor, right_front_motor, right_back_motor});

//sensors
static pros::Imu Imu(15);

//chassis

static lemlib::Drivetrain_t drivetrain {
    &left_side, // left drivetrain motors
    &right_side, // right drivetrain motors
    10, // track width
    2.75, // wheel diameter
    450 // wheel rpm
};

// odometry struct
static lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &Imu// inertial sensor
};

 
// forward/backward PID
static lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
static lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};

static lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

// three wire
static sylib::Addrled baseLeds(22, 5, 43);
static sylib::Addrled intakeLeds(22, 6, 14);
