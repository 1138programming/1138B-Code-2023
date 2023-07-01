
//  Header File for Base
#include "api.h"
#ifdef __cplusplus
extern "C" {
#endif
void Base();
void DriveWithJoysticks(pros::Controller master);
void DriveBy(double dist);
void TurnDeg(double deg);
#ifdef __cplusplus
}
#endif
