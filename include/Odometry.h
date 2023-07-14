
// Header file for odometry and stuff 

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif
void OdometryI();
class Odometry {
    public:
        
        static double getxcord(void); 
        static double getycord(void);
        static double getxrawrot(void);
        static double getxcorddiffrence(void);
        static double getycorddiffrence(void);
        static double absD(double num);
        static double getGyro(void);
        void updateOdometry(void);
        static double xencoderbuffer;
        static double yencoderbuffer;
        static double xcord;
        static double ycord; 
};
#ifdef __cplusplus
}
#endif

