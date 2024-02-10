#pragma once
#include "api.h"
#include "sylib/sylib.hpp"
#include "lemlib/api.hpp"
#include "EZ-GUI/api.hpp"
#include "pros/misc.hpp"
#include "autons.h"

//controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
 
// base
    //motors
    inline pros::Motor left_front_motor(-6, pros::E_MOTOR_GEARSET_06);
    inline pros::Motor left_mid_motor(-4, pros::E_MOTOR_GEARSET_06); 
    inline pros::Motor left_back_motor(-9, pros::E_MOTOR_GEARSET_06); 
    inline pros::Motor right_front_motor(5, pros::E_MOTOR_GEARSET_06);
    inline pros::Motor right_mid_motor(7, pros::E_MOTOR_GEARSET_06);
    inline pros::Motor right_back_motor(10, pros::E_MOTOR_GEARSET_06);
    inline pros::MotorGroup left_side({left_mid_motor, left_front_motor, left_back_motor});
    inline pros::MotorGroup right_side({right_mid_motor, right_front_motor, right_back_motor});

    //sensors
    inline pros::Imu Imu(20);

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
        10// slew rate
        
    };
    
    // turning PID
    inline lemlib::ControllerSettings angularController {
        1.5, // kP
        3, // kI
        5, // kD
        3, // antiwindup
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
    };
    inline lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

//system motors
inline pros::Motor intake(2, pros::E_MOTOR_GEAR_600); // define the intake motor in vanilla pros
inline pros::Motor kicker(3, pros::E_MOTOR_GEAR_100); // define the intake motor in vanilla pros

// three wire
inline pros::ADIDigitalOut leftWing(2);
inline pros::ADIDigitalOut rightWing(3);
inline pros::ADIDigitalOut hang(4);

// // screen
// inline ez::GUI display(
//     {{left_front_motor, "left front"},
//      {left_mid_motor, "left mid"},
//      {left_back_motor, "left back"},
//      {right_front_motor, "right front"},
//      {right_mid_motor, "right mid"},
//      {right_back_motor, "right back"},
//      {flywheel, "fly 1"},
//      {intake, "intake"}},
//     {{"WP", basicWP},
//      {"Disrupt", disrupt},
//      {"SixBall", sixBall}});