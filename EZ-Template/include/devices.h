#include "api.h"
// Motors
inline pros::Motor flywheel(-16, pros::E_MOTOR_GEAR_600);
inline pros::Motor intake(17, pros::E_MOTOR_GEAR_600);

// pneumatics
inline pros::ADIDigitalOut wings(1);
inline pros::ADIDigitalOut balance(2);
inline pros::ADIDigitalOut hangUp(3);
inline pros::ADIDigitalOut hangDown(4);