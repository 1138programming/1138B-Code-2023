
// Header file for odometry and stuff //

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

double getxcord(void); 
double getycord(void);
double getxrawrot(void);
double absD(double num);
double getGyro(void);
void updateOdometry(void);
#ifdef __cplusplus
}
#endif

