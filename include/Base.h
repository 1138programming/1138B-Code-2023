#ifndef BASE_H
#define BASE_H
//  Header File for Base
#include "api.h"
#ifdef __cplusplus
extern "C" {
#endif
void Base_Init();
class BaseDrive {
    public:
        static void drive(int speed);
        static void driveDistance(float distance, int speed);
        static void driveController(pros::Controller controller, int type);
};
#ifdef __cplusplus
}
#endif
#endif
