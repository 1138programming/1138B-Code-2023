#include "api.h"
// Motors
inline sylib::SpeedControllerInfo flyController ([](double rpm){return 0;},1, 1, 1, 1, false, 0, false, 0, 1, 0);
inline sylib::Motor flywheel = sylib::Motor(16, 600, true, flyController);
inline pros::Motor intake(-17, pros::E_MOTOR_GEAR_600);
// pneumatics
inline pros::ADIDigitalOut wings(1);
inline pros::ADIDigitalOut balance(2);
inline pros::ADIDigitalOut hangUp(4);
inline pros::ADIDigitalOut hangDown(3);

// leds
inline sylib::Addrled base(22, 5, 43);
inline sylib::Addrled intakeLEDS(22,6,14);