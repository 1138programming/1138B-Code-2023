
// Header file for odometry and stuff 

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif
void OdometryI();
class Odometry {
    public:
        
        double getxcord(void); 
        double getycord(void);
        double getxrawrot(void);
        double getxcorddiffrence(void);
        double getycorddiffrence(void);
        double absD(double num);
        double getGyro(void);
        void updateOdometry(void);
        double xencoderbuffer;
        double yencoderbuffer;
        double xcord;
        double ycord; 
};
#ifdef __cplusplus
}
#endif

