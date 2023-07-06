
//  Header File for Base
#include "api.h"
#ifdef __cplusplus
extern "C" {
#endif
void Base_Init();
void DriveWithJoysticks();
void DriveBy(double dist);
void TurnDeg(double deg);
extern pros::Motor left_wheelsfront;
extern pros::Motor left_wheelsback;
extern pros::Motor left_wheelstop;
extern pros::Motor right_wheelsfront;
extern pros::Motor right_wheelsback;
extern pros::Motor right_wheelstop;
#ifdef __cplusplus
}
#endif

