#pragma once
#include "api.h"
#include "sylib/sylib.hpp"
#include "lemlib/api.hpp"

//controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// base
    //motors
    inline pros::Motor left_front_motor(20, pros::E_MOTOR_GEARSET_06, true); // port 1, blue gearbox, not reversed
    inline pros::Motor left_mid_motor(19, pros::E_MOTOR_GEARSET_06, true); // port 1, blue gearbox, not reversed
    inline pros::Motor left_back_motor(18, pros::E_MOTOR_GEARSET_06, true); // port 2, green gearbox, not reversed
    inline pros::Motor right_front_motor(11, pros::E_MOTOR_GEARSET_06, false); // port 3, red gearbox, reversed
    inline pros::Motor right_mid_motor(12, pros::E_MOTOR_GEARSET_06, false); // port 3, red gearbox, reversed
    inline pros::Motor right_back_motor(13, pros::E_MOTOR_GEARSET_06, false); // port 4,
    inline pros::MotorGroup left_side({left_mid_motor, left_front_motor, left_back_motor});
    inline pros::MotorGroup right_side({right_mid_motor, right_front_motor, right_back_motor});

    //sensors
    inline pros::Imu Imu(15);

    //chassis

    inline lemlib::Drivetrain drivetrain {
        &left_side, // left drivetrain motors
        &right_side, // right drivetrain motors
        10, // track width
        lemlib::Omniwheel::NEW_275, // wheel diameter
        450, // wheel rpm
        6 // chase speed 
    };

    // odometry struct
    inline lemlib::OdomSensors sensors {
        nullptr, // vertical tracking wheel 1
        nullptr, // vertical tracking wheel 2
        nullptr, // horizontal tracking wheel 1
        nullptr, // we don't have a second tracking wheel, so we set it to nullptr
        &Imu// inertial sensor
    };

    
    // forward/backward PID
    inline lemlib::ControllerSettings lateralController {
        19, // kP
        0, // KI
        85, // kD
        3, // antiwindup
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5// slew rate
        
    };
    
    // turning PID
    inline lemlib::ControllerSettings angularController {
        4, // kP
        0, // kI
        40, // kD
        3, // antiwindup
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        40 // slew rate
    };
    inline lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

//system motors
inline sylib::SpeedControllerInfo flyController ([](double rpm){return 0;},1, 1, 1, 1, false, 0, false, 0, 1, 0); // custom motor control pid for flywheel
inline sylib::Motor flywheel = sylib::Motor(16, 600, true, flyController); // define the flywheel motor using sylib motor
inline pros::Motor intake(17, pros::E_MOTOR_GEAR_600); // define the intake motor in vanilla pros

// three wire
inline pros::ADIDigitalOut wings(1);
inline pros::ADIDigitalOut balance(2);
inline pros::ADIDigitalOut hangUp(4);
inline pros::ADIDigitalOut hangDown(3);
inline sylib::Addrled baseLeds(22, 5, 43);
inline sylib::Addrled intakeLeds(22, 6, 14);
